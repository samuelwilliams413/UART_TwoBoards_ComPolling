################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Projects/STM32F303K8-Nucleo/Examples/UART/UART_TwoBoards_ComPolling/SW4STM32/startup_stm32f303x8.s 

OBJS += \
./Example/SW4STM32/startup_stm32f303x8.o 


# Each subdirectory must supply rules for building sources it contributes
Example/SW4STM32/startup_stm32f303x8.o: D:/en.stm32cubef3/STM32Cube_FW_F3_V1.9.0/Projects/STM32F303K8-Nucleo/Examples/UART/UART_TwoBoards_ComPolling/SW4STM32/startup_stm32f303x8.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Assembler'
	@echo $(PWD)
	arm-none-eabi-as -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -g -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


