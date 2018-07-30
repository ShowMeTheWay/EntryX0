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


void Init__vMPU_6050();

IMU_tstInRawData GetData__stMPU_6050();

void _delay_ms(int time);


#endif /* APPDRV_IMU_INC_IMU_H_ */
