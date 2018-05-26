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
	SensAdapt_initialize();


	while (1)
	{
		SensAdapt_step();
		_delay_ms(1000);
	}


	return 0;


}

/***************************************************** MAIN END *******************************************************************/








