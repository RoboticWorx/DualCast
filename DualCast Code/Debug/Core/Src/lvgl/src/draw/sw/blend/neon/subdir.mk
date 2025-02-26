################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../Core/Src/lvgl/src/draw/sw/blend/neon/lv_blend_neon.S 

OBJS += \
./Core/Src/lvgl/src/draw/sw/blend/neon/lv_blend_neon.o 

S_UPPER_DEPS += \
./Core/Src/lvgl/src/draw/sw/blend/neon/lv_blend_neon.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/lvgl/src/draw/sw/blend/neon/%.o: ../Core/Src/lvgl/src/draw/sw/blend/neon/%.S Core/Src/lvgl/src/draw/sw/blend/neon/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m33 -g3 -DDEBUG -c -I"C:/Users/Jatki/OneDrive/Documents/STM/RFoRa/Core/Src/lvgl" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Core-2f-Src-2f-lvgl-2f-src-2f-draw-2f-sw-2f-blend-2f-neon

clean-Core-2f-Src-2f-lvgl-2f-src-2f-draw-2f-sw-2f-blend-2f-neon:
	-$(RM) ./Core/Src/lvgl/src/draw/sw/blend/neon/lv_blend_neon.d ./Core/Src/lvgl/src/draw/sw/blend/neon/lv_blend_neon.o

.PHONY: clean-Core-2f-Src-2f-lvgl-2f-src-2f-draw-2f-sw-2f-blend-2f-neon

