################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/lvgl/src/lv_misc/lv_anim.c \
../LVGL/lvgl/src/lv_misc/lv_area.c \
../LVGL/lvgl/src/lv_misc/lv_async.c \
../LVGL/lvgl/src/lv_misc/lv_bidi.c \
../LVGL/lvgl/src/lv_misc/lv_color.c \
../LVGL/lvgl/src/lv_misc/lv_debug.c \
../LVGL/lvgl/src/lv_misc/lv_fs.c \
../LVGL/lvgl/src/lv_misc/lv_gc.c \
../LVGL/lvgl/src/lv_misc/lv_ll.c \
../LVGL/lvgl/src/lv_misc/lv_log.c \
../LVGL/lvgl/src/lv_misc/lv_math.c \
../LVGL/lvgl/src/lv_misc/lv_mem.c \
../LVGL/lvgl/src/lv_misc/lv_printf.c \
../LVGL/lvgl/src/lv_misc/lv_task.c \
../LVGL/lvgl/src/lv_misc/lv_templ.c \
../LVGL/lvgl/src/lv_misc/lv_txt.c \
../LVGL/lvgl/src/lv_misc/lv_txt_ap.c \
../LVGL/lvgl/src/lv_misc/lv_utils.c 

OBJS += \
./LVGL/lvgl/src/lv_misc/lv_anim.o \
./LVGL/lvgl/src/lv_misc/lv_area.o \
./LVGL/lvgl/src/lv_misc/lv_async.o \
./LVGL/lvgl/src/lv_misc/lv_bidi.o \
./LVGL/lvgl/src/lv_misc/lv_color.o \
./LVGL/lvgl/src/lv_misc/lv_debug.o \
./LVGL/lvgl/src/lv_misc/lv_fs.o \
./LVGL/lvgl/src/lv_misc/lv_gc.o \
./LVGL/lvgl/src/lv_misc/lv_ll.o \
./LVGL/lvgl/src/lv_misc/lv_log.o \
./LVGL/lvgl/src/lv_misc/lv_math.o \
./LVGL/lvgl/src/lv_misc/lv_mem.o \
./LVGL/lvgl/src/lv_misc/lv_printf.o \
./LVGL/lvgl/src/lv_misc/lv_task.o \
./LVGL/lvgl/src/lv_misc/lv_templ.o \
./LVGL/lvgl/src/lv_misc/lv_txt.o \
./LVGL/lvgl/src/lv_misc/lv_txt_ap.o \
./LVGL/lvgl/src/lv_misc/lv_utils.o 

C_DEPS += \
./LVGL/lvgl/src/lv_misc/lv_anim.d \
./LVGL/lvgl/src/lv_misc/lv_area.d \
./LVGL/lvgl/src/lv_misc/lv_async.d \
./LVGL/lvgl/src/lv_misc/lv_bidi.d \
./LVGL/lvgl/src/lv_misc/lv_color.d \
./LVGL/lvgl/src/lv_misc/lv_debug.d \
./LVGL/lvgl/src/lv_misc/lv_fs.d \
./LVGL/lvgl/src/lv_misc/lv_gc.d \
./LVGL/lvgl/src/lv_misc/lv_ll.d \
./LVGL/lvgl/src/lv_misc/lv_log.d \
./LVGL/lvgl/src/lv_misc/lv_math.d \
./LVGL/lvgl/src/lv_misc/lv_mem.d \
./LVGL/lvgl/src/lv_misc/lv_printf.d \
./LVGL/lvgl/src/lv_misc/lv_task.d \
./LVGL/lvgl/src/lv_misc/lv_templ.d \
./LVGL/lvgl/src/lv_misc/lv_txt.d \
./LVGL/lvgl/src/lv_misc/lv_txt_ap.d \
./LVGL/lvgl/src/lv_misc/lv_utils.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/lvgl/src/lv_misc/%.o: ../LVGL/lvgl/src/lv_misc/%.c LVGL/lvgl/src/lv_misc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/paulo/STM32CubeIDE/LVGL/LVGL_STM32F411_DEMO/LVGL/lvgl/src/lv_font" -I"C:/Users/paulo/STM32CubeIDE/LVGL/LVGL_STM32F411_DEMO/LVGL/lv_examples" -I"C:/Users/paulo/STM32CubeIDE/LVGL/LVGL_STM32F411_DEMO/LVGL/lv_examples/src" -I"C:/Users/paulo/STM32CubeIDE/LVGL/LVGL_STM32F411_DEMO/LVGL" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

