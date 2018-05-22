/*
 * MyLib.h
 *
 *  Created on: Nov 2, 2017
 *      Author: User
 */

#ifndef MYLIB_H_
#define MYLIB_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "stm32f4xx_nucleo_144.h"
#include "stm32f4xx_hal_i2c.h"


/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/***********************************************Timers Sections**************************************************************************/
/********************** User can use this section to tailor TIMx instance used and associated resources *********************************/




/***********************************************Functions prototype section************************************************************/
void ControlClock(void);

void ConfigureLED(void);

void SetResetLed(Led_TypeDef led, uint8_t u8state);

void delay(int time);

void ConfigureButton(void);



#endif /* MYLIB_H_ */
