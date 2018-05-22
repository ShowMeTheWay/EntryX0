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

void Init__vMPU_6050()
{
	unsigned char dest;
	// reset chip 1
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
	// sample divide rate
		I2C__vWriteSingleByteBuffer(mpu_6050_adress, mpu_6050_smprt_div,0x07);
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
		I2C__vWriteSingleByteBuffer(mpu_6050_adress, mpu_6050_config,0x01);
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
	// gyroscope config
		I2C__vWriteSingleByteBuffer(mpu_6050_adress, mpu_6050_gyro_config,0b00001000);
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
	// accelerometer config
		I2C__vWriteSingleByteBuffer(mpu_6050_adress, mpu_6050_accel_config,0b00010000);
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
