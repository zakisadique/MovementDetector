/*******************************************************************************
* File Name: cyfitter.h
* 
* PSoC Creator  4.4
*
* Description:
* 
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2020 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include "cydevice.h"
#include "cydevice_trm.h"

/* Rx */
#define Rx__0__INTTYPE CYREG_PICU2_INTTYPE0
#define Rx__0__MASK 0x01u
#define Rx__0__PC CYREG_PRT2_PC0
#define Rx__0__PORT 2u
#define Rx__0__SHIFT 0u
#define Rx__AG CYREG_PRT2_AG
#define Rx__AMUX CYREG_PRT2_AMUX
#define Rx__BIE CYREG_PRT2_BIE
#define Rx__BIT_MASK CYREG_PRT2_BIT_MASK
#define Rx__BYP CYREG_PRT2_BYP
#define Rx__CTL CYREG_PRT2_CTL
#define Rx__DM0 CYREG_PRT2_DM0
#define Rx__DM1 CYREG_PRT2_DM1
#define Rx__DM2 CYREG_PRT2_DM2
#define Rx__DR CYREG_PRT2_DR
#define Rx__INP_DIS CYREG_PRT2_INP_DIS
#define Rx__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define Rx__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define Rx__LCD_EN CYREG_PRT2_LCD_EN
#define Rx__MASK 0x01u
#define Rx__PORT 2u
#define Rx__PRT CYREG_PRT2_PRT
#define Rx__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define Rx__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define Rx__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define Rx__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define Rx__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define Rx__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define Rx__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define Rx__PS CYREG_PRT2_PS
#define Rx__SHIFT 0u
#define Rx__SLW CYREG_PRT2_SLW

/* Tx */
#define Tx__0__INTTYPE CYREG_PICU2_INTTYPE1
#define Tx__0__MASK 0x02u
#define Tx__0__PC CYREG_PRT2_PC1
#define Tx__0__PORT 2u
#define Tx__0__SHIFT 1u
#define Tx__AG CYREG_PRT2_AG
#define Tx__AMUX CYREG_PRT2_AMUX
#define Tx__BIE CYREG_PRT2_BIE
#define Tx__BIT_MASK CYREG_PRT2_BIT_MASK
#define Tx__BYP CYREG_PRT2_BYP
#define Tx__CTL CYREG_PRT2_CTL
#define Tx__DM0 CYREG_PRT2_DM0
#define Tx__DM1 CYREG_PRT2_DM1
#define Tx__DM2 CYREG_PRT2_DM2
#define Tx__DR CYREG_PRT2_DR
#define Tx__INP_DIS CYREG_PRT2_INP_DIS
#define Tx__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define Tx__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define Tx__LCD_EN CYREG_PRT2_LCD_EN
#define Tx__MASK 0x02u
#define Tx__PORT 2u
#define Tx__PRT CYREG_PRT2_PRT
#define Tx__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define Tx__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define Tx__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define Tx__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define Tx__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define Tx__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define Tx__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define Tx__PS CYREG_PRT2_PS
#define Tx__SHIFT 1u
#define Tx__SLW CYREG_PRT2_SLW

/* ADC_In */
#define ADC_In__0__INTTYPE CYREG_PICU15_INTTYPE5
#define ADC_In__0__MASK 0x20u
#define ADC_In__0__PC CYREG_IO_PC_PRT15_PC5
#define ADC_In__0__PORT 15u
#define ADC_In__0__SHIFT 5u
#define ADC_In__AG CYREG_PRT15_AG
#define ADC_In__AMUX CYREG_PRT15_AMUX
#define ADC_In__BIE CYREG_PRT15_BIE
#define ADC_In__BIT_MASK CYREG_PRT15_BIT_MASK
#define ADC_In__BYP CYREG_PRT15_BYP
#define ADC_In__CTL CYREG_PRT15_CTL
#define ADC_In__DM0 CYREG_PRT15_DM0
#define ADC_In__DM1 CYREG_PRT15_DM1
#define ADC_In__DM2 CYREG_PRT15_DM2
#define ADC_In__DR CYREG_PRT15_DR
#define ADC_In__INP_DIS CYREG_PRT15_INP_DIS
#define ADC_In__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU15_BASE
#define ADC_In__LCD_COM_SEG CYREG_PRT15_LCD_COM_SEG
#define ADC_In__LCD_EN CYREG_PRT15_LCD_EN
#define ADC_In__MASK 0x20u
#define ADC_In__PORT 15u
#define ADC_In__PRT CYREG_PRT15_PRT
#define ADC_In__PRTDSI__CAPS_SEL CYREG_PRT15_CAPS_SEL
#define ADC_In__PRTDSI__DBL_SYNC_IN CYREG_PRT15_DBL_SYNC_IN
#define ADC_In__PRTDSI__OE_SEL0 CYREG_PRT15_OE_SEL0
#define ADC_In__PRTDSI__OE_SEL1 CYREG_PRT15_OE_SEL1
#define ADC_In__PRTDSI__OUT_SEL0 CYREG_PRT15_OUT_SEL0
#define ADC_In__PRTDSI__OUT_SEL1 CYREG_PRT15_OUT_SEL1
#define ADC_In__PRTDSI__SYNC_OUT CYREG_PRT15_SYNC_OUT
#define ADC_In__PS CYREG_PRT15_PS
#define ADC_In__SHIFT 5u
#define ADC_In__SLW CYREG_PRT15_SLW

/* LED_red */
#define LED_red__0__INTTYPE CYREG_PICU2_INTTYPE4
#define LED_red__0__MASK 0x10u
#define LED_red__0__PC CYREG_PRT2_PC4
#define LED_red__0__PORT 2u
#define LED_red__0__SHIFT 4u
#define LED_red__AG CYREG_PRT2_AG
#define LED_red__AMUX CYREG_PRT2_AMUX
#define LED_red__BIE CYREG_PRT2_BIE
#define LED_red__BIT_MASK CYREG_PRT2_BIT_MASK
#define LED_red__BYP CYREG_PRT2_BYP
#define LED_red__CTL CYREG_PRT2_CTL
#define LED_red__DM0 CYREG_PRT2_DM0
#define LED_red__DM1 CYREG_PRT2_DM1
#define LED_red__DM2 CYREG_PRT2_DM2
#define LED_red__DR CYREG_PRT2_DR
#define LED_red__INP_DIS CYREG_PRT2_INP_DIS
#define LED_red__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define LED_red__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define LED_red__LCD_EN CYREG_PRT2_LCD_EN
#define LED_red__MASK 0x10u
#define LED_red__PORT 2u
#define LED_red__PRT CYREG_PRT2_PRT
#define LED_red__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define LED_red__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define LED_red__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define LED_red__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define LED_red__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define LED_red__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define LED_red__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define LED_red__PS CYREG_PRT2_PS
#define LED_red__SHIFT 4u
#define LED_red__SLW CYREG_PRT2_SLW

/* UART_LOG */
#define UART_LOG_BUART_sRX_RxBitCounter__16BIT_CONTROL_AUX_CTL_REG CYREG_B0_UDB11_12_ACTL
#define UART_LOG_BUART_sRX_RxBitCounter__16BIT_CONTROL_CONTROL_REG CYREG_B0_UDB11_12_CTL
#define UART_LOG_BUART_sRX_RxBitCounter__16BIT_CONTROL_COUNT_REG CYREG_B0_UDB11_12_CTL
#define UART_LOG_BUART_sRX_RxBitCounter__16BIT_COUNT_CONTROL_REG CYREG_B0_UDB11_12_CTL
#define UART_LOG_BUART_sRX_RxBitCounter__16BIT_COUNT_COUNT_REG CYREG_B0_UDB11_12_CTL
#define UART_LOG_BUART_sRX_RxBitCounter__16BIT_MASK_MASK_REG CYREG_B0_UDB11_12_MSK
#define UART_LOG_BUART_sRX_RxBitCounter__16BIT_MASK_PERIOD_REG CYREG_B0_UDB11_12_MSK
#define UART_LOG_BUART_sRX_RxBitCounter__16BIT_PERIOD_MASK_REG CYREG_B0_UDB11_12_MSK
#define UART_LOG_BUART_sRX_RxBitCounter__16BIT_PERIOD_PERIOD_REG CYREG_B0_UDB11_12_MSK
#define UART_LOG_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG CYREG_B0_UDB11_ACTL
#define UART_LOG_BUART_sRX_RxBitCounter__CONTROL_REG CYREG_B0_UDB11_CTL
#define UART_LOG_BUART_sRX_RxBitCounter__CONTROL_ST_REG CYREG_B0_UDB11_ST_CTL
#define UART_LOG_BUART_sRX_RxBitCounter__COUNT_REG CYREG_B0_UDB11_CTL
#define UART_LOG_BUART_sRX_RxBitCounter__COUNT_ST_REG CYREG_B0_UDB11_ST_CTL
#define UART_LOG_BUART_sRX_RxBitCounter__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB11_MSK_ACTL
#define UART_LOG_BUART_sRX_RxBitCounter__PER_CTL_AUX_CTL_REG CYREG_B0_UDB11_MSK_ACTL
#define UART_LOG_BUART_sRX_RxBitCounter__PERIOD_REG CYREG_B0_UDB11_MSK
#define UART_LOG_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB11_12_ACTL
#define UART_LOG_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_REG CYREG_B0_UDB11_12_ST
#define UART_LOG_BUART_sRX_RxBitCounter_ST__MASK_REG CYREG_B0_UDB11_MSK
#define UART_LOG_BUART_sRX_RxBitCounter_ST__MASK_ST_AUX_CTL_REG CYREG_B0_UDB11_MSK_ACTL
#define UART_LOG_BUART_sRX_RxBitCounter_ST__PER_ST_AUX_CTL_REG CYREG_B0_UDB11_MSK_ACTL
#define UART_LOG_BUART_sRX_RxBitCounter_ST__STATUS_AUX_CTL_REG CYREG_B0_UDB11_ACTL
#define UART_LOG_BUART_sRX_RxBitCounter_ST__STATUS_CNT_REG CYREG_B0_UDB11_ST_CTL
#define UART_LOG_BUART_sRX_RxBitCounter_ST__STATUS_CONTROL_REG CYREG_B0_UDB11_ST_CTL
#define UART_LOG_BUART_sRX_RxBitCounter_ST__STATUS_REG CYREG_B0_UDB11_ST
#define UART_LOG_BUART_sRX_RxShifter_u0__16BIT_A0_REG CYREG_B0_UDB12_13_A0
#define UART_LOG_BUART_sRX_RxShifter_u0__16BIT_A1_REG CYREG_B0_UDB12_13_A1
#define UART_LOG_BUART_sRX_RxShifter_u0__16BIT_D0_REG CYREG_B0_UDB12_13_D0
#define UART_LOG_BUART_sRX_RxShifter_u0__16BIT_D1_REG CYREG_B0_UDB12_13_D1
#define UART_LOG_BUART_sRX_RxShifter_u0__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB12_13_ACTL
#define UART_LOG_BUART_sRX_RxShifter_u0__16BIT_F0_REG CYREG_B0_UDB12_13_F0
#define UART_LOG_BUART_sRX_RxShifter_u0__16BIT_F1_REG CYREG_B0_UDB12_13_F1
#define UART_LOG_BUART_sRX_RxShifter_u0__A0_A1_REG CYREG_B0_UDB12_A0_A1
#define UART_LOG_BUART_sRX_RxShifter_u0__A0_REG CYREG_B0_UDB12_A0
#define UART_LOG_BUART_sRX_RxShifter_u0__A1_REG CYREG_B0_UDB12_A1
#define UART_LOG_BUART_sRX_RxShifter_u0__D0_D1_REG CYREG_B0_UDB12_D0_D1
#define UART_LOG_BUART_sRX_RxShifter_u0__D0_REG CYREG_B0_UDB12_D0
#define UART_LOG_BUART_sRX_RxShifter_u0__D1_REG CYREG_B0_UDB12_D1
#define UART_LOG_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG CYREG_B0_UDB12_ACTL
#define UART_LOG_BUART_sRX_RxShifter_u0__F0_F1_REG CYREG_B0_UDB12_F0_F1
#define UART_LOG_BUART_sRX_RxShifter_u0__F0_REG CYREG_B0_UDB12_F0
#define UART_LOG_BUART_sRX_RxShifter_u0__F1_REG CYREG_B0_UDB12_F1
#define UART_LOG_BUART_sRX_RxSts__3__MASK 0x08u
#define UART_LOG_BUART_sRX_RxSts__3__POS 3
#define UART_LOG_BUART_sRX_RxSts__4__MASK 0x10u
#define UART_LOG_BUART_sRX_RxSts__4__POS 4
#define UART_LOG_BUART_sRX_RxSts__5__MASK 0x20u
#define UART_LOG_BUART_sRX_RxSts__5__POS 5
#define UART_LOG_BUART_sRX_RxSts__MASK 0x38u
#define UART_LOG_BUART_sRX_RxSts__MASK_REG CYREG_B0_UDB15_MSK
#define UART_LOG_BUART_sRX_RxSts__STATUS_AUX_CTL_REG CYREG_B0_UDB15_ACTL
#define UART_LOG_BUART_sRX_RxSts__STATUS_REG CYREG_B0_UDB15_ST
#define UART_LOG_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A0_REG CYREG_B0_UDB11_12_A0
#define UART_LOG_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A1_REG CYREG_B0_UDB11_12_A1
#define UART_LOG_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D0_REG CYREG_B0_UDB11_12_D0
#define UART_LOG_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D1_REG CYREG_B0_UDB11_12_D1
#define UART_LOG_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB11_12_ACTL
#define UART_LOG_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F0_REG CYREG_B0_UDB11_12_F0
#define UART_LOG_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F1_REG CYREG_B0_UDB11_12_F1
#define UART_LOG_BUART_sTX_sCLOCK_TxBitClkGen__A0_A1_REG CYREG_B0_UDB11_A0_A1
#define UART_LOG_BUART_sTX_sCLOCK_TxBitClkGen__A0_REG CYREG_B0_UDB11_A0
#define UART_LOG_BUART_sTX_sCLOCK_TxBitClkGen__A1_REG CYREG_B0_UDB11_A1
#define UART_LOG_BUART_sTX_sCLOCK_TxBitClkGen__D0_D1_REG CYREG_B0_UDB11_D0_D1
#define UART_LOG_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG CYREG_B0_UDB11_D0
#define UART_LOG_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG CYREG_B0_UDB11_D1
#define UART_LOG_BUART_sTX_sCLOCK_TxBitClkGen__DP_AUX_CTL_REG CYREG_B0_UDB11_ACTL
#define UART_LOG_BUART_sTX_sCLOCK_TxBitClkGen__F0_F1_REG CYREG_B0_UDB11_F0_F1
#define UART_LOG_BUART_sTX_sCLOCK_TxBitClkGen__F0_REG CYREG_B0_UDB11_F0
#define UART_LOG_BUART_sTX_sCLOCK_TxBitClkGen__F1_REG CYREG_B0_UDB11_F1
#define UART_LOG_BUART_sTX_sCLOCK_TxBitClkGen__MSK_DP_AUX_CTL_REG CYREG_B0_UDB11_MSK_ACTL
#define UART_LOG_BUART_sTX_sCLOCK_TxBitClkGen__PER_DP_AUX_CTL_REG CYREG_B0_UDB11_MSK_ACTL
#define UART_LOG_BUART_sTX_TxShifter_u0__16BIT_A0_REG CYREG_B0_UDB13_14_A0
#define UART_LOG_BUART_sTX_TxShifter_u0__16BIT_A1_REG CYREG_B0_UDB13_14_A1
#define UART_LOG_BUART_sTX_TxShifter_u0__16BIT_D0_REG CYREG_B0_UDB13_14_D0
#define UART_LOG_BUART_sTX_TxShifter_u0__16BIT_D1_REG CYREG_B0_UDB13_14_D1
#define UART_LOG_BUART_sTX_TxShifter_u0__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB13_14_ACTL
#define UART_LOG_BUART_sTX_TxShifter_u0__16BIT_F0_REG CYREG_B0_UDB13_14_F0
#define UART_LOG_BUART_sTX_TxShifter_u0__16BIT_F1_REG CYREG_B0_UDB13_14_F1
#define UART_LOG_BUART_sTX_TxShifter_u0__A0_A1_REG CYREG_B0_UDB13_A0_A1
#define UART_LOG_BUART_sTX_TxShifter_u0__A0_REG CYREG_B0_UDB13_A0
#define UART_LOG_BUART_sTX_TxShifter_u0__A1_REG CYREG_B0_UDB13_A1
#define UART_LOG_BUART_sTX_TxShifter_u0__D0_D1_REG CYREG_B0_UDB13_D0_D1
#define UART_LOG_BUART_sTX_TxShifter_u0__D0_REG CYREG_B0_UDB13_D0
#define UART_LOG_BUART_sTX_TxShifter_u0__D1_REG CYREG_B0_UDB13_D1
#define UART_LOG_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG CYREG_B0_UDB13_ACTL
#define UART_LOG_BUART_sTX_TxShifter_u0__F0_F1_REG CYREG_B0_UDB13_F0_F1
#define UART_LOG_BUART_sTX_TxShifter_u0__F0_REG CYREG_B0_UDB13_F0
#define UART_LOG_BUART_sTX_TxShifter_u0__F1_REG CYREG_B0_UDB13_F1
#define UART_LOG_BUART_sTX_TxSts__0__MASK 0x01u
#define UART_LOG_BUART_sTX_TxSts__0__POS 0
#define UART_LOG_BUART_sTX_TxSts__1__MASK 0x02u
#define UART_LOG_BUART_sTX_TxSts__1__POS 1
#define UART_LOG_BUART_sTX_TxSts__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB13_14_ACTL
#define UART_LOG_BUART_sTX_TxSts__16BIT_STATUS_REG CYREG_B0_UDB13_14_ST
#define UART_LOG_BUART_sTX_TxSts__2__MASK 0x04u
#define UART_LOG_BUART_sTX_TxSts__2__POS 2
#define UART_LOG_BUART_sTX_TxSts__3__MASK 0x08u
#define UART_LOG_BUART_sTX_TxSts__3__POS 3
#define UART_LOG_BUART_sTX_TxSts__MASK 0x0Fu
#define UART_LOG_BUART_sTX_TxSts__MASK_REG CYREG_B0_UDB13_MSK
#define UART_LOG_BUART_sTX_TxSts__STATUS_AUX_CTL_REG CYREG_B0_UDB13_ACTL
#define UART_LOG_BUART_sTX_TxSts__STATUS_REG CYREG_B0_UDB13_ST
#define UART_LOG_IntClock__CFG0 CYREG_CLKDIST_DCFG1_CFG0
#define UART_LOG_IntClock__CFG1 CYREG_CLKDIST_DCFG1_CFG1
#define UART_LOG_IntClock__CFG2 CYREG_CLKDIST_DCFG1_CFG2
#define UART_LOG_IntClock__CFG2_SRC_SEL_MASK 0x07u
#define UART_LOG_IntClock__INDEX 0x01u
#define UART_LOG_IntClock__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define UART_LOG_IntClock__PM_ACT_MSK 0x02u
#define UART_LOG_IntClock__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define UART_LOG_IntClock__PM_STBY_MSK 0x02u

/* LED_green */
#define LED_green__0__INTTYPE CYREG_PICU2_INTTYPE6
#define LED_green__0__MASK 0x40u
#define LED_green__0__PC CYREG_PRT2_PC6
#define LED_green__0__PORT 2u
#define LED_green__0__SHIFT 6u
#define LED_green__AG CYREG_PRT2_AG
#define LED_green__AMUX CYREG_PRT2_AMUX
#define LED_green__BIE CYREG_PRT2_BIE
#define LED_green__BIT_MASK CYREG_PRT2_BIT_MASK
#define LED_green__BYP CYREG_PRT2_BYP
#define LED_green__CTL CYREG_PRT2_CTL
#define LED_green__DM0 CYREG_PRT2_DM0
#define LED_green__DM1 CYREG_PRT2_DM1
#define LED_green__DM2 CYREG_PRT2_DM2
#define LED_green__DR CYREG_PRT2_DR
#define LED_green__INP_DIS CYREG_PRT2_INP_DIS
#define LED_green__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define LED_green__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define LED_green__LCD_EN CYREG_PRT2_LCD_EN
#define LED_green__MASK 0x40u
#define LED_green__PORT 2u
#define LED_green__PRT CYREG_PRT2_PRT
#define LED_green__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define LED_green__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define LED_green__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define LED_green__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define LED_green__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define LED_green__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define LED_green__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define LED_green__PS CYREG_PRT2_PS
#define LED_green__SHIFT 6u
#define LED_green__SLW CYREG_PRT2_SLW

/* ADC_DelSig */
#define ADC_DelSig_DEC__COHER CYREG_DEC_COHER
#define ADC_DelSig_DEC__CR CYREG_DEC_CR
#define ADC_DelSig_DEC__DR1 CYREG_DEC_DR1
#define ADC_DelSig_DEC__DR2 CYREG_DEC_DR2
#define ADC_DelSig_DEC__DR2H CYREG_DEC_DR2H
#define ADC_DelSig_DEC__GCOR CYREG_DEC_GCOR
#define ADC_DelSig_DEC__GCORH CYREG_DEC_GCORH
#define ADC_DelSig_DEC__GVAL CYREG_DEC_GVAL
#define ADC_DelSig_DEC__OCOR CYREG_DEC_OCOR
#define ADC_DelSig_DEC__OCORH CYREG_DEC_OCORH
#define ADC_DelSig_DEC__OCORM CYREG_DEC_OCORM
#define ADC_DelSig_DEC__OUTSAMP CYREG_DEC_OUTSAMP
#define ADC_DelSig_DEC__OUTSAMPH CYREG_DEC_OUTSAMPH
#define ADC_DelSig_DEC__OUTSAMPM CYREG_DEC_OUTSAMPM
#define ADC_DelSig_DEC__OUTSAMPS CYREG_DEC_OUTSAMPS
#define ADC_DelSig_DEC__PM_ACT_CFG CYREG_PM_ACT_CFG10
#define ADC_DelSig_DEC__PM_ACT_MSK 0x01u
#define ADC_DelSig_DEC__PM_STBY_CFG CYREG_PM_STBY_CFG10
#define ADC_DelSig_DEC__PM_STBY_MSK 0x01u
#define ADC_DelSig_DEC__SHIFT1 CYREG_DEC_SHIFT1
#define ADC_DelSig_DEC__SHIFT2 CYREG_DEC_SHIFT2
#define ADC_DelSig_DEC__SR CYREG_DEC_SR
#define ADC_DelSig_DEC__TRIM__M1 CYREG_FLSHID_CUST_TABLES_DEC_M1
#define ADC_DelSig_DEC__TRIM__M2 CYREG_FLSHID_CUST_TABLES_DEC_M2
#define ADC_DelSig_DEC__TRIM__M3 CYREG_FLSHID_CUST_TABLES_DEC_M3
#define ADC_DelSig_DEC__TRIM__M4 CYREG_FLSHID_CUST_TABLES_DEC_M4
#define ADC_DelSig_DEC__TRIM__M5 CYREG_FLSHID_CUST_TABLES_DEC_M5
#define ADC_DelSig_DEC__TRIM__M6 CYREG_FLSHID_CUST_TABLES_DEC_M6
#define ADC_DelSig_DEC__TRIM__M7 CYREG_FLSHID_CUST_TABLES_DEC_M7
#define ADC_DelSig_DEC__TRIM__M8 CYREG_FLSHID_CUST_TABLES_DEC_M8
#define ADC_DelSig_DSM__BUF0 CYREG_DSM0_BUF0
#define ADC_DelSig_DSM__BUF1 CYREG_DSM0_BUF1
#define ADC_DelSig_DSM__BUF2 CYREG_DSM0_BUF2
#define ADC_DelSig_DSM__BUF3 CYREG_DSM0_BUF3
#define ADC_DelSig_DSM__CLK CYREG_DSM0_CLK
#define ADC_DelSig_DSM__CR0 CYREG_DSM0_CR0
#define ADC_DelSig_DSM__CR1 CYREG_DSM0_CR1
#define ADC_DelSig_DSM__CR10 CYREG_DSM0_CR10
#define ADC_DelSig_DSM__CR11 CYREG_DSM0_CR11
#define ADC_DelSig_DSM__CR12 CYREG_DSM0_CR12
#define ADC_DelSig_DSM__CR13 CYREG_DSM0_CR13
#define ADC_DelSig_DSM__CR14 CYREG_DSM0_CR14
#define ADC_DelSig_DSM__CR15 CYREG_DSM0_CR15
#define ADC_DelSig_DSM__CR16 CYREG_DSM0_CR16
#define ADC_DelSig_DSM__CR17 CYREG_DSM0_CR17
#define ADC_DelSig_DSM__CR2 CYREG_DSM0_CR2
#define ADC_DelSig_DSM__CR3 CYREG_DSM0_CR3
#define ADC_DelSig_DSM__CR4 CYREG_DSM0_CR4
#define ADC_DelSig_DSM__CR5 CYREG_DSM0_CR5
#define ADC_DelSig_DSM__CR6 CYREG_DSM0_CR6
#define ADC_DelSig_DSM__CR7 CYREG_DSM0_CR7
#define ADC_DelSig_DSM__CR8 CYREG_DSM0_CR8
#define ADC_DelSig_DSM__CR9 CYREG_DSM0_CR9
#define ADC_DelSig_DSM__DEM0 CYREG_DSM0_DEM0
#define ADC_DelSig_DSM__DEM1 CYREG_DSM0_DEM1
#define ADC_DelSig_DSM__MISC CYREG_DSM0_MISC
#define ADC_DelSig_DSM__OUT0 CYREG_DSM0_OUT0
#define ADC_DelSig_DSM__OUT1 CYREG_DSM0_OUT1
#define ADC_DelSig_DSM__REF0 CYREG_DSM0_REF0
#define ADC_DelSig_DSM__REF1 CYREG_DSM0_REF1
#define ADC_DelSig_DSM__REF2 CYREG_DSM0_REF2
#define ADC_DelSig_DSM__REF3 CYREG_DSM0_REF3
#define ADC_DelSig_DSM__RSVD1 CYREG_DSM0_RSVD1
#define ADC_DelSig_DSM__SW0 CYREG_DSM0_SW0
#define ADC_DelSig_DSM__SW2 CYREG_DSM0_SW2
#define ADC_DelSig_DSM__SW3 CYREG_DSM0_SW3
#define ADC_DelSig_DSM__SW4 CYREG_DSM0_SW4
#define ADC_DelSig_DSM__SW6 CYREG_DSM0_SW6
#define ADC_DelSig_DSM__TR0 CYREG_NPUMP_DSM_TR0
#define ADC_DelSig_DSM__TST0 CYREG_DSM0_TST0
#define ADC_DelSig_DSM__TST1 CYREG_DSM0_TST1
#define ADC_DelSig_Ext_CP_Clk__CFG0 CYREG_CLKDIST_DCFG0_CFG0
#define ADC_DelSig_Ext_CP_Clk__CFG1 CYREG_CLKDIST_DCFG0_CFG1
#define ADC_DelSig_Ext_CP_Clk__CFG2 CYREG_CLKDIST_DCFG0_CFG2
#define ADC_DelSig_Ext_CP_Clk__CFG2_SRC_SEL_MASK 0x07u
#define ADC_DelSig_Ext_CP_Clk__INDEX 0x00u
#define ADC_DelSig_Ext_CP_Clk__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define ADC_DelSig_Ext_CP_Clk__PM_ACT_MSK 0x01u
#define ADC_DelSig_Ext_CP_Clk__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define ADC_DelSig_Ext_CP_Clk__PM_STBY_MSK 0x01u
#define ADC_DelSig_IRQ__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define ADC_DelSig_IRQ__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define ADC_DelSig_IRQ__INTC_MASK 0x20000000u
#define ADC_DelSig_IRQ__INTC_NUMBER 29u
#define ADC_DelSig_IRQ__INTC_PRIOR_NUM 7u
#define ADC_DelSig_IRQ__INTC_PRIOR_REG CYREG_NVIC_PRI_29
#define ADC_DelSig_IRQ__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define ADC_DelSig_IRQ__INTC_SET_PD_REG CYREG_NVIC_SETPEND0
#define ADC_DelSig_theACLK__CFG0 CYREG_CLKDIST_ACFG0_CFG0
#define ADC_DelSig_theACLK__CFG1 CYREG_CLKDIST_ACFG0_CFG1
#define ADC_DelSig_theACLK__CFG2 CYREG_CLKDIST_ACFG0_CFG2
#define ADC_DelSig_theACLK__CFG2_SRC_SEL_MASK 0x07u
#define ADC_DelSig_theACLK__CFG3 CYREG_CLKDIST_ACFG0_CFG3
#define ADC_DelSig_theACLK__CFG3_PHASE_DLY_MASK 0x0Fu
#define ADC_DelSig_theACLK__INDEX 0x00u
#define ADC_DelSig_theACLK__PM_ACT_CFG CYREG_PM_ACT_CFG1
#define ADC_DelSig_theACLK__PM_ACT_MSK 0x01u
#define ADC_DelSig_theACLK__PM_STBY_CFG CYREG_PM_STBY_CFG1
#define ADC_DelSig_theACLK__PM_STBY_MSK 0x01u

/* LED_orange */
#define LED_orange__0__INTTYPE CYREG_PICU2_INTTYPE5
#define LED_orange__0__MASK 0x20u
#define LED_orange__0__PC CYREG_PRT2_PC5
#define LED_orange__0__PORT 2u
#define LED_orange__0__SHIFT 5u
#define LED_orange__AG CYREG_PRT2_AG
#define LED_orange__AMUX CYREG_PRT2_AMUX
#define LED_orange__BIE CYREG_PRT2_BIE
#define LED_orange__BIT_MASK CYREG_PRT2_BIT_MASK
#define LED_orange__BYP CYREG_PRT2_BYP
#define LED_orange__CTL CYREG_PRT2_CTL
#define LED_orange__DM0 CYREG_PRT2_DM0
#define LED_orange__DM1 CYREG_PRT2_DM1
#define LED_orange__DM2 CYREG_PRT2_DM2
#define LED_orange__DR CYREG_PRT2_DR
#define LED_orange__INP_DIS CYREG_PRT2_INP_DIS
#define LED_orange__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define LED_orange__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define LED_orange__LCD_EN CYREG_PRT2_LCD_EN
#define LED_orange__MASK 0x20u
#define LED_orange__PORT 2u
#define LED_orange__PRT CYREG_PRT2_PRT
#define LED_orange__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define LED_orange__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define LED_orange__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define LED_orange__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define LED_orange__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define LED_orange__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define LED_orange__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define LED_orange__PS CYREG_PRT2_PS
#define LED_orange__SHIFT 5u
#define LED_orange__SLW CYREG_PRT2_SLW

/* DMA_ADC_MEM */
#define DMA_ADC_MEM__DRQ_CTL CYREG_IDMUX_DRQ_CTL2
#define DMA_ADC_MEM__DRQ_NUMBER 10u
#define DMA_ADC_MEM__NUMBEROF_TDS 0u
#define DMA_ADC_MEM__PRIORITY 2u
#define DMA_ADC_MEM__TERMIN_EN 0u
#define DMA_ADC_MEM__TERMIN_SEL 0u
#define DMA_ADC_MEM__TERMOUT0_EN 1u
#define DMA_ADC_MEM__TERMOUT0_SEL 10u
#define DMA_ADC_MEM__TERMOUT1_EN 0u
#define DMA_ADC_MEM__TERMOUT1_SEL 0u

/* Push_Button */
#define Push_Button__0__INTTYPE CYREG_PICU2_INTTYPE7
#define Push_Button__0__MASK 0x80u
#define Push_Button__0__PC CYREG_PRT2_PC7
#define Push_Button__0__PORT 2u
#define Push_Button__0__SHIFT 7u
#define Push_Button__AG CYREG_PRT2_AG
#define Push_Button__AMUX CYREG_PRT2_AMUX
#define Push_Button__BIE CYREG_PRT2_BIE
#define Push_Button__BIT_MASK CYREG_PRT2_BIT_MASK
#define Push_Button__BYP CYREG_PRT2_BYP
#define Push_Button__CTL CYREG_PRT2_CTL
#define Push_Button__DM0 CYREG_PRT2_DM0
#define Push_Button__DM1 CYREG_PRT2_DM1
#define Push_Button__DM2 CYREG_PRT2_DM2
#define Push_Button__DR CYREG_PRT2_DR
#define Push_Button__INP_DIS CYREG_PRT2_INP_DIS
#define Push_Button__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define Push_Button__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define Push_Button__LCD_EN CYREG_PRT2_LCD_EN
#define Push_Button__MASK 0x80u
#define Push_Button__PORT 2u
#define Push_Button__PRT CYREG_PRT2_PRT
#define Push_Button__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define Push_Button__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define Push_Button__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define Push_Button__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define Push_Button__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define Push_Button__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define Push_Button__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define Push_Button__PS CYREG_PRT2_PS
#define Push_Button__SHIFT 7u
#define Push_Button__SLW CYREG_PRT2_SLW

/* isr_UART_Rx */
#define isr_UART_Rx__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define isr_UART_Rx__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define isr_UART_Rx__INTC_MASK 0x08u
#define isr_UART_Rx__INTC_NUMBER 3u
#define isr_UART_Rx__INTC_PRIOR_NUM 7u
#define isr_UART_Rx__INTC_PRIOR_REG CYREG_NVIC_PRI_3
#define isr_UART_Rx__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define isr_UART_Rx__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* DMA_FFT_UART */
#define DMA_FFT_UART__DRQ_CTL CYREG_IDMUX_DRQ_CTL0
#define DMA_FFT_UART__DRQ_NUMBER 0u
#define DMA_FFT_UART__NUMBEROF_TDS 0u
#define DMA_FFT_UART__PRIORITY 2u
#define DMA_FFT_UART__TERMIN_EN 0u
#define DMA_FFT_UART__TERMIN_SEL 0u
#define DMA_FFT_UART__TERMOUT0_EN 1u
#define DMA_FFT_UART__TERMOUT0_SEL 0u
#define DMA_FFT_UART__TERMOUT1_EN 0u
#define DMA_FFT_UART__TERMOUT1_SEL 0u

/* DMA_MEM_UART */
#define DMA_MEM_UART__DRQ_CTL CYREG_IDMUX_DRQ_CTL0
#define DMA_MEM_UART__DRQ_NUMBER 1u
#define DMA_MEM_UART__NUMBEROF_TDS 0u
#define DMA_MEM_UART__PRIORITY 2u
#define DMA_MEM_UART__TERMIN_EN 0u
#define DMA_MEM_UART__TERMIN_SEL 0u
#define DMA_MEM_UART__TERMOUT0_EN 1u
#define DMA_MEM_UART__TERMOUT0_SEL 1u
#define DMA_MEM_UART__TERMOUT1_EN 0u
#define DMA_MEM_UART__TERMOUT1_SEL 0u

/* isr_pushButton */
#define isr_pushButton__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define isr_pushButton__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define isr_pushButton__INTC_MASK 0x10u
#define isr_pushButton__INTC_NUMBER 4u
#define isr_pushButton__INTC_PRIOR_NUM 7u
#define isr_pushButton__INTC_PRIOR_REG CYREG_NVIC_PRI_4
#define isr_pushButton__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define isr_pushButton__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* isr_DMA_ADC_MEM */
#define isr_DMA_ADC_MEM__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define isr_DMA_ADC_MEM__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define isr_DMA_ADC_MEM__INTC_MASK 0x01u
#define isr_DMA_ADC_MEM__INTC_NUMBER 0u
#define isr_DMA_ADC_MEM__INTC_PRIOR_NUM 7u
#define isr_DMA_ADC_MEM__INTC_PRIOR_REG CYREG_NVIC_PRI_0
#define isr_DMA_ADC_MEM__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define isr_DMA_ADC_MEM__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* isr_DMA_FFT_UART */
#define isr_DMA_FFT_UART__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define isr_DMA_FFT_UART__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define isr_DMA_FFT_UART__INTC_MASK 0x02u
#define isr_DMA_FFT_UART__INTC_NUMBER 1u
#define isr_DMA_FFT_UART__INTC_PRIOR_NUM 7u
#define isr_DMA_FFT_UART__INTC_PRIOR_REG CYREG_NVIC_PRI_1
#define isr_DMA_FFT_UART__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define isr_DMA_FFT_UART__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* isr_DMA_MEM_UART */
#define isr_DMA_MEM_UART__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define isr_DMA_MEM_UART__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define isr_DMA_MEM_UART__INTC_MASK 0x04u
#define isr_DMA_MEM_UART__INTC_NUMBER 2u
#define isr_DMA_MEM_UART__INTC_PRIOR_NUM 7u
#define isr_DMA_MEM_UART__INTC_PRIOR_REG CYREG_NVIC_PRI_2
#define isr_DMA_MEM_UART__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define isr_DMA_MEM_UART__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* Clock_DMA_FFT_UART */
#define Clock_DMA_FFT_UART__CFG0 CYREG_CLKDIST_DCFG2_CFG0
#define Clock_DMA_FFT_UART__CFG1 CYREG_CLKDIST_DCFG2_CFG1
#define Clock_DMA_FFT_UART__CFG2 CYREG_CLKDIST_DCFG2_CFG2
#define Clock_DMA_FFT_UART__CFG2_SRC_SEL_MASK 0x07u
#define Clock_DMA_FFT_UART__INDEX 0x02u
#define Clock_DMA_FFT_UART__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define Clock_DMA_FFT_UART__PM_ACT_MSK 0x04u
#define Clock_DMA_FFT_UART__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define Clock_DMA_FFT_UART__PM_STBY_MSK 0x04u

/* Clock_DMA_MEM_UART */
#define Clock_DMA_MEM_UART__CFG0 CYREG_CLKDIST_DCFG3_CFG0
#define Clock_DMA_MEM_UART__CFG1 CYREG_CLKDIST_DCFG3_CFG1
#define Clock_DMA_MEM_UART__CFG2 CYREG_CLKDIST_DCFG3_CFG2
#define Clock_DMA_MEM_UART__CFG2_SRC_SEL_MASK 0x07u
#define Clock_DMA_MEM_UART__INDEX 0x03u
#define Clock_DMA_MEM_UART__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define Clock_DMA_MEM_UART__PM_ACT_MSK 0x08u
#define Clock_DMA_MEM_UART__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define Clock_DMA_MEM_UART__PM_STBY_MSK 0x08u

/* Miscellaneous */
#define BCLK__BUS_CLK__HZ 24000000U
#define BCLK__BUS_CLK__KHZ 24000U
#define BCLK__BUS_CLK__MHZ 24U
#define CY_PROJECT_NAME "RADAR_Movement_Detector"
#define CY_VERSION "PSoC Creator  4.4"
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PSOC4A 26u
#define CYDEV_CHIP_DIE_PSOC5LP 2u
#define CYDEV_CHIP_DIE_PSOC5TM 3u
#define CYDEV_CHIP_DIE_TMA4 4u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_FM0P 5u
#define CYDEV_CHIP_FAMILY_FM3 6u
#define CYDEV_CHIP_FAMILY_FM4 7u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_PSOC6 4u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC5
#define CYDEV_CHIP_JTAG_ID 0x2E160069u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 26u
#define CYDEV_CHIP_MEMBER_4AA 25u
#define CYDEV_CHIP_MEMBER_4AB 30u
#define CYDEV_CHIP_MEMBER_4AC 14u
#define CYDEV_CHIP_MEMBER_4AD 15u
#define CYDEV_CHIP_MEMBER_4AE 16u
#define CYDEV_CHIP_MEMBER_4D 20u
#define CYDEV_CHIP_MEMBER_4E 6u
#define CYDEV_CHIP_MEMBER_4F 27u
#define CYDEV_CHIP_MEMBER_4G 4u
#define CYDEV_CHIP_MEMBER_4H 24u
#define CYDEV_CHIP_MEMBER_4I 32u
#define CYDEV_CHIP_MEMBER_4J 21u
#define CYDEV_CHIP_MEMBER_4K 22u
#define CYDEV_CHIP_MEMBER_4L 31u
#define CYDEV_CHIP_MEMBER_4M 29u
#define CYDEV_CHIP_MEMBER_4N 11u
#define CYDEV_CHIP_MEMBER_4O 8u
#define CYDEV_CHIP_MEMBER_4P 28u
#define CYDEV_CHIP_MEMBER_4Q 17u
#define CYDEV_CHIP_MEMBER_4R 9u
#define CYDEV_CHIP_MEMBER_4S 12u
#define CYDEV_CHIP_MEMBER_4T 10u
#define CYDEV_CHIP_MEMBER_4U 5u
#define CYDEV_CHIP_MEMBER_4V 23u
#define CYDEV_CHIP_MEMBER_4W 13u
#define CYDEV_CHIP_MEMBER_4X 7u
#define CYDEV_CHIP_MEMBER_4Y 18u
#define CYDEV_CHIP_MEMBER_4Z 19u
#define CYDEV_CHIP_MEMBER_5A 3u
#define CYDEV_CHIP_MEMBER_5B 2u
#define CYDEV_CHIP_MEMBER_6A 33u
#define CYDEV_CHIP_MEMBER_FM3 37u
#define CYDEV_CHIP_MEMBER_FM4 38u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 34u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 35u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 36u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_5B
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_MEMBER_USED
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES0 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES1 1u
#define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1u
#define CYDEV_CHIP_REV_TMA4_ES 17u
#define CYDEV_CHIP_REV_TMA4_ES2 33u
#define CYDEV_CHIP_REV_TMA4_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_3A_ES1 0u
#define CYDEV_CHIP_REVISION_3A_ES2 1u
#define CYDEV_CHIP_REVISION_3A_ES3 3u
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3u
#define CYDEV_CHIP_REVISION_4A_ES0 17u
#define CYDEV_CHIP_REVISION_4A_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4AA_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AB_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AC_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AD_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AE_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4D_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD 0u
#define CYDEV_CHIP_REVISION_4E_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0u
#define CYDEV_CHIP_REVISION_4G_ES 17u
#define CYDEV_CHIP_REVISION_4G_ES2 33u
#define CYDEV_CHIP_REVISION_4G_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4H_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4I_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4J_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4K_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4L_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4M_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4N_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4O_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4P_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4R_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4S_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4T_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4U_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4V_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4W_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4X_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Y_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Z_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_6A_ES 17u
#define CYDEV_CHIP_REVISION_6A_NO_UDB 33u
#define CYDEV_CHIP_REVISION_6A_PRODUCTION 33u
#define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_5B_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CONFIG_FASTBOOT_ENABLED 1
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_AllowButWarn
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_CONFIGURATION_COMPRESSED 1
#define CYDEV_CONFIGURATION_DMA 0
#define CYDEV_CONFIGURATION_ECC 1
#define CYDEV_CONFIGURATION_IMOENABLED CYDEV_CONFIG_FASTBOOT_ENABLED
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_COMPRESSED
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_DEBUG_ENABLE_MASK 0x20u
#define CYDEV_DEBUG_ENABLE_REGISTER CYREG_MLOGIC_DEBUG
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_JTAG_4 1
#define CYDEV_DEBUGGING_DPS_JTAG_5 0
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_DPS_SWD_SWV 6
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD_SWV
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_DEBUGGING_XRES 0
#define CYDEV_DMA_CHANNELS_AVAILABLE 24u
#define CYDEV_ECC_ENABLE 0
#define CYDEV_HEAP_SIZE 0x2000
#define CYDEV_INSTRUCT_CACHE_ENABLED 1
#define CYDEV_INTR_RISING 0x0000001Fu
#define CYDEV_IS_EXPORTING_CODE 0
#define CYDEV_IS_IMPORTING_CODE 0
#define CYDEV_PROJ_TYPE 0
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LAUNCHER 5
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER 4
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_PROTECTION_ENABLE 0
#define CYDEV_STACK_SIZE 0x0800
#define CYDEV_USE_BUNDLED_CMSIS 1
#define CYDEV_VARIABLE_VDDA 0
#define CYDEV_VDDA 5.0
#define CYDEV_VDDA_MV 5000
#define CYDEV_VDDD 5.0
#define CYDEV_VDDD_MV 5000
#define CYDEV_VDDIO0 5.0
#define CYDEV_VDDIO0_MV 5000
#define CYDEV_VDDIO1 5.0
#define CYDEV_VDDIO1_MV 5000
#define CYDEV_VDDIO2 5.0
#define CYDEV_VDDIO2_MV 5000
#define CYDEV_VDDIO3 5.0
#define CYDEV_VDDIO3_MV 5000
#define CYDEV_VIO0 5.0
#define CYDEV_VIO0_MV 5000
#define CYDEV_VIO1 5.0
#define CYDEV_VIO1_MV 5000
#define CYDEV_VIO2 5.0
#define CYDEV_VIO2_MV 5000
#define CYDEV_VIO3 5.0
#define CYDEV_VIO3_MV 5000
#define CYIPBLOCK_ARM_CM3_VERSION 0
#define CYIPBLOCK_P3_ANAIF_VERSION 0
#define CYIPBLOCK_P3_CAN_VERSION 0
#define CYIPBLOCK_P3_CAPSENSE_VERSION 0
#define CYIPBLOCK_P3_COMP_VERSION 0
#define CYIPBLOCK_P3_DECIMATOR_VERSION 0
#define CYIPBLOCK_P3_DFB_VERSION 0
#define CYIPBLOCK_P3_DMA_VERSION 0
#define CYIPBLOCK_P3_DRQ_VERSION 0
#define CYIPBLOCK_P3_DSM_VERSION 0
#define CYIPBLOCK_P3_EMIF_VERSION 0
#define CYIPBLOCK_P3_I2C_VERSION 0
#define CYIPBLOCK_P3_LCD_VERSION 0
#define CYIPBLOCK_P3_LPF_VERSION 0
#define CYIPBLOCK_P3_OPAMP_VERSION 0
#define CYIPBLOCK_P3_PM_VERSION 0
#define CYIPBLOCK_P3_SCCT_VERSION 0
#define CYIPBLOCK_P3_TIMER_VERSION 0
#define CYIPBLOCK_P3_USB_VERSION 0
#define CYIPBLOCK_P3_VIDAC_VERSION 0
#define CYIPBLOCK_P3_VREF_VERSION 0
#define CYIPBLOCK_S8_GPIO_VERSION 0
#define CYIPBLOCK_S8_IRQ_VERSION 0
#define CYIPBLOCK_S8_SAR_VERSION 0
#define CYIPBLOCK_S8_SIO_VERSION 0
#define CYIPBLOCK_S8_UDB_VERSION 0
#define DMA_CHANNELS_USED__MASK0 0x00000403u
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */
