################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/Engineering/Embedded/IMT_Dip/Interfacing/ATmega32/Drivers/MCAL/TIMER/TIMER_program.c 

C_DEPS += \
./Drivers/MCAL/TIMER/TIMER_program.d 

OBJS += \
./Drivers/MCAL/TIMER/TIMER_program.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/MCAL/TIMER/TIMER_program.o: D:/Engineering/Embedded/IMT_Dip/Interfacing/ATmega32/Drivers/MCAL/TIMER/TIMER_program.c Drivers/MCAL/TIMER/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Drivers-2f-MCAL-2f-TIMER

clean-Drivers-2f-MCAL-2f-TIMER:
	-$(RM) ./Drivers/MCAL/TIMER/TIMER_program.d ./Drivers/MCAL/TIMER/TIMER_program.o

.PHONY: clean-Drivers-2f-MCAL-2f-TIMER

