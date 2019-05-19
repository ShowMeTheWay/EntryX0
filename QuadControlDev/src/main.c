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
#include <SensAdapt.h>
#include "main.h"
#include "stm32f4xx.h"
#include "stm32f4xx_nucleo_144.h"
#include "iicb_interface.h"
#include "Com_ReadWrite.h"
#include "uart_interface.h"
#include "pwm_interface.h"
#include "clk_interface.h"
#include "dio_interface.h"
#include "ers.h"
#include "imu.h"
#include "task.h"
#include "genDigitsEst.h"
#include "mdlSensInterface.h"


extern UART_HandleTypeDef huart2;
IMU_tstImuData myIMUData;
uint8_t u8asax[3];
/* Single byte to store input */
uint8_t byte;
uint8_t finalString[20] = {0};
uint8_t idx = 0;


extern volatile float qw,qx,qy,qz,the,chi,phi;

#define nInitTotal 11

/******************************** Buffer for all Communication variables **********************************************/
ComLayer_tstComData ComLayer_stComData;
void (* const Init_vContainerTable[nInitTotal])(void) = {
		HAL_Init,
		SystemClock_Config,
		ControlClock,
		ConfigureLED,
		ConfigureButton,
		PWMConfig,
		Config_I2C_Peripheral,
		uart_gpio_init,
		uart_init,
		SensAdapt_initialize,
		Config_vTask1
};

/***************************************************** MAIN START *******************************************************************/


int main(void)
{

	uint8_t u8i = 0;

	for (u8i = 0; u8i < nInitTotal; u8i++)
	{
		Init_vContainerTable[u8i]();

		if (u8i == 9)
		{
			Init__vMPU_9255(u8asax);
		}
	}

	HAL_UART_Receive_IT(&huart2, &byte, 1);

	while (1){
	}

	return 0;


}
/******************************************** 10ms Task ******************************************88*/
void TIM6_DAC_IRQHandler(void)
{

	volatile static uint8_t a = 0;
	volatile static uint8_t cnt = 0;
	volatile static uint8_t buffer = 0;
	static uint16_t pwm = 0;
	static uint16_t cnt1 = 0;
	uint8_t i;



	/*clear UIF flag*/
	TIM6->SR &= ~TIM_SR_UIF;




//	for (idx = 0; idx < UART_RXBUFFERSIZE;idx++)
//	{
//		UART_aTxBuffer[idx] = UART_aRxBuffer[idx];
//	}
//	/*##-4- Start the transmission process #####################################*/
//	/* While the UART in reception process, user can transmit data through
//	   "aTxBuffer" buffer */
//	if(HAL_UART_Transmit_IT(&UartHandle, (uint8_t*)UART_aTxBuffer, UART_RXBUFFERSIZE)!= HAL_OK)
//	{
//
//	}




	SensAdapt_step();



//
//	if(aRxBuffer == 49)
//	{
//		pwm = 1000;
//		SetPWM(pwm,pwm,5000,5000);
//		printf("\r\n %d",aRxBuffer);
//	}else if(aRxBuffer == 50)
//	{
//		pwm = 1250;
//		SetPWM(pwm,pwm,5000,5000);
//		printf("\r\n %d",aRxBuffer);
//	}
//	else if(aRxBuffer == 51)
//	{
//		pwm = 1300;
//		SetPWM(pwm,pwm,5000,5000);
//		printf("\r\n %d",aRxBuffer);
//	}
//	else if(aRxBuffer == 52)
//	{
//		pwm = 1500;
//		SetPWM(pwm,pwm,5000,5000);
//		printf("\r\n %d",aRxBuffer);
//	}
//	else if(aRxBuffer == 53)
//	{
//		pwm = 1750;
//		SetPWM(pwm,pwm,5000,5000);
//		printf("\r\n %d",aRxBuffer);
//	}
//	else if(aRxBuffer == 54)
//	{
//		pwm = 2000;
//		SetPWM(pwm,pwm,5000,5000);
//		printf("\r\n %d",aRxBuffer);
//	}
//	else if (aRxBuffer == 55)
//	{
//		pwm+=10;
//		SetPWM(pwm,pwm,5000,5000);
//		if(pwm == 2000)
//		{
//			pwm = 2000;
//		}
//		printf("\r\n %d",aRxBuffer);
//	}
//	else if (aRxBuffer == 56)
//	{
//		pwm-=10;
//		SetPWM(pwm,pwm,5000,5000);
//		if(pwm == 1000)
//		{
//			pwm = 1000;
//		}
//		printf("\r\n %d",aRxBuffer);
//	}
//	else
//	{
//		SetPWM(pwm,pwm,5000,5000);
//		printf("\r\n %d",aRxBuffer);
//	}




//	if(cnt1 <= 500)
//	{
//		SetPWM(1000,1000,5000,5000);
//		cnt1++;
//	}
//	else
//	{
//		SetPWM(1500,1500,5000,5000);
//	}


//	myIMUData = GetData__stMPU_9255();


	//myIMUData =  smoothDataMvgAvg(myIMUData);

//	myIMUData.AccXData = (myIMUData.AccXData) / 835.040;
//	myIMUData.AccYData = (myIMUData.AccYData) / 835.040;
//	myIMUData.AccZData = (myIMUData.AccZData) / 835.040;
//	myIMUData.GyroXData = (myIMUData.GyroXData) / 939.650784;
//	myIMUData.GyroYData = (myIMUData.GyroYData) / 939.650784;
//	myIMUData.GyroZData = (myIMUData.GyroZData) / 939.650784;

//	myIMUData.AccXData  =  myIMUData.AccXData/835.040; // [SI] = m/s^2
//	myIMUData.AccYData  =  myIMUData.AccYData/835.040; // [SI] = m/s^2
//	myIMUData.AccZData  =  myIMUData.AccZData/835.040; // [SI] = m/s^2
//	myIMUData.Temp 	    =  ((myIMUData.Temp)/333.87) + 21; // [SI] = deg
//	myIMUData.GyroXData =  myIMUData.GyroXData/3756.72; // [SI] = rad/s
//	myIMUData.GyroYData =  myIMUData.GyroYData/3756.72; // [SI] = rad/s
//	myIMUData.GyroZData =  myIMUData.GyroZData/3756.72; // [SI] = rad/s
//	myIMUData.MagXData  =  myIMUData.MagXData * u8asax[0] * 4800; //fixed scale +/-4800 uT
//	myIMUData.MagYData  =  myIMUData.MagYData * u8asax[1] * 4800; //fixed scale +/-4800 uT
//	myIMUData.MagZData  =  myIMUData.MagZData * u8asax[2] * 4800; //fixed scale +/-4800 uT




//	GeneralDigitsFuseIMUSensors(myIMUData.AccXData,myIMUData.AccYData,myIMUData.AccZData,myIMUData.GyroXData,myIMUData.GyroYData,myIMUData.GyroZData);

//	printf("\r\n %f,%f,%f,%f,%f,%f,%f,%f,%f,%f",myIMUData.AccXData,myIMUData.AccYData,myIMUData.AccZData,myIMUData.Temp,
//														 myIMUData.GyroXData,myIMUData.GyroYData,myIMUData.GyroZData,
//														 myIMUData.MagXData,myIMUData.MagYData,myIMUData.MagZData );
	uint8_t newLine =  '\n';
	static uint8_t oneSec = 0;

	if (oneSec == 100)
	{
		/* Transmit one byte with 100 ms timeout */
		//HAL_UART_Transmit(&huart2, &finalString[0], 20, 1000);
		//HAL_UART_Transmit(&huart2, &newLine, 1, 100);
		for (i = 0; i < idx;i++)
		{
			//printf("%c",(finalString[i]));
		}

		//printf("\r\n");

		oneSec = 0;
	}
	else
	{
		oneSec++;
	}




}

/**
  * @brief  Tx Transfer completed callback
  * @param  UartHandle: UART handle.
  * @note   This example shows a simple way to report end of IT Tx transfer, and
  *         you can add your own implementation.
  * @retval None
  */
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *UartHandle)
{
  /* Set transmission flag: transfer complete*/

}

/**
  * @brief  Rx Transfer completed callback
  * @param  UartHandle: UART handle
  * @note   This example shows a simple way to report end of IT Rx transfer, and
  *         you can add your own implementation.
  * @retval None
  */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{

	static uint8_t recFlag = 0;
	static uint8_t u8arrByte[20] = {0};
	uint8_t u8i = 0;

	if (huart->Instance == USART2)
	{
		HAL_UART_Transmit(&huart2,&byte,1,100);
//	}
//		if (byte == 62)
//		{
//			idx = 0;
//		}
//		else if(byte == 60)
//		{
//			for (u8i = 0; u8i < idx ;u8i++)
//			{
//				finalString[u8i] = u8arrByte[u8i];
//			}
//		}
//		else
//		{
//			u8arrByte[idx] = byte;
//			idx++;
//		}
	    /* Receive one byte in interrupt mode */
	    HAL_UART_Receive_IT(huart, &byte, 1);
	}


}

void USART2_IRQHandler(void)
{
  HAL_UART_IRQHandler(&huart2);

}





/***************************************************** MAIN END *******************************************************************/








