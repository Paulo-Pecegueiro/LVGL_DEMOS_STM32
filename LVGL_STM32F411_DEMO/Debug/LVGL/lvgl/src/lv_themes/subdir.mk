################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/lvgl/src/lv_themes/lv_theme.c \
../LVGL/lvgl/src/lv_themes/lv_theme_empty.c \
../LVGL/lvgl/src/lv_themes/lv_theme_material.c \
../LVGL/lvgl/src/lv_themes/lv_theme_mono.c \
../LVGL/lvgl/src/lv_themes/lv_theme_template.c 

OBJS += \
./LVGL/lvgl/src/lv_themes/lv_theme.o \
./LVGL/lvgl/src/lv_themes/lv_theme_empty.o \
./LVGL/lvgl/src/lv_themes/lv_theme_material.o \
./LVGL/lvgl/src/lv_themes/lv_theme_mono.o \
./LVGL/lvgl/src/lv_themes/lv_theme_template.o 

C_DEPS += \
./LVGL/lvgl/src/lv_themes/lv_theme.d \
./LVGL/lvgl/src/lv_themes/lv_theme_empty.d \
./LVGL/lvgl/src/lv_themes/lv_theme_material.d \
./LVGL/lvgl/src/lv_themes/lv_theme_mono.d \
./LVGL/lvgl/src/lv_themes/lv_theme_template.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/lvgl/src/lv_themes/%.o: ../LVGL/lvgl/src/lv_themes/%.c LVGL/lvgl/src/lv_themes/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/paulo/STM32CubeIDE/LVGL/LVGL_STM32F411_DEMO/LVGL/lvgl/src/lv_font" -I"C:/Users/paulo/STM32CubeIDE/LVGL/LVGL_STM32F411_DEMO/LVGL/lv_examples" -I"C:/Users/paulo/STM32CubeIDE/LVGL/LVGL_STM32F411_DEMO/LVGL/lv_examples/src" -I"C:/Users/paulo/STM32CubeIDE/LVGL/LVGL_STM32F411_DEMO/LVGL" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

