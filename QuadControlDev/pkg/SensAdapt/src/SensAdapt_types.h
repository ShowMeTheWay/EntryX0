/*
 * File: SensAdapt_types.h
 *
 * Code generated for Simulink model 'SensAdapt'.
 *
 * Model version                  : 1.366
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 19 2013)
 * C/C++ source code generated on : Fri Oct 05 23:13:24 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SensAdapt_types_h_
#define RTW_HEADER_SensAdapt_types_h_
#include "rtwtypes.h"
#ifndef _DEFINED_TYPEDEF_FOR_IMU_tstInRawData_
#define _DEFINED_TYPEDEF_FOR_IMU_tstInRawData_

/* Uart data to be displayed  */
typedef struct {
  real_T AccXData;
  real_T AccYData;
  real_T AccZData;
  real_T GyroXData;
  real_T GyroYData;
  real_T GyroZData;
} IMU_tstInRawData;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_IMU_tstRawData_
#define _DEFINED_TYPEDEF_FOR_IMU_tstRawData_

/* Uart data to be displayed  */
typedef struct {
  real_T AccXDataS;
  real_T AccYDataS;
  real_T AccZDataS;
  real_T GyroXDataS;
  real_T GyroYDataS;
  real_T GyroZDataS;
  real_T q0;
  real_T q1;
  real_T q2;
  real_T q3;
} IMU_tstRawData;

#endif
#endif                                 /* RTW_HEADER_SensAdapt_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
