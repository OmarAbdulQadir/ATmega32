//Define the CPU frequency
#define F_CPU 8000000UL

//Standard libraries Section
#include <avr/io.h>
#include <util/delay.h>
//#include "../../LIB/BIT_MATH.h"
//#include "../../LIB/STD_TYPES.h"

//MCAL layer Section
//#include "../../MCAL/INC/<fileName>.h"

//HAL layer Section
//#include "../../HAL/INC/<fileName>.h"

//Private libraries Section
//#include "<fileName>.h"

//Global valriables, struct and enums

 
int main(void){
	
	DDRA= 1;
	PORTA= 0;
	
	while(1){
		PORTA= 1;
		_delay_ms(1000);
		PORTA= 0;
		_delay_ms(500);
	}
	return 0;
}