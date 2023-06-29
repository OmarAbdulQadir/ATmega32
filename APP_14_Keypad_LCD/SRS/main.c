/*
 * main.c
 *
 *  Created on: May 19, 2023
 *      Author: Omar A.Qadir
 */


#include <util/delay.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../Drivers/HAL/KEYPAD/KEYPAD_interface.h"
#include "../../Drivers/HAL/LCD/LCD_interface.h"


int main(void){
	LCD_init();
	u8 str[]= "Starting";
	LCD_write_str(str);
	for(u8 i= 0; i <2 ;i++){
		_delay_ms(50);
		LCD_write_char('.');
	}
	_delay_ms(150);

	keypad_init();
	LCD_clear();
	u8 str1[]= "Value = ";
	LCD_write_str(str1);
	s32 val= 0;
	LCD_write_s32_number(val);
	while(1){
		val= keypad_read();
		if(-1 != val){
			LCD_clear();
			LCD_write_str(str1);
			LCD_write_s32_number(val);
		}
	}
	return 0;
}
