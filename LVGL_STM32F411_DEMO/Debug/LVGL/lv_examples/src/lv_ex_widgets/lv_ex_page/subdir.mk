################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/lv_examples/src/lv_ex_widgets/lv_ex_page/lv_ex_page_1.c 

OBJS += \
./LVGL/lv_examples/src/lv_ex_widgets/lv_ex_page/lv_ex_page_1.o 

C_DEPS += \
./LVGL/lv_examples/src/lv_ex_widgets/lv_ex_page/lv_ex_page_1.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/lv_examples/src/lv_ex_widgets/lv_ex_page/%.o: ../LVGL/lv_examples/src/lv_ex_widgets/lv_ex_page/%.c LVGL/lv_examples/src/lv_ex_widgets/lv_ex_page/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/paulo/STM32CubeIDE/LVGL/LVGL_STM32F411_DEMO/LVGL/lvgl/src/lv_font" -I"C:/Users/paulo/STM32CubeIDE/LVGL/LVGL_STM32F411_DEMO/LVGL/lv_examples" -I"C:/Users/paulo/STM32CubeIDE/LVGL/LVGL_STM32F411_DEMO/LVGL/lv_examples/src" -I"C:/Users/paulo/STM32CubeIDE/LVGL/LVGL_STM32F411_DEMO/LVGL" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

