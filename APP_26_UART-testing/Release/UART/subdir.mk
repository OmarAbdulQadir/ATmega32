################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/Engineering/Embedded/IMT_Dip/Interfacing/ATmega32/Drivers/MCAL/UART/UART_program.c 

OBJS += \
./UART/UART_program.o 

C_DEPS += \
./UART/UART_program.d 


# Each subdirectory must supply rules for building sources it contributes
UART/UART_program.o: D:/Engineering/Embedded/IMT_Dip/Interfacing/ATmega32/Drivers/MCAL/UART/UART_program.c UART/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


