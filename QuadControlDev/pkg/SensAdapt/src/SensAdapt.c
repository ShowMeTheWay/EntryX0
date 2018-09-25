/*
 * File: SensAdapt.c
 *
 * Code generated for Simulink model 'SensAdapt'.
 *
 * Model version                  : 1.361
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 19 2013)
 * C/C++ source code generated on : Sat Sep 22 20:29:49 2018
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
 * Output and update for atomic system: '<S1>/AccConv'
 * Block description for: '<S1>/AccConv'
 *   acc conversion block
 */
void SensAdapt_AccConv(void)
{
  /* Product: '<S2>/accx' incorporates:
   *  Constant: '<S2>/tog'
   */
  SensAdapt_B.accx_gf4n = SensAdapt_B.axc / 8192.0;

  /* Product: '<S2>/accy' incorporates:
   *  Constant: '<S2>/tog'
   */
  SensAdapt_B.accy_azyn = SensAdapt_B.ayc / 8192.0;

  /* Product: '<S2>/accz' incorporates:
   *  Constant: '<S2>/tog'
   */
  SensAdapt_B.accz_nuj4 = SensAdapt_B.azc / 8192.0;
}

/* Output and update for atomic system: '<S1>/GyroConv' */
void SensAdapt_GyroConv(void)
{
  /* Product: '<S3>/accx' incorporates:
   *  Constant: '<S3>/Constant'
   */
  SensAdapt_B.accx = SensAdapt_B.gxc / 939.650784;

  /* Product: '<S3>/accy' incorporates:
   *  Constant: '<S3>/Constant'
   */
  SensAdapt_B.accy = SensAdapt_B.gyc / 939.650784;

  /* Product: '<S3>/accz' incorporates:
   *  Constant: '<S3>/Constant'
   */
  SensAdapt_B.accz = SensAdapt_B.gzc / 939.650784;
}

/* Output and update for atomic system: '<S1>/calibrationBlock' */
void SensAdapt_calibrationBlock(void)
{
  /* MATLAB Function: '<S4>/MATLAB Function' */
  /* MATLAB Function 'SensAdapt/calibrationBlock/MATLAB Function': '<S8>:1' */
  /* '<S8>:1:3' axc = ax - axoff; */
  SensAdapt_B.axc = SensAdapt_B.AccXData - -710.0;

  /* '<S8>:1:4' ayc = ay - ayoff; */
  SensAdapt_B.ayc = SensAdapt_B.AccYData - 50.0;

  /* '<S8>:1:5' azc = az - azoff; */
  SensAdapt_B.azc = SensAdapt_B.AccZData - 467.0;

  /* '<S8>:1:6' gxc = gx - gxoff; */
  SensAdapt_B.gxc = SensAdapt_B.GyroXData - 29.0;

  /* '<S8>:1:7' gyc = gy - gyoff; */
  SensAdapt_B.gyc = SensAdapt_B.GyroYData - -5.0;

  /* '<S8>:1:8' gzc = gz - gzoff; */
  SensAdapt_B.gzc = SensAdapt_B.GyroZData - 7.0;
}

/* Output and update for atomic system: '<S1>/smoothData' */
void SensAdapt_smoothData(void)
{
  /* Sum: '<S9>/Add' incorporates:
   *  Constant: '<S9>/Constant'
   *  Constant: '<S9>/Constant1'
   *  Product: '<S9>/Product'
   *  Product: '<S9>/Product1'
   *  UnitDelay: '<S9>/Unit Delay'
   */
  SensAdapt_B.Add = (SensAdapt_B.accx_gf4n * 0.2) +
    (SensAdapt_DWork.UnitDelay_DSTATE * 0.8);

  /* Sum: '<S10>/Add' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/Constant1'
   *  Product: '<S10>/Product'
   *  Product: '<S10>/Product1'
   *  UnitDelay: '<S10>/Unit Delay'
   */
  SensAdapt_B.Add_pnfv = (SensAdapt_B.accy_azyn * 0.2) +
    (SensAdapt_DWork.UnitDelay_DSTATE_luzf * 0.8);

  /* Sum: '<S11>/Add' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S11>/Constant1'
   *  Product: '<S11>/Product'
   *  Product: '<S11>/Product1'
   *  UnitDelay: '<S11>/Unit Delay'
   */
  SensAdapt_B.Add_bu3s = (SensAdapt_B.accz_nuj4 * 0.2) +
    (SensAdapt_DWork.UnitDelay_DSTATE_i4hd * 0.8);

  /* Inport: '<S6>/gyrox_data_in' */
  SensAdapt_B.gyrox_data_in = SensAdapt_B.accx;

  /* Inport: '<S6>/gyroy_data_in' */
  SensAdapt_B.gyroy_data_in = SensAdapt_B.accy;

  /* Inport: '<S6>/gyroz_data_in' */
  SensAdapt_B.gyroz_data_in = SensAdapt_B.accz;

  /* Update for UnitDelay: '<S9>/Unit Delay' */
  SensAdapt_DWork.UnitDelay_DSTATE = SensAdapt_B.Add;

  /* Update for UnitDelay: '<S10>/Unit Delay' */
  SensAdapt_DWork.UnitDelay_DSTATE_luzf = SensAdapt_B.Add_pnfv;

  /* Update for UnitDelay: '<S11>/Unit Delay' */
  SensAdapt_DWork.UnitDelay_DSTATE_i4hd = SensAdapt_B.Add_bu3s;
}

/* Model step function */
void SensAdapt_step(void)
{
  /* UnitDelay: '<S1>/Unit Delay12' */
  UART_DisplayData(SensAdapt_DWork.UnitDelay12_DSTATE);

  /* BusSelector: '<S1>/Bus Selector' incorporates:
   *  Inport: '<Root>/In1'
   */
  SensAdapt_B.AccXData = GetData__stMPU_6050().AccXData;
  SensAdapt_B.AccYData = GetData__stMPU_6050().AccYData;
  SensAdapt_B.AccZData = GetData__stMPU_6050().AccZData;
  SensAdapt_B.GyroXData = GetData__stMPU_6050().GyroXData;
  SensAdapt_B.GyroYData = GetData__stMPU_6050().GyroYData;
  SensAdapt_B.GyroZData = GetData__stMPU_6050().GyroZData;

  /* Outputs for Atomic SubSystem: '<S1>/calibrationBlock' */
  SensAdapt_calibrationBlock();

  /* End of Outputs for SubSystem: '<S1>/calibrationBlock' */

  /* Outputs for Atomic SubSystem: '<S1>/AccConv'
   *
   * Block description for '<S1>/AccConv':
   *  acc conversion block
   */
  SensAdapt_AccConv();

  /* End of Outputs for SubSystem: '<S1>/AccConv' */

  /* Outputs for Atomic SubSystem: '<S1>/GyroConv' */
  SensAdapt_GyroConv();

  /* End of Outputs for SubSystem: '<S1>/GyroConv' */

  /* Outputs for Atomic SubSystem: '<S1>/smoothData' */
  SensAdapt_smoothData();

  /* End of Outputs for SubSystem: '<S1>/smoothData' */

  /* Outputs for IfAction SubSystem: '<S7>/geEstimator' incorporates:
   *  ActionPort: '<S16>/Action Port'
   */
  /* Outputs for Enabled SubSystem: '<S16>/Subsystem1' incorporates:
   *  EnablePort: '<S20>/Enable'
   */

  /* S-Function (genDigitsEst_f): '<S20>/S-Function Builder1' */
  genDigitsEst_f_Outputs_wrapper(&SensAdapt_B.Add, &SensAdapt_B.Add_pnfv,
    &SensAdapt_B.Add_bu3s, &SensAdapt_B.gyrox_data_in,
    &SensAdapt_B.gyroy_data_in, &SensAdapt_B.gyroz_data_in,
    &SensAdapt_B.SFunctionBuilder1_o1_gqrs,
    &SensAdapt_B.SFunctionBuilder1_o2_piyk,
    &SensAdapt_B.SFunctionBuilder1_o3_cr03 );
  SensAdapt_B.Merge[0] = SensAdapt_B.SFunctionBuilder1_o1_gqrs;
  SensAdapt_B.Merge[1] = SensAdapt_B.SFunctionBuilder1_o2_piyk;
  SensAdapt_B.Merge[2] = SensAdapt_B.SFunctionBuilder1_o3_cr03;
  SensAdapt_B.Merge[3] = 0.0;

  /* End of Outputs for SubSystem: '<S16>/Subsystem1' */
  /* End of Outputs for SubSystem: '<S7>/geEstimator' */

  /* Update for UnitDelay: '<S1>/Unit Delay12' incorporates:
   *  BusCreator: '<S1>/Bus Creator'
   */
  SensAdapt_DWork.UnitDelay12_DSTATE.AccXDataS = SensAdapt_B.Add;
  SensAdapt_DWork.UnitDelay12_DSTATE.AccYDataS = SensAdapt_B.Add_pnfv;
  SensAdapt_DWork.UnitDelay12_DSTATE.AccZDataS = SensAdapt_B.Add_bu3s;
  SensAdapt_DWork.UnitDelay12_DSTATE.GyroXDataS = SensAdapt_B.gyrox_data_in;
  SensAdapt_DWork.UnitDelay12_DSTATE.GyroYDataS = SensAdapt_B.gyroy_data_in;
  SensAdapt_DWork.UnitDelay12_DSTATE.GyroZDataS = SensAdapt_B.gyroz_data_in;
  SensAdapt_DWork.UnitDelay12_DSTATE.q0 = SensAdapt_B.Merge[0];
  SensAdapt_DWork.UnitDelay12_DSTATE.q1 = SensAdapt_B.Merge[1];
  SensAdapt_DWork.UnitDelay12_DSTATE.q2 = SensAdapt_B.Merge[2];
  SensAdapt_DWork.UnitDelay12_DSTATE.q3 = SensAdapt_B.Merge[3];
}

/* Model initialize function */
void SensAdapt_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* block I/O */
  {
    int_T i;
    for (i = 0; i < 4; i++) {
      SensAdapt_B.Merge[i] = 0.0;
    }

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
    SensAdapt_B.SFunctionBuilder1_o1_gqrs = 0.0;
    SensAdapt_B.SFunctionBuilder1_o2_piyk = 0.0;
    SensAdapt_B.SFunctionBuilder1_o3_cr03 = 0.0;
    SensAdapt_B.Add = 0.0;
    SensAdapt_B.Add_pnfv = 0.0;
    SensAdapt_B.Add_bu3s = 0.0;
    SensAdapt_B.gyrox_data_in = 0.0;
    SensAdapt_B.gyroy_data_in = 0.0;
    SensAdapt_B.gyroz_data_in = 0.0;
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
  SensAdapt_DWork.UnitDelay_DSTATE = 0.0;
  SensAdapt_DWork.UnitDelay_DSTATE_luzf = 0.0;
  SensAdapt_DWork.UnitDelay_DSTATE_i4hd = 0.0;

  {
    int_T i;
    for (i = 0; i < 9; i++) {
      SensAdapt_DWork.R[i] = 0.0;
    }
  }

  {
    int32_T i;

    /* Start for IfAction SubSystem: '<S7>/geEstimator' */
    /* Start for Enabled SubSystem: '<S16>/Subsystem' */
    /* Start for DataStoreMemory: '<S19>/Data Store Memory' */
    memcpy(&SensAdapt_DWork.R[0], SensAdapt_ConstP.DataStoreMemory_InitialValue,
           9U * (sizeof(real_T)));

    /* End of Start for SubSystem: '<S16>/Subsystem' */

    /* End of Start for SubSystem: '<S7>/geEstimator' */

    /* Start for Merge: '<S7>/Merge' */
    for (i = 0; i < 4; i++) {
      SensAdapt_B.Merge[i] = 0.0;
    }

    /* End of Start for Merge: '<S7>/Merge' */
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
