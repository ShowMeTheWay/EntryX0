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
#include "stm32f4xx_nucleo_144.h"
#include "stdio.h"
#include "stm32f4xx_hal_uart.h"


static void SystemClock_Config(void);

void Config_I2C_Peripheral(void);

void I2C_MasterTransmit_Single_Byte(void);

void I2C_MasterReceive_Single_Byte(void);

void Error_Handler(void);

int main(void);

void I2C__vReadBuffer(uint8_t I2c_add, uint8_t RegAddr, uint8_t *aRxBuffer, uint8_t rxbuffsz);

void I2C__vWriteBuffer(uint8_t I2c_add, uint8_t *aTxBuffer, uint8_t txbuffsz);

static uint16_t Buffercmp(uint8_t* pBuffer1, uint8_t* pBuffer2, uint16_t BufferLength);

static void Flush_Buffer(uint8_t* pBuffer, uint16_t BufferLength);

#endif /* MAIN_H_ */
