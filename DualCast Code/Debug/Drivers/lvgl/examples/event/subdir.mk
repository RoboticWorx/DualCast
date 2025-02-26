################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/examples/event/lv_example_event_bubble.c \
../Drivers/lvgl/examples/event/lv_example_event_button.c \
../Drivers/lvgl/examples/event/lv_example_event_click.c \
../Drivers/lvgl/examples/event/lv_example_event_draw.c \
../Drivers/lvgl/examples/event/lv_example_event_streak.c 

OBJS += \
./Drivers/lvgl/examples/event/lv_example_event_bubble.o \
./Drivers/lvgl/examples/event/lv_example_event_button.o \
./Drivers/lvgl/examples/event/lv_example_event_click.o \
./Drivers/lvgl/examples/event/lv_example_event_draw.o \
./Drivers/lvgl/examples/event/lv_example_event_streak.o 

C_DEPS += \
./Drivers/lvgl/examples/event/lv_example_event_bubble.d \
./Drivers/lvgl/examples/event/lv_example_event_button.d \
./Drivers/lvgl/examples/event/lv_example_event_click.d \
./Drivers/lvgl/examples/event/lv_example_event_draw.d \
./Drivers/lvgl/examples/event/lv_example_event_streak.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/examples/event/%.o Drivers/lvgl/examples/event/%.su Drivers/lvgl/examples/event/%.cyclo: ../Drivers/lvgl/examples/event/%.c Drivers/lvgl/examples/event/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DLV_COLOR_16_SWAP=1 -DUSE_HAL_DRIVER -DSTM32H563xx -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/lvgl" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/sx126x" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/bmi323" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/bme280" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/vl53l4cx" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Core/Media" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/lvgl/src/misc" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/lvgl/src/stdlib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-examples-2f-event

clean-Drivers-2f-lvgl-2f-examples-2f-event:
	-$(RM) ./Drivers/lvgl/examples/event/lv_example_event_bubble.cyclo ./Drivers/lvgl/examples/event/lv_example_event_bubble.d ./Drivers/lvgl/examples/event/lv_example_event_bubble.o ./Drivers/lvgl/examples/event/lv_example_event_bubble.su ./Drivers/lvgl/examples/event/lv_example_event_button.cyclo ./Drivers/lvgl/examples/event/lv_example_event_button.d ./Drivers/lvgl/examples/event/lv_example_event_button.o ./Drivers/lvgl/examples/event/lv_example_event_button.su ./Drivers/lvgl/examples/event/lv_example_event_click.cyclo ./Drivers/lvgl/examples/event/lv_example_event_click.d ./Drivers/lvgl/examples/event/lv_example_event_click.o ./Drivers/lvgl/examples/event/lv_example_event_click.su ./Drivers/lvgl/examples/event/lv_example_event_draw.cyclo ./Drivers/lvgl/examples/event/lv_example_event_draw.d ./Drivers/lvgl/examples/event/lv_example_event_draw.o ./Drivers/lvgl/examples/event/lv_example_event_draw.su ./Drivers/lvgl/examples/event/lv_example_event_streak.cyclo ./Drivers/lvgl/examples/event/lv_example_event_streak.d ./Drivers/lvgl/examples/event/lv_example_event_streak.o ./Drivers/lvgl/examples/event/lv_example_event_streak.su

.PHONY: clean-Drivers-2f-lvgl-2f-examples-2f-event

