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
#include "mpu_6050.h"


/*************************************************Start I2C Section*************************************************************/

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Uncomment this line to use the board as master, if not it is used as slave */
#define I2C_ADDRESS        0x68F



/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
/* I2C handler declaration */
I2C_HandleTypeDef I2cHandle;

/* Buffer used for transmission */
uint8_t aTxBuffer[]=" ****I2C_TwoBoards advanced communication";

/* Buffer used for reception */
uint8_t aRxBuffer[RXBUFFERSIZE];
uint16_t hTxNumData = 0, hRxNumData = 0;
uint8_t bTransferRequest = 0;

/* Private function prototypes -----------------------------------------------*/



/* Private functions ---------------------------------------------------------*/

/*************************************************End I2C Section*************************************************************/

/*************************************************Start UART Section*************************************************************/

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* UART handler declaration */
UART_HandleTypeDef UartHandle;

/* Private function prototypes -----------------------------------------------*/
#ifdef __GNUC__
/* With GCC, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */


/* Private functions ---------------------------------------------------------*/

/*************************************************End UART Section*************************************************************/

static void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;

  /* Enable Power Control clock */
  __HAL_RCC_PWR_CLK_ENABLE();  // set the PWREN to 1 in  RCC_APB1ENR register (1: Power interface clock enable)

  /* The voltage scaling allows optimizing the power consumption when the device is
     clocked below the maximum system frequency, to update the voltage scaling value
     regarding system frequency refer to product datasheet.  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1); // set the  VOS(voltage output selection) in PWR_CR register to scale 1 mode (11)

  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE; // choose the HSE clock which can be supplied with a 4 -26 Mhz crystal/ceramic resonator oscillator
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS; // set bit HSEBYP (bypass the oscillator with an extern clock) and set HSEON(HSE clock enable)
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON; // enable the PLL set 0x02 in  RCC_PLLCFGR
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE; // select  HSE as a PLL source set PLLSRC in RCC_PLLCFGR

  /*PLL calculation
   * 1. f_VCO_clock = f_PLL_clock_input x (PLLN/PLLM)
   * 2. f_PLL_general_clock_output = f_VCO_clock/PLLP
   *
   *Clock for USB SDIO(sd card) clock
   *f_USB_OTG_FS_SDIO_RNG_clock = f_VCO_clock/PLLQ
   * */
  RCC_OscInitStruct.PLL.PLLM = 15; // choose the division factor for main PLL set the PLLM in RCC_PLLCFGR to 8
  RCC_OscInitStruct.PLL.PLLN = 216; // multiplication factor for main PLL set the PLLN in RCC_PLLCFGR to 216
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2; // division factor for the main system clock set PLLP in RCC_PLLCFGR
  RCC_OscInitStruct.PLL.PLLQ = 4; // set the OTG FS (on-the-go full speed) for USB minimum 48Hz to work correctly
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  /* Activate the Over-Drive mode */
  HAL_PWREx_EnableOverDrive();

  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK; // set SW in RCC_CFGR register to choose PLL as source clock
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;  // set HPRE in RCC_CFGR register - system clock not divided
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;   // set PPRE1 in RCC_CFGR register - AHB clock divided by 4
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;  // set PPRE1 in RCC_CFGR register - AHB clock divided by 2
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);
}

void Config_I2C_Peripheral(void)
{

	/*##-1- Configure the I2C peripheral #######################################*/
	I2cHandle.Instance             = I2Cx;

	I2cHandle.Init.AddressingMode  = I2C_ADDRESSINGMODE_7BIT;
	I2cHandle.Init.ClockSpeed      = 400000;
	I2cHandle.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	I2cHandle.Init.DutyCycle       = I2C_DUTYCYCLE_16_9;
	I2cHandle.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	I2cHandle.Init.NoStretchMode   = I2C_NOSTRETCH_DISABLE;
	I2cHandle.Init.OwnAddress1     = I2C_ADDRESS;
	//I2cHandle.Init.OwnAddress2     = 0xFE;  // no use the dev board as slave

	if(HAL_I2C_Init(&I2cHandle) != HAL_OK)
	{
	  /* Initialization Error */
	  Error_Handler();
	}

}

void Config_USART_Peripheral(void)
{
	/*##-1- Configure the UART peripheral ######################################*/
	/* Put the USART peripheral in the Asynchronous mode (UART Mode) */
	/* UART configured as follows:
	      - Word Length = 8 Bits (7 data bit + 1 parity bit) :
		                  BE CAREFUL : Program 7 data bits + 1 parity bit in PC HyperTerminal
	      - Stop Bit    = One Stop bit
	      - Parity      = none parity
	      - BaudRate    = 9600 baud
	      - Hardware flow control disabled (RTS and CTS signals) */
	UartHandle.Instance        = USARTx;

	UartHandle.Init.BaudRate   = 9600;
	UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
	UartHandle.Init.StopBits   = UART_STOPBITS_1;
	UartHandle.Init.Parity     = UART_PARITY_NONE;
	UartHandle.Init.HwFlowCtl  = UART_HWCONTROL_NONE;
	UartHandle.Init.Mode       = UART_MODE_TX_RX;
	UartHandle.Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_UART_Init(&UartHandle) != HAL_OK)
	{
		/* Initialization Error */
		Error_Handler();
	}

	/* Output a message on Hyperterminal using printf function */
	printf("\n\r Target has been RESET and is active ! \n\r");
}

static void Error_Handler(void)
{
  /* Turn LED Red on */
	SetResetLed(LED_RED,1U);
  while(1)
  {
  }

}

void I2C__vWriteBuffer(uint8_t I2c_add, uint8_t *aTxBuffer, uint8_t txbuffsz)
{
    /* -> Start the transmission process */
    /* While the I2C in reception process, user can transmit data through "aTxBuffer" buffer */
    while(HAL_I2C_Master_Transmit(&I2cHandle, (uint16_t)(I2c_add<<1), (uint8_t*)aTxBuffer, (uint16_t)txbuffsz, (uint32_t)1000)!= HAL_OK)
    {
        /*
         * Error_Handler() function is called when Timeout error occurs.
         * When Acknowledge failure occurs (Slave don't acknowledge it's address)
         * Master restarts communication
         */

        if (HAL_I2C_GetError(&I2cHandle) != HAL_I2C_ERROR_AF)
        {
            Error_Handler();
        }

    }

    /* -> Wait for the end of the transfer */
    /* Before starting a new communication transfer, you need to check the current
     * state of the peripheral; if it’s busy you need to wait for the end of current
     * transfer before starting a new one.
     * For simplicity reasons, this example is just waiting till the end of the
     * transfer, but application may perform other tasks while transfer operation
     * is ongoing.
     */
      while (HAL_I2C_GetState(&I2cHandle) != HAL_I2C_STATE_READY)
      {
      }
}

void I2C__vReadBuffer(uint8_t I2c_add, uint8_t RegAddr, uint8_t *aRxBuffer, uint8_t rxbuffsz)
{
    /* -> Lets ask for register's address */
	I2C__vWriteBuffer(I2c_add, &RegAddr, 1);

    /* -> Put I2C peripheral in reception process */
    while(HAL_I2C_Master_Receive(&I2cHandle, (uint16_t)(I2c_add<<1), aRxBuffer, (uint16_t)rxbuffsz, (uint32_t)1000) != HAL_OK)
    {
        /* Error_Handler() function is called when Timeout error occurs.
         * When Acknowledge failure occurs (Slave don't acknowledge it's address)
         * Master restarts communication
         */
        if (HAL_I2C_GetError(&I2cHandle) != HAL_I2C_ERROR_AF)
        {
            Error_Handler();
        }
    }

    /* -> Wait for the end of the transfer */
    /* Before starting a new communication transfer, you need to check the current
     * state of the peripheral; if it’s busy you need to wait for the end of current
     * transfer before starting a new one.
     * For simplicity reasons, this example is just waiting till the end of the
     * transfer, but application may perform other tasks while transfer operation
     * is ongoing.
     **/
    while (HAL_I2C_GetState(&I2cHandle) != HAL_I2C_STATE_READY)
    {
    }
}

void WHO_AM_I_vTest()
{
	/* Initialize number of data variables */
	static uint8_t registerContent;

	/*Step 1 - Transmit the adress and the register adress that shall be read*/
	/* Update bTransferRequest to send buffer write request for Slave */

	I2C__vReadBuffer(0x68,117,(uint8_t*)&registerContent,1);

	printf("\n\r Who are you ? \n\r");
	printf("\n\r My chip adress is = %d \n\r",registerContent);

	/* Flush Rx buffers */
	Flush_Buffer((uint8_t*)aRxBuffer,RXBUFFERSIZE);
}


/**
  * @brief  Compares two buffers.
  * @param  pBuffer1, pBuffer2: buffers to be compared.
  * @param  BufferLength: buffer's length
  * @retval 0  : pBuffer1 identical to pBuffer2
  *         >0 : pBuffer1 differs from pBuffer2
  */
static uint16_t Buffercmp(uint8_t* pBuffer1, uint8_t* pBuffer2, uint16_t BufferLength)
{
  while (BufferLength--)
  {
    if ((*pBuffer1) != *pBuffer2)
    {
      return BufferLength;
    }
    pBuffer1++;
    pBuffer2++;
  }

  return 0;
}

/**
  * @brief  Flushes the buffer
  * @param  pBuffer: buffers to be flushed.
  * @param  BufferLength: buffer's length
  * @retval None
  */
static void Flush_Buffer(uint8_t* pBuffer, uint16_t BufferLength)
{
  while (BufferLength--)
  {
    *pBuffer = 0;

    pBuffer++;
  }
}
/***************************************************** MAIN START *******************************************************************/

int main(void)
{
	char newL[2]="\r\n";
	char del[1]=",";
	/*Init hal drivers*/
	HAL_Init();

	/*Configure the system clock to 180 Mhz*/
	SystemClock_Config();

	ControlClock();
	ConfigureLED();
	ConfigureButton();
	PWMConfig();
	Config_I2C_Peripheral();
	Config_USART_Peripheral();

	WHO_AM_I_vTest();

	while (1)
	{
//
//	  if (GPIOC->IDR & (1<<13) )
//	  {
//		  SetResetLed(LED_BLUE,1U);
//////		  HAL_UART_Transmit(&UartHandle, (uint8_t *)newL, 2, 0xFFFF);
//////		  //HAL_UART_Transmit(&huart5, (uint8_t *)del, 1, 0xFFFF);
//////		  UART_Transmit_Data(UartHandle,-87);
//////		  HAL_UART_Transmit(&UartHandle, (uint8_t *)del, 1, 0xFFFF);
//////		  UART_Transmit_Data(UartHandle,68.5);
//////		  HAL_UART_Transmit(&UartHandle, (uint8_t *)del, 1, 0xFFFF);
//////		  UART_Transmit_Data(UartHandle,-0.6);
//////		  HAL_UART_Transmit(&UartHandle, (uint8_t *)del, 1, 0xFFFF);
//////		  UART_Transmit_Data(UartHandle,267);
//////		  printf(str);
////
////	  }
////	  else
////	  {
////		  SetResetLed(LED_BLUE,0U);
////	  }

	}


	return 0;


}

/***************************************************** MAIN END *******************************************************************/


/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */
PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the USART3 and Loop until the end of transmission */
  HAL_UART_Transmit(&UartHandle, (uint8_t *)&ch, 1, 0xFFFF);

  return ch;
}






