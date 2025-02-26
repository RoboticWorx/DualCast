################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/lvgl/src/widgets/property/lv_dropdown_properties.c \
../Core/Src/lvgl/src/widgets/property/lv_image_properties.c \
../Core/Src/lvgl/src/widgets/property/lv_keyboard_properties.c \
../Core/Src/lvgl/src/widgets/property/lv_label_properties.c \
../Core/Src/lvgl/src/widgets/property/lv_obj_properties.c \
../Core/Src/lvgl/src/widgets/property/lv_roller_properties.c \
../Core/Src/lvgl/src/widgets/property/lv_style_properties.c \
../Core/Src/lvgl/src/widgets/property/lv_textarea_properties.c 

OBJS += \
./Core/Src/lvgl/src/widgets/property/lv_dropdown_properties.o \
./Core/Src/lvgl/src/widgets/property/lv_image_properties.o \
./Core/Src/lvgl/src/widgets/property/lv_keyboard_properties.o \
./Core/Src/lvgl/src/widgets/property/lv_label_properties.o \
./Core/Src/lvgl/src/widgets/property/lv_obj_properties.o \
./Core/Src/lvgl/src/widgets/property/lv_roller_properties.o \
./Core/Src/lvgl/src/widgets/property/lv_style_properties.o \
./Core/Src/lvgl/src/widgets/property/lv_textarea_properties.o 

C_DEPS += \
./Core/Src/lvgl/src/widgets/property/lv_dropdown_properties.d \
./Core/Src/lvgl/src/widgets/property/lv_image_properties.d \
./Core/Src/lvgl/src/widgets/property/lv_keyboard_properties.d \
./Core/Src/lvgl/src/widgets/property/lv_label_properties.d \
./Core/Src/lvgl/src/widgets/property/lv_obj_properties.d \
./Core/Src/lvgl/src/widgets/property/lv_roller_properties.d \
./Core/Src/lvgl/src/widgets/property/lv_style_properties.d \
./Core/Src/lvgl/src/widgets/property/lv_textarea_properties.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/lvgl/src/widgets/property/%.o Core/Src/lvgl/src/widgets/property/%.su Core/Src/lvgl/src/widgets/property/%.cyclo: ../Core/Src/lvgl/src/widgets/property/%.c Core/Src/lvgl/src/widgets/property/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H563xx -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-lvgl-2f-src-2f-widgets-2f-property

clean-Core-2f-Src-2f-lvgl-2f-src-2f-widgets-2f-property:
	-$(RM) ./Core/Src/lvgl/src/widgets/property/lv_dropdown_properties.cyclo ./Core/Src/lvgl/src/widgets/property/lv_dropdown_properties.d ./Core/Src/lvgl/src/widgets/property/lv_dropdown_properties.o ./Core/Src/lvgl/src/widgets/property/lv_dropdown_properties.su ./Core/Src/lvgl/src/widgets/property/lv_image_properties.cyclo ./Core/Src/lvgl/src/widgets/property/lv_image_properties.d ./Core/Src/lvgl/src/widgets/property/lv_image_properties.o ./Core/Src/lvgl/src/widgets/property/lv_image_properties.su ./Core/Src/lvgl/src/widgets/property/lv_keyboard_properties.cyclo ./Core/Src/lvgl/src/widgets/property/lv_keyboard_properties.d ./Core/Src/lvgl/src/widgets/property/lv_keyboard_properties.o ./Core/Src/lvgl/src/widgets/property/lv_keyboard_properties.su ./Core/Src/lvgl/src/widgets/property/lv_label_properties.cyclo ./Core/Src/lvgl/src/widgets/property/lv_label_properties.d ./Core/Src/lvgl/src/widgets/property/lv_label_properties.o ./Core/Src/lvgl/src/widgets/property/lv_label_properties.su ./Core/Src/lvgl/src/widgets/property/lv_obj_properties.cyclo ./Core/Src/lvgl/src/widgets/property/lv_obj_properties.d ./Core/Src/lvgl/src/widgets/property/lv_obj_properties.o ./Core/Src/lvgl/src/widgets/property/lv_obj_properties.su ./Core/Src/lvgl/src/widgets/property/lv_roller_properties.cyclo ./Core/Src/lvgl/src/widgets/property/lv_roller_properties.d ./Core/Src/lvgl/src/widgets/property/lv_roller_properties.o ./Core/Src/lvgl/src/widgets/property/lv_roller_properties.su ./Core/Src/lvgl/src/widgets/property/lv_style_properties.cyclo ./Core/Src/lvgl/src/widgets/property/lv_style_properties.d ./Core/Src/lvgl/src/widgets/property/lv_style_properties.o ./Core/Src/lvgl/src/widgets/property/lv_style_properties.su ./Core/Src/lvgl/src/widgets/property/lv_textarea_properties.cyclo ./Core/Src/lvgl/src/widgets/property/lv_textarea_properties.d ./Core/Src/lvgl/src/widgets/property/lv_textarea_properties.o ./Core/Src/lvgl/src/widgets/property/lv_textarea_properties.su

.PHONY: clean-Core-2f-Src-2f-lvgl-2f-src-2f-widgets-2f-property

