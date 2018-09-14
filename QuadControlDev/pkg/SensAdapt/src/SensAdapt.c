/*
 * File: SensAdapt.c
 *
 * Code generated for Simulink model 'SensAdapt'.
 *
 * Model version                  : 1.352
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 19 2013)
 * C/C++ source code generated on : Tue Sep 11 00:14:29 2018
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
  real_T y;
  real_T d_y;
  real_T f_y;
  int32_T i;
  real_T scale;
  real_T absxk;
  real_T t;
  static const int8_T b[3] = { 0, 0, 1 };

  real_T I_0[9];
  real_T d_y_0[9];
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
  /* MATLAB Function 'SensAdapt/stateEstimator/geEstimator/MATLAB Function': '<S19>:1' */
  /* R = eye(3); */
  /* '<S19>:1:8' ts = 0.01; */
  /* '<S19>:1:9' k = 10; */
  /* integration */
  /* '<S19>:1:12' wx = gyrox; */
  /* '<S19>:1:13' wy = gyroy; */
  /* '<S19>:1:14' wz = gyroz; */
  /* '<S19>:1:16' wb_vp = [0 -wz wy; wz 0 -wx;-wy wx 0]; */
  /* '<S19>:1:17' R_test = R*(eye(3)+ ts*wb_vp); */
  for (i = 0; i < 9; i++) {
    /* SwitchCase: '<S7>/Switch Case' incorporates:
     *  MATLAB Function: '<S16>/MATLAB Function'
     */
    I[i] = 0;
  }

  for (i = 0; i < 3; i++) {
    /* SwitchCase: '<S7>/Switch Case' incorporates:
     *  MATLAB Function: '<S16>/MATLAB Function'
     */
    I[i + (3 * i)] = 1;
  }

  /* SwitchCase: '<S7>/Switch Case' incorporates:
   *  Constant: '<S16>/Constant'
   *  MATLAB Function: '<S16>/MATLAB Function'
   *  SignalConversion: '<S16>/OutportBufferForOut1'
   */
  d_y_0[0] = 0.0;
  d_y_0[3] = -SensAdapt_B.gyroz_data_in;
  d_y_0[6] = SensAdapt_B.gyroy_data_in;
  d_y_0[1] = SensAdapt_B.gyroz_data_in;
  d_y_0[4] = 0.0;
  d_y_0[7] = -SensAdapt_B.gyrox_data_in;
  d_y_0[2] = -SensAdapt_B.gyroy_data_in;
  d_y_0[5] = SensAdapt_B.gyrox_data_in;
  d_y_0[8] = 0.0;
  for (i = 0; i < 3; i++) {
    for (i_1 = 0; i_1 < 3; i_1++) {
      I_0[i_1 + (3 * i)] = ((real_T)I[i_1 + (3 * i)]) + (0.01 * d_y_0[i_1 + (3 *
        i)]);
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
  /* '<S19>:1:20' X = R_test(:,1); */
  /* '<S19>:1:21' Y = R_test(:,2); */
  /* '<S19>:1:23' err = X' * Y; */
  err = 0.0;
  for (i = 0; i < 3; i++) {
    err += R_test[i] * R_test[3 + i];
  }

  /* '<S19>:1:24' r1 = X - err/2*Y; */
  y = err / 2.0;

  /* '<S19>:1:25' r2 = Y - err/2*X; */
  err /= 2.0;
  for (i = 0; i < 3; i++) {
    r[i] = R_test[i] - (y * R_test[3 + i]);
    r_0[i] = R_test[3 + i] - (err * R_test[i]);
  }

  /* '<S19>:1:26' r3 = cross(r1,r2); */
  r_1[0] = (r[1] * r_0[2]) - (r[2] * r_0[1]);
  r_1[1] = (r[2] * r_0[0]) - (r[0] * r_0[2]);
  r_1[2] = (r[0] * r_0[1]) - (r[1] * r_0[0]);

  /* '<S19>:1:28' Xn = 1/2*(3-r1'*r1)*r1; */
  err = 0.0;
  for (i = 0; i < 3; i++) {
    err += r[i] * r[i];
  }

  d_y = 0.5 * (3.0 - err);

  /* '<S19>:1:29' Yn = 1/2*(3-r2'*r2)*r2; */
  err = 0.0;
  for (i = 0; i < 3; i++) {
    err += r_0[i] * r_0[i];
  }

  f_y = 0.5 * (3.0 - err);

  /* '<S19>:1:30' Zn = 1/2*(3-r3'*r3)*r3; */
  err = 0.0;
  for (i = 0; i < 3; i++) {
    err += r_1[i] * r_1[i];
  }

  err = 0.5 * (3.0 - err);

  /* '<S19>:1:32' R_test = [Xn,Yn,Zn]; */
  /*    sensor fusion */
  /* '<S19>:1:35' OZ_acc = ([accx;accy;accz]); */
  OZ_acc[0] = SensAdapt_B.Add;
  OZ_acc[1] = SensAdapt_B.Add_pnfv;
  OZ_acc[2] = SensAdapt_B.Add_bu3s;

  /* '<S19>:1:36' OZ_acc = OZ_acc/norm(OZ_acc); */
  y = 0.0;
  scale = 2.2250738585072014E-308;
  for (i = 0; i < 3; i++) {
    absxk = fabs(OZ_acc[i]);
    if (absxk > scale) {
      t = scale / absxk;
      y = 1.0 + ((y * t) * t);
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }

  y = scale * sqrt(y);

  /* '<S19>:1:37' OZ_gyro = R_test*[0;0;1]; */
  for (i = 0; i < 3; i++) {
    d_y_0[i] = d_y * r[i];
    OZ_acc[i] /= y;
  }

  for (i = 0; i < 3; i++) {
    d_y_0[3 + i] = f_y * r_0[i];
  }

  for (i = 0; i < 3; i++) {
    d_y_0[6 + i] = err * r_1[i];
  }

  for (i = 0; i < 3; i++) {
    OZ_gyro[i] = 0.0;
    for (i_1 = 0; i_1 < 3; i_1++) {
      OZ_gyro[i] += d_y_0[i + (3 * i_1)] * ((real_T)b[i_1]);
    }
  }

  /* '<S19>:1:40' wf = k*cross(OZ_gyro,OZ_acc); */
  /* '<S19>:1:41' W = [wx;wy;wz] - wf; */
  r[0] = SensAdapt_B.gyrox_data_in - (10.0 * ((OZ_gyro[1] * OZ_acc[2]) -
    (OZ_gyro[2] * OZ_acc[1])));
  r[1] = SensAdapt_B.gyroy_data_in - (10.0 * ((OZ_gyro[2] * OZ_acc[0]) -
    (OZ_gyro[0] * OZ_acc[2])));
  r[2] = SensAdapt_B.gyroz_data_in - (10.0 * ((OZ_gyro[0] * OZ_acc[1]) -
    (OZ_gyro[1] * OZ_acc[0])));

  /* '<S19>:1:43' wb_vp = [0 -W(3) W(2); W(3) 0 -W(1);-W(2) W(1) 0]; */
  /* '<S19>:1:44' R = R*(eye(3)+ ts*wb_vp); */
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
      d_y_0[i + (3 * i_1)] = 0.0;
      for (i_0 = 0; i_0 < 3; i_0++) {
        d_y_0[i + (3 * i_1)] += SensAdapt_DWork.R[i + (3 * i_0)] * I_0[i_0 + (3 *
          i_1)];
      }
    }
  }

  for (i = 0; i < 3; i++) {
    for (i_1 = 0; i_1 < 3; i_1++) {
      SensAdapt_DWork.R[i_1 + (3 * i)] = d_y_0[i_1 + (3 * i)];
    }
  }

  /*    orthogonalization */
  /* '<S19>:1:47' X = R(:,1); */
  /* '<S19>:1:48' Y = R(:,2); */
  /* '<S19>:1:50' err = X' * Y; */
  err = 0.0;
  for (i = 0; i < 3; i++) {
    err += SensAdapt_DWork.R[i] * SensAdapt_DWork.R[3 + i];
  }

  /* '<S19>:1:51' r1 = X - err/2*Y; */
  y = err / 2.0;

  /* '<S19>:1:52' r2 = Y - err/2*X; */
  err /= 2.0;
  for (i = 0; i < 3; i++) {
    r[i] = SensAdapt_DWork.R[i] - (y * SensAdapt_DWork.R[3 + i]);
    r_0[i] = SensAdapt_DWork.R[3 + i] - (err * SensAdapt_DWork.R[i]);
  }

  /* '<S19>:1:53' r3 = cross(r1,r2); */
  r_1[0] = (r[1] * r_0[2]) - (r[2] * r_0[1]);
  r_1[1] = (r[2] * r_0[0]) - (r[0] * r_0[2]);
  r_1[2] = (r[0] * r_0[1]) - (r[1] * r_0[0]);

  /* '<S19>:1:55' Xn = 1/2*(3-r1'*r1)*r1; */
  err = 0.0;
  for (i = 0; i < 3; i++) {
    err += r[i] * r[i];
  }

  y = 0.5 * (3.0 - err);

  /* '<S19>:1:56' Yn = 1/2*(3-r2'*r2)*r2; */
  err = 0.0;
  for (i = 0; i < 3; i++) {
    err += r_0[i] * r_0[i];
  }

  scale = 0.5 * (3.0 - err);

  /* '<S19>:1:57' Zn = 1/2*(3-r3'*r3)*r3; */
  err = 0.0;
  for (i = 0; i < 3; i++) {
    err += r_1[i] * r_1[i];
    SensAdapt_DWork.R[i] = y * r[i];
  }

  err = 0.5 * (3.0 - err);

  /* '<S19>:1:59' R = [Xn,Yn,Zn]; */
  for (i = 0; i < 3; i++) {
    SensAdapt_DWork.R[i + 3] = scale * r_0[i];
  }

  for (i = 0; i < 3; i++) {
    SensAdapt_DWork.R[i + 6] = err * r_1[i];
  }

  /* '<S19>:1:61' ch = asin(R(3,2)); */
  y = asin(SensAdapt_DWork.R[5]);

  /* '<S19>:1:62' ch2 = -asin(R(3,2))+pi; */
  err = asin(SensAdapt_DWork.R[5]);

  /* '<S19>:1:64' if abs(cos(ch)) > 0.01 */
  if (fabs(cos(y)) > 0.01) {
    /* '<S19>:1:65' ph = atan2(-R(3,1)/cos(ch),R(3,3)/cos(ch)); */
    scale = rt_atan2d_snf((-SensAdapt_DWork.R[2]) / cos(y), SensAdapt_DWork.R[8]
                          / cos(y));

    /* '<S19>:1:66' th = atan2(-R(2,1)/cos(ch2),R(2,2)/cos(ch2)); */
    err = rt_atan2d_snf((-SensAdapt_DWork.R[1]) / cos((-err) +
      3.1415926535897931), SensAdapt_DWork.R[4] / cos((-err) +
      3.1415926535897931));
  } else {
    /* '<S19>:1:67' else */
    /* '<S19>:1:68' ph = 0; */
    scale = 0.0;

    /* '<S19>:1:69' th = 0; */
    err = 0.0;
  }

  /* % aflare quaternioni */
  /*  tr = R(1,1) + R(2,2) + R(3,3); */
  /*  m00 = R(1,1); */
  /*  m01 = R(1,2); */
  /*  m02 = R(1,3); */
  /*  m10 = R(2,1); */
  /*  m11 = R(2,2); */
  /*  m12 = R(2,3); */
  /*  m20 = R(3,1); */
  /*  m21 = R(3,2); */
  /*  m22 = R(3,3); */
  /*   */
  /*  if (tr > 0) */
  /*    S = sqrt(tr+1.0) * 2;  */
  /*    qw = 0.25 * S; */
  /*    qx = (m21 - m12) / S; */
  /*    qy = (m02 - m20) / S;  */
  /*    qz = (m10 - m01) / S;  */
  /*  elseif ((m00 > m11)&&(m00 > m22)) */
  /*    S = sqrt(1.0 + m00 - m11 - m22) * 2;  */
  /*    qw = (m21 - m12) / S; */
  /*    qx = 0.25 * S; */
  /*    qy = (m01 + m10) / S;  */
  /*    qz = (m02 + m20) / S;  */
  /*  elseif (m11 > m22) */
  /*    S = sqrt(1.0 + m11 - m00 - m22) * 2;  */
  /*    qw = (m02 - m20) / S; */
  /*    qx = (m01 + m10) / S;  */
  /*    qy = 0.25 * S; */
  /*    qz = (m12 + m21) / S;  */
  /*   else  */
  /*    S = sqrt(1.0 + m22 - m00 - m11) * 2;  */
  /*    qw = (m10 - m01) / S; */
  /*    qx = (m02 + m20) / S; */
  /*    qy = (m12 + m21) / S; */
  /*    qz = 0.25 * S; */
  /*  end */
  SensAdapt_B.Merge[0] = err;
  SensAdapt_B.Merge[1] = y;
  SensAdapt_B.Merge[2] = scale;
  SensAdapt_B.Merge[3] = 0.0;

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
    /* Start for DataStoreMemory: '<S16>/Data Store Memory' */
    memcpy(&SensAdapt_DWork.R[0], SensAdapt_ConstP.DataStoreMemory_InitialValue,
           9U * (sizeof(real_T)));

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
