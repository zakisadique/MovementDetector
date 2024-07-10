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
#include "cfar.h"
#include <math.h>
#include <stdio.h>

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


void CFAR_init(CFAR_input_t *cfarInput){
    cfarInput -> PFA = 0.1;
    cfarInput -> numberGuardCells = 2;
    cfarInput -> numberofBins = 1024;
    cfarInput -> numberReferenceCells = 10;

}

void CFAR_reset_output(CFAR_output_t* cfarOutput){
    cfarOutput -> numberofBins = 1024;
    cfarOutput -> numberTargets = 0;
    
    for (int i = 0; i < cfarOutput -> numberofBins; i++) {
        cfarOutput -> fft_psocPower[i] = 0.0;
        cfarOutput -> thresholds[i] = 0.0;
        cfarOutput -> targetDetected[i] = 0;  
        
    }

}

void calculateCFAR(int32 *fftBuffer, CFAR_input_t *input, CFAR_output_t *output){
    double alpha = input -> numberReferenceCells * (pow(input -> PFA, -1.0/input -> numberReferenceCells) - 1.0);
   
    
    for (int i = 0; i < input -> numberofBins; i++) {
        double real = (double)fftBuffer [2 * i];     // Real component
        double imag = (double)fftBuffer [2 * i + 1]; // Imaginary component

        output -> fft_psocPower[i] = real * real + imag * imag;
    }

    output -> fft_psocPower[0] = 0.0; // Set the DC element to 0
    

    for (int i = input -> numberReferenceCells + input -> numberGuardCells + 1; 
        i <= input ->numberofBins  - input -> numberReferenceCells - input -> numberGuardCells; i++) { // Loop through CUT
        // Calculate sum of lagging and leading cells
        long double lagging_sum = 0.0;
        long double leading_sum = 0.0;
        for (int j = 0; j < input -> numberReferenceCells; j++) {
            lagging_sum += output -> fft_psocPower[i - input -> numberReferenceCells - input -> numberGuardCells + j];
            leading_sum += output -> fft_psocPower[i + input -> numberGuardCells + 1 + j];
        }

        // Calculate noise level
        double noise_level = (lagging_sum + leading_sum) / (2.0 * input -> numberReferenceCells); 

        // Calculate threshold
        double threshold = noise_level * alpha;

        // Store threshold
        output -> thresholds[i] = threshold;

        // Detect target
        if (output -> fft_psocPower[i] > threshold) {
            output -> targetDetected[i] = 1; // Set flag for target detected (could be magnitude instead)
            output -> numberTargets = output -> numberTargets + 1;
        } 
        
    }
}
