################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/ADC.c \
../Core/Src/GPIO.c \
../Core/Src/LCD.c \
../Core/Src/LCD_cfg.c \
../Core/Src/LM35.c \
../Core/Src/RCC.c \
../Core/Src/SYSTICK.c \
../Core/Src/UART.c \
../Core/Src/UART_CFG.c \
../Core/Src/main.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f4xx.c 

OBJS += \
./Core/Src/ADC.o \
./Core/Src/GPIO.o \
./Core/Src/LCD.o \
./Core/Src/LCD_cfg.o \
./Core/Src/LM35.o \
./Core/Src/RCC.o \
./Core/Src/SYSTICK.o \
./Core/Src/UART.o \
./Core/Src/UART_CFG.o \
./Core/Src/main.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f4xx.o 

C_DEPS += \
./Core/Src/ADC.d \
./Core/Src/GPIO.d \
./Core/Src/LCD.d \
./Core/Src/LCD_cfg.d \
./Core/Src/LM35.d \
./Core/Src/RCC.d \
./Core/Src/SYSTICK.d \
./Core/Src/UART.d \
./Core/Src/UART_CFG.d \
./Core/Src/main.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/ADC.cyclo ./Core/Src/ADC.d ./Core/Src/ADC.o ./Core/Src/ADC.su ./Core/Src/GPIO.cyclo ./Core/Src/GPIO.d ./Core/Src/GPIO.o ./Core/Src/GPIO.su ./Core/Src/LCD.cyclo ./Core/Src/LCD.d ./Core/Src/LCD.o ./Core/Src/LCD.su ./Core/Src/LCD_cfg.cyclo ./Core/Src/LCD_cfg.d ./Core/Src/LCD_cfg.o ./Core/Src/LCD_cfg.su ./Core/Src/LM35.cyclo ./Core/Src/LM35.d ./Core/Src/LM35.o ./Core/Src/LM35.su ./Core/Src/RCC.cyclo ./Core/Src/RCC.d ./Core/Src/RCC.o ./Core/Src/RCC.su ./Core/Src/SYSTICK.cyclo ./Core/Src/SYSTICK.d ./Core/Src/SYSTICK.o ./Core/Src/SYSTICK.su ./Core/Src/UART.cyclo ./Core/Src/UART.d ./Core/Src/UART.o ./Core/Src/UART.su ./Core/Src/UART_CFG.cyclo ./Core/Src/UART_CFG.d ./Core/Src/UART_CFG.o ./Core/Src/UART_CFG.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/stm32f4xx_hal_msp.cyclo ./Core/Src/stm32f4xx_hal_msp.d ./Core/Src/stm32f4xx_hal_msp.o ./Core/Src/stm32f4xx_hal_msp.su ./Core/Src/stm32f4xx_it.cyclo ./Core/Src/stm32f4xx_it.d ./Core/Src/stm32f4xx_it.o ./Core/Src/stm32f4xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f4xx.cyclo ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/system_stm32f4xx.su

.PHONY: clean-Core-2f-Src

