/*
 * main.c
 *
 *  Created on: May 20, 2023
 *      Author: Omar A.Qadir
 */


#include <util/delay.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../Drivers/MCAL/DIO/DIO_interface.h"


#define forward_pin B0
#define reverse_pin B1
#define forward_sw B2
#define reverse_sw B3

int main(void){

	DIO_void_set_pin_dir(PORTC, forward_pin, OUTPUT);
	DIO_void_set_pin_dir(PORTC, reverse_pin, OUTPUT);

	DIO_void_clear_pin(PORTC, forward_pin);
	DIO_void_clear_pin(PORTC, reverse_pin);

	DIO_void_set_pin_in_pullUP(PORTC, forward_sw);
	DIO_void_set_pin_in_pullUP(PORTC, reverse_sw);

	while(1){
		u8 forward_sw_val = DIO_u8_get_pin(PORTC, forward_sw);
		u8 reverse_sw_val = DIO_u8_get_pin(PORTC, reverse_sw);
		if((forward_sw_val == HIGH) && (reverse_sw_val == LOW)){
			DIO_void_clear_pin(PORTC, reverse_pin);
			DIO_void_assign_pin(PORTC, forward_pin, HIGH);
		}
		else if((forward_sw_val == LOW) && (reverse_sw_val == HIGH)){
			DIO_void_clear_pin(PORTC, forward_pin);
			DIO_void_assign_pin(PORTC, reverse_pin, HIGH);
		}
		else if((forward_sw_val == HIGH) && (reverse_sw_val == HIGH)){
			DIO_void_clear_pin(PORTC, forward_pin);
			DIO_void_clear_pin(PORTC, reverse_pin);
		}
		else{
			DIO_void_clear_pin(PORTC, forward_pin);
			DIO_void_clear_pin(PORTC, reverse_pin);
		}
		/*
		DIO_void_clear_pin(PORTC, forward_pin);
		DIO_void_clear_pin(PORTC, reverse_pin);
		_delay_ms(100);
		DIO_void_clear_pin(PORTC, reverse_pin);
		DIO_void_assign_pin(PORTC, forward_pin, HIGH);
		_delay_ms(2500);
		DIO_void_clear_pin(PORTC, forward_pin);
		DIO_void_assign_pin(PORTC, reverse_pin, HIGH);
		_delay_ms(2500);
		*/
	}
	return 0;
}
;
