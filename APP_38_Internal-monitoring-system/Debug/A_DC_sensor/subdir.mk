################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/Engineering/Embedded/IMT_Dip/Interfacing/ATmega32/Drivers/HAL/A_DC_sensor/A_DC_sensor_program.c 

OBJS += \
./A_DC_sensor/A_DC_sensor_program.o 

C_DEPS += \
./A_DC_sensor/A_DC_sensor_program.d 


# Each subdirectory must supply rules for building sources it contributes
A_DC_sensor/A_DC_sensor_program.o: D:/Engineering/Embedded/IMT_Dip/Interfacing/ATmega32/Drivers/HAL/A_DC_sensor/A_DC_sensor_program.c A_DC_sensor/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


