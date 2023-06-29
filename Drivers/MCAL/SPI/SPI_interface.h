/*******************************************************************/
/***               Date: 17/6/2023	Day: Saturday	             ***/
/***  	SPI protocol driver for the microcontroller ATMega 32 	 ***/
/***     Created By: Omar Abdul Qadir	 Version= 1.0            ***/
/*******************************************************************/
/***         Note: All the data in the file is readable,         ***/
/***     And any editing will affect the controller's behavior,  ***/
/***          So It's not recommended to edit any data,          ***/
/***   Unless you are sure of what is the effect on behaviors.   ***/
/*******************************************************************/


#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

	/* Configuration bits section */
	// Clock polarity bit
	#define	SPI_clk_polarity		0
	// Clock phase bit
	#define SPI_clk_phase			1
	// Clock rate bits
	#define	SPI_clk_rate			1
	// Double speed enable bit
	#define	SPI_clk2X				0
	// Data order bits
	#define	SPI_data_order			0

	// Slave select pins
	#define SPI_no_SS				3


	/* Function decleration section */
	// Initiate SPI as master
	void SPI_void_init_master(void );
	// Send data to slaves
	u8 SPI_u8_master_transmit(u8 ,u8 );
	// Initiate SPI as slave
	void SPI_void_init_slave(void );
	// Update data to the shift register
	u8 SPI_u8_slave_update(u8 );
	// recive data when transmition compleate
	u8 SPI_u8_recive(void );
	// set callback function to the ISR in both cases Master and slave
	void SPI_void_set_callback(void (*copy_ptr_callback)(void));

#endif /* end SPI_INTERFACE_H */
