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
 * Description  : Input: liniar acceleration on X,Y,Z axis in [m/s^2]
 *				         angular rotation on X,Y,Z axis in [rad/s]
 *
 *				  Output: tilt angles X,Y,Z in [rad]
 *				  		  quaternions in [qw,qx,qy,qz] form
 *****************************************************************************/

#include "genDigitsEst.h"


/********************* Define macros start *****************************************/

#define pi (3.1415)
#define MvgAvgSamples (1) /*min value must be 1 to avoid division by 0*/

/********************* Define macros end *****************************************/

/********************* Global variables start  *****************************************/

float rotationMatrix[3][3] = {
								 {1,0,0},
								 {0,1,0},
								 {0,0,1}
							 };
volatile float qw = 0.0f, qx = 0.0, qy = 0.0, qz = 0.0, chi = 0.0f, ch2 = 0.0f, phi = 0.0f, the = 0.0f;
float sampleTime = 0.01f;
float k = 10;

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
	float R_test[3][3] = {{0}};

	unsigned int idxL,idxC,idx,rows,columns;

	/*build acc vector*/
	float OZ_acc[3] = {ax,ay,az};
	float OZ_gyro[3] = {0};

	float W[3];
	float gyroData[3] = {gx,gy,gz};

	float wb_vp[3][3] = {0};
	float crossPwf[3] = {0};
	float norm = 0;
	float S,tr;

	/************************ A Priori Integration START **********************************/
	rows = sizeof(skewSimMat)/sizeof(skewSimMat[0]);
	columns = (sizeof(skewSimMat)/sizeof(skewSimMat[0][0]))/rows;

	for (idxL = 0; idxL < rows ;idxL++)
	{
		for (idxC = 0; idxC < columns;idxC++)
		{
			R_test[idxL][idxC] = Eye3[idxL][idxC] + (float)sampleTime*skewSimMat[idxL][idxC];
		}
	}

	multiplyMatAB(3,3,rotationMatrix,3,3,R_test,R_temp);
	/************************ A Priori Integration END  **********************************/

	/************************ 1'st Orthogonalization START  **********************************/

	performOrtho(R_temp);

	/************************ 1'st Orthogonalization END  **********************************/

	/************************ Data correction START  **********************************/

	norm = arrayNormAB(3,OZ_acc);
	for (idx = 0; idx < 3 ;idx++)
	{
		OZ_acc[idx] /= norm;
	}

	 OZ_gyro[0] = R_temp[2][0];
	 OZ_gyro[1] = R_temp[2][1];
	 OZ_gyro[2] = R_temp[2][2];

	crossProduct(OZ_gyro,OZ_acc,crossPwf);

	for (idx = 0; idx < 3; idx++)
	{
		W[idx] = gyroData[idx] - crossPwf[idx]*k;
	}

	/************************ Data correction END  **********************************/

	/************************ A Posteriori Integration START **********************************/

	wb_vp[0][0] =  0;    wb_vp[0][1] = -W[2]; wb_vp[0][2] =  W[1];
	wb_vp[1][0] =  W[2]; wb_vp[1][1] =  0;    wb_vp[1][2] = -W[0];
	wb_vp[2][0] = -W[1]; wb_vp[2][1] =  W[0]; wb_vp[2][2] =  0;


	for (idxL = 0; idxL < rows; idxL++)
	{
		for (idxC = 0; idxC < columns;idxC++)
		{
			wb_vp[idxL][idxC] = Eye3[idxL][idxC] + (float)sampleTime * wb_vp[idxL][idxC];
		}
	}

	multiplyMatAB(3,3,rotationMatrix,3,3,wb_vp,R_temp);

	/************************ 2'st Orthogonalization START  **********************************/
	performOrtho(R_temp);

	/************************ 2'st Orthogonalization END  **********************************/

	for (idxL = 0; idxL < rows; idxL++)
	{
		for (idxC = 0; idxC < columns;idxC++)
		{
			rotationMatrix[idxL][idxC] = R_temp[idxL][idxC];
		}
	}

	/************************ A Posteriori Integration END **********************************/

	/************************ Find angles START  **********************************/

	chi = asinf(rotationMatrix[2][1]);
	ch2 = -asinf(rotationMatrix[2][1])+pi;

	if ((fabs(cosf(chi)) > 0.01) && (fabs(cosf(ch2)) > 0.01))
	{
		phi = atan2f(-rotationMatrix[2][0]/cosf(chi),rotationMatrix[2][2]/cosf(chi));
		the = atan2f(-rotationMatrix[1][0]/cosf(ch2),rotationMatrix[1][1]/cosf(ch2));
	}else
	{
		phi = 0;
		the = 0;
	}

	/************************ Find angles END  **********************************/

	/************************ Find quaternions START  **********************************/
	tr = rotationMatrix[0][0] + rotationMatrix[1][1] + rotationMatrix[2][2];

	if (tr > 0)
	{
		S = sqrt(tr+1.0) * 2;
		qw = 0.25 * S;
		qx = (rotationMatrix[2][1] - rotationMatrix[1][2]) / S;
		qy = (rotationMatrix[0][2] - rotationMatrix[2][0]) / S;
		qz = (rotationMatrix[1][0] - rotationMatrix[0][1]) / S;
	}else if((rotationMatrix[0][0] > rotationMatrix[1][1])&&(rotationMatrix[0][0] > rotationMatrix[2][2]))
	{
		S = sqrt(1.0 + rotationMatrix[0][0] - rotationMatrix[1][1] - rotationMatrix[1][2]) * 2;
		qw = (rotationMatrix[2][1] - rotationMatrix[1][2]) / S;
		qx = 0.25 * S;
		qy = (rotationMatrix[0][1] + rotationMatrix[1][0]) / S;
		qz = (rotationMatrix[0][2] + rotationMatrix[2][0]) / S;
	} else if (rotationMatrix[1][1] > rotationMatrix[2][2])
	{
		  S = sqrt(1.0 + rotationMatrix[1][1] - rotationMatrix[0][0] - rotationMatrix[2][2]) * 2;
		  qw = (rotationMatrix[0][2] - rotationMatrix[2][0]) / S;
		  qx = (rotationMatrix[0][1] + rotationMatrix[1][0]) / S;
		  qy = 0.25 * S;
		  qz = (rotationMatrix[1][2] + rotationMatrix[2][1]) / S;
	}else
	{
		S = sqrt(1.0 + rotationMatrix[2][2] - rotationMatrix[0][0]- rotationMatrix[1][1]) * 2;
		qw = (rotationMatrix[1][0] - rotationMatrix[0][1]) / S;
		qx = (rotationMatrix[0][2] + rotationMatrix[2][0]) / S;
		qy = (rotationMatrix[1][2] + rotationMatrix[2][1]) / S;
		qz = 0.25 * S;
	}

	/************************ Find quaternions END  **********************************/

	applyFTJ(0.002);

}

/************************************ Aux Functions ************************************************************/


void multiplyMatAB(int m1, int m2, float mat1[3][3],
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

void crossProduct(float a[] ,float b[], float c[])
{
	c[0] = a[1]*b[2]-b[1]*a[2];
	c[1] = -(a[0]*b[2]-b[0]*a[2]);
	c[2] = a[0]*b[1]-b[0]*a[1];

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

void performOrtho(float R[3][3])
{
	unsigned short int idx = 0;
	float err = 0,r1_aux = 0,r2_aux = 0, r3_aux = 0;
	float r1[3] = {0}, r2[3] = {0}, r3[3] = {0};
	float Xn[3] = {0}, Yn[3] = {0}, Zn[3] = {0};
	float x[3] = {0}, y[3] = {0};

	for (idx = 0; idx < 3; idx++)
	{
		x[idx] = R[idx][0];
		y[idx] = R[idx][1];
	}

	for (idx = 0; idx < 3; idx++)
	{
		err = err + x[idx]*y[idx];
	}

	for (idx = 0; idx < 3; idx++)
	{
		r1[idx] = x[idx] - err/2*y[idx];
		r2[idx] = y[idx] - err/2*x[idx];
	}

	crossProduct(r1,r2,r3);

	for (idx = 0; idx < 3; idx++)
	{
		r1_aux += r1[idx]*r1[idx];
		r2_aux += r2[idx]*r2[idx];
		r3_aux += r3[idx]*r3[idx];
	}

	for (idx = 0; idx < 3; idx++)
	{
		Xn[idx] = 0.5*(3-r1_aux)*r1[idx];
		Yn[idx] = 0.5*(3-r2_aux)*r2[idx];
		Zn[idx] = 0.5*(3-r3_aux)*r3[idx];
	}

	for(idx = 0; idx < 3; idx++)
	{
		R[idx][0] = Xn[idx];
		R[idx][1] = Yn[idx];
		R[idx][2] = Zn[idx];

	}


}

IMU_tstInRawData smoothDataMvgAvg(IMU_tstInRawData rawDataIn)
{
	unsigned int idx = 0;
	static float accx[MvgAvgSamples] = {0};
	static float accy[MvgAvgSamples] = {0};
	static float accz[MvgAvgSamples] = {0};
	static float gyrox[MvgAvgSamples] = {0};
	static float gyroy[MvgAvgSamples] = {0};
	static float gyroz[MvgAvgSamples] = {0};
	float sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0, sum6 = 0;
	IMU_tstInRawData rawData = rawDataIn;


	for (idx = 0; idx < MvgAvgSamples -1; idx++)
	{
		accx[idx] = accx[idx + 1];
		accy[idx] = accy[idx + 1];
		accz[idx] = accz[idx + 1];
		gyrox[idx] = gyrox[idx + 1];
		gyroy[idx] = gyroy[idx + 1];
		gyroz[idx] = gyroz[idx + 1];
	}

	accx[MvgAvgSamples-1] = rawData.AccXData;
	accy[MvgAvgSamples-1] = rawData.AccYData;
	accz[MvgAvgSamples-1] = rawData.AccZData;
	gyrox[MvgAvgSamples-1] = rawData.GyroXData;
	gyroy[MvgAvgSamples-1] = rawData.GyroYData;
	gyroz[MvgAvgSamples-1] = rawData.GyroZData;


	for (idx = 0; idx < MvgAvgSamples; idx++)
	{
		sum1 = sum1 + accx[idx];
		sum2 = sum2 + accy[idx];
		sum3 = sum3 + accz[idx];
		sum4 = sum4 + gyrox[idx];
		sum5 = sum5 + gyroy[idx];
		sum6 = sum6 + gyroz[idx];
	}


	rawData.AccXData = sum1/MvgAvgSamples;
	rawData.AccYData = sum2/MvgAvgSamples;
	rawData.AccZData = sum3/MvgAvgSamples;
	rawData.GyroXData = sum4/MvgAvgSamples;
	rawData.GyroYData = sum5/MvgAvgSamples;
	rawData.GyroZData = sum6/MvgAvgSamples;

	return rawData;

}

void applyFTJ(float alpha)
{
	static float qw_prev = 0, qx_prev = 0, qy_prev = 0, qz_prev = 0, the_prev = 0, chi_prev = 0, phi_prev = 0;

	qw = ( qw * alpha ) + ( qw_prev * (1-alpha));
	qx = ( qx * alpha ) + ( qx_prev * (1-alpha));
	qy = ( qy * alpha ) + ( qy_prev * (1-alpha));
	qz = ( qz * alpha ) + ( qz_prev * (1-alpha));
	the = ( the * alpha ) + ( the_prev * (1-alpha));
	chi = ( chi * alpha ) + ( chi_prev * (1-alpha));
	phi = ( phi * alpha ) + ( phi_prev * (1-alpha));

	qw_prev = qw;
	qx_prev = qx;
	qy_prev = qy;
	qz_prev = qz;
	the_prev = the;
	chi_prev = chi;
	phi_prev = phi;
}
