################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Media/lidar1.c \
../Core/Media/lidar2.c \
../Core/Media/lidar3.c \
../Core/Media/lidar4.c \
../Core/Media/lidar5.c \
../Core/Media/lidar6.c \
../Core/Media/lidar7.c \
../Core/Media/lidar8.c \
../Core/Media/lidar9.c \
../Core/Media/read_the_docs.c \
../Core/Media/wifi1.c \
../Core/Media/wifi2.c \
../Core/Media/wifi3.c \
../Core/Media/wifi4.c 

OBJS += \
./Core/Media/lidar1.o \
./Core/Media/lidar2.o \
./Core/Media/lidar3.o \
./Core/Media/lidar4.o \
./Core/Media/lidar5.o \
./Core/Media/lidar6.o \
./Core/Media/lidar7.o \
./Core/Media/lidar8.o \
./Core/Media/lidar9.o \
./Core/Media/read_the_docs.o \
./Core/Media/wifi1.o \
./Core/Media/wifi2.o \
./Core/Media/wifi3.o \
./Core/Media/wifi4.o 

C_DEPS += \
./Core/Media/lidar1.d \
./Core/Media/lidar2.d \
./Core/Media/lidar3.d \
./Core/Media/lidar4.d \
./Core/Media/lidar5.d \
./Core/Media/lidar6.d \
./Core/Media/lidar7.d \
./Core/Media/lidar8.d \
./Core/Media/lidar9.d \
./Core/Media/read_the_docs.d \
./Core/Media/wifi1.d \
./Core/Media/wifi2.d \
./Core/Media/wifi3.d \
./Core/Media/wifi4.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Media/%.o Core/Media/%.su Core/Media/%.cyclo: ../Core/Media/%.c Core/Media/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DLV_COLOR_16_SWAP=1 -DUSE_HAL_DRIVER -DSTM32H563xx -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/lvgl" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/sx126x" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/bmi323" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/bme280" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/vl53l4cx" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Core/Media" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/lvgl/src/misc" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/lvgl/src/stdlib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Media

clean-Core-2f-Media:
	-$(RM) ./Core/Media/lidar1.cyclo ./Core/Media/lidar1.d ./Core/Media/lidar1.o ./Core/Media/lidar1.su ./Core/Media/lidar2.cyclo ./Core/Media/lidar2.d ./Core/Media/lidar2.o ./Core/Media/lidar2.su ./Core/Media/lidar3.cyclo ./Core/Media/lidar3.d ./Core/Media/lidar3.o ./Core/Media/lidar3.su ./Core/Media/lidar4.cyclo ./Core/Media/lidar4.d ./Core/Media/lidar4.o ./Core/Media/lidar4.su ./Core/Media/lidar5.cyclo ./Core/Media/lidar5.d ./Core/Media/lidar5.o ./Core/Media/lidar5.su ./Core/Media/lidar6.cyclo ./Core/Media/lidar6.d ./Core/Media/lidar6.o ./Core/Media/lidar6.su ./Core/Media/lidar7.cyclo ./Core/Media/lidar7.d ./Core/Media/lidar7.o ./Core/Media/lidar7.su ./Core/Media/lidar8.cyclo ./Core/Media/lidar8.d ./Core/Media/lidar8.o ./Core/Media/lidar8.su ./Core/Media/lidar9.cyclo ./Core/Media/lidar9.d ./Core/Media/lidar9.o ./Core/Media/lidar9.su ./Core/Media/read_the_docs.cyclo ./Core/Media/read_the_docs.d ./Core/Media/read_the_docs.o ./Core/Media/read_the_docs.su ./Core/Media/wifi1.cyclo ./Core/Media/wifi1.d ./Core/Media/wifi1.o ./Core/Media/wifi1.su ./Core/Media/wifi2.cyclo ./Core/Media/wifi2.d ./Core/Media/wifi2.o ./Core/Media/wifi2.su ./Core/Media/wifi3.cyclo ./Core/Media/wifi3.d ./Core/Media/wifi3.o ./Core/Media/wifi3.su ./Core/Media/wifi4.cyclo ./Core/Media/wifi4.d ./Core/Media/wifi4.o ./Core/Media/wifi4.su

.PHONY: clean-Core-2f-Media

