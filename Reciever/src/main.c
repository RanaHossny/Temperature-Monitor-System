#include "./LIB/BIT_Math.h"
#include "./LIB/STD_Types.h"

#include "MCAL/GPIO/GPIO.h"
#include "MCAL/RCC/RCC.h"
#include "MCAL/SYSTICK/SYSTICK.h"
#include "MCAL/UART/UART.h"
#include "HAL/Motor_Driver/HMotor_Int.h"

int main(void){
	Init_Rcc();
	Enable_peripheral(RCC_AHB1ENR_GPIOA,RCC_AHB1);
	Enable_peripheral(RCC_AHB1ENR_GPIOB,RCC_AHB1);
	Enable_peripheral(RCC_APB2ENR_USART1,RCC_APB2);
	Enable_peripheral(RCC_APB2ENR_SYSCFG,RCC_APB2);

	MGPIO_vSetPinMode(GPIO_PORTA,0,GPIO_MODE_OUTPUT);
	MGPIO_vSetPinMode(GPIO_PORTA,1,GPIO_MODE_OUTPUT);
	MGPIO_vSetPinMode(GPIO_PORTA,2,GPIO_MODE_OUTPUT);
	MGPIO_vSetPinMode(GPIO_PORTA,3,GPIO_MODE_OUTPUT);






	MGPIO_vSetPinMode(GPIO_PORTB,7,GPIO_MODE_ALTFUN);
	MGPIO_vSetAlternativeFunction(GPIO_PORTB,7,7);

	//MGPIO_vSetPinValue(GPIO_PORTA,0,GPIO_HIGH);
	 UART_Config* UART_test1;

	         UART_test1->USART_Mode=UART_MODE_TX_RX;
	         UART_test1->BaudRate=UART_BaudRate_9600;
	         UART_test1->Payload_Length=UART_Length_8B;
	         UART_test1->Parity=UART_Parity__NONE;
	         UART_test1->StopBits=UART_StopBits__1;
	         UART_test1->HwFlowCtl=UART_NO_Flow_Control;
	         UART_test1->IRQ_Enable=UART_IRQ_Enable_NONE;

	        MUART_vInit(UART_test1);


	        Motor_On(GPIO_PORTA,2,GPIO_PORTA,3);


	while(1){
		uint8 recv=MUART_u8ReadData();
			if(recv=='1'){
				Motor_On(GPIO_PORTA,0,GPIO_PORTA,1); //Fan On
			}
			else if (recv=='2'){
				Motor_Off(GPIO_PORTA,0,GPIO_PORTA,1); //Fan Off
			    Motor_On(GPIO_PORTA,2,GPIO_PORTA,3);
			}
			else if(recv=='3'){
				Motor_Off(GPIO_PORTA,2,GPIO_PORTA,3);  //Car Motor Off
			}
			}
	}




