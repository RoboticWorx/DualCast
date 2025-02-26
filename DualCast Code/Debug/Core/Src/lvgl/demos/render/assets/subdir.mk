################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/lvgl/demos/render/assets/img_render_arc_bg.c \
../Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_argb8888.c \
../Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_i1.c \
../Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_l8.c \
../Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_rgb565.c \
../Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_rgb888.c \
../Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_xrgb8888.c 

OBJS += \
./Core/Src/lvgl/demos/render/assets/img_render_arc_bg.o \
./Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_argb8888.o \
./Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_i1.o \
./Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_l8.o \
./Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_rgb565.o \
./Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_rgb888.o \
./Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_xrgb8888.o 

C_DEPS += \
./Core/Src/lvgl/demos/render/assets/img_render_arc_bg.d \
./Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_argb8888.d \
./Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_i1.d \
./Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_l8.d \
./Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_rgb565.d \
./Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_rgb888.d \
./Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_xrgb8888.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/lvgl/demos/render/assets/%.o Core/Src/lvgl/demos/render/assets/%.su Core/Src/lvgl/demos/render/assets/%.cyclo: ../Core/Src/lvgl/demos/render/assets/%.c Core/Src/lvgl/demos/render/assets/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H563xx -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-lvgl-2f-demos-2f-render-2f-assets

clean-Core-2f-Src-2f-lvgl-2f-demos-2f-render-2f-assets:
	-$(RM) ./Core/Src/lvgl/demos/render/assets/img_render_arc_bg.cyclo ./Core/Src/lvgl/demos/render/assets/img_render_arc_bg.d ./Core/Src/lvgl/demos/render/assets/img_render_arc_bg.o ./Core/Src/lvgl/demos/render/assets/img_render_arc_bg.su ./Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_argb8888.cyclo ./Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_argb8888.d ./Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_argb8888.o ./Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_argb8888.su ./Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_i1.cyclo ./Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_i1.d ./Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_i1.o ./Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_i1.su ./Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_l8.cyclo ./Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_l8.d ./Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_l8.o ./Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_l8.su ./Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_rgb565.cyclo ./Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_rgb565.d ./Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_rgb565.o ./Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_rgb565.su ./Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_rgb888.cyclo ./Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_rgb888.d ./Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_rgb888.o ./Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_rgb888.su ./Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_xrgb8888.cyclo ./Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_xrgb8888.d ./Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_xrgb8888.o ./Core/Src/lvgl/demos/render/assets/img_render_lvgl_logo_xrgb8888.su

.PHONY: clean-Core-2f-Src-2f-lvgl-2f-demos-2f-render-2f-assets

