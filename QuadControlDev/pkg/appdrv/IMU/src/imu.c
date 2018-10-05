/*
 * imu.c
 *
 *  Created on: May 22, 2018
 *      Author: User
 */
#include "imu.h"
#include "iicb_interface.h"
#include "uart_interface.h"
#include "main.h"


/*create the delay function*/
void _delay_ms(int time)
{
	volatile int i,j;

	for(i=0;i<time;i++)
	{
		j++;
	}
}

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

IMU_tstInRawData GetData__stMPU_6050()
{
	uint8_t u8ImuRawData[14] = {0};
	int16_t int16FinalImuRawData[6]={0};
	IMU_tstInRawData IMUstRawData;


	I2C__vReadBuffer(mpu_6050_adress,mpu_6050_accel_x_h,u8ImuRawData,14);

	int16FinalImuRawData[0] = (u8ImuRawData[0]<<8)|(u8ImuRawData[1]); //acc_x
	int16FinalImuRawData[1] = (u8ImuRawData[2]<<8)|(u8ImuRawData[3]); //acc_y
	int16FinalImuRawData[2] = (u8ImuRawData[4]<<8)|(u8ImuRawData[5]); //acc_z
	int16FinalImuRawData[3] = (u8ImuRawData[8]<<8)|(u8ImuRawData[9]); //gyro_x
	int16FinalImuRawData[4] = (u8ImuRawData[10]<<8)|(u8ImuRawData[11]); //gyro_y
	int16FinalImuRawData[5] = (u8ImuRawData[12]<<8)|(u8ImuRawData[13]); //gyro_z

	/*copy array data into dedicated structure*/

	IMUstRawData.AccXData = (float)int16FinalImuRawData[0];
	IMUstRawData.AccYData = (float)int16FinalImuRawData[1];
	IMUstRawData.AccZData = (float)int16FinalImuRawData[2];
	IMUstRawData.GyroXData = (float)int16FinalImuRawData[3];
	IMUstRawData.GyroYData = (float)int16FinalImuRawData[4];
	IMUstRawData.GyroZData = (float)int16FinalImuRawData[5];



	return IMUstRawData;
}
