/*
 * MGPIO_Int.h
 *
 *  Created on: Aug 10, 2023
 *      Author: moroz
 */

#ifndef MCAL_MGPIO_MGPIO_INT_H_
#define MCAL_MGPIO_MGPIO_INT_H_

#define GPIO_MODE_INPUT 0b00
#define GPIO_MODE_OUTPUT 0b01
#define GPIO_MODE_ALTFUN 0b10
#define GPIO_MODE_ANALOG 0b11

#define GPIO_PORTA 0
#define GPIO_PORTB 1
#define GPIO_PORTC 2

#define GPIO_PUSHPULL 0
#define GPIO_OPENDRAIN 1

#define GPIO_LOW_SPEED 0b00
#define GPIO_MEDIUM_SPEED 0b01
#define GPIO_HIGH_SPEED 0b10
#define GPIO_VERYHIGH_SPEED 0b11

#define GPIO_NO_PULL 0b00
#define GPIO_PULL_UP 0b01
#define GPIO_PULL_DOWN 0b10
#define GPIO_PULL_UP 0b01

#define GPIO_HIGH 1
#define GPIO_LOW 0

#define AF0  0b0000
#define AF1  0b0001
#define AF2  0b0010
#define AF3  0b0011
#define AF4  0b0100
#define AF5  0b0101
#define AF6  0b0110
#define AF7  0b0111
#define AF8  0b1000
#define AF9  0b1001
#define AF10 0b1010
#define AF11 0b1011
#define AF12 0b1100
#define AF13 0b1101
#define AF14 0b1110
#define AF15 0b1111


void MGPIO_vSetPinMode(u8 A_u8PortId, u8 A_u8PinNo , u8 A_u8Mode);
void MGPIO_vSetPinOutputType(u8 A_u8PortId, u8 A_u8PinNo , u8 A_u8OutputType);
void MGPIO_vSetPinOutputSpeed(u8 A_u8PortId, u8 A_u8PinNo , u8 A_u8OutputSpeed);
void MGPIO_vSetPinInputPull(u8 A_u8PortId, u8 A_u8PinNo , u8 A_u8PullType);

u8 MGPIO_u8GetPinValue(u8 A_u8PortId,u8 A_u8PinNo);
void MGPIO_vSetPinValue(u8 A_u8PortId, u8 A_u8PinNo , u8 A_u8PinVal);
void MGPIO_vSetPinValue_fast(u8 A_u8PortId, u8 A_u8PinNo , u8 A_u8PinVal);//BSRR
void MGPIO_vSetAlternativeFunction(u8 A_u8PortId, u8 A_u8PinNo , u8 A_u8AltFun);

#endif /* MCAL_MGPIO_MGPIO_INT_H_ */
