/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/



/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx.h"
#include "stm32f4xx_nucleo_144.h"
#include "myLib.h"


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define ON 1
#define OFF 0
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/



int main(void)
{
	ControlClock();
	ConfigureLED();

  /* Toggle some leds in an infinite loop */
  while (1)
  {

	  SetResetLed(LED_BLUE,1U);
	  delay(100000);
	  SetResetLed(LED_BLUE,0U);
	  SetResetLed(LED_GREEN,1U);
	  delay(100000);
	  SetResetLed(LED_GREEN,0U);
	  SetResetLed(LED_RED,1U);
	  delay(100000);
	  SetResetLed(LED_RED,0U);

  }
}


