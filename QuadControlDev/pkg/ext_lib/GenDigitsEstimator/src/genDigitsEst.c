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


/********************* Define macros end *****************************************/


float rotationMatrix[3][3] = {{0}};
float sampleTime = 0.01;
float k = 2;


void GeneralDigitsFuseIMUSensors(float accx, float accy, float accz, float gyrox, float gyroy, float gyroz)
{
	/*construct skew simetric matrix*/
	 float skewSimMat[3][3] =  {
		  	  	  	  	  	  	  	 	 {0, -gyroz, gyroy},
										 {gyroz, 0, -gyrox},
										 {-gyroy, gyrox, 0}
		       	   	   	   	   	   	 };
	float Eye3[3][3] = {
						 	 {1,0,0},
							 {0,1,0},
							 {0,0,1}
						 };
	float R_temp[3][3] = {{0}};

	uint16_t idxL,idxC,rows,columns,idx;


	/************************ Integration start **********************************/
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

	/************************ Integration end  **********************************/

	/************************ Orthogonalization start  **********************************/

	/************************ Orthogonalization start  **********************************/

	/************************ Sensor fusion start  **********************************/
	/*build acc vector*/
	float OZ_acc[3] = {accx,accy,accz};

	for (idx = 0; idx < 3 ;idx++)
	{
		OZ_acc[idx] /=  arrayNormAB(3,OZ_acc);
	}

	Vector OZ_acc_ = {OZ_acc[0],OZ_acc[1],OZ_acc[2]};
	Vector OZ_gyro_  = {R_temp[0][2],R_temp[1][2],R_temp[2][2]};
	Vector wf;

	wf = crossProduct(OZ_acc_,OZ_gyro_);
	float wfFinal[3] = {wf.i-k,wf.j-k,wf.k-k};

	float W[3];

	for (idx = 0; idx < 3; idx++)
	{
		W[idx]-= wfFinal[idx];
	}

	float wb_vp[3][3] = {
				  	  {0, -W[2], W[1]},
					  {W[2], 0, -W[0]},
					  {-W[1], W[0], 0}
				  };

	prodRectAB(3,3,rotationMatrix,3,3,Eye3,R_temp);

	for (idxL = 0; idxL < rows ;idxL++)
	{
		for (idxC = 0; idxC < columns;idxC++)
		{
			wb_vp[idxL][idxC]*= sampleTime;
		}
	}

	for (idxL = 0; idxL < rows ;idxL++)
	{
		for (idxC = 0; idxC < columns;idxC++)
		{
			rotationMatrix[idxL][idxC] = R_temp[idxL][idxC] + wb_vp[idxL][idxC];
		}
	}





	/************************ Sensor fusion end  **********************************/



}

/************************************ Aux Functions ************************************************************/

void prodRectAB(int m1, int m2, float mat1[][m2],
              int n1, int n2, float mat2[][n2], float res[m1][n2])
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

float dotProduct(Vector a, Vector b)
{
	return a.i*b.i+a.j*b.j+a.k*b.k;
}

Vector crossProduct(Vector a,Vector b)
{
	Vector c = {a.j*b.k - a.k*b.j, a.k*b.i - a.i*b.k, a.i*b.j - a.j*b.i};

	return c;
}

float scalarTripleProduct(Vector a,Vector b,Vector c)
{
	return dotProduct(a,crossProduct(b,c));
}

Vector vectorTripleProduct(Vector a,Vector b,Vector c)
{
	return crossProduct(a,crossProduct(b,c));
}

float arrayNormAB(int nr, float array[])
{
	int idx;
	float sum = 0;

	for (idx = 0; idx < nr;idx++)
	{
		sum+= pow(array[idx],2);
	}

	sum = sqrt(sum);

	return sum;
}
