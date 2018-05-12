/*
 * SimulinkAdapt.c
 *
 *  Created on: May 12, 2018
 *      Author: User
 */
#include "SimulinkAdapt.h"
#include "uart_interface.h"

void UART_DisplayData(UART_tstDataDisplayed data_in)
{
	printf("\r\n %f,%f,%f,%f \r\n",data_in.data1,data_in.data2,data_in.data3,data_in.data4);
}



