################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/lvgl/examples/others/observer/lv_example_observer_1.c \
../Core/Src/lvgl/examples/others/observer/lv_example_observer_2.c \
../Core/Src/lvgl/examples/others/observer/lv_example_observer_3.c \
../Core/Src/lvgl/examples/others/observer/lv_example_observer_4.c \
../Core/Src/lvgl/examples/others/observer/lv_example_observer_5.c \
../Core/Src/lvgl/examples/others/observer/lv_example_observer_6.c 

OBJS += \
./Core/Src/lvgl/examples/others/observer/lv_example_observer_1.o \
./Core/Src/lvgl/examples/others/observer/lv_example_observer_2.o \
./Core/Src/lvgl/examples/others/observer/lv_example_observer_3.o \
./Core/Src/lvgl/examples/others/observer/lv_example_observer_4.o \
./Core/Src/lvgl/examples/others/observer/lv_example_observer_5.o \
./Core/Src/lvgl/examples/others/observer/lv_example_observer_6.o 

C_DEPS += \
./Core/Src/lvgl/examples/others/observer/lv_example_observer_1.d \
./Core/Src/lvgl/examples/others/observer/lv_example_observer_2.d \
./Core/Src/lvgl/examples/others/observer/lv_example_observer_3.d \
./Core/Src/lvgl/examples/others/observer/lv_example_observer_4.d \
./Core/Src/lvgl/examples/others/observer/lv_example_observer_5.d \
./Core/Src/lvgl/examples/others/observer/lv_example_observer_6.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/lvgl/examples/others/observer/%.o Core/Src/lvgl/examples/others/observer/%.su Core/Src/lvgl/examples/others/observer/%.cyclo: ../Core/Src/lvgl/examples/others/observer/%.c Core/Src/lvgl/examples/others/observer/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H563xx -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-lvgl-2f-examples-2f-others-2f-observer

clean-Core-2f-Src-2f-lvgl-2f-examples-2f-others-2f-observer:
	-$(RM) ./Core/Src/lvgl/examples/others/observer/lv_example_observer_1.cyclo ./Core/Src/lvgl/examples/others/observer/lv_example_observer_1.d ./Core/Src/lvgl/examples/others/observer/lv_example_observer_1.o ./Core/Src/lvgl/examples/others/observer/lv_example_observer_1.su ./Core/Src/lvgl/examples/others/observer/lv_example_observer_2.cyclo ./Core/Src/lvgl/examples/others/observer/lv_example_observer_2.d ./Core/Src/lvgl/examples/others/observer/lv_example_observer_2.o ./Core/Src/lvgl/examples/others/observer/lv_example_observer_2.su ./Core/Src/lvgl/examples/others/observer/lv_example_observer_3.cyclo ./Core/Src/lvgl/examples/others/observer/lv_example_observer_3.d ./Core/Src/lvgl/examples/others/observer/lv_example_observer_3.o ./Core/Src/lvgl/examples/others/observer/lv_example_observer_3.su ./Core/Src/lvgl/examples/others/observer/lv_example_observer_4.cyclo ./Core/Src/lvgl/examples/others/observer/lv_example_observer_4.d ./Core/Src/lvgl/examples/others/observer/lv_example_observer_4.o ./Core/Src/lvgl/examples/others/observer/lv_example_observer_4.su ./Core/Src/lvgl/examples/others/observer/lv_example_observer_5.cyclo ./Core/Src/lvgl/examples/others/observer/lv_example_observer_5.d ./Core/Src/lvgl/examples/others/observer/lv_example_observer_5.o ./Core/Src/lvgl/examples/others/observer/lv_example_observer_5.su ./Core/Src/lvgl/examples/others/observer/lv_example_observer_6.cyclo ./Core/Src/lvgl/examples/others/observer/lv_example_observer_6.d ./Core/Src/lvgl/examples/others/observer/lv_example_observer_6.o ./Core/Src/lvgl/examples/others/observer/lv_example_observer_6.su

.PHONY: clean-Core-2f-Src-2f-lvgl-2f-examples-2f-others-2f-observer

