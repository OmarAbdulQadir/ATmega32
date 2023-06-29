//Define the CPU frequency
#define F_CPU 8000000UL

//Standard libraries Section
//#include <avr/io.h>
#include <util/delay.h>
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

//MCAL layer Section
#include "../../MCAL/DIO/interface.h"
//#include "../../MCAL/<libraryName>/interface.h"

//HAL layer Section
//#include "../../HAL/<libraryName>/interface.h"

//Private libraries Section
//#include "<fileName>.h"

//Global valriables, struct and enums
#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3
#define B0 0
#define B1 1
#define B2 2
#define B3 3
#define B4 4
#define B5 5
#define B6 6
#define B7 7
#define OUTPUT 1
#define INPUT 0
 
int main(void){
	
	set_pin_dir(PORTA, B0, OUTPUT);
	clear_pin(PORTA, B0);
	
	while(1){
		set_pin(PORTA, B0);
		_delay_ms(1000);
		clear_pin(PORTA, B0);
		_delay_ms(500);
	
	}
	return 0;
}