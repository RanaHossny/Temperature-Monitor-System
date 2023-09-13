/*
 * HMotor_Prog.c
 *
 *  Created on: Sep 5, 2023
 *      Author: karee
 */

#include"HMotor_Int.h"

void Motor_On(uint8 PortId1,uint8 Pin1, uint8 PortId2,uint8 Pin2){
	MGPIO_u8SetPinVal(PortId1,Pin1,1);
	MGPIO_u8SetPinVal(PortId2,Pin2,0);
}

void Motor_Off(uint8 PortId1,uint8 Pin1, uint8 PortId2,uint8 Pin2){
	MGPIO_u8SetPinVal(PortId1,Pin1,0);
	MGPIO_u8SetPinVal(PortId2,Pin2,0);
}


