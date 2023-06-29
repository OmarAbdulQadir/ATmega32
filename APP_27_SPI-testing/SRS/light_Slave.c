/*
 * light_Slave.c
 *
 *  Created on: Jun 22, 2023
 *      Author: Omar A.Qadir
 */

// Libraries section
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

// Private libraries section
#include "../INC/light_Slave.h"

// Drivers Section
#include "../../Drivers/MCAL/ADC/ADC_interface.h"
#include "../../Drivers/MCAL/TIMER/TIMER_interface.h"
#include "../../Drivers/MCAL/SPI/SPI_interface.h"

// Global variables
extern u8 real_light;

void update_light_value(void ){
	// overflow counter for more time to be counted
	static u8 light_slave_OVF_counter = bottom;
	// update the light value to be sent every 30 ms
	if (light_slave_OVF_counter == timer_OVF_lim){
		// Create variable to save digital value of light
		u16 copy_digital_light= 0;
		// Read the new light value
		ADC_void_read_data(&copy_digital_light);
		// Calculate the analog voltage
		f32 analog_voltage = (copy_digital_light*5)/1024.0;
		// Calculate the light intensity
		real_light= (((2500/analog_voltage) - 500)/16.7);
		// Reset the timer configurations
		TIMER_config();
		SPI_u8_slave_update(real_light);
		light_slave_OVF_counter = bottom;
	}
	else{
		light_slave_OVF_counter++;
	}
}
