/*
 * SimulinkAdapt.h
 *
 *  Created on: May 12, 2018
 *      Author: User
 */

#ifndef MATLAB_SOURCE_SIMULINKADAPT_H_
#define MATLAB_SOURCE_SIMULINKADAPT_H_

#include "SensAdapt_types.h"
#include "rtwtypes.h"
#include "stm32f4xx.h"


void UART_DisplayData(IMU_tstRawData din);

uint8_t GetButtonState(void);

void SetLedState(uint8_t u8state);

#endif /* MATLAB_SOURCE_SIMULINKADAPT_H_ */
