#include "./LIB/BIT_Math.h"
#include "./LIB/STD_Types.h"

#include "./MCAL/MGPIO/MGPIO_Int.h"
#include "./MCAL/MNVIC/MNVIC_Int.h"
#include "./MCAL/MRCC/MRCC_Int.h"
#include "./MCAL/MSYSTICK/MSYSTICK_Int.h"
#include "./MCAL/MUSART/MUSART_Int.h"
volatile u8 counter=0;
void callback(void){
	u8 recv=MUSART_u8ReadData();
	if(recv==1){
		MGPIO_vSetPinValue(GPIO_PORTA,0,GPIO_HIGH);
		MSYSTICK_vDelayMsec(50);
		counter++;
	}
	else{
		counter=0;
	}
}
int main(int argc,char ** argv){
	MRCC_vInit();
	MRCC_vEnableCLock(GPIOA_EN);
	MRCC_vEnableCLock(GPIOB_EN);
	MRCC_vEnableCLock(USART1_EN);
	MRCC_vEnableCLock(SYSCFG_EN);
	
	MGPIO_vSetPinMode(GPIO_PORTA,0,GPIO_MODE_OUTPUT);
	MGPIO_vSetPinOutputSpeed(GPIO_PORTA,0,GPIO_MEDIUM_SPEED);
	MGPIO_vSetPinOutputType(GPIO_PORTA,0,GPIO_PUSHPULL);
	

	
	//MEXTI_vEnableLine(ln0,PortA);
	//MEXTI_vExternalInterruptMask(ln0,ENNABLE);
	//MEXTI_vTriggerSelection(ln0,RISINGEDGE);
	//MEXTI_vSetEXT0Callback(callback);

	
	MGPIO_vSetPinMode(GPIO_PORTB,6,GPIO_MODE_ALTFUN);
	MGPIO_vSetAlternativeFunction(GPIO_PORTB,6,AF7);
	MGPIO_vSetPinMode(GPIO_PORTB,7,GPIO_MODE_ALTFUN);
	MGPIO_vSetAlternativeFunction(GPIO_PORTB,7,AF7);
	
	//MGPIO_vSetPinValue(GPIO_PORTA,0,GPIO_HIGH);
  MUSART_voidInit();
	MUSART_voidEnable();
	MUSART_voidInterruptEnable();
	MUSART_voidCallBack(callback);

	
	MNVIC_vInterruptSetEnable(37);
	MNVIC_vsetGroupMode(MNVIC_G16_S0);
	MNVIC_vSetInterruptPriority(37,0,0);
while(1){
		if (counter==50){
			u8 c = 1;
		  MUSART_voidSendData(&c,1);
		 }
		}
	}