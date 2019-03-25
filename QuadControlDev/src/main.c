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


/* Buffer used for reception */
uint8_t aRxBuffer;
UART_HandleTypeDef UartHandle;
IMU_tstImuData myIMUData;
uint8_t u8asax[3];

extern volatile float qw,qx,qy,qz,the,chi,phi;

#define nInitTotal 10

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
		Config_USART_Peripheral,
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

		if (u8i == 8)
		{
			Init__vMPU_9255(u8asax);
		}
	}



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


	/*clear UIF flag*/
	TIM6->SR &= ~TIM_SR_UIF;


	//SensAdapt_step();

//	HAL_UART_Receive(&UartHandle, (uint8_t*)&aRxBuffer, 1, 0xFFFF);
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


	myIMUData = GetData__stMPU_9255();


	//myIMUData =  smoothDataMvgAvg(myIMUData);

//	myIMUData.AccXData = (myIMUData.AccXData) / 835.040;
//	myIMUData.AccYData = (myIMUData.AccYData) / 835.040;
//	myIMUData.AccZData = (myIMUData.AccZData) / 835.040;
//	myIMUData.GyroXData = (myIMUData.GyroXData) / 939.650784;
//	myIMUData.GyroYData = (myIMUData.GyroYData) / 939.650784;
//	myIMUData.GyroZData = (myIMUData.GyroZData) / 939.650784;

	myIMUData.AccXData  =  myIMUData.AccXData/835.040; // [SI] = m/s^2
	myIMUData.AccYData  =  myIMUData.AccYData/835.040; // [SI] = m/s^2
	myIMUData.AccZData  =  myIMUData.AccZData/835.040; // [SI] = m/s^2
	myIMUData.Temp 	    =  ((myIMUData.Temp)/333.87) + 21; // [SI] = deg
	myIMUData.GyroXData =  myIMUData.GyroXData/3756.72; // [SI] = rad/s
	myIMUData.GyroYData =  myIMUData.GyroYData/3756.72; // [SI] = rad/s
	myIMUData.GyroZData =  myIMUData.GyroZData/3756.72; // [SI] = rad/s
	myIMUData.MagXData  =  myIMUData.MagXData * u8asax[0] * 4800; //fixed scale +/-4800 uT
	myIMUData.MagYData  =  myIMUData.MagYData * u8asax[1] * 4800; //fixed scale +/-4800 uT
	myIMUData.MagZData  =  myIMUData.MagZData * u8asax[2] * 4800; //fixed scale +/-4800 uT




//	GeneralDigitsFuseIMUSensors(myIMUData.AccXData,myIMUData.AccYData,myIMUData.AccZData,myIMUData.GyroXData,myIMUData.GyroYData,myIMUData.GyroZData);

	printf("\r\n %f,%f,%f,%f,%f,%f,%f,%f,%f,%f",myIMUData.AccXData,myIMUData.AccYData,myIMUData.AccZData,myIMUData.Temp,
														 myIMUData.GyroXData,myIMUData.GyroYData,myIMUData.GyroZData,
														 myIMUData.MagXData,myIMUData.MagYData,myIMUData.MagZData );



}



/***************************************************** MAIN END *******************************************************************/








