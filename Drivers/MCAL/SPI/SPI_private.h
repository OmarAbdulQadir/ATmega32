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


#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

	/* Private macros section */
	// Null pointer
	#define NULL				(void* ) 0
	// Control regester master mask
	#define SPCR_master_mask	0b11010000
	// Control regester slave mask
	#define SPCR_slave_mask		0b11000000
	// Status register reset mask
	#define SPSR_reset_mask		0b11111110
	// Enable
	#define SPI_enable			1

	/* Configuration bits */
	// Data Order bit
	#define SPI_DORD			5
	// Clock polarity bit
	#define SPI_CPOL			3
	// Clock phase bit
	#define SPI_CPHA			2
	// Double speed enable bit
	#define SPI_SPI2X			0
	// Write colision flag bit
	#define SPI_WCOL			6
	// Global interrupt bit
	#define SPI_global_int		7

	/* SPI Regesters section */
	// SPI control register
	#define SPI_SPCR			(*(volatile u8*) 0x2D)
	// SPI Status register
	#define SPI_SPSR			(*(volatile u8*) 0x2E)
	// SPI Data regester
	#define SPI_SPDR			(*(volatile u8*) 0x2F)
	// Status register
	#define ADC_SREG			*((volatile u8 *) 0x5F)

	/* ISR decleration */
	// Transmition complete ISR
	void __vector_12(void)__attribute__((signal));

#endif /* end SPI_PRIVATE_H */
