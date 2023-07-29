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
#include "../../Drivers/MCAL/ADC/ADC_interface.h"

// Macros section


// Global Variable section


// Main function
int main(void ){
	// Setup section

	DIO_void_set_pin_dir(DIO_REF_PORTB, B3, OUTPUT);

	u8 preload_val[] = {0, 126};
	PWM_config PWM_config_struct = {PWM_fast, PWM_fast_clr_top, PWM_1024PRE, 0, preload_val};
	gen_PWM(&PWM_config_struct);

	ADC_config_struct ADC_config_struct = {0, 3, 0, 0, 0};
	ADC_void_init();
	ADC_void_config(&ADC_config_struct);
	u16 analog_data = 0, last_analog_data = 0;
	ADC_void_read_data(&analog_data);

	while(1){
		// Loop section
		if(analog_data != last_analog_data){
			preload_val[1] = analog_data/4;
			gen_PWM(&PWM_config_struct);
			last_analog_data = analog_data;
		}
		ADC_void_read_data(&analog_data);
	}
	return 0;
}

