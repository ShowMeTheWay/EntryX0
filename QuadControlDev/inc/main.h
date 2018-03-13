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

/***********************************************START I2C section*****************************************************************************/


/***********************************************END I2C section*****************************************************************************/

/***********************************************START USART section*****************************************************************************/


/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* User can use this section to tailor USARTx/UARTx instance used and associated
   resources */
/* Definition for USARTx clock resources */
#define USARTx                           USART3
#define USARTx_CLK_ENABLE()              __HAL_RCC_USART3_CLK_ENABLE();
#define USARTx_RX_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOD_CLK_ENABLE()
#define USARTx_TX_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOD_CLK_ENABLE()

#define USARTx_FORCE_RESET()             __HAL_RCC_USART3_FORCE_RESET()
#define USARTx_RELEASE_RESET()           __HAL_RCC_USART3_RELEASE_RESET()

/* Definition for USARTx Pins */
#define USARTx_TX_PIN                    GPIO_PIN_10
#define USARTx_TX_GPIO_PORT              GPIOB
#define USARTx_TX_AF                     GPIO_AF7_USART3
#define USARTx_RX_PIN                    GPIO_PIN_9
#define USARTx_RX_GPIO_PORT              GPIOD
#define USARTx_RX_AF                     GPIO_AF7_USART3

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

/***********************************************END USART section*****************************************************************************/



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
