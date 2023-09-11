/*
 * MRCC_PROC.c
 *
 *  Created on: Aug 10, 2023
 *      Author: moroz
 */


#include "../../LIB/BIT_Math.h"
#include "../../LIB/STD_Types.h"

#include "MRCC_Int.h"
#include "MRCC_Private.h"
#include "MRCC_Config.h"

void MRCC_vInit(void){
// CSS on/off
// HSE_BYP CLR -> Oscillator enable (not bypassed), SET -> bypassed
CLR_BIT(RCC -> CR,HSEBYP);
// Select clock switch (HSI/HSE/PLL)
SET_BIT(RCC -> CFGR,SW0);
CLR_BIT(RCC -> CFGR,SW1);
// Enable selected clock (HSI on/HSE on/PLL on)
#if RCC_HSE_ENABLE == ENABLEE
SET_BIT(RCC -> CR ,HSEON);
#endif
}
void MRCC_vEnableCLock(u8 A_u8PortNo){
	switch(A_u8PortNo){
	case GPIOA_EN:
		SET_BIT(RCC -> AHB1ENR,GPIOA_EN);
		break;
	case GPIOB_EN:
		SET_BIT(RCC -> AHB1ENR,GPIOB_EN);
		break;
	case GPIOC_EN:
		SET_BIT(RCC -> AHB1ENR,GPIOC_EN);
		break;
	case GPIOD_EN:
		SET_BIT(RCC -> AHB1ENR,GPIOD_EN);
		break;
	case GPIOE_EN:
		SET_BIT(RCC -> AHB1ENR,GPIOE_EN);
		break;
	case GPIOH_EN:
		SET_BIT(RCC -> AHB1ENR,GPIOH_EN);
		break;
	case CRC_EN:
		SET_BIT(RCC -> AHB1ENR,CRC_EN);
		break;
	case DMA1_EN:
		SET_BIT(RCC -> AHB1ENR,DMA1_EN);
		break;
	case DMA2_EN:
		SET_BIT(RCC -> AHB1ENR,DMA2_EN);
		break;
		//
	case OTGFS_EN:
		SET_BIT(RCC -> AHB2ENR,7);
		break;
		//
	case TIM2_EN:
		SET_BIT(RCC -> APB1ENR,(TIM2_EN-24));
		break;
	case TIM3_EN:
		SET_BIT(RCC -> APB1ENR,(TIM3_EN-24));
		break;
	case TIM4_EN:
		SET_BIT(RCC -> APB1ENR,(TIM4_EN-24));
		break;
	case TIM5_EN:
		SET_BIT(RCC -> APB1ENR,(TIM5_EN-24));
		break;
	case WWDG_EN:
		SET_BIT(RCC -> APB1ENR,(WWDG_EN-24));
		break;
	case SPI2_EN:
		SET_BIT(RCC -> APB1ENR,(SPI2_EN-24));
		break;
	case SPI3_EN:
		SET_BIT(RCC -> APB1ENR,(SPI3_EN-24));
		break;
	case UART2_EN:
		SET_BIT(RCC -> APB1ENR,(UART2_EN-24));
		break;
	case I2C1_EN:
		SET_BIT(RCC -> APB1ENR,(I2C1_EN-24));
		break;
	case I2C2_EN:
		SET_BIT(RCC -> APB1ENR,(I2C2_EN-24));
		break;
	case I2C3_EN:
		SET_BIT(RCC -> APB1ENR,(I2C3_EN-24));
		break;
	case PWR_EN:
		SET_BIT(RCC -> APB1ENR,(PWR_EN-24));
		break;
	//
	case TIM1_EN:
		SET_BIT(RCC -> APB2ENR,(TIM1_EN-53));
		break;
	case USART1_EN:
		SET_BIT(RCC -> APB2ENR,(USART1_EN-53));
		break;
	case USART6_EN:
		SET_BIT(RCC -> APB2ENR,(USART6_EN-53));
		break;
	case ADC1_EN:
		SET_BIT(RCC -> APB2ENR,(ADC1_EN-53));
		break;
	case SDIO_EN:
		SET_BIT(RCC -> APB2ENR,(SDIO_EN-53));
		break;
	case SPI1_EN:
		SET_BIT(RCC -> APB2ENR,(SPI1_EN-53));
		break;
	case SPI4_EN:
		SET_BIT(RCC -> APB2ENR,(SPI4_EN-53));
		break;
	case SYSCFG_EN:
		SET_BIT(RCC -> APB2ENR,(SYSCFG_EN-53));
		break;
	case TIM9_EN:
		SET_BIT(RCC -> APB2ENR ,(TIM9_EN-53));
		break;
	case TIM10_EN:
		SET_BIT(RCC -> APB2ENR,(TIM10_EN-53));
		break;
	case TIM11_EN:
		SET_BIT(RCC-> APB2ENR,(TIM11_EN-53));
		break;
	default:
		break;
	}

}
void MRCC_vDisableClock(u8 A_u8PortNo){
	switch(A_u8PortNo){
	case GPIOA_EN:
		CLR_BIT(RCC -> AHB1ENR,GPIOA_EN);
		break;
	case GPIOB_EN:
		CLR_BIT(RCC -> AHB1ENR,GPIOB_EN);
		break;
	case GPIOC_EN:
		CLR_BIT(RCC -> AHB1ENR,GPIOC_EN);
		break;
	case GPIOD_EN:
		CLR_BIT(RCC -> AHB1ENR,GPIOD_EN);
		break;
	case GPIOE_EN:
		CLR_BIT(RCC -> AHB1ENR,GPIOE_EN);
		break;
	case GPIOH_EN:
		CLR_BIT(RCC -> AHB1ENR,GPIOH_EN);
		break;
	case CRC_EN:
		CLR_BIT(RCC -> AHB1ENR,CRC_EN);
		break;
	case DMA1_EN:
		CLR_BIT(RCC -> AHB1ENR,DMA1_EN);
		break;
	case DMA2_EN:
		CLR_BIT(RCC -> AHB1ENR,DMA2_EN);
		break;

	case OTGFS_EN:
		CLR_BIT(RCC -> AHB2ENR,7);
		break;
		//
	case TIM2_EN:
		CLR_BIT(RCC -> APB1ENR,(TIM2_EN-24));
		break;
	case TIM3_EN:
		CLR_BIT(RCC -> APB1ENR,(TIM3_EN-24));
		break;
	case TIM4_EN:
		CLR_BIT(RCC -> APB1ENR,(TIM4_EN-24));
		break;
	case TIM5_EN:
		CLR_BIT(RCC -> APB1ENR,(TIM5_EN-24));
		break;
	case WWDG_EN:
		CLR_BIT(RCC -> APB1ENR,(WWDG_EN-24));
		break;
	case SPI2_EN:
		CLR_BIT(RCC -> APB1ENR,(SPI2_EN-24));
		break;
	case SPI3_EN:
		CLR_BIT(RCC -> APB1ENR,(SPI3_EN-24));
		break;
	case UART2_EN:
		CLR_BIT(RCC -> APB1ENR,(UART2_EN-24));
		break;
	case I2C1_EN:
		CLR_BIT(RCC -> APB1ENR,(I2C1_EN-24));
		break;
	case I2C2_EN:
		CLR_BIT(RCC -> APB1ENR,(I2C2_EN-24));
		break;
	case I2C3_EN:
		CLR_BIT(RCC -> APB1ENR,(I2C3_EN-24));
		break;
	case PWR_EN:
		CLR_BIT(RCC -> APB1ENR,(PWR_EN-24));
		break;
	//
	case TIM1_EN:
		CLR_BIT(RCC -> APB2ENR,(TIM1_EN-53));
		break;
	case USART1_EN:
		CLR_BIT(RCC -> APB2ENR,(USART1_EN-53));
		break;
	case USART6_EN:
		CLR_BIT(RCC -> APB2ENR,(USART6_EN-53));
		break;
	case ADC1_EN:
		CLR_BIT(RCC -> APB2ENR,(ADC1_EN-53));
		break;
	case SDIO_EN:
		CLR_BIT(RCC -> APB2ENR,(SDIO_EN-53));
		break;
	case SPI1_EN:
		CLR_BIT(RCC -> APB2ENR,(SPI1_EN-53));
		break;
	case SPI4_EN:
		CLR_BIT(RCC -> APB2ENR,(SPI4_EN-53));
		break;
	case SYSCFG_EN:
		CLR_BIT(RCC -> APB2ENR,(SYSCFG_EN-53));
		break;
	case TIM9_EN:
		CLR_BIT(RCC -> APB2ENR ,(TIM9_EN-53));
		break;
	case TIM10_EN:
		CLR_BIT(RCC -> APB2ENR,(TIM10_EN-53));
		break;
	case TIM11_EN:
		CLR_BIT(RCC-> APB2ENR,(TIM11_EN-53));
		break;
	default:
		break;
	}
}
