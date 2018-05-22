/*
 * pwm_interface.h
 *
 *  Created on: May 22, 2018
 *      Author: User
 */

#ifndef DRIVER_PWM_INC_PWM_INTERFACE_H_
#define DRIVER_PWM_INC_PWM_INTERFACE_H_

#include "pwm_interface_ci.h"

void PWMConfig();

void SetPWM(uint32_t pulse1 ,uint32_t pulse2 ,uint32_t pulse3 ,uint32_t pulse4);



#endif /* DRIVER_PWM_INC_PWM_INTERFACE_H_ */
