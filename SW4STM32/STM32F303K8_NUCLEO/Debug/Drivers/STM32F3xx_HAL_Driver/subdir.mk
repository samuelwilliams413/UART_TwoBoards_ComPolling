################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal.c \
D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_adc.c \
D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_adc_ex.c \
D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_cortex.c \
D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_dma.c \
D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_gpio.c \
D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_pwr.c \
D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_pwr_ex.c \
D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_rcc.c \
D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_rcc_ex.c \
D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_uart.c \
D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_uart_ex.c 

OBJS += \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_adc.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_adc_ex.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_cortex.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_dma.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_gpio.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_pwr.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_pwr_ex.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_rcc.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_rcc_ex.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_uart.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_uart_ex.o 

C_DEPS += \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_adc.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_adc_ex.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_cortex.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_dma.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_gpio.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_pwr.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_pwr_ex.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_rcc.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_rcc_ex.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_uart.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_uart_ex.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal.o: D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32F303x8 -DUSE_STM32F3XX_NUCLEO_32 -DUSE_HAL_DRIVER -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Projects/STM32F303K8-Nucleo/Examples/UART/UART_TwoBoards_ComPolling/Inc" -ID:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_hal_adc.h -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/CMSIS/Device/ST/STM32F3xx/Include" -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Inc" -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/BSP/STM32F3xx_Nucleo_32" -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/CMSIS/Include" -I"C:/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.win32_1.13.3.201707031232/tools/compiler/arm-none-eabi/include" -I"C:/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.win32_1.13.3.201707031232/tools/compiler/lib/gcc/arm-none-eabi/5.4.1/include" -I"C:/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.win32_1.13.3.201707031232/tools/compiler/lib/gcc/arm-none-eabi/5.4.1/include-fixed"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_adc.o: D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_adc.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32F303x8 -DUSE_STM32F3XX_NUCLEO_32 -DUSE_HAL_DRIVER -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Projects/STM32F303K8-Nucleo/Examples/UART/UART_TwoBoards_ComPolling/Inc" -ID:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_hal_adc.h -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/CMSIS/Device/ST/STM32F3xx/Include" -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Inc" -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/BSP/STM32F3xx_Nucleo_32" -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/CMSIS/Include" -I"C:/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.win32_1.13.3.201707031232/tools/compiler/arm-none-eabi/include" -I"C:/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.win32_1.13.3.201707031232/tools/compiler/lib/gcc/arm-none-eabi/5.4.1/include" -I"C:/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.win32_1.13.3.201707031232/tools/compiler/lib/gcc/arm-none-eabi/5.4.1/include-fixed"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_adc_ex.o: D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_adc_ex.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32F303x8 -DUSE_STM32F3XX_NUCLEO_32 -DUSE_HAL_DRIVER -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Projects/STM32F303K8-Nucleo/Examples/UART/UART_TwoBoards_ComPolling/Inc" -ID:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_hal_adc.h -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/CMSIS/Device/ST/STM32F3xx/Include" -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Inc" -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/BSP/STM32F3xx_Nucleo_32" -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/CMSIS/Include" -I"C:/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.win32_1.13.3.201707031232/tools/compiler/arm-none-eabi/include" -I"C:/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.win32_1.13.3.201707031232/tools/compiler/lib/gcc/arm-none-eabi/5.4.1/include" -I"C:/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.win32_1.13.3.201707031232/tools/compiler/lib/gcc/arm-none-eabi/5.4.1/include-fixed"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_cortex.o: D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_cortex.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32F303x8 -DUSE_STM32F3XX_NUCLEO_32 -DUSE_HAL_DRIVER -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Projects/STM32F303K8-Nucleo/Examples/UART/UART_TwoBoards_ComPolling/Inc" -ID:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_hal_adc.h -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/CMSIS/Device/ST/STM32F3xx/Include" -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Inc" -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/BSP/STM32F3xx_Nucleo_32" -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/CMSIS/Include" -I"C:/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.win32_1.13.3.201707031232/tools/compiler/arm-none-eabi/include" -I"C:/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.win32_1.13.3.201707031232/tools/compiler/lib/gcc/arm-none-eabi/5.4.1/include" -I"C:/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.win32_1.13.3.201707031232/tools/compiler/lib/gcc/arm-none-eabi/5.4.1/include-fixed"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_dma.o: D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_dma.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32F303x8 -DUSE_STM32F3XX_NUCLEO_32 -DUSE_HAL_DRIVER -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Projects/STM32F303K8-Nucleo/Examples/UART/UART_TwoBoards_ComPolling/Inc" -ID:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_hal_adc.h -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/CMSIS/Device/ST/STM32F3xx/Include" -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Inc" -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/BSP/STM32F3xx_Nucleo_32" -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/CMSIS/Include" -I"C:/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.win32_1.13.3.201707031232/tools/compiler/arm-none-eabi/include" -I"C:/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.win32_1.13.3.201707031232/tools/compiler/lib/gcc/arm-none-eabi/5.4.1/include" -I"C:/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.win32_1.13.3.201707031232/tools/compiler/lib/gcc/arm-none-eabi/5.4.1/include-fixed"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_gpio.o: D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_gpio.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32F303x8 -DUSE_STM32F3XX_NUCLEO_32 -DUSE_HAL_DRIVER -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Projects/STM32F303K8-Nucleo/Examples/UART/UART_TwoBoards_ComPolling/Inc" -ID:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_hal_adc.h -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/CMSIS/Device/ST/STM32F3xx/Include" -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Inc" -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/BSP/STM32F3xx_Nucleo_32" -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/CMSIS/Include" -I"C:/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.win32_1.13.3.201707031232/tools/compiler/arm-none-eabi/include" -I"C:/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.win32_1.13.3.201707031232/tools/compiler/lib/gcc/arm-none-eabi/5.4.1/include" -I"C:/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.win32_1.13.3.201707031232/tools/compiler/lib/gcc/arm-none-eabi/5.4.1/include-fixed"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_pwr.o: D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_pwr.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32F303x8 -DUSE_STM32F3XX_NUCLEO_32 -DUSE_HAL_DRIVER -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Projects/STM32F303K8-Nucleo/Examples/UART/UART_TwoBoards_ComPolling/Inc" -ID:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_hal_adc.h -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/CMSIS/Device/ST/STM32F3xx/Include" -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Inc" -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/BSP/STM32F3xx_Nucleo_32" -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/CMSIS/Include" -I"C:/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.win32_1.13.3.201707031232/tools/compiler/arm-none-eabi/include" -I"C:/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.win32_1.13.3.201707031232/tools/compiler/lib/gcc/arm-none-eabi/5.4.1/include" -I"C:/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.win32_1.13.3.201707031232/tools/compiler/lib/gcc/arm-none-eabi/5.4.1/include-fixed"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_pwr_ex.o: D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_pwr_ex.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32F303x8 -DUSE_STM32F3XX_NUCLEO_32 -DUSE_HAL_DRIVER -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Projects/STM32F303K8-Nucleo/Examples/UART/UART_TwoBoards_ComPolling/Inc" -ID:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_hal_adc.h -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/CMSIS/Device/ST/STM32F3xx/Include" -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Inc" -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/BSP/STM32F3xx_Nucleo_32" -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/CMSIS/Include" -I"C:/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.win32_1.13.3.201707031232/tools/compiler/arm-none-eabi/include" -I"C:/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.win32_1.13.3.201707031232/tools/compiler/lib/gcc/arm-none-eabi/5.4.1/include" -I"C:/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.win32_1.13.3.201707031232/tools/compiler/lib/gcc/arm-none-eabi/5.4.1/include-fixed"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_rcc.o: D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_rcc.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32F303x8 -DUSE_STM32F3XX_NUCLEO_32 -DUSE_HAL_DRIVER -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Projects/STM32F303K8-Nucleo/Examples/UART/UART_TwoBoards_ComPolling/Inc" -ID:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_hal_adc.h -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/CMSIS/Device/ST/STM32F3xx/Include" -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Inc" -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/BSP/STM32F3xx_Nucleo_32" -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/CMSIS/Include" -I"C:/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.win32_1.13.3.201707031232/tools/compiler/arm-none-eabi/include" -I"C:/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.win32_1.13.3.201707031232/tools/compiler/lib/gcc/arm-none-eabi/5.4.1/include" -I"C:/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.win32_1.13.3.201707031232/tools/compiler/lib/gcc/arm-none-eabi/5.4.1/include-fixed"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_rcc_ex.o: D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_rcc_ex.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32F303x8 -DUSE_STM32F3XX_NUCLEO_32 -DUSE_HAL_DRIVER -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Projects/STM32F303K8-Nucleo/Examples/UART/UART_TwoBoards_ComPolling/Inc" -ID:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_hal_adc.h -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/CMSIS/Device/ST/STM32F3xx/Include" -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Inc" -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/BSP/STM32F3xx_Nucleo_32" -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/CMSIS/Include" -I"C:/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.win32_1.13.3.201707031232/tools/compiler/arm-none-eabi/include" -I"C:/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.win32_1.13.3.201707031232/tools/compiler/lib/gcc/arm-none-eabi/5.4.1/include" -I"C:/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.win32_1.13.3.201707031232/tools/compiler/lib/gcc/arm-none-eabi/5.4.1/include-fixed"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_uart.o: D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_uart.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32F303x8 -DUSE_STM32F3XX_NUCLEO_32 -DUSE_HAL_DRIVER -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Projects/STM32F303K8-Nucleo/Examples/UART/UART_TwoBoards_ComPolling/Inc" -ID:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_hal_adc.h -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/CMSIS/Device/ST/STM32F3xx/Include" -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Inc" -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/BSP/STM32F3xx_Nucleo_32" -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/CMSIS/Include" -I"C:/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.win32_1.13.3.201707031232/tools/compiler/arm-none-eabi/include" -I"C:/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.win32_1.13.3.201707031232/tools/compiler/lib/gcc/arm-none-eabi/5.4.1/include" -I"C:/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.win32_1.13.3.201707031232/tools/compiler/lib/gcc/arm-none-eabi/5.4.1/include-fixed"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_uart_ex.o: D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_uart_ex.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32F303x8 -DUSE_STM32F3XX_NUCLEO_32 -DUSE_HAL_DRIVER -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Projects/STM32F303K8-Nucleo/Examples/UART/UART_TwoBoards_ComPolling/Inc" -ID:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Inc/stm32f3xx_hal_adc.h -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/CMSIS/Device/ST/STM32F3xx/Include" -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/STM32F3xx_HAL_Driver/Inc" -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/BSP/STM32F3xx_Nucleo_32" -I"D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Drivers/CMSIS/Include" -I"C:/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.win32_1.13.3.201707031232/tools/compiler/arm-none-eabi/include" -I"C:/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.win32_1.13.3.201707031232/tools/compiler/lib/gcc/arm-none-eabi/5.4.1/include" -I"C:/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.win32_1.13.3.201707031232/tools/compiler/lib/gcc/arm-none-eabi/5.4.1/include-fixed"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


