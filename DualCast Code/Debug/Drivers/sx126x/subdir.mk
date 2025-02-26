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
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DLV_COLOR_16_SWAP=1 -DUSE_HAL_DRIVER -DSTM32H563xx -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/lvgl" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/sx126x" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/bmi323" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/bme280" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/vl53l4cx" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Core/Media" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/lvgl/src/misc" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/lvgl/src/stdlib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-sx126x

clean-Drivers-2f-sx126x:
	-$(RM) ./Drivers/sx126x/lr_fhss_mac.cyclo ./Drivers/sx126x/lr_fhss_mac.d ./Drivers/sx126x/lr_fhss_mac.o ./Drivers/sx126x/lr_fhss_mac.su ./Drivers/sx126x/sx126x.cyclo ./Drivers/sx126x/sx126x.d ./Drivers/sx126x/sx126x.o ./Drivers/sx126x/sx126x.su ./Drivers/sx126x/sx126x_driver_version.cyclo ./Drivers/sx126x/sx126x_driver_version.d ./Drivers/sx126x/sx126x_driver_version.o ./Drivers/sx126x/sx126x_driver_version.su ./Drivers/sx126x/sx126x_hal.cyclo ./Drivers/sx126x/sx126x_hal.d ./Drivers/sx126x/sx126x_hal.o ./Drivers/sx126x/sx126x_hal.su ./Drivers/sx126x/sx126x_lr_fhss.cyclo ./Drivers/sx126x/sx126x_lr_fhss.d ./Drivers/sx126x/sx126x_lr_fhss.o ./Drivers/sx126x/sx126x_lr_fhss.su

.PHONY: clean-Drivers-2f-sx126x

