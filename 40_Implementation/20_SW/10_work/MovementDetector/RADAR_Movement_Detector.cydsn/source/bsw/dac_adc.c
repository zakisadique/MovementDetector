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
#include "dac_adc.h"


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

/*****************************************************************************/
/* Local function prototypes ('static')                                      */
/*****************************************************************************/



/*****************************************************************************/
/* Function implementation - global ('extern') and local ('static')          */
/*****************************************************************************/

// Initialize ADC
RC_t ADC_Init(){
    ADC_DelSig_Start();

}

// Initialize DAC
RC_t DAC_Init(){
    return RC_SUCCESS;
}

// Set DAC State
RC_t DAC_Set(DAC_ONOFF_t dacOnOff){
    if (dacOnOff == DAC_ON){
        WaveDAC8_Start();
    }
    else if (dacOnOff == DAC_OFF){
        WaveDAC8_Stop();
    }
    return RC_SUCCESS;

}

// Set ADC State
RC_t ADC_Set(ADC_ONOFF_t adcOnOff){
    if (adcOnOff == ADC_ON){
       ADC_DelSig_StartConvert();
    }
    else if (adcOnOff == ADC_OFF){
       ADC_DelSig_StopConvert();
    }
    return RC_SUCCESS;
}