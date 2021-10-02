################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/lv_examples/assets/img_cogwheel_alpha16.c \
../LVGL/lv_examples/assets/img_cogwheel_argb.c \
../LVGL/lv_examples/assets/img_cogwheel_chroma_keyed.c \
../LVGL/lv_examples/assets/img_cogwheel_indexed16.c \
../LVGL/lv_examples/assets/img_cogwheel_rgb.c \
../LVGL/lv_examples/assets/lv_font_montserrat_12_compr_az.c \
../LVGL/lv_examples/assets/lv_font_montserrat_16_compr_az.c \
../LVGL/lv_examples/assets/lv_font_montserrat_28_compr_az.c 

OBJS += \
./LVGL/lv_examples/assets/img_cogwheel_alpha16.o \
./LVGL/lv_examples/assets/img_cogwheel_argb.o \
./LVGL/lv_examples/assets/img_cogwheel_chroma_keyed.o \
./LVGL/lv_examples/assets/img_cogwheel_indexed16.o \
./LVGL/lv_examples/assets/img_cogwheel_rgb.o \
./LVGL/lv_examples/assets/lv_font_montserrat_12_compr_az.o \
./LVGL/lv_examples/assets/lv_font_montserrat_16_compr_az.o \
./LVGL/lv_examples/assets/lv_font_montserrat_28_compr_az.o 

C_DEPS += \
./LVGL/lv_examples/assets/img_cogwheel_alpha16.d \
./LVGL/lv_examples/assets/img_cogwheel_argb.d \
./LVGL/lv_examples/assets/img_cogwheel_chroma_keyed.d \
./LVGL/lv_examples/assets/img_cogwheel_indexed16.d \
./LVGL/lv_examples/assets/img_cogwheel_rgb.d \
./LVGL/lv_examples/assets/lv_font_montserrat_12_compr_az.d \
./LVGL/lv_examples/assets/lv_font_montserrat_16_compr_az.d \
./LVGL/lv_examples/assets/lv_font_montserrat_28_compr_az.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/lv_examples/assets/%.o: ../LVGL/lv_examples/assets/%.c LVGL/lv_examples/assets/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/paulo/STM32CubeIDE/LVGL/LVGL_STM32F411_DEMO/LVGL/lvgl/src/lv_font" -I"C:/Users/paulo/STM32CubeIDE/LVGL/LVGL_STM32F411_DEMO/LVGL/lv_examples" -I"C:/Users/paulo/STM32CubeIDE/LVGL/LVGL_STM32F411_DEMO/LVGL" -I"C:/Users/paulo/STM32CubeIDE/LVGL/LVGL_STM32F411_DEMO/LVGL/lv_examples/src" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

