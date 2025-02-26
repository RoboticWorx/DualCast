################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/libs/freetype/lv_freetype.c \
../Drivers/lvgl/src/libs/freetype/lv_freetype_glyph.c \
../Drivers/lvgl/src/libs/freetype/lv_freetype_image.c \
../Drivers/lvgl/src/libs/freetype/lv_freetype_outline.c \
../Drivers/lvgl/src/libs/freetype/lv_ftsystem.c 

OBJS += \
./Drivers/lvgl/src/libs/freetype/lv_freetype.o \
./Drivers/lvgl/src/libs/freetype/lv_freetype_glyph.o \
./Drivers/lvgl/src/libs/freetype/lv_freetype_image.o \
./Drivers/lvgl/src/libs/freetype/lv_freetype_outline.o \
./Drivers/lvgl/src/libs/freetype/lv_ftsystem.o 

C_DEPS += \
./Drivers/lvgl/src/libs/freetype/lv_freetype.d \
./Drivers/lvgl/src/libs/freetype/lv_freetype_glyph.d \
./Drivers/lvgl/src/libs/freetype/lv_freetype_image.d \
./Drivers/lvgl/src/libs/freetype/lv_freetype_outline.d \
./Drivers/lvgl/src/libs/freetype/lv_ftsystem.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/libs/freetype/%.o Drivers/lvgl/src/libs/freetype/%.su Drivers/lvgl/src/libs/freetype/%.cyclo: ../Drivers/lvgl/src/libs/freetype/%.c Drivers/lvgl/src/libs/freetype/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DLV_COLOR_16_SWAP=1 -DUSE_HAL_DRIVER -DSTM32H563xx -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/lvgl" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/sx126x" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/bmi323" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/bme280" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/vl53l4cx" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Core/Media" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/lvgl/src/misc" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/lvgl/src/stdlib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-libs-2f-freetype

clean-Drivers-2f-lvgl-2f-src-2f-libs-2f-freetype:
	-$(RM) ./Drivers/lvgl/src/libs/freetype/lv_freetype.cyclo ./Drivers/lvgl/src/libs/freetype/lv_freetype.d ./Drivers/lvgl/src/libs/freetype/lv_freetype.o ./Drivers/lvgl/src/libs/freetype/lv_freetype.su ./Drivers/lvgl/src/libs/freetype/lv_freetype_glyph.cyclo ./Drivers/lvgl/src/libs/freetype/lv_freetype_glyph.d ./Drivers/lvgl/src/libs/freetype/lv_freetype_glyph.o ./Drivers/lvgl/src/libs/freetype/lv_freetype_glyph.su ./Drivers/lvgl/src/libs/freetype/lv_freetype_image.cyclo ./Drivers/lvgl/src/libs/freetype/lv_freetype_image.d ./Drivers/lvgl/src/libs/freetype/lv_freetype_image.o ./Drivers/lvgl/src/libs/freetype/lv_freetype_image.su ./Drivers/lvgl/src/libs/freetype/lv_freetype_outline.cyclo ./Drivers/lvgl/src/libs/freetype/lv_freetype_outline.d ./Drivers/lvgl/src/libs/freetype/lv_freetype_outline.o ./Drivers/lvgl/src/libs/freetype/lv_freetype_outline.su ./Drivers/lvgl/src/libs/freetype/lv_ftsystem.cyclo ./Drivers/lvgl/src/libs/freetype/lv_ftsystem.d ./Drivers/lvgl/src/libs/freetype/lv_ftsystem.o ./Drivers/lvgl/src/libs/freetype/lv_ftsystem.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-libs-2f-freetype

