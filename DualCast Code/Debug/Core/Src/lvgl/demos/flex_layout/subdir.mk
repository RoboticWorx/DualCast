################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_ctrl_pad.c \
../Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_flex_loader.c \
../Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_main.c \
../Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_view.c \
../Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_view_child_node.c \
../Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_view_ctrl_pad.c 

OBJS += \
./Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_ctrl_pad.o \
./Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_flex_loader.o \
./Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_main.o \
./Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_view.o \
./Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_view_child_node.o \
./Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_view_ctrl_pad.o 

C_DEPS += \
./Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_ctrl_pad.d \
./Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_flex_loader.d \
./Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_main.d \
./Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_view.d \
./Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_view_child_node.d \
./Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_view_ctrl_pad.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/lvgl/demos/flex_layout/%.o Core/Src/lvgl/demos/flex_layout/%.su Core/Src/lvgl/demos/flex_layout/%.cyclo: ../Core/Src/lvgl/demos/flex_layout/%.c Core/Src/lvgl/demos/flex_layout/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H563xx -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-lvgl-2f-demos-2f-flex_layout

clean-Core-2f-Src-2f-lvgl-2f-demos-2f-flex_layout:
	-$(RM) ./Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_ctrl_pad.cyclo ./Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_ctrl_pad.d ./Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_ctrl_pad.o ./Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_ctrl_pad.su ./Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_flex_loader.cyclo ./Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_flex_loader.d ./Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_flex_loader.o ./Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_flex_loader.su ./Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_main.cyclo ./Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_main.d ./Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_main.o ./Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_main.su ./Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_view.cyclo ./Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_view.d ./Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_view.o ./Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_view.su ./Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_view_child_node.cyclo ./Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_view_child_node.d ./Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_view_child_node.o ./Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_view_child_node.su ./Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_view_ctrl_pad.cyclo ./Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_view_ctrl_pad.d ./Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_view_ctrl_pad.o ./Core/Src/lvgl/demos/flex_layout/lv_demo_flex_layout_view_ctrl_pad.su

.PHONY: clean-Core-2f-Src-2f-lvgl-2f-demos-2f-flex_layout

