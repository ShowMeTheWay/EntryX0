/*
 * File: SensAdapt.h
 *
 * Code generated for Simulink model 'SensAdapt'.
 *
 * Model version                  : 1.89
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 19 2013)
 * C/C++ source code generated on : Sun May 27 00:50:37 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SensAdapt_h_
#define RTW_HEADER_SensAdapt_h_
#ifndef SensAdapt_COMMON_INCLUDES_
# define SensAdapt_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* SensAdapt_COMMON_INCLUDES_ */

#include "SensAdapt_types.h"

/* Macros for accessing real-time model data structure */

/* Block signals (auto storage) */
typedef struct {
  uint16_T u16AccXData;                /* '<Root>/Bus Selector' */
  uint16_T u16AccYData;                /* '<Root>/Bus Selector' */
  uint16_T u16AccZData;                /* '<Root>/Bus Selector' */
  uint16_T u16GyroXData;               /* '<Root>/Bus Selector' */
  uint16_T u16GyroYData;               /* '<Root>/Bus Selector' */
  uint16_T u16GyroZData;               /* '<Root>/Bus Selector' */
  uint16_T Product;                    /* '<S6>/Product' */
  uint16_T Product_chkv;               /* '<S5>/Product' */
  uint16_T Product_a1oc;               /* '<S4>/Product' */
  uint16_T Product_kzgj;               /* '<S3>/Product' */
  uint16_T Product_bnex;               /* '<S2>/Product' */
  uint16_T Product_mq0i;               /* '<S1>/Product' */
} BlockIO_SensAdapt;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  IMU_tstRawData UnitDelay12_DSTATE;   /* '<Root>/Unit Delay12' */
  uint16_T TappedDelay_X[9];           /* '<S6>/Tapped Delay' */
  uint16_T TappedDelay_X_b4iy[9];      /* '<S5>/Tapped Delay' */
  uint16_T TappedDelay_X_cw5c[9];      /* '<S4>/Tapped Delay' */
  uint16_T TappedDelay_X_ouxw[9];      /* '<S3>/Tapped Delay' */
  uint16_T TappedDelay_X_ido1[9];      /* '<S2>/Tapped Delay' */
  uint16_T TappedDelay_X_n51i[9];      /* '<S1>/Tapped Delay' */
} D_Work_SensAdapt;

/* Block signals (auto storage) */
extern BlockIO_SensAdapt SensAdapt_B;

/* Block states (auto storage) */
extern D_Work_SensAdapt SensAdapt_DWork;

/* Model entry point functions */
extern void SensAdapt_initialize(void);
extern void SensAdapt_step(void);

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
 * '<Root>' : 'SensAdapt'
 * '<S1>'   : 'SensAdapt/smoothData'
 * '<S2>'   : 'SensAdapt/smoothData1'
 * '<S3>'   : 'SensAdapt/smoothData2'
 * '<S4>'   : 'SensAdapt/smoothData3'
 * '<S5>'   : 'SensAdapt/smoothData4'
 * '<S6>'   : 'SensAdapt/smoothData5'
 */

/*-
 * Requirements for '<Root>': SensAdapt
 */
#endif                                 /* RTW_HEADER_SensAdapt_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
