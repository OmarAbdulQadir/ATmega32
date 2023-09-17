################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../AIC_MNGR/AIC_config.c \
../AIC_MNGR/AIC_program.c 

OBJS += \
./AIC_MNGR/AIC_config.o \
./AIC_MNGR/AIC_program.o 

C_DEPS += \
./AIC_MNGR/AIC_config.d \
./AIC_MNGR/AIC_program.d 


# Each subdirectory must supply rules for building sources it contributes
AIC_MNGR/%.o: ../AIC_MNGR/%.c AIC_MNGR/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


