################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SRS/main.c 

C_DEPS += \
./SRS/main.d 

OBJS += \
./SRS/main.o 


# Each subdirectory must supply rules for building sources it contributes
SRS/%.o: ../SRS/%.c SRS/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-SRS

clean-SRS:
	-$(RM) ./SRS/main.d ./SRS/main.o

.PHONY: clean-SRS

