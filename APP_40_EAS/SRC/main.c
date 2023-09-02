/*
 * main.c
 *
 *  Created on: Aug 24, 2023
 *      Author: Omar A.Qadir
 */


// Standard libraries section
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

// MCAL Layer section


// HAL Layer section
#include "../../Drivers/HAL/LCD/LCD_interface.h"
#include "../../Drivers/HAL/Temp_sensor/Temp_sensor_interface.h"
#include "../../Drivers/HAL/LDR_sensor/LDR_sensor_interface.h"

// main function
int main(void){

	Temp_sensor_voidInit(0);
	LDRsensor_voidInit(1);

	LCD_init();
	LCD_write_str((u8*)"Temp= ");
	LCD_set_cursor(1, 0);
	LCD_write_str((u8*)"Light lvl= ");

	f64 curr_temp, prev_temp= 0;
	u8 curr_light, prev_light= 100;

	curr_temp = Temp_sensor_voidClcTemp();
	curr_light = LDRsensor_voidClcInt();

	while(1){

		if(curr_temp != prev_temp){
			prev_temp = curr_temp;
			LCD_set_cursor(0, 6);
			LCD_write_str((u8*)"     ");
			LCD_set_cursor(0, 6);
			LCD_write_float(prev_temp, 2);
		}
		if(curr_light != prev_light){
			prev_light = curr_light;
			LCD_set_cursor(1, 11);
			LCD_write_str((u8*)" ");
			LCD_set_cursor(1, 11);
			LCD_write_s32_number(prev_light);
		}
		curr_temp = Temp_sensor_voidClcTemp();
		curr_light = LDRsensor_voidClcInt();
	}
	return 0;
}
