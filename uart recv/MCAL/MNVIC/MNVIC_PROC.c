/*
 * MNVIC_PROC.c
 *
 *  Created on: Aug 13, 2023
 *      Author: moroz
 */
/***********************************
 *************************************
AUTHOR  : MAHMOUD MOHAMED OMAR IBRAHIM
MICRO   : STM32F401CCU6
LAYER   : MCAL
DRIVER  : NVIC_Driver
File    : Main File
Version : 1.0
************************************
*******************/
#include "../../LIB/BIT_Math.h"
#include "../../LIB/STD_Types.h"

#include "MNVIC_Int.h"
#include "MNVIC_Private.h"
#include "MNVIC_Config.h"
/*
 * Return value: void
 * Input parameter: interrupt id
 * functionality: enable interrupt
 * **/
u32 Global_u32setGroupMode;
void MNVIC_vInterruptSetEnable(u8 Copy_u8InterruptID){
	if (Copy_u8InterruptID > 84 ) return;
	u8 reg = Copy_u8InterruptID / Register_bits;
	u8 bitno = Copy_u8InterruptID % Register_bits;
	NVIC->ISER[reg] |= (1<<bitno);
}
/*
 * Return Type: void
 * Input parameter: Group mode
 * functionality: set group mode
 *
 *  */

void MNVIC_vsetGroupMode(Group_Mode Copy_GroupMode){
	u32 Global_u32setGroupMode = MNVIC_VECTKEY | (Copy_GroupMode<<8);
	AIRCR = Global_u32setGroupMode;
}

void MNVIC_vInterruptClearEnable(u8 Copy_u8InterruptID){
	if (Copy_u8InterruptID > 84 ) return;
	u8 reg = Copy_u8InterruptID / Register_bits;
	u8 bitno = Copy_u8InterruptID % Register_bits;
	NVIC->ICER[reg] |= (1<<bitno);
}
void MNVIC_vSetInterruptPriority(u8 Copy_u8InterruptID, u8 Copy_GroupId,u8 Copy_SubGroupId){
	switch (Global_u32setGroupMode){
	case MNVIC_G16_S0:
		NVIC -> IPR[Copy_u8InterruptID]=(Copy_GroupId<<4);break;
	case MNVIC_G8_S2:
		NVIC -> IPR[Copy_u8InterruptID]=(Copy_GroupId<<5);
		NVIC -> IPR[Copy_u8InterruptID]|=(Copy_SubGroupId<<4);break;
	case MNVIC_G4_S4:
		NVIC -> IPR[Copy_u8InterruptID]=(Copy_GroupId<<6);
		NVIC -> IPR[Copy_u8InterruptID]|=(Copy_SubGroupId<<4);break;
	case MNVIC_G2_S8:
		NVIC -> IPR[Copy_u8InterruptID]=(Copy_GroupId<<7);
		NVIC -> IPR[Copy_u8InterruptID]|=(Copy_SubGroupId<<4);break;
	case MNVIC_G0_S16:
		NVIC -> IPR[Copy_u8InterruptID]=(Copy_SubGroupId<<4);break;
		break;
	default:
		break;
	}
}

