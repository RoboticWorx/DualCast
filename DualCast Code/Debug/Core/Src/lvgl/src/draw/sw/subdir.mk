################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/lvgl/src/draw/sw/lv_draw_sw.c \
../Core/Src/lvgl/src/draw/sw/lv_draw_sw_arc.c \
../Core/Src/lvgl/src/draw/sw/lv_draw_sw_border.c \
../Core/Src/lvgl/src/draw/sw/lv_draw_sw_box_shadow.c \
../Core/Src/lvgl/src/draw/sw/lv_draw_sw_fill.c \
../Core/Src/lvgl/src/draw/sw/lv_draw_sw_gradient.c \
../Core/Src/lvgl/src/draw/sw/lv_draw_sw_img.c \
../Core/Src/lvgl/src/draw/sw/lv_draw_sw_letter.c \
../Core/Src/lvgl/src/draw/sw/lv_draw_sw_line.c \
../Core/Src/lvgl/src/draw/sw/lv_draw_sw_mask.c \
../Core/Src/lvgl/src/draw/sw/lv_draw_sw_mask_rect.c \
../Core/Src/lvgl/src/draw/sw/lv_draw_sw_transform.c \
../Core/Src/lvgl/src/draw/sw/lv_draw_sw_triangle.c \
../Core/Src/lvgl/src/draw/sw/lv_draw_sw_utils.c \
../Core/Src/lvgl/src/draw/sw/lv_draw_sw_vector.c 

OBJS += \
./Core/Src/lvgl/src/draw/sw/lv_draw_sw.o \
./Core/Src/lvgl/src/draw/sw/lv_draw_sw_arc.o \
./Core/Src/lvgl/src/draw/sw/lv_draw_sw_border.o \
./Core/Src/lvgl/src/draw/sw/lv_draw_sw_box_shadow.o \
./Core/Src/lvgl/src/draw/sw/lv_draw_sw_fill.o \
./Core/Src/lvgl/src/draw/sw/lv_draw_sw_gradient.o \
./Core/Src/lvgl/src/draw/sw/lv_draw_sw_img.o \
./Core/Src/lvgl/src/draw/sw/lv_draw_sw_letter.o \
./Core/Src/lvgl/src/draw/sw/lv_draw_sw_line.o \
./Core/Src/lvgl/src/draw/sw/lv_draw_sw_mask.o \
./Core/Src/lvgl/src/draw/sw/lv_draw_sw_mask_rect.o \
./Core/Src/lvgl/src/draw/sw/lv_draw_sw_transform.o \
./Core/Src/lvgl/src/draw/sw/lv_draw_sw_triangle.o \
./Core/Src/lvgl/src/draw/sw/lv_draw_sw_utils.o \
./Core/Src/lvgl/src/draw/sw/lv_draw_sw_vector.o 

C_DEPS += \
./Core/Src/lvgl/src/draw/sw/lv_draw_sw.d \
./Core/Src/lvgl/src/draw/sw/lv_draw_sw_arc.d \
./Core/Src/lvgl/src/draw/sw/lv_draw_sw_border.d \
./Core/Src/lvgl/src/draw/sw/lv_draw_sw_box_shadow.d \
./Core/Src/lvgl/src/draw/sw/lv_draw_sw_fill.d \
./Core/Src/lvgl/src/draw/sw/lv_draw_sw_gradient.d \
./Core/Src/lvgl/src/draw/sw/lv_draw_sw_img.d \
./Core/Src/lvgl/src/draw/sw/lv_draw_sw_letter.d \
./Core/Src/lvgl/src/draw/sw/lv_draw_sw_line.d \
./Core/Src/lvgl/src/draw/sw/lv_draw_sw_mask.d \
./Core/Src/lvgl/src/draw/sw/lv_draw_sw_mask_rect.d \
./Core/Src/lvgl/src/draw/sw/lv_draw_sw_transform.d \
./Core/Src/lvgl/src/draw/sw/lv_draw_sw_triangle.d \
./Core/Src/lvgl/src/draw/sw/lv_draw_sw_utils.d \
./Core/Src/lvgl/src/draw/sw/lv_draw_sw_vector.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/lvgl/src/draw/sw/%.o Core/Src/lvgl/src/draw/sw/%.su Core/Src/lvgl/src/draw/sw/%.cyclo: ../Core/Src/lvgl/src/draw/sw/%.c Core/Src/lvgl/src/draw/sw/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H563xx -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-lvgl-2f-src-2f-draw-2f-sw

clean-Core-2f-Src-2f-lvgl-2f-src-2f-draw-2f-sw:
	-$(RM) ./Core/Src/lvgl/src/draw/sw/lv_draw_sw.cyclo ./Core/Src/lvgl/src/draw/sw/lv_draw_sw.d ./Core/Src/lvgl/src/draw/sw/lv_draw_sw.o ./Core/Src/lvgl/src/draw/sw/lv_draw_sw.su ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_arc.cyclo ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_arc.d ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_arc.o ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_arc.su ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_border.cyclo ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_border.d ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_border.o ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_border.su ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_box_shadow.cyclo ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_box_shadow.d ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_box_shadow.o ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_box_shadow.su ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_fill.cyclo ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_fill.d ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_fill.o ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_fill.su ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_gradient.cyclo ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_gradient.d ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_gradient.o ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_gradient.su ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_img.cyclo ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_img.d ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_img.o ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_img.su ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_letter.cyclo ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_letter.d ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_letter.o ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_letter.su ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_line.cyclo ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_line.d ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_line.o ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_line.su ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_mask.cyclo ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_mask.d ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_mask.o ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_mask.su ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_mask_rect.cyclo ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_mask_rect.d ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_mask_rect.o ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_mask_rect.su ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_transform.cyclo ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_transform.d ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_transform.o ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_transform.su ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_triangle.cyclo ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_triangle.d ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_triangle.o ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_triangle.su ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_utils.cyclo ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_utils.d ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_utils.o ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_utils.su ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_vector.cyclo ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_vector.d ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_vector.o ./Core/Src/lvgl/src/draw/sw/lv_draw_sw_vector.su

.PHONY: clean-Core-2f-Src-2f-lvgl-2f-src-2f-draw-2f-sw

