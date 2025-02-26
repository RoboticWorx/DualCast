################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_artist_palette.c \
../Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_books.c \
../Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_camera_with_flash.c \
../Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_cat_face.c \
../Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_deciduous_tree.c \
../Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_dog_face.c \
../Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_earth_globe_europe_africa.c \
../Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_flexed_biceps.c \
../Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_movie_camera.c \
../Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_red_heart.c \
../Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_rocket.c \
../Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_soccer_ball.c 

OBJS += \
./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_artist_palette.o \
./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_books.o \
./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_camera_with_flash.o \
./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_cat_face.o \
./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_deciduous_tree.o \
./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_dog_face.o \
./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_earth_globe_europe_africa.o \
./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_flexed_biceps.o \
./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_movie_camera.o \
./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_red_heart.o \
./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_rocket.o \
./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_soccer_ball.o 

C_DEPS += \
./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_artist_palette.d \
./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_books.d \
./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_camera_with_flash.d \
./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_cat_face.d \
./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_deciduous_tree.d \
./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_dog_face.d \
./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_earth_globe_europe_africa.d \
./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_flexed_biceps.d \
./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_movie_camera.d \
./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_red_heart.d \
./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_rocket.d \
./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_soccer_ball.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/lvgl/demos/multilang/assets/emojis/%.o Core/Src/lvgl/demos/multilang/assets/emojis/%.su Core/Src/lvgl/demos/multilang/assets/emojis/%.cyclo: ../Core/Src/lvgl/demos/multilang/assets/emojis/%.c Core/Src/lvgl/demos/multilang/assets/emojis/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H563xx -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-lvgl-2f-demos-2f-multilang-2f-assets-2f-emojis

clean-Core-2f-Src-2f-lvgl-2f-demos-2f-multilang-2f-assets-2f-emojis:
	-$(RM) ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_artist_palette.cyclo ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_artist_palette.d ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_artist_palette.o ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_artist_palette.su ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_books.cyclo ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_books.d ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_books.o ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_books.su ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_camera_with_flash.cyclo ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_camera_with_flash.d ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_camera_with_flash.o ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_camera_with_flash.su ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_cat_face.cyclo ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_cat_face.d ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_cat_face.o ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_cat_face.su ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_deciduous_tree.cyclo ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_deciduous_tree.d ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_deciduous_tree.o ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_deciduous_tree.su ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_dog_face.cyclo ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_dog_face.d ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_dog_face.o ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_dog_face.su ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_earth_globe_europe_africa.cyclo ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_earth_globe_europe_africa.d ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_earth_globe_europe_africa.o ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_earth_globe_europe_africa.su ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_flexed_biceps.cyclo ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_flexed_biceps.d ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_flexed_biceps.o ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_flexed_biceps.su ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_movie_camera.cyclo ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_movie_camera.d ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_movie_camera.o ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_movie_camera.su ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_red_heart.cyclo ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_red_heart.d ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_red_heart.o ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_red_heart.su ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_rocket.cyclo ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_rocket.d ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_rocket.o ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_rocket.su ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_soccer_ball.cyclo ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_soccer_ball.d ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_soccer_ball.o ./Core/Src/lvgl/demos/multilang/assets/emojis/img_emoji_soccer_ball.su

.PHONY: clean-Core-2f-Src-2f-lvgl-2f-demos-2f-multilang-2f-assets-2f-emojis

