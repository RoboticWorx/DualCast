################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/drivers/qnx/lv_qnx.c 

OBJS += \
./Drivers/lvgl/src/drivers/qnx/lv_qnx.o 

C_DEPS += \
./Drivers/lvgl/src/drivers/qnx/lv_qnx.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/drivers/qnx/%.o Drivers/lvgl/src/drivers/qnx/%.su Drivers/lvgl/src/drivers/qnx/%.cyclo: ../Drivers/lvgl/src/drivers/qnx/%.c Drivers/lvgl/src/drivers/qnx/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DLV_COLOR_16_SWAP=1 -DUSE_HAL_DRIVER -DSTM32H563xx -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/lvgl" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/sx126x" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/bmi323" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/bme280" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/vl53l4cx" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Core/Media" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/lvgl/src/misc" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/lvgl/src/stdlib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-drivers-2f-qnx

clean-Drivers-2f-lvgl-2f-src-2f-drivers-2f-qnx:
	-$(RM) ./Drivers/lvgl/src/drivers/qnx/lv_qnx.cyclo ./Drivers/lvgl/src/drivers/qnx/lv_qnx.d ./Drivers/lvgl/src/drivers/qnx/lv_qnx.o ./Drivers/lvgl/src/drivers/qnx/lv_qnx.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-drivers-2f-qnx

