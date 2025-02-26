################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/lvgl/src/others/vg_lite_tvg/vg_lite_matrix.c 

OBJS += \
./Core/Src/lvgl/src/others/vg_lite_tvg/vg_lite_matrix.o 

C_DEPS += \
./Core/Src/lvgl/src/others/vg_lite_tvg/vg_lite_matrix.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/lvgl/src/others/vg_lite_tvg/%.o Core/Src/lvgl/src/others/vg_lite_tvg/%.su Core/Src/lvgl/src/others/vg_lite_tvg/%.cyclo: ../Core/Src/lvgl/src/others/vg_lite_tvg/%.c Core/Src/lvgl/src/others/vg_lite_tvg/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H563xx -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-lvgl-2f-src-2f-others-2f-vg_lite_tvg

clean-Core-2f-Src-2f-lvgl-2f-src-2f-others-2f-vg_lite_tvg:
	-$(RM) ./Core/Src/lvgl/src/others/vg_lite_tvg/vg_lite_matrix.cyclo ./Core/Src/lvgl/src/others/vg_lite_tvg/vg_lite_matrix.d ./Core/Src/lvgl/src/others/vg_lite_tvg/vg_lite_matrix.o ./Core/Src/lvgl/src/others/vg_lite_tvg/vg_lite_matrix.su

.PHONY: clean-Core-2f-Src-2f-lvgl-2f-src-2f-others-2f-vg_lite_tvg

