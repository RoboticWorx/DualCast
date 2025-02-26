################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/draw/vg_lite/lv_draw_buf_vg_lite.c \
../Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite.c \
../Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_arc.c \
../Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_border.c \
../Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_box_shadow.c \
../Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_fill.c \
../Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_img.c \
../Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_label.c \
../Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_layer.c \
../Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_line.c \
../Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_mask_rect.c \
../Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_triangle.c \
../Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_vector.c \
../Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_decoder.c \
../Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_grad.c \
../Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_math.c \
../Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_path.c \
../Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_pending.c \
../Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_stroke.c \
../Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_utils.c 

OBJS += \
./Drivers/lvgl/src/draw/vg_lite/lv_draw_buf_vg_lite.o \
./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite.o \
./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_arc.o \
./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_border.o \
./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_box_shadow.o \
./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_fill.o \
./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_img.o \
./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_label.o \
./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_layer.o \
./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_line.o \
./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_mask_rect.o \
./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_triangle.o \
./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_vector.o \
./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_decoder.o \
./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_grad.o \
./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_math.o \
./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_path.o \
./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_pending.o \
./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_stroke.o \
./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_utils.o 

C_DEPS += \
./Drivers/lvgl/src/draw/vg_lite/lv_draw_buf_vg_lite.d \
./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite.d \
./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_arc.d \
./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_border.d \
./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_box_shadow.d \
./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_fill.d \
./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_img.d \
./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_label.d \
./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_layer.d \
./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_line.d \
./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_mask_rect.d \
./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_triangle.d \
./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_vector.d \
./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_decoder.d \
./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_grad.d \
./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_math.d \
./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_path.d \
./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_pending.d \
./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_stroke.d \
./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_utils.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/draw/vg_lite/%.o Drivers/lvgl/src/draw/vg_lite/%.su Drivers/lvgl/src/draw/vg_lite/%.cyclo: ../Drivers/lvgl/src/draw/vg_lite/%.c Drivers/lvgl/src/draw/vg_lite/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DLV_COLOR_16_SWAP=1 -DUSE_HAL_DRIVER -DSTM32H563xx -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/lvgl" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/sx126x" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/bmi323" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/bme280" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/vl53l4cx" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Core/Media" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/lvgl/src/misc" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/lvgl/src/stdlib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-draw-2f-vg_lite

clean-Drivers-2f-lvgl-2f-src-2f-draw-2f-vg_lite:
	-$(RM) ./Drivers/lvgl/src/draw/vg_lite/lv_draw_buf_vg_lite.cyclo ./Drivers/lvgl/src/draw/vg_lite/lv_draw_buf_vg_lite.d ./Drivers/lvgl/src/draw/vg_lite/lv_draw_buf_vg_lite.o ./Drivers/lvgl/src/draw/vg_lite/lv_draw_buf_vg_lite.su ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite.cyclo ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite.d ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite.o ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite.su ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_arc.cyclo ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_arc.d ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_arc.o ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_arc.su ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_border.cyclo ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_border.d ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_border.o ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_border.su ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_box_shadow.cyclo ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_box_shadow.d ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_box_shadow.o ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_box_shadow.su ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_fill.cyclo ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_fill.d ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_fill.o ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_fill.su ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_img.cyclo ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_img.d ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_img.o ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_img.su ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_label.cyclo ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_label.d ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_label.o ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_label.su ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_layer.cyclo ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_layer.d ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_layer.o ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_layer.su ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_line.cyclo ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_line.d ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_line.o ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_line.su ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_mask_rect.cyclo ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_mask_rect.d ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_mask_rect.o ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_mask_rect.su ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_triangle.cyclo ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_triangle.d ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_triangle.o ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_triangle.su ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_vector.cyclo ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_vector.d ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_vector.o ./Drivers/lvgl/src/draw/vg_lite/lv_draw_vg_lite_vector.su ./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_decoder.cyclo ./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_decoder.d ./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_decoder.o ./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_decoder.su ./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_grad.cyclo ./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_grad.d ./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_grad.o ./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_grad.su ./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_math.cyclo ./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_math.d ./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_math.o ./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_math.su ./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_path.cyclo ./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_path.d ./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_path.o ./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_path.su ./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_pending.cyclo ./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_pending.d ./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_pending.o ./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_pending.su ./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_stroke.cyclo ./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_stroke.d ./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_stroke.o ./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_stroke.su ./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_utils.cyclo ./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_utils.d ./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_utils.o ./Drivers/lvgl/src/draw/vg_lite/lv_vg_lite_utils.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-draw-2f-vg_lite

