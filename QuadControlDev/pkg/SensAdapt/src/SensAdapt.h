/*
 * File: SensAdapt.h
 *
 * Code generated for Simulink model 'SensAdapt'.
 *
 * Model version                  : 1.95
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 19 2013)
 * C/C++ source code generated on : Sat Jun 02 11:43:10 2018
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
  real_T u16AccXData;                  /* '<Root>/Bus Selector' */
  real_T u16AccYData;                  /* '<Root>/Bus Selector' */
  real_T u16AccZData;                  /* '<Root>/Bus Selector' */
  real_T u16GyroXData;                 /* '<Root>/Bus Selector' */
  real_T u16GyroYData;                 /* '<Root>/Bus Selector' */
  real_T u16GyroZData;                 /* '<Root>/Bus Selector' */
  real_T Product;                      /* '<S14>/Product' */
  real_T Product_bkqq;                 /* '<S13>/Product' */
  real_T Product_igt4;                 /* '<S12>/Product' */
  real_T Product_kzvd;                 /* '<S11>/Product' */
  real_T Product_hx1x;                 /* '<S10>/Product' */
  real_T Product_chkv;                 /* '<S9>/Product' */
  real_T Product_a1oc;                 /* '<S8>/Product' */
  real_T Product_kzgj;                 /* '<S7>/Product' */
  real_T Product_m02k;                 /* '<S6>/Product' */
  real_T Product_jsq1;                 /* '<S5>/Product' */
  real_T Product_bnex;                 /* '<S4>/Product' */
  real_T Product_mq0i;                 /* '<S3>/Product' */
  real_T accx;                         /* '<S2>/accx' */
  real_T accy;                         /* '<S2>/accy' */
  real_T accz;                         /* '<S2>/accz' */
  real_T accx_gf4n;                    /* '<S1>/accx' */
  real_T accy_azyn;                    /* '<S1>/accy' */
  real_T accz_nuj4;                    /* '<S1>/accz' */
} BlockIO_SensAdapt;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  IMU_tstRawData UnitDelay12_DSTATE;   /* '<Root>/Unit Delay12' */
  real_T TappedDelay_X[19];            /* '<S14>/Tapped Delay' */
  real_T TappedDelay_X_ekvt[19];       /* '<S13>/Tapped Delay' */
  real_T TappedDelay_X_lceu[19];       /* '<S12>/Tapped Delay' */
  real_T TappedDelay_X_la2x[19];       /* '<S11>/Tapped Delay' */
  real_T TappedDelay_X_kvli[19];       /* '<S10>/Tapped Delay' */
  real_T TappedDelay_X_b4iy[19];       /* '<S9>/Tapped Delay' */
  real_T TappedDelay_X_cw5c[19];       /* '<S8>/Tapped Delay' */
  real_T TappedDelay_X_ouxw[19];       /* '<S7>/Tapped Delay' */
  real_T TappedDelay_X_jphy[19];       /* '<S6>/Tapped Delay' */
  real_T TappedDelay_X_iau4[19];       /* '<S5>/Tapped Delay' */
  real_T TappedDelay_X_ido1[19];       /* '<S4>/Tapped Delay' */
  real_T TappedDelay_X_n51i[19];       /* '<S3>/Tapped Delay' */
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
 * '<S1>'   : 'SensAdapt/AccConvToG'
 * '<S2>'   : 'SensAdapt/GyroConvToRadpsec'
 * '<S3>'   : 'SensAdapt/smoothData'
 * '<S4>'   : 'SensAdapt/smoothData1'
 * '<S5>'   : 'SensAdapt/smoothData10'
 * '<S6>'   : 'SensAdapt/smoothData11'
 * '<S7>'   : 'SensAdapt/smoothData2'
 * '<S8>'   : 'SensAdapt/smoothData3'
 * '<S9>'   : 'SensAdapt/smoothData4'
 * '<S10>'  : 'SensAdapt/smoothData5'
 * '<S11>'  : 'SensAdapt/smoothData6'
 * '<S12>'  : 'SensAdapt/smoothData7'
 * '<S13>'  : 'SensAdapt/smoothData8'
 * '<S14>'  : 'SensAdapt/smoothData9'
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
