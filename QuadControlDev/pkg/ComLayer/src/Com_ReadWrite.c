
#include "Com_ReadWrite.h"


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
uint8_t ComMdl_Read_ComLayer_IMUData(void) {
  return ComLayer_stComData.ComLayer_IMUData;
}
void ComMdl_Write_ComLayer_IMUData(uint8_t u) {
  ComLayer_stComData.ComLayer_IMUData = u;
}
