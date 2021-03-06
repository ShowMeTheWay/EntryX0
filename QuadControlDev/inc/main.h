/*
 * main.h
 *
 *  Created on: Oct 6, 2017
 *      Author: User
 */

#ifndef MAIN_H_
#define MAIN_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "stdio.h"
#include "stm32f4xx_hal_uart.h"

int main(void);

void TIM6_DAC_IRQHandler(void);

void USART2_IRQHandler(void);

#endif /* MAIN_H_ */
