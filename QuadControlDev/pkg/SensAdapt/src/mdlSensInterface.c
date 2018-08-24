/*
 * SimulinkAdapt.c
 *
 *  Created on: May 12, 2018
 *      Author: User
 */
#include <mdlSensInterface.h>
#include "uart_interface.h"
#include "MadgwickAHRS.h"

void UART_DisplayData(IMU_tstRawData din)
{
	printf("\r\n %f,%f,%f,%f,%f,%f,%f,%f,%f,%f",din.AccXDataS,din.AccYDataS,din.AccZDataS, \
			                                    din.GyroXDataS,din.GyroYDataS,din.GyroZDataS, \
												din.q0,din.q1,din.q2,din.q3);

}

