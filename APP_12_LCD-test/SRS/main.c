<<<<<<< HEAD
/*
 * main.c
 *
 *  Created on: May 18, 2023
 *      Author: Omar A.Qadir
 */


//#include<avr/io.h>
#include<util/delay.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../Drivers/MCAL/DIO/DIO_interface.h"


#define EN 0
#define RW 1
#define RS 2

#define control_port PORTB
#define data_port PORTA

#define function_set 0b00111000
#define disp_control 0b00001100
#define disp_clear	 0b00000001

void write_cmd(u8 cmd){
	DIO_void_clear_pin(control_port, RS);
	DIO_void_clear_pin(control_port, RW);
	_delay_us(1);
	DIO_void_set_pin(control_port, EN);
	_delay_us(1);
	DIO_void_assign_port(data_port, cmd);
	DIO_void_clear_pin(control_port, EN);
	_delay_us(1);
}

void write_data(u8 word){
	DIO_void_set_pin(control_port, RS);
	DIO_void_clear_pin(control_port, RW);
	_delay_us(1);
	DIO_void_set_pin(control_port, EN);
	_delay_us(1);
	DIO_void_assign_port(data_port, word);
	DIO_void_clear_pin(control_port, EN);
	_delay_us(1);
}

void LCD_init_8bit(){
	DIO_void_set_port_dir(data_port, OUTPUT);
	DIO_void_set_pin_dir(control_port, EN, OUTPUT);
	DIO_void_set_pin_dir(control_port, RW, OUTPUT);
	DIO_void_set_pin_dir(control_port, RS, OUTPUT);

	_delay_ms(50);
	write_cmd(function_set);
	_delay_us(50);
	write_cmd(disp_control);
	_delay_us(50);
	write_cmd(disp_clear);
	_delay_ms(2);
}

void LCD_write_char_8bit(u8 data){
	write_data(data);
	_delay_us(50);
}

void LCD_write_string_8bit(u8* str){
	u8 i= 0;
	while(str[i] != '\0'){
		LCD_write_char_8bit(str[i]);
		i++;
	}
}

int main(void){

	LCD_init_8bit();
	LCD_write_char_8bit('S');
	LCD_write_char_8bit(' ');

	u8 string[]= "Omar";
	LCD_write_string_8bit(string);


	while(1){

	}
	return 0;
}
=======
/*
 * main.c
 *
 *  Created on: May 18, 2023
 *      Author: Omar A.Qadir
 */


//#include<avr/io.h>
#include<util/delay.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../Drivers/MCAL/DIO/DIO_interface.h"


#define EN 0
#define RW 1
#define RS 2

#define control_port PORTB
#define data_port PORTA

#define function_set 0b00111000
#define disp_control 0b00001100
#define disp_clear	 0b00000001

void write_cmd(u8 cmd){
	DIO_void_clear_pin(control_port, RS);
	DIO_void_clear_pin(control_port, RW);
	_delay_us(1);
	DIO_void_set_pin(control_port, EN);
	_delay_us(1);
	DIO_void_assign_port(data_port, cmd);
	DIO_void_clear_pin(control_port, EN);
	_delay_us(1);
}

void write_data(u8 word){
	DIO_void_set_pin(control_port, RS);
	DIO_void_clear_pin(control_port, RW);
	_delay_us(1);
	DIO_void_set_pin(control_port, EN);
	_delay_us(1);
	DIO_void_assign_port(data_port, word);
	DIO_void_clear_pin(control_port, EN);
	_delay_us(1);
}

void LCD_init_8bit(){
	DIO_void_set_port_dir(data_port, OUTPUT);
	DIO_void_set_pin_dir(control_port, EN, OUTPUT);
	DIO_void_set_pin_dir(control_port, RW, OUTPUT);
	DIO_void_set_pin_dir(control_port, RS, OUTPUT);

	_delay_ms(50);
	write_cmd(function_set);
	_delay_us(50);
	write_cmd(disp_control);
	_delay_us(50);
	write_cmd(disp_clear);
	_delay_ms(2);
}

void LCD_write_char_8bit(u8 data){
	write_data(data);
	_delay_us(50);
}

void LCD_write_string_8bit(u8* str){
	u8 i= 0;
	while(str[i] != '\0'){
		LCD_write_char_8bit(str[i]);
		i++;
	}
}

int main(void){

	LCD_init_8bit();
	LCD_write_char_8bit('S');
	LCD_write_char_8bit(' ');

	u8 string[]= "Omar";
	LCD_write_string_8bit(string);


	while(1){

	}
	return 0;
}
>>>>>>> a73b211c25f3e2130416d3627f21379d7d4e605f
