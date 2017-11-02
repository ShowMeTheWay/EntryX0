/*
 * MyLib.h
 *
 *  Created on: Nov 2, 2017
 *      Author: User
 */

#ifndef MYLIB_H_
#define MYLIB_H_

#include "stm32f4xx.h"
#include "stm32f4xx_nucleo_144.h"

void ControlClock(void);

void ConfigureLED(void);

void SetResetLed(Led_TypeDef led, uint8_t u8state);

void delay(int time);

#endif /* MYLIB_H_ */
