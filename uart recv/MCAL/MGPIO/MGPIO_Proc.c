/*
 * MGPIO_Proc.c
 *
 *  Created on: Aug 10, 2023
 *      Author: moroz
 */
#include "../../LIB/BIT_Math.h"
#include "../../LIB/STD_Types.h"

#include "MGPIO_Int.h"
#include "MGPIO_Private.h"
#include "MGPIO_Config.h"
void MGPIO_vSetPinMode(u8 A_u8PortId, u8 A_u8PinNo , u8 A_u8Mode){
	if(A_u8Mode == GPIO_MODE_INPUT){
		switch (A_u8PortId){
				case GPIO_PORTA:
					GPIOA -> MODER &= ~(0b11 << (A_u8PinNo<<1));
					GPIOA -> MODER |=(A_u8Mode<< (A_u8PinNo<<1));
					break;
				case GPIO_PORTB:
					GPIOB -> MODER &= ~(0b11 << (A_u8PinNo<<1));
					GPIOB -> MODER |=(A_u8Mode<< (A_u8PinNo<<1));
					break;
				case GPIO_PORTC:
					GPIOA -> MODER &= ~(0b11 << (A_u8PinNo<<1));
					GPIOA -> MODER |=(A_u8Mode<< (A_u8PinNo<<1));
					break;
				default:
					break;
		}
	}
	else if(A_u8Mode == GPIO_MODE_OUTPUT){
			switch (A_u8PortId){
					case GPIO_PORTA:
						GPIOA -> MODER &= ~(0b11 << (A_u8PinNo<<1));
						GPIOA -> MODER |=(A_u8Mode<< (A_u8PinNo<<1));
						break;
					case GPIO_PORTB:
						GPIOB -> MODER &= ~(0b11 << (A_u8PinNo<<1));
						GPIOB -> MODER |=(A_u8Mode<< (A_u8PinNo<<1));
						break;
					case GPIO_PORTC:
						GPIOC -> MODER &= ~(0b11 << (A_u8PinNo<<1));
						GPIOC -> MODER |=(A_u8Mode<< (A_u8PinNo<<1));
						break;
					default:
						break;
			}
		}
	else if(A_u8Mode == GPIO_MODE_ALTFUN){
			switch (A_u8PortId){
					case GPIO_PORTA:
						GPIOA -> MODER &= ~(0b11 << (A_u8PinNo<<1));
						GPIOA -> MODER |=(A_u8Mode<< (A_u8PinNo<<1));
						break;
					case GPIO_PORTB:
						GPIOB -> MODER &= ~(0b11 << (A_u8PinNo<<1));
						GPIOB -> MODER |=(A_u8Mode<< (A_u8PinNo<<1));
						break;
					case GPIO_PORTC:
						GPIOC -> MODER &= ~(0b11 << (A_u8PinNo<<1));
						GPIOC -> MODER |=(A_u8Mode<< (A_u8PinNo<<1));
						break;
					default:
						break;
			}
		}
	else if(A_u8Mode == GPIO_MODE_ANALOG){
				switch (A_u8PortId){
						case GPIO_PORTA:
							GPIOA -> MODER &= ~(0b11 << (A_u8PinNo<<1));
							GPIOA -> MODER |=(A_u8Mode<< (A_u8PinNo<<1));
							break;
						case GPIO_PORTB:
							GPIOB -> MODER &= ~(0b11 << (A_u8PinNo<<1));
							GPIOB -> MODER |=(A_u8Mode<< (A_u8PinNo<<1));
							break;
						case GPIO_PORTC:
							GPIOC -> MODER &= ~(0b11 << (A_u8PinNo<<1));
							GPIOC -> MODER |=(A_u8Mode<< (A_u8PinNo<<1));
							break;
						default:
							break;
				}
			}
	else {/*error*/}

}
void MGPIO_vSetPinOutputType(u8 A_u8PortId, u8 A_u8PinNo , u8 A_u8OutputType){
	if(A_u8OutputType==GPIO_OPENDRAIN){
		switch (A_u8PortId){
				case GPIO_PORTA:
					SET_BIT(GPIOA -> OTYPER , A_u8PinNo);
					break;
				case GPIO_PORTB:
					SET_BIT(GPIOB -> OTYPER , A_u8PinNo);
					break;
				case GPIO_PORTC:
					SET_BIT(GPIOC -> OTYPER , A_u8PinNo);
					break;
				default:
					break;
		}
	}
	if(A_u8OutputType==GPIO_PUSHPULL){
			switch (A_u8PortId){
					case GPIO_PORTA:
						CLR_BIT(GPIOA -> OTYPER , A_u8PinNo);
						break;
					case GPIO_PORTB:
						CLR_BIT(GPIOB -> OTYPER , A_u8PinNo);
						break;
					case GPIO_PORTC:
						CLR_BIT(GPIOC -> OTYPER , A_u8PinNo);
						break;
					default:
						break;
		}
	}
}
void MGPIO_vSetPinOutputSpeed(u8 A_u8PortId, u8 A_u8PinNo , u8 A_u8OutputSpeed){
	if(A_u8OutputSpeed == GPIO_LOW_SPEED){
		switch (A_u8PortId){
				case GPIO_PORTA:
					GPIOA -> OSPEEDER &= ~(0b11 << (A_u8PinNo<<1));
					GPIOA -> OSPEEDER |=(A_u8OutputSpeed << (A_u8PinNo<<1));
					break;
				case GPIO_PORTB:
					GPIOB -> OSPEEDER &= ~(0b11 << (A_u8PinNo<<1));
					GPIOB -> OSPEEDER |=(A_u8OutputSpeed << (A_u8PinNo<<1));
					break;
				case GPIO_PORTC:
					GPIOA -> OSPEEDER &= ~(0b11 << (A_u8PinNo<<1));
					GPIOA -> OSPEEDER |=(A_u8OutputSpeed << (A_u8PinNo<<1));
					break;
				default:
					break;
		}
	}
	else if(A_u8OutputSpeed == GPIO_MEDIUM_SPEED){
			switch (A_u8PortId){
					case GPIO_PORTA:
						GPIOA -> OSPEEDER &= ~(0b11 << (A_u8PinNo<<1));
						GPIOA -> OSPEEDER |=(A_u8OutputSpeed << (A_u8PinNo<<1));
						break;
					case GPIO_PORTB:
						GPIOB -> OSPEEDER &= ~(0b11 << (A_u8PinNo<<1));
						GPIOB -> OSPEEDER |=(A_u8OutputSpeed << (A_u8PinNo<<1));
						break;
					case GPIO_PORTC:
						GPIOC -> OSPEEDER &= ~(0b11 << (A_u8PinNo<<1));
						GPIOC -> OSPEEDER |=(A_u8OutputSpeed << (A_u8PinNo<<1));
						break;
					default:
						break;
			}
		}
	else if(A_u8OutputSpeed == GPIO_HIGH_SPEED){
			switch (A_u8PortId){
					case GPIO_PORTA:
						GPIOA -> OSPEEDER &= ~(0b11 << (A_u8PinNo<<1));
						GPIOA -> OSPEEDER |=(A_u8OutputSpeed << (A_u8PinNo<<1));
						break;
					case GPIO_PORTB:
						GPIOB -> OSPEEDER &= ~(0b11 << (A_u8PinNo<<1));
						GPIOB -> OSPEEDER |=(A_u8OutputSpeed << (A_u8PinNo<<1));
						break;
					case GPIO_PORTC:
						GPIOC -> OSPEEDER &= ~(0b11 << (A_u8PinNo<<1));
						GPIOC -> OSPEEDER |=(A_u8OutputSpeed << (A_u8PinNo<<1));
						break;
					default:
						break;
			}
		}
	else if(A_u8OutputSpeed  == GPIO_VERYHIGH_SPEED){
				switch (A_u8PortId){
						case GPIO_PORTA:
							GPIOA -> OSPEEDER &= ~(0b11 << (A_u8PinNo<<1));
							GPIOA -> OSPEEDER |=(A_u8OutputSpeed << (A_u8PinNo<<1));
							break;
						case GPIO_PORTB:
							GPIOB -> OSPEEDER &= ~(0b11 << (A_u8PinNo<<1));
							GPIOB -> OSPEEDER |=(A_u8OutputSpeed << (A_u8PinNo<<1));
							break;
						case GPIO_PORTC:
							GPIOC -> OSPEEDER &= ~(0b11 << (A_u8PinNo<<1));
							GPIOC -> OSPEEDER |=(A_u8OutputSpeed << (A_u8PinNo<<1));
							break;
						default:
							break;
				}
			}
	else {/*error*/}

}
void MGPIO_vSetPinInputPull(u8 A_u8PortId, u8 A_u8PinNo , u8 A_u8PullType){
	if(A_u8PullType == GPIO_NO_PULL){
		switch (A_u8PortId){
				case GPIO_PORTA:
					GPIOA -> PUPDR &= ~(0b11 << (A_u8PinNo<<1));
					GPIOA -> PUPDR |=(A_u8PullType << (A_u8PinNo<<1));
					break;
				case GPIO_PORTB:
					GPIOB -> PUPDR &= ~(0b11 << (A_u8PinNo<<1));
					GPIOB -> PUPDR |=(A_u8PullType << (A_u8PinNo<<1));
					break;
				case GPIO_PORTC:
					GPIOA -> PUPDR &= ~(0b11 << (A_u8PinNo<<1));
					GPIOA -> PUPDR |=(A_u8PullType << (A_u8PinNo<<1));
					break;
				default:
					break;
		}
	}
	else if(A_u8PullType == GPIO_PULL_UP ){
			switch (A_u8PortId){
					case GPIO_PORTA:
						GPIOA -> PUPDR &= ~(0b11 << (A_u8PinNo<<1));
						GPIOA -> PUPDR |=(A_u8PullType << (A_u8PinNo<<1));
						break;
					case GPIO_PORTB:
						GPIOB -> PUPDR &= ~(0b11 << (A_u8PinNo<<1));
						GPIOB -> PUPDR |=(A_u8PullType << (A_u8PinNo<<1));
						break;
					case GPIO_PORTC:
						GPIOC -> PUPDR &= ~(0b11 << (A_u8PinNo<<1));
						GPIOC -> PUPDR |=(A_u8PullType << (A_u8PinNo<<1));
						break;
					default:
						break;
			}
		}
	else if(A_u8PullType == GPIO_PULL_DOWN){
			switch (A_u8PortId){
					case GPIO_PORTA:
						GPIOA -> PUPDR &= ~(0b11 << (A_u8PinNo<<1));
						GPIOA -> PUPDR |=(A_u8PullType << (A_u8PinNo<<1));
						break;
					case GPIO_PORTB:
						GPIOB -> PUPDR &= ~(0b11 << (A_u8PinNo<<1));
						GPIOB -> PUPDR |=(A_u8PullType << (A_u8PinNo<<1));
						break;
					case GPIO_PORTC:
						GPIOC -> PUPDR &= ~(0b11 << (A_u8PinNo<<1));
						GPIOC -> PUPDR |=(A_u8PullType << (A_u8PinNo<<1));
						break;
					default:
						break;
			}
		}
	else {/*error*/}
}
u8 MGPIO_u8GetPinValue(u8 A_u8PortId,u8 A_u8PinNo){
	u8 L_u8PinValue=0;
	switch(A_u8PortId){
	case GPIO_PORTA:
		L_u8PinValue=GET_BIT(GPIOA->IDR,A_u8PinNo);
			break;
		case GPIO_PORTB:
			L_u8PinValue=GET_BIT(GPIOB->IDR,A_u8PinNo);
			break;
		case GPIO_PORTC:
			L_u8PinValue=GET_BIT(GPIOC->IDR,A_u8PinNo);
			break;
		default:
			break;

	}
return L_u8PinValue;
}
void MGPIO_vSetPinValue(u8 A_u8PortId, u8 A_u8PinNo , u8 A_u8PinVal){
	if(A_u8PinVal == GPIO_HIGH){
		switch(A_u8PortId){
		case GPIO_PORTA:
			    SET_BIT(GPIOA->ODR,A_u8PinNo);
				break;
			case GPIO_PORTB:
				SET_BIT(GPIOB->ODR,A_u8PinNo);
				break;
			case GPIO_PORTC:
				SET_BIT(GPIOC->ODR,A_u8PinNo);
				break;
			default:
				break;

		}
	}
	else if(A_u8PinVal == GPIO_LOW){
		switch(A_u8PortId){
			case GPIO_PORTA:
				    CLR_BIT(GPIOA->ODR,A_u8PinNo);
					break;
				case GPIO_PORTB:
					CLR_BIT(GPIOB->ODR,A_u8PinNo);
					break;
				case GPIO_PORTC:
					CLR_BIT(GPIOC->ODR,A_u8PinNo);
					break;
				default:
					break;

			}
	}
}
void MGPIO_vSetPinValue_fast(u8 A_u8PortId, u8 A_u8PinNo , u8 A_u8PinVal){
	if(A_u8PinVal == GPIO_HIGH){
		switch(A_u8PortId){
		case GPIO_PORTA:
			    SET_BIT(GPIOA->BSRR,A_u8PinNo);
				break;
			case GPIO_PORTB:
				SET_BIT(GPIOB->BSRR,A_u8PinNo);
				break;
			case GPIO_PORTC:
				SET_BIT(GPIOC->BSRR,A_u8PinNo);
				break;
			default:
				break;

		}
	}
	else if(A_u8PinVal == GPIO_LOW){
		switch(A_u8PortId){
			case GPIO_PORTA:
				    CLR_BIT(GPIOA->BSRR,A_u8PinNo);
					break;
				case GPIO_PORTB:
					CLR_BIT(GPIOB->BSRR,A_u8PinNo);
					break;
				case GPIO_PORTC:
					CLR_BIT(GPIOC->BSRR,A_u8PinNo);
					break;
				default:
					break;

			}
	}
}//BSRR
void MGPIO_vSetAlternativeFunction(u8 A_u8PortId, u8 A_u8PinNo , u8 A_u8AltFun){
	if(A_u8PinNo  <=7U)
		{
			switch(A_u8PortId  )
			{
				 case GPIO_PORTA  : GPIOA->AFRL |=(u32)(A_u8AltFun <<(4U* A_u8PinNo )); break ;
				 case GPIO_PORTB  : GPIOB->AFRL |=(u32)(A_u8AltFun <<(4U* A_u8PinNo )); break ;
				 case GPIO_PORTC  : GPIOC->AFRL |=(u32)(A_u8AltFun <<(4U* A_u8PinNo )); break ;

				 default : break ;
			}

		}

		else
		{
		switch(A_u8PortId )
			{
				 case GPIO_PORTA  : GPIOA->AFRH |=(u32)(A_u8AltFun <<(4U* ( A_u8PinNo  % 8U))); break ;
				 case GPIO_PORTB  : GPIOB->AFRH |=(u32)(A_u8AltFun <<(4U* ( A_u8PinNo  % 8U))); break ;
				 case GPIO_PORTC  : GPIOC->AFRH |=(u32)(A_u8AltFun <<(4U* ( A_u8PinNo  % 8U))); break ;
				 default : break ;
			}


		}
}


