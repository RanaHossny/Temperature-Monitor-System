/*
 * MUSART_Config.h
 *
 *  Created on: Sep 3, 2023
 *      Author: karee
 */

#ifndef MCAL_MUSART_MUSART_CONFIG_H_
#define MCAL_MUSART_MUSART_CONFIG_H_

#include"../../LIB/STD_Types.h"

#define UART_MODE_RX                         (uint32) (1<<2)
#define UART_MODE_TX                       	 (uint32) (1<<3)
#define UART_MODE_TX_RX                     ((uint32)(1<<2 | 1<<3))

#define UART_BaudRate_1200 1200
#define UART_BaudRate_2400 2400
#define UART_BaudRate_9600 9600
#define UART_BaudRate_19200 19200
#define UART_BaudRate_38400 38400
#define UART_BaudRate_75600 75600
#define UART_BaudRate_115200 115200
#define UART_BaudRate_230400 230400
#define UART_BaudRate_460800 460800
#define UART_BaudRate_921600 921600
#define UART_BaudRate_2000000 2000000
#define UART_BaudRate_3000000 3000000

/*0: 1 Start bit, 8 Data bits, n Stop bit
  1: 1 Start bit, 9 Data bits, n Stop bit*/

#define UART_Length_8B (uint32) (0<<12)
#define UART_Length_9B (uint32)(1<<12)


#define UART_Parity__NONE                    (uint32)(0<<10)
#define UART_Parity__EVEN                    ((uint32)(1<<10 | 0<<9))
#define UART_Parity__ODD                     ((uint32)(1<<10 | 1<<9))


#define UART_StopBits__half                  (uint32)(1<<12)
#define UART_StopBits__1                     (uint32)(0<<12)
#define UART_StopBits__1_half                (uint32)(3<<12)
#define UART_StopBits__2                     (uint32)(2<<12)

#define UART_NO_Flow_Control                 (uint32)(0)
#define UART_RTS                             ((uint32)1<<8)
#define UART_CTS                             ((uint32)1<<9)
#define UART_Both_RTS_CTS                    ((uint32)(1<<8 | 1<<9))

#define UART_IRQ_Enable_NONE                      		(uint32) (0)
#define UART_IRQ_Enable_TXE                       		(uint32) (1<<7) //Transmit data register empty
#define UART_IRQ_Enable_TC                     			(uint32) (1<<6) //Transmission complete
#define UART_IRQ_Enable_RXNEIE                       	(uint32) (1<<5) //Received data ready to be read & Overrun error detected
#define UART_IRQ_Enable_PE                       	    (uint32) (1<<8) //Parity error


enum Polling_mechism{
	enable ,
	disable
};

#endif /* MCAL_MUSART_MUSART_CONFIG_H_ */
