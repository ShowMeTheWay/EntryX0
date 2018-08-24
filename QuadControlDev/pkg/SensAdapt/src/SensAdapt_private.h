/*
 * File: SensAdapt_private.h
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

#ifndef RTW_HEADER_SensAdapt_private_h_
#define RTW_HEADER_SensAdapt_private_h_
#include "rtwtypes.h"

/* Includes for objects with custom storage classes. */
#include "imu.h"
#include "mdlSensInterface.h"
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else

/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                 /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

extern void madgwick_f_Outputs_wrapper(const real_T *accx,
  const real_T *accy,
  const real_T *accz,
  const real_T *gyrox,
  const real_T *gyroy,
  const real_T *gyroz,
  real_T *qt0,
  real_T *qt1,
  real_T *qt2,
  real_T *qt3);
extern void SensAdapt_AccConv(void);
extern void SensAdapt_GyroConv(void);
extern void SensAdapt_calibrationBlock(void);
extern void SensAdapt_smoothData_Init(void);
extern void SensAdapt_smoothData(void);

#endif                                 /* RTW_HEADER_SensAdapt_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
