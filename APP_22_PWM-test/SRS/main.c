/*
 * main.c
 *
 *  Created on: Jul 3, 2023
 *      Author: Omar A.Qadir
 */


// STD Libraries section
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BiT_MATH.h"


// Drivers section
#include "../../Drivers/MCAL/DIO/DIO_interface.h"
#include "../../Drivers/MCAL/PWM/PWM_interface.h"

// Macros section


// Global Variable section


// Main function
int main(void ){
	// Setup section

	DIO_void_set_pin_dir(PORTB, B3, OUTPUT);

	u8 preload_val[] = {0, 175};
	PWM_config PWM_config_struct = {PWM_fast, PWM_fast_clr_top, PWM_1024PRE, 0, preload_val};
	gen_PWM(&PWM_config_struct);

	while(1){
		// Loop section

	}
	return 0;
}

