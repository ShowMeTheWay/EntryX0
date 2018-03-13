
#include "Com_ReadWrite.h"
#include "stm32f4xx.h"


/******************************************************************************
 * Name: ComLayer_IMUData
 * Type category: VALUE
 * Type name: uint8
 * Providers: IMUM
 * Requesters:
 *****************************************************************************/
void Com_Write_ComLayer_IMUData(uint8_t u) {
	ComLayer_stComData.ComLayer_IMUData = u;
}
void Com_Read_ComLayer_IMUData(uint8_t* u) {
  *u = ComLayer_stComData.ComLayer_IMUData;
}


