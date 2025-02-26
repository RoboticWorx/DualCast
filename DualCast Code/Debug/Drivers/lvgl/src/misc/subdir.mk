################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/misc/lv_anim.c \
../Drivers/lvgl/src/misc/lv_anim_timeline.c \
../Drivers/lvgl/src/misc/lv_area.c \
../Drivers/lvgl/src/misc/lv_array.c \
../Drivers/lvgl/src/misc/lv_async.c \
../Drivers/lvgl/src/misc/lv_bidi.c \
../Drivers/lvgl/src/misc/lv_circle_buf.c \
../Drivers/lvgl/src/misc/lv_color.c \
../Drivers/lvgl/src/misc/lv_color_op.c \
../Drivers/lvgl/src/misc/lv_event.c \
../Drivers/lvgl/src/misc/lv_fs.c \
../Drivers/lvgl/src/misc/lv_iter.c \
../Drivers/lvgl/src/misc/lv_ll.c \
../Drivers/lvgl/src/misc/lv_log.c \
../Drivers/lvgl/src/misc/lv_lru.c \
../Drivers/lvgl/src/misc/lv_math.c \
../Drivers/lvgl/src/misc/lv_matrix.c \
../Drivers/lvgl/src/misc/lv_palette.c \
../Drivers/lvgl/src/misc/lv_profiler_builtin.c \
../Drivers/lvgl/src/misc/lv_rb.c \
../Drivers/lvgl/src/misc/lv_style.c \
../Drivers/lvgl/src/misc/lv_style_gen.c \
../Drivers/lvgl/src/misc/lv_templ.c \
../Drivers/lvgl/src/misc/lv_text.c \
../Drivers/lvgl/src/misc/lv_text_ap.c \
../Drivers/lvgl/src/misc/lv_timer.c \
../Drivers/lvgl/src/misc/lv_tree.c \
../Drivers/lvgl/src/misc/lv_utils.c 

OBJS += \
./Drivers/lvgl/src/misc/lv_anim.o \
./Drivers/lvgl/src/misc/lv_anim_timeline.o \
./Drivers/lvgl/src/misc/lv_area.o \
./Drivers/lvgl/src/misc/lv_array.o \
./Drivers/lvgl/src/misc/lv_async.o \
./Drivers/lvgl/src/misc/lv_bidi.o \
./Drivers/lvgl/src/misc/lv_circle_buf.o \
./Drivers/lvgl/src/misc/lv_color.o \
./Drivers/lvgl/src/misc/lv_color_op.o \
./Drivers/lvgl/src/misc/lv_event.o \
./Drivers/lvgl/src/misc/lv_fs.o \
./Drivers/lvgl/src/misc/lv_iter.o \
./Drivers/lvgl/src/misc/lv_ll.o \
./Drivers/lvgl/src/misc/lv_log.o \
./Drivers/lvgl/src/misc/lv_lru.o \
./Drivers/lvgl/src/misc/lv_math.o \
./Drivers/lvgl/src/misc/lv_matrix.o \
./Drivers/lvgl/src/misc/lv_palette.o \
./Drivers/lvgl/src/misc/lv_profiler_builtin.o \
./Drivers/lvgl/src/misc/lv_rb.o \
./Drivers/lvgl/src/misc/lv_style.o \
./Drivers/lvgl/src/misc/lv_style_gen.o \
./Drivers/lvgl/src/misc/lv_templ.o \
./Drivers/lvgl/src/misc/lv_text.o \
./Drivers/lvgl/src/misc/lv_text_ap.o \
./Drivers/lvgl/src/misc/lv_timer.o \
./Drivers/lvgl/src/misc/lv_tree.o \
./Drivers/lvgl/src/misc/lv_utils.o 

C_DEPS += \
./Drivers/lvgl/src/misc/lv_anim.d \
./Drivers/lvgl/src/misc/lv_anim_timeline.d \
./Drivers/lvgl/src/misc/lv_area.d \
./Drivers/lvgl/src/misc/lv_array.d \
./Drivers/lvgl/src/misc/lv_async.d \
./Drivers/lvgl/src/misc/lv_bidi.d \
./Drivers/lvgl/src/misc/lv_circle_buf.d \
./Drivers/lvgl/src/misc/lv_color.d \
./Drivers/lvgl/src/misc/lv_color_op.d \
./Drivers/lvgl/src/misc/lv_event.d \
./Drivers/lvgl/src/misc/lv_fs.d \
./Drivers/lvgl/src/misc/lv_iter.d \
./Drivers/lvgl/src/misc/lv_ll.d \
./Drivers/lvgl/src/misc/lv_log.d \
./Drivers/lvgl/src/misc/lv_lru.d \
./Drivers/lvgl/src/misc/lv_math.d \
./Drivers/lvgl/src/misc/lv_matrix.d \
./Drivers/lvgl/src/misc/lv_palette.d \
./Drivers/lvgl/src/misc/lv_profiler_builtin.d \
./Drivers/lvgl/src/misc/lv_rb.d \
./Drivers/lvgl/src/misc/lv_style.d \
./Drivers/lvgl/src/misc/lv_style_gen.d \
./Drivers/lvgl/src/misc/lv_templ.d \
./Drivers/lvgl/src/misc/lv_text.d \
./Drivers/lvgl/src/misc/lv_text_ap.d \
./Drivers/lvgl/src/misc/lv_timer.d \
./Drivers/lvgl/src/misc/lv_tree.d \
./Drivers/lvgl/src/misc/lv_utils.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/misc/%.o Drivers/lvgl/src/misc/%.su Drivers/lvgl/src/misc/%.cyclo: ../Drivers/lvgl/src/misc/%.c Drivers/lvgl/src/misc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DLV_COLOR_16_SWAP=1 -DUSE_HAL_DRIVER -DSTM32H563xx -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/lvgl" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/sx126x" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/bmi323" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/bme280" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/vl53l4cx" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Core/Media" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/lvgl/src/misc" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/lvgl/src/stdlib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-misc

clean-Drivers-2f-lvgl-2f-src-2f-misc:
	-$(RM) ./Drivers/lvgl/src/misc/lv_anim.cyclo ./Drivers/lvgl/src/misc/lv_anim.d ./Drivers/lvgl/src/misc/lv_anim.o ./Drivers/lvgl/src/misc/lv_anim.su ./Drivers/lvgl/src/misc/lv_anim_timeline.cyclo ./Drivers/lvgl/src/misc/lv_anim_timeline.d ./Drivers/lvgl/src/misc/lv_anim_timeline.o ./Drivers/lvgl/src/misc/lv_anim_timeline.su ./Drivers/lvgl/src/misc/lv_area.cyclo ./Drivers/lvgl/src/misc/lv_area.d ./Drivers/lvgl/src/misc/lv_area.o ./Drivers/lvgl/src/misc/lv_area.su ./Drivers/lvgl/src/misc/lv_array.cyclo ./Drivers/lvgl/src/misc/lv_array.d ./Drivers/lvgl/src/misc/lv_array.o ./Drivers/lvgl/src/misc/lv_array.su ./Drivers/lvgl/src/misc/lv_async.cyclo ./Drivers/lvgl/src/misc/lv_async.d ./Drivers/lvgl/src/misc/lv_async.o ./Drivers/lvgl/src/misc/lv_async.su ./Drivers/lvgl/src/misc/lv_bidi.cyclo ./Drivers/lvgl/src/misc/lv_bidi.d ./Drivers/lvgl/src/misc/lv_bidi.o ./Drivers/lvgl/src/misc/lv_bidi.su ./Drivers/lvgl/src/misc/lv_circle_buf.cyclo ./Drivers/lvgl/src/misc/lv_circle_buf.d ./Drivers/lvgl/src/misc/lv_circle_buf.o ./Drivers/lvgl/src/misc/lv_circle_buf.su ./Drivers/lvgl/src/misc/lv_color.cyclo ./Drivers/lvgl/src/misc/lv_color.d ./Drivers/lvgl/src/misc/lv_color.o ./Drivers/lvgl/src/misc/lv_color.su ./Drivers/lvgl/src/misc/lv_color_op.cyclo ./Drivers/lvgl/src/misc/lv_color_op.d ./Drivers/lvgl/src/misc/lv_color_op.o ./Drivers/lvgl/src/misc/lv_color_op.su ./Drivers/lvgl/src/misc/lv_event.cyclo ./Drivers/lvgl/src/misc/lv_event.d ./Drivers/lvgl/src/misc/lv_event.o ./Drivers/lvgl/src/misc/lv_event.su ./Drivers/lvgl/src/misc/lv_fs.cyclo ./Drivers/lvgl/src/misc/lv_fs.d ./Drivers/lvgl/src/misc/lv_fs.o ./Drivers/lvgl/src/misc/lv_fs.su ./Drivers/lvgl/src/misc/lv_iter.cyclo ./Drivers/lvgl/src/misc/lv_iter.d ./Drivers/lvgl/src/misc/lv_iter.o ./Drivers/lvgl/src/misc/lv_iter.su ./Drivers/lvgl/src/misc/lv_ll.cyclo ./Drivers/lvgl/src/misc/lv_ll.d ./Drivers/lvgl/src/misc/lv_ll.o ./Drivers/lvgl/src/misc/lv_ll.su ./Drivers/lvgl/src/misc/lv_log.cyclo ./Drivers/lvgl/src/misc/lv_log.d ./Drivers/lvgl/src/misc/lv_log.o ./Drivers/lvgl/src/misc/lv_log.su ./Drivers/lvgl/src/misc/lv_lru.cyclo ./Drivers/lvgl/src/misc/lv_lru.d ./Drivers/lvgl/src/misc/lv_lru.o ./Drivers/lvgl/src/misc/lv_lru.su ./Drivers/lvgl/src/misc/lv_math.cyclo ./Drivers/lvgl/src/misc/lv_math.d ./Drivers/lvgl/src/misc/lv_math.o ./Drivers/lvgl/src/misc/lv_math.su ./Drivers/lvgl/src/misc/lv_matrix.cyclo ./Drivers/lvgl/src/misc/lv_matrix.d ./Drivers/lvgl/src/misc/lv_matrix.o ./Drivers/lvgl/src/misc/lv_matrix.su ./Drivers/lvgl/src/misc/lv_palette.cyclo ./Drivers/lvgl/src/misc/lv_palette.d ./Drivers/lvgl/src/misc/lv_palette.o ./Drivers/lvgl/src/misc/lv_palette.su ./Drivers/lvgl/src/misc/lv_profiler_builtin.cyclo ./Drivers/lvgl/src/misc/lv_profiler_builtin.d ./Drivers/lvgl/src/misc/lv_profiler_builtin.o ./Drivers/lvgl/src/misc/lv_profiler_builtin.su ./Drivers/lvgl/src/misc/lv_rb.cyclo ./Drivers/lvgl/src/misc/lv_rb.d ./Drivers/lvgl/src/misc/lv_rb.o ./Drivers/lvgl/src/misc/lv_rb.su ./Drivers/lvgl/src/misc/lv_style.cyclo ./Drivers/lvgl/src/misc/lv_style.d ./Drivers/lvgl/src/misc/lv_style.o ./Drivers/lvgl/src/misc/lv_style.su ./Drivers/lvgl/src/misc/lv_style_gen.cyclo ./Drivers/lvgl/src/misc/lv_style_gen.d ./Drivers/lvgl/src/misc/lv_style_gen.o ./Drivers/lvgl/src/misc/lv_style_gen.su ./Drivers/lvgl/src/misc/lv_templ.cyclo ./Drivers/lvgl/src/misc/lv_templ.d ./Drivers/lvgl/src/misc/lv_templ.o ./Drivers/lvgl/src/misc/lv_templ.su ./Drivers/lvgl/src/misc/lv_text.cyclo ./Drivers/lvgl/src/misc/lv_text.d ./Drivers/lvgl/src/misc/lv_text.o ./Drivers/lvgl/src/misc/lv_text.su ./Drivers/lvgl/src/misc/lv_text_ap.cyclo ./Drivers/lvgl/src/misc/lv_text_ap.d ./Drivers/lvgl/src/misc/lv_text_ap.o ./Drivers/lvgl/src/misc/lv_text_ap.su ./Drivers/lvgl/src/misc/lv_timer.cyclo ./Drivers/lvgl/src/misc/lv_timer.d ./Drivers/lvgl/src/misc/lv_timer.o ./Drivers/lvgl/src/misc/lv_timer.su ./Drivers/lvgl/src/misc/lv_tree.cyclo ./Drivers/lvgl/src/misc/lv_tree.d ./Drivers/lvgl/src/misc/lv_tree.o ./Drivers/lvgl/src/misc/lv_tree.su ./Drivers/lvgl/src/misc/lv_utils.cyclo ./Drivers/lvgl/src/misc/lv_utils.d ./Drivers/lvgl/src/misc/lv_utils.o ./Drivers/lvgl/src/misc/lv_utils.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-misc

