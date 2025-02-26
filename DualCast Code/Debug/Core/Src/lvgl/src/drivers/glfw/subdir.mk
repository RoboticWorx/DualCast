################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/lvgl/src/drivers/glfw/lv_glfw_window.c \
../Core/Src/lvgl/src/drivers/glfw/lv_opengles_debug.c \
../Core/Src/lvgl/src/drivers/glfw/lv_opengles_driver.c \
../Core/Src/lvgl/src/drivers/glfw/lv_opengles_texture.c 

OBJS += \
./Core/Src/lvgl/src/drivers/glfw/lv_glfw_window.o \
./Core/Src/lvgl/src/drivers/glfw/lv_opengles_debug.o \
./Core/Src/lvgl/src/drivers/glfw/lv_opengles_driver.o \
./Core/Src/lvgl/src/drivers/glfw/lv_opengles_texture.o 

C_DEPS += \
./Core/Src/lvgl/src/drivers/glfw/lv_glfw_window.d \
./Core/Src/lvgl/src/drivers/glfw/lv_opengles_debug.d \
./Core/Src/lvgl/src/drivers/glfw/lv_opengles_driver.d \
./Core/Src/lvgl/src/drivers/glfw/lv_opengles_texture.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/lvgl/src/drivers/glfw/%.o Core/Src/lvgl/src/drivers/glfw/%.su Core/Src/lvgl/src/drivers/glfw/%.cyclo: ../Core/Src/lvgl/src/drivers/glfw/%.c Core/Src/lvgl/src/drivers/glfw/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H563xx -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-lvgl-2f-src-2f-drivers-2f-glfw

clean-Core-2f-Src-2f-lvgl-2f-src-2f-drivers-2f-glfw:
	-$(RM) ./Core/Src/lvgl/src/drivers/glfw/lv_glfw_window.cyclo ./Core/Src/lvgl/src/drivers/glfw/lv_glfw_window.d ./Core/Src/lvgl/src/drivers/glfw/lv_glfw_window.o ./Core/Src/lvgl/src/drivers/glfw/lv_glfw_window.su ./Core/Src/lvgl/src/drivers/glfw/lv_opengles_debug.cyclo ./Core/Src/lvgl/src/drivers/glfw/lv_opengles_debug.d ./Core/Src/lvgl/src/drivers/glfw/lv_opengles_debug.o ./Core/Src/lvgl/src/drivers/glfw/lv_opengles_debug.su ./Core/Src/lvgl/src/drivers/glfw/lv_opengles_driver.cyclo ./Core/Src/lvgl/src/drivers/glfw/lv_opengles_driver.d ./Core/Src/lvgl/src/drivers/glfw/lv_opengles_driver.o ./Core/Src/lvgl/src/drivers/glfw/lv_opengles_driver.su ./Core/Src/lvgl/src/drivers/glfw/lv_opengles_texture.cyclo ./Core/Src/lvgl/src/drivers/glfw/lv_opengles_texture.d ./Core/Src/lvgl/src/drivers/glfw/lv_opengles_texture.o ./Core/Src/lvgl/src/drivers/glfw/lv_opengles_texture.su

.PHONY: clean-Core-2f-Src-2f-lvgl-2f-src-2f-drivers-2f-glfw

