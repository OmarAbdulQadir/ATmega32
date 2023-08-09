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


#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

	/*
	 * Note: Each data byte to be sent its value must be between 0 - 250, And the other values
	 * are reserved for special operations as described below.
	 *
	 * 255: End of frame.
	 * 254:	Repeated start.
	 * 253:
	 * 252:
	 * 251:
	 */

	/* Transmition frequency configuration */
	// Bit rate register value
	#define I2C_TWBR_val		32			// Frequency value f= (Sys_clock)/(16+(2*I2C_TWBR_val*(4^(I2C_TWPS_val))))
	// Prescaler value
	#define I2C_TWPS_val		0			// Prescaler values (0: 1, 1: 4, 2: 16, 3: 64)
	
	
	
	/* public functions decleration */
	// Initiate the I2C prepheral
	void I2C_void_master_init(u8 );
	// Start communication in master mode
	u8 I2C_void_master_start_comm(u8 * );
	// Get the pointer to the buffered data frame
	u8* I2C_u8_ptr_get_buffered_frame(void );
	// Set buffered data frame
	void I2C_u8_void_set_buffered_frame(u8* );

#endif /* end SPI_INTERFACE_H */
