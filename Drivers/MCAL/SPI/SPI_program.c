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

// Standard libraries section
#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/BIT_MATH.h"

// Private libraries section
#include "SPI_private.h"
#include "SPI_interface.h"

// Drivers section
#include "../DIO/DIO_interface.h"

// Global variables and structs
static void (*ptr_callback_function)(void)= NULL;
static u8 Last_byte;
static u8 Current_channel;
//static u8* SPI_slave_id;

/******************************************************************************/
/* Functions implementation section */
void SPI_void_init_master(void ){
	/*
	 *
	 */
	/* Set pins direction */
	// Set clk Direction
	DIO_void_set_pin_dir(DIO_REF_PORTB, B7, OUTPUT);
	// Set MISO Direction
	DIO_void_set_pin_dir(DIO_REF_PORTB, B6, INPUT);
	// Set MOSI Direction
	DIO_void_set_pin_dir(DIO_REF_PORTB, B5, OUTPUT);
	// Set SS Direction
	for(u8 i= 0; i < SPI_no_SS; i++){
		DIO_void_set_pin_dir(DIO_REF_PORTB, 4-i, OUTPUT);
		DIO_void_set_pin(DIO_REF_PORTB, 4-i);
	}
	// Set control register
	SPI_SPCR = ((SPCR_master_mask) | (SPI_data_order << SPI_DORD) | (SPI_clk_polarity << SPI_CPOL) | (SPI_clk_phase << SPI_CPHA) | (SPI_clk_rate));
	// Set status register
	SPI_SPSR &= SPSR_reset_mask;
	SPI_SPSR |= SPI_clk2X;
	// Global interrupt enable
	ADC_SREG |= (SPI_enable << SPI_global_int);
}



u8 SPI_u8_master_transmit(u8 copy_slave_id, u8 copy_u8_data){
	/*
	 *
	 */
	// Pull down the selected slave
	DIO_void_clear_pin(DIO_REF_PORTB, copy_slave_id);
	// Assign the data to the data register
	SPI_SPDR= copy_u8_data;
	// Save the current channel to pull the slave up when finishing
	Current_channel= copy_slave_id;
	// Return the data if the colission flag is set
	if(get_bit(SPI_SPSR, SPI_WCOL) == 1){
		return copy_u8_data;
	}
	// Return zero if transmition process starts proberly
	return 0;
}

void SPI_void_init_slave(void ){
	/*
	 *
	 */
	/* Set pins direction */
	// Set clk Direction
	DIO_void_set_pin_dir(DIO_REF_PORTB, B7, INPUT);
	// Set MISO Direction
	DIO_void_set_pin_dir(DIO_REF_PORTB, B6, OUTPUT);
	// Set MOSI Direction
	DIO_void_set_pin_dir(DIO_REF_PORTB, B5, INPUT);
	// Set SS pin direction
	DIO_void_set_pin_dir(DIO_REF_PORTB, B4, INPUT);
	// Set control register
	SPI_SPCR = ((SPCR_slave_mask) | (SPI_data_order << SPI_DORD) | (SPI_clk_polarity << SPI_CPOL) | (SPI_clk_phase << SPI_CPHA));
	// Global interrupt enable
	ADC_SREG |= (SPI_enable << SPI_global_int);
}


u8 SPI_u8_slave_update(u8 copy_u8_data){
	/*
	 *
	 */
	u8 copy_recived_data= SPI_SPDR;
	SPI_SPDR = copy_u8_data;
	return copy_recived_data;
}

u8 SPI_u8_recive(void ){
	/*
	 *
	 */
	return Last_byte;
}

void SPI_void_set_callback(void (*copy_ptr_callback)(void)){
	/*
	 *
	 */
	ptr_callback_function = copy_ptr_callback;
}


void __vector_12(void){
	/*
	 *
	 */
	if (get_bit(SPI_SPCR, 4) == SPI_enable){
		DIO_void_set_pin(DIO_REF_PORTB, Current_channel);
		Last_byte= SPI_SPDR;
	}
	else{
		Last_byte= SPI_SPDR;
	}
	if(ptr_callback_function != NULL)
		ptr_callback_function();
}
