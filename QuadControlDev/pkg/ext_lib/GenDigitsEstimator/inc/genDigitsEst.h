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
#include "stm32f4xx.h"

typedef struct{
	float i,j,k;
	}Vector;

void GeneralDigitsFuseIMUSensors(float accx, float accy, float accz, float gyrox, float gyroy, float gyroz);

void prodRectAB(int m1, int m2, float mat1[][m2],
              int n1, int n2, float mat2[][n2], float res[m1][n2]);

float dotProduct(Vector a, Vector b);

Vector crossProduct(Vector a,Vector b);

float scalarTripleProduct(Vector a,Vector b,Vector c);

Vector vectorTripleProduct(Vector a,Vector b,Vector c);

float arrayNormAB(int nr, float array[]);

#endif /* EXT_LIB_GENDIGITSESTIMATOR_INC_GENDIGITSEST_H_ */
