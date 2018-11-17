 /***************************************************************************
 *=====================      Copyright by General Digits      ===============
 ****************************************************************************
 * Title        : genDigitsEst.h
 *
 * Date:        : 08.09.2018
 *
 * Version      : Revision: 1.1
 *
 * Responsible  : Beniamin Costandin
 *
 * Departement  : Software Engineering
 *
 * Description  : This function will gets as input the IMU data and outputs the Euler angles
 *
 *
 *****************************************************************************/

#ifndef EXT_LIB_GENDIGITSESTIMATOR_INC_GENDIGITSEST_H_
#define EXT_LIB_GENDIGITSESTIMATOR_INC_GENDIGITSEST_H_

#include <math.h>
#include <SensAdapt.h>

extern volatile float qw,qx,qx,qz,the,chi,phi;

void GeneralDigitsFuseIMUSensors(float accx, float accy, float accz, float gyrox, float gyroy, float gyroz);

void multiplyMatAB(int m1, int m2, float mat1[3][3],
              int n1, int n2, float mat2[3][3], float res[3][3]);

void crossProduct(float a[] ,float b[], float c[]);

float arrayNormAB(int nr, float array[]);

void performOrtho(float R[3][3]);

IMU_tstInRawData smoothDataMvgAvg(IMU_tstInRawData rawDataIn);

void applyFTJ(float alpha);

#endif /* EXT_LIB_GENDIGITSESTIMATOR_INC_GENDIGITSEST_H_ */
