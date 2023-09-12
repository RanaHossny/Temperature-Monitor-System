#include "MCAL/RCC/RCC.h"
#include "MCAL/GPIO/GPIO.h"
#include "MCAL/SYSTICK/SYSTICK.h"
#include "MCAL/UART/UART.h"
#include"LIB/STD_Types.h"
#include "HAL/LCD/LCD.h"
#include "MCAL/ADC/ADC.h"
#include "HAL/LM35/LM35.h"
#include "HAL/Motor_Driver/HMotor_Int.h"

int main(void){
	 Init_Rcc();
	 Enable_peripheral( RCC_AHB1ENR_GPIOA,RCC_AHB1);
	 Enable_peripheral( RCC_AHB1ENR_GPIOB,RCC_AHB1);
	 Enable_peripheral(RCC_APB2ENR_USART1,RCC_APB2);
	 Enable_peripheral(RCC_APB2ENR_SYSCFG,RCC_APB2);
	 ADC_Init() ;

	 MSTK_voidInit();
	 UART_Config* UART_test1;

	         UART_test1->USART_Mode=UART_MODE_TX_RX;
	         UART_test1->BaudRate=UART_BaudRate_9600;
	         UART_test1->Payload_Length=UART_Length_8B;
	         UART_test1->Parity=UART_Parity__NONE;
	         UART_test1->StopBits=UART_StopBits__1;
	         UART_test1->HwFlowCtl=UART_NO_Flow_Control;
	         UART_test1->IRQ_Enable=UART_IRQ_Enable_NONE;

	        MUART_vInit(UART_test1);

	// MSTK_voidIntState();
	 int i;
	 for(i=1;i<=11;i++){
		 MGPIO_vSetPinMode(GPIO_PORTA, i, GPIO_MODE_OUTPUT);
	 }
	 MGPIO_vSetPinMode(GPIO_PORTB, 1, GPIO_MODE_OUTPUT);
	 MGPIO_vSetPinMode(GPIO_PORTB, 2, GPIO_MODE_OUTPUT);

	 MGPIO_vSetPinMode(GPIO_PORTB, 6, GPIO_MODE_ALTFUN); //Uart1 Tx
	 MGPIO_vSetAlternativeFunction(GPIO_PORTB,6,7);

	 Motor_On(GPIO_PORTB,1,GPIO_PORTB,2);



	 LCD_voidInit();
	 float32 tempr=0;


	 char* Stat="    HighTemp";
	 char* Stat2="    AutoParking";
	 char* data = "K";

    while (1)

    {
    	double x=0;
    	double y=0;
    	double z=0;

      	tempr = ADC_ReadChannel(0);

      	LCD_enuWritenumber(LCD_u8NUM_0,100+ADC_to_Temperature(tempr));
      	while (y<20){MSTK_voidDelayMsec(500); y++;}
      	LCD_enuWriteCmd (LCD_u8NUM_0 ,LCD_u8CLEAR);
      	if(ADC_to_Temperature(tempr)>=90){
      		LCD_enuWriteData(LCD_u8NUM_0,Stat,12);
      		MUART_vSendData("1",2);
      		while (x<100){MSTK_voidDelayMsec(500); x++;}
      		tempr = ADC_ReadChannel(0);
      		LCD_enuWritenumber(LCD_u8NUM_0,100+ADC_to_Temperature(tempr));
      		if(ADC_to_Temperature(tempr)>=90){
  				MUART_vSendData("3",2);
  		      	LCD_enuWriteCmd (LCD_u8NUM_0 ,LCD_u8CLEAR);
      			LCD_enuWriteData(LCD_u8NUM_0,Stat2,15);

      		}
      		else if(ADC_to_Temperature(tempr)<90){
      			MUART_vSendData("2",2);
      		}
      	}
    }



    return 0;
}

