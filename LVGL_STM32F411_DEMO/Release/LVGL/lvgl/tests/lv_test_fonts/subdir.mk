################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/lvgl/tests/lv_test_fonts/font_1.c \
../LVGL/lvgl/tests/lv_test_fonts/font_2.c \
../LVGL/lvgl/tests/lv_test_fonts/font_3.c 

OBJS += \
./LVGL/lvgl/tests/lv_test_fonts/font_1.o \
./LVGL/lvgl/tests/lv_test_fonts/font_2.o \
./LVGL/lvgl/tests/lv_test_fonts/font_3.o 

C_DEPS += \
./LVGL/lvgl/tests/lv_test_fonts/font_1.d \
./LVGL/lvgl/tests/lv_test_fonts/font_2.d \
./LVGL/lvgl/tests/lv_test_fonts/font_3.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/lvgl/tests/lv_test_fonts/%.o: ../LVGL/lvgl/tests/lv_test_fonts/%.c LVGL/lvgl/tests/lv_test_fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/paulo/STM32CubeIDE/LVGL/LVGL_STM32F411_DEMO/LVGL/lvgl/src/lv_font" -I"C:/Users/paulo/STM32CubeIDE/LVGL/LVGL_STM32F411_DEMO/LVGL/lv_examples" -I"C:/Users/paulo/STM32CubeIDE/LVGL/LVGL_STM32F411_DEMO/LVGL" -I"C:/Users/paulo/STM32CubeIDE/LVGL/LVGL_STM32F411_DEMO/LVGL/lv_examples/src" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

