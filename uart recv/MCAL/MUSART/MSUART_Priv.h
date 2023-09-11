/*
 * MSUART_Priv.h
 *
 *  Created on: Aug 23, 2023
 *      Author: moroz
 */

#ifndef MCAL_MUSART_MSUART_PRIV_H_
#define MCAL_MUSART_MSUART_PRIV_H_
#define NULLptr ((void*)0)
#define  USART1_BASE_ADDR 0x40011000
#define  USART2_BASE_ADDR 0x40004400
#define  USART6_BASE_ADDR 0x40011400
typedef struct{
	u8 SBK:1;
	u8 RWU:1;
	u8 RE:1;
	u8 TE:1;
	u8 IDLEIE:1;
	u8 RXNEIE:1;
	u8 TCIE:1;
	u8 TXEIE:1;
	u8 PEIE:1;
	u8 PC:1;
	u8 PCE:1;
	u8 WAKE:1;
	u8 M:1;
	u8 UE:1;
	u8 Reserved1:1;
	u8 OVER8:1;
	u32 Reserved2:16;
}USARTCR1;

typedef struct{
	u32 SR;
	u32 DR;
	u32 BRR;
	USARTCR1 CR1;
	u32 CR2;
	u32 CR3;
	u32 GTPR;
}USART_MemMap_t;
#define  USART1 ((volatile USART_MemMap_t* ) (USART1_BASE_ADDR))
#define  USART2 ((volatile USART_MemMap_t* ) (USART2_BASE_ADDR))
#define  USART6 ((volatile USART_MemMap_t* ) (USART6_BASE_ADDR))

#endif /* MCAL_MUSART_MSUART_PRIV_H_ */
