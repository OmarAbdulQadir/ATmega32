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
#include "../DIO/DIO_interface.h"

// Global variables and structs
static u8 I2C_mode;
static u8 I2C_recive_data[8]= { 0 };
static u8 err_handle = I2C_no_err;

static u8* copy_ptr_master_data_frame = NULL;

enum I2C_mode{
	I2C_master_transmit = 0x02,
	I2C_master_recive = 0x04,
	I2C_slave_recive = 0x60,
	I2C_slave_transmit = 0xA8,
	I2C_silent = 0xFF
};

enum I2C_master_status_messages{
	I2C_S_cond_ack = 0x08,
	I2C_RS_cond_ack = 0x10,
	I2C_SLA_W_ack = 0x18,
	I2C_SLA_R_ack = 0x40,
	I2C_DB_n_t_ack = 0x28,
	I2C_DB_n_r_ack = 0x50,
	I2C_SLA_W_nack = 0x20,
	I2C_SLA_R_nack = 0x48,
	I2C_DB_n_t_nack = 0x30,
	I2C_DB_n_r_nack = 0x58,
	I2C_Arb_lost = 0x38
};

/******************************************************************************/
/* Functions implementation section */
void I2C_void_master_inti(u8 I2C_SLA){
	/*
	 *
	 */
	// Set the bit rate regester
	I2C_TWBR = I2C_TWBR_val;
	// set the prescaler register
	I2C_TWSR = I2C_TWPS_val;
	// Set the slave address, and enable general call recognition bit
	I2C_TWAR = ((I2C_SLA << 1) | 1);
	// initiate I2C perepheral and configure the register
	I2C_TWCR = ((I2C_enable << I2C_TWCR_TWEA) | (I2C_disable << I2C_TWCR_TWSTA) | (I2C_disable << I2C_TWCR_TWSTO) | (I2C_enable << I2C_TWCR_TWWC) | (I2C_enable << I2C_TWCR_TWEN) | (I2C_enable << I2C_TWCR_TWIE));
	// Enable global intrrupt
	I2C_SREG |= (I2C_enable << I2C_glob_int);
	// Set mode to scilent
	I2C_mode = I2C_silent;
	DIO_void_set_port_dir(PORTD, OUTPUT);
	DIO_void_set_port_dir(PORTB, OUTPUT);
}


u8 I2C_get_status_word(void ){
	/*
	 *
	 */
	return (I2C_TWSR & I2C_TWS_mask);
}


void I2C_master_transmit_respond(void ){
	/*
	 *
	 */
	static u8 data_frame_index = I2C_S_frame;
	switch(I2C_get_status_word()){
		case (I2C_S_cond_ack):
			// Load SLA+W in the data register
			DIO_void_assign_port(PORTB,  copy_ptr_master_data_frame[data_frame_index]);
			I2C_TWDR = copy_ptr_master_data_frame[data_frame_index];
			// Clear start condition bit
			clr_bit(I2C_TWCR, I2C_TWCR_TWSTA);
			// Increment the frame index pointing to next byte in the frame
			data_frame_index++;
			// Clearing TWI interrupt flage
			set_bit(I2C_TWCR, I2C_TWCR_TWINT);
		break;
		case (I2C_RS_cond_ack):
			// Load SLA+W in the data register
			I2C_TWDR = copy_ptr_master_data_frame[data_frame_index];
			// Clear start condition bit
			clr_bit(I2C_TWCR, I2C_TWCR_TWSTA);
			// Increment the frame index pointing to next byte in the frame
			data_frame_index++;
			// Clearing TWI interrupt flage
			set_bit(I2C_TWCR, I2C_TWCR_TWINT);
		break;
		case (I2C_SLA_W_ack):
			// Load the first data byte
			I2C_TWDR = copy_ptr_master_data_frame[data_frame_index];
			// Increment the frame index pointing to next byte in the frame
			data_frame_index++;
			// Clearing TWI interrupt flage
			set_bit(I2C_TWCR, I2C_TWCR_TWINT);
		break;
		case (I2C_DB_n_t_ack):
			if((copy_ptr_master_data_frame[data_frame_index] == I2C_end_frame) || (data_frame_index > I2C_max_frame)){
				// Send stop condition
				set_bit(I2C_TWCR, I2C_TWCR_TWSTO);
				// Reset I2C mode flag
				I2C_mode = I2C_silent;
				// Reset the frame index
				data_frame_index = I2C_S_frame;
				// Reset the frame pointer
				copy_ptr_master_data_frame = NULL;
				// Clearing TWI interrupt flage
				set_bit(I2C_TWCR, I2C_TWCR_TWINT);
			}
			else if(copy_ptr_master_data_frame[data_frame_index] == I2C_repeated_start){
				// Reset the frame pointer pointing to the new address
				copy_ptr_master_data_frame += ++data_frame_index;
				// Reset the frame index
				data_frame_index = I2C_S_frame;
				// Set I2C mode flag to master mode R/W
				I2C_mode = ((get_bit(copy_ptr_master_data_frame[data_frame_index], 0) == 0) ? 0x02 : 0x04);
				// Send repeated start
				set_bit(I2C_TWCR, I2C_TWCR_TWSTA);
			}
			else if(copy_ptr_master_data_frame[data_frame_index] == I2C_253_None){
			}
			else if(copy_ptr_master_data_frame[data_frame_index] == I2C_252_None){
			}
			else if(copy_ptr_master_data_frame[data_frame_index] == I2C_251_None){
			}
			else{
				// Load the data byte
				I2C_TWDR = copy_ptr_master_data_frame[data_frame_index];
				// Increment the frame index pointing to next byte in the frame
				data_frame_index++;
				// Clearing TWI interrupt flag
				set_bit(I2C_TWCR, I2C_TWCR_TWINT);
			}
		break;
		case (I2C_SLA_W_nack):
			if(err_handle == I2C_no_err){
				// Resend SLA+W
				err_handle = I2C_20_R0;
				// Load SLA+W in the data register
				I2C_TWDR = copy_ptr_master_data_frame[--data_frame_index];
				// Increment the frame index pointing to next byte in the frame
				data_frame_index++;
				// Clearing TWI interrupt flage
				set_bit(I2C_TWCR, I2C_TWCR_TWINT);
			}
			else if(err_handle == I2C_20_R0){
				// Send repeated start
				err_handle = I2C_20_R1;
				// Reset the frame index
				data_frame_index = I2C_S_frame;
				// Send repeated start
				set_bit(I2C_TWCR, I2C_TWCR_TWSTA);
			}
			else if(err_handle == I2C_20_R1){
				// Send stop codondition
				err_handle = I2C_20_R2;
				// Send stop condition
				set_bit(I2C_TWCR, I2C_TWCR_TWSTO);
				// Reset I2C mode flag
				I2C_mode = I2C_silent;
				// Reset the frame index
				data_frame_index = I2C_S_frame;
				// Reset the frame pointer
				copy_ptr_master_data_frame = NULL;
				// Clearing TWI interrupt flage
				set_bit(I2C_TWCR, I2C_TWCR_TWINT);
			}
		break;
		case (I2C_DB_n_t_nack):
			if(err_handle == I2C_no_err){
				// Resend the data byte (n)
				err_handle = I2C_30_R0;
				// Load the data byte
				I2C_TWDR = copy_ptr_master_data_frame[--data_frame_index];
				// Increment the frame index pointing to next byte in the frame
				data_frame_index++;
				// Clearing TWI interrupt flage
				set_bit(I2C_TWCR, I2C_TWCR_TWINT);
			}
			else if(err_handle == I2C_30_R0){
				// Send repeated start
				err_handle = I2C_30_R1;
				// Reset the frame index
				data_frame_index = I2C_S_frame;
				// Send repeated start
				set_bit(I2C_TWCR, I2C_TWCR_TWSTA);
			}
			else if(err_handle == I2C_30_R1){
				// Send stop condition
				err_handle = I2C_30_R2;
				// Send stop condition
				set_bit(I2C_TWCR, I2C_TWCR_TWSTO);
				// Reset I2C mode flag
				I2C_mode = I2C_silent;
				// Reset the frame index
				data_frame_index = I2C_S_frame;
				// Reset the frame pointer
				copy_ptr_master_data_frame = NULL;
				// Clearing TWI interrupt flag
				set_bit(I2C_TWCR, I2C_TWCR_TWINT);
			}
		break;
		case I2C_Arb_lost:
			// Reset I2C mode flag
			I2C_mode = I2C_silent;
			// Reset the frame index
			data_frame_index = I2C_S_frame;
			// Wait until bus is empty then resend start condition
			I2C_void_master_start_comm(copy_ptr_master_data_frame);
		break;
		default:

		break;
	}
}


void I2C_master_recive_respond(void ){
	/*
	 *
	 */
	static u8 data_frame_index = I2C_S_frame;
	static u8 recived_data_index = 0;
	DIO_void_assign_port(PORTD,  I2C_get_status_word());
	switch (I2C_get_status_word()){
		case (I2C_S_cond_ack):
			// Load SLA+W in the data register
			DIO_void_assign_port(PORTB,  copy_ptr_master_data_frame[data_frame_index]);
			I2C_TWDR = copy_ptr_master_data_frame[data_frame_index];
			// Clear start condition bit
			clr_bit(I2C_TWCR, I2C_TWCR_TWSTA);
			// Increment the frame index pointing to next byte in the frame
			data_frame_index++;
			// Clearing TWI interrupt flage
			set_bit(I2C_TWCR, I2C_TWCR_TWINT);
		break;
		case (I2C_RS_cond_ack):
			// Load SLA+W in the data register
			DIO_void_assign_port(PORTB,  copy_ptr_master_data_frame[data_frame_index]);
			I2C_TWDR = copy_ptr_master_data_frame[data_frame_index];
			// Clear start condition bit
			clr_bit(I2C_TWCR, I2C_TWCR_TWSTA);
			// Increment the frame index pointing to next byte in the frame
			data_frame_index++;
			// Clearing TWI interrupt flage
			set_bit(I2C_TWCR, I2C_TWCR_TWINT);
		break;
		case (I2C_SLA_R_ack):
			// Save data size
			if (copy_ptr_master_data_frame[data_frame_index] > 8)
				copy_ptr_master_data_frame[data_frame_index] = 8;
			recived_data_index = (copy_ptr_master_data_frame[data_frame_index]-1);
			// Recive first data byte
			I2C_recive_data[0] = I2C_TWDR;
			// Clearing TWI interrupt flage
			set_bit(I2C_TWCR, I2C_TWCR_TWINT);
		break;
		case (I2C_DB_n_r_ack):
			if (recived_data_index > 0){
				// calculate the current data index
				u8 current_data_index = copy_ptr_master_data_frame[data_frame_index] - (recived_data_index--);
				// Recive current data byte
				I2C_recive_data[current_data_index] = I2C_TWDR;
				// Clearing TWI interrupt flage
				set_bit(I2C_TWCR, I2C_TWCR_TWINT);
			}
			else if(copy_ptr_master_data_frame[++data_frame_index] == I2C_end_frame){
				// Send stop condition
				set_bit(I2C_TWCR, I2C_TWCR_TWSTO);
				// Reset I2C mode flag
				I2C_mode = I2C_silent;
				// Reset the frame index
				data_frame_index = I2C_S_frame;
				// Reset the frame pointer
				copy_ptr_master_data_frame = NULL;
				// Clearing TWI interrupt flage
				set_bit(I2C_TWCR, I2C_TWCR_TWINT);
			}
			else if(copy_ptr_master_data_frame[data_frame_index] == I2C_repeated_start){
				// Reset the frame pointer pointing to the new address
				copy_ptr_master_data_frame += ++data_frame_index;
				// Reset the frame index
				data_frame_index = I2C_S_frame;
				// Set I2C mode flag to master mode R/W
				I2C_mode = ((get_bit(copy_ptr_master_data_frame[data_frame_index], 0) == 0) ? 0x02 : 0x04);
				// Send repeated start
				set_bit(I2C_TWCR, I2C_TWCR_TWSTA);
			}
			else if(copy_ptr_master_data_frame[data_frame_index] == I2C_253_None){

			}
			else if(copy_ptr_master_data_frame[data_frame_index] == I2C_252_None){

			}
			else if(copy_ptr_master_data_frame[data_frame_index] == I2C_251_None){

			}
		break;
		case (I2C_SLA_R_nack):

		break;
		case (I2C_DB_n_r_nack):

		break;
		case (I2C_Arb_lost):

		break;
		default:

		break;
	}
}


void I2C_void_master_start_comm(u8* copy_ptr_data_frame ){
	/*
	 *
	 */
	// Check data frame validity and mode flag
	if((copy_ptr_data_frame[0] != I2C_end_frame) && (I2C_mode == I2C_silent)){
		// Set I2C mode flag to master mode R/W
		I2C_mode = ((get_bit(copy_ptr_data_frame[0], 0) == 0) ? 0x02 : 0x04);
		// Store the data frame pointer
		copy_ptr_master_data_frame = copy_ptr_data_frame;
		// Send start cond
		set_bit(I2C_TWCR, I2C_TWCR_TWSTA);
	}
	else{

	}
}


void I2C_slave_transmit_respond(void ){
	/*
	 *
	 */

}


void I2C_slave_recive_respond(void ){
	/*
	 *
	 */

}


void __vector_19(void ){
	/*
	 *
	 */
	if (I2C_mode == I2C_silent){
		I2C_mode = (I2C_TWSR & I2C_TWS_mask);
	}
	switch(I2C_mode){
		case I2C_master_transmit:
			I2C_master_transmit_respond();
			break;
		case I2C_master_recive:
			I2C_master_recive_respond();
			break;
		case I2C_slave_transmit:
			I2C_slave_transmit_respond();
			break;
		case I2C_slave_recive:
			I2C_slave_recive_respond();
			break;
	}
}
