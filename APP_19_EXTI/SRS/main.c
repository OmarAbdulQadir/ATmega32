/*
 * main.c
 *
 *  Created on: Jun 2, 2023
 *      Author: Omar A.Qadir
 */

#include <util/delay.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../Drivers/MCAL/DIO/DIO_interface.h"
#include "../../Drivers/MCAL/EXTI/EXTI_interface.h"

void toggle_value(void);

int main(void){
	// Setup section
	DIO_void_set_pin_in_pullUP(PORTB, B2);
	DIO_void_set_pin_dir(PORTA, B1, OUTPUT);


	EXTI_init_config_struct EXTI_config = {disable, EXTI_falling_edge, disable, EXTI_falling_edge, enable, EXTI_INT2_falling_edge};
	EXTI_void_init(&EXTI_config);
	EXTI_void_INT_callback(INT2, toggle_value);

	while(1){
		// Loop section

	}
	return 0;
}



void toggle_value(void){
	DIO_void_toggle_pin(PORTA, B1);
}

