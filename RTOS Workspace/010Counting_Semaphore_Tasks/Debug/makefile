################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include common/ThirdParty/SEGGER/SEGGER/Syscalls/subdir.mk
-include common/ThirdParty/SEGGER/SEGGER/subdir.mk
-include common/ThirdParty/SEGGER/Rec/subdir.mk
-include common/ThirdParty/SEGGER/OS/subdir.mk
-include common/ThirdParty/SEGGER/Config/subdir.mk
-include common/ThirdParty/FreeRTOS/portable/MemMang/subdir.mk
-include common/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F/subdir.mk
-include common/ThirdParty/FreeRTOS/subdir.mk
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


BUILD_ARTIFACT_NAME := 010Counting_Semaphore_Tasks
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX := 
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME).$(BUILD_ARTIFACT_EXTENSION)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
010Counting_Semaphore_Tasks.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
010Counting_Semaphore_Tasks.list \

OBJCOPY_BIN += \
010Counting_Semaphore_Tasks.bin \


# All Target
all: main-build

# Main-build Target
main-build: 010Counting_Semaphore_Tasks.elf secondary-outputs

# Tool invocations
010Counting_Semaphore_Tasks.elf: $(OBJS) $(USER_OBJS) C:\Users\Oliver\Desktop\FastBit\ Embedded\ Brain\ Academy\CubeIDE\ Workspaces\Mastering\ RTOS\ -\ Hands\ on\ FreeRTOS\ and\ STM32Fx\ with\ Debugging\RTOS\ Workspace\010Counting_Semaphore_Tasks\STM32F446RETX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "010Counting_Semaphore_Tasks.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\Oliver\Desktop\FastBit Embedded Brain Academy\CubeIDE Workspaces\Mastering RTOS - Hands on FreeRTOS and STM32Fx with Debugging\RTOS Workspace\010Counting_Semaphore_Tasks\STM32F446RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="010Counting_Semaphore_Tasks.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

010Counting_Semaphore_Tasks.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "010Counting_Semaphore_Tasks.list"
	@echo 'Finished building: $@'
	@echo ' '

010Counting_Semaphore_Tasks.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "010Counting_Semaphore_Tasks.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents fail-specified-linker-script-missing warn-no-linker-script-specified
.SECONDARY:

-include ../makefile.targets
