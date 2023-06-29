/*
 * main.c
 *
 *  Created on: May 19, 2023
 *      Author: Omar A.Qadir
 */


#include <util/delay.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../Drivers/MCAL/DIO/DIO_interface.h"
#include "../../Drivers/HAL/LCD/LCD_interface.h"

int main(void){

	LCD_init();

	LCD_write_char('S');
	LCD_write_char(5+'0');
	LCD_write_char(' ');

	LCD_set_cursor(0, 4);
	u8 str1[]= "Omar ";
	LCD_write_str(str1);

	LCD_set_cursor(1, 6);
	LCD_write_s32_number(-12345);

	f32 float_val= 10.2;
	LCD_clear();
	for(u8 i= 0; i< 10; i++){
		float_val += i/10.0;
		LCD_write_float(float_val, 2);
		_delay_ms(250);
		LCD_clear();
	}

/*
	u8 new_char[3][8]= {{0, 0, 0, 4, 3, 4, 24, 0},
						{0, 0, 4, 10, 31, 0, 0, 0},
						{0, 0, 3, 4, 31, 0, 0, 0}};
	LCD_create_char(new_char[0], 0);
	LCD_create_char(new_char[1], 1);
	LCD_create_char(new_char[2], 2);
	LCD_clear();
	LCD_write_char(0);
	LCD_write_char(1);
	LCD_write_char(2);
*/

	_delay_ms(1000);
	LCD_clear();
	s32 val= 3245435;
	while(1){
		u8 str2[]= "The number ";
		LCD_write_str(str2);
		LCD_set_cursor(1, 0);
		LCD_write_s32_number(val);
		val--;
		_delay_ms(50);
		LCD_clear();
	}
	return 0;
}
