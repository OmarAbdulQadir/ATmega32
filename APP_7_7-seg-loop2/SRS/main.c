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

int main(void){

	u8 seg_val_dec[10] ={64, 121, 36, 48, 25, 18, 2, 120, 0, 24}; //DEC values for the 7 segment numbers
	DIO_void_set_port_dir(PORTC, PORT_MAX);
	DIO_void_set_port_dir(PORTD, PORT_MAX);
	DIO_void_set_port(PORTC);
	DIO_void_set_port(PORTD);
	u8 count = min;

	while(1){
		if (max < count){
			count = min;
		}
		DIO_void_assign_port(PORTC, seg_val_dec[(count/10)]);
		DIO_void_assign_port(PORTD, seg_val_dec[(count%10)]);
		count++;
		_delay_ms(100);
	}
	return 0;
}
