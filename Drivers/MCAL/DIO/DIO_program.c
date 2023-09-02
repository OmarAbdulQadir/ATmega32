/*******************************************************************/
/***               Date: 2/5/2023	Day: Tuesday                 ***/
/***    Digital I/O driver for the microcontroller ATMega 32     ***/
/***     Created By: Omar Abdul Qadir	 Version= 3.0            ***/
/*******************************************************************/
/***         Note: All the data in the file is readable,         ***/
/***     And any editing will affect the controller's behavior,  ***/
/***          So It's not recommended to edit any data,          ***/
/***   Unless you are sure of what is the effect on behaviors.   ***/
/*******************************************************************/

//Private libraries Section
#include "DIO_interface.h"
#include "DIO_register.h"

//Global variables
static volatile u8* DIO_PINx_REF[4] = {DIO_PINA, DIO_PINB, DIO_PINC, DIO_PIND};
static volatile u8* DIO_DDRx_REF[4] = {DIO_DDRA, DIO_DDRB, DIO_DDRC, DIO_DDRD};
static volatile u8* DIO_PORTx_REF[4] = {DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD};


/* Implementing of the driver functions */
/* Set direction of PORTx functions */
void DIO_void_set_port_dir(u8 copy_u8_port_id, u8 port_dir_copy)
{
	/* 
	 *	Function set given port to a given direction
	 *	Inputs::
	 *		copy_u8_port_id>> port indicator as folloing (0, PORTA)
	 *												  	 (1, PORTB)
	 *												  	 (2, PORTC)
	 *												  	 (3, PORTD)
	 *		port_dir_copy>> port direction in Dec, Hex or binary
	 *						Ex: 0b00001111
	 *						0: for input pin
	 *						1: for output pin
	 *	
	 *	Function does not return any output, yet it affects the 
	 *	PORT Direction Register DDRx
	 */
	*(DIO_DDRx_REF[copy_u8_port_id]) = port_dir_copy;
}


void DIO_void_set_port_in_pullUp(u8 copy_u8_port_id)
{
	/*
	 *	Function set given port to be input pull up
	 *	Inputs::
	 *		copy_u8_port_id>> port indicator as folloing (0, PORTA)
	 *												  	 (1, PORTB)
	 *												  	 (2, PORTC)
	 *												  	 (3, PORTD)
	 *	
	 *	Function does not return any output, yet it affects the 
	 *	PORT Direction Register DDRx
	 */
	*(DIO_DDRx_REF[copy_u8_port_id]) = INPUT;
	*(DIO_PORTx_REF[copy_u8_port_id]) = PORT_MAX;
}


u8 DIO_u8_get_PortDir(u8 copy_u8_port_id)
{
	return *(DIO_DDRx_REF[copy_u8_port_id]);
}

/* Set direction of PINx functions */
void DIO_void_set_pin_dir(u8 copy_u8_port_id, u8 copy_u8_pin_num, u8 pin_dir_copy)
{
	/* 
	 * 	Function set given pin to a given direction
	 *	Inputs::
	 *	copy_u8_port_id>> port indicator as folloing (0, PORTA)
	 *											  	 (1, PORTB)
	 *											  	 (2, PORTC)
	 *											  	 (3, PORTD)
	 *	copy_u8_pin_num>> pin number that needed to be set 0-7
	 *	pin_dir_copy>> pin direction set as folloing
	 *				   0: for input pin
	 *				   1: for output pin
	 *
	 * Function does not return any output, yet it affects the 
	 * pin in the PORT Direction Register DDRx
	 */	
	agn_bit(*(DIO_DDRx_REF[copy_u8_port_id]), copy_u8_pin_num, pin_dir_copy);
}


void DIO_void_set_pin_in_pullUP(u8 copy_u8_port_id, u8 copy_u8_pin_num)
{
	/* 
	 *  Function set given pin to be input pull up
	 *	Inputs::
	 *		copy_u8_port_id>> port indicator as folloing (0, PORTA)
	 *												  	 (1, PORTB)
	 *												  	 (2, PORTC)
	 *												  	 (3, PORTD)
	 *	
	 *	Function does not return any output, yet it affects the 
	 *	pin in the PORT Direction Register DDRx					  
	 */
	clr_bit(*(DIO_DDRx_REF[copy_u8_port_id]), copy_u8_pin_num);
	set_bit(*(DIO_PORTx_REF[copy_u8_port_id]), copy_u8_pin_num);
}


u8 DIO_u8_get_PinDir(u8 copy_u8_port_id, u8 copy_u8_pin_num)
{
	return get_bit(*(DIO_DDRx_REF[copy_u8_port_id]), copy_u8_pin_num);
}


/* Assign Value to output PORTx functions */
void DIO_void_set_port(u8 copy_u8_port_id)
{
	/* 
	 *	Function set given port to high
	 *	Inputs::
	 *		copy_u8_port_id>> port indicator as folloing (0, PORTA)
	 *													 (1, PORTB)
	 *													 (2, PORTC)
	 *													 (3, PORTD)
	 *	
	 *	Function does not return any output, yet it affects the 
	 *	PORT output Register PORTx							       
	 */
	*(DIO_PORTx_REF[copy_u8_port_id]) = PORT_MAX;
}


void DIO_void_clear_port(u8 copy_u8_port_id)
{
	/* 
	 *	Function set given port to LOW
	 *	Inputs::
	 *		copy_u8_port_id>> port indicator as folloing (0, PORTA)
	 *													 (1, PORTB)
	 *													 (2, PORTC)
	 *													 (3, PORTD)
	 *	
	 *	Function does not return any output, yet it affects the 
	 *	PORT output Register PORTx							       
	 */
	*(DIO_PORTx_REF[copy_u8_port_id]) = LOW;
}


void DIO_void_toggle_port(u8 copy_u8_port_id)
{
	/*
	 *	Function toggle all pins of given port
	 *	Inputs::
	 *		copy_u8_port_id>> port indicator as folloing (0, PORTA)
	 *													 (1, PORTB)
	 *													 (2, PORTC)
	 *													 (3, PORTD)
	 *	
	 *	Function does not return any output, yet it affects the 
	 *	PORT output Register PORTx							       
	 */
	*(DIO_PORTx_REF[copy_u8_port_id]) ^= PORT_MAX;
}


void DIO_void_assign_port(u8 copy_u8_port_id, u8 port_val)
{
	/*	
	 *	Function assign value to given port
	 *	Inputs::
	 *		copy_u8_port_id>> port indicator as folloing (0, PORTA)
	 *												  	 (1, PORTB)
	 *												  	 (2, PORTC)
	 *												  	 (3, PORTD)
	 *	
	 *	Function does not return any output, yet it affects the 
	 *	PORT output Register PORTx							       
	 */
	*(DIO_PORTx_REF[copy_u8_port_id]) = port_val;
}


u8 DIO_u8_get_PortOut(u8 copy_u8_port_id)
{
	/*
	 *
	 */
	return *(DIO_PORTx_REF[copy_u8_port_id]);
}


/* Assign Value to output PINx functions */
void DIO_void_set_pin(u8 copy_u8_port_id, u8 copy_u8_pin_num)
{
	/* 
	 *	Function set given pin to high
	 *	Inputs::
	 *		copy_u8_port_id>> port indicator as folloing (0, PORTA)
	 *												  	 (1, PORTB)
	 *												  	 (2, PORTC)
	 *												  	 (3, PORTD)
	 *		copy_u8_pin_num>> pin number that needed to be set 0-7
	 *	
	 *	Function does not return any output, yet it affects 
	 *	given pin of the PORT output Register PORTx				   
	 */
	set_bit(*(DIO_PORTx_REF[copy_u8_port_id]), copy_u8_pin_num);
}


void DIO_void_clear_pin(u8 copy_u8_port_id, u8 copy_u8_pin_num)
{
	/* 
	 *	Function set given pin to LOW
	 *	Inputs::
	 *		copy_u8_port_id>> port indicator as folloing (0, PORTA)
	 *												  	 (1, PORTB)
	 *												  	 (2, PORTC)
	 *												  	 (3, PORTD)
	 *		copy_u8_pin_num>> pin number that needed to be set 0-7
	 *	
	 *	Function does not return any output, yet it affects 
	 *	given pin of the PORT output Register PORTx				   
	 */
	clr_bit(*(DIO_PORTx_REF[copy_u8_port_id]), copy_u8_pin_num);
}


void DIO_void_toggle_pin(u8 copy_u8_port_id, u8 copy_u8_pin_num)
{
	/* 
	 *	Function toggle given pin
	 *	Inputs::
	 *		copy_u8_port_id>> port indicator as folloing (0, PORTA)
	 *												  	 (1, PORTB)
	 *												  	 (2, PORTC)
	 *												  	 (3, PORTD)
	 *		copy_u8_pin_num>> pin number that needed to be set 0-7
	 *	
	 *	Function does not return any output, yet it affects 
	 *	given pin of the PORT output Register PORTx				   
	 */
	tgl_bit(*(DIO_PORTx_REF[copy_u8_port_id]), copy_u8_pin_num);
}


void DIO_void_assign_pin(u8 copy_u8_port_id, u8 copy_u8_pin_num, u8 pin_val)
{
	/* 
	 *	Function assign value to given pin
	 *	Inputs::
	 *		copy_u8_port_id>> port indicator as folloing (0, PORTA)
	 *												  	 (1, PORTB)
	 *												  	 (2, PORTC)
	 *												  	 (3, PORTD)
	 *		copy_u8_pin_num>> pin number that needed to be set 0-7
	 *	
	 *	Function does not return any output, yet it affects 
	 *	given pin of the PORT output Register PORTx				   
	 */
	agn_bit(*(DIO_PORTx_REF[copy_u8_port_id]), copy_u8_pin_num, pin_val);
}


u8 DIO_u8_get_PinOut(u8 copy_u8_port_id, u8 copy_u8_pin_num)
{
	/*
	 *
	 */
	return get_bit(*(DIO_PORTx_REF[copy_u8_port_id]), copy_u8_pin_num);
}


/* Get value from input PORTx functions */
u8 DIO_u8_get_port(u8 copy_u8_port_id)
{
	/* 
	 *	Function gets the value of a given port
	 *	Inputs::
	 *		copy_u8_port_id>> port indicator as folloing (0, PORTA)
	 *												  	 (1, PORTB)
	 *												  	 (2, PORTC)
	 *												  	 (3, PORTD)
	 *	
	 *	outputs::
	 *		port_val_copy>> copy of the register PINx value
	 *						size: 1 Byte - u8
	 *	
	 *	Function does not affect any regester it only gets
	 *	from the value in the input regester PINx of the 
	 *	given port                                                 
	 */
	return *(DIO_PINx_REF[copy_u8_port_id]);
}


/* Get value from input PINx functions */
u8 DIO_u8_get_pin(u8 copy_u8_port_id, u8 copy_u8_pin_num)
{
	/* 
	 *	Function gets the value of a given pin
	 *	Inputs::
	 *		copy_u8_port_id>> port indicator as folloing (0, PORTA)
	 *												  (1, PORTB)
	 *												  (2, PORTC)
	 *												  (3, PORTD)
	 *		copy_u8_pin_num>> pin number that needed to be set 0-7
	 *	
	 *	outputs::
	 *		pin_val_copy>> copy of the register PINx value
	 *						size: 1 Byte - u8
	 *						values: 0 for LOW, 1 for HIGH
	 *	
	 *	Function does not affect any regester it only gets the pin
	 *	value from the value in the input regester PINx of the 
	 *	given port                                                 
	 */
	return get_bit(*(DIO_PINx_REF[copy_u8_port_id]), copy_u8_pin_num);
}
