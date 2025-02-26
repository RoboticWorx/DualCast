################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/libs/fsdrv/lv_fs_cbfs.c \
../Drivers/lvgl/src/libs/fsdrv/lv_fs_fatfs.c \
../Drivers/lvgl/src/libs/fsdrv/lv_fs_littlefs.c \
../Drivers/lvgl/src/libs/fsdrv/lv_fs_memfs.c \
../Drivers/lvgl/src/libs/fsdrv/lv_fs_posix.c \
../Drivers/lvgl/src/libs/fsdrv/lv_fs_stdio.c \
../Drivers/lvgl/src/libs/fsdrv/lv_fs_win32.c 

OBJS += \
./Drivers/lvgl/src/libs/fsdrv/lv_fs_cbfs.o \
./Drivers/lvgl/src/libs/fsdrv/lv_fs_fatfs.o \
./Drivers/lvgl/src/libs/fsdrv/lv_fs_littlefs.o \
./Drivers/lvgl/src/libs/fsdrv/lv_fs_memfs.o \
./Drivers/lvgl/src/libs/fsdrv/lv_fs_posix.o \
./Drivers/lvgl/src/libs/fsdrv/lv_fs_stdio.o \
./Drivers/lvgl/src/libs/fsdrv/lv_fs_win32.o 

C_DEPS += \
./Drivers/lvgl/src/libs/fsdrv/lv_fs_cbfs.d \
./Drivers/lvgl/src/libs/fsdrv/lv_fs_fatfs.d \
./Drivers/lvgl/src/libs/fsdrv/lv_fs_littlefs.d \
./Drivers/lvgl/src/libs/fsdrv/lv_fs_memfs.d \
./Drivers/lvgl/src/libs/fsdrv/lv_fs_posix.d \
./Drivers/lvgl/src/libs/fsdrv/lv_fs_stdio.d \
./Drivers/lvgl/src/libs/fsdrv/lv_fs_win32.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/libs/fsdrv/%.o Drivers/lvgl/src/libs/fsdrv/%.su Drivers/lvgl/src/libs/fsdrv/%.cyclo: ../Drivers/lvgl/src/libs/fsdrv/%.c Drivers/lvgl/src/libs/fsdrv/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DLV_COLOR_16_SWAP=1 -DUSE_HAL_DRIVER -DSTM32H563xx -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/lvgl" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/sx126x" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/bmi323" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/bme280" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/vl53l4cx" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Core/Media" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/lvgl/src/misc" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/lvgl/src/stdlib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-libs-2f-fsdrv

clean-Drivers-2f-lvgl-2f-src-2f-libs-2f-fsdrv:
	-$(RM) ./Drivers/lvgl/src/libs/fsdrv/lv_fs_cbfs.cyclo ./Drivers/lvgl/src/libs/fsdrv/lv_fs_cbfs.d ./Drivers/lvgl/src/libs/fsdrv/lv_fs_cbfs.o ./Drivers/lvgl/src/libs/fsdrv/lv_fs_cbfs.su ./Drivers/lvgl/src/libs/fsdrv/lv_fs_fatfs.cyclo ./Drivers/lvgl/src/libs/fsdrv/lv_fs_fatfs.d ./Drivers/lvgl/src/libs/fsdrv/lv_fs_fatfs.o ./Drivers/lvgl/src/libs/fsdrv/lv_fs_fatfs.su ./Drivers/lvgl/src/libs/fsdrv/lv_fs_littlefs.cyclo ./Drivers/lvgl/src/libs/fsdrv/lv_fs_littlefs.d ./Drivers/lvgl/src/libs/fsdrv/lv_fs_littlefs.o ./Drivers/lvgl/src/libs/fsdrv/lv_fs_littlefs.su ./Drivers/lvgl/src/libs/fsdrv/lv_fs_memfs.cyclo ./Drivers/lvgl/src/libs/fsdrv/lv_fs_memfs.d ./Drivers/lvgl/src/libs/fsdrv/lv_fs_memfs.o ./Drivers/lvgl/src/libs/fsdrv/lv_fs_memfs.su ./Drivers/lvgl/src/libs/fsdrv/lv_fs_posix.cyclo ./Drivers/lvgl/src/libs/fsdrv/lv_fs_posix.d ./Drivers/lvgl/src/libs/fsdrv/lv_fs_posix.o ./Drivers/lvgl/src/libs/fsdrv/lv_fs_posix.su ./Drivers/lvgl/src/libs/fsdrv/lv_fs_stdio.cyclo ./Drivers/lvgl/src/libs/fsdrv/lv_fs_stdio.d ./Drivers/lvgl/src/libs/fsdrv/lv_fs_stdio.o ./Drivers/lvgl/src/libs/fsdrv/lv_fs_stdio.su ./Drivers/lvgl/src/libs/fsdrv/lv_fs_win32.cyclo ./Drivers/lvgl/src/libs/fsdrv/lv_fs_win32.d ./Drivers/lvgl/src/libs/fsdrv/lv_fs_win32.o ./Drivers/lvgl/src/libs/fsdrv/lv_fs_win32.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-libs-2f-fsdrv

