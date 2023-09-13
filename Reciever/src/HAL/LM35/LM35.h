/********************************************/
/* Description : LM35 */
/* Author      : sara hossny         */
/* Date        : 9/9/2023                  */
/* Version     : 0.1V                       */
/********************************************/
 /* Gaurd */
#ifndef   LM35_H
#define   LM35_H
#include "../../LIB/STD_Types.h"

float32 ADC_to_Temperature(uint16 adcValue);
#endif
