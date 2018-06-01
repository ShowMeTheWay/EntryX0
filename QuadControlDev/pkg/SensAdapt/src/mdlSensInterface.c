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
	printf("\r\n %f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f \r\n",data_in.signal7,data_in.signal8,
														   data_in.signal9,data_in.signal10,
														   data_in.signal11,data_in.signal12,
			                                               data_in.u16AccXDataS,data_in.u16AccYDataS,
														   data_in.u16AccZDataS,data_in.u16GyroXDataS,
														   data_in.u16GyroYDataS,data_in.u16GyroZDataS);
}



