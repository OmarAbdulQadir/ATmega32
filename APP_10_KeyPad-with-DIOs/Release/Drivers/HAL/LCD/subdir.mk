################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/Engineering/Embedded/IMT_Dip/Interfacing/ATmega32/Drivers/HAL/LCD/LCD_program.c 

C_DEPS += \
./Drivers/HAL/LCD/LCD_program.d 

OBJS += \
./Drivers/HAL/LCD/LCD_program.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/HAL/LCD/LCD_program.o: D:/Engineering/Embedded/IMT_Dip/Interfacing/ATmega32/Drivers/HAL/LCD/LCD_program.c Drivers/HAL/LCD/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Drivers-2f-HAL-2f-LCD

clean-Drivers-2f-HAL-2f-LCD:
	-$(RM) ./Drivers/HAL/LCD/LCD_program.d ./Drivers/HAL/LCD/LCD_program.o

.PHONY: clean-Drivers-2f-HAL-2f-LCD

