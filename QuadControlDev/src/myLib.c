/*
 * myLib.c
 *
 *  Created on: Nov 2, 2017
 *      Author: User
 */


/* Includes ------------------------------------------------------------------*/
#include "myLib.h"
#include "mpu_6050.h"
#include "main.h"

/***********************************************Start PWM Section****************************************************************/
/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/



/***********************************************End PWM Section****************************************************************/


void ControlClock(void)
{
	//RccR
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN ; // enable the RCC for the GPIO Port B
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN; // enable the RCC for GPIO Port C (user button)
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN; // enable the clock for tim3

}

void ConfigureLED(void)
{
	/*The blue led is connected to the PB7*/
	//GPIO_MODER_MODER7   11
	//GPIO_MODER_MODER7_0 01
	//GPIO_MODER_MODER7_1 10

	//ModerR
	GPIOB->MODER |= GPIO_MODER_MODER0_0|GPIO_MODER_MODER7_0|GPIO_MODER_MODER14_0;  // set the PORB  Pin 0,7,14 as general purpose output mode
	GPIOB->MODER &= ~(GPIO_MODER_MODER0_1|GPIO_MODER_MODER7_1|GPIO_MODER_MODER14_1);  // set the PORB  Pin 0,7,14 as general purpose output mode assure that second position is 0 (01)
	//OtyperR
	GPIOB->OTYPER &= ~(GPIO_OTYPER_OT_0|GPIO_OTYPER_OT_7|GPIO_OTYPER_OT_14); // set the pin as push pull(reset state)
	//SpeedR
	GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR0|GPIO_OSPEEDER_OSPEEDR7|GPIO_OSPEEDER_OSPEEDR14; // set up the pin speed as high speed
	//PupdR
	GPIOB->PUPDR &= ~(GPIO_PUPDR_PUPDR0|GPIO_PUPDR_PUPDR7|GPIO_PUPDR_PUPDR14); // set no pull up, pull down setting
}

void SetResetLed(Led_TypeDef led, uint8_t u8state)
{

	if (led == LED_BLUE)
	{
		(u8state==1)?GPIOB->BSRR |= (GPIO_BSRR_BS_7):(GPIOB->BSRR |= GPIO_BSRR_BR_7);
	}else if(led == LED_GREEN)
	{
		(u8state==1)?GPIOB->BSRR |= (GPIO_BSRR_BS_0):(GPIOB->BSRR |= GPIO_BSRR_BR_0);
	}else
	{
		(u8state==1)?GPIOB->BSRR |= (GPIO_BSRR_BS_14):(GPIOB->BSRR |= GPIO_BSRR_BR_14);
	}
}

void ConfigureButton(void)
{
	GPIOC->MODER &= ~(GPIO_MODER_MODER13); // set the pin as general purpose input output mode
	GPIOC->PUPDR &= ~(GPIO_PUPDR_PUPDR13); //set no pull up, pull down setting
}


/*create the delay function*/
void delay(int time)
{
	volatile int i,j;

	for(i=0;i<time;i++)
	{
		j++;
	}
}
