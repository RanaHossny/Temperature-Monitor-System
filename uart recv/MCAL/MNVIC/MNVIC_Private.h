/*
 * MNVIC_Private.h
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
File    : Private File
Version : 1.0
************************************
*******************/
#ifndef MCAL_MNVIC_MNVIC_PRIVATE_H_
#define MCAL_MNVIC_MNVIC_PRIVATE_H_
#define MNVIC_VECTKEY (0x05FA)

#define MNVIC_BASE_ADDRESS  (0xE000E100)
typedef struct {
	u32 ISER[8];
	u32 res1[24];
	u32 ICER[8];
	u32 res2[24];
	u32 ISPR[8];
	u32 res3[24];
	u32 ICPR[8];
	u32 res4[24];
	u32 IABR[8];
	u32 res5[56];
	u8  IPR[240];
	u32 res6[580];
	u32 STIR;
}MNVIC_MemMap_t;

#define NVIC ((volatile MNVIC_MemMap_t *) (MNVIC_BASE_ADDRESS))
#define AIRCR (*((volatile u32*)(0xE000ED0C)))


#endif /* MCAL_MNVIC_MNVIC_PRIVATE_H_ */
