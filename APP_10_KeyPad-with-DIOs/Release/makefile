################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include SRS/subdir.mk
-include DIO/subdir.mk
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := APP_10_KeyPad-with-DIOs
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
APP_10_KeyPad-with-DIOs.lss \

FLASH_IMAGE += \
APP_10_KeyPad-with-DIOs.hex \

EEPROM_IMAGE += \
APP_10_KeyPad-with-DIOs.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: main-build

# Main-build Target
main-build: APP_10_KeyPad-with-DIOs.elf secondary-outputs

# Tool invocations
APP_10_KeyPad-with-DIOs.elf: $(OBJS) $(USER_OBJS) makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,APP_10_KeyPad-with-DIOs.map -mmcu=atmega32 -o "APP_10_KeyPad-with-DIOs.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

APP_10_KeyPad-with-DIOs.lss: APP_10_KeyPad-with-DIOs.elf makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S APP_10_KeyPad-with-DIOs.elf  >"APP_10_KeyPad-with-DIOs.lss"
	@echo 'Finished building: $@'
	@echo ' '

APP_10_KeyPad-with-DIOs.hex: APP_10_KeyPad-with-DIOs.elf makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex APP_10_KeyPad-with-DIOs.elf  "APP_10_KeyPad-with-DIOs.hex"
	@echo 'Finished building: $@'
	@echo ' '

APP_10_KeyPad-with-DIOs.eep: APP_10_KeyPad-with-DIOs.elf makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex APP_10_KeyPad-with-DIOs.elf  "APP_10_KeyPad-with-DIOs.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: APP_10_KeyPad-with-DIOs.elf makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 APP_10_KeyPad-with-DIOs.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) APP_10_KeyPad-with-DIOs.eep APP_10_KeyPad-with-DIOs.elf APP_10_KeyPad-with-DIOs.hex APP_10_KeyPad-with-DIOs.lss sizedummy
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents main-build

-include ../makefile.targets
