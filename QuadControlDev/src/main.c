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
#include "mpu_6050.h"
#include "iicb_interface.h"
#include "Com_ReadWrite.h"
#include "uart_interface.h"
#include "pwm_interface.h"
#include "clk_interface.h"
#include "ers.h"

/******************************** Buffer for all Communication variables **********************************************/
ComLayer_tstComData ComLayer_stComData;



/***************************************************** MAIN START *******************************************************************/



/*create the delay function*/
void delay(int time)
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

	/* Initialize number of data variables */
		static uint8_t registerContent;
		uint8_t regV;

		/*Step 1 - Transmit the adress and the register adress that shall be read*/
		/* Update bTransferRequest to send buffer write request for Slave */

		I2C__vReadBuffer(0x68,117,(uint8_t*)&registerContent,1);

		Com_Write_ComLayer_IMUData(registerContent);

		Com_Read_ComLayer_IMUData(&regV);

		printf("\r\n Ba mere %d \r\n",regV);

	while (1)
	{
		SensAdapt_step();
		delay(1000);
	}


	return 0;


}

/***************************************************** MAIN END *******************************************************************/








