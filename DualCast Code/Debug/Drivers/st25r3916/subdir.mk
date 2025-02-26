################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/st25r3916/rfal_rfst25r3916.c \
../Drivers/st25r3916/st25r3916.c \
../Drivers/st25r3916/st25r3916_aat.c \
../Drivers/st25r3916/st25r3916_com.c \
../Drivers/st25r3916/st25r3916_irq.c \
../Drivers/st25r3916/st25r3916_led.c \
../Drivers/st25r3916/timer.c 

OBJS += \
./Drivers/st25r3916/rfal_rfst25r3916.o \
./Drivers/st25r3916/st25r3916.o \
./Drivers/st25r3916/st25r3916_aat.o \
./Drivers/st25r3916/st25r3916_com.o \
./Drivers/st25r3916/st25r3916_irq.o \
./Drivers/st25r3916/st25r3916_led.o \
./Drivers/st25r3916/timer.o 

C_DEPS += \
./Drivers/st25r3916/rfal_rfst25r3916.d \
./Drivers/st25r3916/st25r3916.d \
./Drivers/st25r3916/st25r3916_aat.d \
./Drivers/st25r3916/st25r3916_com.d \
./Drivers/st25r3916/st25r3916_irq.d \
./Drivers/st25r3916/st25r3916_led.d \
./Drivers/st25r3916/timer.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/st25r3916/%.o Drivers/st25r3916/%.su Drivers/st25r3916/%.cyclo: ../Drivers/st25r3916/%.c Drivers/st25r3916/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DST25R3916 -DUSE_HAL_DRIVER -DSTM32H563xx -DLV_COLOR_16_SWAP=1 -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -I"C:/Users/Jatki/OneDrive/Documents/STM/RFoRa/Drivers/lvgl" -I"C:/Users/Jatki/OneDrive/Documents/STM/RFoRa/Drivers/sx126x" -I"C:/Users/Jatki/OneDrive/Documents/STM/RFoRa/Drivers/st25r3916" -I"C:/Users/Jatki/OneDrive/Documents/STM/RFoRa/Middlewares/rfal" -I"C:/Users/Jatki/OneDrive/Documents/STM/RFoRa/Middlewares/rfal/Inc" -I"C:/Users/Jatki/OneDrive/Documents/STM/RFoRa/Middlewares/rfal/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-st25r3916

clean-Drivers-2f-st25r3916:
	-$(RM) ./Drivers/st25r3916/rfal_rfst25r3916.cyclo ./Drivers/st25r3916/rfal_rfst25r3916.d ./Drivers/st25r3916/rfal_rfst25r3916.o ./Drivers/st25r3916/rfal_rfst25r3916.su ./Drivers/st25r3916/st25r3916.cyclo ./Drivers/st25r3916/st25r3916.d ./Drivers/st25r3916/st25r3916.o ./Drivers/st25r3916/st25r3916.su ./Drivers/st25r3916/st25r3916_aat.cyclo ./Drivers/st25r3916/st25r3916_aat.d ./Drivers/st25r3916/st25r3916_aat.o ./Drivers/st25r3916/st25r3916_aat.su ./Drivers/st25r3916/st25r3916_com.cyclo ./Drivers/st25r3916/st25r3916_com.d ./Drivers/st25r3916/st25r3916_com.o ./Drivers/st25r3916/st25r3916_com.su ./Drivers/st25r3916/st25r3916_irq.cyclo ./Drivers/st25r3916/st25r3916_irq.d ./Drivers/st25r3916/st25r3916_irq.o ./Drivers/st25r3916/st25r3916_irq.su ./Drivers/st25r3916/st25r3916_led.cyclo ./Drivers/st25r3916/st25r3916_led.d ./Drivers/st25r3916/st25r3916_led.o ./Drivers/st25r3916/st25r3916_led.su ./Drivers/st25r3916/timer.cyclo ./Drivers/st25r3916/timer.d ./Drivers/st25r3916/timer.o ./Drivers/st25r3916/timer.su

.PHONY: clean-Drivers-2f-st25r3916

