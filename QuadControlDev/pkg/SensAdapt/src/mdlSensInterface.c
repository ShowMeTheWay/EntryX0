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
	printf("\r\n %f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f",din.AccXDataS,din.AccYDataS,din.AccZDataS, \
			                                    din.GyroXDataS,din.GyroYDataS,din.GyroZDataS, \
												din.q0,din.q1,din.q2,din.q3,din.th,din.ch,din.ph);

}

uint8_t GetButtonState(void)
{
	uint8_t btnS = 0;

	if (GPIOC->IDR & (1<<13))
	{
		btnS = 1;
	}
	else
	{
		btnS = 0;
	}

	return btnS;
}

void SetLedState(uint8_t u8State)
{
	(u8State == 1)?(GPIOB->BSRR |= (GPIO_BSRR_BS_7)):(GPIOB->BSRR |= (GPIO_BSRR_BR_7));
}
