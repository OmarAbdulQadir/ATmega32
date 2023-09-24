/*
 * main.c
 *
 *  Created on: Aug 3, 2023
 *      Author: Omar A.Qadir
 */

// Standard libraries section
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

// Drivers section
#include "../../Drivers/HAL/LCD/LCD_interface.h"
#include "../../Drivers/HAL/Temp_sensor/Temp_sensor_interface.h"

// Macros section

// Global Variables section

// main function section
int main(void){
	// Setup section

	LCD_init();
	LCD_write_str((u8*)"Value = ");

	Temp_sensor_voidInit(0);
	u8 Temp = Temp_sensor_u8ClcTemp();
	u8 Temp_prev = 0;

	while(1){
		// Loop section

		if(Temp != Temp_prev){
			Temp_prev = Temp;
			LCD_set_cursor(0, 8);
			LCD_write_float(Temp_prev, 2);
		}
		Temp = Temp_sensor_u8ClcTemp();
	}
	return 0;
}
