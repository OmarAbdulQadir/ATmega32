##########                   Target Specific Details                 ##########
##########               Customize these for your project            ##########
##########                          LED Flashing                     ##########

###############################################################################
##########                       Files sections                      ##########
###############################################################################

## Main App
TARGET= main

## Source files
SRS= $(TARGET).c
#SRS+= <Dir>
#Adding sources from MCAL
#SRS+= ../../MCAL/SRS/<fileName>.c
#Adding sources from HAL
#SRS+= ../../HAL/SRS/<fileName>.c

## INC files
#Adding Standard libraries
INC= -I/../../LIB/BIT_MATH.h
INC+= -I/../../LIB/STD_TYPES.h
#INC+= -I<Dir>
#Adding Headers from MCAL
#INC+= -I/../../MCAL/INC/<fileName>.h
#Adding Headers from HAL
#INC+= -I/../../HAL/INC/<fileName>.h

###############################################################################
##########                       Flags sections                      ##########
###############################################################################

## Name of target microcontroller
#CC :: Compiler Microcontroller
MCU_CC= atmega32
#PR :: avr-dude Microcontroller
MCU_PR= m32

## Name of target avr-dude programmer
Burner= usbasp
PORT= com2

## Clock Frequency
F_CPU= 8000000

## Compiler flags
CFLAGS= -Wall -g3

## Optimization level
# Ox:: 1, 2, 3(fastest), s(smallest), g(for debugging only)
OPT= -Os

## Linker flags
LFLAGS= 

## Assembler flags
AFLAGS= -c 

## Hex flags
HFLAGS= -j .text -j .data -O ihex


###############################################################################
##########                     excutables sections                   ##########
###############################################################################

## Compiler
CC= avr-gcc
OBJCOPY= avr-objcopy
SIZE= avr-size

## Programmer
PROGRAMMER= avrdude

###############################################################################
##########                       Commands sections                   ##########
###############################################################################

##all :: Compiles, build, burn, and then clean the files
all: build size burn clean


##Build:: compile, assemble, link and then create hex file
build: $(TARGET).hex

#compile and assemble
$(TARGET).o: $(SRS)
	$(CC) $^ $(INC) $(OPT) $(CFLAGS) -mmcu=$(MCU_CC) -o $@

#link
$(TARGET).elf: $(TARGET).o
	$(CC) $(SRS) $(INC) $(OPT) $(LFLAGS) -mmcu=$(MCU_CC) -o $(TARGET).elf

#create hex file
$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) $(HFLAGS) $^ $@


##file size:: Prints the file size
size: build
	$(SIZE) --format=avr --mcu=$(MCU_CC) $(TARGET).elf
	
	
##burn:: commands only for Burnning process
burn: build
	$(PROGRAMMER) -c $(Burner) -P $(PORT) -p $(MCU_PR) -U flash:w:$(TARGET).hex


##clean:: command only for cleanning the o/p files for the whole process
clean:
	del *.hex *.elf *.o