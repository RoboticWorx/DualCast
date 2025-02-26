################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/lvgl/examples/styles/lv_example_style_1.c \
../Core/Src/lvgl/examples/styles/lv_example_style_10.c \
../Core/Src/lvgl/examples/styles/lv_example_style_11.c \
../Core/Src/lvgl/examples/styles/lv_example_style_12.c \
../Core/Src/lvgl/examples/styles/lv_example_style_13.c \
../Core/Src/lvgl/examples/styles/lv_example_style_14.c \
../Core/Src/lvgl/examples/styles/lv_example_style_15.c \
../Core/Src/lvgl/examples/styles/lv_example_style_16.c \
../Core/Src/lvgl/examples/styles/lv_example_style_17.c \
../Core/Src/lvgl/examples/styles/lv_example_style_18.c \
../Core/Src/lvgl/examples/styles/lv_example_style_2.c \
../Core/Src/lvgl/examples/styles/lv_example_style_3.c \
../Core/Src/lvgl/examples/styles/lv_example_style_4.c \
../Core/Src/lvgl/examples/styles/lv_example_style_5.c \
../Core/Src/lvgl/examples/styles/lv_example_style_6.c \
../Core/Src/lvgl/examples/styles/lv_example_style_7.c \
../Core/Src/lvgl/examples/styles/lv_example_style_8.c \
../Core/Src/lvgl/examples/styles/lv_example_style_9.c 

OBJS += \
./Core/Src/lvgl/examples/styles/lv_example_style_1.o \
./Core/Src/lvgl/examples/styles/lv_example_style_10.o \
./Core/Src/lvgl/examples/styles/lv_example_style_11.o \
./Core/Src/lvgl/examples/styles/lv_example_style_12.o \
./Core/Src/lvgl/examples/styles/lv_example_style_13.o \
./Core/Src/lvgl/examples/styles/lv_example_style_14.o \
./Core/Src/lvgl/examples/styles/lv_example_style_15.o \
./Core/Src/lvgl/examples/styles/lv_example_style_16.o \
./Core/Src/lvgl/examples/styles/lv_example_style_17.o \
./Core/Src/lvgl/examples/styles/lv_example_style_18.o \
./Core/Src/lvgl/examples/styles/lv_example_style_2.o \
./Core/Src/lvgl/examples/styles/lv_example_style_3.o \
./Core/Src/lvgl/examples/styles/lv_example_style_4.o \
./Core/Src/lvgl/examples/styles/lv_example_style_5.o \
./Core/Src/lvgl/examples/styles/lv_example_style_6.o \
./Core/Src/lvgl/examples/styles/lv_example_style_7.o \
./Core/Src/lvgl/examples/styles/lv_example_style_8.o \
./Core/Src/lvgl/examples/styles/lv_example_style_9.o 

C_DEPS += \
./Core/Src/lvgl/examples/styles/lv_example_style_1.d \
./Core/Src/lvgl/examples/styles/lv_example_style_10.d \
./Core/Src/lvgl/examples/styles/lv_example_style_11.d \
./Core/Src/lvgl/examples/styles/lv_example_style_12.d \
./Core/Src/lvgl/examples/styles/lv_example_style_13.d \
./Core/Src/lvgl/examples/styles/lv_example_style_14.d \
./Core/Src/lvgl/examples/styles/lv_example_style_15.d \
./Core/Src/lvgl/examples/styles/lv_example_style_16.d \
./Core/Src/lvgl/examples/styles/lv_example_style_17.d \
./Core/Src/lvgl/examples/styles/lv_example_style_18.d \
./Core/Src/lvgl/examples/styles/lv_example_style_2.d \
./Core/Src/lvgl/examples/styles/lv_example_style_3.d \
./Core/Src/lvgl/examples/styles/lv_example_style_4.d \
./Core/Src/lvgl/examples/styles/lv_example_style_5.d \
./Core/Src/lvgl/examples/styles/lv_example_style_6.d \
./Core/Src/lvgl/examples/styles/lv_example_style_7.d \
./Core/Src/lvgl/examples/styles/lv_example_style_8.d \
./Core/Src/lvgl/examples/styles/lv_example_style_9.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/lvgl/examples/styles/%.o Core/Src/lvgl/examples/styles/%.su Core/Src/lvgl/examples/styles/%.cyclo: ../Core/Src/lvgl/examples/styles/%.c Core/Src/lvgl/examples/styles/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H563xx -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-lvgl-2f-examples-2f-styles

clean-Core-2f-Src-2f-lvgl-2f-examples-2f-styles:
	-$(RM) ./Core/Src/lvgl/examples/styles/lv_example_style_1.cyclo ./Core/Src/lvgl/examples/styles/lv_example_style_1.d ./Core/Src/lvgl/examples/styles/lv_example_style_1.o ./Core/Src/lvgl/examples/styles/lv_example_style_1.su ./Core/Src/lvgl/examples/styles/lv_example_style_10.cyclo ./Core/Src/lvgl/examples/styles/lv_example_style_10.d ./Core/Src/lvgl/examples/styles/lv_example_style_10.o ./Core/Src/lvgl/examples/styles/lv_example_style_10.su ./Core/Src/lvgl/examples/styles/lv_example_style_11.cyclo ./Core/Src/lvgl/examples/styles/lv_example_style_11.d ./Core/Src/lvgl/examples/styles/lv_example_style_11.o ./Core/Src/lvgl/examples/styles/lv_example_style_11.su ./Core/Src/lvgl/examples/styles/lv_example_style_12.cyclo ./Core/Src/lvgl/examples/styles/lv_example_style_12.d ./Core/Src/lvgl/examples/styles/lv_example_style_12.o ./Core/Src/lvgl/examples/styles/lv_example_style_12.su ./Core/Src/lvgl/examples/styles/lv_example_style_13.cyclo ./Core/Src/lvgl/examples/styles/lv_example_style_13.d ./Core/Src/lvgl/examples/styles/lv_example_style_13.o ./Core/Src/lvgl/examples/styles/lv_example_style_13.su ./Core/Src/lvgl/examples/styles/lv_example_style_14.cyclo ./Core/Src/lvgl/examples/styles/lv_example_style_14.d ./Core/Src/lvgl/examples/styles/lv_example_style_14.o ./Core/Src/lvgl/examples/styles/lv_example_style_14.su ./Core/Src/lvgl/examples/styles/lv_example_style_15.cyclo ./Core/Src/lvgl/examples/styles/lv_example_style_15.d ./Core/Src/lvgl/examples/styles/lv_example_style_15.o ./Core/Src/lvgl/examples/styles/lv_example_style_15.su ./Core/Src/lvgl/examples/styles/lv_example_style_16.cyclo ./Core/Src/lvgl/examples/styles/lv_example_style_16.d ./Core/Src/lvgl/examples/styles/lv_example_style_16.o ./Core/Src/lvgl/examples/styles/lv_example_style_16.su ./Core/Src/lvgl/examples/styles/lv_example_style_17.cyclo ./Core/Src/lvgl/examples/styles/lv_example_style_17.d ./Core/Src/lvgl/examples/styles/lv_example_style_17.o ./Core/Src/lvgl/examples/styles/lv_example_style_17.su ./Core/Src/lvgl/examples/styles/lv_example_style_18.cyclo ./Core/Src/lvgl/examples/styles/lv_example_style_18.d ./Core/Src/lvgl/examples/styles/lv_example_style_18.o ./Core/Src/lvgl/examples/styles/lv_example_style_18.su ./Core/Src/lvgl/examples/styles/lv_example_style_2.cyclo ./Core/Src/lvgl/examples/styles/lv_example_style_2.d ./Core/Src/lvgl/examples/styles/lv_example_style_2.o ./Core/Src/lvgl/examples/styles/lv_example_style_2.su ./Core/Src/lvgl/examples/styles/lv_example_style_3.cyclo ./Core/Src/lvgl/examples/styles/lv_example_style_3.d ./Core/Src/lvgl/examples/styles/lv_example_style_3.o ./Core/Src/lvgl/examples/styles/lv_example_style_3.su ./Core/Src/lvgl/examples/styles/lv_example_style_4.cyclo ./Core/Src/lvgl/examples/styles/lv_example_style_4.d ./Core/Src/lvgl/examples/styles/lv_example_style_4.o ./Core/Src/lvgl/examples/styles/lv_example_style_4.su ./Core/Src/lvgl/examples/styles/lv_example_style_5.cyclo ./Core/Src/lvgl/examples/styles/lv_example_style_5.d ./Core/Src/lvgl/examples/styles/lv_example_style_5.o ./Core/Src/lvgl/examples/styles/lv_example_style_5.su ./Core/Src/lvgl/examples/styles/lv_example_style_6.cyclo ./Core/Src/lvgl/examples/styles/lv_example_style_6.d ./Core/Src/lvgl/examples/styles/lv_example_style_6.o ./Core/Src/lvgl/examples/styles/lv_example_style_6.su ./Core/Src/lvgl/examples/styles/lv_example_style_7.cyclo ./Core/Src/lvgl/examples/styles/lv_example_style_7.d ./Core/Src/lvgl/examples/styles/lv_example_style_7.o ./Core/Src/lvgl/examples/styles/lv_example_style_7.su ./Core/Src/lvgl/examples/styles/lv_example_style_8.cyclo ./Core/Src/lvgl/examples/styles/lv_example_style_8.d ./Core/Src/lvgl/examples/styles/lv_example_style_8.o ./Core/Src/lvgl/examples/styles/lv_example_style_8.su ./Core/Src/lvgl/examples/styles/lv_example_style_9.cyclo ./Core/Src/lvgl/examples/styles/lv_example_style_9.d ./Core/Src/lvgl/examples/styles/lv_example_style_9.o ./Core/Src/lvgl/examples/styles/lv_example_style_9.su

.PHONY: clean-Core-2f-Src-2f-lvgl-2f-examples-2f-styles

