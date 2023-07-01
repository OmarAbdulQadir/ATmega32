/*
 * main.c
 *
 *  Created on: Jun 23, 2023
 *      Author: Omar A.Qadir
 */


// Libraries section
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

// Driver section
#include "../../Drivers/MCAL/DIO/DIO_interface.h"
#include "../../Drivers/MCAL/IIC/IIC_interface.h"

// Private section


// Macros section


// Global variables section


// Main app
int main(void ){
	// Setup section

	u8 I2C_test_frame[]= {0xA0, 0x64, 254, 0xA1, 4, 254, 0xA0, 0x64, 0x10, 0x15, 0x20, 0x25, 255};
	/*
	 * Testing frame with EEPROM
	 * 0xA0: SLA+W
	 * 0x64: data position in the section
	 * 254 : Sr code
	 * 0xA1: SLA+R
	 * 4   : Number of bytes to read
	 * 254 : Sr code
	 * 0xA0: SLA+W
	 * 0x64: data position in the section
	 * 0x10, 0x15, 0x20, 0x25: The data itself
	 * 255 : end frame code
	 */
	I2C_void_master_inti(75);
	I2C_void_master_start_comm(I2C_test_frame);

	while(1){
		// Loop section

	}
}
