/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: DABfolder.c
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
#include "DABfolder_private.h"

/* Block signals (default storage) */
B_DABfolder DABfolder_B;

/* Real-time model */
static RT_MODEL_DABfolder DABfolder_M_;
RT_MODEL_DABfolder *const DABfolder_M = &DABfolder_M_;

/* Model step function */
void DABfolder_step(void)
{
  {
    uint16_t i;

    /* Read regular ADC2 value */
    for (i=0; i<1; i++) {
      if (HAL_ADC_PollForConversion(&hadc2, G_ADC2_PollTimeOut) == HAL_OK) {
        ADC2_RegularConvertedValue[i] = (uint16_t)HAL_ADC_GetValue(&hadc2);
      }
    }
  }

  /* Get regular rank1 output value from ADC2 regular value buffer */
  DABfolder_B.ADC_Read2 = ADC2_RegularConvertedValue[0];

  /* Re-Start ADC2 conversion */
  HAL_ADC_Start(&hadc2);


    double D=-0.5; //Between -0.5 and 0.5
    double PhaseShiftValue=0;
    //if (D<=0.5 && D>0){
    // PhaseShiftValue=25+50*D; //Between 25 and 50
    //}
    //else if (D>=-0.5 && D<0) {
    // PhaseShiftValue=25+50*(-D); //between 0 and 25;
    //}
    //else { PhaseShiftValue=25; //Used to control the primary bridge (between 0 and 50, where 50 is a phase shift of D=0.5, and 0, is D=-0.5)
    //}

    int CCR = 25; //Used to control the secondary bridge, but no need to change.

    PhaseShiftValue=25+50*(D);

 	DABfolder_B.Add2 = PhaseShiftValue * (-1.0) + 50.0;

  {
    /* CCR1 */
    TIM1->CCR1 = PhaseShiftValue;
  }

  {
    /* CCR2 */
    TIM1->CCR2 = DABfolder_B.Add2;
  }

  {
    /* CCR3 */
    TIM1->CCR3 = CCR;
  }

  {
    /* CCR4 */
    TIM1->CCR4 = CCR * (-1.0) + 50.0;
  }
}

/* Model initialize function */
void DABfolder_initialize(void)
{
  {
    /* user code (Start function Header) */
    {
      /* ADC2 initialization. */
      /* Store ADC2 informations and its handler. */
      G_ADC_Conf[G_ADC_Count] = &ADC2_Conf;
      G_ADC_Handler[G_ADC_Count] = &hadc2;
      G_ADC_Count++;
      ADC2_Conf.regularBuffer = ADC2_RegularConvertedValue;
      ADC2_Conf.regularCount = 1;
    }

    /* user code (Start function Body) */
    {
      /* ADC2 Start. */
      /* Start ADC2 conversion. */
      HAL_ADC_Start(&hadc2);
    }
  }
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] DABfolder.c
 */
