/*
 * imu.c
 *
 *  Created on: May 22, 2018
 *      Author: User
 */
#include "imu.h"
#include "iicb_interface.h"
#include "uart_interface.h"


/*create the delay function*/
void _delay_ms(int time)
{
	volatile int i,j;

	for(i=0;i<time;i++)
	{
		j++;
	}
}

#ifdef MPU_6050

void Init__vMPU_6050()
{
	unsigned char dest;
	// reset chip 1 - exit sleep mode
		_delay_ms(1000);
		I2C__vWriteSingleByteBuffer(mpu_6050_adress,mpu_6050_pwr_mgmnt_1,init_byte_107);
		_delay_ms(1000);
		I2C__vReadBuffer(mpu_6050_adress,mpu_6050_pwr_mgmnt_1,&dest,1);

		if (dest == init_byte_107)
		{
			printf("\r\n MPU chip 1 reseted successfully !\r\n");

		}
		else
		{
			printf("\r\n MPU chip 1 reset failed !\r\n");
		}
		_delay_ms(1000);
	// reset chip 2
		I2C__vWriteSingleByteBuffer(mpu_6050_adress, mpu_6050_sig_path_rst,init_byte_104);
		_delay_ms(1000);
		I2C__vReadBuffer(mpu_6050_adress,mpu_6050_sig_path_rst,&dest,1);
		if ((dest == 0x00))
		{
			// dupa ce se da reset valorile devin 0 din nou
			printf("\r\n MPU chip 2 reseted successfully !\r\n");

		}
		else
		{
			printf("\r\n MPU chip 2 reset failed !\r\n");
		}
		_delay_ms(1000);
	// sample divide rate  sample rate = ex 8kHz / (1+divide rate)  =  8000/110 = 72 Hz
		I2C__vWriteSingleByteBuffer(mpu_6050_adress, mpu_6050_smprt_div,80);
		_delay_ms(1000);
		I2C__vReadBuffer(mpu_6050_adress,mpu_6050_smprt_div,&dest,1);
		if ((dest == init_byte_104))
		{

			printf("\r\n MPU sample divide rate configured successfully !\r\n");
		}
		else
		{
			printf("\r\n MPU sample divide rate configuration failed !\r\n");
		}
		_delay_ms(1000);

	// digital low pass filter
		I2C__vWriteSingleByteBuffer(mpu_6050_adress, mpu_6050_config,0x00);
		_delay_ms(1000);
		I2C__vReadBuffer(mpu_6050_adress,mpu_6050_config,&dest,1);
		if (dest == 0x01)
		{
			printf("\r\n MPU digital low pass filter configured successfully !\r\n");

		}
		else
		{
			printf("\r\n MPU digital low pass filter configuration failed !\r\n");
		}
		_delay_ms(1000);
	// gyroscope config - gyro full scale = +/- 2000dps
		I2C__vWriteSingleByteBuffer(mpu_6050_adress, mpu_6050_gyro_config,0b00011000);
		_delay_ms(1000);
		I2C__vReadBuffer(mpu_6050_adress,mpu_6050_gyro_config,&dest,1);
		if (dest == 0b00001000)
		{
			printf("\r\n MPU gyroscope configured successfully !\r\n");

		}
		else
		{
			printf("\r\n MPU gyroscope configuration failed !\r\n");
		}
		_delay_ms(10);
	// accelerometer config - accelerometer full scale = +/- 4g
		I2C__vWriteSingleByteBuffer(mpu_6050_adress, mpu_6050_accel_config,0b00001000);
		_delay_ms(1000);
		I2C__vReadBuffer(mpu_6050_adress,mpu_6050_accel_config,&dest,1);
		if (dest == 0b00010000)
		{
			printf("\r\n MPU accelerometer configured successfully !\r\n");

		}
		else
		{
			printf("\r\n MPU accelerometer configuration failed !\r\n");
		}
		_delay_ms(1000);

	return ;
}

#else

void Init__vMPU_9255(uint8_t u8asax[3])
{
	/*used to validate the I2C writing by reading back the register value*/
	uint8_t u8destVal;
	uint8_t u8sensMagVal[3] = {0};


	/*tie the clock source to X axis of the gyro for a better accuracy*/
	I2C__vWriteSingleByteBuffer(MPU_9255_ADDRESS,MPU_9255_PWR_MGMNT_1,INIT_BYTE_107);
	I2C__vReadBuffer(MPU_9255_ADDRESS,MPU_9255_PWR_MGMNT_1,&u8destVal,1);

	if (u8destVal == INIT_BYTE_107)
	{
		printf("\r\nMPU clock source configuration...[ OK ]\r\n");
	}
	else
	{
		printf("\r\nMPU clock source configuration...[ NOK ]\r\n");
	}

	/*select accelerometer scale to 4g*/
	I2C__vWriteSingleByteBuffer(MPU_9255_ADDRESS,MPU_9255_ACCEL_CONFIG_1,INIT_BYTE_28);
	I2C__vReadBuffer(MPU_9255_ADDRESS,MPU_9255_ACCEL_CONFIG_1,&u8destVal,1);

	if (u8destVal == INIT_BYTE_28)
	{
		printf("\r\nMPU accelerometer scale configuration...[ OK ]\r\n");
	}
	else
	{
		printf("\r\nMPU accelerometer scale configuration...[ NOK ]\r\n");
	}

	/*select gyroscope scale to 500 dg/sec and FCHOI*/
	I2C__vWriteSingleByteBuffer(MPU_9255_ADDRESS,MPU_9255_GYRO_CONFIG,INIT_BYTE_27);
	I2C__vReadBuffer(MPU_9255_ADDRESS,MPU_9255_GYRO_CONFIG,&u8destVal,1);

	if (u8destVal == INIT_BYTE_27)
	{
		printf("\r\nMPU gyroscope scale configuration...[ OK ]\r\n");
	}
	else
	{
		printf("\r\nMPU gyroscope scale configuration...[ NOK ]\r\n");
	}

	/*turn on the low pass filter for the accelerometer 10Hz bandwidth */
	I2C__vWriteSingleByteBuffer(MPU_9255_ADDRESS,MPU_9255_ACCEL_CONFIG_2,INIT_BYTE_29);
	I2C__vReadBuffer(MPU_9255_ADDRESS,MPU_9255_ACCEL_CONFIG_2,&u8destVal,1);

	if (u8destVal == INIT_BYTE_29)
	{
		printf("\r\nMPU accelerometer filter configuration...[ OK ]\r\n");
	}
	else
	{
		printf("\r\nMPU accelerometer filter configuration...[ NOK ]\r\n");
	}

	/*turn on the low pass filter for the gyroscope 10Hz bandwidth */
	I2C__vWriteSingleByteBuffer(MPU_9255_ADDRESS,MPU_6050_CONFIG,INIT_BYTE_26);
	I2C__vReadBuffer(MPU_9255_ADDRESS,MPU_6050_CONFIG,&u8destVal,1);

	if (u8destVal == INIT_BYTE_26)
	{
		printf("\r\nMPU gyroscope filter configuration...[ OK ]\r\n");
	}
	else
	{
		printf("\r\nMPU gyroscope filter configuration...[ NOK ]\r\n");
	}


	/*disable I2C master interface.Precondition to enable bypass multiplexer of the I2C master interface*/
	I2C__vWriteSingleByteBuffer(MPU_9255_ADDRESS,MPU_9255_USER_CTRL,INIT_BYTE_106);
	I2C__vReadBuffer(MPU_9255_ADDRESS,MPU_9255_USER_CTRL,&u8destVal,1);

	if (u8destVal == INIT_BYTE_106)
	{
		printf("\r\nMPU I2C master disabled...[ OK ]\r\n");
	}
	else
	{
		printf("\r\nMPU I2C master disabled...[ NOK ]\r\n");
	}

	/*enable I2C master interface bypass multiplexer*/
	I2C__vWriteSingleByteBuffer(MPU_9255_ADDRESS,MPU_9255_INT_BYPASS_CONFIG,INIT_BYTE_55);
	I2C__vReadBuffer(MPU_9255_ADDRESS,MPU_9255_INT_BYPASS_CONFIG,&u8destVal,1);

	if (u8destVal == INIT_BYTE_55)
	{
		printf("\r\nMPU I2C bypass mux enabled...[ OK ]\r\n");
	}
	else
	{
		printf("\r\nMPU I2C bypass mux enabled...[ NOK ]\r\n");
	}

	/*setup the magnetometer:Fuse ROM access mode and 16 bit output*/
	I2C__vWriteSingleByteBuffer(MPU_9255_AK8963_DEVICE_ID,MPU_9255_MAG_CONTROL_CONFIG,INIT_BYTE_MAG_10);
	_delay_ms(1000);
	I2C__vReadBuffer(MPU_9255_AK8963_DEVICE_ID,MPU_9255_MAG_CONTROL_CONFIG,&u8destVal,1);

	if (u8destVal == INIT_BYTE_MAG_10)
	{
		printf("\r\nMPU magnetometer fuse mode...[ OK ]\r\n");
	}
	else
	{
		printf("\r\nMPU magnetometer fuse mode...[ NOK ]\r\n");
	}

	/*read the sensitivity adjustment values*/
	I2C__vReadBuffer(MPU_9255_AK8963_DEVICE_ID,MPU_9255_MAG_ASAX_CONFIG,u8sensMagVal,3);

	u8asax[0] = (u8sensMagVal[0]-128)*0.5/128+1;
	u8asax[1] = (u8sensMagVal[1]-128)*0.5/128+1;
	u8asax[2] = (u8sensMagVal[2]-128)*0.5/128+1;

	/*reset the magnetometer to power down mode*/
	I2C__vWriteSingleByteBuffer(MPU_9255_AK8963_DEVICE_ID,MPU_9255_MAG_CONTROL_CONFIG,RESET_BYTE_MAG_10);
	_delay_ms(1000);
	I2C__vReadBuffer(MPU_9255_AK8963_DEVICE_ID,MPU_9255_MAG_CONTROL_CONFIG,&u8destVal,1);

	if (u8destVal == RESET_BYTE_MAG_10)
	{
		printf("\r\nMPU magnetometer reset...[ OK ]\r\n");
	}
	else
	{
		printf("\r\nMPU magnetometer reset...[ NOK ]\r\n");
	}

	/*enable chip to continuous mode 2(100Hz) and 16-bit output*/
	I2C__vWriteSingleByteBuffer(MPU_9255_AK8963_DEVICE_ID,MPU_9255_MAG_CONTROL_CONFIG,RESET_BYTE_MAG_MODE2_10);
	_delay_ms(1000);
	I2C__vReadBuffer(MPU_9255_AK8963_DEVICE_ID,MPU_9255_MAG_CONTROL_CONFIG,&u8destVal,1);

	if (u8destVal == RESET_BYTE_MAG_MODE2_10)
	{
		printf("\r\nMPU magnetometer reset mode 2 and 16 bit output...[ OK ]\r\n");
	}
	else
	{
		printf("\r\nMPU magnetometer reset mode 2 and 16 bit output...[ NOK ]\r\n");
	}


	I2C__vReadBuffer(MPU_9255_ADDRESS,117,&u8destVal,1);

	if (u8destVal == 0x73)
	{
		printf("\r\nWho am I...[ OK ]\r\n");
	}
	else
	{
		printf("\r\nWho am I...[ NOK ]\r\n");
	}
}

#endif


IMU_tstImuData GetData__stMPU_9255()
{
	uint8_t u8ImuAccelGyroRawData[14] = {0};
	int16_t int16FinalImuRawData[10]={0};
	IMU_tstImuData IMUstRawData;
	uint8_t u8drdybit = 0;
	uint8_t u8magData[7] = {0}; //last byte is HOFL from status register 2


	I2C__vReadBuffer(MPU_9255_ADDRESS,MPU_9255_ACCEL_X_H,u8ImuAccelGyroRawData,14);

	int16FinalImuRawData[0] = (u8ImuAccelGyroRawData[0]<<8)|(u8ImuAccelGyroRawData[1]); //acc_x
	int16FinalImuRawData[1] = (u8ImuAccelGyroRawData[2]<<8)|(u8ImuAccelGyroRawData[3]); //acc_y
	int16FinalImuRawData[2] = (u8ImuAccelGyroRawData[4]<<8)|(u8ImuAccelGyroRawData[5]); //acc_z
	int16FinalImuRawData[3] = (u8ImuAccelGyroRawData[6]<<8)|(u8ImuAccelGyroRawData[7]); //temperature
	int16FinalImuRawData[4] = (u8ImuAccelGyroRawData[8]<<8)|(u8ImuAccelGyroRawData[9]); //gyro_x
	int16FinalImuRawData[5] = (u8ImuAccelGyroRawData[10]<<8)|(u8ImuAccelGyroRawData[11]); //gyro_y
	int16FinalImuRawData[6] = (u8ImuAccelGyroRawData[12]<<8)|(u8ImuAccelGyroRawData[13]); //gyro_z

	/*read DRDY bit from Status 1 register to check if the data in ready "1" ready "0" not ready  */
	I2C__vReadBuffer(MPU_9255_AK8963_DEVICE_ID,MPU_9255_MAG_STATUS_1_CONFIG,&u8drdybit,1);

	if ((u8drdybit & MPU_9255_DATA_READY_MASK ) == MPU_9255_DATA_READY)
	{
		I2C__vReadBuffer(MPU_9255_AK8963_DEVICE_ID,MPU_9255_MAG_HXL_AD,u8magData,7);

		/*check if magnetic sensor is overflow: If yes discard the reading*/

		if (!(u8magData[6] & MPU_9255_MAGIC_OVERFLOW_MASK))
		{
			int16FinalImuRawData[7] = (u8magData[0] | (u8magData[1]<<8));
			int16FinalImuRawData[8] = (u8magData[2] | (u8magData[3]<<8));
			int16FinalImuRawData[9] = (u8magData[4] | (u8magData[5]<<8));
		}
		else
		{
			/*data discarded*/
		}
	}

	/*copy array data into dedicated structure*/

	IMUstRawData.AccXData  = (float)int16FinalImuRawData[0];
	IMUstRawData.AccYData  = (float)int16FinalImuRawData[1];
	IMUstRawData.AccZData  = (float)int16FinalImuRawData[2];
	IMUstRawData.Temp      = (float)int16FinalImuRawData[3];
	IMUstRawData.GyroXData = (float)int16FinalImuRawData[4];
	IMUstRawData.GyroYData = (float)int16FinalImuRawData[5];
	IMUstRawData.GyroZData = (float)int16FinalImuRawData[6];
	IMUstRawData.MagXData  = (float)int16FinalImuRawData[7];
	IMUstRawData.MagYData  = (float)int16FinalImuRawData[8];
	IMUstRawData.MagZData  = (float)int16FinalImuRawData[9];

	return IMUstRawData;
}
