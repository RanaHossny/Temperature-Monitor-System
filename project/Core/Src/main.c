
#include "RCC.h"
#include "GPIO.h"
#include  "SYSTICK.h"
#include"STD_Types.h"
#include "LCD.h"
#include "ADC.h"
#include "LM35.h"


int main(void){
	 Init_Rcc();
	 Enable_peripheral(  RCC_AHB1ENR_GPIOA	,RCC_AHB1 );
	 ADC_Init() ;
	 MSTK_voidInit();
//	 MSTK_voidIntState();
	 int i;
	 for(i=1;i<=11;i++){
		 MGPIO_vSetPinMode(GPIO_PORTA, i, GPIO_MODE_OUTPUT);
	 }

	 LCD_voidInit();
	 float32 tempr=0;

    while (1)

    {


      	tempr = ADC_ReadChannel(0);
      	LCD_enuWritenumber(LCD_u8NUM_0,ADC_to_Temperature(tempr));
      	MSTK_voidDelayMsec(500);
      	LCD_enuWriteCmd (LCD_u8NUM_0 ,LCD_u8CLEAR);

    }

    return 0;
}
