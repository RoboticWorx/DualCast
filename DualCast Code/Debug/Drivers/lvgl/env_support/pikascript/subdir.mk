################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/env_support/pikascript/pika_lv_point_t.c \
../Drivers/lvgl/env_support/pikascript/pika_lv_timer_t.c \
../Drivers/lvgl/env_support/pikascript/pika_lv_wegit.c \
../Drivers/lvgl/env_support/pikascript/pika_lvgl.c \
../Drivers/lvgl/env_support/pikascript/pika_lvgl_indev_t.c \
../Drivers/lvgl/env_support/pikascript/pika_lvgl_lv_event.c \
../Drivers/lvgl/env_support/pikascript/pika_lvgl_lv_obj.c \
../Drivers/lvgl/env_support/pikascript/pika_lvgl_lv_style_t.c 

OBJS += \
./Drivers/lvgl/env_support/pikascript/pika_lv_point_t.o \
./Drivers/lvgl/env_support/pikascript/pika_lv_timer_t.o \
./Drivers/lvgl/env_support/pikascript/pika_lv_wegit.o \
./Drivers/lvgl/env_support/pikascript/pika_lvgl.o \
./Drivers/lvgl/env_support/pikascript/pika_lvgl_indev_t.o \
./Drivers/lvgl/env_support/pikascript/pika_lvgl_lv_event.o \
./Drivers/lvgl/env_support/pikascript/pika_lvgl_lv_obj.o \
./Drivers/lvgl/env_support/pikascript/pika_lvgl_lv_style_t.o 

C_DEPS += \
./Drivers/lvgl/env_support/pikascript/pika_lv_point_t.d \
./Drivers/lvgl/env_support/pikascript/pika_lv_timer_t.d \
./Drivers/lvgl/env_support/pikascript/pika_lv_wegit.d \
./Drivers/lvgl/env_support/pikascript/pika_lvgl.d \
./Drivers/lvgl/env_support/pikascript/pika_lvgl_indev_t.d \
./Drivers/lvgl/env_support/pikascript/pika_lvgl_lv_event.d \
./Drivers/lvgl/env_support/pikascript/pika_lvgl_lv_obj.d \
./Drivers/lvgl/env_support/pikascript/pika_lvgl_lv_style_t.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/env_support/pikascript/%.o Drivers/lvgl/env_support/pikascript/%.su Drivers/lvgl/env_support/pikascript/%.cyclo: ../Drivers/lvgl/env_support/pikascript/%.c Drivers/lvgl/env_support/pikascript/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DLV_COLOR_16_SWAP=1 -DUSE_HAL_DRIVER -DSTM32H563xx -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/lvgl" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/sx126x" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/bmi323" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/bme280" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/vl53l4cx" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Core/Media" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/lvgl/src/misc" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/lvgl/src/stdlib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-env_support-2f-pikascript

clean-Drivers-2f-lvgl-2f-env_support-2f-pikascript:
	-$(RM) ./Drivers/lvgl/env_support/pikascript/pika_lv_point_t.cyclo ./Drivers/lvgl/env_support/pikascript/pika_lv_point_t.d ./Drivers/lvgl/env_support/pikascript/pika_lv_point_t.o ./Drivers/lvgl/env_support/pikascript/pika_lv_point_t.su ./Drivers/lvgl/env_support/pikascript/pika_lv_timer_t.cyclo ./Drivers/lvgl/env_support/pikascript/pika_lv_timer_t.d ./Drivers/lvgl/env_support/pikascript/pika_lv_timer_t.o ./Drivers/lvgl/env_support/pikascript/pika_lv_timer_t.su ./Drivers/lvgl/env_support/pikascript/pika_lv_wegit.cyclo ./Drivers/lvgl/env_support/pikascript/pika_lv_wegit.d ./Drivers/lvgl/env_support/pikascript/pika_lv_wegit.o ./Drivers/lvgl/env_support/pikascript/pika_lv_wegit.su ./Drivers/lvgl/env_support/pikascript/pika_lvgl.cyclo ./Drivers/lvgl/env_support/pikascript/pika_lvgl.d ./Drivers/lvgl/env_support/pikascript/pika_lvgl.o ./Drivers/lvgl/env_support/pikascript/pika_lvgl.su ./Drivers/lvgl/env_support/pikascript/pika_lvgl_indev_t.cyclo ./Drivers/lvgl/env_support/pikascript/pika_lvgl_indev_t.d ./Drivers/lvgl/env_support/pikascript/pika_lvgl_indev_t.o ./Drivers/lvgl/env_support/pikascript/pika_lvgl_indev_t.su ./Drivers/lvgl/env_support/pikascript/pika_lvgl_lv_event.cyclo ./Drivers/lvgl/env_support/pikascript/pika_lvgl_lv_event.d ./Drivers/lvgl/env_support/pikascript/pika_lvgl_lv_event.o ./Drivers/lvgl/env_support/pikascript/pika_lvgl_lv_event.su ./Drivers/lvgl/env_support/pikascript/pika_lvgl_lv_obj.cyclo ./Drivers/lvgl/env_support/pikascript/pika_lvgl_lv_obj.d ./Drivers/lvgl/env_support/pikascript/pika_lvgl_lv_obj.o ./Drivers/lvgl/env_support/pikascript/pika_lvgl_lv_obj.su ./Drivers/lvgl/env_support/pikascript/pika_lvgl_lv_style_t.cyclo ./Drivers/lvgl/env_support/pikascript/pika_lvgl_lv_style_t.d ./Drivers/lvgl/env_support/pikascript/pika_lvgl_lv_style_t.o ./Drivers/lvgl/env_support/pikascript/pika_lvgl_lv_style_t.su

.PHONY: clean-Drivers-2f-lvgl-2f-env_support-2f-pikascript

