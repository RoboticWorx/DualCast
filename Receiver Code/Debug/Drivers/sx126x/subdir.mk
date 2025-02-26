################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/sx126x/lr_fhss_mac.c \
../Drivers/sx126x/sx126x.c \
../Drivers/sx126x/sx126x_driver_version.c \
../Drivers/sx126x/sx126x_hal.c \
../Drivers/sx126x/sx126x_lr_fhss.c 

OBJS += \
./Drivers/sx126x/lr_fhss_mac.o \
./Drivers/sx126x/sx126x.o \
./Drivers/sx126x/sx126x_driver_version.o \
./Drivers/sx126x/sx126x_hal.o \
./Drivers/sx126x/sx126x_lr_fhss.o 

C_DEPS += \
./Drivers/sx126x/lr_fhss_mac.d \
./Drivers/sx126x/sx126x.d \
./Drivers/sx126x/sx126x_driver_version.d \
./Drivers/sx126x/sx126x_hal.d \
./Drivers/sx126x/sx126x_lr_fhss.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/sx126x/%.o Drivers/sx126x/%.su Drivers/sx126x/%.cyclo: ../Drivers/sx126x/%.c Drivers/sx126x/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U073xx -c -I../Core/Inc -I../Drivers/STM32U0xx_HAL_Driver/Inc -I../Drivers/STM32U0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32U0xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast-RX/Drivers/sx126x" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast-RX/Drivers/bme280" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-sx126x

clean-Drivers-2f-sx126x:
	-$(RM) ./Drivers/sx126x/lr_fhss_mac.cyclo ./Drivers/sx126x/lr_fhss_mac.d ./Drivers/sx126x/lr_fhss_mac.o ./Drivers/sx126x/lr_fhss_mac.su ./Drivers/sx126x/sx126x.cyclo ./Drivers/sx126x/sx126x.d ./Drivers/sx126x/sx126x.o ./Drivers/sx126x/sx126x.su ./Drivers/sx126x/sx126x_driver_version.cyclo ./Drivers/sx126x/sx126x_driver_version.d ./Drivers/sx126x/sx126x_driver_version.o ./Drivers/sx126x/sx126x_driver_version.su ./Drivers/sx126x/sx126x_hal.cyclo ./Drivers/sx126x/sx126x_hal.d ./Drivers/sx126x/sx126x_hal.o ./Drivers/sx126x/sx126x_hal.su ./Drivers/sx126x/sx126x_lr_fhss.cyclo ./Drivers/sx126x/sx126x_lr_fhss.d ./Drivers/sx126x/sx126x_lr_fhss.o ./Drivers/sx126x/sx126x_lr_fhss.su

.PHONY: clean-Drivers-2f-sx126x

