/*
 * uart_interface.h
 *
 *  Created on: May 11, 2018
 *      Author: User
 */

#ifndef DRIVER_UART_INC_UART_INTERFACE_H_
#define DRIVER_UART_INC_UART_INTERFACE_H_

#include "stm32f4xx.h"
#include "uart_interface_ci.h"

void Config_USART_Peripheral(void);

void HAL_UART_MspInit(UART_HandleTypeDef *huart);

void UART_Transmit_Data(UART_HandleTypeDef UartHandle, float data_in);

#endif /* DRIVER_UART_INC_UART_INTERFACE_H_ */
