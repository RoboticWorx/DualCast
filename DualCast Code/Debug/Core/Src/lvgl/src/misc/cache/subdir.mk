################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/lvgl/src/misc/cache/lv_cache.c \
../Core/Src/lvgl/src/misc/cache/lv_cache_entry.c \
../Core/Src/lvgl/src/misc/cache/lv_cache_lru_rb.c \
../Core/Src/lvgl/src/misc/cache/lv_image_cache.c \
../Core/Src/lvgl/src/misc/cache/lv_image_header_cache.c 

OBJS += \
./Core/Src/lvgl/src/misc/cache/lv_cache.o \
./Core/Src/lvgl/src/misc/cache/lv_cache_entry.o \
./Core/Src/lvgl/src/misc/cache/lv_cache_lru_rb.o \
./Core/Src/lvgl/src/misc/cache/lv_image_cache.o \
./Core/Src/lvgl/src/misc/cache/lv_image_header_cache.o 

C_DEPS += \
./Core/Src/lvgl/src/misc/cache/lv_cache.d \
./Core/Src/lvgl/src/misc/cache/lv_cache_entry.d \
./Core/Src/lvgl/src/misc/cache/lv_cache_lru_rb.d \
./Core/Src/lvgl/src/misc/cache/lv_image_cache.d \
./Core/Src/lvgl/src/misc/cache/lv_image_header_cache.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/lvgl/src/misc/cache/%.o Core/Src/lvgl/src/misc/cache/%.su Core/Src/lvgl/src/misc/cache/%.cyclo: ../Core/Src/lvgl/src/misc/cache/%.c Core/Src/lvgl/src/misc/cache/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H563xx -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-lvgl-2f-src-2f-misc-2f-cache

clean-Core-2f-Src-2f-lvgl-2f-src-2f-misc-2f-cache:
	-$(RM) ./Core/Src/lvgl/src/misc/cache/lv_cache.cyclo ./Core/Src/lvgl/src/misc/cache/lv_cache.d ./Core/Src/lvgl/src/misc/cache/lv_cache.o ./Core/Src/lvgl/src/misc/cache/lv_cache.su ./Core/Src/lvgl/src/misc/cache/lv_cache_entry.cyclo ./Core/Src/lvgl/src/misc/cache/lv_cache_entry.d ./Core/Src/lvgl/src/misc/cache/lv_cache_entry.o ./Core/Src/lvgl/src/misc/cache/lv_cache_entry.su ./Core/Src/lvgl/src/misc/cache/lv_cache_lru_rb.cyclo ./Core/Src/lvgl/src/misc/cache/lv_cache_lru_rb.d ./Core/Src/lvgl/src/misc/cache/lv_cache_lru_rb.o ./Core/Src/lvgl/src/misc/cache/lv_cache_lru_rb.su ./Core/Src/lvgl/src/misc/cache/lv_image_cache.cyclo ./Core/Src/lvgl/src/misc/cache/lv_image_cache.d ./Core/Src/lvgl/src/misc/cache/lv_image_cache.o ./Core/Src/lvgl/src/misc/cache/lv_image_cache.su ./Core/Src/lvgl/src/misc/cache/lv_image_header_cache.cyclo ./Core/Src/lvgl/src/misc/cache/lv_image_header_cache.d ./Core/Src/lvgl/src/misc/cache/lv_image_header_cache.o ./Core/Src/lvgl/src/misc/cache/lv_image_header_cache.su

.PHONY: clean-Core-2f-Src-2f-lvgl-2f-src-2f-misc-2f-cache

