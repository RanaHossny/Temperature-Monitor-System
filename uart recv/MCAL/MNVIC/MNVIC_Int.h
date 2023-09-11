/*
 * MNVIC_Int.h
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
File    : Interface File
Version : 1.0
************************************
*******************/
#ifndef MCAL_MNVIC_MNVIC_INT_H_
#define MCAL_MNVIC_MNVIC_INT_H_
#define Register_bits 32
typedef enum {
	MNVIC_G16_S0=3,
	MNVIC_G8_S2,
	MNVIC_G4_S4,
	MNVIC_G2_S8,
	MNVIC_G0_S16
}Group_Mode;
void MNVIC_vInterruptSetEnable(u8 Copy_u8InterruptID);
void MNVIC_vInterruptClearEnable(u8 Copy_u8InterruptID);
void MNVIC_vsetGroupMode(Group_Mode Copy_GroupMode);
void MNVIC_vSetInterruptPriority(u8 Copy_u8InterruptID, u8 Copy_GroupId,u8 Copy_SubGroupId);


#endif /* MCAL_MNVIC_MNVIC_INT_H_ */
