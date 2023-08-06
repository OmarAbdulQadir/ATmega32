/*
 * main.c
 *
 *  Created on: Aug 3, 2023
 *      Author: Omar A.Qadir
 */

#include "util/delay.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../Drivers/MCAL/EEPROM/EEPROM_interface.h"
#include "../../Drivers/MCAL/DIO/DIO_interface.h"


int main (void){

	DIO_void_set_pin_dir(DIO_REF_PORTA, B0, OUTPUT);
	EEPROM_write_data(5, 1);
	DIO_void_assign_pin(DIO_REF_PORTA, B0, EEPROM_read_data(5));

	_delay_ms(1000);

	EEPROM_write_data(5, 0);
	DIO_void_assign_pin(DIO_REF_PORTA, B0, EEPROM_read_data(5));

	while(1){

	}
	return 0;
}
