/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "global.h"
#include "detector.h"
#include "fft_application.h"

#define UART_START_VARIABLE 's'
#define UART_FINISH_VARIABLE 'o'
#define UART_TARGET_VARIABLE 't'
#define UART_NO_TARGET_VARIABLE 'n'

#define NO_OF_SAMPLES 1024

Detector_t movementDetector;


extern uint16_t ADCBuffer[NO_OF_SAMPLES];
extern uint32_t fftBuffer[2* NO_OF_SAMPLES];

//ISR which will increment the systick counter every ms
ISR(systick_handler)
{
    CounterTick(cnt_systick);
}

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
   
    //Set systick period to 1 ms. Enable the INT and start it.
	EE_systick_set_period(MILLISECONDS_TO_TICKS(1, BCLK__BUS_CLK__HZ));
	EE_systick_enable_int();
    
    // Start Operating System
    for(;;)	    
    	StartOS(OSDEFAULTAPPMODE);
}

void unhandledException()
{
    //Ooops, something terrible happened....check the call stack to see how we got here...
    __asm("bkpt");
}

/********************************************************************************
 * Task Definitions
 ********************************************************************************/

TASK(tsk_init)
{
    
    //Init MCAL Drivers   
    DETECTOR_init(&movementDetector);
    
    //Reconfigure ISRs with OS parameters.
    //This line MUST be called after the hardware driver initialisation!
    EE_system_init();
	
    //Start SysTick
	//Must be done here, because otherwise the isr vector is not overwritten yet
    EE_systick_start();  
    
    //Activate tasks
    ActivateTask(tsk_control);
    ActivateTask(tsk_background);

    TerminateTask();
    
}




TASK(tsk_control)
{
    //Initialize an event and wait for its trigger
    EventMaskType ev = 0;
    
    while (1){
        WaitEvent(ev_pushButton | ev_reSample | ev_sReceived | ev_send | ev_oReceived | ev_tReceived | ev_nReceived);
        GetEvent(tsk_control, &ev);
        ClearEvent(ev);
        
        // Process the event received
        DETECTOR_processEvents(&movementDetector, ev);
        
    }

    TerminateTask();
}

// Idle task
TASK(tsk_background)
{
    
    
    while(1)
    {

    }
    TerminateTask();
    
}

// Process interrupts received on UART
ISR2(isr_UART_Rx){
    
    uint8_t data = UART_LOG_GetByte();
    if (data ==  UART_START_VARIABLE){
        SetEvent(tsk_control, ev_sReceived);
    } else if (data == UART_FINISH_VARIABLE){
        SetEvent(tsk_control, ev_oReceived); 
    } else if (data == UART_TARGET_VARIABLE){
        SetEvent(tsk_control, ev_tReceived); 
    } else if (data == UART_NO_TARGET_VARIABLE){
        SetEvent(tsk_control, ev_nReceived); 
    }
    
    
    
    
}

// Process interrupts when transfer from ADC to memory is completed
ISR2(isr_DMA_ADC_MEM){
    
    SetEvent(tsk_control, ev_samplingFinished);
}

// Process interrupts when button is pressed
ISR2(isr_pushButton){
    
    SetEvent(tsk_control, ev_pushButton);
}


/********************************************************************************
 * ISR Definitions
 ********************************************************************************/

/* [] END OF FILE */
