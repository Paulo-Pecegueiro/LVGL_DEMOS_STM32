################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include LVGL/lvgl/tests/lv_test_widgets/subdir.mk
-include LVGL/lvgl/tests/lv_test_fonts/subdir.mk
-include LVGL/lvgl/tests/lv_test_core/subdir.mk
-include LVGL/lvgl/tests/subdir.mk
-include LVGL/lvgl/src/lv_widgets/subdir.mk
-include LVGL/lvgl/src/lv_themes/subdir.mk
-include LVGL/lvgl/src/lv_misc/subdir.mk
-include LVGL/lvgl/src/lv_hal/subdir.mk
-include LVGL/lvgl/src/lv_gpu/subdir.mk
-include LVGL/lvgl/src/lv_font/subdir.mk
-include LVGL/lvgl/src/lv_draw/subdir.mk
-include LVGL/lvgl/src/lv_core/subdir.mk
-include LVGL/lvgl/examples/porting/subdir.mk
-include LVGL/lv_examples/src/lv_ex_widgets/lv_ex_win/subdir.mk
-include LVGL/lv_examples/src/lv_ex_widgets/lv_ex_tileview/subdir.mk
-include LVGL/lv_examples/src/lv_ex_widgets/lv_ex_textarea/subdir.mk
-include LVGL/lv_examples/src/lv_ex_widgets/lv_ex_tabview/subdir.mk
-include LVGL/lv_examples/src/lv_ex_widgets/lv_ex_table/subdir.mk
-include LVGL/lv_examples/src/lv_ex_widgets/lv_ex_switch/subdir.mk
-include LVGL/lv_examples/src/lv_ex_widgets/lv_ex_spinner/subdir.mk
-include LVGL/lv_examples/src/lv_ex_widgets/lv_ex_spinbox/subdir.mk
-include LVGL/lv_examples/src/lv_ex_widgets/lv_ex_slider/subdir.mk
-include LVGL/lv_examples/src/lv_ex_widgets/lv_ex_roller/subdir.mk
-include LVGL/lv_examples/src/lv_ex_widgets/lv_ex_page/subdir.mk
-include LVGL/lv_examples/src/lv_ex_widgets/lv_ex_objmask/subdir.mk
-include LVGL/lv_examples/src/lv_ex_widgets/lv_ex_obj/subdir.mk
-include LVGL/lv_examples/src/lv_ex_widgets/lv_ex_msgbox/subdir.mk
-include LVGL/lv_examples/src/lv_ex_widgets/lv_ex_list/subdir.mk
-include LVGL/lv_examples/src/lv_ex_widgets/lv_ex_linemeter/subdir.mk
-include LVGL/lv_examples/src/lv_ex_widgets/lv_ex_line/subdir.mk
-include LVGL/lv_examples/src/lv_ex_widgets/lv_ex_led/subdir.mk
-include LVGL/lv_examples/src/lv_ex_widgets/lv_ex_label/subdir.mk
-include LVGL/lv_examples/src/lv_ex_widgets/lv_ex_keyboard/subdir.mk
-include LVGL/lv_examples/src/lv_ex_widgets/lv_ex_imgbtn/subdir.mk
-include LVGL/lv_examples/src/lv_ex_widgets/lv_ex_img/subdir.mk
-include LVGL/lv_examples/src/lv_ex_widgets/lv_ex_gauge/subdir.mk
-include LVGL/lv_examples/src/lv_ex_widgets/lv_ex_dropdown/subdir.mk
-include LVGL/lv_examples/src/lv_ex_widgets/lv_ex_cpicker/subdir.mk
-include LVGL/lv_examples/src/lv_ex_widgets/lv_ex_cont/subdir.mk
-include LVGL/lv_examples/src/lv_ex_widgets/lv_ex_checkbox/subdir.mk
-include LVGL/lv_examples/src/lv_ex_widgets/lv_ex_chart/subdir.mk
-include LVGL/lv_examples/src/lv_ex_widgets/lv_ex_canvas/subdir.mk
-include LVGL/lv_examples/src/lv_ex_widgets/lv_ex_calendar/subdir.mk
-include LVGL/lv_examples/src/lv_ex_widgets/lv_ex_btnmatrix/subdir.mk
-include LVGL/lv_examples/src/lv_ex_widgets/lv_ex_btn/subdir.mk
-include LVGL/lv_examples/src/lv_ex_widgets/lv_ex_bar/subdir.mk
-include LVGL/lv_examples/src/lv_ex_widgets/lv_ex_arc/subdir.mk
-include LVGL/lv_examples/src/lv_ex_widgets/subdir.mk
-include LVGL/lv_examples/src/lv_ex_style/subdir.mk
-include LVGL/lv_examples/src/lv_ex_get_started/subdir.mk
-include LVGL/lv_examples/src/lv_demo_widgets/subdir.mk
-include LVGL/lv_examples/src/lv_demo_stress/subdir.mk
-include LVGL/lv_examples/src/lv_demo_printer/images/subdir.mk
-include LVGL/lv_examples/src/lv_demo_printer/subdir.mk
-include LVGL/lv_examples/src/lv_demo_keypad_encoder/subdir.mk
-include LVGL/lv_examples/src/lv_demo_benchmark/subdir.mk
-include LVGL/lv_examples/assets/subdir.mk
-include LVGL/hal_stm_lvgl/touch/subdir.mk
-include LVGL/hal_stm_lvgl/tft/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := LVGL_STM32F411_DEMO
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
LVGL_STM32F411_DEMO.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
LVGL_STM32F411_DEMO.list \

OBJCOPY_BIN += \
LVGL_STM32F411_DEMO.bin \


# All Target
all: main-build

# Main-build Target
main-build: LVGL_STM32F411_DEMO.elf secondary-outputs

# Tool invocations
LVGL_STM32F411_DEMO.elf: $(OBJS) $(USER_OBJS) C:\Users\paulo\STM32CubeIDE\LVGL\LVGL_STM32F411_DEMO\STM32F411CEUX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "LVGL_STM32F411_DEMO.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\paulo\STM32CubeIDE\LVGL\LVGL_STM32F411_DEMO\STM32F411CEUX_FLASH.ld" --specs=nosys.specs -Wl,-Map="LVGL_STM32F411_DEMO.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

LVGL_STM32F411_DEMO.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "LVGL_STM32F411_DEMO.list"
	@echo 'Finished building: $@'
	@echo ' '

LVGL_STM32F411_DEMO.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "LVGL_STM32F411_DEMO.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(SIZE_OUTPUT)$(OBJDUMP_LIST)$(EXECUTABLES)$(OBJS)$(S_DEPS)$(S_UPPER_DEPS)$(C_DEPS)$(OBJCOPY_BIN) LVGL_STM32F411_DEMO.elf
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
