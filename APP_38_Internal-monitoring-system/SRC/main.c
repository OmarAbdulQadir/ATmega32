/*
 * main.c
 *
 *  Created on: Aug 6, 2023
 *      Author: Omar A.Qadir
 */

#include <util/delay.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../Drivers/MCAL/EEP/EEP_interface.h"

#include "../../Drivers/HAL/LCD/LCD_interface.h"
#include "../../Drivers/HAL/A_DC_sensor/A_DC_sensor_interface.h"
#include "../../Drivers/HAL/V_DC_sensor/V_DC_sensor_interface.h"
#include "../../Drivers/HAL/Temp_sensor/Temp_sensor_interface.h"

void APP_voidUpdateLCD(u8, f64 );

#define LCD_LOC0		0, 2
#define LCD_LOC1		0, 11
#define LCD_LOC2		1, 2
#define LCD_LOC3		1, 11
u32 cycle_counter= 0;


int main(void){

	LCD_init();
	LCD_write_str((u8*) "A=    mA");
	LCD_set_cursor(0, 9);
	LCD_write_str((u8*) "V=    V");
	LCD_set_cursor(1, 0);
	LCD_write_str((u8*) "P=    mW");
	LCD_set_cursor(1, 9);
	LCD_write_str((u8*) "T=    C");

	A_DC_sensor_voidInit(Amp_A0_1);
	Vsensor_voidInit(2);
	Temp_sensor_voidInit(3);

	f64 Curr_volt = Vsensor_voidClcVolt(),
		Curr_amps = A_DC_sensor_voidClcAmps(),
		Curr_temp = Temp_sensor_voidClcTemp(),
		Curr_pwr = Curr_volt*Curr_amps;

	f64 prev_volt = 0,
		prev_amps = 0,
		prev_temp = 0,
		prev_pwr = 0;

	while(1){

		// Nxt move to update the values
		if(prev_volt != Curr_volt){
			prev_volt = Curr_volt;
			APP_voidUpdateLCD(1, prev_volt);
		}
		if(prev_amps != Curr_amps){
			prev_amps = Curr_amps;
			if(prev_amps < 100.0){
				LCD_set_cursor(0, 0);
				LCD_write_str((u8*) "A=    mA");
				APP_voidUpdateLCD(0, prev_amps);
			}
			else{
				LCD_set_cursor(0, 0);
				LCD_write_str((u8*) "A=     A");
				APP_voidUpdateLCD(0, prev_amps/1000.0);
			}
		}
		if(prev_temp != Curr_temp){
			prev_temp = Curr_temp;
			APP_voidUpdateLCD(3, prev_temp);
		}
		if(prev_pwr != Curr_pwr){
			prev_pwr = Curr_pwr;
			if(prev_pwr < 100.0){
				LCD_set_cursor(1, 0);
				LCD_write_str((u8*) "P=    mW");
				APP_voidUpdateLCD(2, prev_pwr);
			}
			else{
				LCD_set_cursor(1, 0);
				LCD_write_str((u8*) "P=     W");
				APP_voidUpdateLCD(2, prev_pwr/1000.0);
			}
		}
		_delay_ms(250);
		Curr_volt = Vsensor_voidClcVolt();
		Curr_amps = A_DC_sensor_voidClcAmps();
		Curr_temp = Temp_sensor_voidClcTemp();
		Curr_pwr = Curr_volt*Curr_amps;
		cycle_counter++;

	}
	return 0;
}


void APP_voidUpdateLCD(u8 copy_u8LCD_location, f64 copy_f64Variable){
	static u8 NVM_0= 0;
	static u16 NVM_1= 256;
	static u16 NVM_2= 512;
	static u16 NVM_3= 768;
	switch(copy_u8LCD_location){
		case 0:
			LCD_set_cursor(LCD_LOC0);
			LCD_write_str((u8*)"    ");
			LCD_set_cursor(LCD_LOC0);
			LCD_write_float(copy_f64Variable, 1);
			if(copy_f64Variable > 150.0)
				EEPROM_write_data(NVM_0++, cycle_counter);
			break;
		case 1:
			LCD_set_cursor(LCD_LOC1);
			LCD_write_str((u8*)"    ");
			LCD_set_cursor(LCD_LOC1);
			LCD_write_float(copy_f64Variable, 1);
			if(copy_f64Variable < 4.35)
				EEPROM_write_data(NVM_1++, cycle_counter);
			break;
		case 2:
			LCD_set_cursor(LCD_LOC2);
			LCD_write_str((u8*)"    ");
			LCD_set_cursor(LCD_LOC2);
			LCD_write_float(copy_f64Variable, 1);
			if(copy_f64Variable > 750.0)
				EEPROM_write_data(NVM_2++, cycle_counter);
			break;
		case 3:
			LCD_set_cursor(LCD_LOC3);
			LCD_write_str((u8*)"    ");
			LCD_set_cursor(LCD_LOC3);
			LCD_write_float(copy_f64Variable, 1);
			if(copy_f64Variable > 40.0)
				EEPROM_write_data(NVM_3++, cycle_counter);
			break;
		default:
			break;
	}
}
