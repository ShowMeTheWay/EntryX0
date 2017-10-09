/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "stm32f4xx_nucleo_144.h"

// RCC(reset and clock control) configuration


			

int main(void)
{
	/*Init HAL library*/
	HAL_Init();

	/*Enable HSI oscillator and configure the PLL to reach the maximum frequency 180 MHz when using HSI oscillator as PLL clock source*/
	SystemClockConfiguration();

	/* Configure LED1,LED2,LED3 */
	BSP_LED_Init(LED1);
	BSP_LED_Init(LED2);
	BSP_LED_Init(LED3);

	/* Initialize User push-button, will be used to trigger an interrupt each time it's pressed.*/
	BSP_PB_Init(BUTTON_USER,BUTTON_MODE_EXTI);

	/* Output SYSCLK  / 1 on MCO1 pin(PA.08) */
	HAL_RCC_MCOnfig(RCC_MCO1,RCC_MCO1SOURCE_PLLCLK,RCC_MCODIV_1);


	/*toggle LEDS*/
	while(1)
	{

	}
}
