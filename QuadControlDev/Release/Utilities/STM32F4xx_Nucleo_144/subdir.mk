################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Utilities/STM32F4xx_Nucleo_144/stm32f4xx_nucleo_144.c 

OBJS += \
./Utilities/STM32F4xx_Nucleo_144/stm32f4xx_nucleo_144.o 

C_DEPS += \
./Utilities/STM32F4xx_Nucleo_144/stm32f4xx_nucleo_144.d 


# Each subdirectory must supply rules for building sources it contributes
Utilities/STM32F4xx_Nucleo_144/%.o: ../Utilities/STM32F4xx_Nucleo_144/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32F429ZITx -DNUCLEO_F429ZI -DSTM32F4 -DSTM32 -DUSE_HAL_DRIVER -DSTM32F429xx -I"D:/Beni/workspace/EntryX0/QuadControlDev/inc" -I"D:/Beni/workspace/EntryX0/QuadControlDev/CMSIS/core" -I"D:/Beni/workspace/EntryX0/QuadControlDev/CMSIS/device" -I"D:/Beni/workspace/EntryX0/QuadControlDev/HAL_Driver/Inc/Legacy" -I"D:/Beni/workspace/EntryX0/QuadControlDev/HAL_Driver/Inc" -I"D:/Beni/workspace/EntryX0/QuadControlDev/Utilities/STM32F4xx_Nucleo_144" -O3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


