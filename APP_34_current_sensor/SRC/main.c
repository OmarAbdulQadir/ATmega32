/*
 * main.c
 *
 *  Created on: Jul 31, 2023
 *      Author: Omar A.Qadir
 */


// STD Libraries section
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

// Drivers section
#include "../../Drivers/MCAL/DIO/DIO_interface.h"
#include "../../Drivers/HAL/LCD/LCD_interface.h"
#include "../../Drivers/HAL/A_DC_sensor/A_DC_sensor_interface.h"

// Macros section

// Global variables section

// Main function section
int main(void){
	// Setup section

	DIO_void_set_pin_dir(DIO_REF_PORTB, B0, OUTPUT);
	DIO_void_set_pin(DIO_REF_PORTB, B0);

	LCD_init();
	LCD_write_str((u8*) "value= ");

	A_DC_sensor_voidInit(Amp_A0_1);
	f64 Amps = 0, Amps_prev = 0;
	Amps = A_DC_sensor_voidClcAmps();


	while(1){
		// Loop section
		if(Amps != Amps_prev){
			Amps_prev = Amps;
			LCD_set_cursor(0, 7);
			LCD_write_str((u8*)"    ");
			LCD_set_cursor(0, 7);
			LCD_write_float(Amps_prev, 2);
		}
		DIO_void_toggle_pin(DIO_REF_PORTB, B0);
		Amps = A_DC_sensor_voidClcAmps();
		DIO_void_toggle_pin(DIO_REF_PORTB, B0);
	}
	return 0;
}
