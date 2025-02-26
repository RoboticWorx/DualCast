################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/lvgl/src/core/lv_group.c \
../Core/Src/lvgl/src/core/lv_obj.c \
../Core/Src/lvgl/src/core/lv_obj_class.c \
../Core/Src/lvgl/src/core/lv_obj_draw.c \
../Core/Src/lvgl/src/core/lv_obj_event.c \
../Core/Src/lvgl/src/core/lv_obj_id_builtin.c \
../Core/Src/lvgl/src/core/lv_obj_pos.c \
../Core/Src/lvgl/src/core/lv_obj_property.c \
../Core/Src/lvgl/src/core/lv_obj_scroll.c \
../Core/Src/lvgl/src/core/lv_obj_style.c \
../Core/Src/lvgl/src/core/lv_obj_style_gen.c \
../Core/Src/lvgl/src/core/lv_obj_tree.c \
../Core/Src/lvgl/src/core/lv_refr.c 

OBJS += \
./Core/Src/lvgl/src/core/lv_group.o \
./Core/Src/lvgl/src/core/lv_obj.o \
./Core/Src/lvgl/src/core/lv_obj_class.o \
./Core/Src/lvgl/src/core/lv_obj_draw.o \
./Core/Src/lvgl/src/core/lv_obj_event.o \
./Core/Src/lvgl/src/core/lv_obj_id_builtin.o \
./Core/Src/lvgl/src/core/lv_obj_pos.o \
./Core/Src/lvgl/src/core/lv_obj_property.o \
./Core/Src/lvgl/src/core/lv_obj_scroll.o \
./Core/Src/lvgl/src/core/lv_obj_style.o \
./Core/Src/lvgl/src/core/lv_obj_style_gen.o \
./Core/Src/lvgl/src/core/lv_obj_tree.o \
./Core/Src/lvgl/src/core/lv_refr.o 

C_DEPS += \
./Core/Src/lvgl/src/core/lv_group.d \
./Core/Src/lvgl/src/core/lv_obj.d \
./Core/Src/lvgl/src/core/lv_obj_class.d \
./Core/Src/lvgl/src/core/lv_obj_draw.d \
./Core/Src/lvgl/src/core/lv_obj_event.d \
./Core/Src/lvgl/src/core/lv_obj_id_builtin.d \
./Core/Src/lvgl/src/core/lv_obj_pos.d \
./Core/Src/lvgl/src/core/lv_obj_property.d \
./Core/Src/lvgl/src/core/lv_obj_scroll.d \
./Core/Src/lvgl/src/core/lv_obj_style.d \
./Core/Src/lvgl/src/core/lv_obj_style_gen.d \
./Core/Src/lvgl/src/core/lv_obj_tree.d \
./Core/Src/lvgl/src/core/lv_refr.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/lvgl/src/core/%.o Core/Src/lvgl/src/core/%.su Core/Src/lvgl/src/core/%.cyclo: ../Core/Src/lvgl/src/core/%.c Core/Src/lvgl/src/core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H563xx -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-lvgl-2f-src-2f-core

clean-Core-2f-Src-2f-lvgl-2f-src-2f-core:
	-$(RM) ./Core/Src/lvgl/src/core/lv_group.cyclo ./Core/Src/lvgl/src/core/lv_group.d ./Core/Src/lvgl/src/core/lv_group.o ./Core/Src/lvgl/src/core/lv_group.su ./Core/Src/lvgl/src/core/lv_obj.cyclo ./Core/Src/lvgl/src/core/lv_obj.d ./Core/Src/lvgl/src/core/lv_obj.o ./Core/Src/lvgl/src/core/lv_obj.su ./Core/Src/lvgl/src/core/lv_obj_class.cyclo ./Core/Src/lvgl/src/core/lv_obj_class.d ./Core/Src/lvgl/src/core/lv_obj_class.o ./Core/Src/lvgl/src/core/lv_obj_class.su ./Core/Src/lvgl/src/core/lv_obj_draw.cyclo ./Core/Src/lvgl/src/core/lv_obj_draw.d ./Core/Src/lvgl/src/core/lv_obj_draw.o ./Core/Src/lvgl/src/core/lv_obj_draw.su ./Core/Src/lvgl/src/core/lv_obj_event.cyclo ./Core/Src/lvgl/src/core/lv_obj_event.d ./Core/Src/lvgl/src/core/lv_obj_event.o ./Core/Src/lvgl/src/core/lv_obj_event.su ./Core/Src/lvgl/src/core/lv_obj_id_builtin.cyclo ./Core/Src/lvgl/src/core/lv_obj_id_builtin.d ./Core/Src/lvgl/src/core/lv_obj_id_builtin.o ./Core/Src/lvgl/src/core/lv_obj_id_builtin.su ./Core/Src/lvgl/src/core/lv_obj_pos.cyclo ./Core/Src/lvgl/src/core/lv_obj_pos.d ./Core/Src/lvgl/src/core/lv_obj_pos.o ./Core/Src/lvgl/src/core/lv_obj_pos.su ./Core/Src/lvgl/src/core/lv_obj_property.cyclo ./Core/Src/lvgl/src/core/lv_obj_property.d ./Core/Src/lvgl/src/core/lv_obj_property.o ./Core/Src/lvgl/src/core/lv_obj_property.su ./Core/Src/lvgl/src/core/lv_obj_scroll.cyclo ./Core/Src/lvgl/src/core/lv_obj_scroll.d ./Core/Src/lvgl/src/core/lv_obj_scroll.o ./Core/Src/lvgl/src/core/lv_obj_scroll.su ./Core/Src/lvgl/src/core/lv_obj_style.cyclo ./Core/Src/lvgl/src/core/lv_obj_style.d ./Core/Src/lvgl/src/core/lv_obj_style.o ./Core/Src/lvgl/src/core/lv_obj_style.su ./Core/Src/lvgl/src/core/lv_obj_style_gen.cyclo ./Core/Src/lvgl/src/core/lv_obj_style_gen.d ./Core/Src/lvgl/src/core/lv_obj_style_gen.o ./Core/Src/lvgl/src/core/lv_obj_style_gen.su ./Core/Src/lvgl/src/core/lv_obj_tree.cyclo ./Core/Src/lvgl/src/core/lv_obj_tree.d ./Core/Src/lvgl/src/core/lv_obj_tree.o ./Core/Src/lvgl/src/core/lv_obj_tree.su ./Core/Src/lvgl/src/core/lv_refr.cyclo ./Core/Src/lvgl/src/core/lv_refr.d ./Core/Src/lvgl/src/core/lv_refr.o ./Core/Src/lvgl/src/core/lv_refr.su

.PHONY: clean-Core-2f-Src-2f-lvgl-2f-src-2f-core

