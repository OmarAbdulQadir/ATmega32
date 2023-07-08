/*
 * main.c
 *
 *  Created on: Jun 16, 2023
 *      Author: Omar A.Qadir
 */


// Libraries section
#include <util/delay.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

// Drivers section
#include "../../Drivers/MCAL/DIO/DIO_interface.h"
#include "../../Drivers/MCAL/WDT/WDT_interface.h"

// Macros section

// Functions decleration


// Global variables Section


int main(void){
	// Setup section
	DIO_void_set_pin_dir(DIO_REF_PORTA, B0, OUTPUT);
	DIO_void_set_pin(DIO_REF_PORTA, B0);
	_delay_ms(1000);
	DIO_void_clear_pin(DIO_REF_PORTA, B0);

	WDT_void_start(time65_0_ms);

	_delay_ms(30);
	DIO_void_set_pin(DIO_REF_PORTA, B0);
	_delay_ms(36);
	DIO_void_clear_pin(DIO_REF_PORTA, B0);

	WDT_void_stop();

	while(1){
		// Loop section

	}
	return 0;
}
