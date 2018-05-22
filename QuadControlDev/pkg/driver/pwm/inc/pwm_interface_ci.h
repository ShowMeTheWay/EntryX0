/*
 * pwm_interface_ci.h
 *
 *  Created on: May 22, 2018
 *      Author: User
 */

#ifndef DRIVER_PWM_INC_PWM_INTERFACE_CI_H_
#define DRIVER_PWM_INC_PWM_INTERFACE_CI_H_

#include "stm32f4xx.h"

/***********************************************TIMER 3**********************************************************************************/

/* Definition for TIMx clock resources */
#define TIMx                           TIM3
#define TIMx_CLK_ENABLE()              __HAL_RCC_TIM3_CLK_ENABLE()

/* Definition for TIMx Channel Pins */
#define TIMx_CHANNEL_GPIO_PORT()       __HAL_RCC_GPIOB_CLK_ENABLE();
#define TIMx_GPIO_PORT_CHANNEL1        GPIOB
#define TIMx_GPIO_PORT_CHANNEL2        GPIOB
#define TIMx_GPIO_PORT_CHANNEL3        GPIOB
#define TIMx_GPIO_PORT_CHANNEL4        GPIOB
#define TIMx_GPIO_PIN_CHANNEL1         GPIO_PIN_4
#define TIMx_GPIO_PIN_CHANNEL2         GPIO_PIN_5
#define TIMx_GPIO_PIN_CHANNEL3         GPIO_PIN_0
#define TIMx_GPIO_PIN_CHANNEL4         GPIO_PIN_1
#define TIMx_GPIO_AF_CHANNEL1          GPIO_AF2_TIM3
#define TIMx_GPIO_AF_CHANNEL2          GPIO_AF2_TIM3
#define TIMx_GPIO_AF_CHANNEL3          GPIO_AF2_TIM3
#define TIMx_GPIO_AF_CHANNEL4          GPIO_AF2_TIM3

#define  PERIOD_VALUE       (uint32_t)(40900 - 1)  /* Period Value  */
#define  PULSE1_VALUE       (uint32_t)(PERIOD_VALUE/2)        /* Capture Compare 1 Value  */
#define  PULSE2_VALUE       (uint32_t)(PERIOD_VALUE*37.5/100) /* Capture Compare 2 Value  */
#define  PULSE3_VALUE       (uint32_t)(PERIOD_VALUE/4)        /* Capture Compare 3 Value  */
#define  PULSE4_VALUE       (uint32_t)(PERIOD_VALUE*12.5/100) /* Capture Compare 4 Value  */
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#endif /* DRIVER_PWM_INC_PWM_INTERFACE_CI_H_ */
