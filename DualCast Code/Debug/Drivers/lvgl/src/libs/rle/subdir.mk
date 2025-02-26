################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/libs/rle/lv_rle.c 

OBJS += \
./Drivers/lvgl/src/libs/rle/lv_rle.o 

C_DEPS += \
./Drivers/lvgl/src/libs/rle/lv_rle.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/libs/rle/%.o Drivers/lvgl/src/libs/rle/%.su Drivers/lvgl/src/libs/rle/%.cyclo: ../Drivers/lvgl/src/libs/rle/%.c Drivers/lvgl/src/libs/rle/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DLV_COLOR_16_SWAP=1 -DUSE_HAL_DRIVER -DSTM32H563xx -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/lvgl" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/sx126x" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/bmi323" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/bme280" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/vl53l4cx" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Core/Media" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/lvgl/src/misc" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/lvgl/src/stdlib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-libs-2f-rle

clean-Drivers-2f-lvgl-2f-src-2f-libs-2f-rle:
	-$(RM) ./Drivers/lvgl/src/libs/rle/lv_rle.cyclo ./Drivers/lvgl/src/libs/rle/lv_rle.d ./Drivers/lvgl/src/libs/rle/lv_rle.o ./Drivers/lvgl/src/libs/rle/lv_rle.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-libs-2f-rle

