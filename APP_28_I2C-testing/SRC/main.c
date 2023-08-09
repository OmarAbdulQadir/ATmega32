/*
 * main.c
 *
 *  Created on: Jun 23, 2023
 *      Author: Omar A.Qadir
 */


// Libraries section
#include <util/delay.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

// Driver section
#include "../../Drivers/MCAL/IIC/IIC_interface.h"
#include "../../Drivers/HAL/LCD/LCD_interface.h"

// Private section


// Macros section


// Functions decleration

// Global variables section


// Main app
int main(void ){
	// Setup section

	u8 I2C_test_frame[]= {0xA0, 0x00, 254, 0xA1, 5, 254, 0xA0, 0x00, 0x21, 0x22, 0x23, 0x24, 255};
	/*
	 * Testing frame with EEPROM
	 * 0xA0: SLA+W
	 * 0x00: data position in the section
	 * 254 : Sr code
	 * 0xA1: SLA+R
	 * 4   : Number of bytes to read
	 * 254 : Sr code
	 * 0xA0: SLA+W
	 * 0x00: data position in the section
	 * 0x10, 0x15, 0x20, 0x25: The data itself
	 * 255 : end frame code
	 */
	I2C_void_master_init(75);
	I2C_void_master_start_comm(I2C_test_frame);

	LCD_init();
	LCD_write_str((u8*)"Starting...");

	LCD_clear();
	u8* rec_frame = I2C_u8_ptr_get_buffered_frame();
	for(u8 i= 0; i < 8; i++){
		LCD_set_cursor((i/4), ((i%4)*4));
		LCD_write_s32_number(rec_frame[i]);
	}

	while(1){
		// Loop section

	}
}
