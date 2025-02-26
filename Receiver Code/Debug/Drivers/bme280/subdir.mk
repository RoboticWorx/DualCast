################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/bme280/bme280.c \
../Drivers/bme280/common_bme.c 

OBJS += \
./Drivers/bme280/bme280.o \
./Drivers/bme280/common_bme.o 

C_DEPS += \
./Drivers/bme280/bme280.d \
./Drivers/bme280/common_bme.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/bme280/%.o Drivers/bme280/%.su Drivers/bme280/%.cyclo: ../Drivers/bme280/%.c Drivers/bme280/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U073xx -c -I../Core/Inc -I../Drivers/STM32U0xx_HAL_Driver/Inc -I../Drivers/STM32U0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32U0xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast-RX/Drivers/sx126x" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast-RX/Drivers/bme280" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-bme280

clean-Drivers-2f-bme280:
	-$(RM) ./Drivers/bme280/bme280.cyclo ./Drivers/bme280/bme280.d ./Drivers/bme280/bme280.o ./Drivers/bme280/bme280.su ./Drivers/bme280/common_bme.cyclo ./Drivers/bme280/common_bme.d ./Drivers/bme280/common_bme.o ./Drivers/bme280/common_bme.su

.PHONY: clean-Drivers-2f-bme280

