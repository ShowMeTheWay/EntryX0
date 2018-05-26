/*
 * SimulinkAdapt.c
 *
 *  Created on: May 12, 2018
 *      Author: User
 */
#include <mdlSensInterface.h>
#include "uart_interface.h"

void UART_DisplayData(IMU_tstRawData data_in)
{
	printf("\r\n %d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d \r\n",data_in.u16AccXData,data_in.u16AccYData,data_in.u16AccZData,data_in.u16GyroXData,data_in.u16GyroYData,data_in.u16GyroZData,
			                             data_in.u16AccXDataS,data_in.u16AccYDataS,data_in.u16GyroYDataS,data_in.u16GyroXDataS,data_in.u16GyroYDataS,data_in.u16GyroZDataS);
}



