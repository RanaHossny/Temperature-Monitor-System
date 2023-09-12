/*
 * MUSART_Program.c
 *
 *  Created on: Sep 3, 2023
 *      Author: karee
 */


#include"UART.h"

UART_Config* Global_UART1;

//Global_UART_Config ->USART_Mode = UART_MODE_TX;


void MUART_vInit(UART_Config* UART_Config){

    Global_UART1=UART_Config;
    //u32 pclk ,BRR  ;
    //Enable USART Module
	//	USART_CR1  Bit 13 UE: USART enable
	USART->CR1 |= 1<<13 ;

	//Enable USART Tx and Rx engines according to the USART_Mode configuration item
	//	USART_CR1 Bit 3 TE: Transmitter enable & Bit 2 RE: Receiver enable
	USART->CR1 |= UART_Config->USART_Mode ;

	//PAYLOAD Width
	// USART->CR1  Bit 12 M: Word length
	USART->CR1 |= UART_Config->Payload_Length ;

	//Configuration of parity control bit fields
	// USART->CR1 	Bit 10 PCE: Parity control enable     Bit 9 PS: Parity selection
	USART->CR1 |= UART_Config->Parity ;

	//configure the number of stop bits
	//USART_CR2  Bits 13:12 STOP: STOP bits
	USART->CR2 |= UART_Config->StopBits ;


	//USART hardware flow control
	//USART_CR3  Bit 9 CTSE: CTS enable   Bit 8 RTSE: RTS enable
	USART->CR3 |= UART_Config->HwFlowCtl ;


	//Configuration of BRR(Baudrate register)



	USART->BRR = 0x683 ;



	//ENABLE / DISABLE Interrupt
	//USART_CR1
	if (UART_Config->IRQ_Enable  != UART_IRQ_Enable_NONE)
	{
		//USART->CR1 |= (UART_Config->IRQ_Enable) ;
		//		Enable NVIC For USARTx IRQ
    }

}
void MUART_vSendData(uint16* Copy_u8Data ,uint16 Copy_u8Length){
	for (uint8 i = 0 ; i<Copy_u8Length ; i++)
		{
			USART -> DR = Copy_u8Data[i];
			while(GET_BIT(USART -> SR,7)==0);
		}
}

	void MUSART_voidSendString(uint8* copy_u8Data)
{
	uint8 iterator=0;
	while(copy_u8Data[iterator] != '\0')
	{
		   USART->DR = copy_u8Data[iterator] ;
		   while(GET_BIT(USART->SR,6) == 0) ;
		   iterator++;
	}
}

uint8 MUART_u8ReadData(){

		uint8 local_u8Recieved = 0;
		while(GET_BIT(USART->SR,5)==0);
		local_u8Recieved = (uint8) USART -> DR;
		return local_u8Recieved;
}
void MUART_voidEnable(void) ;
void MUART_voidDisable(void) ;
//void MUART_vCallbackFun(void(*ptr)(void));

