################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/lvgl/env_support/rt-thread/lv_rt_thread_port.c 

OBJS += \
./Core/Src/lvgl/env_support/rt-thread/lv_rt_thread_port.o 

C_DEPS += \
./Core/Src/lvgl/env_support/rt-thread/lv_rt_thread_port.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/lvgl/env_support/rt-thread/%.o Core/Src/lvgl/env_support/rt-thread/%.su Core/Src/lvgl/env_support/rt-thread/%.cyclo: ../Core/Src/lvgl/env_support/rt-thread/%.c Core/Src/lvgl/env_support/rt-thread/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H563xx -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-lvgl-2f-env_support-2f-rt-2d-thread

clean-Core-2f-Src-2f-lvgl-2f-env_support-2f-rt-2d-thread:
	-$(RM) ./Core/Src/lvgl/env_support/rt-thread/lv_rt_thread_port.cyclo ./Core/Src/lvgl/env_support/rt-thread/lv_rt_thread_port.d ./Core/Src/lvgl/env_support/rt-thread/lv_rt_thread_port.o ./Core/Src/lvgl/env_support/rt-thread/lv_rt_thread_port.su

.PHONY: clean-Core-2f-Src-2f-lvgl-2f-env_support-2f-rt-2d-thread

