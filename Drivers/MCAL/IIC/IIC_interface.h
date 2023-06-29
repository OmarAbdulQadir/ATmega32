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
	
	/* Transmition frequency configuration */
	// Bit rate register value
	#define I2C_TWBR_val		32
	// Prescaler value
	#define I2C_TWPS_val		0
	
	
	
	/* public functions decleration */
	// Initiate the I2C prepheral
	void I2C_master_inti(void );
	// Start communication in master mode
	void I2C_u8_master_start_comm(u8 * );
	

#endif /* end SPI_INTERFACE_H */
