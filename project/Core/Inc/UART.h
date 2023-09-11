/********************************************************************************/
/**    File Name: UART.h                                                        */
/**                                                                             */
/**  Description: Implementation of the UART contain header of function the module */
/**-----------------------------------------------------------------------------*/
/**  CODING LANGUAGE :  C                                                       */
/**  TARGET          :  STM32F401CCG6                                           */
/**-----------------------------------------------------------------------------*/
/**               C O P Y R I G H T                                             */
/**-----------------------------------------------------------------------------*/
/** Copyright (c) 2023 by Sara Hossny .       All rights reserved.              */
/**                                                                             */
/**-----------------------------------------------------------------------------*/
/**               A U T H O R   I D E N T I T Y                                 */
/**-----------------------------------------------------------------------------*/
/** ShortName    Name                      Company                              */
/** --------     ---------------------     -------------------------------------*/
/** Sara    Sara Hossny                 ain shams university.               */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 23/08/2023   0.1       Rana Hossny   Initial Creation                        */
/** 25/08/2023   0.2       Sara Hossny   EDIT AND ADD MORE FUNCTION              */

/********************************************************************************/


#ifndef   UART_H
#define   UART_H
#include "STD_Types.h"
#include"UART_PRIV.h"
void v_Send_byte(uint16 data, uint8 uart_indx);
uint16 u16_receive_data( uint8 uart_indx);

void vUART_Init();


#endif
