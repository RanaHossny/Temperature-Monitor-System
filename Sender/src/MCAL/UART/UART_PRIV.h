/*
 * MUSART_Private.h
 *
 *  Created on: Sep 3, 2023
 *      Author: karee
 */

#ifndef MCAL_MUSART_MUSART_PRIVATE_H_
#define MCAL_MUSART_MUSART_PRIVATE_H_

#include "../../LIB/STD_Types.h"

#define MUSART_BASE_ADD  0x40011000
typedef struct
{
	uint32 SR;
	uint32 DR;
	uint32 BRR;
	uint32 CR1;
	uint32 CR2;
	uint32 CR3;
	uint32 GTPR;
}MUSART_t;

typedef struct
{

	uint8        			  USART_Mode;   		  // Specifies the TX/RX Mode.
	// This parameter must be set based on @ref UART_Mode_define

	uint32  			      BaudRate ; 		    // This member configures the UART communication baud rate
	// This parameter must be set based on @ref UART_BaudRate_define

	uint8				  Payload_Length;			// Specifies the number of data bits transmitted or received in a frame.
	// This parameter must be set based on @ref UART_Payload_Length_define


	uint8 				  Parity ;					//Specifies the parity mode.
	//@ref UART_Parity_define


	uint8 				  StopBits ;				//Specifies the number of stop bits transmitted
	//@ref UART_StopBits_define

	uint8 				  HwFlowCtl ;				//Specifies whether the hardware flow control mode is enabled or disabled
	//@ref UART_HwFlowCtl_define


	uint8					 IRQ_Enable;				//enable or disable UART IRQ TX/RX
	//@ref UART_IRQ_Enable_define , you can select two or three parameters EX.UART_IRQ_Enable_TXE |UART_IRQ_Enable_TC

	//void(* P_IRQ_CallBack)(void) ;					//Set the C Function() which will be called once the IRQ  Happen

}UART_Config;

#define USART   ((volatile MUSART_t*)MUSART_BASE_ADD)



#endif /* MCAL_MUSART_MUSART_PRIVATE_H_ */
