/*
 * MUSART_Int.h
 *
 *  Created on: Sep 3, 2023
 *      Author: karee
 */

#ifndef MCAL_MUSART_MUSART_INT_H_
#define MCAL_MUSART_MUSART_INT_H_

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"
#include"UART_PRIV.h"
#include"UART_CFG.h"


void MUART_vInit();
void MUART_vSendData(uint16* Copy_u8Data ,uint16 Copy_u8Length);
void MUSART_voidSendString(uint8* copy_u8Data);
uint8 MUART_u8ReadData( );
//void MUART_voidEnable(void) ;
//void MUART_voidDisable(void) ;
//void MUART_vCallbackFun(void(*ptr)(void));



#endif /* MCAL_MUSART_MUSART_INT_H_ */
