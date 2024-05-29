/**
* \file <filename>
* \author <author-name>
* \date <date>
*
* \brief <Symbolic File name>
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
#include "dma.h"


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
uint16_t ADCBuffer[1024]; // buffer to store sampled data
/*****************************************************************************/
/* Local function prototypes ('static')                                      */
/*****************************************************************************/



/*****************************************************************************/
/* Function implementation - global ('extern') and local ('static')          */
/*****************************************************************************/

// Initialize DMA
RC_t DMA_Init(){
    /* DMA Configuration for DMA_ADC_MEM */
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
    
    
    
    Clock_DMA_MEM_UART_Start();
    return RC_SUCCESS;
    
    
}

// SET DMA state
RC_t DMA_Set(DMA_id_t dmaId, DMA_ONOFF_t dmaOnOff){
    switch (dmaId)
    {
        case DMA_ADC_TO_MEMORY : 
            if (dmaOnOff == DMA_ON){
                CyDmaChEnable(DMA_ADC_MEM_Chan, 1);
            } else if (dmaOnOff == DMA_ON){
                CyDmaChDisable(DMA_ADC_MEM_Chan);
            }
            break;
        
        case DMA_MEMORY_TO_UART : 
            if (dmaOnOff == DMA_ON){
                CyDmaChEnable(DMA_MEM_UART_Chan, 1);
            } else if (dmaOnOff == DMA_ON){
                CyDmaChDisable(DMA_MEM_UART_Chan);
            }
            break;

        default: return RC_ERROR_BAD_PARAM;
    }

}


