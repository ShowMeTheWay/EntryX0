/*
 * File: SensAdapt.h
 *
 * Code generated for Simulink model 'SensAdapt'.
 *
 * Model version                  : 1.391
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 19 2013)
 * C/C++ source code generated on : Sun May 19 14:18:58 2019
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
#include <math.h>
#include "rtwtypes.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#endif                                 /* SensAdapt_COMMON_INCLUDES_ */

#include "SensAdapt_types.h"

/* Macros for accessing real-time model data structure */

/* Block signals (auto storage) */
typedef struct {
  real_T AccXData;                     /* '<S1>/Bus Selector' */
  real_T AccYData;                     /* '<S1>/Bus Selector' */
  real_T AccZData;                     /* '<S1>/Bus Selector' */
  real_T GyroXData;                    /* '<S1>/Bus Selector' */
  real_T GyroYData;                    /* '<S1>/Bus Selector' */
  real_T GyroZData;                    /* '<S1>/Bus Selector' */
  real_T Merge[7];                     /* '<S7>/Merge' */
  real_T SFunctionBuilder1_o1;         /* '<S18>/S-Function Builder1' */
  real_T SFunctionBuilder1_o2;         /* '<S18>/S-Function Builder1' */
  real_T SFunctionBuilder1_o3;         /* '<S18>/S-Function Builder1' */
  real_T SFunctionBuilder1_o4;         /* '<S18>/S-Function Builder1' */
  real_T SFunctionBuilder1_o1_gqrs;    /* '<S20>/S-Function Builder1' */
  real_T SFunctionBuilder1_o2_piyk;    /* '<S20>/S-Function Builder1' */
  real_T SFunctionBuilder1_o3_cr03;    /* '<S20>/S-Function Builder1' */
  real_T Add;                          /* '<S9>/Add' */
  real_T Add_g0zf;                     /* '<S11>/Add' */
  real_T Add_p1ev;                     /* '<S10>/Add' */
  real_T gyrox_data_in;                /* '<S6>/gyrox_data_in' */
  real_T gyroy_data_in;                /* '<S6>/gyroy_data_in' */
  real_T gyroz_data_in;                /* '<S6>/gyroz_data_in' */
  real_T axc;                          /* '<S4>/MATLAB Function' */
  real_T ayc;                          /* '<S4>/MATLAB Function' */
  real_T azc;                          /* '<S4>/MATLAB Function' */
  real_T gxc;                          /* '<S4>/MATLAB Function' */
  real_T gyc;                          /* '<S4>/MATLAB Function' */
  real_T gzc;                          /* '<S4>/MATLAB Function' */
  real_T accx;                         /* '<S3>/accx' */
  real_T accy;                         /* '<S3>/accy' */
  real_T accz;                         /* '<S3>/accz' */
  real_T accx_gf4n;                    /* '<S2>/accx' */
  real_T accy_azyn;                    /* '<S2>/accy' */
  real_T accz_nuj4;                    /* '<S2>/accz' */
} BlockIO_SensAdapt;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  IMU_tstRawData UnitDelay12_DSTATE;   /* '<S1>/Unit Delay12' */
  real_T UnitDelay_DSTATE_lkem;        /* '<S9>/Unit Delay' */
  real_T UnitDelay_DSTATE_lfj0;        /* '<S11>/Unit Delay' */
  real_T UnitDelay_DSTATE_er14;        /* '<S10>/Unit Delay' */
  real_T R[9];                         /* '<S19>/Data Store Memory' */
} D_Work_SensAdapt;

/* Constant parameters (auto storage) */
typedef struct {
  /* Expression: [1 0 0;0 1 0; 0 0 1]
   * Referenced by: '<S19>/Data Store Memory'
   */
  real_T DataStoreMemory_InitialValue[9];
} ConstParam_SensAdapt;

/* Block signals (auto storage) */
extern BlockIO_SensAdapt SensAdapt_B;

/* Block states (auto storage) */
extern D_Work_SensAdapt SensAdapt_DWork;

/* Constant parameters (auto storage) */
extern const ConstParam_SensAdapt SensAdapt_ConstP;

/* Model entry point functions */
extern void SensAdapt_initialize(void);
extern void SensAdapt_step(void);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Multiport Switch' : Eliminated due to constant selection input
 * Block '<S3>/Multiport Switch' : Eliminated due to constant selection input
 * Block '<S2>/Constant' : Unused code path elimination
 * Block '<S2>/choose' : Unused code path elimination
 * Block '<S2>/tog' : Unused code path elimination
 * Block '<S3>/Constant1' : Unused code path elimination
 * Block '<S3>/choose' : Unused code path elimination
 * Block '<S3>/choose1' : Unused code path elimination
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
 * '<S1>'   : 'SensAdapt/SensAdapt'
 * '<S2>'   : 'SensAdapt/SensAdapt/AccConv'
 * '<S3>'   : 'SensAdapt/SensAdapt/GyroConv'
 * '<S4>'   : 'SensAdapt/SensAdapt/calibrationBlock'
 * '<S5>'   : 'SensAdapt/SensAdapt/nothing'
 * '<S6>'   : 'SensAdapt/SensAdapt/smoothData'
 * '<S7>'   : 'SensAdapt/SensAdapt/stateEstimator'
 * '<S8>'   : 'SensAdapt/SensAdapt/calibrationBlock/MATLAB Function'
 * '<S9>'   : 'SensAdapt/SensAdapt/smoothData/FTJ'
 * '<S10>'  : 'SensAdapt/SensAdapt/smoothData/FTJ1'
 * '<S11>'  : 'SensAdapt/SensAdapt/smoothData/FTJ2'
 * '<S12>'  : 'SensAdapt/SensAdapt/smoothData/FTS'
 * '<S13>'  : 'SensAdapt/SensAdapt/smoothData/FTS1'
 * '<S14>'  : 'SensAdapt/SensAdapt/smoothData/FTS2'
 * '<S15>'  : 'SensAdapt/SensAdapt/smoothData/filter'
 * '<S16>'  : 'SensAdapt/SensAdapt/stateEstimator/geEstimator'
 * '<S17>'  : 'SensAdapt/SensAdapt/stateEstimator/kalEstimator'
 * '<S18>'  : 'SensAdapt/SensAdapt/stateEstimator/madgEstimator'
 * '<S19>'  : 'SensAdapt/SensAdapt/stateEstimator/geEstimator/Subsystem'
 * '<S20>'  : 'SensAdapt/SensAdapt/stateEstimator/geEstimator/Subsystem1'
 * '<S21>'  : 'SensAdapt/SensAdapt/stateEstimator/geEstimator/Subsystem/FTJ'
 * '<S22>'  : 'SensAdapt/SensAdapt/stateEstimator/geEstimator/Subsystem/FTJ1'
 * '<S23>'  : 'SensAdapt/SensAdapt/stateEstimator/geEstimator/Subsystem/FTJ2'
 * '<S24>'  : 'SensAdapt/SensAdapt/stateEstimator/geEstimator/Subsystem/MATLAB Function'
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
