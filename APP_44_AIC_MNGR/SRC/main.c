/*
 * main.c
 *
 *  Created on: Sep 6, 2023
 *      Author: Omar A.Qadir
 */

#include "../AIC_MNGR/AIC_interface.h"
#include "../../Drivers/MCAL/DIO/DIO_interface.h"
#include "../../Drivers/HAL/LCD/LCD_interface.h"


#define NULL	(void*)0

void check_respond(u8 copy_respond, u8 copy_cmdNum);

int main(void){

	u8 respond;
	u16 AnalogData;
	DIO_void_set_port_dir(DIO_REF_PORTD, OUTPUT);
	DIO_void_assign_port(DIO_REF_PORTD, 0x00);

	LCD_init();

	AIC_Init();
	respond = AIC_InitChannel(0);
	check_respond(respond, 20);

	respond = AIC_ReadChannel(0, &AnalogData);
	check_respond(respond, 27);

	AnalogData = ((AnalogData*500)/1024);

	LCD_write_s32_number(AnalogData);

	while(1){



	}
	return 0;
}


void check_respond(u8 copy_respond, u8 copy_cmdNum)
{
	while(copy_respond == 0)
		DIO_void_assign_port(DIO_REF_PORTD, copy_cmdNum);
}
