################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/Engineering/Embedded/IMT_Dip/Interfacing/Workplace/Drivers/MCAL/ADC/ADC_program.c 

C_DEPS += \
./Drivers/MCAL/ADC/ADC_program.d 

OBJS += \
./Drivers/MCAL/ADC/ADC_program.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/MCAL/ADC/ADC_program.o: D:/Engineering/Embedded/IMT_Dip/Interfacing/Workplace/Drivers/MCAL/ADC/ADC_program.c Drivers/MCAL/ADC/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Drivers-2f-MCAL-2f-ADC

clean-Drivers-2f-MCAL-2f-ADC:
	-$(RM) ./Drivers/MCAL/ADC/ADC_program.d ./Drivers/MCAL/ADC/ADC_program.o

.PHONY: clean-Drivers-2f-MCAL-2f-ADC

