#ifndef IICB_INTERFACE_H
#define IICB_INTERFACE_H


#include "ers.h"

void HAL_I2C_MspInit(I2C_HandleTypeDef *hi2c);
void HAL_I2C_MspDeInit(I2C_HandleTypeDef *hi2c);
void Config_I2C_Peripheral(void);
void I2C__vReadBuffer(uint8_t I2c_add, uint8_t RegAddr, uint8_t *aRxBuffer, uint8_t rxbuffsz);

void I2C__vWriteBuffer(uint8_t I2c_add, uint8_t *aTxBuffer, uint16_t txbuffsz);

void I2C__vWriteSingleByteBuffer(uint8_t I2c_add, uint8_t regAdress, uint8_t regValue);

static uint16_t Buffercmp(uint8_t* pBuffer1, uint8_t* pBuffer2, uint16_t BufferLength);
static void Flush_Buffer(uint8_t* pBuffer, uint16_t BufferLength);
void WHO_AM_I_vTest();

#endif /* IICB_INTERFACE_H */
