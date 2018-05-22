/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/



/* Includes ------------------------------------------------------------------*/
#include <SensAdapt.h>
#include "main.h"
#include "stm32f4xx.h"
#include "stm32f4xx_nucleo_144.h"
#include "iicb_interface.h"
#include "Com_ReadWrite.h"
#include "uart_interface.h"
#include "pwm_interface.h"
#include "clk_interface.h"
#include "dio_interface.h"
#include "ers.h"
#include "imu.h"

/******************************** Buffer for all Communication variables **********************************************/
ComLayer_tstComData ComLayer_stComData;



/***************************************************** MAIN START *******************************************************************/



/*create the delay function*/
void _delay_ms(int time)
{
	volatile int i,j;

	for(i=0;i<time;i++)
	{
		j++;
	}
}


int main(void)
{
	HAL_Init();

	/*Configure the system clock to 180 Mhz*/
	SystemClock_Config();

	ControlClock();
	ConfigureLED();
	ConfigureButton();
	PWMConfig();
	Config_I2C_Peripheral();
	Config_USART_Peripheral();
	Init__vMPU_6050();

	static uint8_t dest[14];
	static uint16_t destf[6];
	uint8_t idx = 0;
	while (1)
	{
		//SensAdapt_step();
		//I2C__vReadBuffer(mpu_6050_adress,mpu_6050_accel_x_h,dest,14);
		I2C__vReadBuffer(mpu_6050_adress,mpu_6050_accel_x_h,dest,14);

		destf[0] = (dest[0]<<8)|(dest[1]); //acc_x
		destf[1] = (dest[2]<<8)|(dest[3]); //acc_y
		destf[2] = (dest[4]<<8)|(dest[5]); //acc_z
		destf[3] = (dest[8]<<8)|(dest[9]); //gyro_x
		destf[4] = (dest[10]<<8)|(dest[11]); //gyro_y
		destf[5] = (dest[12]<<8)|(dest[13]); //gyro_z

		printf("\r\n %d,%d,%d,%d,%d,%d \r\n",destf[0],destf[1],destf[2],destf[3],destf[4],destf[5]);
		_delay_ms(1000);
	}


	return 0;


}

/***************************************************** MAIN END *******************************************************************/








