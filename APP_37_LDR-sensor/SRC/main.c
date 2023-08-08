/*
 * main.c
 *
 *  Created on: Aug 6, 2023
 *      Author: Omar A.Qadir
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../Drivers/MCAL/EEP/EEP_interface.h"

#include "../../Drivers/HAL/LCD/LCD_interface.h"
#include "../../Drivers/HAL/LDR_sensor/LDR_sensor_interface.h"


int main(void){

	u8 EEPROM_counter = 0;

	LCD_init();
	LCD_write_str((u8*) "Value: ");

	LDRsensor_voidInit(0);
	u8 intensity = LDRsensor_voidClcInt();
	u8 prev_int = 100;

	while(1){
		if(prev_int != intensity){
			prev_int = intensity;
			LCD_set_cursor(0, 7);
			LCD_write_s32_number(prev_int);
			EEPROM_write_data(EEPROM_counter++, prev_int);
		}
		intensity = LDRsensor_voidClcInt();
	}
	return 0;
}
