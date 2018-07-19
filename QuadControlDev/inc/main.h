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

void _delay_ms(int time);

void TIM6_DAC_IRQHandler(void);

#endif /* MAIN_H_ */
