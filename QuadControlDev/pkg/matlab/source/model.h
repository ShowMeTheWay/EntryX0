/*
 * File: model.h
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

#ifndef RTW_HEADER_model_h_
#define RTW_HEADER_model_h_
#ifndef model_COMMON_INCLUDES_
# define model_COMMON_INCLUDES_
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* model_COMMON_INCLUDES_ */

#include "model_types.h"

/* Macros for accessing real-time model data structure */

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  UART_tstDataDisplayed UnitDelay_DSTATE;/* '<Root>/Unit Delay' */
  real_T DiscreteTransferFcn_states;   /* '<S2>/Discrete Transfer Fcn' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator1' */
  int32_T counter;                     /* '<Root>/Sine Wave' */
  int32_T clockTickCounter_a01h;       /* '<Root>/Pulse Generator' */
  uint8_T Output_DSTATE;               /* '<S3>/Output' */
} D_Work_model;

/* Constant parameters (auto storage) */
typedef struct {
  /* Expression: OutValues
   * Referenced by: '<S1>/Vector'
   */
  real_T Vector_Value[9];
} ConstParam_model;

/* Block states (auto storage) */
extern D_Work_model model_DWork;

/* Constant parameters (auto storage) */
extern const ConstParam_model model_ConstP;

/* Model entry point functions */
extern void model_initialize(void);
extern void model_step(void);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Data Type Propagation' : Unused code path elimination
 * Block '<S4>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S5>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S1>/Out' : Eliminate redundant signal conversion block
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'model'
 * '<S1>'   : 'model/Repeating Sequence Stair1'
 * '<S2>'   : 'model/Subsystem'
 * '<S3>'   : 'model/Repeating Sequence Stair1/LimitedCounter'
 * '<S4>'   : 'model/Repeating Sequence Stair1/LimitedCounter/Increment Real World'
 * '<S5>'   : 'model/Repeating Sequence Stair1/LimitedCounter/Wrap To Zero'
 */

/*-
 * Requirements for '<Root>': model
 */
#endif                                 /* RTW_HEADER_model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
