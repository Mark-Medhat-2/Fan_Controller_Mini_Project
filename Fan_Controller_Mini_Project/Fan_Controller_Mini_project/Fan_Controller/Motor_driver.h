/*
 * Motor_driver.h
 *
 *  Created on: Oct 15, 2021
 *      Author: marcm
 */

#ifndef MOTOR_DRIVER_H_
#define MOTOR_DRIVER_H_
#include "std_types.h"

typedef enum
{
	CW,CCW,STOP
}DcMotor_State;


void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state,uint8 speed);


#endif /* MOTOR_DRIVER_H_ */
