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
#include "task.h"

#define nInitTotal 12

/******************************** Buffer for all Communication variables **********************************************/
ComLayer_tstComData ComLayer_stComData;
void (* const Init_vContainerTable[nInitTotal])(void) = {
		HAL_Init,
		SystemClock_Config,
		ControlClock,
		ConfigureLED,
		ConfigureButton,
		PWMConfig,
		PWMConfig,
		Config_I2C_Peripheral,
		Config_USART_Peripheral,
		Init__vMPU_6050,
		SensAdapt_initialize,
		Config_vTask1
};

/***************************************************** MAIN START *******************************************************************/


int main(void)
{
	uint8_t u8i = 0;
	for (u8i = 0; u8i < nInitTotal; u8i++)
	{
		Init_vContainerTable[u8i]();
	}
	while (1){}

	return 0;


}
/******************************************** 10ms Task ******************************************88*/
void TIM6_DAC_IRQHandler(void)
{

	volatile static uint8_t a = 0;
	/*clear UIF flag*/
	TIM6->SR &= ~TIM_SR_UIF;
	a = a^1;
	SetResetLed(LED_BLUE,a);

	SensAdapt_step();
}



/***************************************************** MAIN END *******************************************************************/








