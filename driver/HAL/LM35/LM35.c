/********************************************/
/* Description : LM35 						*/
/* Author      : sara hossny         		*/
/* Date        : 9/9/2023                   */
/* Version     : 0.1V                       */
/********************************************/
#include "STD_Types.h"
#include "BIT_Math.h"
#include "RCC.h"
#include "LM35_PRIV.h"
#include "LM35_CONFG.h"
#include "LM35.h"


float32 ADC_to_Temperature(uint16 adcValue) {
    // and LM35 sensitivity is 10 mV/°C
//    float32 voltage = (adcValue / (STEPS*1.0)) * Vref; // Convert ADC reading to voltage
//    float32 temperature = (voltage - 0.5) * 100.0; // Convert voltage to temperature in Celsius
    float32 output_temp=((float) adcValue /STEPS) * Vref;
	output_temp=output_temp/0.01;
    return output_temp;
}




