#ifndef MCAL_MRCC_MRCC_INT_H_
#define MCAL_MRCC_MRCC_INT_H_
//AHB1
#define GPIOA_EN 0
#define GPIOB_EN 1
#define GPIOC_EN 2
#define GPIOD_EN 3
#define GPIOE_EN 4
#define GPIOH_EN 7
#define CRC_EN 12
#define DMA1_EN 21
#define DMA2_EN 22
// AHB2
#define OTGFS_EN 23
// APB1
#define TIM2_EN 24
#define TIM3_EN 1+24
#define TIM4_EN 2+24
#define TIM5_EN 3+24
#define WWDG_EN 11+24
#define SPI2_EN 14+24
#define SPI3_EN 15+24
#define UART2_EN 17+24
#define I2C1_EN 21+24
#define I2C2_EN 22+24
#define I2C3_EN 23+24
#define PWR_EN 28+24
//APB2
#define TIM1_EN 53
#define USART1_EN 53+4
#define USART6_EN 53+5
#define ADC1_EN 53+8
#define SDIO_EN 11+53
#define SPI1_EN 12+53
#define SPI4_EN 13+53
#define SYSCFG_EN 14+53
#define TIM9_EN 16+53
#define TIM10_EN 17+53
#define TIM11_EN 18+53


void MRCC_vInit(void);
void MRCC_vEnableCLock(u8 A_u8PortNo);
void MRCC_vDisableClock(u8 A_u8PortNo);

#endif /* MCAL_MRCC_MRCC_INT_H_ */
