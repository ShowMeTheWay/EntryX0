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

/* Buffer used for reception */
uint8_t aRxBuffer;
UART_HandleTypeDef UartHandle;


#define nInitTotal 11

/******************************** Buffer for all Communication variables **********************************************/
ComLayer_tstComData ComLayer_stComData;
void (* const Init_vContainerTable[nInitTotal])(void) = {
		HAL_Init,
		SystemClock_Config,
		ControlClock,
		ConfigureLED,
		ConfigureButton,
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
	volatile static uint8_t cnt = 0;
	volatile static uint8_t buffer = 0;
	static uint16_t pwm = 0;

	/*clear UIF flag*/
	TIM6->SR &= ~TIM_SR_UIF;
	a = a^1;
	SetResetLed(LED_BLUE,a);

	//SensAdapt_step();

	HAL_UART_Receive(&UartHandle, (uint8_t*)&aRxBuffer, 1, 0xFFFF);

	if(aRxBuffer == 49)
	{
		pwm = 1000;
		SetPWM(5000,pwm,5000,5000);
		printf("\r\n %d",aRxBuffer);
	}else if(aRxBuffer == 50)
	{
		pwm = 1250;
		SetPWM(5000,pwm,5000,5000);
		printf("\r\n %d",aRxBuffer);
	}
	else if(aRxBuffer == 51)
	{
		pwm = 1300;
		SetPWM(5000,pwm,5000,5000);
		printf("\r\n %d",aRxBuffer);
	}
	else if(aRxBuffer == 52)
	{
		pwm = 1500;
		SetPWM(5000,pwm,5000,5000);
		printf("\r\n %d",aRxBuffer);
	}
	else if(aRxBuffer == 53)
	{
		pwm = 1750;
		SetPWM(5000,pwm,5000,5000);
		printf("\r\n %d",aRxBuffer);
	}
	else if(aRxBuffer == 54)
	{
		pwm = 2000;
		SetPWM(5000,pwm,5000,5000);
		printf("\r\n %d",aRxBuffer);
	}
	else if (aRxBuffer == 55)
	{
		pwm+=10;
		SetPWM(5000,pwm,5000,5000);
		if(pwm == 2000)
		{
			pwm = 2000;
		}
		printf("\r\n %d",aRxBuffer);
	}
	else if (aRxBuffer == 56)
	{
		pwm-=10;
		SetPWM(5000,pwm,5000,5000);
		if(pwm == 1000)
		{
			pwm = 1000;
		}
		printf("\r\n %d",aRxBuffer);
	}
	else
	{
		SetPWM(5000,0,5000,5000);
		printf("\r\n %d",aRxBuffer);
	}










}



/***************************************************** MAIN END *******************************************************************/








