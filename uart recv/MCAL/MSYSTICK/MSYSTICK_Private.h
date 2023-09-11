/*
 * MSYSTICK_Private.h
 *
 *  Created on: Aug 15, 2023
 *      Author: moroz
 */
/***********************************
 *************************************
AUTHOR  : MAHMOUD MOHAMED OMAR IBRAHIM
MICRO   : STM32F401CCU6
LAYER   : MCAL
DRIVER  : EXTI_Driver
File    : Private File
Version : 1.0
************************************
*******************/
#ifndef MCAL_MSYSTICK_MSYSTICK_PRIVATE_H_
#define MCAL_MSYSTICK_MSYSTICK_PRIVATE_H_
#define MSYSTICK_BASE_ADDR (0xE000E010)
#define CTRL_ENA 0
#define CTRL_TICKENT 1
#define CTRL_CLKSRC 2
#define CTRL_COUNTFLAG 16
#define NULLptr (void*)0
typedef struct{
	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;
}MSYSTICK_MemMap_t;
#define SYSTICK ((volatile MSYSTICK_MemMap_t*)(MSYSTICK_BASE_ADDR))



#endif /* MCAL_MSYSTICK_MSYSTICK_PRIVATE_H_ */
