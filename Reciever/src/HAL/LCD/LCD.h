/********************************************************************************/
/**    File Name: LCD.h                                                    */
/**                                                                             */
/**  Description: Implementation of the LED contain configuration for the module                            */
/**-----------------------------------------------------------------------------*/
/**  CODING LANGUAGE :  C                                                       */
/**  TARGET          :  STM32F401CCG6                                           */
/**-----------------------------------------------------------------------------*/
/**               C O P Y R I G H T                                             */
/**-----------------------------------------------------------------------------*/
/** Copyright (c) 2023 by Rana Hossny .       All rights reserved.              */
/**                                                                             */
/**-----------------------------------------------------------------------------*/
/**               A U T H O R   I D E N T I T Y                                 */
/**-----------------------------------------------------------------------------*/
/** ShortName    Name                      Company                              */
/** --------     ---------------------     -------------------------------------*/
/** Rana     Rana Hossny                 ain shams university.               */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 9/09/2023   0.1       Rana Hossny   Initial Creation                        */
/********************************************************************************/

#ifndef LCD_H
#define LCD_H
#include "../../LIB/STD_Types.h"
#include "LCD_cfg.h"

#define LCD_u8CLEAR      ((uint8 )0x01)

void LCD_voidInit(void) ;

tenuErrorStatus LCD_enuWriteCmd (uint8 u8LcdNumCpy , uint8 u8CmdCpy);

tenuErrorStatus LCD_enuWriteChar (uint8 u8LcdNumCpy , uint8 u8DataCpy);
void LCD_enuWritenumber(uint8 u8LcdNumCpy, float32 pu8DataCpy);

tenuErrorStatus LCD_enuWriteData (uint8 u8LcdNumCpy , uint8 *  pu8DataCpy , uint8 u8SizeCpy);

tenuErrorStatus LCD_enuCreateCustChar (uint8 u8LcdNumCpy , uint8 *pu8PatternCpy , uint8 u8Location) ;

#endif




