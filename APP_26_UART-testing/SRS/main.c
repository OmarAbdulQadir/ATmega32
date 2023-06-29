/*
 * main.c
 *
 *  Created on: Jun 16, 2023
 *      Author: Omar A.Qadir
 */


// Libraries section
#include "util/delay.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

// Drivers section
#include "../../Drivers/MCAL/UART/UART_interface.h"

// Macros section


// Functions decleration


// Global variables and structs section


int main(void){
	// Setup section
	UART_void_init();
	_delay_ms(1000);
	//UART_void_transmit_char('a');
	UART_void_transmit_str("omar");

	while (1){
		// Loop sectionvoid UART_void_transmit_char(u8

	}
	return 0;
}
