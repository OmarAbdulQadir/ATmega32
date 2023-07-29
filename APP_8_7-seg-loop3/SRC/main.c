/*
 * main.c
 *
 *  Created on: May 5, 2023
 *      Author: Omar A.Qadir
 */

//Standard libraries Section
//#include <avr/io.h>
#include <util/delay.h>
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

//MCAL layer Section
//#include "../MCAL/<driverName>/interface.h"
#include "../../Drivers/MCAL/DIO/DIO_interface.h"

//HAL layer Section
//#include "../HAL/<driverName>/interface.h"

//Private libraries Section
//#include "../INC/<fileName>.h"

//Global valriables, struct and enums
#define max 99
#define min 0

#define ref_rate 50
#define _delay_time 2

int main(void){

	u8 seg_val_dec[10] ={64, 121, 36, 48, 25, 18, 2, 120, 0, 24}; //DEC values for the 7 segment numbers
	DIO_void_set_port_dir(DIO_REF_PORTD, OUTPUT);
	DIO_void_set_pin_dir(DIO_REF_PORTC, B0, OUTPUT);
	DIO_void_set_pin_dir(DIO_REF_PORTC, B1, OUTPUT);
	u8 count = 0;

	while(1){
		if (max < count){
			count = 0;
		}
		for(u8 i = 0; i < ref_rate; i++){
			DIO_void_set_pin(DIO_REF_PORTC, B0);
			DIO_void_assign_port(DIO_REF_PORTD, seg_val_dec[(count/10)]);
			_delay_ms(_delay_time);
			DIO_void_clear_pin(DIO_REF_PORTC, B0);
			DIO_void_set_pin(DIO_REF_PORTC, B1);
			DIO_void_assign_port(DIO_REF_PORTD, seg_val_dec[(count%10)]);
			_delay_ms(_delay_time);
			DIO_void_clear_pin(DIO_REF_PORTC, B1);
		}
		count++;
	}
	return 0;
}
