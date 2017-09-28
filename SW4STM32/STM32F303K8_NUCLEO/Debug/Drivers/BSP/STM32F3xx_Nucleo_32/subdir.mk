################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/BSP/STM32F3xx_Nucleo_32/stm32f3xx_nucleo_32.c 

OBJS += \
./Drivers/BSP/STM32F3xx_Nucleo_32/stm32f3xx_nucleo_32.o 

C_DEPS += \
./Drivers/BSP/STM32F3xx_Nucleo_32/stm32f3xx_nucleo_32.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/STM32F3xx_Nucleo_32/stm32f3xx_nucleo_32.o: D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/BSP/STM32F3xx_Nucleo_32/stm32f3xx_nucleo_32.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32F303x8 -DUSE_STM32F3XX_NUCLEO_32 -DUSE_HAL_DRIVER -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Projects/STM32F303K8-Nucleo/Examples/UART/UART_TwoBoards_ComPolling/Inc" -ID:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_hal_adc.h -ID:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_hal_gpio.h -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/CMSIS/Device/ST/STM32F3xx/Include" -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Inc" -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/BSP/STM32F3xx_Nucleo_32" -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/CMSIS/Include" -I"C:/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.win32_1.13.3.201707031232/tools/compiler/arm-none-eabi/include" -I"C:/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.win32_1.13.3.201707031232/tools/compiler/lib/gcc/arm-none-eabi/5.4.1/include" -I"C:/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.win32_1.13.3.201707031232/tools/compiler/lib/gcc/arm-none-eabi/5.4.1/include-fixed"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


