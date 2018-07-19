/*
 * task.h
 *
 *  Created on: Jun 2, 2018
 *      Author: User
 */

#ifndef SYSTEM_TASK_INC_TASK_H_
#define SYSTEM_TASK_INC_TASK_H_

#include "stm32f4xx.h"

/* Definition for TIMx clock resources */
#define TIM6_CLK_ENABLE()              __HAL_RCC_TIM6_CLK_ENABLE()


void Config_vTask1();

#endif /* SYSTEM_TASK_INC_TASK_H_ */
