/*
 * File: SensAdapt.c
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

#include "SensAdapt.h"
#include "SensAdapt_private.h"

/* Block signals (auto storage) */
BlockIO_SensAdapt SensAdapt_B;

/* Block states (auto storage) */
D_Work_SensAdapt SensAdapt_DWork;

/* Initial conditions for atomic system: '<Root>/smoothData' */
void SensAdapt_smoothData_Init(void)
{
  int32_T i;

  /* InitializeConditions for S-Function (sfix_udelay): '<S1>/Tapped Delay' */
  for (i = 0; i < 9; i++) {
    SensAdapt_DWork.TappedDelay_X_n51i[i] = 0U;
  }

  /* End of InitializeConditions for S-Function (sfix_udelay): '<S1>/Tapped Delay' */
}

/* Output and update for atomic system: '<Root>/smoothData' */
void SensAdapt_smoothData(void)
{
  uint16_T rtb_VectorConcatenate[10];
  uint32_T tmp;
  int32_T i;

  /* SignalConversion: '<S1>/ConcatBufferAtVector ConcatenateIn1' */
  rtb_VectorConcatenate[0] = SensAdapt_B.u16AccXData;

  /* S-Function (sfix_udelay): '<S1>/Tapped Delay' */
  for (i = 0; i < 9; i++) {
    rtb_VectorConcatenate[i + 1] = SensAdapt_DWork.TappedDelay_X_n51i[i];
  }

  /* End of S-Function (sfix_udelay): '<S1>/Tapped Delay' */

  /* Sum: '<S1>/Sum of Elements' */
  tmp = rtb_VectorConcatenate[0];
  for (i = 0; i < 9; i++) {
    tmp += rtb_VectorConcatenate[i + 1];
  }

  /* Product: '<S1>/Product' incorporates:
   *  Sum: '<S1>/Sum of Elements'
   */
  SensAdapt_B.Product_mq0i = (uint16_T)(tmp / 10U);

  /* Update for S-Function (sfix_udelay): '<S1>/Tapped Delay' */
  for (i = 0; i < 8; i++) {
    SensAdapt_DWork.TappedDelay_X_n51i[i] = SensAdapt_DWork.TappedDelay_X_n51i[i
      + 1];
  }

  SensAdapt_DWork.TappedDelay_X_n51i[8] = SensAdapt_B.u16AccXData;

  /* End of Update for S-Function (sfix_udelay): '<S1>/Tapped Delay' */
}

/* Initial conditions for atomic system: '<Root>/smoothData1' */
void SensAdapt_smoothData1_Init(void)
{
  int32_T i;

  /* InitializeConditions for S-Function (sfix_udelay): '<S2>/Tapped Delay' */
  for (i = 0; i < 9; i++) {
    SensAdapt_DWork.TappedDelay_X_ido1[i] = 0U;
  }

  /* End of InitializeConditions for S-Function (sfix_udelay): '<S2>/Tapped Delay' */
}

/* Output and update for atomic system: '<Root>/smoothData1' */
void SensAdapt_smoothData1(void)
{
  uint16_T rtb_VectorConcatenate_cgrs[10];
  uint32_T tmp;
  int32_T i;

  /* SignalConversion: '<S2>/ConcatBufferAtVector ConcatenateIn1' */
  rtb_VectorConcatenate_cgrs[0] = SensAdapt_B.u16AccYData;

  /* S-Function (sfix_udelay): '<S2>/Tapped Delay' */
  for (i = 0; i < 9; i++) {
    rtb_VectorConcatenate_cgrs[i + 1] = SensAdapt_DWork.TappedDelay_X_ido1[i];
  }

  /* End of S-Function (sfix_udelay): '<S2>/Tapped Delay' */

  /* Sum: '<S2>/Sum of Elements' */
  tmp = rtb_VectorConcatenate_cgrs[0];
  for (i = 0; i < 9; i++) {
    tmp += rtb_VectorConcatenate_cgrs[i + 1];
  }

  /* Product: '<S2>/Product' incorporates:
   *  Sum: '<S2>/Sum of Elements'
   */
  SensAdapt_B.Product_bnex = (uint16_T)(tmp / 10U);

  /* Update for S-Function (sfix_udelay): '<S2>/Tapped Delay' */
  for (i = 0; i < 8; i++) {
    SensAdapt_DWork.TappedDelay_X_ido1[i] = SensAdapt_DWork.TappedDelay_X_ido1[i
      + 1];
  }

  SensAdapt_DWork.TappedDelay_X_ido1[8] = SensAdapt_B.u16AccYData;

  /* End of Update for S-Function (sfix_udelay): '<S2>/Tapped Delay' */
}

/* Initial conditions for atomic system: '<Root>/smoothData2' */
void SensAdapt_smoothData2_Init(void)
{
  int32_T i;

  /* InitializeConditions for S-Function (sfix_udelay): '<S3>/Tapped Delay' */
  for (i = 0; i < 9; i++) {
    SensAdapt_DWork.TappedDelay_X_ouxw[i] = 0U;
  }

  /* End of InitializeConditions for S-Function (sfix_udelay): '<S3>/Tapped Delay' */
}

/* Output and update for atomic system: '<Root>/smoothData2' */
void SensAdapt_smoothData2(void)
{
  uint16_T rtb_VectorConcatenate_ipgk[10];
  uint32_T tmp;
  int32_T i;

  /* SignalConversion: '<S3>/ConcatBufferAtVector ConcatenateIn1' */
  rtb_VectorConcatenate_ipgk[0] = SensAdapt_B.u16AccZData;

  /* S-Function (sfix_udelay): '<S3>/Tapped Delay' */
  for (i = 0; i < 9; i++) {
    rtb_VectorConcatenate_ipgk[i + 1] = SensAdapt_DWork.TappedDelay_X_ouxw[i];
  }

  /* End of S-Function (sfix_udelay): '<S3>/Tapped Delay' */

  /* Sum: '<S3>/Sum of Elements' */
  tmp = rtb_VectorConcatenate_ipgk[0];
  for (i = 0; i < 9; i++) {
    tmp += rtb_VectorConcatenate_ipgk[i + 1];
  }

  /* Product: '<S3>/Product' incorporates:
   *  Sum: '<S3>/Sum of Elements'
   */
  SensAdapt_B.Product_kzgj = (uint16_T)(tmp / 10U);

  /* Update for S-Function (sfix_udelay): '<S3>/Tapped Delay' */
  for (i = 0; i < 8; i++) {
    SensAdapt_DWork.TappedDelay_X_ouxw[i] = SensAdapt_DWork.TappedDelay_X_ouxw[i
      + 1];
  }

  SensAdapt_DWork.TappedDelay_X_ouxw[8] = SensAdapt_B.u16AccZData;

  /* End of Update for S-Function (sfix_udelay): '<S3>/Tapped Delay' */
}

/* Initial conditions for atomic system: '<Root>/smoothData3' */
void SensAdapt_smoothData3_Init(void)
{
  int32_T i;

  /* InitializeConditions for S-Function (sfix_udelay): '<S4>/Tapped Delay' */
  for (i = 0; i < 9; i++) {
    SensAdapt_DWork.TappedDelay_X_cw5c[i] = 0U;
  }

  /* End of InitializeConditions for S-Function (sfix_udelay): '<S4>/Tapped Delay' */
}

/* Output and update for atomic system: '<Root>/smoothData3' */
void SensAdapt_smoothData3(void)
{
  uint16_T rtb_VectorConcatenate_o1is[10];
  uint32_T tmp;
  int32_T i;

  /* SignalConversion: '<S4>/ConcatBufferAtVector ConcatenateIn1' */
  rtb_VectorConcatenate_o1is[0] = SensAdapt_B.u16GyroXData;

  /* S-Function (sfix_udelay): '<S4>/Tapped Delay' */
  for (i = 0; i < 9; i++) {
    rtb_VectorConcatenate_o1is[i + 1] = SensAdapt_DWork.TappedDelay_X_cw5c[i];
  }

  /* End of S-Function (sfix_udelay): '<S4>/Tapped Delay' */

  /* Sum: '<S4>/Sum of Elements' */
  tmp = rtb_VectorConcatenate_o1is[0];
  for (i = 0; i < 9; i++) {
    tmp += rtb_VectorConcatenate_o1is[i + 1];
  }

  /* Product: '<S4>/Product' incorporates:
   *  Sum: '<S4>/Sum of Elements'
   */
  SensAdapt_B.Product_a1oc = (uint16_T)(tmp / 10U);

  /* Update for S-Function (sfix_udelay): '<S4>/Tapped Delay' */
  for (i = 0; i < 8; i++) {
    SensAdapt_DWork.TappedDelay_X_cw5c[i] = SensAdapt_DWork.TappedDelay_X_cw5c[i
      + 1];
  }

  SensAdapt_DWork.TappedDelay_X_cw5c[8] = SensAdapt_B.u16GyroXData;

  /* End of Update for S-Function (sfix_udelay): '<S4>/Tapped Delay' */
}

/* Initial conditions for atomic system: '<Root>/smoothData4' */
void SensAdapt_smoothData4_Init(void)
{
  int32_T i;

  /* InitializeConditions for S-Function (sfix_udelay): '<S5>/Tapped Delay' */
  for (i = 0; i < 9; i++) {
    SensAdapt_DWork.TappedDelay_X_b4iy[i] = 0U;
  }

  /* End of InitializeConditions for S-Function (sfix_udelay): '<S5>/Tapped Delay' */
}

/* Output and update for atomic system: '<Root>/smoothData4' */
void SensAdapt_smoothData4(void)
{
  uint16_T rtb_VectorConcatenate_ha5f[10];
  uint32_T tmp;
  int32_T i;

  /* SignalConversion: '<S5>/ConcatBufferAtVector ConcatenateIn1' */
  rtb_VectorConcatenate_ha5f[0] = SensAdapt_B.u16GyroYData;

  /* S-Function (sfix_udelay): '<S5>/Tapped Delay' */
  for (i = 0; i < 9; i++) {
    rtb_VectorConcatenate_ha5f[i + 1] = SensAdapt_DWork.TappedDelay_X_b4iy[i];
  }

  /* End of S-Function (sfix_udelay): '<S5>/Tapped Delay' */

  /* Sum: '<S5>/Sum of Elements' */
  tmp = rtb_VectorConcatenate_ha5f[0];
  for (i = 0; i < 9; i++) {
    tmp += rtb_VectorConcatenate_ha5f[i + 1];
  }

  /* Product: '<S5>/Product' incorporates:
   *  Sum: '<S5>/Sum of Elements'
   */
  SensAdapt_B.Product_chkv = (uint16_T)(tmp / 10U);

  /* Update for S-Function (sfix_udelay): '<S5>/Tapped Delay' */
  for (i = 0; i < 8; i++) {
    SensAdapt_DWork.TappedDelay_X_b4iy[i] = SensAdapt_DWork.TappedDelay_X_b4iy[i
      + 1];
  }

  SensAdapt_DWork.TappedDelay_X_b4iy[8] = SensAdapt_B.u16GyroYData;

  /* End of Update for S-Function (sfix_udelay): '<S5>/Tapped Delay' */
}

/* Initial conditions for atomic system: '<Root>/smoothData5' */
void SensAdapt_smoothData5_Init(void)
{
  int32_T i;

  /* InitializeConditions for S-Function (sfix_udelay): '<S6>/Tapped Delay' */
  for (i = 0; i < 9; i++) {
    SensAdapt_DWork.TappedDelay_X[i] = 0U;
  }

  /* End of InitializeConditions for S-Function (sfix_udelay): '<S6>/Tapped Delay' */
}

/* Output and update for atomic system: '<Root>/smoothData5' */
void SensAdapt_smoothData5(void)
{
  uint16_T rtb_VectorConcatenate_kecd[10];
  uint32_T tmp;
  int32_T i;

  /* SignalConversion: '<S6>/ConcatBufferAtVector ConcatenateIn1' */
  rtb_VectorConcatenate_kecd[0] = SensAdapt_B.u16GyroZData;

  /* S-Function (sfix_udelay): '<S6>/Tapped Delay' */
  for (i = 0; i < 9; i++) {
    rtb_VectorConcatenate_kecd[i + 1] = SensAdapt_DWork.TappedDelay_X[i];
  }

  /* End of S-Function (sfix_udelay): '<S6>/Tapped Delay' */

  /* Sum: '<S6>/Sum of Elements' */
  tmp = rtb_VectorConcatenate_kecd[0];
  for (i = 0; i < 9; i++) {
    tmp += rtb_VectorConcatenate_kecd[i + 1];
  }

  /* Product: '<S6>/Product' incorporates:
   *  Sum: '<S6>/Sum of Elements'
   */
  SensAdapt_B.Product = (uint16_T)(tmp / 10U);

  /* Update for S-Function (sfix_udelay): '<S6>/Tapped Delay' */
  for (i = 0; i < 8; i++) {
    SensAdapt_DWork.TappedDelay_X[i] = SensAdapt_DWork.TappedDelay_X[i + 1];
  }

  SensAdapt_DWork.TappedDelay_X[8] = SensAdapt_B.u16GyroZData;

  /* End of Update for S-Function (sfix_udelay): '<S6>/Tapped Delay' */
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

  /* Update for UnitDelay: '<Root>/Unit Delay12' incorporates:
   *  BusCreator: '<Root>/Bus Creator'
   */
  SensAdapt_DWork.UnitDelay12_DSTATE.u16AccXDataS = SensAdapt_B.Product_mq0i;
  SensAdapt_DWork.UnitDelay12_DSTATE.u16AccYDataS = SensAdapt_B.Product_bnex;
  SensAdapt_DWork.UnitDelay12_DSTATE.u16AccZDataS = SensAdapt_B.Product_kzgj;
  SensAdapt_DWork.UnitDelay12_DSTATE.u16GyroXDataS = SensAdapt_B.Product_a1oc;
  SensAdapt_DWork.UnitDelay12_DSTATE.u16GyroYDataS = SensAdapt_B.Product_chkv;
  SensAdapt_DWork.UnitDelay12_DSTATE.u16GyroZDataS = SensAdapt_B.Product;
  SensAdapt_DWork.UnitDelay12_DSTATE.u16AccXData = SensAdapt_B.u16AccXData;
  SensAdapt_DWork.UnitDelay12_DSTATE.u16AccYData = SensAdapt_B.u16AccYData;
  SensAdapt_DWork.UnitDelay12_DSTATE.u16AccZData = SensAdapt_B.u16AccZData;
  SensAdapt_DWork.UnitDelay12_DSTATE.u16GyroXData = SensAdapt_B.u16GyroXData;
  SensAdapt_DWork.UnitDelay12_DSTATE.u16GyroYData = SensAdapt_B.u16GyroYData;
  SensAdapt_DWork.UnitDelay12_DSTATE.u16GyroZData = SensAdapt_B.u16GyroZData;
}

/* Model initialize function */
void SensAdapt_initialize(void)
{
  /* Registration code */

  /* block I/O */
  (void) memset(((void *) &SensAdapt_B), 0,
                sizeof(BlockIO_SensAdapt));

  /* states (dwork) */
  (void) memset((void *)&SensAdapt_DWork, 0,
                sizeof(D_Work_SensAdapt));

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
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
