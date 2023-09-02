################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ACC_MNGR/ACC_program.c 

OBJS += \
./ACC_MNGR/ACC_program.o 

C_DEPS += \
./ACC_MNGR/ACC_program.d 


# Each subdirectory must supply rules for building sources it contributes
ACC_MNGR/%.o: ../ACC_MNGR/%.c ACC_MNGR/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


