/**
* \file uart.c
* \author P. Fromm
* \date 8.12.19
*
* \brief UART wrapper
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


#include "uart.h"

/*****************************************************************************/
/* Local pre-processor symbols/macros ('#define')                            */
/*****************************************************************************/

/*****************************************************************************/
/* Global variable definitions (declared in header file with 'extern')       */
/*****************************************************************************/

const static uint8_t UART_Bits_Ascending[128] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
    32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
    48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
    64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
    80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
    96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111,
    112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127,

};
const static uint8_t UART_Bits_Descending[128] = {
    128, 127, 126, 125, 124, 123, 122, 121, 120, 119, 118, 117, 116, 115, 114, 113,
    112, 111, 110, 109, 108, 107, 106, 105, 104, 103, 102, 101, 100, 99, 98, 97,
    96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81,
    80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65,
    64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49,
    48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33,
    32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17,
    16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1

};

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

/**
 * Init a Uart Port
 * @param UART_t * const me : IN/OUT - pointer to uart port object 
 * @return RC_SUCCESS or error code
 */
RC_t UART_init()
{
    
    UART_LOG_Start();
//    UART_LOG_PutString("Ready to receive data\n");
    return RC_SUCCESS;
}

RC_t UART_restartOperation(){
    UART_LOG_Stop();
    UART_LOG_Start();

}
//
///**
// * Write a string to the UART, Using Ringbuffer and ISR
// * @param UART_t * const me : IN/OUT - pointer to uart port object 
// * @param uint8_t const * const s : IN - pointer to the string to be transmitted
// * @return <return description>
// */
//RC_t UART_writeString(UART_t *const me, uint8_t const * const s)
//{
//    //Write data into ringbuffer
//    uint16_t len = strlen(s);
//    uint16_t capacity = RB_getCapacity(&me->m_txBuffer);
//    
//    if (len < capacity)
//    {
//        for (uint16_t i = 0; i < len; i++)
//        {
//            RB_write(&me->m_txBuffer, &s[i]);
//        }
//    
//        //Initiate transfer
//        //Can be optimized in terms of speed
//        uint8_t firstElement = 0;
//        RB_read(&me->m_txBuffer, &firstElement);
//        
//        //Send to driver
//        //Rest will be transmitted by TX_isr;
//        UART_writeByte(firstElement);
//    }
//    else
//    {
//        return RC_ERROR_MEMORY;
//    }
//    
//    return RC_SUCCESS;
//}
//
///**
// * Write next char to the UART port
// * @param UART_t * const me : IN/OUT - pointer to uart port object 
// * @return RC_SUCCESS or errorcode
// */
//RC_t UART_TX_isrHandler(UART_t *const me)
//{
//    
//    if (RB_getNumberOfStoredElements(&me->m_txBuffer))
//    {
//        uint8_t nextElement = 0;
//        RB_read(&me->m_txBuffer, &nextElement);
//        
//        //Send to driver
//        UART_writeByte(nextElement);
//        
//        return RC_SUCCESS;
//    }
//    else
//    {
//        //do nothing, transfer ended
//        return RC_ERROR_BUFFER_EMTPY;
//    }
//    
//}
//
//
//
//RC_t UART_RX_isrHandler(UART_t *const me){
//    uint8_t receivedByte = UART_readByte();
//    
//    
//    RC_t result = RC_ERROR;
//    result =  RB_write(&me->m_rxBuffer, &receivedByte);
//    if (result == RC_SUCCESS && receivedByte == UART_Terminator){
//        result = RC_TRIGGER;
//    }
//    me -> countISR++;
//    return result;
//}
//
//RC_t UART_getJsonString(UART_t * const me, uint8_t * const jsonString){
//#if 0
//    if (me == NULL || jsonString == NULL){
//        return RC_ERROR_NULL;
//    }
//    
//    if (RB_getNumberOfStoredElements(&me->m_rxBuffer) == 0) {
//        return RC_ERROR_BUFFER_EMTPY;
//    }
//#endif
//for (uint8_t i = 0; i > MAX_JSON_STRING_LENGTH; ++i){
//
//    jsonString[i] = '\0';
//}
//
//
//    char receivedChar;
//    int index = 0;
//    uint8_t data;
//    while (1) {
//        RC_t result = RB_read(&me->m_rxBuffer, &data);
//
//        if (result == RC_SUCCESS) {
//            receivedChar = data;
//            jsonString[index++] = receivedChar;
//      
//            if (receivedChar == UART_Terminator) {
//                jsonString[index] = '\0';
//                //UART_LOG_PutString("UART_getString");
//                //UART_LOG_PutString((const char8 *)jsonString); // debug
//                //UART_LOG_PutString("\n");
//                return RC_SUCCESS;
//            }
//
//            if (index >= MAX_JSON_STRING_LENGTH - 1) {
//                return RC_ERROR_READ_FAILS;
//                break;
//            }
//        } else {
//             return RC_ERROR_READ_FAILS;
//            //break;
//        }
//    }
//}


RC_t UART_RX_isrHandler(){
uint8_t data = UART_LOG_GetByte();

    
    if (data == 's'){

            UART_LOG_PutArray(UART_Bits_Ascending, 128);
            UART_LOG_PutArray(UART_Bits_Descending, 128);

    }
}