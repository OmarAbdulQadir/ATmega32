/*
 * main.c
 *
 *  Created on: May 20, 2023
 *      Author: Omar A.Qadir
 */


#include <util/delay.h>
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../Drivers/HAL/KEYPAD/KEYPAD_interface.h"
#include "../../Drivers/HAL/LCD/LCD_interface.h"
#include "../INC/clc.h"



s8 keyMap[16] = {7, 8, 9, '/', 4, 5, 6, 'x', 1,  2,  3, '-', 'C',  0, '=', '+'};
//Mapping to :: {7, 8, 9,  47, 4, 5, 6, 120, 1,  2,  3,  45,  67,  0,  61,  43}


int main(void){

	// Prepherals initiation
	LCD_init();
	keypad_init();
	keypad_set_map(keyMap);
	s32 val = 0;
	u16 off_count= 0;
	while(val != 67){
		val= keypad_read();
	}

	LCD_write_str("Starting...");
	_delay_ms(250);
	LCD_clear();

	// Super loop
	while(1){
		// use counter to shut down when calculator is not used
		// Check the keypad buttons for any actions taken
		off_count++;
		val= keypad_read();
		if(val != -1){
			// Lots of handling
			if (val == 61){

			}
			else if(val == 67){
				LCD_clear();
				calc(-1, -1);
			}
			else if(val > 9){

			}
			else if(val < 9){

			}
		}
		if(off_count == -1){
			// counter for power saving
			LCD_clear();
			while(val != 67){
				val= keypad_read();
			}
			LCD_write_str("Enter value.");
			_delay_ms(250);
			LCD_clear();
		}
	}
	return 0;
}
