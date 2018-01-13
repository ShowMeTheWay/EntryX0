/*
 * MyLib.h
 *
 *  Created on: Nov 2, 2017
 *      Author: User
 */

#ifndef MYLIB_H_
#define MYLIB_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "stm32f4xx_nucleo_144.h"
#include "stm32f4xx_hal_i2c.h"


/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/***********************************************Timers Sections**************************************************************************/
/********************** User can use this section to tailor TIMx instance used and associated resources *********************************/
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
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */



/***********************************************Functions prototype section************************************************************/
void ControlClock(void);

void ConfigureLED(void);

void SetResetLed(Led_TypeDef led, uint8_t u8state);

void delay(int time);

void ConfigureButton(void);

void PWMConfig(void);

void SetPWM(uint32_t pulse1 ,uint32_t pulse2 ,uint32_t pulse3 ,uint32_t pulse4);

static void Error_Handler(void);

void PWMConfig(void);

void Config_I2C_Peripheral(void);


#endif /* MYLIB_H_ */
