/*
 * main.c
 *
 *  Created on: May 6, 2023
 *      Author: Omar A.Qadir
 */


#include <util/delay.h>
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../Drivers/MCAL/DIO/DIO_interface.h"

#define test_port_in DIO_REF_PORTA
#define test_port_out DIO_REF_PORTB

int main(void){

	for(u8 i= 0; i< 8; i++){
		DIO_void_set_pin_in_pullUP(test_port_in, i);
		DIO_void_set_pin_dir(test_port_out, i, OUTPUT);
	}
	while(1){
		for(u8 i= 0; i< 8; i++){
			DIO_void_assign_pin(test_port_out, i, DIO_u8_get_pin(test_port_in, i));
		}
	}
	return 0;
}
