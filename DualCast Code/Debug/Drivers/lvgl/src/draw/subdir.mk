################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/draw/lv_draw.c \
../Drivers/lvgl/src/draw/lv_draw_arc.c \
../Drivers/lvgl/src/draw/lv_draw_buf.c \
../Drivers/lvgl/src/draw/lv_draw_image.c \
../Drivers/lvgl/src/draw/lv_draw_label.c \
../Drivers/lvgl/src/draw/lv_draw_line.c \
../Drivers/lvgl/src/draw/lv_draw_mask.c \
../Drivers/lvgl/src/draw/lv_draw_rect.c \
../Drivers/lvgl/src/draw/lv_draw_triangle.c \
../Drivers/lvgl/src/draw/lv_draw_vector.c \
../Drivers/lvgl/src/draw/lv_image_decoder.c 

OBJS += \
./Drivers/lvgl/src/draw/lv_draw.o \
./Drivers/lvgl/src/draw/lv_draw_arc.o \
./Drivers/lvgl/src/draw/lv_draw_buf.o \
./Drivers/lvgl/src/draw/lv_draw_image.o \
./Drivers/lvgl/src/draw/lv_draw_label.o \
./Drivers/lvgl/src/draw/lv_draw_line.o \
./Drivers/lvgl/src/draw/lv_draw_mask.o \
./Drivers/lvgl/src/draw/lv_draw_rect.o \
./Drivers/lvgl/src/draw/lv_draw_triangle.o \
./Drivers/lvgl/src/draw/lv_draw_vector.o \
./Drivers/lvgl/src/draw/lv_image_decoder.o 

C_DEPS += \
./Drivers/lvgl/src/draw/lv_draw.d \
./Drivers/lvgl/src/draw/lv_draw_arc.d \
./Drivers/lvgl/src/draw/lv_draw_buf.d \
./Drivers/lvgl/src/draw/lv_draw_image.d \
./Drivers/lvgl/src/draw/lv_draw_label.d \
./Drivers/lvgl/src/draw/lv_draw_line.d \
./Drivers/lvgl/src/draw/lv_draw_mask.d \
./Drivers/lvgl/src/draw/lv_draw_rect.d \
./Drivers/lvgl/src/draw/lv_draw_triangle.d \
./Drivers/lvgl/src/draw/lv_draw_vector.d \
./Drivers/lvgl/src/draw/lv_image_decoder.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/draw/%.o Drivers/lvgl/src/draw/%.su Drivers/lvgl/src/draw/%.cyclo: ../Drivers/lvgl/src/draw/%.c Drivers/lvgl/src/draw/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DLV_COLOR_16_SWAP=1 -DUSE_HAL_DRIVER -DSTM32H563xx -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/lvgl" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/sx126x" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/bmi323" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/bme280" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/vl53l4cx" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Core/Media" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/lvgl/src/misc" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/lvgl/src/stdlib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-draw

clean-Drivers-2f-lvgl-2f-src-2f-draw:
	-$(RM) ./Drivers/lvgl/src/draw/lv_draw.cyclo ./Drivers/lvgl/src/draw/lv_draw.d ./Drivers/lvgl/src/draw/lv_draw.o ./Drivers/lvgl/src/draw/lv_draw.su ./Drivers/lvgl/src/draw/lv_draw_arc.cyclo ./Drivers/lvgl/src/draw/lv_draw_arc.d ./Drivers/lvgl/src/draw/lv_draw_arc.o ./Drivers/lvgl/src/draw/lv_draw_arc.su ./Drivers/lvgl/src/draw/lv_draw_buf.cyclo ./Drivers/lvgl/src/draw/lv_draw_buf.d ./Drivers/lvgl/src/draw/lv_draw_buf.o ./Drivers/lvgl/src/draw/lv_draw_buf.su ./Drivers/lvgl/src/draw/lv_draw_image.cyclo ./Drivers/lvgl/src/draw/lv_draw_image.d ./Drivers/lvgl/src/draw/lv_draw_image.o ./Drivers/lvgl/src/draw/lv_draw_image.su ./Drivers/lvgl/src/draw/lv_draw_label.cyclo ./Drivers/lvgl/src/draw/lv_draw_label.d ./Drivers/lvgl/src/draw/lv_draw_label.o ./Drivers/lvgl/src/draw/lv_draw_label.su ./Drivers/lvgl/src/draw/lv_draw_line.cyclo ./Drivers/lvgl/src/draw/lv_draw_line.d ./Drivers/lvgl/src/draw/lv_draw_line.o ./Drivers/lvgl/src/draw/lv_draw_line.su ./Drivers/lvgl/src/draw/lv_draw_mask.cyclo ./Drivers/lvgl/src/draw/lv_draw_mask.d ./Drivers/lvgl/src/draw/lv_draw_mask.o ./Drivers/lvgl/src/draw/lv_draw_mask.su ./Drivers/lvgl/src/draw/lv_draw_rect.cyclo ./Drivers/lvgl/src/draw/lv_draw_rect.d ./Drivers/lvgl/src/draw/lv_draw_rect.o ./Drivers/lvgl/src/draw/lv_draw_rect.su ./Drivers/lvgl/src/draw/lv_draw_triangle.cyclo ./Drivers/lvgl/src/draw/lv_draw_triangle.d ./Drivers/lvgl/src/draw/lv_draw_triangle.o ./Drivers/lvgl/src/draw/lv_draw_triangle.su ./Drivers/lvgl/src/draw/lv_draw_vector.cyclo ./Drivers/lvgl/src/draw/lv_draw_vector.d ./Drivers/lvgl/src/draw/lv_draw_vector.o ./Drivers/lvgl/src/draw/lv_draw_vector.su ./Drivers/lvgl/src/draw/lv_image_decoder.cyclo ./Drivers/lvgl/src/draw/lv_image_decoder.d ./Drivers/lvgl/src/draw/lv_image_decoder.o ./Drivers/lvgl/src/draw/lv_image_decoder.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-draw

