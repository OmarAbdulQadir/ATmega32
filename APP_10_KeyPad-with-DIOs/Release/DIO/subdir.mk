################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/Engineering/Embedded/IMT_Dip/Interfacing/ATmega32/Drivers/MCAL/DIO/DIO_program.c 

C_DEPS += \
./DIO/DIO_program.d 

OBJS += \
./DIO/DIO_program.o 


# Each subdirectory must supply rules for building sources it contributes
DIO/DIO_program.o: D:/Engineering/Embedded/IMT_Dip/Interfacing/ATmega32/Drivers/MCAL/DIO/DIO_program.c DIO/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-DIO

clean-DIO:
	-$(RM) ./DIO/DIO_program.d ./DIO/DIO_program.o

.PHONY: clean-DIO

