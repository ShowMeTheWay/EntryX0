/*
 * File: SensAdapt.c
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

#include "SensAdapt.h"
#include "SensAdapt_private.h"

/* Block signals (auto storage) */
BlockIO_SensAdapt SensAdapt_B;

/* Block states (auto storage) */
D_Work_SensAdapt SensAdapt_DWork;

/* Output and update for atomic system: '<Root>/AccConvToG' */
void SensAdapt_AccConvToG(void)
{
  /* Product: '<S1>/accx' incorporates:
   *  Constant: '<S1>/Constant'
   */
  SensAdapt_B.accx_gf4n = SensAdapt_B.u16AccXData / 8192.0;

  /* Product: '<S1>/accy' incorporates:
   *  Constant: '<S1>/Constant'
   */
  SensAdapt_B.accy_azyn = SensAdapt_B.u16AccYData / 8192.0;

  /* Product: '<S1>/accz' incorporates:
   *  Constant: '<S1>/Constant'
   */
  SensAdapt_B.accz_nuj4 = SensAdapt_B.u16AccZData / 8192.0;
}

/* Output and update for atomic system: '<Root>/GyroConvToRadpsec' */
void SensAdapt_GyroConvToRadpsec(void)
{
  /* Product: '<S2>/accx' incorporates:
   *  Constant: '<S2>/Constant'
   */
  SensAdapt_B.accx = SensAdapt_B.u16GyroXData / 939.650784;

  /* Product: '<S2>/accy' incorporates:
   *  Constant: '<S2>/Constant'
   */
  SensAdapt_B.accy = SensAdapt_B.u16GyroYData / 939.650784;

  /* Product: '<S2>/accz' incorporates:
   *  Constant: '<S2>/Constant'
   */
  SensAdapt_B.accz = SensAdapt_B.u16GyroZData / 939.650784;
}

/* Initial conditions for atomic system: '<Root>/smoothData' */
void SensAdapt_smoothData_Init(void)
{
  int32_T i;

  /* InitializeConditions for S-Function (sfix_udelay): '<S3>/Tapped Delay' */
  for (i = 0; i < 9; i++) {
    SensAdapt_DWork.TappedDelay_X_n51i[i] = 9.0;
  }

  /* End of InitializeConditions for S-Function (sfix_udelay): '<S3>/Tapped Delay' */
}

/* Output and update for atomic system: '<Root>/smoothData' */
void SensAdapt_smoothData(void)
{
  int_T i;
  real_T rtb_VectorConcatenate[10];
  real_T tmp;

  /* SignalConversion: '<S3>/ConcatBufferAtVector ConcatenateIn1' */
  rtb_VectorConcatenate[0] = SensAdapt_B.u16AccXData;

  /* S-Function (sfix_udelay): '<S3>/Tapped Delay' */
  memcpy(&rtb_VectorConcatenate[1], &SensAdapt_DWork.TappedDelay_X_n51i[0], 9U *
         (sizeof(real_T)));

  /* Sum: '<S3>/Sum of Elements' */
  tmp = rtb_VectorConcatenate[0];
  for (i = 0; i < 9; i++) {
    tmp += rtb_VectorConcatenate[i + 1];
  }

  /* Product: '<S3>/Product' incorporates:
   *  Sum: '<S3>/Sum of Elements'
   */
  SensAdapt_B.Product_mq0i = tmp / 10.0;

  /* Update for S-Function (sfix_udelay): '<S3>/Tapped Delay' */
  for (i = 0; i < 8; i++) {
    SensAdapt_DWork.TappedDelay_X_n51i[i] = SensAdapt_DWork.TappedDelay_X_n51i[i
      + 1];
  }

  SensAdapt_DWork.TappedDelay_X_n51i[8] = SensAdapt_B.u16AccXData;

  /* End of Update for S-Function (sfix_udelay): '<S3>/Tapped Delay' */
}

/* Initial conditions for atomic system: '<Root>/smoothData1' */
void SensAdapt_smoothData1_Init(void)
{
  int32_T i;

  /* InitializeConditions for S-Function (sfix_udelay): '<S4>/Tapped Delay' */
  for (i = 0; i < 9; i++) {
    SensAdapt_DWork.TappedDelay_X_ido1[i] = 9.0;
  }

  /* End of InitializeConditions for S-Function (sfix_udelay): '<S4>/Tapped Delay' */
}

/* Output and update for atomic system: '<Root>/smoothData1' */
void SensAdapt_smoothData1(void)
{
  int_T i;
  real_T rtb_VectorConcatenate_cgrs[10];
  real_T tmp;

  /* SignalConversion: '<S4>/ConcatBufferAtVector ConcatenateIn1' */
  rtb_VectorConcatenate_cgrs[0] = SensAdapt_B.u16AccYData;

  /* S-Function (sfix_udelay): '<S4>/Tapped Delay' */
  memcpy(&rtb_VectorConcatenate_cgrs[1], &SensAdapt_DWork.TappedDelay_X_ido1[0],
         9U * (sizeof(real_T)));

  /* Sum: '<S4>/Sum of Elements' */
  tmp = rtb_VectorConcatenate_cgrs[0];
  for (i = 0; i < 9; i++) {
    tmp += rtb_VectorConcatenate_cgrs[i + 1];
  }

  /* Product: '<S4>/Product' incorporates:
   *  Sum: '<S4>/Sum of Elements'
   */
  SensAdapt_B.Product_bnex = tmp / 10.0;

  /* Update for S-Function (sfix_udelay): '<S4>/Tapped Delay' */
  for (i = 0; i < 8; i++) {
    SensAdapt_DWork.TappedDelay_X_ido1[i] = SensAdapt_DWork.TappedDelay_X_ido1[i
      + 1];
  }

  SensAdapt_DWork.TappedDelay_X_ido1[8] = SensAdapt_B.u16AccYData;

  /* End of Update for S-Function (sfix_udelay): '<S4>/Tapped Delay' */
}

/* Initial conditions for atomic system: '<Root>/smoothData10' */
void SensAdapt_smoothData10_Init(void)
{
  int32_T i;

  /* InitializeConditions for S-Function (sfix_udelay): '<S5>/Tapped Delay' */
  for (i = 0; i < 9; i++) {
    SensAdapt_DWork.TappedDelay_X_iau4[i] = 9.0;
  }

  /* End of InitializeConditions for S-Function (sfix_udelay): '<S5>/Tapped Delay' */
}

/* Output and update for atomic system: '<Root>/smoothData10' */
void SensAdapt_smoothData10(void)
{
  int_T i;
  real_T rtb_VectorConcatenate_bsmr[10];
  real_T tmp;

  /* SignalConversion: '<S5>/ConcatBufferAtVector ConcatenateIn1' */
  rtb_VectorConcatenate_bsmr[0] = SensAdapt_B.accy;

  /* S-Function (sfix_udelay): '<S5>/Tapped Delay' */
  memcpy(&rtb_VectorConcatenate_bsmr[1], &SensAdapt_DWork.TappedDelay_X_iau4[0],
         9U * (sizeof(real_T)));

  /* Sum: '<S5>/Sum of Elements' */
  tmp = rtb_VectorConcatenate_bsmr[0];
  for (i = 0; i < 9; i++) {
    tmp += rtb_VectorConcatenate_bsmr[i + 1];
  }

  /* Product: '<S5>/Product' incorporates:
   *  Sum: '<S5>/Sum of Elements'
   */
  SensAdapt_B.Product_jsq1 = tmp / 10.0;

  /* Update for S-Function (sfix_udelay): '<S5>/Tapped Delay' */
  for (i = 0; i < 8; i++) {
    SensAdapt_DWork.TappedDelay_X_iau4[i] = SensAdapt_DWork.TappedDelay_X_iau4[i
      + 1];
  }

  SensAdapt_DWork.TappedDelay_X_iau4[8] = SensAdapt_B.accy;

  /* End of Update for S-Function (sfix_udelay): '<S5>/Tapped Delay' */
}

/* Initial conditions for atomic system: '<Root>/smoothData11' */
void SensAdapt_smoothData11_Init(void)
{
  int32_T i;

  /* InitializeConditions for S-Function (sfix_udelay): '<S6>/Tapped Delay' */
  for (i = 0; i < 9; i++) {
    SensAdapt_DWork.TappedDelay_X_jphy[i] = 9.0;
  }

  /* End of InitializeConditions for S-Function (sfix_udelay): '<S6>/Tapped Delay' */
}

/* Output and update for atomic system: '<Root>/smoothData11' */
void SensAdapt_smoothData11(void)
{
  int_T i;
  real_T rtb_VectorConcatenate_coyr[10];
  real_T tmp;

  /* SignalConversion: '<S6>/ConcatBufferAtVector ConcatenateIn1' */
  rtb_VectorConcatenate_coyr[0] = SensAdapt_B.accz;

  /* S-Function (sfix_udelay): '<S6>/Tapped Delay' */
  memcpy(&rtb_VectorConcatenate_coyr[1], &SensAdapt_DWork.TappedDelay_X_jphy[0],
         9U * (sizeof(real_T)));

  /* Sum: '<S6>/Sum of Elements' */
  tmp = rtb_VectorConcatenate_coyr[0];
  for (i = 0; i < 9; i++) {
    tmp += rtb_VectorConcatenate_coyr[i + 1];
  }

  /* Product: '<S6>/Product' incorporates:
   *  Sum: '<S6>/Sum of Elements'
   */
  SensAdapt_B.Product_m02k = tmp / 10.0;

  /* Update for S-Function (sfix_udelay): '<S6>/Tapped Delay' */
  for (i = 0; i < 8; i++) {
    SensAdapt_DWork.TappedDelay_X_jphy[i] = SensAdapt_DWork.TappedDelay_X_jphy[i
      + 1];
  }

  SensAdapt_DWork.TappedDelay_X_jphy[8] = SensAdapt_B.accz;

  /* End of Update for S-Function (sfix_udelay): '<S6>/Tapped Delay' */
}

/* Initial conditions for atomic system: '<Root>/smoothData2' */
void SensAdapt_smoothData2_Init(void)
{
  int32_T i;

  /* InitializeConditions for S-Function (sfix_udelay): '<S7>/Tapped Delay' */
  for (i = 0; i < 9; i++) {
    SensAdapt_DWork.TappedDelay_X_ouxw[i] = 9.0;
  }

  /* End of InitializeConditions for S-Function (sfix_udelay): '<S7>/Tapped Delay' */
}

/* Output and update for atomic system: '<Root>/smoothData2' */
void SensAdapt_smoothData2(void)
{
  int_T i;
  real_T rtb_VectorConcatenate_ipgk[10];
  real_T tmp;

  /* SignalConversion: '<S7>/ConcatBufferAtVector ConcatenateIn1' */
  rtb_VectorConcatenate_ipgk[0] = SensAdapt_B.u16AccZData;

  /* S-Function (sfix_udelay): '<S7>/Tapped Delay' */
  memcpy(&rtb_VectorConcatenate_ipgk[1], &SensAdapt_DWork.TappedDelay_X_ouxw[0],
         9U * (sizeof(real_T)));

  /* Sum: '<S7>/Sum of Elements' */
  tmp = rtb_VectorConcatenate_ipgk[0];
  for (i = 0; i < 9; i++) {
    tmp += rtb_VectorConcatenate_ipgk[i + 1];
  }

  /* Product: '<S7>/Product' incorporates:
   *  Sum: '<S7>/Sum of Elements'
   */
  SensAdapt_B.Product_kzgj = tmp / 10.0;

  /* Update for S-Function (sfix_udelay): '<S7>/Tapped Delay' */
  for (i = 0; i < 8; i++) {
    SensAdapt_DWork.TappedDelay_X_ouxw[i] = SensAdapt_DWork.TappedDelay_X_ouxw[i
      + 1];
  }

  SensAdapt_DWork.TappedDelay_X_ouxw[8] = SensAdapt_B.u16AccZData;

  /* End of Update for S-Function (sfix_udelay): '<S7>/Tapped Delay' */
}

/* Initial conditions for atomic system: '<Root>/smoothData3' */
void SensAdapt_smoothData3_Init(void)
{
  int32_T i;

  /* InitializeConditions for S-Function (sfix_udelay): '<S8>/Tapped Delay' */
  for (i = 0; i < 9; i++) {
    SensAdapt_DWork.TappedDelay_X_cw5c[i] = 9.0;
  }

  /* End of InitializeConditions for S-Function (sfix_udelay): '<S8>/Tapped Delay' */
}

/* Output and update for atomic system: '<Root>/smoothData3' */
void SensAdapt_smoothData3(void)
{
  int_T i;
  real_T rtb_VectorConcatenate_o1is[10];
  real_T tmp;

  /* SignalConversion: '<S8>/ConcatBufferAtVector ConcatenateIn1' */
  rtb_VectorConcatenate_o1is[0] = SensAdapt_B.u16GyroXData;

  /* S-Function (sfix_udelay): '<S8>/Tapped Delay' */
  memcpy(&rtb_VectorConcatenate_o1is[1], &SensAdapt_DWork.TappedDelay_X_cw5c[0],
         9U * (sizeof(real_T)));

  /* Sum: '<S8>/Sum of Elements' */
  tmp = rtb_VectorConcatenate_o1is[0];
  for (i = 0; i < 9; i++) {
    tmp += rtb_VectorConcatenate_o1is[i + 1];
  }

  /* Product: '<S8>/Product' incorporates:
   *  Sum: '<S8>/Sum of Elements'
   */
  SensAdapt_B.Product_a1oc = tmp / 10.0;

  /* Update for S-Function (sfix_udelay): '<S8>/Tapped Delay' */
  for (i = 0; i < 8; i++) {
    SensAdapt_DWork.TappedDelay_X_cw5c[i] = SensAdapt_DWork.TappedDelay_X_cw5c[i
      + 1];
  }

  SensAdapt_DWork.TappedDelay_X_cw5c[8] = SensAdapt_B.u16GyroXData;

  /* End of Update for S-Function (sfix_udelay): '<S8>/Tapped Delay' */
}

/* Initial conditions for atomic system: '<Root>/smoothData4' */
void SensAdapt_smoothData4_Init(void)
{
  int32_T i;

  /* InitializeConditions for S-Function (sfix_udelay): '<S9>/Tapped Delay' */
  for (i = 0; i < 9; i++) {
    SensAdapt_DWork.TappedDelay_X_b4iy[i] = 9.0;
  }

  /* End of InitializeConditions for S-Function (sfix_udelay): '<S9>/Tapped Delay' */
}

/* Output and update for atomic system: '<Root>/smoothData4' */
void SensAdapt_smoothData4(void)
{
  int_T i;
  real_T rtb_VectorConcatenate_ha5f[10];
  real_T tmp;

  /* SignalConversion: '<S9>/ConcatBufferAtVector ConcatenateIn1' */
  rtb_VectorConcatenate_ha5f[0] = SensAdapt_B.u16GyroYData;

  /* S-Function (sfix_udelay): '<S9>/Tapped Delay' */
  memcpy(&rtb_VectorConcatenate_ha5f[1], &SensAdapt_DWork.TappedDelay_X_b4iy[0],
         9U * (sizeof(real_T)));

  /* Sum: '<S9>/Sum of Elements' */
  tmp = rtb_VectorConcatenate_ha5f[0];
  for (i = 0; i < 9; i++) {
    tmp += rtb_VectorConcatenate_ha5f[i + 1];
  }

  /* Product: '<S9>/Product' incorporates:
   *  Sum: '<S9>/Sum of Elements'
   */
  SensAdapt_B.Product_chkv = tmp / 10.0;

  /* Update for S-Function (sfix_udelay): '<S9>/Tapped Delay' */
  for (i = 0; i < 8; i++) {
    SensAdapt_DWork.TappedDelay_X_b4iy[i] = SensAdapt_DWork.TappedDelay_X_b4iy[i
      + 1];
  }

  SensAdapt_DWork.TappedDelay_X_b4iy[8] = SensAdapt_B.u16GyroYData;

  /* End of Update for S-Function (sfix_udelay): '<S9>/Tapped Delay' */
}

/* Initial conditions for atomic system: '<Root>/smoothData5' */
void SensAdapt_smoothData5_Init(void)
{
  int32_T i;

  /* InitializeConditions for S-Function (sfix_udelay): '<S10>/Tapped Delay' */
  for (i = 0; i < 9; i++) {
    SensAdapt_DWork.TappedDelay_X_kvli[i] = 9.0;
  }

  /* End of InitializeConditions for S-Function (sfix_udelay): '<S10>/Tapped Delay' */
}

/* Output and update for atomic system: '<Root>/smoothData5' */
void SensAdapt_smoothData5(void)
{
  int_T i;
  real_T rtb_VectorConcatenate_kecd[10];
  real_T tmp;

  /* SignalConversion: '<S10>/ConcatBufferAtVector ConcatenateIn1' */
  rtb_VectorConcatenate_kecd[0] = SensAdapt_B.u16GyroZData;

  /* S-Function (sfix_udelay): '<S10>/Tapped Delay' */
  memcpy(&rtb_VectorConcatenate_kecd[1], &SensAdapt_DWork.TappedDelay_X_kvli[0],
         9U * (sizeof(real_T)));

  /* Sum: '<S10>/Sum of Elements' */
  tmp = rtb_VectorConcatenate_kecd[0];
  for (i = 0; i < 9; i++) {
    tmp += rtb_VectorConcatenate_kecd[i + 1];
  }

  /* Product: '<S10>/Product' incorporates:
   *  Sum: '<S10>/Sum of Elements'
   */
  SensAdapt_B.Product_hx1x = tmp / 10.0;

  /* Update for S-Function (sfix_udelay): '<S10>/Tapped Delay' */
  for (i = 0; i < 8; i++) {
    SensAdapt_DWork.TappedDelay_X_kvli[i] = SensAdapt_DWork.TappedDelay_X_kvli[i
      + 1];
  }

  SensAdapt_DWork.TappedDelay_X_kvli[8] = SensAdapt_B.u16GyroZData;

  /* End of Update for S-Function (sfix_udelay): '<S10>/Tapped Delay' */
}

/* Initial conditions for atomic system: '<Root>/smoothData6' */
void SensAdapt_smoothData6_Init(void)
{
  int32_T i;

  /* InitializeConditions for S-Function (sfix_udelay): '<S11>/Tapped Delay' */
  for (i = 0; i < 9; i++) {
    SensAdapt_DWork.TappedDelay_X_la2x[i] = 9.0;
  }

  /* End of InitializeConditions for S-Function (sfix_udelay): '<S11>/Tapped Delay' */
}

/* Output and update for atomic system: '<Root>/smoothData6' */
void SensAdapt_smoothData6(void)
{
  int_T i;
  real_T rtb_VectorConcatenate_kibn[10];
  real_T tmp;

  /* SignalConversion: '<S11>/ConcatBufferAtVector ConcatenateIn1' */
  rtb_VectorConcatenate_kibn[0] = SensAdapt_B.accx_gf4n;

  /* S-Function (sfix_udelay): '<S11>/Tapped Delay' */
  memcpy(&rtb_VectorConcatenate_kibn[1], &SensAdapt_DWork.TappedDelay_X_la2x[0],
         9U * (sizeof(real_T)));

  /* Sum: '<S11>/Sum of Elements' */
  tmp = rtb_VectorConcatenate_kibn[0];
  for (i = 0; i < 9; i++) {
    tmp += rtb_VectorConcatenate_kibn[i + 1];
  }

  /* Product: '<S11>/Product' incorporates:
   *  Sum: '<S11>/Sum of Elements'
   */
  SensAdapt_B.Product_kzvd = tmp / 10.0;

  /* Update for S-Function (sfix_udelay): '<S11>/Tapped Delay' */
  for (i = 0; i < 8; i++) {
    SensAdapt_DWork.TappedDelay_X_la2x[i] = SensAdapt_DWork.TappedDelay_X_la2x[i
      + 1];
  }

  SensAdapt_DWork.TappedDelay_X_la2x[8] = SensAdapt_B.accx_gf4n;

  /* End of Update for S-Function (sfix_udelay): '<S11>/Tapped Delay' */
}

/* Initial conditions for atomic system: '<Root>/smoothData7' */
void SensAdapt_smoothData7_Init(void)
{
  int32_T i;

  /* InitializeConditions for S-Function (sfix_udelay): '<S12>/Tapped Delay' */
  for (i = 0; i < 9; i++) {
    SensAdapt_DWork.TappedDelay_X_lceu[i] = 9.0;
  }

  /* End of InitializeConditions for S-Function (sfix_udelay): '<S12>/Tapped Delay' */
}

/* Output and update for atomic system: '<Root>/smoothData7' */
void SensAdapt_smoothData7(void)
{
  int_T i;
  real_T rtb_VectorConcatenate_flm5[10];
  real_T tmp;

  /* SignalConversion: '<S12>/ConcatBufferAtVector ConcatenateIn1' */
  rtb_VectorConcatenate_flm5[0] = SensAdapt_B.accy_azyn;

  /* S-Function (sfix_udelay): '<S12>/Tapped Delay' */
  memcpy(&rtb_VectorConcatenate_flm5[1], &SensAdapt_DWork.TappedDelay_X_lceu[0],
         9U * (sizeof(real_T)));

  /* Sum: '<S12>/Sum of Elements' */
  tmp = rtb_VectorConcatenate_flm5[0];
  for (i = 0; i < 9; i++) {
    tmp += rtb_VectorConcatenate_flm5[i + 1];
  }

  /* Product: '<S12>/Product' incorporates:
   *  Sum: '<S12>/Sum of Elements'
   */
  SensAdapt_B.Product_igt4 = tmp / 10.0;

  /* Update for S-Function (sfix_udelay): '<S12>/Tapped Delay' */
  for (i = 0; i < 8; i++) {
    SensAdapt_DWork.TappedDelay_X_lceu[i] = SensAdapt_DWork.TappedDelay_X_lceu[i
      + 1];
  }

  SensAdapt_DWork.TappedDelay_X_lceu[8] = SensAdapt_B.accy_azyn;

  /* End of Update for S-Function (sfix_udelay): '<S12>/Tapped Delay' */
}

/* Initial conditions for atomic system: '<Root>/smoothData8' */
void SensAdapt_smoothData8_Init(void)
{
  int32_T i;

  /* InitializeConditions for S-Function (sfix_udelay): '<S13>/Tapped Delay' */
  for (i = 0; i < 9; i++) {
    SensAdapt_DWork.TappedDelay_X_ekvt[i] = 9.0;
  }

  /* End of InitializeConditions for S-Function (sfix_udelay): '<S13>/Tapped Delay' */
}

/* Output and update for atomic system: '<Root>/smoothData8' */
void SensAdapt_smoothData8(void)
{
  int_T i;
  real_T rtb_VectorConcatenate_ah1r[10];
  real_T tmp;

  /* SignalConversion: '<S13>/ConcatBufferAtVector ConcatenateIn1' */
  rtb_VectorConcatenate_ah1r[0] = SensAdapt_B.accz_nuj4;

  /* S-Function (sfix_udelay): '<S13>/Tapped Delay' */
  memcpy(&rtb_VectorConcatenate_ah1r[1], &SensAdapt_DWork.TappedDelay_X_ekvt[0],
         9U * (sizeof(real_T)));

  /* Sum: '<S13>/Sum of Elements' */
  tmp = rtb_VectorConcatenate_ah1r[0];
  for (i = 0; i < 9; i++) {
    tmp += rtb_VectorConcatenate_ah1r[i + 1];
  }

  /* Product: '<S13>/Product' incorporates:
   *  Sum: '<S13>/Sum of Elements'
   */
  SensAdapt_B.Product_bkqq = tmp / 10.0;

  /* Update for S-Function (sfix_udelay): '<S13>/Tapped Delay' */
  for (i = 0; i < 8; i++) {
    SensAdapt_DWork.TappedDelay_X_ekvt[i] = SensAdapt_DWork.TappedDelay_X_ekvt[i
      + 1];
  }

  SensAdapt_DWork.TappedDelay_X_ekvt[8] = SensAdapt_B.accz_nuj4;

  /* End of Update for S-Function (sfix_udelay): '<S13>/Tapped Delay' */
}

/* Initial conditions for atomic system: '<Root>/smoothData9' */
void SensAdapt_smoothData9_Init(void)
{
  int32_T i;

  /* InitializeConditions for S-Function (sfix_udelay): '<S14>/Tapped Delay' */
  for (i = 0; i < 9; i++) {
    SensAdapt_DWork.TappedDelay_X[i] = 9.0;
  }

  /* End of InitializeConditions for S-Function (sfix_udelay): '<S14>/Tapped Delay' */
}

/* Output and update for atomic system: '<Root>/smoothData9' */
void SensAdapt_smoothData9(void)
{
  int_T i;
  real_T rtb_VectorConcatenate_jvvp[10];
  real_T tmp;

  /* SignalConversion: '<S14>/ConcatBufferAtVector ConcatenateIn1' */
  rtb_VectorConcatenate_jvvp[0] = SensAdapt_B.accx;

  /* S-Function (sfix_udelay): '<S14>/Tapped Delay' */
  memcpy(&rtb_VectorConcatenate_jvvp[1], &SensAdapt_DWork.TappedDelay_X[0], 9U *
         (sizeof(real_T)));

  /* Sum: '<S14>/Sum of Elements' */
  tmp = rtb_VectorConcatenate_jvvp[0];
  for (i = 0; i < 9; i++) {
    tmp += rtb_VectorConcatenate_jvvp[i + 1];
  }

  /* Product: '<S14>/Product' incorporates:
   *  Sum: '<S14>/Sum of Elements'
   */
  SensAdapt_B.Product = tmp / 10.0;

  /* Update for S-Function (sfix_udelay): '<S14>/Tapped Delay' */
  for (i = 0; i < 8; i++) {
    SensAdapt_DWork.TappedDelay_X[i] = SensAdapt_DWork.TappedDelay_X[i + 1];
  }

  SensAdapt_DWork.TappedDelay_X[8] = SensAdapt_B.accx;

  /* End of Update for S-Function (sfix_udelay): '<S14>/Tapped Delay' */
}

/* Model step function */
void SensAdapt_step(void)
{
  /* UnitDelay: '<Root>/Unit Delay12' */
  UART_DisplayData(SensAdapt_DWork.UnitDelay12_DSTATE);

  /* BusSelector: '<Root>/Bus Selector' incorporates:
   *  Inport: '<Root>/In1'
   */
  SensAdapt_B.u16AccXData = GetData__stMPU_6050().u16AccXData;
  SensAdapt_B.u16AccYData = GetData__stMPU_6050().u16AccYData;
  SensAdapt_B.u16AccZData = GetData__stMPU_6050().u16AccZData;
  SensAdapt_B.u16GyroXData = GetData__stMPU_6050().u16GyroXData;
  SensAdapt_B.u16GyroYData = GetData__stMPU_6050().u16GyroYData;
  SensAdapt_B.u16GyroZData = GetData__stMPU_6050().u16GyroZData;

  /* Outputs for Atomic SubSystem: '<Root>/AccConvToG' */
  SensAdapt_AccConvToG();

  /* End of Outputs for SubSystem: '<Root>/AccConvToG' */

  /* Outputs for Atomic SubSystem: '<Root>/smoothData' */
  SensAdapt_smoothData();

  /* End of Outputs for SubSystem: '<Root>/smoothData' */

  /* Outputs for Atomic SubSystem: '<Root>/smoothData1' */
  SensAdapt_smoothData1();

  /* End of Outputs for SubSystem: '<Root>/smoothData1' */

  /* Outputs for Atomic SubSystem: '<Root>/smoothData2' */
  SensAdapt_smoothData2();

  /* End of Outputs for SubSystem: '<Root>/smoothData2' */

  /* Outputs for Atomic SubSystem: '<Root>/smoothData3' */
  SensAdapt_smoothData3();

  /* End of Outputs for SubSystem: '<Root>/smoothData3' */

  /* Outputs for Atomic SubSystem: '<Root>/smoothData4' */
  SensAdapt_smoothData4();

  /* End of Outputs for SubSystem: '<Root>/smoothData4' */

  /* Outputs for Atomic SubSystem: '<Root>/smoothData5' */
  SensAdapt_smoothData5();

  /* End of Outputs for SubSystem: '<Root>/smoothData5' */

  /* Outputs for Atomic SubSystem: '<Root>/smoothData6' */
  SensAdapt_smoothData6();

  /* End of Outputs for SubSystem: '<Root>/smoothData6' */

  /* Outputs for Atomic SubSystem: '<Root>/smoothData7' */
  SensAdapt_smoothData7();

  /* End of Outputs for SubSystem: '<Root>/smoothData7' */

  /* Outputs for Atomic SubSystem: '<Root>/smoothData8' */
  SensAdapt_smoothData8();

  /* End of Outputs for SubSystem: '<Root>/smoothData8' */

  /* Outputs for Atomic SubSystem: '<Root>/GyroConvToRadpsec' */
  SensAdapt_GyroConvToRadpsec();

  /* End of Outputs for SubSystem: '<Root>/GyroConvToRadpsec' */

  /* Outputs for Atomic SubSystem: '<Root>/smoothData9' */
  SensAdapt_smoothData9();

  /* End of Outputs for SubSystem: '<Root>/smoothData9' */

  /* Outputs for Atomic SubSystem: '<Root>/smoothData10' */
  SensAdapt_smoothData10();

  /* End of Outputs for SubSystem: '<Root>/smoothData10' */

  /* Outputs for Atomic SubSystem: '<Root>/smoothData11' */
  SensAdapt_smoothData11();

  /* End of Outputs for SubSystem: '<Root>/smoothData11' */

  /* Update for UnitDelay: '<Root>/Unit Delay12' incorporates:
   *  BusCreator: '<Root>/Bus Creator'
   */
  SensAdapt_DWork.UnitDelay12_DSTATE.u16AccXDataS = SensAdapt_B.Product_mq0i;
  SensAdapt_DWork.UnitDelay12_DSTATE.u16AccYDataS = SensAdapt_B.Product_bnex;
  SensAdapt_DWork.UnitDelay12_DSTATE.u16AccZDataS = SensAdapt_B.Product_kzgj;
  SensAdapt_DWork.UnitDelay12_DSTATE.u16GyroXDataS = SensAdapt_B.Product_a1oc;
  SensAdapt_DWork.UnitDelay12_DSTATE.u16GyroYDataS = SensAdapt_B.Product_chkv;
  SensAdapt_DWork.UnitDelay12_DSTATE.u16GyroZDataS = SensAdapt_B.Product_hx1x;
  SensAdapt_DWork.UnitDelay12_DSTATE.signal7 = SensAdapt_B.Product_kzvd;
  SensAdapt_DWork.UnitDelay12_DSTATE.signal8 = SensAdapt_B.Product_igt4;
  SensAdapt_DWork.UnitDelay12_DSTATE.signal9 = SensAdapt_B.Product_bkqq;
  SensAdapt_DWork.UnitDelay12_DSTATE.signal10 = SensAdapt_B.Product;
  SensAdapt_DWork.UnitDelay12_DSTATE.signal11 = SensAdapt_B.Product_jsq1;
  SensAdapt_DWork.UnitDelay12_DSTATE.signal12 = SensAdapt_B.Product_m02k;
}

/* Model initialize function */
void SensAdapt_initialize(void)
{
  /* Registration code */

  /* block I/O */
  {
    SensAdapt_B.u16AccXData = 0.0;
    SensAdapt_B.u16AccYData = 0.0;
    SensAdapt_B.u16AccZData = 0.0;
    SensAdapt_B.u16GyroXData = 0.0;
    SensAdapt_B.u16GyroYData = 0.0;
    SensAdapt_B.u16GyroZData = 0.0;
    SensAdapt_B.Product = 0.0;
    SensAdapt_B.Product_bkqq = 0.0;
    SensAdapt_B.Product_igt4 = 0.0;
    SensAdapt_B.Product_kzvd = 0.0;
    SensAdapt_B.Product_hx1x = 0.0;
    SensAdapt_B.Product_chkv = 0.0;
    SensAdapt_B.Product_a1oc = 0.0;
    SensAdapt_B.Product_kzgj = 0.0;
    SensAdapt_B.Product_m02k = 0.0;
    SensAdapt_B.Product_jsq1 = 0.0;
    SensAdapt_B.Product_bnex = 0.0;
    SensAdapt_B.Product_mq0i = 0.0;
    SensAdapt_B.accx = 0.0;
    SensAdapt_B.accy = 0.0;
    SensAdapt_B.accz = 0.0;
    SensAdapt_B.accx_gf4n = 0.0;
    SensAdapt_B.accy_azyn = 0.0;
    SensAdapt_B.accz_nuj4 = 0.0;
  }

  /* states (dwork) */
  (void) memset((void *)&SensAdapt_DWork, 0,
                sizeof(D_Work_SensAdapt));

  {
    int_T i;
    for (i = 0; i < 9; i++) {
      SensAdapt_DWork.TappedDelay_X[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 9; i++) {
      SensAdapt_DWork.TappedDelay_X_ekvt[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 9; i++) {
      SensAdapt_DWork.TappedDelay_X_lceu[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 9; i++) {
      SensAdapt_DWork.TappedDelay_X_la2x[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 9; i++) {
      SensAdapt_DWork.TappedDelay_X_kvli[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 9; i++) {
      SensAdapt_DWork.TappedDelay_X_b4iy[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 9; i++) {
      SensAdapt_DWork.TappedDelay_X_cw5c[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 9; i++) {
      SensAdapt_DWork.TappedDelay_X_ouxw[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 9; i++) {
      SensAdapt_DWork.TappedDelay_X_jphy[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 9; i++) {
      SensAdapt_DWork.TappedDelay_X_iau4[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 9; i++) {
      SensAdapt_DWork.TappedDelay_X_ido1[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 9; i++) {
      SensAdapt_DWork.TappedDelay_X_n51i[i] = 0.0;
    }
  }

  /* InitializeConditions for Atomic SubSystem: '<Root>/smoothData' */
  SensAdapt_smoothData_Init();

  /* End of InitializeConditions for SubSystem: '<Root>/smoothData' */

  /* InitializeConditions for Atomic SubSystem: '<Root>/smoothData1' */
  SensAdapt_smoothData1_Init();

  /* End of InitializeConditions for SubSystem: '<Root>/smoothData1' */

  /* InitializeConditions for Atomic SubSystem: '<Root>/smoothData2' */
  SensAdapt_smoothData2_Init();

  /* End of InitializeConditions for SubSystem: '<Root>/smoothData2' */

  /* InitializeConditions for Atomic SubSystem: '<Root>/smoothData3' */
  SensAdapt_smoothData3_Init();

  /* End of InitializeConditions for SubSystem: '<Root>/smoothData3' */

  /* InitializeConditions for Atomic SubSystem: '<Root>/smoothData4' */
  SensAdapt_smoothData4_Init();

  /* End of InitializeConditions for SubSystem: '<Root>/smoothData4' */

  /* InitializeConditions for Atomic SubSystem: '<Root>/smoothData5' */
  SensAdapt_smoothData5_Init();

  /* End of InitializeConditions for SubSystem: '<Root>/smoothData5' */

  /* InitializeConditions for Atomic SubSystem: '<Root>/smoothData6' */
  SensAdapt_smoothData6_Init();

  /* End of InitializeConditions for SubSystem: '<Root>/smoothData6' */

  /* InitializeConditions for Atomic SubSystem: '<Root>/smoothData7' */
  SensAdapt_smoothData7_Init();

  /* End of InitializeConditions for SubSystem: '<Root>/smoothData7' */

  /* InitializeConditions for Atomic SubSystem: '<Root>/smoothData8' */
  SensAdapt_smoothData8_Init();

  /* End of InitializeConditions for SubSystem: '<Root>/smoothData8' */

  /* InitializeConditions for Atomic SubSystem: '<Root>/smoothData9' */
  SensAdapt_smoothData9_Init();

  /* End of InitializeConditions for SubSystem: '<Root>/smoothData9' */

  /* InitializeConditions for Atomic SubSystem: '<Root>/smoothData10' */
  SensAdapt_smoothData10_Init();

  /* End of InitializeConditions for SubSystem: '<Root>/smoothData10' */

  /* InitializeConditions for Atomic SubSystem: '<Root>/smoothData11' */
  SensAdapt_smoothData11_Init();

  /* End of InitializeConditions for SubSystem: '<Root>/smoothData11' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
