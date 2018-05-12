/*
 * File: model.c
 *
 * Code generated for Simulink model 'model'.
 *
 * Model version                  : 1.63
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 19 2013)
 * C/C++ source code generated on : Sat May 12 21:04:45 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "model.h"
#include "model_private.h"

/* Block states (auto storage) */
D_Work_model model_DWork;

/* Model step function */
void model_step(void)
{
  int32_T rtb_data2;
  uint8_T rtb_FixPtSum1;
  int32_T PulseGenerator;

  /* UnitDelay: '<Root>/Unit Delay' */
  UART_DisplayData(model_DWork.UnitDelay_DSTATE);

  /* DiscretePulseGenerator: '<Root>/Pulse Generator1' */
  rtb_data2 = ((model_DWork.clockTickCounter < 650) &&
               (model_DWork.clockTickCounter >= 0)) ? 1 : 0;
  if (model_DWork.clockTickCounter >= 1299) {
    model_DWork.clockTickCounter = 0;
  } else {
    model_DWork.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator1' */

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  PulseGenerator = ((model_DWork.clockTickCounter_a01h < 650) &&
                    (model_DWork.clockTickCounter_a01h >= 0)) ? 1 : 0;
  if (model_DWork.clockTickCounter_a01h >= 1299) {
    model_DWork.clockTickCounter_a01h = 0;
  } else {
    model_DWork.clockTickCounter_a01h++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* Sum: '<S4>/FixPt Sum1' incorporates:
   *  Constant: '<S4>/FixPt Constant'
   *  UnitDelay: '<S3>/Output'
   */
  rtb_FixPtSum1 = (uint8_T)(model_DWork.Output_DSTATE + 1U);

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
  model_DWork.UnitDelay_DSTATE.data1 = 0.00995 *
    model_DWork.DiscreteTransferFcn_states;
  model_DWork.UnitDelay_DSTATE.data2 = rtb_data2;
  model_DWork.UnitDelay_DSTATE.data3 = model_ConstP.Vector_Value
    [(model_DWork.Output_DSTATE)];
  model_DWork.UnitDelay_DSTATE.data4 = 2.0 * sin(((((real_T)model_DWork.counter)
    * 2.0) * 3.1415926535897931) / 100.0);

  /* Update for DiscreteTransferFcn: '<S2>/Discrete Transfer Fcn' */
  model_DWork.DiscreteTransferFcn_states = ((real_T)PulseGenerator) - (-0.99 *
    model_DWork.DiscreteTransferFcn_states);

  /* Update for UnitDelay: '<S3>/Output' */
  model_DWork.Output_DSTATE = rtb_FixPtSum1;

  /* Update for Sin: '<Root>/Sine Wave' */
  model_DWork.counter++;
  if (model_DWork.counter == 100) {
    model_DWork.counter = 0;
  }

  /* End of Update for Sin: '<Root>/Sine Wave' */
}

/* Model initialize function */
void model_initialize(void)
{
  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)&model_DWork, 0,
                sizeof(D_Work_model));
  model_DWork.DiscreteTransferFcn_states = 0.0;

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator1' */
  model_DWork.clockTickCounter = 0;

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  model_DWork.clockTickCounter_a01h = 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
