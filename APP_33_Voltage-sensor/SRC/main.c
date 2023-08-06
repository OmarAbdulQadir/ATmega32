/*
 * main.c
 *
 *  Created on: Jul 31, 2023
 *      Author: Omar A.Qadir
 */

// STD Libraries section
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <util/delay.h>

// Drivers section
#include "../../Drivers/HAL/LCD/LCD_interface.h"
#include "../../Drivers/HAL/V_DC_sensor/V_DC_sensor_interface.h"

// Macros section

// Global variables section

// Main function section
int main(void){
	// Setup section

	LCD_init();
	LCD_write_str((u8*) "value= ");

	Vsensor_voidInit(0);
	Vsensor_voidClcVolt();
	f64 voltage = Vsensor_voidClcVolt();
	f64 voltage_prev = 0;



	while(1){
		// Loop section
			if(voltage != voltage_prev){
				voltage_prev = voltage;
				LCD_set_cursor(0, 8);
				LCD_write_str((u8*) "    ");
				LCD_set_cursor(0, 8);
				LCD_write_float(voltage_prev, 2);
			}
			voltage = Vsensor_voidClcVolt();
		}
	return 0;
}
