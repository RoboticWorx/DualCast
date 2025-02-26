################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_1.c \
../Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_10.c \
../Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_11.c \
../Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_12.c \
../Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_13.c \
../Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_14.c \
../Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_15.c \
../Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_16.c \
../Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_17.c \
../Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_18.c \
../Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_19.c \
../Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_2.c \
../Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_22.c \
../Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_25.c \
../Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_3.c \
../Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_4.c \
../Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_5.c \
../Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_6.c \
../Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_7.c \
../Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_8.c \
../Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_9.c 

OBJS += \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_1.o \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_10.o \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_11.o \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_12.o \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_13.o \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_14.o \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_15.o \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_16.o \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_17.o \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_18.o \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_19.o \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_2.o \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_22.o \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_25.o \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_3.o \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_4.o \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_5.o \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_6.o \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_7.o \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_8.o \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_9.o 

C_DEPS += \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_1.d \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_10.d \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_11.d \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_12.d \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_13.d \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_14.d \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_15.d \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_16.d \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_17.d \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_18.d \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_19.d \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_2.d \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_22.d \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_25.d \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_3.d \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_4.d \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_5.d \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_6.d \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_7.d \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_8.d \
./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_9.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/demos/multilang/assets/avatars/%.o Drivers/lvgl/demos/multilang/assets/avatars/%.su Drivers/lvgl/demos/multilang/assets/avatars/%.cyclo: ../Drivers/lvgl/demos/multilang/assets/avatars/%.c Drivers/lvgl/demos/multilang/assets/avatars/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DLV_COLOR_16_SWAP=1 -DUSE_HAL_DRIVER -DSTM32H563xx -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/lvgl" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/sx126x" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/bmi323" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/bme280" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/vl53l4cx" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Core/Media" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/lvgl/src/misc" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/lvgl/src/stdlib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-demos-2f-multilang-2f-assets-2f-avatars

clean-Drivers-2f-lvgl-2f-demos-2f-multilang-2f-assets-2f-avatars:
	-$(RM) ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_1.cyclo ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_1.d ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_1.o ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_1.su ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_10.cyclo ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_10.d ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_10.o ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_10.su ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_11.cyclo ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_11.d ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_11.o ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_11.su ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_12.cyclo ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_12.d ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_12.o ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_12.su ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_13.cyclo ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_13.d ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_13.o ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_13.su ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_14.cyclo ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_14.d ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_14.o ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_14.su ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_15.cyclo ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_15.d ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_15.o ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_15.su ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_16.cyclo ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_16.d ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_16.o ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_16.su ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_17.cyclo ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_17.d ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_17.o ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_17.su ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_18.cyclo ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_18.d ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_18.o ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_18.su ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_19.cyclo ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_19.d ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_19.o ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_19.su ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_2.cyclo ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_2.d ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_2.o ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_2.su ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_22.cyclo ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_22.d ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_22.o ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_22.su ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_25.cyclo ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_25.d ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_25.o ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_25.su ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_3.cyclo ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_3.d ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_3.o ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_3.su ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_4.cyclo ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_4.d ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_4.o ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_4.su ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_5.cyclo ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_5.d ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_5.o ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_5.su ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_6.cyclo ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_6.d ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_6.o ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_6.su ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_7.cyclo ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_7.d ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_7.o ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_7.su ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_8.cyclo ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_8.d ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_8.o ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_8.su ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_9.cyclo ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_9.d
	-$(RM) ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_9.o ./Drivers/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_9.su

.PHONY: clean-Drivers-2f-lvgl-2f-demos-2f-multilang-2f-assets-2f-avatars

