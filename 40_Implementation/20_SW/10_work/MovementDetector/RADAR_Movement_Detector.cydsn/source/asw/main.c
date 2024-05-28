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
#include "led.h"
#include "uart.h"

/* Defines for DMA_ADC_MEM */
#define DMA_ADC_MEM_BYTES_PER_BURST 2
#define DMA_ADC_MEM_REQUEST_PER_BURST 1
#define DMA_ADC_MEM_SRC_BASE (CYDEV_PERIPH_BASE)
#define DMA_ADC_MEM_DST_BASE (CYDEV_SRAM_BASE)

/* Variable declarations for DMA_ADC_MEM */
/* Move these variable declarations to the top of the function */
uint8_t DMA_ADC_MEM_Chan;
uint8_t DMA_ADC_MEM_TD[1];


/* Defines for DMA_MEM_UART */
#define DMA_MEM_UART_BYTES_PER_BURST 2
#define DMA_MEM_UART_REQUEST_PER_BURST 1
#define DMA_MEM_UART_SRC_BASE (CYDEV_SRAM_BASE)
#define DMA_MEM_UART_DST_BASE (CYDEV_PERIPH_BASE)

/* Variable declarations for DMA_MEM_UART */
/* Move these variable declarations to the top of the function */
uint8_t DMA_MEM_UART_Chan;
uint8_t DMA_MEM_UART_TD[1];  


uint16_t ADCBuffer[1024];


typedef enum {
    IDLE,    /**< Waiting for the start of a new round.    */
    SAMPLING,       /**< Waiting for the display to show a digit. */
    UART_TRANSFER,  /**< Waiting for the user to react.           */
    None                    /**< No specific state (uninitialized).       */
} States;

typedef struct Detector_t{
    States detectorState;          /**< Current state of the game. */
    uint8_t  numberOfTransfers;          /**< Current round number. */
    boolean_t samplingFinished;
    boolean_t transferToUARTFinished;
    boolean_t readyToSend;
    boolean_t memoryToUARTFinished;
} Detector_t;

Detector_t movementDetector;



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
    
    UART_init();
    ADC_DelSig_Start();
    Clock_1_Start();
    
    movementDetector.detectorState = IDLE;
    DMA_ADC_MEM_Chan = DMA_ADC_MEM_DmaInitialize(
        DMA_ADC_MEM_BYTES_PER_BURST, 
        DMA_ADC_MEM_REQUEST_PER_BURST, 
        HI16(DMA_ADC_MEM_SRC_BASE), 
        HI16(DMA_ADC_MEM_DST_BASE));
    DMA_ADC_MEM_TD[0] = CyDmaTdAllocate();
    CyDmaTdSetConfiguration(DMA_ADC_MEM_TD[0], 2048, CY_DMA_DISABLE_TD, DMA_ADC_MEM__TD_TERMOUT_EN | CY_DMA_TD_INC_DST_ADR);
    CyDmaTdSetAddress(DMA_ADC_MEM_TD[0], LO16((uint32)ADC_DelSig_DEC_SAMP_PTR), LO16((uint32)ADCBuffer));
    CyDmaChSetInitialTd(DMA_ADC_MEM_Chan, DMA_ADC_MEM_TD[0]);

    /* DMA Configuration for DMA_MEM_UART */
    DMA_MEM_UART_Chan = DMA_MEM_UART_DmaInitialize(
        DMA_MEM_UART_BYTES_PER_BURST, 
        DMA_MEM_UART_REQUEST_PER_BURST, 
        HI16(DMA_MEM_UART_SRC_BASE), 
        HI16(DMA_MEM_UART_DST_BASE));
    DMA_MEM_UART_TD[0] = CyDmaTdAllocate();
    CyDmaTdSetConfiguration(DMA_MEM_UART_TD[0], 2048, CY_DMA_DISABLE_TD, DMA_MEM_UART__TD_TERMOUT_EN | CY_DMA_TD_INC_SRC_ADR);
    CyDmaTdSetAddress(DMA_MEM_UART_TD[0], LO16((uint32)ADCBuffer), LO16((uint32)UART_LOG_TXDATA_PTR));
    CyDmaChSetInitialTd(DMA_MEM_UART_Chan, DMA_MEM_UART_TD[0]);
    
    
    
    //Reconfigure ISRs with OS parameters.
    //This line MUST be called after the hardware driver initialisation!
    EE_system_init();
	
    //Start SysTick
	//Must be done here, because otherwise the isr vector is not overwritten yet
    EE_systick_start();  

    
    //SetRelAlarm(alrm_main,1,1000);
    //Start the alarm with 100ms cycle time
    
    movementDetector.detectorState = IDLE;
    movementDetector.numberOfTransfers = 0;
    movementDetector.samplingFinished = FALSE;
    movementDetector.readyToSend = FALSE;
    movementDetector.transferToUARTFinished = FALSE;
    movementDetector.memoryToUARTFinished = FALSE;
    
    
    ActivateTask(tsk_control);
    ActivateTask(tsk_background);

    TerminateTask();
    
}



TASK(tsk_background)
{
    
    
    while(1)
    {

    }
    TerminateTask();
    
}

TASK(tsk_control)
{
#if 0
    while (1){
    switch(movementDetector.detectorState){
            case(IDLE):
            {
                movementDetector.numberOfTransfers = 0;
                movementDetector.samplingFinished = FALSE;
                movementDetector.readyToSend = FALSE;
                movementDetector.transferToUARTFinished = FALSE;
                movementDetector.memoryToUARTFinished = FALSE;
            
            }
            break;
            
            case(SAMPLING):
            {
                
                CyDmaChEnable(DMA_ADC_MEM_Chan, 1);
                WaveDAC8_Start();
                ADC_DelSig_StartConvert();
                boolean_t samplingInProgress = TRUE;
                
                while (samplingInProgress == TRUE){
                    if (movementDetector.samplingFinished == TRUE){
                        if (movementDetector.readyToSend == FALSE){
                            CyDmaChDisable(DMA_ADC_MEM_Chan);
                            WaveDAC8_Stop();
                            movementDetector.samplingFinished = FALSE;
                            samplingInProgress = FALSE;
                        } else if (movementDetector.readyToSend == TRUE){
                            movementDetector.detectorState = UART_TRANSFER;
                            movementDetector.readyToSend = FALSE;
                            movementDetector.samplingFinished = TRUE;
                            samplingInProgress = FALSE;
                        
                        }

                    }
                }
            }

            break;
            
            case(UART_TRANSFER):
            {
                
                CyDmaChEnable(DMA_MEM_UART_Chan, 1);
                boolean_t workInProgress = TRUE;
                while (workInProgress == TRUE){
                    if (movementDetector.transferToUARTFinished == TRUE && movementDetector.memoryToUARTFinished == TRUE){
                    movementDetector.transferToUARTFinished = FALSE;
                    movementDetector.memoryToUARTFinished = FALSE;
                    movementDetector.numberOfTransfers += 1;
                    CyDmaChDisable(DMA_MEM_UART_Chan);
                    
                        if (movementDetector.numberOfTransfers == 10){
                            movementDetector.numberOfTransfers = 0;
                            movementDetector.detectorState = IDLE;
                        } else {
                            movementDetector.detectorState = SAMPLING;
                        }
                        
                        workInProgress = FALSE;
                    }
                    
                }
            }
            break;
            
            case(None):
            
            break;
        
        }
    
    }
#endif    
    EventMaskType ev = 0;
    
    while (1){
        WaitEvent(ev_pushButton | ev_noSReceived | ev_sReceived | ev_countLessTen | ev_countEqualTen | ev_send | ev_UARTOver);
        GetEvent(tsk_control, &ev);
        ClearEvent(ev);
        
        switch (movementDetector.detectorState){
            case (IDLE):
            {
                if (ev & ev_pushButton){
                    //start Sampling
                    CyDmaChEnable(DMA_ADC_MEM_Chan, 1);
                    WaveDAC8_Start();
                    ADC_DelSig_StartConvert();
                    movementDetector.detectorState = SAMPLING;
                }
            }
            break;
            
            case (SAMPLING):
            {
                
                if (ev & ev_sReceived){
                    movementDetector.readyToSend = TRUE;
                }
                if (ev & ev_samplingFinished){
                    // trigger from DMA1 ISR
                    if (movementDetector.readyToSend == FALSE){
                            CyDmaChDisable(DMA_ADC_MEM_Chan);
                            WaveDAC8_Stop();
                            ADC_DelSig_StopConvert();
                            
                            SetEvent(tsk_control, ev_noSReceived);
                        }
                    if (movementDetector.readyToSend == TRUE){
                            movementDetector.readyToSend = FALSE;
                        
                            CyDmaChDisable(DMA_ADC_MEM_Chan);
                            WaveDAC8_Stop();
                            ADC_DelSig_StopConvert();
                            SetEvent(tsk_control, ev_send);
                        }
                } 
                if (ev & ev_noSReceived){
                    CyDmaChEnable(DMA_ADC_MEM_Chan, 1);
                    WaveDAC8_Start();
                    ADC_DelSig_StartConvert();
                }
                if (ev & ev_send){
//                    CyDmaChDisable(DMA_ADC_MEM_Chan);
//                    WaveDAC8_Stop();
//                    ADC_DelSig_StopConvert();
                    
                    CyDmaChEnable(DMA_MEM_UART_Chan, 1);
                    movementDetector.detectorState = UART_TRANSFER;
                }
            }

            
            case (UART_TRANSFER):
            {
                if (ev & ev_UARTOver){
                    // O Received
                    CyDmaChDisable(DMA_MEM_UART_Chan);
                    
                    movementDetector.numberOfTransfers += 1;
                    if (movementDetector.numberOfTransfers < 10){
                        movementDetector.detectorState = SAMPLING;
                        SetEvent(tsk_control, ev_noSReceived); //change name to restartSampling
                    }
                    else if (movementDetector.numberOfTransfers == 10){
                        
                        movementDetector.detectorState = IDLE;
                        
                        
                        movementDetector.numberOfTransfers = 0;
                        movementDetector.samplingFinished = FALSE;
                        movementDetector.readyToSend = FALSE;
                        movementDetector.transferToUARTFinished = FALSE;
                        movementDetector.memoryToUARTFinished = FALSE;
                    }
                    
                }
            
            }
            break;
            
            case (None):
            {}
            break;   
         
        
        
        }
        
    }


    TerminateTask();
    
}

ISR2(isr_UART_Rx){
    #if 0
    uint8_t data = UART_LOG_GetByte();
    if (movementDetector.detectorState == SAMPLING && data == 's'){
        movementDetector.readyToSend = TRUE;
    } else if (movementDetector.detectorState == UART_TRANSFER && data == 'o'){
        movementDetector.transferToUARTFinished = TRUE;
    }
    #endif
    
    uint8_t data = UART_LOG_GetByte();
    if (movementDetector.detectorState == SAMPLING && data == 's'){
       SetEvent(tsk_control, ev_sReceived);
    } else if (movementDetector.detectorState == UART_TRANSFER && data == 'o'){
        SetEvent(tsk_control, ev_UARTOver); // change name t ev_o received
    }

}

ISR2(isr_DMA_ADC_MEM){
#if 0
   movementDetector.samplingFinished = TRUE;
#endif

SetEvent(tsk_control, ev_samplingFinished);
    
}

ISR2(isr_DMA_MEM_UART){
    
   movementDetector.memoryToUARTFinished = TRUE;
}


ISR2(isr_pushButton){
#if 0
    if (movementDetector.detectorState == IDLE){
        movementDetector.detectorState = SAMPLING;
    }
#endif

    SetEvent(tsk_control, ev_pushButton);
}

/********************************************************************************
 * ISR Definitions
 ********************************************************************************/

/* [] END OF FILE */
