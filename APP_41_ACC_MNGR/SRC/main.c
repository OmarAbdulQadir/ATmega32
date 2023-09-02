/*
 * main.c
 *
 *  Created on: Sep 1, 2023
 *      Author: Omar A.Qadir
 */

#include <util/delay.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../Drivers/MCAL/DIO/DIO_interface.h"
#include "../ACC_MNGR/ACC_interface.h"

int main(void){


	DIO_void_set_port_dir(DIO_REF_PORTA, OUTPUT);
	ACC_init();
	_delay_ms(5);
	DIO_void_assign_port(DIO_REF_PORTA, ACC_WriteChannel(3, ACC_ChannelOn));



	while(1){

		DIO_void_assign_port(DIO_REF_PORTA, ACC_WriteChannel(3, ACC_ChannelOn));
		_delay_ms(250);
		DIO_void_assign_port(DIO_REF_PORTA, ACC_WriteChannel(3, ACC_ChannelOff));
		_delay_ms(250);
	}
	return 0;
}
