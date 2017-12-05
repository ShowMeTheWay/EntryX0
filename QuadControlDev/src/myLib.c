/*
 * myLib.c
 *
 *  Created on: Nov 2, 2017
 *      Author: User
 */


/* Includes ------------------------------------------------------------------*/
#include "myLib.h"

/* Private typedef -----------------------------------------------------------*/
#define  PERIOD_VALUE       (uint32_t)(40900 - 1)  /* Period Value  */
#define  PULSE1_VALUE       (uint32_t)(PERIOD_VALUE/2)        /* Capture Compare 1 Value  */
#define  PULSE2_VALUE       (uint32_t)(PERIOD_VALUE*37.5/100) /* Capture Compare 2 Value  */
#define  PULSE3_VALUE       (uint32_t)(PERIOD_VALUE/4)        /* Capture Compare 3 Value  */
#define  PULSE4_VALUE       (uint32_t)(PERIOD_VALUE*12.5/100) /* Capture Compare 4 Value  */
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/

/* Timer handler declaration */
TIM_HandleTypeDef TimHandle;

/* Timer Output Compare Configuration Structure declaration */
TIM_OC_InitTypeDef sConfig;

/* Counter Prescaler value */
uint32_t uhPrescalerValue = 0;

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

static void Error_Handler(void)
{
    /* Turn LEDRed on */
	SetResetLed(LED_RED,1U);
    while (1)
    {
    	//do nothing
    }
}

void PWMConfig()
{
	/*##-1- Configure the TIM peripheral #######################################*/
	  /* -----------------------------------------------------------------------
	  TIM3 Configuration: generate 4 PWM signals with 4 different duty cycles.

	    In this example TIM3 input clock (TIM3CLK) is set to APB1 clock x 2,
	    since APB1 prescaler is equal to 2.
	    TIM3CLK = APB1CLK*2 = 45MHz x 2  = 90MHz
	    APB1CLK = HCLK/2; 180 MHz / 2 = 90 MHz
	      => TIM3CLK = HCLK = SystemCoreClock

	    To get TIM3 counter clock at 15 MHz, the prescaler is computed as follows:
	       Prescaler = (TIM3CLK / TIM3 counter clock) - 1
	       Prescaler = ((SystemCoreClock) /15 MHz) - 1

	    To get TIM3 output clock at 22,52 KHz, the period (ARR)) is computed as follows:
	       ARR = (TIM3 counter clock / TIM3 output clock) - 1
	           = 665

	    TIM3 Channel1 duty cycle = (TIM3_CCR1/ TIM3_ARR + 1)* 100 = 50%
	    TIM3 Channel2 duty cycle = (TIM3_CCR2/ TIM3_ARR + 1)* 100 = 37.5%
	    TIM3 Channel3 duty cycle = (TIM3_CCR3/ TIM3_ARR + 1)* 100 = 25%
	    TIM3 Channel4 duty cycle = (TIM3_CCR4/ TIM3_ARR + 1)* 100 = 12.5%

	    Note:
	     SystemCoreClock variable holds HCLK frequency and is defined in system_stm32f4xx.c file.
	     Each time the core clock (HCLK) changes, user had to update SystemCoreClock
	     variable value. Otherwise, any configuration based on this variable will be incorrect.
	     This variable is updated in three ways:
	      1) by calling CMSIS function SystemCoreClockUpdate()
	      2) by calling HAL API function HAL_RCC_GetSysClockFreq()
	      3) each time HAL_RCC_ClockConfig() is called to configure the system clock frequency
	  ----------------------------------------------------------------------- */

	 /* Initialize TIMx peripheral as follows:
	       + Prescaler = (SystemCoreClock / 15000000) - 1
	       + Period = (666 - 1)
	       + ClockDivision = 0
	       + Counter direction = Up
	  */

	/* Compute the prescaler value to have TIM3 counter clock equal to 15000000 Hz */
	uhPrescalerValue = (uint32_t)((SystemCoreClock/2) / 2000000) - 1;

	TimHandle.Instance = TIMx;                       // choose the timer instance defined as tim3
	TimHandle.Init.Prescaler = uhPrescalerValue;
	TimHandle.Init.Period = PERIOD_VALUE;
	TimHandle.Init.ClockDivision = 0;
	TimHandle.Init.CounterMode = TIM_COUNTERMODE_UP;
	TimHandle.Init.RepetitionCounter = 0;

	if (HAL_TIM_PWM_Init(&TimHandle) != HAL_OK)
	{
		/* Initialization Error */
	    Error_Handler();
	}

	/*##-2- Configure the PWM channels #########################################*/
	/* Common configuration for all channels */

	sConfig.OCMode 		 = TIM_OCMODE_PWM1;
	sConfig.OCPolarity   = TIM_OCPOLARITY_HIGH;
	sConfig.OCFastMode   = TIM_OCFAST_DISABLE;
	sConfig.OCNPolarity  = TIM_OCNPOLARITY_HIGH;
	sConfig.OCNIdleState = TIM_OCNIDLESTATE_RESET;

	sConfig.OCIdleState  = TIM_OCIDLESTATE_RESET;

	/* Set the pulse value for channel 1 */
	sConfig.Pulse = PULSE1_VALUE;
	if (HAL_TIM_PWM_ConfigChannel(&TimHandle, &sConfig, TIM_CHANNEL_1) != HAL_OK)
	{
		/* Configuration Error */
		Error_Handler();
	}

	/* Set the pulse value for channel 2 */
	sConfig.Pulse = PULSE2_VALUE;
	if (HAL_TIM_PWM_ConfigChannel(&TimHandle, &sConfig, TIM_CHANNEL_2) != HAL_OK)
	{
	  /* Configuration Error */
	  Error_Handler();
	}

	/* Set the pulse value for channel 3 */
	sConfig.Pulse = PULSE3_VALUE;
	if (HAL_TIM_PWM_ConfigChannel(&TimHandle, &sConfig, TIM_CHANNEL_3) != HAL_OK)
	{
	  /* Configuration Error */
	  Error_Handler();
	}

	/* Set the pulse value for channel 4 */
	sConfig.Pulse = PULSE4_VALUE;
	if (HAL_TIM_PWM_ConfigChannel(&TimHandle, &sConfig, TIM_CHANNEL_4) != HAL_OK)
	{
	  /* Configuration Error */
	  Error_Handler();
	}

	/*##-3- Start PWM signals generation #######################################*/
	/* Start channel 1 */
	if (HAL_TIM_PWM_Start(&TimHandle, TIM_CHANNEL_1) != HAL_OK)
	{
	  /* PWM Generation Error */
	  Error_Handler();
	}
	/* Start channel 2 */
	if (HAL_TIM_PWM_Start(&TimHandle, TIM_CHANNEL_2) != HAL_OK)
	{
	  /* PWM Generation Error */
	  Error_Handler();
	}
	/* Start channel 3 */
	if (HAL_TIM_PWM_Start(&TimHandle, TIM_CHANNEL_3) != HAL_OK)
	{
	  /* PWM generation Error */
	  Error_Handler();
	}
	/* Start channel 4 */
	if (HAL_TIM_PWM_Start(&TimHandle, TIM_CHANNEL_4) != HAL_OK)
	{
	  /* PWM generation Error */
	  Error_Handler();
	}

	HAL_TIM_PWM_MspInit(&TimHandle);

}

void SetPWM(uint32_t pulse1 ,uint32_t pulse2 ,uint32_t pulse3 ,uint32_t pulse4)
{
	/* Set the pulse value for channel 1 */
	sConfig.Pulse = pulse1;
	if (HAL_TIM_PWM_ConfigChannel(&TimHandle, &sConfig, TIM_CHANNEL_1) != HAL_OK)
	{
		/* Configuration Error */
		Error_Handler();
	}

	/* Set the pulse value for channel 2 */
	sConfig.Pulse = pulse2;
	if (HAL_TIM_PWM_ConfigChannel(&TimHandle, &sConfig, TIM_CHANNEL_2) != HAL_OK)
	{
		/* Configuration Error */
		Error_Handler();
	}

	/* Set the pulse value for channel 3 */
	sConfig.Pulse = pulse3;
	if (HAL_TIM_PWM_ConfigChannel(&TimHandle, &sConfig, TIM_CHANNEL_3) != HAL_OK)
	{
		/* Configuration Error */
		Error_Handler();
	}

	/* Set the pulse value for channel 4 */
	sConfig.Pulse = pulse4;
	if (HAL_TIM_PWM_ConfigChannel(&TimHandle, &sConfig, TIM_CHANNEL_4) != HAL_OK)
	{
		/* Configuration Error */
		Error_Handler();
	}

	/*##-3- Start PWM signals generation #######################################*/
	/* Start channel 1 */
	if (HAL_TIM_PWM_Start(&TimHandle, TIM_CHANNEL_1) != HAL_OK)
	{
		/* PWM Generation Error */
		Error_Handler();
	}
	/* Start channel 2 */
	if (HAL_TIM_PWM_Start(&TimHandle, TIM_CHANNEL_2) != HAL_OK)
	{
		/* PWM Generation Error */
		Error_Handler();
	}
	/* Start channel 3 */
	if (HAL_TIM_PWM_Start(&TimHandle, TIM_CHANNEL_3) != HAL_OK)
	{
		/* PWM generation Error */
		Error_Handler();
	}
	/* Start channel 4 */
	if (HAL_TIM_PWM_Start(&TimHandle, TIM_CHANNEL_4) != HAL_OK)
	{
		/* PWM generation Error */
		Error_Handler();
	}
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
