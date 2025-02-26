################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_ctrl_pad.c \
../Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_flex_loader.c \
../Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_main.c \
../Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_view.c \
../Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_view_child_node.c \
../Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_view_ctrl_pad.c 

OBJS += \
./Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_ctrl_pad.o \
./Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_flex_loader.o \
./Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_main.o \
./Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_view.o \
./Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_view_child_node.o \
./Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_view_ctrl_pad.o 

C_DEPS += \
./Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_ctrl_pad.d \
./Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_flex_loader.d \
./Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_main.d \
./Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_view.d \
./Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_view_child_node.d \
./Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_view_ctrl_pad.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/demos/flex_layout/%.o Drivers/lvgl/demos/flex_layout/%.su Drivers/lvgl/demos/flex_layout/%.cyclo: ../Drivers/lvgl/demos/flex_layout/%.c Drivers/lvgl/demos/flex_layout/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DLV_COLOR_16_SWAP=1 -DUSE_HAL_DRIVER -DSTM32H563xx -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/lvgl" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/sx126x" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/bmi323" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/bme280" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/vl53l4cx" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Core/Media" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/lvgl/src/misc" -I"C:/Users/Jatki/OneDrive/Documents/STM/DualCast/Drivers/lvgl/src/stdlib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-demos-2f-flex_layout

clean-Drivers-2f-lvgl-2f-demos-2f-flex_layout:
	-$(RM) ./Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_ctrl_pad.cyclo ./Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_ctrl_pad.d ./Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_ctrl_pad.o ./Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_ctrl_pad.su ./Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_flex_loader.cyclo ./Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_flex_loader.d ./Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_flex_loader.o ./Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_flex_loader.su ./Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_main.cyclo ./Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_main.d ./Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_main.o ./Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_main.su ./Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_view.cyclo ./Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_view.d ./Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_view.o ./Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_view.su ./Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_view_child_node.cyclo ./Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_view_child_node.d ./Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_view_child_node.o ./Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_view_child_node.su ./Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_view_ctrl_pad.cyclo ./Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_view_ctrl_pad.d ./Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_view_ctrl_pad.o ./Drivers/lvgl/demos/flex_layout/lv_demo_flex_layout_view_ctrl_pad.su

.PHONY: clean-Drivers-2f-lvgl-2f-demos-2f-flex_layout

