/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: DABfolder_ADC.c
 *
 * Code generated for Simulink model :DABfolder.
 *
 * Model version      : 1.41
 * Simulink Coder version    : 9.5 (R2021a) 14-Nov-2020
 * TLC version       : 9.5 (Feb 18 2021)
 * C/C++ source code generated on  : Wed May 18 15:37:06 2022
 *
 * Target selection: stm32.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 *
 *
 * ******************************************************************************
 * * attention
 * *
 * * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 * * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
 * * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 * * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 * * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 * *
 * ******************************************************************************
 */

#include "DABfolder.h"
#include "DABfolder_ADC.h"

/* Number of ADC configured. */
uint16_t G_ADC_Count = 0;

/* Array of ADC informations. */
ADC_ConfTypeDef* G_ADC_Conf[2];
ADC_HandleTypeDef* G_ADC_Handler[2];

/* ADC2 Regular channel Converted value buffer */
uint16_t ADC2_RegularConvertedValue[1];

/* ADC2 informations. */
ADC_ConfTypeDef ADC2_Conf = {
  /* Regular channels. */
  NULL, 0, 0,

  /* Injected channels. */
  NULL, 0, ADC_INJECTED_RANK_1,

  /* Dma. */
  0, false,

  /* End of conversion. */
  false,

  /* Interrupts callbacks. */
  NULL, NULL, NULL, NULL, NULL, NULL
};

/* ADC2 polling timeout value. Number of Solver loop. (can be changed)*/
uint32_t G_ADC2_PollTimeOut = 10;

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] DABfolder_ADC.c
 */
