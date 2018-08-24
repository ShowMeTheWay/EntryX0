/*
 * File: SensAdapt.h
 *
 * Code generated for Simulink model 'SensAdapt'.
 *
 * Model version                  : 1.246
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 19 2013)
 * C/C++ source code generated on : Fri Aug 24 19:41:56 2018
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
  real_T AccXData;                     /* '<Root>/Bus Selector' */
  real_T AccYData;                     /* '<Root>/Bus Selector' */
  real_T AccZData;                     /* '<Root>/Bus Selector' */
  real_T GyroXData;                    /* '<Root>/Bus Selector' */
  real_T GyroYData;                    /* '<Root>/Bus Selector' */
  real_T GyroZData;                    /* '<Root>/Bus Selector' */
  real_T SFunctionBuilder1_o1;         /* '<S5>/S-Function Builder1' */
  real_T SFunctionBuilder1_o2;         /* '<S5>/S-Function Builder1' */
  real_T SFunctionBuilder1_o3;         /* '<S5>/S-Function Builder1' */
  real_T SFunctionBuilder1_o4;         /* '<S5>/S-Function Builder1' */
  real_T Product;                      /* '<S8>/Product' */
  real_T Product_jqhr;                 /* '<S9>/Product' */
  real_T Product_krg1;                 /* '<S10>/Product' */
  real_T Product_nhwi;                 /* '<S11>/Product' */
  real_T Product_ax4f;                 /* '<S12>/Product' */
  real_T Product_pz1k;                 /* '<S13>/Product' */
  real_T axc;                          /* '<S3>/MATLAB Function' */
  real_T ayc;                          /* '<S3>/MATLAB Function' */
  real_T azc;                          /* '<S3>/MATLAB Function' */
  real_T gxc;                          /* '<S3>/MATLAB Function' */
  real_T gyc;                          /* '<S3>/MATLAB Function' */
  real_T gzc;                          /* '<S3>/MATLAB Function' */
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
  real_T TappedDelay_X[9];             /* '<S8>/Tapped Delay' */
  real_T TappedDelay_X_h4nz[9];        /* '<S9>/Tapped Delay' */
  real_T TappedDelay_X_auph[9];        /* '<S10>/Tapped Delay' */
  real_T TappedDelay_X_ahra[9];        /* '<S11>/Tapped Delay' */
  real_T TappedDelay_X_nmbc[9];        /* '<S12>/Tapped Delay' */
  real_T TappedDelay_X_byda[9];        /* '<S13>/Tapped Delay' */
} D_Work_SensAdapt;

/* Block signals (auto storage) */
extern BlockIO_SensAdapt SensAdapt_B;

/* Block states (auto storage) */
extern D_Work_SensAdapt SensAdapt_DWork;

/* Model entry point functions */
extern void SensAdapt_initialize(void);
extern void SensAdapt_step(void);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Multiport Switch' : Eliminated due to constant selection input
 * Block '<S2>/Multiport Switch' : Eliminated due to constant selection input
 * Block '<S1>/Constant' : Unused code path elimination
 * Block '<S1>/choose' : Unused code path elimination
 * Block '<S1>/tomssquare' : Unused code path elimination
 * Block '<S2>/Constant1' : Unused code path elimination
 * Block '<S2>/choose' : Unused code path elimination
 * Block '<S2>/choose1' : Unused code path elimination
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
 * '<Root>' : 'SensAdapt'
 * '<S1>'   : 'SensAdapt/AccConv'
 * '<S2>'   : 'SensAdapt/GyroConv'
 * '<S3>'   : 'SensAdapt/calibrationBlock'
 * '<S4>'   : 'SensAdapt/nothing'
 * '<S5>'   : 'SensAdapt/processData'
 * '<S6>'   : 'SensAdapt/smoothData'
 * '<S7>'   : 'SensAdapt/calibrationBlock/MATLAB Function'
 * '<S8>'   : 'SensAdapt/smoothData/filter'
 * '<S9>'   : 'SensAdapt/smoothData/filter1'
 * '<S10>'  : 'SensAdapt/smoothData/filter2'
 * '<S11>'  : 'SensAdapt/smoothData/filter3'
 * '<S12>'  : 'SensAdapt/smoothData/filter4'
 * '<S13>'  : 'SensAdapt/smoothData/filter5'
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
