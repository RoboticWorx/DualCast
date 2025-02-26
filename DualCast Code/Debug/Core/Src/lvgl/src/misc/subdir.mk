################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/lvgl/src/misc/lv_anim.c \
../Core/Src/lvgl/src/misc/lv_anim_timeline.c \
../Core/Src/lvgl/src/misc/lv_area.c \
../Core/Src/lvgl/src/misc/lv_array.c \
../Core/Src/lvgl/src/misc/lv_async.c \
../Core/Src/lvgl/src/misc/lv_bidi.c \
../Core/Src/lvgl/src/misc/lv_circle_buf.c \
../Core/Src/lvgl/src/misc/lv_color.c \
../Core/Src/lvgl/src/misc/lv_color_op.c \
../Core/Src/lvgl/src/misc/lv_event.c \
../Core/Src/lvgl/src/misc/lv_fs.c \
../Core/Src/lvgl/src/misc/lv_iter.c \
../Core/Src/lvgl/src/misc/lv_ll.c \
../Core/Src/lvgl/src/misc/lv_log.c \
../Core/Src/lvgl/src/misc/lv_lru.c \
../Core/Src/lvgl/src/misc/lv_math.c \
../Core/Src/lvgl/src/misc/lv_matrix.c \
../Core/Src/lvgl/src/misc/lv_palette.c \
../Core/Src/lvgl/src/misc/lv_profiler_builtin.c \
../Core/Src/lvgl/src/misc/lv_rb.c \
../Core/Src/lvgl/src/misc/lv_style.c \
../Core/Src/lvgl/src/misc/lv_style_gen.c \
../Core/Src/lvgl/src/misc/lv_templ.c \
../Core/Src/lvgl/src/misc/lv_text.c \
../Core/Src/lvgl/src/misc/lv_text_ap.c \
../Core/Src/lvgl/src/misc/lv_timer.c \
../Core/Src/lvgl/src/misc/lv_tree.c \
../Core/Src/lvgl/src/misc/lv_utils.c 

OBJS += \
./Core/Src/lvgl/src/misc/lv_anim.o \
./Core/Src/lvgl/src/misc/lv_anim_timeline.o \
./Core/Src/lvgl/src/misc/lv_area.o \
./Core/Src/lvgl/src/misc/lv_array.o \
./Core/Src/lvgl/src/misc/lv_async.o \
./Core/Src/lvgl/src/misc/lv_bidi.o \
./Core/Src/lvgl/src/misc/lv_circle_buf.o \
./Core/Src/lvgl/src/misc/lv_color.o \
./Core/Src/lvgl/src/misc/lv_color_op.o \
./Core/Src/lvgl/src/misc/lv_event.o \
./Core/Src/lvgl/src/misc/lv_fs.o \
./Core/Src/lvgl/src/misc/lv_iter.o \
./Core/Src/lvgl/src/misc/lv_ll.o \
./Core/Src/lvgl/src/misc/lv_log.o \
./Core/Src/lvgl/src/misc/lv_lru.o \
./Core/Src/lvgl/src/misc/lv_math.o \
./Core/Src/lvgl/src/misc/lv_matrix.o \
./Core/Src/lvgl/src/misc/lv_palette.o \
./Core/Src/lvgl/src/misc/lv_profiler_builtin.o \
./Core/Src/lvgl/src/misc/lv_rb.o \
./Core/Src/lvgl/src/misc/lv_style.o \
./Core/Src/lvgl/src/misc/lv_style_gen.o \
./Core/Src/lvgl/src/misc/lv_templ.o \
./Core/Src/lvgl/src/misc/lv_text.o \
./Core/Src/lvgl/src/misc/lv_text_ap.o \
./Core/Src/lvgl/src/misc/lv_timer.o \
./Core/Src/lvgl/src/misc/lv_tree.o \
./Core/Src/lvgl/src/misc/lv_utils.o 

C_DEPS += \
./Core/Src/lvgl/src/misc/lv_anim.d \
./Core/Src/lvgl/src/misc/lv_anim_timeline.d \
./Core/Src/lvgl/src/misc/lv_area.d \
./Core/Src/lvgl/src/misc/lv_array.d \
./Core/Src/lvgl/src/misc/lv_async.d \
./Core/Src/lvgl/src/misc/lv_bidi.d \
./Core/Src/lvgl/src/misc/lv_circle_buf.d \
./Core/Src/lvgl/src/misc/lv_color.d \
./Core/Src/lvgl/src/misc/lv_color_op.d \
./Core/Src/lvgl/src/misc/lv_event.d \
./Core/Src/lvgl/src/misc/lv_fs.d \
./Core/Src/lvgl/src/misc/lv_iter.d \
./Core/Src/lvgl/src/misc/lv_ll.d \
./Core/Src/lvgl/src/misc/lv_log.d \
./Core/Src/lvgl/src/misc/lv_lru.d \
./Core/Src/lvgl/src/misc/lv_math.d \
./Core/Src/lvgl/src/misc/lv_matrix.d \
./Core/Src/lvgl/src/misc/lv_palette.d \
./Core/Src/lvgl/src/misc/lv_profiler_builtin.d \
./Core/Src/lvgl/src/misc/lv_rb.d \
./Core/Src/lvgl/src/misc/lv_style.d \
./Core/Src/lvgl/src/misc/lv_style_gen.d \
./Core/Src/lvgl/src/misc/lv_templ.d \
./Core/Src/lvgl/src/misc/lv_text.d \
./Core/Src/lvgl/src/misc/lv_text_ap.d \
./Core/Src/lvgl/src/misc/lv_timer.d \
./Core/Src/lvgl/src/misc/lv_tree.d \
./Core/Src/lvgl/src/misc/lv_utils.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/lvgl/src/misc/%.o Core/Src/lvgl/src/misc/%.su Core/Src/lvgl/src/misc/%.cyclo: ../Core/Src/lvgl/src/misc/%.c Core/Src/lvgl/src/misc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H563xx -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-lvgl-2f-src-2f-misc

clean-Core-2f-Src-2f-lvgl-2f-src-2f-misc:
	-$(RM) ./Core/Src/lvgl/src/misc/lv_anim.cyclo ./Core/Src/lvgl/src/misc/lv_anim.d ./Core/Src/lvgl/src/misc/lv_anim.o ./Core/Src/lvgl/src/misc/lv_anim.su ./Core/Src/lvgl/src/misc/lv_anim_timeline.cyclo ./Core/Src/lvgl/src/misc/lv_anim_timeline.d ./Core/Src/lvgl/src/misc/lv_anim_timeline.o ./Core/Src/lvgl/src/misc/lv_anim_timeline.su ./Core/Src/lvgl/src/misc/lv_area.cyclo ./Core/Src/lvgl/src/misc/lv_area.d ./Core/Src/lvgl/src/misc/lv_area.o ./Core/Src/lvgl/src/misc/lv_area.su ./Core/Src/lvgl/src/misc/lv_array.cyclo ./Core/Src/lvgl/src/misc/lv_array.d ./Core/Src/lvgl/src/misc/lv_array.o ./Core/Src/lvgl/src/misc/lv_array.su ./Core/Src/lvgl/src/misc/lv_async.cyclo ./Core/Src/lvgl/src/misc/lv_async.d ./Core/Src/lvgl/src/misc/lv_async.o ./Core/Src/lvgl/src/misc/lv_async.su ./Core/Src/lvgl/src/misc/lv_bidi.cyclo ./Core/Src/lvgl/src/misc/lv_bidi.d ./Core/Src/lvgl/src/misc/lv_bidi.o ./Core/Src/lvgl/src/misc/lv_bidi.su ./Core/Src/lvgl/src/misc/lv_circle_buf.cyclo ./Core/Src/lvgl/src/misc/lv_circle_buf.d ./Core/Src/lvgl/src/misc/lv_circle_buf.o ./Core/Src/lvgl/src/misc/lv_circle_buf.su ./Core/Src/lvgl/src/misc/lv_color.cyclo ./Core/Src/lvgl/src/misc/lv_color.d ./Core/Src/lvgl/src/misc/lv_color.o ./Core/Src/lvgl/src/misc/lv_color.su ./Core/Src/lvgl/src/misc/lv_color_op.cyclo ./Core/Src/lvgl/src/misc/lv_color_op.d ./Core/Src/lvgl/src/misc/lv_color_op.o ./Core/Src/lvgl/src/misc/lv_color_op.su ./Core/Src/lvgl/src/misc/lv_event.cyclo ./Core/Src/lvgl/src/misc/lv_event.d ./Core/Src/lvgl/src/misc/lv_event.o ./Core/Src/lvgl/src/misc/lv_event.su ./Core/Src/lvgl/src/misc/lv_fs.cyclo ./Core/Src/lvgl/src/misc/lv_fs.d ./Core/Src/lvgl/src/misc/lv_fs.o ./Core/Src/lvgl/src/misc/lv_fs.su ./Core/Src/lvgl/src/misc/lv_iter.cyclo ./Core/Src/lvgl/src/misc/lv_iter.d ./Core/Src/lvgl/src/misc/lv_iter.o ./Core/Src/lvgl/src/misc/lv_iter.su ./Core/Src/lvgl/src/misc/lv_ll.cyclo ./Core/Src/lvgl/src/misc/lv_ll.d ./Core/Src/lvgl/src/misc/lv_ll.o ./Core/Src/lvgl/src/misc/lv_ll.su ./Core/Src/lvgl/src/misc/lv_log.cyclo ./Core/Src/lvgl/src/misc/lv_log.d ./Core/Src/lvgl/src/misc/lv_log.o ./Core/Src/lvgl/src/misc/lv_log.su ./Core/Src/lvgl/src/misc/lv_lru.cyclo ./Core/Src/lvgl/src/misc/lv_lru.d ./Core/Src/lvgl/src/misc/lv_lru.o ./Core/Src/lvgl/src/misc/lv_lru.su ./Core/Src/lvgl/src/misc/lv_math.cyclo ./Core/Src/lvgl/src/misc/lv_math.d ./Core/Src/lvgl/src/misc/lv_math.o ./Core/Src/lvgl/src/misc/lv_math.su ./Core/Src/lvgl/src/misc/lv_matrix.cyclo ./Core/Src/lvgl/src/misc/lv_matrix.d ./Core/Src/lvgl/src/misc/lv_matrix.o ./Core/Src/lvgl/src/misc/lv_matrix.su ./Core/Src/lvgl/src/misc/lv_palette.cyclo ./Core/Src/lvgl/src/misc/lv_palette.d ./Core/Src/lvgl/src/misc/lv_palette.o ./Core/Src/lvgl/src/misc/lv_palette.su ./Core/Src/lvgl/src/misc/lv_profiler_builtin.cyclo ./Core/Src/lvgl/src/misc/lv_profiler_builtin.d ./Core/Src/lvgl/src/misc/lv_profiler_builtin.o ./Core/Src/lvgl/src/misc/lv_profiler_builtin.su ./Core/Src/lvgl/src/misc/lv_rb.cyclo ./Core/Src/lvgl/src/misc/lv_rb.d ./Core/Src/lvgl/src/misc/lv_rb.o ./Core/Src/lvgl/src/misc/lv_rb.su ./Core/Src/lvgl/src/misc/lv_style.cyclo ./Core/Src/lvgl/src/misc/lv_style.d ./Core/Src/lvgl/src/misc/lv_style.o ./Core/Src/lvgl/src/misc/lv_style.su ./Core/Src/lvgl/src/misc/lv_style_gen.cyclo ./Core/Src/lvgl/src/misc/lv_style_gen.d ./Core/Src/lvgl/src/misc/lv_style_gen.o ./Core/Src/lvgl/src/misc/lv_style_gen.su ./Core/Src/lvgl/src/misc/lv_templ.cyclo ./Core/Src/lvgl/src/misc/lv_templ.d ./Core/Src/lvgl/src/misc/lv_templ.o ./Core/Src/lvgl/src/misc/lv_templ.su ./Core/Src/lvgl/src/misc/lv_text.cyclo ./Core/Src/lvgl/src/misc/lv_text.d ./Core/Src/lvgl/src/misc/lv_text.o ./Core/Src/lvgl/src/misc/lv_text.su ./Core/Src/lvgl/src/misc/lv_text_ap.cyclo ./Core/Src/lvgl/src/misc/lv_text_ap.d ./Core/Src/lvgl/src/misc/lv_text_ap.o ./Core/Src/lvgl/src/misc/lv_text_ap.su ./Core/Src/lvgl/src/misc/lv_timer.cyclo ./Core/Src/lvgl/src/misc/lv_timer.d ./Core/Src/lvgl/src/misc/lv_timer.o ./Core/Src/lvgl/src/misc/lv_timer.su ./Core/Src/lvgl/src/misc/lv_tree.cyclo ./Core/Src/lvgl/src/misc/lv_tree.d ./Core/Src/lvgl/src/misc/lv_tree.o ./Core/Src/lvgl/src/misc/lv_tree.su ./Core/Src/lvgl/src/misc/lv_utils.cyclo ./Core/Src/lvgl/src/misc/lv_utils.d ./Core/Src/lvgl/src/misc/lv_utils.o ./Core/Src/lvgl/src/misc/lv_utils.su

.PHONY: clean-Core-2f-Src-2f-lvgl-2f-src-2f-misc

