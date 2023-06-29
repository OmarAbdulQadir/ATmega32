/*******************************************************************/
/***               Date: 23/6/2023	Day: Friday		             ***/
/***  	IIC protocol driver for the microcontroller ATMega 32 	 ***/
/***     Created By: Omar Abdul Qadir	 Version= 1.0            ***/
/*******************************************************************/
/***         Note: All the data in the file is readable,         ***/
/***     And any editing will affect the controller's behavior,  ***/
/***          So It's not recommended to edit any data,          ***/
/***   Unless you are sure of what is the effect on behaviors.   ***/
/*******************************************************************/

// Standard libraries section
#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/BIT_MATH.h"

// Private libraries section
#include "IIC_private.h"
#include "IIC_interface.h"

// Drivers section


// Global variables and structs


/******************************************************************************/
/* Functions implementation section */
void I2C_void_master_inti(void ){
	/*
	 *
	 */
	// Set the bit rate regester
	I2C_TWBR = I2C_TWBR_val;
	// set the prescaler register
	I2C_TWSR = I2C_TWPS_val;
	// initiate I2C perepheral and configure the register
	I2C_TWCR = ((I2C_enable << I2C_TWCR_TWINT) | (I2C_enable << I2C_TWCR_TWEA) | (I2C_disable << I2C_TWCR_TWSTA) | (I2C_disable << I2C_TWCR_TWSTO) | (I2C_enable << I2C_TWCR_TWWC) | (I2C_enable << I2C_TWCR_TWEN) | (I2C_enable << I2C_TWCR_TWIE));
}


void I2C_u8_master_sent_byte(u8 copy_data_byte){
	/*
	 *
	 */
	
}


void I2C_u8_master_start_comm(u8* copy_ptr_data_frame){
	/*
	 *
	 */

}

void __vector_19(void){
	/*
	 *
	 */

}
