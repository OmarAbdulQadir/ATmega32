################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIOC_MNGR/DIOC_config.c \
../DIOC_MNGR/DIOC_program.c 

OBJS += \
./DIOC_MNGR/DIOC_config.o \
./DIOC_MNGR/DIOC_program.o 

C_DEPS += \
./DIOC_MNGR/DIOC_config.d \
./DIOC_MNGR/DIOC_program.d 


# Each subdirectory must supply rules for building sources it contributes
DIOC_MNGR/%.o: ../DIOC_MNGR/%.c DIOC_MNGR/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


