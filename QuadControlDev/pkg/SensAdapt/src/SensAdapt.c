/*
 * File: SensAdapt.c
 *
 * Code generated for Simulink model 'SensAdapt'.
 *
 * Model version                  : 1.386
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 19 2013)
 * C/C++ source code generated on : Fri Oct 19 20:34:59 2018
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
   *  Constant: '<S2>/tomssquare'
   */
  SensAdapt_B.accx_gf4n = SensAdapt_B.axc / 835.04;

  /* Product: '<S2>/accy' incorporates:
   *  Constant: '<S2>/tomssquare'
   */
  SensAdapt_B.accy_azyn = SensAdapt_B.ayc / 835.04;

  /* Product: '<S2>/accz' incorporates:
   *  Constant: '<S2>/tomssquare'
   */
  SensAdapt_B.accz_nuj4 = SensAdapt_B.azc / 835.04;
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
    (SensAdapt_DWork.UnitDelay_DSTATE_lkem * 0.8);

  /* Sum: '<S11>/Add' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S11>/Constant1'
   *  Product: '<S11>/Product'
   *  Product: '<S11>/Product1'
   *  UnitDelay: '<S11>/Unit Delay'
   */
  SensAdapt_B.Add_g0zf = (SensAdapt_B.accy_azyn * 0.2) +
    (SensAdapt_DWork.UnitDelay_DSTATE_lfj0 * 0.8);

  /* Sum: '<S10>/Add' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/Constant1'
   *  Product: '<S10>/Product'
   *  Product: '<S10>/Product1'
   *  UnitDelay: '<S10>/Unit Delay'
   */
  SensAdapt_B.Add_p1ev = (SensAdapt_B.accz_nuj4 * 0.2) +
    (SensAdapt_DWork.UnitDelay_DSTATE_er14 * 0.8);

  /* Inport: '<S6>/gyrox_data_in' */
  SensAdapt_B.gyrox_data_in = SensAdapt_B.accx;

  /* Inport: '<S6>/gyroy_data_in' */
  SensAdapt_B.gyroy_data_in = SensAdapt_B.accy;

  /* Inport: '<S6>/gyroz_data_in' */
  SensAdapt_B.gyroz_data_in = SensAdapt_B.accz;

  /* Update for UnitDelay: '<S9>/Unit Delay' */
  SensAdapt_DWork.UnitDelay_DSTATE_lkem = SensAdapt_B.Add;

  /* Update for UnitDelay: '<S11>/Unit Delay' */
  SensAdapt_DWork.UnitDelay_DSTATE_lfj0 = SensAdapt_B.Add_g0zf;

  /* Update for UnitDelay: '<S10>/Unit Delay' */
  SensAdapt_DWork.UnitDelay_DSTATE_er14 = SensAdapt_B.Add_p1ev;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T tmp;
  int32_T tmp_0;
  if ((rtIsNaN(u0)) || (rtIsNaN(u1))) {
    y = (rtNaN);
  } else if ((rtIsInf(u0)) && (rtIsInf(u1))) {
    if (u1 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u0 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(tmp_0, tmp);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model step function */
void SensAdapt_step(void)
{
  real_T R_test[9];
  real_T err;
  real_T r[3];
  real_T r_0[3];
  real_T r_1[3];
  real_T OZ_acc[3];
  real_T OZ_gyro[3];
  int8_T I[9];
  real_T f_y;
  int32_T i;
  real_T scale;
  static const int8_T b[3] = { 0, 0, 1 };

  real_T rtb_th;
  real_T rtb_ph;
  real_T rtb_qy;
  real_T rtb_qw;
  real_T I_0[9];
  real_T d_y[9];
  real_T tmp[9];
  int32_T i_0;
  int32_T i_1;

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
  /* Outputs for Enabled SubSystem: '<S16>/Subsystem' incorporates:
   *  EnablePort: '<S19>/Enable'
   */
  /* MATLAB Function 'SensAdapt/stateEstimator/geEstimator/Subsystem/MATLAB Function': '<S24>:1' */
  /* R = eye(3); */
  /* '<S24>:1:8' ts = 0.01; */
  /* '<S24>:1:9' k = 50; */
  /* integration */
  /* '<S24>:1:12' wx = gyrox; */
  /* '<S24>:1:13' wy = gyroy; */
  /* '<S24>:1:14' wz = gyroz; */
  /* '<S24>:1:16' wb_vp = [0 -wz wy; wz 0 -wx;-wy wx 0]; */
  /* '<S24>:1:17' R_test = R*(eye(3)+ ts*wb_vp); */
  for (i = 0; i < 9; i++) {
    /* SwitchCase: '<S7>/Switch Case' incorporates:
     *  MATLAB Function: '<S19>/MATLAB Function'
     */
    I[i] = 0;
  }

  for (i = 0; i < 3; i++) {
    /* SwitchCase: '<S7>/Switch Case' incorporates:
     *  MATLAB Function: '<S19>/MATLAB Function'
     */
    I[i + (3 * i)] = 1;
  }

  /* SwitchCase: '<S7>/Switch Case' incorporates:
   *  Constant: '<S21>/Constant'
   *  Constant: '<S21>/Constant1'
   *  Constant: '<S22>/Constant'
   *  Constant: '<S22>/Constant1'
   *  Constant: '<S23>/Constant'
   *  Constant: '<S23>/Constant1'
   *  MATLAB Function: '<S19>/MATLAB Function'
   *  Product: '<S21>/Product'
   *  Product: '<S21>/Product1'
   *  Product: '<S22>/Product'
   *  Product: '<S22>/Product1'
   *  Product: '<S23>/Product'
   *  Product: '<S23>/Product1'
   *  SignalConversion: '<S19>/OutportBufferForOut1'
   *  Sum: '<S21>/Add'
   *  Sum: '<S22>/Add'
   *  Sum: '<S23>/Add'
   *  UnitDelay: '<S21>/Unit Delay'
   *  UnitDelay: '<S22>/Unit Delay'
   *  UnitDelay: '<S23>/Unit Delay'
   */
  d_y[0] = 0.0;
  d_y[3] = -SensAdapt_B.gyroz_data_in;
  d_y[6] = SensAdapt_B.gyroy_data_in;
  d_y[1] = SensAdapt_B.gyroz_data_in;
  d_y[4] = 0.0;
  d_y[7] = -SensAdapt_B.gyrox_data_in;
  d_y[2] = -SensAdapt_B.gyroy_data_in;
  d_y[5] = SensAdapt_B.gyrox_data_in;
  d_y[8] = 0.0;
  for (i = 0; i < 3; i++) {
    for (i_1 = 0; i_1 < 3; i_1++) {
      I_0[i_1 + (3 * i)] = ((real_T)I[i_1 + (3 * i)]) + (0.01 * d_y[i_1 + (3 * i)]);
    }
  }

  for (i = 0; i < 3; i++) {
    for (i_1 = 0; i_1 < 3; i_1++) {
      R_test[i + (3 * i_1)] = 0.0;
      for (i_0 = 0; i_0 < 3; i_0++) {
        R_test[i + (3 * i_1)] += SensAdapt_DWork.R[i + (3 * i_0)] * I_0[i_0 + (3
          * i_1)];
      }
    }
  }

  /* orthogonalization */
  /* '<S24>:1:20' X = R_test(:,1); */
  /* '<S24>:1:21' Y = R_test(:,2); */
  /* '<S24>:1:23' err = X' * Y; */
  err = 0.0;
  for (i = 0; i < 3; i++) {
    err += R_test[i] * R_test[3 + i];
  }

  /* '<S24>:1:24' r1 = X - err/2*Y; */
  rtb_qw = err / 2.0;

  /* '<S24>:1:25' r2 = Y - err/2*X; */
  err /= 2.0;
  for (i = 0; i < 3; i++) {
    r[i] = R_test[i] - (rtb_qw * R_test[3 + i]);
    r_0[i] = R_test[3 + i] - (err * R_test[i]);
  }

  /* '<S24>:1:26' r3 = cross(r1,r2); */
  r_1[0] = (r[1] * r_0[2]) - (r[2] * r_0[1]);
  r_1[1] = (r[2] * r_0[0]) - (r[0] * r_0[2]);
  r_1[2] = (r[0] * r_0[1]) - (r[1] * r_0[0]);

  /* '<S24>:1:28' Xn = 1/2*(3-r1'*r1)*r1; */
  err = 0.0;
  for (i = 0; i < 3; i++) {
    err += r[i] * r[i];
  }

  rtb_ph = 0.5 * (3.0 - err);

  /* '<S24>:1:29' Yn = 1/2*(3-r2'*r2)*r2; */
  err = 0.0;
  for (i = 0; i < 3; i++) {
    err += r_0[i] * r_0[i];
  }

  f_y = 0.5 * (3.0 - err);

  /* '<S24>:1:30' Zn = 1/2*(3-r3'*r3)*r3; */
  err = 0.0;
  for (i = 0; i < 3; i++) {
    err += r_1[i] * r_1[i];
  }

  err = 0.5 * (3.0 - err);

  /* '<S24>:1:32' R_test = [Xn,Yn,Zn]; */
  /*    sensor fusion */
  /* '<S24>:1:35' OZ_acc = ([accx;accy;accz]); */
  OZ_acc[0] = SensAdapt_B.Add;
  OZ_acc[1] = SensAdapt_B.Add_g0zf;
  OZ_acc[2] = SensAdapt_B.Add_p1ev;

  /* '<S24>:1:36' OZ_acc = OZ_acc/norm(OZ_acc); */
  rtb_qw = 0.0;
  scale = 2.2250738585072014E-308;
  for (i = 0; i < 3; i++) {
    rtb_qy = fabs(OZ_acc[i]);
    if (rtb_qy > scale) {
      rtb_th = scale / rtb_qy;
      rtb_qw = 1.0 + ((rtb_qw * rtb_th) * rtb_th);
      scale = rtb_qy;
    } else {
      rtb_th = rtb_qy / scale;
      rtb_qw += rtb_th * rtb_th;
    }
  }

  rtb_qw = scale * sqrt(rtb_qw);

  /* '<S24>:1:37' OZ_gyro = R_test*[0;0;1]; */
  for (i = 0; i < 3; i++) {
    d_y[i] = rtb_ph * r[i];
    OZ_acc[i] /= rtb_qw;
  }

  for (i = 0; i < 3; i++) {
    d_y[3 + i] = f_y * r_0[i];
  }

  for (i = 0; i < 3; i++) {
    d_y[6 + i] = err * r_1[i];
  }

  for (i = 0; i < 3; i++) {
    OZ_gyro[i] = 0.0;
    for (i_1 = 0; i_1 < 3; i_1++) {
      OZ_gyro[i] += d_y[i + (3 * i_1)] * ((real_T)b[i_1]);
    }
  }

  /* '<S24>:1:39' wf = k*cross(OZ_gyro,OZ_acc); */
  /* '<S24>:1:40' W = [wx;wy;wz] - wf; */
  r[0] = SensAdapt_B.gyrox_data_in - (50.0 * ((OZ_gyro[1] * OZ_acc[2]) -
    (OZ_gyro[2] * OZ_acc[1])));
  r[1] = SensAdapt_B.gyroy_data_in - (50.0 * ((OZ_gyro[2] * OZ_acc[0]) -
    (OZ_gyro[0] * OZ_acc[2])));
  r[2] = SensAdapt_B.gyroz_data_in - (50.0 * ((OZ_gyro[0] * OZ_acc[1]) -
    (OZ_gyro[1] * OZ_acc[0])));

  /* '<S24>:1:42' wb_vp = [0 -W(3) W(2); W(3) 0 -W(1);-W(2) W(1) 0]; */
  /* '<S24>:1:43' R = R*(eye(3)+ ts*wb_vp); */
  for (i = 0; i < 9; i++) {
    I[i] = 0;
  }

  for (i = 0; i < 3; i++) {
    I[i + (3 * i)] = 1;
  }

  tmp[0] = 0.0;
  tmp[3] = -r[2];
  tmp[6] = r[1];
  tmp[1] = r[2];
  tmp[4] = 0.0;
  tmp[7] = -r[0];
  tmp[2] = -r[1];
  tmp[5] = r[0];
  tmp[8] = 0.0;
  for (i = 0; i < 3; i++) {
    for (i_1 = 0; i_1 < 3; i_1++) {
      I_0[i_1 + (3 * i)] = ((real_T)I[i_1 + (3 * i)]) + (0.01 * tmp[i_1 + (3 * i)]);
    }
  }

  for (i = 0; i < 3; i++) {
    for (i_1 = 0; i_1 < 3; i_1++) {
      d_y[i + (3 * i_1)] = 0.0;
      for (i_0 = 0; i_0 < 3; i_0++) {
        d_y[i + (3 * i_1)] += SensAdapt_DWork.R[i + (3 * i_0)] * I_0[i_0 + (3 *
          i_1)];
      }
    }
  }

  for (i = 0; i < 3; i++) {
    for (i_1 = 0; i_1 < 3; i_1++) {
      SensAdapt_DWork.R[i_1 + (3 * i)] = d_y[i_1 + (3 * i)];
    }
  }

  /*    orthogonalization */
  /* '<S24>:1:46' X = R(:,1); */
  /* '<S24>:1:47' Y = R(:,2); */
  /* '<S24>:1:49' err = X' * Y; */
  err = 0.0;
  for (i = 0; i < 3; i++) {
    err += SensAdapt_DWork.R[i] * SensAdapt_DWork.R[3 + i];
  }

  /* '<S24>:1:50' r1 = X - err/2*Y; */
  rtb_qw = err / 2.0;

  /* '<S24>:1:51' r2 = Y - err/2*X; */
  err /= 2.0;
  for (i = 0; i < 3; i++) {
    r[i] = SensAdapt_DWork.R[i] - (rtb_qw * SensAdapt_DWork.R[3 + i]);
    r_0[i] = SensAdapt_DWork.R[3 + i] - (err * SensAdapt_DWork.R[i]);
  }

  /* '<S24>:1:52' r3 = cross(r1,r2); */
  r_1[0] = (r[1] * r_0[2]) - (r[2] * r_0[1]);
  r_1[1] = (r[2] * r_0[0]) - (r[0] * r_0[2]);
  r_1[2] = (r[0] * r_0[1]) - (r[1] * r_0[0]);

  /* '<S24>:1:54' Xn = 1/2*(3-r1'*r1)*r1; */
  err = 0.0;
  for (i = 0; i < 3; i++) {
    err += r[i] * r[i];
  }

  rtb_qw = 0.5 * (3.0 - err);

  /* '<S24>:1:55' Yn = 1/2*(3-r2'*r2)*r2; */
  err = 0.0;
  for (i = 0; i < 3; i++) {
    err += r_0[i] * r_0[i];
  }

  scale = 0.5 * (3.0 - err);

  /* '<S24>:1:56' Zn = 1/2*(3-r3'*r3)*r3; */
  err = 0.0;
  for (i = 0; i < 3; i++) {
    err += r_1[i] * r_1[i];
    SensAdapt_DWork.R[i] = rtb_qw * r[i];
  }

  err = 0.5 * (3.0 - err);

  /* '<S24>:1:58' R = [Xn,Yn,Zn]; */
  for (i = 0; i < 3; i++) {
    SensAdapt_DWork.R[i + 3] = scale * r_0[i];
  }

  for (i = 0; i < 3; i++) {
    SensAdapt_DWork.R[i + 6] = err * r_1[i];
  }

  /* '<S24>:1:60' ch = asin(R(3,2)); */
  f_y = asin(SensAdapt_DWork.R[5]);

  /* '<S24>:1:61' ch2 = -asin(R(3,2))+pi; */
  err = asin(SensAdapt_DWork.R[5]);

  /* '<S24>:1:63' if abs(cos(ch)) > 0.01 */
  if (fabs(cos(f_y)) > 0.01) {
    /* '<S24>:1:64' ph = atan2(-R(3,1)/cos(ch),R(3,3)/cos(ch)); */
    rtb_ph = rt_atan2d_snf((-SensAdapt_DWork.R[2]) / cos(f_y),
      SensAdapt_DWork.R[8] / cos(f_y));

    /* '<S24>:1:65' th = atan2(-R(2,1)/cos(ch2),R(2,2)/cos(ch2)); */
    rtb_th = rt_atan2d_snf((-SensAdapt_DWork.R[1]) / cos((-err) +
      3.1415926535897931), SensAdapt_DWork.R[4] / cos((-err) +
      3.1415926535897931));
  } else {
    /* '<S24>:1:66' else */
    /* '<S24>:1:67' ph = 0; */
    rtb_ph = 0.0;

    /* '<S24>:1:68' th = 0; */
    rtb_th = 0.0;
  }

  /*  aflare quaternioni */
  /* '<S24>:1:72' tr = R(1,1) + R(2,2) + R(3,3); */
  err = (SensAdapt_DWork.R[0] + SensAdapt_DWork.R[4]) + SensAdapt_DWork.R[8];

  /* '<S24>:1:74' m00 = R(1,1); */
  /* '<S24>:1:75' m01 = R(1,2); */
  /* '<S24>:1:76' m02 = R(1,3); */
  /* '<S24>:1:77' m10 = R(2,1); */
  /* '<S24>:1:78' m11 = R(2,2); */
  /* '<S24>:1:79' m12 = R(2,3); */
  /* '<S24>:1:80' m20 = R(3,1); */
  /* '<S24>:1:81' m21 = R(3,2); */
  /* '<S24>:1:82' m22 = R(3,3); */
  /* '<S24>:1:84' if (tr > 0) */
  if (err > 0.0) {
    /* '<S24>:1:85' S = sqrt(tr+1.0) * 2; */
    err = sqrt(err + 1.0) * 2.0;

    /* '<S24>:1:86' qw = 0.25 * S; */
    rtb_qw = 0.25 * err;

    /* '<S24>:1:87' qx = (m21 - m12) / S; */
    scale = (SensAdapt_DWork.R[5] - SensAdapt_DWork.R[7]) / err;

    /* '<S24>:1:88' qy = (m02 - m20) / S; */
    rtb_qy = (SensAdapt_DWork.R[6] - SensAdapt_DWork.R[2]) / err;

    /* '<S24>:1:89' qz = (m10 - m01) / S; */
    err = (SensAdapt_DWork.R[1] - SensAdapt_DWork.R[3]) / err;
  } else if ((SensAdapt_DWork.R[0] > SensAdapt_DWork.R[4]) &&
             (SensAdapt_DWork.R[0] > SensAdapt_DWork.R[8])) {
    /* '<S24>:1:90' elseif ((m00 > m11)&&(m00 > m22)) */
    /* '<S24>:1:91' S = sqrt(1.0 + m00 - m11 - m22) * 2; */
    err = sqrt(((1.0 + SensAdapt_DWork.R[0]) - SensAdapt_DWork.R[4]) -
               SensAdapt_DWork.R[8]) * 2.0;

    /* '<S24>:1:92' qw = (m21 - m12) / S; */
    rtb_qw = (SensAdapt_DWork.R[5] - SensAdapt_DWork.R[7]) / err;

    /* '<S24>:1:93' qx = 0.25 * S; */
    scale = 0.25 * err;

    /* '<S24>:1:94' qy = (m01 + m10) / S; */
    rtb_qy = (SensAdapt_DWork.R[3] + SensAdapt_DWork.R[1]) / err;

    /* '<S24>:1:95' qz = (m02 + m20) / S; */
    err = (SensAdapt_DWork.R[6] + SensAdapt_DWork.R[2]) / err;
  } else if (SensAdapt_DWork.R[4] > SensAdapt_DWork.R[8]) {
    /* '<S24>:1:96' elseif (m11 > m22) */
    /* '<S24>:1:97' S = sqrt(1.0 + m11 - m00 - m22) * 2; */
    err = sqrt(((1.0 + SensAdapt_DWork.R[4]) - SensAdapt_DWork.R[0]) -
               SensAdapt_DWork.R[8]) * 2.0;

    /* '<S24>:1:98' qw = (m02 - m20) / S; */
    rtb_qw = (SensAdapt_DWork.R[6] - SensAdapt_DWork.R[2]) / err;

    /* '<S24>:1:99' qx = (m01 + m10) / S; */
    scale = (SensAdapt_DWork.R[3] + SensAdapt_DWork.R[1]) / err;

    /* '<S24>:1:100' qy = 0.25 * S; */
    rtb_qy = 0.25 * err;

    /* '<S24>:1:101' qz = (m12 + m21) / S; */
    err = (SensAdapt_DWork.R[7] + SensAdapt_DWork.R[5]) / err;
  } else {
    /* '<S24>:1:102' else */
    /* '<S24>:1:103' S = sqrt(1.0 + m22 - m00 - m11) * 2; */
    err = sqrt(((1.0 + SensAdapt_DWork.R[8]) - SensAdapt_DWork.R[0]) -
               SensAdapt_DWork.R[4]) * 2.0;

    /* '<S24>:1:104' qw = (m10 - m01) / S; */
    rtb_qw = (SensAdapt_DWork.R[1] - SensAdapt_DWork.R[3]) / err;

    /* '<S24>:1:105' qx = (m02 + m20) / S; */
    scale = (SensAdapt_DWork.R[6] + SensAdapt_DWork.R[2]) / err;

    /* '<S24>:1:106' qy = (m12 + m21) / S; */
    rtb_qy = (SensAdapt_DWork.R[7] + SensAdapt_DWork.R[5]) / err;

    /* '<S24>:1:107' qz = 0.25 * S; */
    err *= 0.25;
  }

  SensAdapt_DWork.UnitDelay_DSTATE = (rtb_th * 0.2) +
    (SensAdapt_DWork.UnitDelay_DSTATE * 0.8);
  SensAdapt_DWork.UnitDelay_DSTATE_ayto = (f_y * 0.2) +
    (SensAdapt_DWork.UnitDelay_DSTATE_ayto * 0.8);
  SensAdapt_DWork.UnitDelay_DSTATE_c4lw = (rtb_ph * 0.2) +
    (SensAdapt_DWork.UnitDelay_DSTATE_c4lw * 0.8);
  SensAdapt_B.Merge[0] = rtb_qw;
  SensAdapt_B.Merge[1] = scale;
  SensAdapt_B.Merge[2] = rtb_qy;
  SensAdapt_B.Merge[3] = err;
  SensAdapt_B.Merge[4] = SensAdapt_DWork.UnitDelay_DSTATE;
  SensAdapt_B.Merge[5] = SensAdapt_DWork.UnitDelay_DSTATE_ayto;
  SensAdapt_B.Merge[6] = SensAdapt_DWork.UnitDelay_DSTATE_c4lw;

  /* End of Outputs for SubSystem: '<S16>/Subsystem' */
  /* End of Outputs for SubSystem: '<S7>/geEstimator' */

  /* Update for UnitDelay: '<S1>/Unit Delay12' incorporates:
   *  BusCreator: '<S1>/Bus Creator'
   */
  SensAdapt_DWork.UnitDelay12_DSTATE.AccXDataS = SensAdapt_B.Add;
  SensAdapt_DWork.UnitDelay12_DSTATE.AccYDataS = SensAdapt_B.Add_g0zf;
  SensAdapt_DWork.UnitDelay12_DSTATE.AccZDataS = SensAdapt_B.Add_p1ev;
  SensAdapt_DWork.UnitDelay12_DSTATE.GyroXDataS = SensAdapt_B.gyrox_data_in;
  SensAdapt_DWork.UnitDelay12_DSTATE.GyroYDataS = SensAdapt_B.gyroy_data_in;
  SensAdapt_DWork.UnitDelay12_DSTATE.GyroZDataS = SensAdapt_B.gyroz_data_in;
  SensAdapt_DWork.UnitDelay12_DSTATE.q0 = SensAdapt_B.Merge[0];
  SensAdapt_DWork.UnitDelay12_DSTATE.q1 = SensAdapt_B.Merge[1];
  SensAdapt_DWork.UnitDelay12_DSTATE.q2 = SensAdapt_B.Merge[2];
  SensAdapt_DWork.UnitDelay12_DSTATE.q3 = SensAdapt_B.Merge[3];
  SensAdapt_DWork.UnitDelay12_DSTATE.th = SensAdapt_B.Merge[4];
  SensAdapt_DWork.UnitDelay12_DSTATE.ch = SensAdapt_B.Merge[5];
  SensAdapt_DWork.UnitDelay12_DSTATE.ph = SensAdapt_B.Merge[6];
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
    for (i = 0; i < 7; i++) {
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
    SensAdapt_B.Add_g0zf = 0.0;
    SensAdapt_B.Add_p1ev = 0.0;
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
  SensAdapt_DWork.UnitDelay_DSTATE_ayto = 0.0;
  SensAdapt_DWork.UnitDelay_DSTATE_c4lw = 0.0;
  SensAdapt_DWork.UnitDelay_DSTATE_lkem = 0.0;
  SensAdapt_DWork.UnitDelay_DSTATE_lfj0 = 0.0;
  SensAdapt_DWork.UnitDelay_DSTATE_er14 = 0.0;

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
    for (i = 0; i < 7; i++) {
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
