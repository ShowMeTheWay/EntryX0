/*
 * File: SensAdapt.c
 *
 * Code generated for Simulink model 'SensAdapt'.
 *
 * Model version                  : 1.63
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 19 2013)
 * C/C++ source code generated on : Tue May 15 00:45:34 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SensAdapt.h"
#include "SensAdapt_private.h"

/* Block states (auto storage) */
D_Work_SensAdapt SensAdapt_DWork;

/* Model step function */
void SensAdapt_step(void)
{
  int32_T rtb_data2;
  uint8_T rtb_FixPtSum1;
  int32_T PulseGenerator;

  /* UnitDelay: '<Root>/Unit Delay' */
  UART_DisplayData(SensAdapt_DWork.UnitDelay_DSTATE);

  /* DiscretePulseGenerator: '<Root>/Pulse Generator1' */
  rtb_data2 = ((SensAdapt_DWork.clockTickCounter < 650) &&
               (SensAdapt_DWork.clockTickCounter >= 0)) ? 1 : 0;
  if (SensAdapt_DWork.clockTickCounter >= 1299) {
    SensAdapt_DWork.clockTickCounter = 0;
  } else {
    SensAdapt_DWork.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator1' */

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  PulseGenerator = ((SensAdapt_DWork.clockTickCounter_a01h < 650) &&
                    (SensAdapt_DWork.clockTickCounter_a01h >= 0)) ? 1 : 0;
  if (SensAdapt_DWork.clockTickCounter_a01h >= 1299) {
    SensAdapt_DWork.clockTickCounter_a01h = 0;
  } else {
    SensAdapt_DWork.clockTickCounter_a01h++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* Sum: '<S4>/FixPt Sum1' incorporates:
   *  Constant: '<S4>/FixPt Constant'
   *  UnitDelay: '<S3>/Output'
   */
  rtb_FixPtSum1 = (uint8_T)(SensAdapt_DWork.Output_DSTATE + 1U);

  /* Switch: '<S5>/FixPt Switch' incorporates:
   *  Constant: '<S5>/Constant'
   */
  if (rtb_FixPtSum1 > 8) {
    rtb_FixPtSum1 = 0U;
  }

  /* End of Switch: '<S5>/FixPt Switch' */

  /* Update for UnitDelay: '<Root>/Unit Delay' incorporates:
   *  BusCreator: '<Root>/Bus Creator'
   *  Constant: '<S1>/Vector'
   *  DiscreteTransferFcn: '<S2>/Discrete Transfer Fcn'
   *  MultiPortSwitch: '<S1>/Output'
   *  Sin: '<Root>/Sine Wave'
   *  UnitDelay: '<S3>/Output'
   */
  SensAdapt_DWork.UnitDelay_DSTATE.data1 = 0.00995 *
    SensAdapt_DWork.DiscreteTransferFcn_states;
  SensAdapt_DWork.UnitDelay_DSTATE.data2 = rtb_data2;
  SensAdapt_DWork.UnitDelay_DSTATE.data3 = SensAdapt_ConstP.Vector_Value
    [(SensAdapt_DWork.Output_DSTATE)];
  SensAdapt_DWork.UnitDelay_DSTATE.data4 = 2.0 * sin(((((real_T)
    SensAdapt_DWork.counter) * 2.0) * 3.1415926535897931) / 100.0);

  /* Update for DiscreteTransferFcn: '<S2>/Discrete Transfer Fcn' */
  SensAdapt_DWork.DiscreteTransferFcn_states = ((real_T)PulseGenerator) - (-0.99
    * SensAdapt_DWork.DiscreteTransferFcn_states);

  /* Update for UnitDelay: '<S3>/Output' */
  SensAdapt_DWork.Output_DSTATE = rtb_FixPtSum1;

  /* Update for Sin: '<Root>/Sine Wave' */
  SensAdapt_DWork.counter++;
  if (SensAdapt_DWork.counter == 100) {
    SensAdapt_DWork.counter = 0;
  }

  /* End of Update for Sin: '<Root>/Sine Wave' */
}

/* Model initialize function */
void SensAdapt_initialize(void)
{
  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)&SensAdapt_DWork, 0,
                sizeof(D_Work_SensAdapt));
  SensAdapt_DWork.DiscreteTransferFcn_states = 0.0;

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator1' */
  SensAdapt_DWork.clockTickCounter = 0;

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  SensAdapt_DWork.clockTickCounter_a01h = 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
