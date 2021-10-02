################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/lvgl/tests/lv_test_core/lv_test_core.c \
../LVGL/lvgl/tests/lv_test_core/lv_test_font_loader.c \
../LVGL/lvgl/tests/lv_test_core/lv_test_obj.c \
../LVGL/lvgl/tests/lv_test_core/lv_test_style.c 

OBJS += \
./LVGL/lvgl/tests/lv_test_core/lv_test_core.o \
./LVGL/lvgl/tests/lv_test_core/lv_test_font_loader.o \
./LVGL/lvgl/tests/lv_test_core/lv_test_obj.o \
./LVGL/lvgl/tests/lv_test_core/lv_test_style.o 

C_DEPS += \
./LVGL/lvgl/tests/lv_test_core/lv_test_core.d \
./LVGL/lvgl/tests/lv_test_core/lv_test_font_loader.d \
./LVGL/lvgl/tests/lv_test_core/lv_test_obj.d \
./LVGL/lvgl/tests/lv_test_core/lv_test_style.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/lvgl/tests/lv_test_core/%.o: ../LVGL/lvgl/tests/lv_test_core/%.c LVGL/lvgl/tests/lv_test_core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/paulo/STM32CubeIDE/LVGL/LVGL_STM32F411_DEMO/LVGL/lvgl/src/lv_font" -I"C:/Users/paulo/STM32CubeIDE/LVGL/LVGL_STM32F411_DEMO/LVGL/lv_examples" -I"C:/Users/paulo/STM32CubeIDE/LVGL/LVGL_STM32F411_DEMO/LVGL" -I"C:/Users/paulo/STM32CubeIDE/LVGL/LVGL_STM32F411_DEMO/LVGL/lv_examples/src" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

