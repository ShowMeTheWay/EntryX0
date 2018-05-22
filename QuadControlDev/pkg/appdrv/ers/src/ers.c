/*
 * ers.c
 *
 *  Created on: May 22, 2018
 *      Author: User
 */

#include "uart_interface.h"


void Error_Handler(char msg[])
{
	uint8_t idx = 0;
  /* Turn LED Red on */
	SetResetLed(LED_RED,1U);

  while(1)
  {
	  printf("\r\n Error in %s \r\n",msg);
  }

}
