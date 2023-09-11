/*
 * MSYSTICK_Int.h
 *
 *  Created on: Aug 15, 2023
 *      Author: moroz
 */
/***********************************
 *************************************
AUTHOR  : MAHMOUD MOHAMED OMAR IBRAHIM
MICRO   : STM32F401CCU6
LAYER   : MCAL
DRIVER  : SYSTICK_Driver
File    : Interface File
Version : 1.0
************************************
*******************/
#ifndef MCAL_MSYSTICK_MSYSTICK_INT_H_
#define MCAL_MSYSTICK_MSYSTICK_INT_H_
void MSYSTICK_vInit(void);
void MSYSTICK_vIntState(void);
void MSYSTICK_vStart(u32 A_u32PreloadValue);
u8 MSYSTICK_u8ReadFlag(void);
void MSYSTICK_vDelayUsec(u32 A_u32DelayUsec);
void MSYSTICK_vDelayMsec(u32 A_u32DelayMsec);
void MSYSTICK_vDelayMsecInt(u32 A_u32DelayMsec);
u32 MSYSTICK_u32GetElapsedTime(void);
u32 MSYSTICK_u32GetRemainingTime(void);
void MSYSTICK_Callback(void(*ptr)(void));

#endif /* MCAL_MSYSTICK_MSYSTICK_INT_H_ */
