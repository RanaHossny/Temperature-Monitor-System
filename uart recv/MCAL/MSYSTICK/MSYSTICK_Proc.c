/*
 * MSYSTICK_Proc.c
 *
 *  Created on: Aug 15, 2023
 *      Author: moroz
 */

#include "../../LIB/BIT_Math.h"
#include "../../LIB/STD_Types.h"

#include "MSYSTICK_Int.h"
#include "MSYSTICK_Private.h"
#include "MSYSTICK_Config.h"

void(*Global_CallbackSystickPointer)(void) = NULLptr;
/*
 * return type: void
 * arguments : void
 * implementation: chooses the CLK Source either AHB or AHB/8
 * */
void MSYSTICK_vInit(void){
#ifdef RCC_CLK == AHB
	SYSTICK -> CTRL |= 1<<CTRL_CLKSRC;
#endif
#ifdef RCC_CLK == AHB8
	SYSTICK -> CTRL &= ~(1<<CTRL_CLKSRC);
#endif
}
/*
 * return type: void
 * arguments : void
 * implementation: Enables interrupt
 * */
void MSYSTICK_vIntState(void){
	SYSTICK -> CTRL |= 1<<CTRL_TICKENT;
}
/*
 * return type: void
 * arguments : 32 bit preload value (will be truncated to 24 bit)
 * implementation: starts the systick timer with the given reload value
 * */
void MSYSTICK_vStart(u32 A_u32PreloadValue){
	//CLR_BIT(SYSTICK -> CTRL,CTRL_TICKENT);
	SYSTICK -> VAL = 0 ;
	SYSTICK -> LOAD = A_u32PreloadValue;
	SYSTICK -> CTRL |= 1<<CTRL_ENA;
}
/*
 * return type: void
 * arguments : void
 * implementation: reads flag and reset it in process
 * */
u8 MSYSTICK_u8ReadFlag(void){
	return (GET_BIT(SYSTICK -> CTRL,CTRL_COUNTFLAG));
}
/*
 * return type: void
 * arguments : void
 * implementation: reads flag and reset it in process
 * */

void MSYSTICK_vDelayUsec(u32 A_u32DelayUsec){
    CLR_BIT(SYSTICK -> CTRL,CTRL_TICKENT);
    MSYSTICK_vStart(A_u32DelayUsec*16);
    while(GET_BIT(SYSTICK->CTRL,CTRL_COUNTFLAG)==0);
}
void MSYSTICK_vDelayMsec(u32 A_u32DelayMsec){
    CLR_BIT(SYSTICK -> CTRL,CTRL_TICKENT);
    MSYSTICK_vStart(A_u32DelayMsec*16000);
    while(GET_BIT(SYSTICK->CTRL,CTRL_COUNTFLAG)==0);
}
void MSYSTICK_vDelayMsecInt(u32 A_u32DelayMsec){
    MSYSTICK_vStart(A_u32DelayMsec*16000);
}
u32 MSYSTICK_u32GetElapsedTime(void){
	return (SYSTICK -> LOAD) - (SYSTICK -> VAL);
}
u32 MSYSTICK_u32GetRemainingTime(void){
	return (SYSTICK -> VAL);
}
void MSYSTICK_Callback(void(*ptr)(void)){
	Global_CallbackSystickPointer = ptr;
}
void SysTick_Handler(void){
	Global_CallbackSystickPointer();
	//MSYSTICK_u8ReadFlag();
	//CLR_BIT(SYSTICK -> CTRL,1);
	//CLR_BIT(SYSTICK -> CTRL,0);
}

