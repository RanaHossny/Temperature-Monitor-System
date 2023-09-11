/********************************************/
/* Description : ADC */
/* Author      : sara hossny         */
/* Date        : 9/9/2023                  */
/* Version     : 0.1V                       */
/********************************************/
 /* Gaurd */
#ifndef   ADC_H
#define   ADC_H
#include "STD_Types.h"
void ADC_Init(void);
float32 ADC_ReadChannel(uint32 channel);
//float32 adc_read();
//void start_conversation();
//void adc_init();
#endif
