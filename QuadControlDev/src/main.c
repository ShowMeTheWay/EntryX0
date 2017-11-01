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
#include "main.h"
#include "stm32f4xx.h"
#include "stm32f4xx_nucleo_144.h"


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/

// create delay function
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
	//GPIO_MODER_MODER7   11
	//GPIO_MODER_MODER7_0 01
	//GPIO_MODER_MODER7_1 10

	//RccR
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN ; // enable the RCC for the GPIO Port B
	//ModerR
	GPIOB->MODER |= GPIO_MODER_MODER7_0;  // set the PORB  Pin 7 as general purpose output mode
	GPIOB->MODER &= ~(GPIO_MODER_MODER7_1);  // set the PORB  Pin 7 as general purpose output mode assure that second position is 0 (01)
	//OtyperR
	GPIOB->OTYPER &= ~(GPIO_OTYPER_OT_7); // set the pin as push pull(reset state)
	//SpeedR
	GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR7; // set up the pin speed as high speed
	GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR7; // set up the pin speed as high speed
	//PupdR
	GPIOB->PUPDR &= ~(GPIO_PUPDR_PUPDR7); // set no pull up, pull down setting

  /* Toggle some leds in an infinite loop */
  while (1)
  {
	  GPIOB->BSRR |= GPIO_BSRR_BS_7;
	  delay(200000);
	  GPIOB->BSRR |= GPIO_BSRR_BR_7;
	  delay(100000);

  }
}


