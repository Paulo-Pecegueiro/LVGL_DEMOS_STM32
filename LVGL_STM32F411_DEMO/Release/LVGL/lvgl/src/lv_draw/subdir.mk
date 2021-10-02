################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/lvgl/src/lv_draw/lv_draw_arc.c \
../LVGL/lvgl/src/lv_draw/lv_draw_blend.c \
../LVGL/lvgl/src/lv_draw/lv_draw_img.c \
../LVGL/lvgl/src/lv_draw/lv_draw_label.c \
../LVGL/lvgl/src/lv_draw/lv_draw_line.c \
../LVGL/lvgl/src/lv_draw/lv_draw_mask.c \
../LVGL/lvgl/src/lv_draw/lv_draw_rect.c \
../LVGL/lvgl/src/lv_draw/lv_draw_triangle.c \
../LVGL/lvgl/src/lv_draw/lv_img_buf.c \
../LVGL/lvgl/src/lv_draw/lv_img_cache.c \
../LVGL/lvgl/src/lv_draw/lv_img_decoder.c 

OBJS += \
./LVGL/lvgl/src/lv_draw/lv_draw_arc.o \
./LVGL/lvgl/src/lv_draw/lv_draw_blend.o \
./LVGL/lvgl/src/lv_draw/lv_draw_img.o \
./LVGL/lvgl/src/lv_draw/lv_draw_label.o \
./LVGL/lvgl/src/lv_draw/lv_draw_line.o \
./LVGL/lvgl/src/lv_draw/lv_draw_mask.o \
./LVGL/lvgl/src/lv_draw/lv_draw_rect.o \
./LVGL/lvgl/src/lv_draw/lv_draw_triangle.o \
./LVGL/lvgl/src/lv_draw/lv_img_buf.o \
./LVGL/lvgl/src/lv_draw/lv_img_cache.o \
./LVGL/lvgl/src/lv_draw/lv_img_decoder.o 

C_DEPS += \
./LVGL/lvgl/src/lv_draw/lv_draw_arc.d \
./LVGL/lvgl/src/lv_draw/lv_draw_blend.d \
./LVGL/lvgl/src/lv_draw/lv_draw_img.d \
./LVGL/lvgl/src/lv_draw/lv_draw_label.d \
./LVGL/lvgl/src/lv_draw/lv_draw_line.d \
./LVGL/lvgl/src/lv_draw/lv_draw_mask.d \
./LVGL/lvgl/src/lv_draw/lv_draw_rect.d \
./LVGL/lvgl/src/lv_draw/lv_draw_triangle.d \
./LVGL/lvgl/src/lv_draw/lv_img_buf.d \
./LVGL/lvgl/src/lv_draw/lv_img_cache.d \
./LVGL/lvgl/src/lv_draw/lv_img_decoder.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/lvgl/src/lv_draw/%.o: ../LVGL/lvgl/src/lv_draw/%.c LVGL/lvgl/src/lv_draw/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/paulo/STM32CubeIDE/LVGL/LVGL_STM32F411_DEMO/LVGL/lvgl/src/lv_font" -I"C:/Users/paulo/STM32CubeIDE/LVGL/LVGL_STM32F411_DEMO/LVGL/lv_examples" -I"C:/Users/paulo/STM32CubeIDE/LVGL/LVGL_STM32F411_DEMO/LVGL" -I"C:/Users/paulo/STM32CubeIDE/LVGL/LVGL_STM32F411_DEMO/LVGL/lv_examples/src" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

