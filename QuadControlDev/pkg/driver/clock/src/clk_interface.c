/*
 * clk_interface.c
 *
 *  Created on: May 22, 2018
 *      Author: User
 */

#include "clk_interface.h"

void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;
  HAL_StatusTypeDef ret = HAL_OK;

  /* Enable Power Control clock */
  __HAL_RCC_PWR_CLK_ENABLE();  // set the PWREN to 1 in  RCC_APB1ENR register (1: Power interface clock enable)

  /* The voltage scaling allows optimizing the power consumption when the device is
     clocked below the maximum system frequency, to update the voltage scaling value
     regarding system frequency refer to product datasheet.  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1); // set the  VOS(voltage output selection) in PWR_CR register to scale 1 mode (11)

  /* -1- Select HSI as system clock source to allow modification of the PLL configuration */
   RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK;
   RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
   if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
   {
     /* Initialization Error */
     Error_Handler();
   }

  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE; // choose the HSE clock which can be supplied with a 4 -26 Mhz crystal/ceramic resonator oscillator
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE; // select  HSE as a PLL source set PLLSRC in RCC_PLLCFGR
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON; // enable the PLL set 0x02 in  RCC_PLLCFGR


  /*PLL calculation
   * 1. f_VCO_clock = f_PLL_clock_input x (PLLN/PLLM)
   * 2. f_PLL_general_clock_output = f_VCO_clock/PLLP
   *
   *Clock for USB SDIO(sd card) clock
   *f_USB_OTG_FS_SDIO_RNG_clock = f_VCO_clock/PLLQ
   * */
  RCC_OscInitStruct.PLL.PLLM = 8; // choose the division factor for main PLL set the PLLM in RCC_PLLCFGR to 8
  RCC_OscInitStruct.PLL.PLLN = 360; // multiplication factor for main PLL set the PLLN in RCC_PLLCFGR to 216
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2; // division factor for the main system clock set PLLP in RCC_PLLCFGR
  RCC_OscInitStruct.PLL.PLLQ = 7; // set the OTG FS (on-the-go full speed) for USB minimum 48Hz to work correctly
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  ret = HAL_RCC_OscConfig(&RCC_OscInitStruct);
  if(ret != HAL_OK)
  {
	  while(1) { ; }
  }

  /* Activate the OverDrive to reach the 180 MHz Frequency */
  ret = HAL_PWREx_EnableOverDrive();
  if(ret != HAL_OK)
  {
    while(1) { ; }
  }

  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK; // set SW in RCC_CFGR register to choose PLL as source clock
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;  // set HPRE in RCC_CFGR register - system clock not divided
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;   // set PPRE1 in RCC_CFGR register - AHB clock divided by 4
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;  // set PPRE1 in RCC_CFGR register - AHB clock divided by 2

  ret = HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);
  if(ret != HAL_OK)
  {
    while(1) { ; }
  }
}
