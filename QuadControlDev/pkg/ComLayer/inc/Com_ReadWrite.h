#ifndef COM_LAYER_H_
#define COM_LAYER_H_

#include "stm32f4xx.h"
#include "Com_Buffer.h"

void Com_Write_ComLayer_IMUData(uint8_t u);
void Com_Read_ComLayer_IMUData(uint8_t* u);
uint8_t ComMdl_Read_ComLayer_IMUData(void);
void ComMdl_Write_ComLayer_IMUData(uint8_t u);




#endif /*COM_LAYER_H_*/
