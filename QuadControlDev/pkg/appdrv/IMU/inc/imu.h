/*
 * imu.h
 *
 *  Created on: May 22, 2018
 *      Author: User
 */

#ifndef APPDRV_IMU_INC_IMU_H_
#define APPDRV_IMU_INC_IMU_H_

#include "mpu_6050.h"
#include "SensAdapt_types.h"
#include "main.h"


typedef struct ImuData {
	float AccXData;
	float AccYData;
	float AccZData;
	float Temp;
	float GyroXData;
	float GyroYData;
	float GyroZData;
	float MagXData;
	float MagYData;
	float MagZData;
}IMU_tstImuData;

void Init__vMPU_9255(uint8_t u8asax[3]);

IMU_tstImuData GetData__stMPU_9255();

void _delay_ms(int time);


#endif /* APPDRV_IMU_INC_IMU_H_ */
