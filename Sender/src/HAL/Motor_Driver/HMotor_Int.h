/*
 * HMotor_Int.h
 *
 *  Created on: Sep 5, 2023
 *      Author: karee
 */

#ifndef HAL_MOTOR_DRIVER_HMOTOR_INT_H_
#define HAL_MOTOR_DRIVER_HMOTOR_INT_H_

#include"../../LIB/STD_Types.h"
#include"../../MCAL/GPIO/GPIO.h"

void Motor_On(uint8 PortId1,uint8 Pin1, uint8 PortId2,uint8 Pin2);

void Motor_Off(uint8 PortId1,uint8 Pin1, uint8 PortId2,uint8 Pin2);


#endif /* HAL_MOTOR_DRIVER_HMOTOR_INT_H_ */
