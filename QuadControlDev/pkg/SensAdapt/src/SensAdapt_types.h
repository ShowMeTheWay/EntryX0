/*
 * File: SensAdapt_types.h
 *
 * Code generated for Simulink model 'SensAdapt'.
 *
 * Model version                  : 1.95
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 19 2013)
 * C/C++ source code generated on : Fri Jun 01 22:36:56 2018
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
  real_T u16AccXData;
  real_T u16AccYData;
  real_T u16AccZData;
  real_T u16GyroXData;
  real_T u16GyroYData;
  real_T u16GyroZData;
} IMU_tstInRawData;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_IMU_tstRawData_
#define _DEFINED_TYPEDEF_FOR_IMU_tstRawData_

/* Uart data to be displayed  */
typedef struct {
  real_T u16AccXDataS;
  real_T u16AccYDataS;
  real_T u16AccZDataS;
  real_T u16GyroXDataS;
  real_T u16GyroYDataS;
  real_T u16GyroZDataS;
  real_T signal7;
  real_T signal8;
  real_T signal9;
  real_T signal10;
  real_T signal11;
  real_T signal12;
} IMU_tstRawData;

#endif
#endif                                 /* RTW_HEADER_SensAdapt_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
