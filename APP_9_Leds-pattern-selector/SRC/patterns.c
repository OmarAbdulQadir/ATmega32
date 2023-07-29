/*
 * patterns.c
 *
 *  Created on: May 6, 2023
 *      Author: Omar A.Qadir
 */

#include <util/delay.h>
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../INC/patterns.h"
#include "../../Drivers/MCAL/DIO/DIO_interface.h"

void flashing_led( ){
	DIO_void_set_port(__port_out_);
	_delay_ms(300);
	DIO_void_clear_port(__port_out_);
	_delay_ms(300);
}

void lshift( ){
	u8 val= 0b00000001;
	DIO_void_assign_port(__port_out_, val);
	for(u8 i = 0; i < 8; i++){
		DIO_void_assign_port(__port_out_, (val<<i));
		_delay_ms(250);
	}
}

void rshift( ){
	u8 val= 0b10000000;
	DIO_void_assign_port(__port_out_, val);
	for(u8 i = 0; i < 8; i++){
		DIO_void_assign_port(__port_out_, (val>>i));
		_delay_ms(250);
	}
}

void converge( ){
	for (u8 i = 0; i < 4; i++){
		DIO_void_toggle_pin(__port_out_, i);
		DIO_void_toggle_pin(__port_out_, (7-i));
		_delay_ms(300);
	}
}

void diverge( ){
	DIO_void_set_port(__port_out_);
	for (u8 i = 0; i < 4; i++){
		DIO_void_toggle_pin(__port_out_, i);
		DIO_void_toggle_pin(__port_out_, (7-i));
		_delay_ms(300);
	}
}

void ping_pong( ){
	u8 val= 0b00000001;
	for (u8 i = 0; i < 8; i++){
		DIO_void_assign_port(__port_out_, (val<<i));
		_delay_ms(250);
	}
	for (s8 i = 7; i >= 0; i--){
		DIO_void_assign_port(__port_out_, (val<<i));
		_delay_ms(250);
	}
}

void snake( ){
	for (u8 i = 0; i < 8; i++){
		DIO_void_toggle_pin(__port_out_, i);
		_delay_ms(300);
	}
}

void conv_div( ){
	for (u8 i = 0; i < 4; i++){
		DIO_void_toggle_pin(__port_out_, i);
		DIO_void_toggle_pin(__port_out_, (7-i));
		_delay_ms(300);
	}
	DIO_void_set_port(__port_out_);
	for (u8 i = 0; i < 4; i++){
		DIO_void_toggle_pin(__port_out_, i);
		DIO_void_toggle_pin(__port_out_, (7-i));
		_delay_ms(300);
	}
}
