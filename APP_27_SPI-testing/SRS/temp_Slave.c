/*
 * temp_Slave.c
 *
 *  Created on: Jun 22, 2023
 *      Author: Omar A.Qadir
 */


// Libraries section
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

// Private libraries section
#include "../INC/temp_Slave.h"

// Drivers Section
#include "../../Drivers/MCAL/SPI/SPI_interface.h"

// Global variables
extern f32 real_temprature;


void update_temprature_value(void ){
	// transmission status for full data send
	static u8 transmission_status= temp_dec_byte;
	// if status is equal to 0, send the dec temp value
	switch(transmission_status){
	case temp_dec_byte:
		// update with the dec value on the first byte
		SPI_u8_slave_update((u8)real_temprature);
		// Increment the counter to send the next byte
		transmission_status++;
		break;
	// if status is equal to 1, send the floating value
	case temp_float_byte:
		// update with the float value on the second byte
		SPI_u8_slave_update((u8)((real_temprature - ((u8)real_temprature))*100));
		// Increment the counter for clearence on the next interrupt
		transmission_status++;
		break;
	default:
		// update the data regester with ready value
		SPI_u8_slave_update(0xFF);
		// Clear the counter after sending the full data word
		transmission_status= temp_dec_byte;
		break;
	}
}
