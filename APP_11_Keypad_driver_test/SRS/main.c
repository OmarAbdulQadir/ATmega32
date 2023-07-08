/*
 * main.c
 *
 *  Created on: May 12, 2023
 *      Author: Omar A.Qadir
 */


//Standard libraries Section
//#include <avr/io.h>
#include <util/delay.h>
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

//MCAL layer Section
//#include "../../MCAL/<driverName>/interface.h"
#include "../../Drivers/MCAL/DIO/DIO_interface.h"

//HAL layer Section
//#include "../../Drivers/HAL/<driverName>/<driverName>_interface.h"
#include "../../Drivers/HAL/KEYPAD/KEYPAD_interface.h"

//Private libraries Section
//#include "../INC/<fileName>.h"

//Global valriables, struct and enums



int main(void){
	DIO_void_set_port_dir(DIO_REF_PORTC, OUTPUT);
	keypad_init();
	s8 val_id;

	while(1){
		val_id = keypad_read();
		if(-1 != val_id)
			DIO_void_assign_port(DIO_REF_PORTC, val_id);
	}
	return 0;
}
