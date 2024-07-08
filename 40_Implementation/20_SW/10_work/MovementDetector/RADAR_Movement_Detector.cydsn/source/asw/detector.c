/**
* \brief Implements the Reaction Game logic
*
* \copyright Copyright ©2016
* Department of electrical engineering and information technology, Hochschule Darmstadt - University of applied sciences (h_da). All Rights Reserved.
* Permission to use, copy, modify, and distribute this software and its documentation for educational, and research purposes in the context of non-commercial
* (unless permitted by h_da) and official h_da projects, is hereby granted for enrolled students of h_da, provided that the above copyright notice,
* this paragraph and the following paragraph appear in all copies, modifications, and distributions.
* Contact Prof.Dr.-Ing. Peter Fromm, peter.fromm@h-da.de, Birkenweg 8 64295 Darmstadt - GERMANY for commercial requests.
*
* \warning This software is a PROTOTYPE version and is not designed or intended for use in production, especially not for safety-critical applications!
* The user represents and warrants that it will NOT use or redistribute the Software for such purposes.
* This prototype is for research purposes only. This software is provided "AS IS," without a warranty of any kind.
*/

/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/


#include "project.h"
#include "detector.h"
#include "uart.h"
#include "dma.h"
#include "dac_adc.h"
#include "led.h"
#include "uart.h"

#include "fft_application.h"

/*****************************************************************************/
/* Local pre-processor symbols/macros ('#define')                            */
/*****************************************************************************/

/*****************************************************************************/
/* Global variable definitions (declared in header file with 'extern')       */
/*****************************************************************************/

/*****************************************************************************/
/* Local type definitions ('typedef')                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Local variable definitions ('static')                                     */
/*****************************************************************************/

/**
 * @brief Variable representing the clock frequency for the reaction game module.
 */


/*****************************************************************************/
/* Local function prototypes ('static')                                      */
/*****************************************************************************/


/*****************************************************************************/
/* Function implementation - global ('extern') and local ('static')          */
/*****************************************************************************/

// INIT all low level drivers
RC_t DETECTOR_initDrivers(){
    UART_init();
    DMA_Init();
    ADC_Init();
    DAC_Init();
    
    return RC_SUCCESS;
}

// Init Detector object attributes and drivers used by the object
RC_t DETECTOR_init(Detector_t* detector){
    DETECTOR_initDrivers();
    
    detector->detectorState = IDLE;
    DETECTOR_setLedState(IDLE);
    
    detector->numberOfTransfers = 0;
    detector->samplingFinished = FALSE;
    detector->readyToSend = FALSE;
    detector->memoryToUARTFinished = FALSE;
    
    
    return RC_SUCCESS;    
}

RC_t DETECTOR_setLedState(States_t state){
    switch (state){
        case (IDLE): {
            LED_Set(LED_ALL, LED_OFF);
            LED_Set(LED_RED, LED_ON);
            
        }
        break;
        
        case (SAMPLING): {
            LED_Set(LED_ALL, LED_OFF);
            LED_Set(LED_ORANGE, LED_ON);
        }
        break;
        
        case (UART_TRANSFER): {
            LED_Set(LED_ALL, LED_OFF);
            LED_Set(LED_GREEN, LED_ON);
        }
        break;
    }
    
    return RC_SUCCESS;
}

// Process events as they get triggered based on a State Machine Architecture
RC_t DETECTOR_processEvents(Detector_t* detector, EventMaskType ev){
    
            switch (detector -> detectorState){
            /*  IDLE states waits for the button to get pushed.
            *   
            *   ev_pushButton:          Triggered when button is pressed. The event turns ON the
            *                               ADC, DAC, and DMA modules and sampling is started and data is 
            *                               transferred from ADC output to a memory location with the help of 
            *                               DMA module. State changes from IDLE to SAMPLING
            */
            case (IDLE):
            {   
                if (ev & ev_pushButton){
  
                    DMA_Set(DMA_ADC_TO_MEMORY, DMA_ON);
                    DAC_Set(DAC_ON);
                    ADC_Set(ADC_ON);
                    
                    detector -> detectorState = SAMPLING;
                    DETECTOR_setLedState(SAMPLING);
                    
                }
            }
            break;
            
            /*  SAMPLING state waits continously samples the data and waits for a trigger character to arrive on the UART
            *   ev_sReceived:           Triggered when UART receives an 's'. Enables a flag to indicate that data
            *                               can be sent 
            *   ev_samplingFinished:    Triggered when ADC finishes sampling. If external system is not ready to receice data, 
            *                               existing data is discarded and another event is triggered to start resampling
            *   ev_reSample:            Triggered when sampling needs to be restarted.
            *   ev_send:                Triggered when sampling is finished and external system is ready to recieve data. State changes
            *                               from SAMPLING to UART_TRANSFER 
            */
            case (SAMPLING):
            {

                
                
                if (ev & ev_sReceived){
                    
                    detector -> readyToSend = TRUE;
                }
                if (ev & ev_samplingFinished){
                    
                    DMA_Set(DMA_ADC_TO_MEMORY, DMA_OFF);
                    
                    if (detector -> readyToSend == FALSE){

                        SetEvent(tsk_control, ev_reSample);
                    }
                    if (detector ->readyToSend == TRUE){

                        detector -> readyToSend = FALSE;
                        
                        SetEvent(tsk_control, ev_send);
                    }
                } 
                if (ev & ev_reSample){

                    DMA_Set(DMA_ADC_TO_MEMORY, DMA_ON);
                    
                }
                if (ev & ev_send){
                    
                    //DMA_Set(DMA_ADC_TO_MEMORY, DMA_OFF);
                    //DMA_Set(DMA_MEMORY_TO_UART, DMA_ON); //
                    
                    fft_app(ADCBuffer,fftBuffer,1024); //
                    //DMA_Set(DMA_FFT_TO_UART, DMA_ON);
                    
                    for (int i = 0; i < 2048; ++i){
                        uint8_t byte0 = (fftBuffer[i] >> 24) & 0xFF; // Most significant byte
                        uint8_t byte1 = (fftBuffer[i] >> 16) & 0xFF;
                        uint8_t byte2 = (fftBuffer[i] >> 8) & 0xFF;
                        uint8_t byte3 = fftBuffer[i] & 0xFF;         // Least significant byte

                        // Send each byte over UART
                        UART_LOG_PutChar(byte3);
                        UART_LOG_PutChar(byte2);
                        UART_LOG_PutChar(byte1);
                        UART_LOG_PutChar(byte0);
                    
                    }
                    
                    
                    
                    
                    detector -> detectorState = UART_TRANSFER;
                    DETECTOR_setLedState(UART_TRANSFER);
                    

                }
                
            }
            break;

            /*  UART_TRANSFER state transfers the sampled data over UART and waits for a feedback
            *   ev_noSReceived:         Trigered when sampling needs to be started again
            *   ev_UARTOver:            Triggered when UART receives an 'o'. Marks end of transfer. If number of 
            *                               transfers < 10. Sampling starts again. If number of transfers = 10, process 
            *                               is considered complete, and system waits for a button press again. State changes
            *                               from UART_TRANSFER to IDLE.
            *    

            */
            case (UART_TRANSFER):
            {
                if (ev & ev_sendFFT){
                    DMA_Set(DMA_MEMORY_TO_UART, DMA_OFF);
                    
                    #define DMA 1
                    #if DMA == 1
                    
                    fft_app(ADCBuffer,fftBuffer,1024); //
                    DMA_Set(DMA_FFT_TO_UART, DMA_ON); //
                    #endif 
                    #if DMA == 0
                    
                    fft_app(ADCBuffer,fftBuffer,1024); //
                    for (int i = 0; i < 2048; ++i){
                        uint8_t byte0 = (fftBuffer[i] >> 24) & 0xFF; // Most significant byte
                        uint8_t byte1 = (fftBuffer[i] >> 16) & 0xFF;
                        uint8_t byte2 = (fftBuffer[i] >> 8) & 0xFF;
                        uint8_t byte3 = fftBuffer[i] & 0xFF;         // Least significant byte

                        // Send each byte over UART
                        UART_LOG_PutChar(byte3);
                        UART_LOG_PutChar(byte2);
                        UART_LOG_PutChar(byte1);
                        UART_LOG_PutChar(byte0);
                    
                    }
                    #endif

                }
                
                
                if (ev & ev_oReceived){
                    
                    //DMA_Set(DMA_MEMORY_TO_UART, DMA_OFF);
                    
                    DMA_Set(DMA_FFT_TO_UART, DMA_OFF); //
                    
                    
                    detector -> numberOfTransfers += 1;
                    if (detector -> numberOfTransfers < 10){
                        detector -> detectorState = SAMPLING;
                        DETECTOR_setLedState(SAMPLING);
                        
                        SetEvent(tsk_control, ev_reSample);
                    }
                    else if (detector -> numberOfTransfers == 10){
                        detector -> detectorState = IDLE;
                        DETECTOR_setLedState(IDLE);

                        DAC_Set(DAC_OFF);
                        ADC_Set(ADC_OFF);
                        
                        detector -> numberOfTransfers = 0;
                        detector -> samplingFinished = FALSE;
                        detector ->readyToSend = FALSE;
                        detector ->memoryToUARTFinished = FALSE;
                        
                        
                    }
                }
            }
            break;
        
        }
    return RC_SUCCESS;
}