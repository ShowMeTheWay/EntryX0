/*
 * dio_interface.h
 *
 *  Created on: May 22, 2018
 *      Author: User
 */

#ifndef DRIVER_DIO_INC_DIO_INTERFACE_H_
#define DRIVER_DIO_INC_DIO_INTERFACE_H_

#include "stm32f4xx_nucleo_144.h"
#include "stm32f4xx.h"

void ControlClock(void);

void ConfigureLED(void);

void SetResetLed(Led_TypeDef led, uint8_t u8state);

void ConfigureButton(void);

#endif /* DRIVER_DIO_INC_DIO_INTERFACE_H_ */
