################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../startup/startup_stm32f429xx.s 

OBJS += \
./startup/startup_stm32f429xx.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Assembler'
	@echo $(PWD)
	arm-none-eabi-as -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -I"D:/Beni/workspace/EntryX0/QuadControlDev/inc" -I"D:/Beni/workspace/EntryX0/QuadControlDev/CMSIS/core" -I"D:/Beni/workspace/EntryX0/QuadControlDev/CMSIS/device" -I"D:/Beni/workspace/EntryX0/QuadControlDev/HAL_Driver/Inc/Legacy" -I"D:/Beni/workspace/EntryX0/QuadControlDev/HAL_Driver/Inc" -I"D:/Beni/workspace/EntryX0/QuadControlDev/Utilities/STM32F4xx_Nucleo_144" -g -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


