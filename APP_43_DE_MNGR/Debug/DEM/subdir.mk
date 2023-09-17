################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DEM/DEM_config.c \
../DEM/DEM_program.c 

OBJS += \
./DEM/DEM_config.o \
./DEM/DEM_program.o 

C_DEPS += \
./DEM/DEM_config.d \
./DEM/DEM_program.d 


# Each subdirectory must supply rules for building sources it contributes
DEM/%.o: ../DEM/%.c DEM/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


