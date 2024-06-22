/**
* \note <notes>
* Programming rules (may be deleted in the final release of the file)
* ===================================================================
*
* 1. Naming conventions:
*    - Prefix of your module in front of every function and static data. 
*    - Scope _ for public and __ for private functions / data / types, e.g. 
*       Public:  void CONTROL_straightPark_Init();
*       Private: static void CONTROL__calcDistance();
*       Public:  typedef enum {RED, GREEN, YELLOW} CONTROL_color_t
*    - Own type definitions e.g. for structs or enums get a postfix _t
*    - #define's and enums are written in CAPITAL letters
* 2. Code structure
*    - Be aware of the scope of your modules and functions. Provide only functions which belong to your module to your files
*    - Prepare your design before starting to code
*    - Implement the simple most solution (Too many if then else nestings are an indicator that you have not properly analysed your task)
*    - Avoid magic numbers, use enums and #define's instead
*    - Make sure, that all error conditions are properly handled
*    - If your module provides data structures, which are required in many other files, it is recommended to place them in a file_type.h file
*	  - If your module contains configurable parts, is is recommended to place these in a file_config.h|.c file
* 3. Data conventions
*    - Minimize the scope of data (and functions)
*    - Global data is not allowed outside of the signal layer (in case a signal layer is part of your design)
*    - All static objects have to be placed in a valid linker sections
*    - Data which is accessed in more than one task has to be volatile and needs to be protected (e.g. by using messages or semaphores)
*    - Do not mix signed and unsigned data in the same operation
* 4. Documentation
*    - Use self explaining function and variable names
*    - Use proper indentation
*    - Provide Javadoc / Doxygen compatible comments in your header file and C-File
*    		- Every  File has to be documented in the header
*			- Every function parameter and return value must be documented, the valid range needs to be specified
*     		- Logical code blocks in the C-File must be commented
*    - For a detailed list of doxygen commands check http://www.stack.nl/~dimitri/doxygen/index.html 
* 5. Qualification
*    - Perform and document design and code reviews for every module
*    - Provide test specifications for every module (focus on error conditions)
*
* Further information:
*    - Check the programming rules defined in the MIMIR project guide
*         - Code structure: https://fromm.eit.h-da.de/intern/mimir/methods/eng_codestructure/method.htm
*         - MISRA for C: https://fromm.eit.h-da.de/intern/mimir/methods/eng_c_rules/method.htm
*         - MISRA for C++: https://fromm.eit.h-da.de/intern/mimir/methods/eng_cpp_rules/method.htm 
*
* \todo <todos>
* \warning <warnings, e.g. dependencies, order of execution etc.>
*
*  Changelog:\n
*  - <version; data of change; author>
*            - <description of the change>
*
* \copyright Copyright �2016
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

 
#ifndef DMA_H
#define DMA_H

#include "global.h"
#include "arm_math.h"
    
    
/*****************************************************************************/
/* Global pre-processor symbols/macros and type declarations                 */
/*****************************************************************************/
    
#define NO_OF_SAMPLES 1024
    
extern uint16_t ADCBuffer[1024];
extern int32 fftBuffer[2048];
extern uint8_t *casted_buffer;


//####################### Enumerations

// DMA Identifier
enum eDMA_id{
  DMA_ADC_TO_MEMORY,
  DMA_MEMORY_TO_UART,
  DMA_FFT_TO_UART
};         
typedef enum eDMA_id DMA_id_t;

// DMA States
enum eDMA_ONOFF{
    DMA_OFF = 0,    /**< Turn the LED OFF */
    DMA_ON  = 1     /**< Turn the LED ON */
};
typedef enum eDMA_ONOFF DMA_ONOFF_t;

/* Variable declarations for DMA_ADC_MEM */
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


/* Defines for DMA_FFT_UART */
#define DMA_FFT_UART_BYTES_PER_BURST 4
#define DMA_FFT_UART_REQUEST_PER_BURST 1
#define DMA_FFT_UART_SRC_BASE (CYDEV_SRAM_BASE)
#define DMA_FFT_UART_DST_BASE (CYDEV_PERIPH_BASE)

/* Variable declarations for DMA_FFT_UART */
/* Move these variable declarations to the top of the function */
uint8_t DMA_FFT_UART_Chan;
uint8_t DMA_FFT_UART_TD[3];






// Wrapper to allow representing the file in Together as class
#ifdef TOGETHER

   
#endif /* Together */

/*****************************************************************************/
/* Extern global variables                                                   */
/*****************************************************************************/


/*****************************************************************************/
/* API functions                                                             */
/*****************************************************************************/

// Initialize DMA
RC_t DMA_Init();

// SET DMA state
RC_t DMA_Set(DMA_id_t dmaId, DMA_ONOFF_t dmaOnOff);


/*****************************************************************************/
/* Private stuff, only visible for Together, declared static in cpp - File   */
/*****************************************************************************/


#ifdef TOGETHER



};
#endif /* Together */

#endif /* DMA_H */
