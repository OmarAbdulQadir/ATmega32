/*
 * main.c
 *
 *  Created on: Sep 2, 2023
 *      Author: Omar A.Qadir
 */


#include <util/delay.h>
#include "../../Drivers/MCAL/DIO/DIO_interface.h"
#include "../DIOC_MNGR/DIOC_interface.h"

int main(void)
{

	DIO_void_set_port_dir(DIO_REF_PORTA, OUTPUT);
	DIO_void_set_port_dir(DIO_REF_PORTC, OUTPUT);

	DIOC_init();

	DIO_void_assign_port(DIO_REF_PORTA, DIOC_WriteChannel(0, HIGH));
	_delay_ms(250);
	DIO_void_assign_port(DIO_REF_PORTA, DIOC_WriteChannel(0, LOW));
	_delay_ms(250);

	DIO_void_assign_port(DIO_REF_PORTA, DIOC_WriteChannel(1, HIGH));
	_delay_ms(250);
	DIO_void_assign_port(DIO_REF_PORTA, DIOC_WriteChannel(1, LOW));
	_delay_ms(250);

	DIO_void_assign_port(DIO_REF_PORTA, DIOC_WriteChannel(2, HIGH));
	_delay_ms(250);
	DIO_void_assign_port(DIO_REF_PORTA, DIOC_WriteChannel(2, LOW));
	_delay_ms(250);

	u8 ChannelValue=0;
	DIO_void_assign_port(DIO_REF_PORTA, DIOC_SetChannelDir(2, INPUT));
	_delay_ms(100);
	DIO_void_assign_port(DIO_REF_PORTA, DIOC_SetChannelDir(1, INPUT));
	_delay_ms(100);
	DIO_void_assign_port(DIO_REF_PORTA, DIOC_SetChannelDir(0, INPUT));
	_delay_ms(100);


	DIO_void_assign_port(DIO_REF_PORTA, DIOC_ReadChannel(2, &ChannelValue));
	DIO_void_assign_port(DIO_REF_PORTC, ChannelValue);
	_delay_ms(250);

	DIO_void_assign_port(DIO_REF_PORTA, DIOC_ReadChannel(1, &ChannelValue));
	DIO_void_assign_port(DIO_REF_PORTC, ChannelValue);
	_delay_ms(250);
	DIO_void_assign_port(DIO_REF_PORTA, DIOC_ReadChannel(1, &ChannelValue));
	DIO_void_assign_port(DIO_REF_PORTC, ChannelValue);
	_delay_ms(250);

	DIO_void_assign_port(DIO_REF_PORTA, DIOC_ReadChannel(0, &ChannelValue));
	DIO_void_assign_port(DIO_REF_PORTC, ChannelValue);
	_delay_ms(250);
	DIO_void_assign_port(DIO_REF_PORTA, DIOC_ReadChannel(0, &ChannelValue));
	DIO_void_assign_port(DIO_REF_PORTC, ChannelValue);
	_delay_ms(250);

	while(1)
	{

	}
	return 0;
}
