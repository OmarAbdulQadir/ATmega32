################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SRS/Master.c \
../SRS/light_Slave.c \
../SRS/main.c \
../SRS/motor_Slave.c \
../SRS/temp_Slave.c 

OBJS += \
./SRS/Master.o \
./SRS/light_Slave.o \
./SRS/main.o \
./SRS/motor_Slave.o \
./SRS/temp_Slave.o 

C_DEPS += \
./SRS/Master.d \
./SRS/light_Slave.d \
./SRS/main.d \
./SRS/motor_Slave.d \
./SRS/temp_Slave.d 


# Each subdirectory must supply rules for building sources it contributes
SRS/%.o: ../SRS/%.c SRS/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


