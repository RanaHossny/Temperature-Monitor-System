/*
 * BIT_Math.h
 *
 *  Created on: Aug 10, 2023
 *      Author: yasmi
 */

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_

#define SET_BIT(Reg , BitNum)   (Reg) |= (1<<(BitNum))
#define CLR_BIT(Reg , BitNum)   (Reg) &=~(1<<(BitNum))
#define TGL_BIT(Reg , BitNum)   (Reg) ^= (1<<(BitNum))
#define EDIT_VALUE(Reg ,value, mask ) (Reg) = value|(~mask&Reg)
#define GET_BIT(Reg , BitNum)   (((Reg) >> (BitNum))&0x01)

#endif /* LIB_BIT_MATH_H_ */
