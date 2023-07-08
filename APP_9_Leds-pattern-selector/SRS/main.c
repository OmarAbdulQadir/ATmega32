/*
 * main.c
 *
 *  Created on: May 6, 2023
 *      Author: Omar A.Qadir
 */

//Standard libraries Section
//#include <avr/io.h>
#include <util/delay.h>
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

//MCAL layer Section
//#include "../MCAL/<driverName>/interface.h"
#include "../../Drivers/MCAL/DIO/DIO_interface.h"

//HAL layer Section
//#include "../HAL/<driverName>/interface.h"

//Private libraries Section
//#include "../INC/<fileName>.h"
#include "../INC/patterns.h"


//Global valriables, struct and enums



enum pattern{
	flasing_500_ms,
	lshift_250_ms,
	rshift_250_ms,
	converge_300_ms,
	diverge_300_ms,
	ping_pong_250_ms,
	snake_300_ms,
	conv_div_300_ms
};

int main(void){

	DIO_void_set_port_dir(DIO_REF_PORTA, PORT_MAX);
	DIO_void_set_port_dir(DIO_REF_PORTC, INPUT);
	DIO_void_clear_port(DIO_REF_PORTA);

	while(1){
		switch (DIO_u8_get_port(DIO_REF_PORTC)){
				case flasing_500_ms: flashing_led(); break;
				case lshift_250_ms: lshift(); break;
				case rshift_250_ms: rshift(); break;
				case converge_300_ms: converge(); break;
				case diverge_300_ms: diverge(); break;
				case ping_pong_250_ms: ping_pong(); break;
				case snake_300_ms: snake(); break;
				case conv_div_300_ms:conv_div(); break;
		}
		DIO_void_clear_port(DIO_REF_PORTA);
	}
	return 0;
}
