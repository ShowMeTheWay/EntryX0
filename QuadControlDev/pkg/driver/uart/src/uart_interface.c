/*
 * uart_interface.c
 *
 *  Created on: May 11, 2018
 *      Author: User
 */

#include "uart_interface_ci.h"
#include "uart_interface.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* UART handler declaration */
UART_HandleTypeDef huart2;

/* Private function prototypes -----------------------------------------------*/
#ifdef __GNUC__
/* With GCC, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

__IO ITStatus UartReady = RESET;
/* Buffer used for transmission */
uint8_t UART_aTxBuffer[]="";
/* Buffer used for reception */
uint8_t UART_aRxBuffer[10];
/* Private functions ---------------------------------------------------------*/


/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */
PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the USART3 and Loop until the end of transmission */
  HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, 100);

  return ch;
}

void uart_gpio_init()
{
	GPIO_InitTypeDef GPIO_InitStruct;

	__GPIOD_CLK_ENABLE();

	/**USART2 GPIO Configuration
	PD5     ------> USART2_TX
	PD6     ------> USART2_RX
	*/
	GPIO_InitStruct.Pin = GPIO_PIN_5 | GPIO_PIN_6;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
	GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
}

void uart_init()
{
	__USART2_CLK_ENABLE();

	huart2.Instance = USART2;
	huart2.Init.BaudRate = 19200;
	huart2.Init.WordLength = UART_WORDLENGTH_8B;
	huart2.Init.StopBits = UART_STOPBITS_1;
	huart2.Init.Parity = UART_PARITY_NONE;
	huart2.Init.Mode = UART_MODE_TX_RX;
	huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart2.Init.OverSampling = UART_OVERSAMPLING_16;
	HAL_UART_Init(&huart2);

	/* Peripheral interrupt init*/
	HAL_NVIC_SetPriority(USART2_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(USART2_IRQn);
}


//void Config_USART_Peripheral(void)
//{
//	/*##-1- Configure the UART peripheral ######################################*/
//	/* Put the USART peripheral in the Asynchronous mode (UART Mode) */
//	/* UART configured as follows:
//	      - Word Length = 8 Bits (7 data bit + 1 parity bit) :
//		                  BE CAREFUL : Program 7 data bits + 1 parity bit in PC HyperTerminal
//	      - Stop Bit    = One Stop bit
//	      - Parity      = none parity
//	      - BaudRate    = 9600 baud
//	      - Hardware flow control disabled (RTS and CTS signals) */
//	UartHandle.Instance        = USARTx;
//
//	UartHandle.Init.BaudRate   = 19200;
//	UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
//	UartHandle.Init.StopBits   = UART_STOPBITS_1;
//	UartHandle.Init.Parity     = UART_PARITY_NONE;
//	UartHandle.Init.HwFlowCtl  = UART_HWCONTROL_NONE;
//	UartHandle.Init.Mode       = UART_MODE_TX_RX;
//	UartHandle.Init.OverSampling = UART_OVERSAMPLING_16;
//	if (HAL_UART_Init(&UartHandle) != HAL_OK)
//	{
//		/* Initialization Error */
//		Error_Handler("UART init error !!!");
//	}
//
//	/* Output a message on Hyperterminal using printf function */
//	printf("\n\r Target has been RESET and is active ! \n\r");
//}
//
///**
//  * @brief UART MSP Initialization
//  *        This function configures the hardware resources used in this example:
//  *           - Peripheral's clock enable
//  *           - Peripheral's GPIO Configuration
//  * @param huart: UART handle pointer
//  * @retval None
//  */
//void HAL_UART_MspInit(UART_HandleTypeDef *huart)
//{
//  GPIO_InitTypeDef  GPIO_InitStruct;
//
//
//  /*##-1- Enable peripherals and GPIO Clocks #################################*/
//  /* Enable GPIO TX/RX clock */
//  USARTx_TX_GPIO_CLK_ENABLE();
//  USARTx_RX_GPIO_CLK_ENABLE();
//
//
//  /* Enable USARTx clock */
//  USARTx_CLK_ENABLE();
//
//  /*##-2- Configure peripheral GPIO ##########################################*/
//  /* UART TX GPIO pin configuration  */
//  GPIO_InitStruct.Pin       = USARTx_TX_PIN;
//  GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
//  GPIO_InitStruct.Pull      = GPIO_PULLUP;
//  GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
//  GPIO_InitStruct.Alternate = USARTx_TX_AF;
//
//  HAL_GPIO_Init(USARTx_TX_GPIO_PORT, &GPIO_InitStruct);
//
//  /* UART RX GPIO pin configuration  */
//  GPIO_InitStruct.Pin = USARTx_RX_PIN;
//  GPIO_InitStruct.Alternate = USARTx_RX_AF;
//
//  HAL_GPIO_Init(USARTx_RX_GPIO_PORT, &GPIO_InitStruct);
//
//  HAL_NVIC_SetPriority(USARTx_IRQn, 0, 1);
//  HAL_NVIC_EnableIRQ(USARTx_IRQn);
//
//  /*##-2- Put UART peripheral in reception process ###########################*/
//  if(HAL_UART_Receive_IT(&UartHandle, (uint8_t *)UART_aRxBuffer, 10) != HAL_OK)
//  {
//
//  }
//
//}

/**
  * @brief UART MSP De-Initialization
  *        This function frees the hardware resources used in this example:
  *          - Disable the Peripheral's clock
  *          - Revert GPIO and NVIC configuration to their default state
  * @param huart: UART handle pointer
  * @retval None
  */
//void HAL_UART_MspDeInit(UART_HandleTypeDef *huart)
//{
//  /*##-1- Reset peripherals ##################################################*/
//  USARTx_FORCE_RESET();
//  USARTx_RELEASE_RESET();
//
//  /*##-2- Disable peripherals and GPIO Clocks ################################*/
//  /* Configure UART Tx as alternate function */
//  HAL_GPIO_DeInit(USARTx_TX_GPIO_PORT, USARTx_TX_PIN);
//  /* Configure UART Rx as alternate function */
//  HAL_GPIO_DeInit(USARTx_RX_GPIO_PORT, USARTx_RX_PIN);
//
//  /*##-3- Disable the NVIC for UART ##########################################*/
//  HAL_NVIC_DisableIRQ(USARTx_IRQn);
//}


void UART_Transmit_Data(UART_HandleTypeDef UartHandle, float data_in)
{
	int data_in_ = 0;
	uint8_t cnt = 0;
	float isInteger;
	uint8_t buffLeng = 0;

	/*check how many digits the integer part has*/
	data_in_ = (int)data_in;
	while(data_in_ != 0)
	{
		data_in_ = data_in_/10;
		cnt++;
	}

	isInteger = data_in - (int)(data_in);
	/*check if the input data is negative*/
	if(data_in < (float)0.0)
	{
		if(cnt == 0)
		{
			buffLeng = cnt  + 5; // 5 digits: 1-sign; 1-"."; 2-digits for the fractional part;1-for the 0 ex: -0.23
		}else
		{
			buffLeng = cnt  + 4; // 4 digits more: 1-sign;1-".";2-digits for the fraction part ex: -45.34
		}

		if(isInteger == 0)
		{
			buffLeng = cnt + 1; // add 1 digit for sign
		}

	}else if(data_in > (float)0.0)
	{
		if(cnt == 0)
		{
			buffLeng = cnt  + 4; // 4 digits: 1-"."; 2-digits for the fractional part;1-for the 0 ex: 0.23
		}else
		{
			buffLeng = cnt  + 3; // 4 digits more: 1-sign;1-".";2-digits for the fraction part ex: 45.34
		}

		if(isInteger == 0)
		{
			buffLeng = cnt;
		}
	}
	else
	{
		buffLeng  = 1;
	}

	char buff[buffLeng]; // define the buffer to be sent via UART
	gcvt(data_in,buffLeng,buff); // converts the float number to ASCII characters

	HAL_UART_Transmit(&huart2,(uint8_t *)buff,buffLeng,0xFFFF);

}

uint8_t UART_Receive_Data()
{
	uint8_t buf = 0;
	HAL_UART_Receive(&huart2,(uint8_t*)&buf,1,0xFFFF);

	return buf;
}
