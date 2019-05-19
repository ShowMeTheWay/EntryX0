/*
 * task.c
 *
 *  Created on: Jun 2, 2018
 *      Author: User
 */
#include "task.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal.h"

//Period = [(TIM6CLK/200) - 1]. to have a (1/100) s time base.
#define ANY_DELAY_RQUIRED ((1000000 / 200U) - 1U)

/* Timer handler declaration */
TIM_HandleTypeDef Tim4Handle;

void Config_vTask1()
{
	RCC_ClkInitTypeDef    clkconfig;
	uint32_t              uwTimclock, uwAPB1Prescaler = 0U;
	uint32_t              uwPrescalerValue = 0U;
	uint32_t              pFLatency;

	/*Configure the TIM6 IRQ priority */
	HAL_NVIC_SetPriority(TIM6_DAC_IRQn, 0U ,1U);
	/* Enable the TIM6 global Interrupt */
	HAL_NVIC_EnableIRQ(TIM6_DAC_IRQn);
	/*enable clock source for timer 6 APB BUS*/
	/* Enable TIM6 clock */
	__HAL_RCC_TIM6_CLK_ENABLE();

	/* Get clock configuration */
	HAL_RCC_GetClockConfig(&clkconfig, &pFLatency);

	/* Get APB1 prescaler */
	uwAPB1Prescaler = clkconfig.APB1CLKDivider;

	/* Compute TIM6 clock */
	if (uwAPB1Prescaler == RCC_HCLK_DIV1)
	{
		uwTimclock = HAL_RCC_GetPCLK1Freq();
	}
	else
	{
		uwTimclock = 2*HAL_RCC_GetPCLK1Freq();
	}

	/* Compute the prescaler value to have TIM6 counter clock equal to 1MHz */
	uwPrescalerValue = (uint32_t) ((uwTimclock / 1000000) - 1U);

	/*Clear the update event flag*/
	TIM6->SR = 0;
	/* Set the required delay */
	TIM6->PSC = uwPrescalerValue;
	/*set the auto reload register*/
	TIM6->ARR = ANY_DELAY_RQUIRED;
	/*enable update interrupt*/
	TIM6->DIER = TIM_DIER_UIE;
	/*start the timer counter*/
	TIM6->CR1 |= TIM_CR1_CEN;


}
