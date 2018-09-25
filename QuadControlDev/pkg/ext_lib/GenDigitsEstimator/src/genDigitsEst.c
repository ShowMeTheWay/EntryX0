 /***************************************************************************
 *=====================      Copyright by General Digits      ===============
 ****************************************************************************
 * Title        : genDigitsEst.c
 *
 * Date:        : 08.09.2018
 *
 * Version      : Revision: 1.1
 *
 * Responsible  : Beniamin Costandin
 *
 * Department   : Software Engineering and Control
 *
 * Description  : This function will gets as input the IMU data and outputs the Euler angles
 *
 *
 *****************************************************************************/

#include "genDigitsEst.h"

/********************* Define macros start *****************************************/

#define pi 3.1415

/********************* Define macros end *****************************************/
/********************* Global variables start  *****************************************/

float rotationMatrix[3][3] = {{0}};
volatile float chi = 0.0f, ch2 = 0.0f, phi = 0.0f, the = 0.0f;
float sampleTime = 0.01;
float k = 2;

/********************* Global variables end  *****************************************/


void GeneralDigitsFuseIMUSensors(float ax, float ay, float az, float gx, float gy, float gz)
{
	/*construct skew simetric matrix*/
	float skewSimMat[3][3] =  {
		  	  	  	  	  	  	  	 	 {0, -gz, gy},
										 {gz, 0, -gx},
										 {-gy, gx, 0}
		       	   	   	   	   	   	 };
	float Eye3[3][3] = {
						 	 {1,0,0},
							 {0,1,0},
							 {0,0,1}
						 };
	float R_temp[3][3] = {{0}};

	unsigned int idxL,idxC,idx,rows,columns;

	/*build acc vector*/
	float OZ_acc[3] = {ax,ay,az};
	float OZ_gyro[3] = {0};

	float W[3];
	float gyroData[3] = {gx,gy,gz};

	float wb_vp[3][3]= {0};
	float *crossPwf = NULL;
	float X[3] = {0}, Y[3]={0};

	/************************ Integration START **********************************/
	prodRectAB(3,3,rotationMatrix,3,3,Eye3,R_temp);

	rows = sizeof(skewSimMat)/sizeof(skewSimMat[0]);
	columns = (sizeof(skewSimMat)/sizeof(skewSimMat[0][0]))/rows;


	for (idxL = 0; idxL < rows ;idxL++)
	{
		for (idxC = 0; idxC < columns;idxC++)
		{
			skewSimMat[idxL][idxC]*= sampleTime;
		}
	}

	for (idxL = 0; idxL < rows ;idxL++)
	{
		for (idxC = 0; idxC < columns;idxC++)
		{
			R_temp[idxL][idxC] = R_temp[idxL][idxC] + skewSimMat[idxL][idxC];
		}
	}

	/************************ Integration END  **********************************/

	/************************ Orthogonalization START  **********************************/
	for (idxC = 0; idxC < columns ; idxC++)
	{
		for (idxL = 0; idxL < rows;idxL++)
		{
			if(idxC == 0)
			{
				X[idxL] = R_temp[idxL][idxC];
			}else if(idxC == 1)
			{
				Y[idxL] = R_temp[idxL][idxC];
			}else
			{
				continue;
			}

		}
	}

	performOrtho(X,Y,R_temp);

	/************************ Orthogonalization END  **********************************/

	/************************ Sensor fusion START  **********************************/


	for (idx = 0; idx < 3 ;idx++)
	{
		OZ_acc[idx] /=  arrayNormAB(3,OZ_acc);
	}

	 OZ_gyro[0] = R_temp[0][2];
	 OZ_gyro[1] = R_temp[1][2];
	 OZ_gyro[2] = R_temp[2][2];

	 crossPwf = crossProduct(OZ_acc,OZ_gyro);

	for (idx = 0; idx < 3; idx++)
	{
		W[idx] = gyroData[idx] - crossPwf[idx]*k;
	}

	wb_vp[0][0] =  0;
	wb_vp[0][1] = -W[2];
	wb_vp[0][2] =  W[1];

	wb_vp[1][0] =  W[2];
	wb_vp[1][1] =  0;
	wb_vp[1][2] = -W[0];

	wb_vp[2][0] = -W[1];
	wb_vp[2][1] =  W[0];
	wb_vp[2][2] =  0;


	for (idxL = 0; idxL < rows ;idxL++)
	{
		for (idxC = 0; idxC < columns;idxC++)
		{
			wb_vp[idxL][idxC] = R_temp[idxL][idxC] + sampleTime * wb_vp[idxL][idxC];
		}
	}

	prodRectAB(3,3,rotationMatrix,3,3,Eye3,R_temp);

	for (idxL = 0; idxL < rows ;idxL++)
	{
		for (idxC = 0; idxC < columns;idxC++)
		{
			rotationMatrix[idxL][idxC] = R_temp[idxL][idxC] + sampleTime * wb_vp[idxL][idxC];
		}
	}

	/************************ Sensor fusion END  **********************************/

	/************************ Find angles START  **********************************/

	chi = asinf(rotationMatrix[2][1]);
	ch2 = -asinf(rotationMatrix[2][1])+pi;

	if (fabs(chi) > 0.01)
	{
		phi = atan2f(-rotationMatrix[2][0]/cos(chi),rotationMatrix[2][2]/cosf(chi));
		the = atan2f(-rotationMatrix[1][0]/cos(ch2),rotationMatrix[1][1]/cosf(ch2));
	}else
	{
		phi = 0;
		the = 0;
	}

	/************************ Find angles END  **********************************/




}

/************************************ Aux Functions ************************************************************/


void prodRectAB(int m1, int m2, float mat1[3][3],
              int n1, int n2, float mat2[3][3], float res[3][3])
{
    int x, i, j;
    for (i = 0; i < m1; i++) {
        for (j = 0; j < n2; j++) {
            res[i][j] = 0;
            for (x = 0; x < m2; x++) {
                *(*(res + i) + j) += *(*(mat1 + i) + x) *
                                     *(*(mat2 + x) + j);
            }
        }
    }

}

float * crossProduct(float a[] ,float b[])
{
	static float c[3] = {0};

	c[0] = a[1]*b[2]-b[1]*a[2];
	c[1] = -(a[0]*b[2]-b[0]*a[2]);
	c[2] = a[0]*b[1]-b[0]*a[1];

	return c;
}

float arrayNormAB(int nr, float array[])
{
	int idx;
	float sum = 0;

	for (idx = 0; idx < nr;idx++)
	{
		sum+= powf(array[idx],2);
	}

	sum = sqrtf(sum);

	return sum;
}

void performOrtho(float x[], float y[], float R[3][3])
{
	unsigned short int idx = 0,lns = 0,cols = 0;
	float err = 0,r1_aux = 0,r2_aux = 0, r3_aux = 0;
	float r1[3] = {0},r2[3] = {0};
	float Xn[3] = {0}, Yn[3] = {0}, Zn[3] = {0};
	float *r3 = NULL;

	for (idx = 0; idx < 3; idx++)
	{
		err = err + x[idx]*y[idx];
	}

	for (idx = 0; idx < 3; idx++)
	{
		r1[idx] = x[idx] - err/2*y[idx];
		r1[idx] = y[idx] - err/2*x[idx];
	}

	r3 = crossProduct(r1,r2);

	for (idx = 0; idx < 3; idx++)
	{
		r1_aux += r1[idx]*r1[idx];
		r2_aux += r2[idx]*r2[idx];
		r3_aux += r3[idx]*r3[idx];
	}

	for (idx = 0; idx < 3; idx++)
	{
		Xn[idx] = 1/2*(3-r1_aux)*r1[idx];
		Yn[idx] = 1/2*(3-r2_aux)*r2[idx];
		Zn[idx] = 1/2*(3-r3_aux)*r3[idx];
	}

	for(cols = 0; cols < 3; cols++)
	{
		for (lns = 0; lns < 3; lns++)
		{
			if(cols == 0)
			{
				R[lns][cols] = Xn[lns];
			}else if(cols == 1)
			{
				R[lns][cols] = Yn[lns];
			}else
			{
				R[lns][cols] = Zn[lns];
			}
		}
	}


}

