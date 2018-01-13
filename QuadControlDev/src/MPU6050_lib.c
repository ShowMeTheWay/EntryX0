/*
 * MPU6050_lib.c
 *
 *  Created on: Jun 15, 2015
 *      Author: Beny
 */

#include "mpu_6050.h"
#include "myLib.h"

void Init_MPU_6050()
{
	unsigned char dest;
	// reset chip 1
		_delay_ms(10);
		TWI_Write_Single_Byte(mpu_6050_adress, mpu_6050_pwr_mgmnt_1,init_byte_107);
		_delay_ms(100);
		TWI_Read_Single_Byte(mpu_6050_adress,mpu_6050_pwr_mgmnt_1,&dest);
		if (dest == init_byte_107)
		{
			USART_Transmit('\n');USART_Transmit(' ');USART_Transmit('1');USART_Transmit('0');USART_Transmit('7');
			USART_Transmit('-');USART_Transmit('o');USART_Transmit('k');

		}
		else
		{
			USART_Transmit('+');
			USART_Transmit(dest + 50);
			USART_Transmit('+');
		}
		_delay_ms(10);
	// reset chip 2
		TWI_Write_Single_Byte(mpu_6050_adress, mpu_6050_sig_path_rst,init_byte_104);
		_delay_ms(100);
		TWI_Read_Single_Byte(mpu_6050_adress,mpu_6050_sig_path_rst,&dest);
		if ((dest == 0x00))
		{
			// dupa ce se da reset valorile devin 0 din nou
			USART_Transmit('\n');USART_Transmit(' ');USART_Transmit('1');USART_Transmit('0');USART_Transmit('4');
			USART_Transmit('-');USART_Transmit('o');USART_Transmit('k');

		}
		else
		{
			USART_Transmit('\n');USART_Transmit(' ');USART_Transmit('1');USART_Transmit('0');USART_Transmit('4');
			USART_Transmit('+');USART_Transmit(dest + 50);USART_Transmit('+');
		}
		_delay_ms(10);
	// sample divide rate
		TWI_Write_Single_Byte(mpu_6050_adress, mpu_6050_smprt_div,0x07);
		_delay_ms(10);
		TWI_Read_Single_Byte(mpu_6050_adress,mpu_6050_smprt_div,&dest);
		if ((dest == init_byte_104))
		{
			USART_Transmit('\n');USART_Transmit(' ');USART_Transmit('2');USART_Transmit('5');USART_Transmit('-');
			USART_Transmit('o');USART_Transmit('k');

		}
		else
		{
			USART_Transmit('\n');USART_Transmit(' ');USART_Transmit('2');USART_Transmit('5');USART_Transmit('-');
			USART_Transmit('+');USART_Transmit(dest + 50);USART_Transmit('+');
		}
		_delay_ms(10);

	// digital low pass filter
		TWI_Write_Single_Byte(mpu_6050_adress, mpu_6050_config,0x01);
		_delay_ms(10);
		TWI_Read_Single_Byte(mpu_6050_adress,mpu_6050_config,&dest);
		if (dest == 0x01)
		{
			USART_Transmit('\n');USART_Transmit(' ');USART_Transmit('2');USART_Transmit('6');USART_Transmit('-');
			USART_Transmit('o');USART_Transmit('k');

		}
		else
		{
			USART_Transmit('\n');USART_Transmit(' ');USART_Transmit('2');USART_Transmit('6');USART_Transmit('-');
			USART_Transmit('+');USART_Transmit(dest + 50);USART_Transmit('+');
		}
		_delay_ms(10);
	// gyroscope config
		TWI_Write_Single_Byte(mpu_6050_adress, mpu_6050_gyro_config,0b00001000);
		_delay_ms(10);
		TWI_Read_Single_Byte(mpu_6050_adress,mpu_6050_gyro_config,&dest);
		if (dest == 0b00001000)
		{
			USART_Transmit('\n');USART_Transmit(' ');USART_Transmit('2');USART_Transmit('7');USART_Transmit('-');
			USART_Transmit('o');USART_Transmit('k');

		}
		else
		{
			USART_Transmit('\n');USART_Transmit(' ');USART_Transmit('2');USART_Transmit('7');USART_Transmit('-');
			USART_Transmit('+');USART_Transmit(dest + 50);USART_Transmit('+');
		}
		_delay_ms(10);
	// accelerometer config
		TWI_Write_Single_Byte(mpu_6050_adress, mpu_6050_accel_config,0b00010000);
		_delay_ms(10);
		TWI_Read_Single_Byte(mpu_6050_adress,mpu_6050_accel_config,&dest);
		if (dest == 0b00010000)
		{
			USART_Transmit('\n');USART_Transmit(' ');USART_Transmit('2');USART_Transmit('8');USART_Transmit('-');
			USART_Transmit('o');USART_Transmit('k');

		}
		else
		{
			USART_Transmit('\n');USART_Transmit(' ');USART_Transmit('2');USART_Transmit('8');USART_Transmit('-');
			USART_Transmit('+');USART_Transmit(dest + 50);USART_Transmit('+');
		}
		_delay_ms(10);

	return ;
}
