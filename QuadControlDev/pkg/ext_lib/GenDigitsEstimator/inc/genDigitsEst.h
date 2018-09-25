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

extern volatile float the,chi,phi;

typedef struct{
	float i,j,k;
	}Vector;

void GeneralDigitsFuseIMUSensors(float accx, float accy, float accz, float gyrox, float gyroy, float gyroz);

void prodRectAB(int m1, int m2, float mat1[3][3],
              int n1, int n2, float mat2[3][3], float res[3][3]);

float * crossProduct(float a[] ,float b[]);

float arrayNormAB(int nr, float array[]);

void performOrtho(float x[], float y[], float R[3][3]);

#endif /* EXT_LIB_GENDIGITSESTIMATOR_INC_GENDIGITSEST_H_ */
