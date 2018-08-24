/*
 * File: SensAdapt.c
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

#include "SensAdapt.h"
#include "SensAdapt_private.h"

/* Block signals (auto storage) */
BlockIO_SensAdapt SensAdapt_B;

/* Block states (auto storage) */
D_Work_SensAdapt SensAdapt_DWork;

/*
 * Output and update for atomic system: '<Root>/AccConv'
 * Block description for: '<Root>/AccConv'
 *   acc conversion block
 */
void SensAdapt_AccConv(void)
{
  /* Product: '<S1>/accx' incorporates:
   *  Constant: '<S1>/tog'
   */
  SensAdapt_B.accx_gf4n = SensAdapt_B.axc / 8192.0;

  /* Product: '<S1>/accy' incorporates:
   *  Constant: '<S1>/tog'
   */
  SensAdapt_B.accy_azyn = SensAdapt_B.ayc / 8192.0;

  /* Product: '<S1>/accz' incorporates:
   *  Constant: '<S1>/tog'
   */
  SensAdapt_B.accz_nuj4 = SensAdapt_B.azc / 8192.0;
}

/* Output and update for atomic system: '<Root>/GyroConv' */
void SensAdapt_GyroConv(void)
{
  /* Product: '<S2>/accx' incorporates:
   *  Constant: '<S2>/Constant'
   */
  SensAdapt_B.accx = SensAdapt_B.gxc / 939.650784;

  /* Product: '<S2>/accy' incorporates:
   *  Constant: '<S2>/Constant'
   */
  SensAdapt_B.accy = SensAdapt_B.gyc / 939.650784;

  /* Product: '<S2>/accz' incorporates:
   *  Constant: '<S2>/Constant'
   */
  SensAdapt_B.accz = SensAdapt_B.gzc / 939.650784;
}

/* Output and update for atomic system: '<Root>/calibrationBlock' */
void SensAdapt_calibrationBlock(void)
{
  /* MATLAB Function: '<S3>/MATLAB Function' */
  /* MATLAB Function 'calibrationBlock/MATLAB Function': '<S7>:1' */
  /* '<S7>:1:3' axc = ax - axoff; */
  SensAdapt_B.axc = SensAdapt_B.AccXData - -710.0;

  /* '<S7>:1:4' ayc = ay - ayoff; */
  SensAdapt_B.ayc = SensAdapt_B.AccYData - 50.0;

  /* '<S7>:1:5' azc = az - azoff; */
  SensAdapt_B.azc = SensAdapt_B.AccZData - 467.0;

  /* '<S7>:1:6' gxc = gx - gxoff; */
  SensAdapt_B.gxc = SensAdapt_B.GyroXData - 29.0;

  /* '<S7>:1:7' gyc = gy - gyoff; */
  SensAdapt_B.gyc = SensAdapt_B.GyroYData - -5.0;

  /* '<S7>:1:8' gzc = gz - gzoff; */
  SensAdapt_B.gzc = SensAdapt_B.GyroZData - 7.0;
}

/* Initial conditions for atomic system: '<Root>/smoothData' */
void SensAdapt_smoothData_Init(void)
{
  int32_T i;
  for (i = 0; i < 9; i++) {
    /* InitializeConditions for S-Function (sfix_udelay): '<S8>/Tapped Delay' */
    SensAdapt_DWork.TappedDelay_X[i] = 0.0;

    /* InitializeConditions for S-Function (sfix_udelay): '<S9>/Tapped Delay' */
    SensAdapt_DWork.TappedDelay_X_h4nz[i] = 0.0;

    /* InitializeConditions for S-Function (sfix_udelay): '<S10>/Tapped Delay' */
    SensAdapt_DWork.TappedDelay_X_auph[i] = 0.0;

    /* InitializeConditions for S-Function (sfix_udelay): '<S11>/Tapped Delay' */
    SensAdapt_DWork.TappedDelay_X_ahra[i] = 0.0;

    /* InitializeConditions for S-Function (sfix_udelay): '<S12>/Tapped Delay' */
    SensAdapt_DWork.TappedDelay_X_nmbc[i] = 0.0;

    /* InitializeConditions for S-Function (sfix_udelay): '<S13>/Tapped Delay' */
    SensAdapt_DWork.TappedDelay_X_byda[i] = 0.0;
  }
}

/* Output and update for atomic system: '<Root>/smoothData' */
void SensAdapt_smoothData(void)
{
  int_T i;
  real_T rtb_VectorConcatenate[10];
  real_T tmp;

  /* SignalConversion: '<S8>/ConcatBufferAtVector ConcatenateIn1' */
  rtb_VectorConcatenate[0] = SensAdapt_B.accx_gf4n;

  /* S-Function (sfix_udelay): '<S8>/Tapped Delay' */
  memcpy(&rtb_VectorConcatenate[1], &SensAdapt_DWork.TappedDelay_X[0], 9U *
         (sizeof(real_T)));

  /* Sum: '<S8>/Sum of Elements' */
  tmp = rtb_VectorConcatenate[0];
  for (i = 0; i < 9; i++) {
    tmp += rtb_VectorConcatenate[i + 1];
  }

  /* Product: '<S8>/Product' incorporates:
   *  Sum: '<S8>/Sum of Elements'
   */
  SensAdapt_B.Product = tmp / 10.0;

  /* SignalConversion: '<S9>/ConcatBufferAtVector ConcatenateIn1' */
  rtb_VectorConcatenate[0] = SensAdapt_B.accy_azyn;

  /* S-Function (sfix_udelay): '<S9>/Tapped Delay' */
  memcpy(&rtb_VectorConcatenate[1], &SensAdapt_DWork.TappedDelay_X_h4nz[0], 9U *
         (sizeof(real_T)));

  /* Sum: '<S9>/Sum of Elements' */
  tmp = rtb_VectorConcatenate[0];
  for (i = 0; i < 9; i++) {
    tmp += rtb_VectorConcatenate[i + 1];
  }

  /* Product: '<S9>/Product' incorporates:
   *  Sum: '<S9>/Sum of Elements'
   */
  SensAdapt_B.Product_jqhr = tmp / 10.0;

  /* SignalConversion: '<S10>/ConcatBufferAtVector ConcatenateIn1' */
  rtb_VectorConcatenate[0] = SensAdapt_B.accz_nuj4;

  /* S-Function (sfix_udelay): '<S10>/Tapped Delay' */
  memcpy(&rtb_VectorConcatenate[1], &SensAdapt_DWork.TappedDelay_X_auph[0], 9U *
         (sizeof(real_T)));

  /* Sum: '<S10>/Sum of Elements' */
  tmp = rtb_VectorConcatenate[0];
  for (i = 0; i < 9; i++) {
    tmp += rtb_VectorConcatenate[i + 1];
  }

  /* Product: '<S10>/Product' incorporates:
   *  Sum: '<S10>/Sum of Elements'
   */
  SensAdapt_B.Product_krg1 = tmp / 10.0;

  /* SignalConversion: '<S11>/ConcatBufferAtVector ConcatenateIn1' */
  rtb_VectorConcatenate[0] = SensAdapt_B.accx;

  /* S-Function (sfix_udelay): '<S11>/Tapped Delay' */
  memcpy(&rtb_VectorConcatenate[1], &SensAdapt_DWork.TappedDelay_X_ahra[0], 9U *
         (sizeof(real_T)));

  /* Sum: '<S11>/Sum of Elements' */
  tmp = rtb_VectorConcatenate[0];
  for (i = 0; i < 9; i++) {
    tmp += rtb_VectorConcatenate[i + 1];
  }

  /* Product: '<S11>/Product' incorporates:
   *  Sum: '<S11>/Sum of Elements'
   */
  SensAdapt_B.Product_nhwi = tmp / 10.0;

  /* SignalConversion: '<S12>/ConcatBufferAtVector ConcatenateIn1' */
  rtb_VectorConcatenate[0] = SensAdapt_B.accy;

  /* S-Function (sfix_udelay): '<S12>/Tapped Delay' */
  memcpy(&rtb_VectorConcatenate[1], &SensAdapt_DWork.TappedDelay_X_nmbc[0], 9U *
         (sizeof(real_T)));

  /* Sum: '<S12>/Sum of Elements' */
  tmp = rtb_VectorConcatenate[0];
  for (i = 0; i < 9; i++) {
    tmp += rtb_VectorConcatenate[i + 1];
  }

  /* Product: '<S12>/Product' incorporates:
   *  Sum: '<S12>/Sum of Elements'
   */
  SensAdapt_B.Product_ax4f = tmp / 10.0;

  /* SignalConversion: '<S13>/ConcatBufferAtVector ConcatenateIn1' */
  rtb_VectorConcatenate[0] = SensAdapt_B.accz;

  /* S-Function (sfix_udelay): '<S13>/Tapped Delay' */
  memcpy(&rtb_VectorConcatenate[1], &SensAdapt_DWork.TappedDelay_X_byda[0], 9U *
         (sizeof(real_T)));

  /* Sum: '<S13>/Sum of Elements' */
  tmp = rtb_VectorConcatenate[0];
  for (i = 0; i < 9; i++) {
    tmp += rtb_VectorConcatenate[i + 1];
  }

  /* Product: '<S13>/Product' incorporates:
   *  Sum: '<S13>/Sum of Elements'
   */
  SensAdapt_B.Product_pz1k = tmp / 10.0;

  /* Update for S-Function (sfix_udelay): '<S8>/Tapped Delay' */
  for (i = 0; i < 8; i++) {
    SensAdapt_DWork.TappedDelay_X[i] = SensAdapt_DWork.TappedDelay_X[i + 1];
  }

  SensAdapt_DWork.TappedDelay_X[8] = SensAdapt_B.accx_gf4n;

  /* End of Update for S-Function (sfix_udelay): '<S8>/Tapped Delay' */

  /* Update for S-Function (sfix_udelay): '<S9>/Tapped Delay' */
  for (i = 0; i < 8; i++) {
    SensAdapt_DWork.TappedDelay_X_h4nz[i] = SensAdapt_DWork.TappedDelay_X_h4nz[i
      + 1];
  }

  SensAdapt_DWork.TappedDelay_X_h4nz[8] = SensAdapt_B.accy_azyn;

  /* End of Update for S-Function (sfix_udelay): '<S9>/Tapped Delay' */

  /* Update for S-Function (sfix_udelay): '<S10>/Tapped Delay' */
  for (i = 0; i < 8; i++) {
    SensAdapt_DWork.TappedDelay_X_auph[i] = SensAdapt_DWork.TappedDelay_X_auph[i
      + 1];
  }

  SensAdapt_DWork.TappedDelay_X_auph[8] = SensAdapt_B.accz_nuj4;

  /* End of Update for S-Function (sfix_udelay): '<S10>/Tapped Delay' */

  /* Update for S-Function (sfix_udelay): '<S11>/Tapped Delay' */
  for (i = 0; i < 8; i++) {
    SensAdapt_DWork.TappedDelay_X_ahra[i] = SensAdapt_DWork.TappedDelay_X_ahra[i
      + 1];
  }

  SensAdapt_DWork.TappedDelay_X_ahra[8] = SensAdapt_B.accx;

  /* End of Update for S-Function (sfix_udelay): '<S11>/Tapped Delay' */

  /* Update for S-Function (sfix_udelay): '<S12>/Tapped Delay' */
  for (i = 0; i < 8; i++) {
    SensAdapt_DWork.TappedDelay_X_nmbc[i] = SensAdapt_DWork.TappedDelay_X_nmbc[i
      + 1];
  }

  SensAdapt_DWork.TappedDelay_X_nmbc[8] = SensAdapt_B.accy;

  /* End of Update for S-Function (sfix_udelay): '<S12>/Tapped Delay' */

  /* Update for S-Function (sfix_udelay): '<S13>/Tapped Delay' */
  for (i = 0; i < 8; i++) {
    SensAdapt_DWork.TappedDelay_X_byda[i] = SensAdapt_DWork.TappedDelay_X_byda[i
      + 1];
  }

  SensAdapt_DWork.TappedDelay_X_byda[8] = SensAdapt_B.accz;

  /* End of Update for S-Function (sfix_udelay): '<S13>/Tapped Delay' */
}

/* Model step function */
void SensAdapt_step(void)
{
  /* UnitDelay: '<Root>/Unit Delay12' */
  UART_DisplayData(SensAdapt_DWork.UnitDelay12_DSTATE);

  /* BusSelector: '<Root>/Bus Selector' incorporates:
   *  Inport: '<Root>/In1'
   */
  SensAdapt_B.AccXData = GetData__stMPU_6050().AccXData;
  SensAdapt_B.AccYData = GetData__stMPU_6050().AccYData;
  SensAdapt_B.AccZData = GetData__stMPU_6050().AccZData;
  SensAdapt_B.GyroXData = GetData__stMPU_6050().GyroXData;
  SensAdapt_B.GyroYData = GetData__stMPU_6050().GyroYData;
  SensAdapt_B.GyroZData = GetData__stMPU_6050().GyroZData;

  /* Outputs for Atomic SubSystem: '<Root>/calibrationBlock' */
  SensAdapt_calibrationBlock();

  /* End of Outputs for SubSystem: '<Root>/calibrationBlock' */

  /* Outputs for Atomic SubSystem: '<Root>/AccConv'
   *
   * Block description for '<Root>/AccConv':
   *  acc conversion block
   */
  SensAdapt_AccConv();

  /* End of Outputs for SubSystem: '<Root>/AccConv' */

  /* Outputs for Atomic SubSystem: '<Root>/GyroConv' */
  SensAdapt_GyroConv();

  /* End of Outputs for SubSystem: '<Root>/GyroConv' */

  /* Outputs for Atomic SubSystem: '<Root>/smoothData' */
  SensAdapt_smoothData();

  /* End of Outputs for SubSystem: '<Root>/smoothData' */

  /* S-Function (madgwick_f): '<S5>/S-Function Builder1' */
  madgwick_f_Outputs_wrapper(&SensAdapt_B.Product, &SensAdapt_B.Product_jqhr,
    &SensAdapt_B.Product_krg1, &SensAdapt_B.Product_nhwi,
    &SensAdapt_B.Product_ax4f, &SensAdapt_B.Product_pz1k,
    &SensAdapt_B.SFunctionBuilder1_o1, &SensAdapt_B.SFunctionBuilder1_o2,
    &SensAdapt_B.SFunctionBuilder1_o3, &SensAdapt_B.SFunctionBuilder1_o4 );

  /* Update for UnitDelay: '<Root>/Unit Delay12' incorporates:
   *  BusCreator: '<Root>/Bus Creator'
   */
  SensAdapt_DWork.UnitDelay12_DSTATE.AccXDataS = SensAdapt_B.Product;
  SensAdapt_DWork.UnitDelay12_DSTATE.AccYDataS = SensAdapt_B.Product_jqhr;
  SensAdapt_DWork.UnitDelay12_DSTATE.AccZDataS = SensAdapt_B.Product_krg1;
  SensAdapt_DWork.UnitDelay12_DSTATE.GyroXDataS = SensAdapt_B.Product_nhwi;
  SensAdapt_DWork.UnitDelay12_DSTATE.GyroYDataS = SensAdapt_B.Product_ax4f;
  SensAdapt_DWork.UnitDelay12_DSTATE.GyroZDataS = SensAdapt_B.Product_pz1k;
  SensAdapt_DWork.UnitDelay12_DSTATE.q0 = SensAdapt_B.SFunctionBuilder1_o1;
  SensAdapt_DWork.UnitDelay12_DSTATE.q1 = SensAdapt_B.SFunctionBuilder1_o2;
  SensAdapt_DWork.UnitDelay12_DSTATE.q2 = SensAdapt_B.SFunctionBuilder1_o3;
  SensAdapt_DWork.UnitDelay12_DSTATE.q3 = SensAdapt_B.SFunctionBuilder1_o4;
}

/* Model initialize function */
void SensAdapt_initialize(void)
{
  /* Registration code */

  /* block I/O */
  {
    SensAdapt_B.AccXData = 0.0;
    SensAdapt_B.AccYData = 0.0;
    SensAdapt_B.AccZData = 0.0;
    SensAdapt_B.GyroXData = 0.0;
    SensAdapt_B.GyroYData = 0.0;
    SensAdapt_B.GyroZData = 0.0;
    SensAdapt_B.SFunctionBuilder1_o1 = 0.0;
    SensAdapt_B.SFunctionBuilder1_o2 = 0.0;
    SensAdapt_B.SFunctionBuilder1_o3 = 0.0;
    SensAdapt_B.SFunctionBuilder1_o4 = 0.0;
    SensAdapt_B.Product = 0.0;
    SensAdapt_B.Product_jqhr = 0.0;
    SensAdapt_B.Product_krg1 = 0.0;
    SensAdapt_B.Product_nhwi = 0.0;
    SensAdapt_B.Product_ax4f = 0.0;
    SensAdapt_B.Product_pz1k = 0.0;
    SensAdapt_B.axc = 0.0;
    SensAdapt_B.ayc = 0.0;
    SensAdapt_B.azc = 0.0;
    SensAdapt_B.gxc = 0.0;
    SensAdapt_B.gyc = 0.0;
    SensAdapt_B.gzc = 0.0;
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
      SensAdapt_DWork.TappedDelay_X_h4nz[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 9; i++) {
      SensAdapt_DWork.TappedDelay_X_auph[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 9; i++) {
      SensAdapt_DWork.TappedDelay_X_ahra[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 9; i++) {
      SensAdapt_DWork.TappedDelay_X_nmbc[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 9; i++) {
      SensAdapt_DWork.TappedDelay_X_byda[i] = 0.0;
    }
  }

  /* InitializeConditions for Atomic SubSystem: '<Root>/smoothData' */
  SensAdapt_smoothData_Init();

  /* End of InitializeConditions for SubSystem: '<Root>/smoothData' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
