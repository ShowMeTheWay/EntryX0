/*
 * File: SensAdapt_private.h
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

extern void SensAdapt_AccConvToG(void);
extern void SensAdapt_GyroConvToRadpsec(void);
extern void SensAdapt_smoothData_Init(void);
extern void SensAdapt_smoothData(void);
extern void SensAdapt_smoothData1_Init(void);
extern void SensAdapt_smoothData1(void);
extern void SensAdapt_smoothData10_Init(void);
extern void SensAdapt_smoothData10(void);
extern void SensAdapt_smoothData11_Init(void);
extern void SensAdapt_smoothData11(void);
extern void SensAdapt_smoothData2_Init(void);
extern void SensAdapt_smoothData2(void);
extern void SensAdapt_smoothData3_Init(void);
extern void SensAdapt_smoothData3(void);
extern void SensAdapt_smoothData4_Init(void);
extern void SensAdapt_smoothData4(void);
extern void SensAdapt_smoothData5_Init(void);
extern void SensAdapt_smoothData5(void);
extern void SensAdapt_smoothData6_Init(void);
extern void SensAdapt_smoothData6(void);
extern void SensAdapt_smoothData7_Init(void);
extern void SensAdapt_smoothData7(void);
extern void SensAdapt_smoothData8_Init(void);
extern void SensAdapt_smoothData8(void);
extern void SensAdapt_smoothData9_Init(void);
extern void SensAdapt_smoothData9(void);

#endif                                 /* RTW_HEADER_SensAdapt_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
