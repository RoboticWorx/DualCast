################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/lvgl/src/draw/nxp/pxp/lv_draw_buf_pxp.c \
../Core/Src/lvgl/src/draw/nxp/pxp/lv_draw_pxp.c \
../Core/Src/lvgl/src/draw/nxp/pxp/lv_draw_pxp_fill.c \
../Core/Src/lvgl/src/draw/nxp/pxp/lv_draw_pxp_img.c \
../Core/Src/lvgl/src/draw/nxp/pxp/lv_draw_pxp_layer.c \
../Core/Src/lvgl/src/draw/nxp/pxp/lv_pxp_cfg.c \
../Core/Src/lvgl/src/draw/nxp/pxp/lv_pxp_osa.c \
../Core/Src/lvgl/src/draw/nxp/pxp/lv_pxp_utils.c 

OBJS += \
./Core/Src/lvgl/src/draw/nxp/pxp/lv_draw_buf_pxp.o \
./Core/Src/lvgl/src/draw/nxp/pxp/lv_draw_pxp.o \
./Core/Src/lvgl/src/draw/nxp/pxp/lv_draw_pxp_fill.o \
./Core/Src/lvgl/src/draw/nxp/pxp/lv_draw_pxp_img.o \
./Core/Src/lvgl/src/draw/nxp/pxp/lv_draw_pxp_layer.o \
./Core/Src/lvgl/src/draw/nxp/pxp/lv_pxp_cfg.o \
./Core/Src/lvgl/src/draw/nxp/pxp/lv_pxp_osa.o \
./Core/Src/lvgl/src/draw/nxp/pxp/lv_pxp_utils.o 

C_DEPS += \
./Core/Src/lvgl/src/draw/nxp/pxp/lv_draw_buf_pxp.d \
./Core/Src/lvgl/src/draw/nxp/pxp/lv_draw_pxp.d \
./Core/Src/lvgl/src/draw/nxp/pxp/lv_draw_pxp_fill.d \
./Core/Src/lvgl/src/draw/nxp/pxp/lv_draw_pxp_img.d \
./Core/Src/lvgl/src/draw/nxp/pxp/lv_draw_pxp_layer.d \
./Core/Src/lvgl/src/draw/nxp/pxp/lv_pxp_cfg.d \
./Core/Src/lvgl/src/draw/nxp/pxp/lv_pxp_osa.d \
./Core/Src/lvgl/src/draw/nxp/pxp/lv_pxp_utils.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/lvgl/src/draw/nxp/pxp/%.o Core/Src/lvgl/src/draw/nxp/pxp/%.su Core/Src/lvgl/src/draw/nxp/pxp/%.cyclo: ../Core/Src/lvgl/src/draw/nxp/pxp/%.c Core/Src/lvgl/src/draw/nxp/pxp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H563xx -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-lvgl-2f-src-2f-draw-2f-nxp-2f-pxp

clean-Core-2f-Src-2f-lvgl-2f-src-2f-draw-2f-nxp-2f-pxp:
	-$(RM) ./Core/Src/lvgl/src/draw/nxp/pxp/lv_draw_buf_pxp.cyclo ./Core/Src/lvgl/src/draw/nxp/pxp/lv_draw_buf_pxp.d ./Core/Src/lvgl/src/draw/nxp/pxp/lv_draw_buf_pxp.o ./Core/Src/lvgl/src/draw/nxp/pxp/lv_draw_buf_pxp.su ./Core/Src/lvgl/src/draw/nxp/pxp/lv_draw_pxp.cyclo ./Core/Src/lvgl/src/draw/nxp/pxp/lv_draw_pxp.d ./Core/Src/lvgl/src/draw/nxp/pxp/lv_draw_pxp.o ./Core/Src/lvgl/src/draw/nxp/pxp/lv_draw_pxp.su ./Core/Src/lvgl/src/draw/nxp/pxp/lv_draw_pxp_fill.cyclo ./Core/Src/lvgl/src/draw/nxp/pxp/lv_draw_pxp_fill.d ./Core/Src/lvgl/src/draw/nxp/pxp/lv_draw_pxp_fill.o ./Core/Src/lvgl/src/draw/nxp/pxp/lv_draw_pxp_fill.su ./Core/Src/lvgl/src/draw/nxp/pxp/lv_draw_pxp_img.cyclo ./Core/Src/lvgl/src/draw/nxp/pxp/lv_draw_pxp_img.d ./Core/Src/lvgl/src/draw/nxp/pxp/lv_draw_pxp_img.o ./Core/Src/lvgl/src/draw/nxp/pxp/lv_draw_pxp_img.su ./Core/Src/lvgl/src/draw/nxp/pxp/lv_draw_pxp_layer.cyclo ./Core/Src/lvgl/src/draw/nxp/pxp/lv_draw_pxp_layer.d ./Core/Src/lvgl/src/draw/nxp/pxp/lv_draw_pxp_layer.o ./Core/Src/lvgl/src/draw/nxp/pxp/lv_draw_pxp_layer.su ./Core/Src/lvgl/src/draw/nxp/pxp/lv_pxp_cfg.cyclo ./Core/Src/lvgl/src/draw/nxp/pxp/lv_pxp_cfg.d ./Core/Src/lvgl/src/draw/nxp/pxp/lv_pxp_cfg.o ./Core/Src/lvgl/src/draw/nxp/pxp/lv_pxp_cfg.su ./Core/Src/lvgl/src/draw/nxp/pxp/lv_pxp_osa.cyclo ./Core/Src/lvgl/src/draw/nxp/pxp/lv_pxp_osa.d ./Core/Src/lvgl/src/draw/nxp/pxp/lv_pxp_osa.o ./Core/Src/lvgl/src/draw/nxp/pxp/lv_pxp_osa.su ./Core/Src/lvgl/src/draw/nxp/pxp/lv_pxp_utils.cyclo ./Core/Src/lvgl/src/draw/nxp/pxp/lv_pxp_utils.d ./Core/Src/lvgl/src/draw/nxp/pxp/lv_pxp_utils.o ./Core/Src/lvgl/src/draw/nxp/pxp/lv_pxp_utils.su

.PHONY: clean-Core-2f-Src-2f-lvgl-2f-src-2f-draw-2f-nxp-2f-pxp

