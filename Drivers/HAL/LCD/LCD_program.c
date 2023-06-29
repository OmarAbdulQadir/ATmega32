/*******************************************************************/
/***               Date: 12/5/2023	Day: Friday		             ***/
/***  	LCD control driver for the microcontroller ATMega 32 	 ***/
/***     Created By: Omar Abdul Qadir	 Version= 1.0            ***/
/*******************************************************************/
/***         Note: All the data in the file is readable,         ***/
/***     And any editing will affect the controller's behavior,  ***/
/***          So It's not recommended to edit any data,          ***/
/***   Unless you are sure of what is the effect on behaviors.   ***/
/*******************************************************************/

// Standard libraries Section
#include <util/delay.h>
#include "../../../LIB/BIT_MATH.h"
#include "../../../LIB/STD_TYPES.h"

// Private libraries Section
#include "LCD_config.h"
#include "LCD_private.h"
#include "LCD_interface.h"

// Drivers section
#include "../../MCAL/DIO/DIO_interface.h"

/******************************************************************************/

/* LCD helper functions implementation */
s32 LCD_pow(u8 val, u8 power){
	/*
	 *	Function gets the mathematical exponential
	 *	Inputs::
	 *		val>> the base variable
	 *		power>> the exponential power variable
	 *
	 *	Return::
	 *		power_res>> the result of the exponential function
	 *	Function is helper and not allowed to be used out side of the driver.
	 */
	// Create a container for the power result and set its inital value
	s32 power_res= val;
	// Loop in the power order
	for(u8 i= 0; i< power-1; i++)
		// Remultibly the value by itself
		power_res*= val;
	// Return the result in the container
	return power_res;
}

/******************************************************************************/

/* LCD 8bit interfacing functions implementation */
void LCD_write_data_8bit(u8 lcd_copy_word_8bit){
	/*
	 *	Function to sent data byte to the LCD
	 *	Inputs::
	 *		lcd_copy_word_8bit>> The data byte that needs to be sent to the LCD
	 *
	 *	Function does not return any  valus and it is helper and not allowed to be used out side of the driver.
	 */
	// Configure RS/RW pins to recive data
	DIO_void_set_pin(lcd_ctrl_port, lcd_RS);
	DIO_void_clear_pin(lcd_ctrl_port, lcd_RW);
	_delay_us(1);
	// Enable pin is high to send the packet
	DIO_void_set_pin(lcd_ctrl_port, lcd_EN);
	_delay_us(1);
	// Sent the data packet
	DIO_void_assign_port(lcd_data_port, lcd_copy_word_8bit);
	// Enable pin low
	DIO_void_clear_pin(lcd_ctrl_port, lcd_EN);
}

void LCD_write_cmd_8bit(u8 lcd_copy_cmd_8bit){
	/*
	 *	Function to sent comand byte to the LCD
	 *	Inputs::
	 *		lcd_copy_cmd_8bit>> The comand byte that needs to be sent to the LCD
	 *
	 *	Function does not return any  valus and it is helper and not allowed to be used out side of the driver.
	 */
	// Configure RS/RW pins to recive command
	DIO_void_clear_pin(lcd_ctrl_port, lcd_RS);
	DIO_void_clear_pin(lcd_ctrl_port, lcd_RW);
	_delay_us(1);
	// Enable pin is high to send the packet
	DIO_void_set_pin(lcd_ctrl_port, lcd_EN);
	_delay_us(1);
	// Sent the command packet
	DIO_void_assign_port(lcd_data_port, lcd_copy_cmd_8bit);
	// Enable pin low
	DIO_void_clear_pin(lcd_ctrl_port, lcd_EN);
}

u8 LCD_read_address_8bit(void ){
	/*
	 *	Function to read the current address in the address counter of the display.
	 *	No inputs to the function
	 *
	 *	Function return the current address.
	 */
	// Configure the data port to input
	DIO_void_set_port_dir(lcd_data_port, INPUT);
	_delay_ms(50);
	// Configure RS/RW pins to send address
	DIO_void_clear_pin(lcd_ctrl_port, lcd_RS);
	DIO_void_set_pin(lcd_ctrl_port, lcd_RW);
	_delay_us(1);
	// Enable pin is high to recive the packet
	DIO_void_set_pin(lcd_ctrl_port, lcd_EN);
	_delay_us(1);
	// Recive the packet
	u8 address= DIO_u8_get_port(lcd_data_port);
	// Enable pin low
	DIO_void_clear_pin(lcd_ctrl_port, lcd_EN);
	// clear the busy flag bit
	clr_bit(address, lcd_busy_flag);
	// Configure the data port back to output
	DIO_void_set_port_dir(lcd_data_port, OUTPUT);
	return address;
}

/******************************************************************************/

/* LCD 8bit interfacing functions implementation */
void LCD_write_data_4bit(u8 lcd_copy_word_4bit){
	/*
	 *	Function to sent data byte to the LCD
	 *	Inputs::
	 *		lcd_copy_word_4bit>> The data byte that needs to be sent to the LCD
	 *
	 *	Function does not return any  valus and it is helper and not allowed to be used out side of the driver.
	 */
	// Configure RS/RW pins to recive command
	DIO_void_set_pin(lcd_ctrl_port, lcd_RS);
	DIO_void_clear_pin(lcd_ctrl_port, lcd_RW);
	_delay_us(1);
	// Enable pin is high to send the higher nipple
	DIO_void_set_pin(lcd_ctrl_port, lcd_EN);
	_delay_us(1);
	// Sent the higher nipple
	for(u8 i= 4; i< 8; i++)
			DIO_void_assign_pin(lcd_data_port, i, get_bit(lcd_copy_word_4bit, i));
	// Enable pin low
	DIO_void_clear_pin(lcd_ctrl_port, lcd_EN);
	_delay_us(10);
	// Enable pin is high to send the Lower nipple
	DIO_void_set_pin(lcd_ctrl_port, lcd_EN);
	_delay_us(1);
	// Sent the Lower nipple
	for(u8 i= 4; i< 8; i++)
		DIO_void_assign_pin(lcd_data_port, i, get_bit(lcd_copy_word_4bit, i-4));
	// Enable pin low
	DIO_void_clear_pin(lcd_ctrl_port, lcd_EN);
}

void LCD_write_cmd_4bit(u8 lcd_copy_cmd_4bit){
	/*
	 *	Function to sent comand byte to the LCD
	 *	Inputs::
	 *		lcd_copy_cmd_4bit>> The comand byte that needs to be sent to the LCD
	 *
	 *	Function does not return any  valus and it is helper and not allowed to be used out side of the driver.
	 */
	// Configure RS/RW pins to recive command
	DIO_void_clear_pin(lcd_ctrl_port, lcd_RS);
	DIO_void_clear_pin(lcd_ctrl_port, lcd_RW);
	_delay_us(1);
	// Enable pin is high to send the higher nipple
	DIO_void_set_pin(lcd_ctrl_port, lcd_EN);
	_delay_us(1);
	// Sent the higher nipple
	for(u8 i= 4; i< 8; i++)
		DIO_void_assign_pin(lcd_data_port, i, get_bit(lcd_copy_cmd_4bit, i));
	// Enable pin low
	DIO_void_clear_pin(lcd_ctrl_port, lcd_EN);
	_delay_us(10);
	// Enable pin is high to send the Lower nipple
	DIO_void_set_pin(lcd_ctrl_port, lcd_EN);
	_delay_us(1);
	// Sent the Lower nipple
	for(u8 i= 4; i< 8; i++)
		DIO_void_assign_pin(lcd_data_port, i, get_bit(lcd_copy_cmd_4bit, i-4));
	// Enable pin low
	DIO_void_clear_pin(lcd_ctrl_port, lcd_EN);
}

void LCD_function_set_4bit(void ){
	/*
	 *	Function to initiat the LCD with 4bits communication
	 *	No inputs for the function.
	 *
	 *	No return from the function.
	 */
	// Configure RS/RW pins to recive command
	DIO_void_clear_pin(lcd_ctrl_port, lcd_RS);
	DIO_void_clear_pin(lcd_ctrl_port, lcd_RW);
	_delay_us(1);
	// Enable pin is high to send the packet
	DIO_void_set_pin(lcd_ctrl_port, lcd_EN);
	_delay_us(1);
	// Sent the higher nipple
	for(u8 i= 0; i< 4; i++)
		DIO_void_assign_pin(lcd_data_port, i+4, get_bit(0b0010, i));
	// Enable pin Low
	DIO_void_clear_pin(lcd_ctrl_port, lcd_EN);
	_delay_us(10);
	// Enable pin is high to send the packet
	DIO_void_set_pin(lcd_ctrl_port, lcd_EN);
	_delay_us(1);
	// Sent the higher nipple again
	for(u8 i= 0; i< 4; i++)
		DIO_void_assign_pin(lcd_data_port, i+4, get_bit(0b0010, i));
	// Enable pin low
	DIO_void_clear_pin(lcd_ctrl_port, lcd_EN);
	_delay_us(10);
	// Enable pin is high to send the packet
	DIO_void_set_pin(lcd_ctrl_port, lcd_EN);
	_delay_us(1);
	// Sent the lower nipple
	for(u8 i= 0; i< 4; i++)
		DIO_void_assign_pin(lcd_data_port, i+4, get_bit(0b1000, i));
	// Enable pin low
	DIO_void_clear_pin(lcd_ctrl_port, lcd_EN);
	_delay_us(10);
}

u8 LCD_read_data_4bit(void){
	/*
	 *	Function to read the current address in the address counter of the display.
	 *	No inputs to the function
	 *
	 *	Function return the current address.
	 */
	// Configure the data pins to input
	DIO_void_set_pin_dir(lcd_data_port, B7, INPUT);
	DIO_void_set_pin_dir(lcd_data_port, B6, INPUT);
	DIO_void_set_pin_dir(lcd_data_port, B5, INPUT);
	DIO_void_set_pin_dir(lcd_data_port, B4, INPUT);
	// Configure RS/RW pins to send address
	DIO_void_clear_pin(lcd_ctrl_port, lcd_RS);
	DIO_void_set_pin(lcd_ctrl_port, lcd_RW);
	_delay_us(1);
	// Enable pin is high to recive the higher nipple
	DIO_void_set_pin(lcd_ctrl_port, lcd_EN);
	_delay_us(1);
	// Recive the higher nipple
	u8 address= (DIO_u8_get_port(lcd_data_port) << 4);
	// Enable pin is low
	DIO_void_clear_pin(lcd_ctrl_port, lcd_EN);
	_delay_us(10);
	// Enable pin is high to recive the lower nipple
	DIO_void_set_pin(lcd_ctrl_port, lcd_EN);
	_delay_us(1);
	// Recive the lower nipple
	address|= DIO_u8_get_port(lcd_data_port);
	// Enable pin is low
	DIO_void_clear_pin(lcd_ctrl_port, lcd_EN);
	// clear the busy flag bit
	clr_bit(address, lcd_busy_flag);
	// Configure the data pins back to output
	DIO_void_set_pin_dir(lcd_data_port, B7, OUTPUT);
	DIO_void_set_pin_dir(lcd_data_port, B6, OUTPUT);
	DIO_void_set_pin_dir(lcd_data_port, B5, OUTPUT);
	DIO_void_set_pin_dir(lcd_data_port, B4, OUTPUT);
	// Return the current address
	return address;
}


/******************************************************************************/

/* User interfacing functions implementation */
void LCD_init(void){
	/*
	 *	Function to initiate the LCD with the pre-set configurations
	 *	No inputs to the function.
	 *
	 *	No return from the function.
	 */
#if _LCD_interface_ == _8bit_interface
	// Configure the I/O Data port
	DIO_void_set_port_dir(lcd_data_port, OUTPUT);
	// Configure the I/O control pins
	DIO_void_set_pin_dir(lcd_ctrl_port, lcd_EN, OUTPUT);
	DIO_void_set_pin_dir(lcd_ctrl_port, lcd_RW, OUTPUT);
	DIO_void_set_pin_dir(lcd_ctrl_port, lcd_RS, OUTPUT);

	// Wait more than 30 ms
	_delay_ms(50);
	// Send the function set command
	LCD_write_cmd_8bit(function_set_8bit);
	// Wait more than 39 us
	_delay_us(50);
	// Send the display on command
	LCD_write_cmd_8bit(display_on);
	// Wait more than 39 us
	_delay_us(50);
	// Send the display clean command
	LCD_write_cmd_8bit(display_clear);
	// Wait more than 1.53 ms
	_delay_ms(2);
#elif _LCD_interface_ == _4bit_interface
	// Configure the I/O Data pins
	DIO_void_set_pin_dir(lcd_data_port, B7, OUTPUT);
	DIO_void_set_pin_dir(lcd_data_port, B6, OUTPUT);
	DIO_void_set_pin_dir(lcd_data_port, B5, OUTPUT);
	DIO_void_set_pin_dir(lcd_data_port, B4, OUTPUT);
	// Configure the I/O control pins
	DIO_void_set_pin_dir(lcd_ctrl_port, lcd_EN, OUTPUT);
	DIO_void_set_pin_dir(lcd_ctrl_port, lcd_RW, OUTPUT);
	DIO_void_set_pin_dir(lcd_ctrl_port, lcd_RS, OUTPUT);

	// Wait more than 30 ms
	_delay_ms(50);
	// Send the function set command
	LCD_function_set_4bit();
	// Wait more than 39 us
	_delay_us(50);
	// Send the display on command
	LCD_write_cmd_4bit(display_on);
	// Wait more than 39 us
	_delay_us(50);
	// Send the display clean command
	LCD_write_cmd_4bit(display_clear);
	// Wait more than 1.53 ms
	_delay_ms(2);
#endif
}

void LCD_set_cursor(u8 copy_u8_row, u8 copy_u8_column){
	/*
	 *	Function to set the cursor to certain location on the display
	 *	Inputs::
	 *		copy_u8_row>> The required row to move to.
	 *		copy_u8_column>> The required column to move to.
	 *	
	 *	Function does not return any values.
	 */
#if _LCD_interface_ == _8bit_interface
	// calculate the addres from the given rows and columns
	u8 address= 128+(copy_u8_row*line2)+(copy_u8_column);
	// Sent set address command
	LCD_write_cmd_8bit(address);
	// wait more than 39 us
	_delay_us(50);
#elif _LCD_interface_ == _4bit_interface
	// calculate the addres from the given rows and columns
	u8 address= 128+(copy_u8_row*line2)+(copy_u8_column);
	// Sent set address command
	LCD_write_cmd_4bit(address);
	// wait more than 39 us
	_delay_us(50);
#endif
}

void LCD_clear(void){
	/*
	 *	Function to clear the LCD display and return to location R= 0, C= 0.
	 *	No inputs to the function.
	 *	
	 *	Function does not return any values.
	 */
#if _LCD_interface_ == _8bit_interface
	// Send Display clear command
	LCD_write_cmd_8bit(display_clear);
	// Wait more than 1.53 ms
	_delay_ms(2);
	// Send set address command with home address
	LCD_write_cmd_8bit(return_home);
	// wait more than 39 us
	_delay_ms(2);
#elif _LCD_interface_ == _4bit_interface
	// Send Display clear command
	LCD_write_cmd_4bit(display_clear);
	// Wait more than 1.53 ms
	_delay_ms(2);
	// Send set address command with home address
	LCD_write_cmd_4bit(return_home);
	// wait more than 39 us
	_delay_ms(2);
#endif
}

void LCD_off(void ){
	/*
	 *	Function to turn off the back light of the LCD.
	 *	No inputs to the function.
	 *	
	 *	Function does not return any values.
	 */
#if _LCD_interface_ == _8bit_interface
	// Send display off command
	LCD_write_cmd_8bit(display_off);
	// Wait more than 39 us
	_delay_ms(50);
#elif _LCD_interface_ == _4bit_interface
	// Send display off command
	LCD_write_cmd_4bit(display_off);
	// Wait more than 39 us
	_delay_ms(50);
#endif
}

void LCD_on(void ){
	/*
	 *	Function to turn on the back light of the LCD.
	 *	No inputs to the function.
	 *	
	 *	Function does not return any values.
	 */
#if _LCD_interface_ == _8bit_interface
	// Send display on command
	LCD_write_cmd_8bit(display_on);
	// Wait more than 39 us
	_delay_us(50);
#elif _LCD_interface_ == _4bit_interface
	// Send display off command
	LCD_write_cmd_4bit(display_on);
	// Wait more than 39 us
	_delay_us(50);
#endif
}

void LCD_create_char(u8* copy_pu8_char_data, u8 copy_u8_loc){
	/*
	 *	Function to store new charachter in the display ram.
	 *	Inputs::
	 *		copy_pu8_char_data>> The character data to be stored.
	 *		copy_u8_loc>> Character location in ram.
	 *	
	 *	Function does not return any values.
	 */
#if _LCD_interface_ == _8bit_interface
	// Get the current address from the address counter
	u8 curr_address= LCD_read_address_8bit();
	// Send set address to the CGRAM
	LCD_write_cmd_8bit(64+copy_u8_loc);
	//wait more than 39 us
	_delay_us(50);
	// Sent data packet
	for(u8 i= 0; i< 8; i++){
		LCD_write_data_8bit(copy_pu8_char_data[i]);
		_delay_us(50);
	}
	// Return to the current addres
	LCD_write_cmd_8bit(128+curr_address);
	// Wait more than 39 us
	_delay_us(50);
#elif _LCD_interface_ == _4bit_interface

#endif
}

void LCD_write_char(u8 copy_u8_char){
	/*
	 *	Function to write a character on the display.
	 *	Inputs::
	 *		copy_u8_char>> The character to be displayed.
	 *	
	 *	Function does not return any values.
	 */
#if _LCD_interface_ == _8bit_interface
	// Sent char data
	LCD_write_data_8bit(copy_u8_char);
	// Wait more than 39 us
	_delay_us(50);
#elif _LCD_interface_ == _4bit_interface
	// Wait more than 39 us
	LCD_write_data_4bit(copy_u8_char);
	// Wait more than 39 us
	_delay_us(50);
#endif
}

void LCD_write_str(u8* copy_pu8_str_ref){
	/*
	 *	Function to write a string on the display.
	 *	Inputs::
	 *		copy_pu8_str_ref>> Pointer to the first element of the string.
	 *	
	 *	Function does not return any values.
	 */
	// Create a counter for string indexing
	u8 i = 0;
	// Loop on the string till null terminator
	while(copy_pu8_str_ref[i] != null){
		// Display the curent character
		LCD_write_char(copy_pu8_str_ref[i]);
		// Increment the string index
		i++;
	}
}

void LCD_write_s32_number(s32 copy_s32_number){
	/*
	 *	Function to write a number on the display.
	 *	Inputs::
	 *		copy_s32_number>> The number to displayed.
	 *	
	 *	Function does not return any values.
	 */
	// Print zero if the original number is zero
	if(0 == copy_s32_number)
		LCD_write_char('0');
	// Check if the number is negative to print sign
	else if(0 > copy_s32_number){
		// Print the negative sign
		LCD_write_char('-');
		// Conver the number to positive
		copy_s32_number *= -1;
	}
	// Start printing the given number
	// Create a container for storing the nunmber
	u8 val_container[10];
	// Create counter to exit with the exact index
	u8 counter= 0;
	// Loop till the end of the number or overflow the container
	while((10 >= counter)  && (0 != copy_s32_number)){
		// Store the units in the container in the current index
		val_container[counter]= copy_s32_number%10;
		// Remove the stored unit from the original number
		copy_s32_number /= 10;
		// Increment the index
		counter++;
	}
	// Print the number in the container in reverse order
	for(u8 i= 1; i < (counter+1); i++){ //1, 2, 3, 4, 5
		LCD_write_char(val_container[counter-i]+'0'); //4, 3, 2, 1, 0
	}
}

void LCD_write_float(f32 copy_f32_number, u8 copy_u8_floating_point){
	/*
	 *	Function to write a float on the display.
	 *	Inputs::
	 *		copy_f32_number>> The float variable to displayed.
	 *		copy_u8_floating_point>> Required floating point to display.
	 *	
	 *	Function does not return any values.
	 */
	// Get the decimal value
	s32 int_val = (s32)copy_f32_number;
	// Get the floating value
	s32 float_val = (s32)((copy_f32_number - (f32)int_val) * LCD_pow(10, copy_u8_floating_point));
	// Print the decimal value
	LCD_write_s32_number(int_val);
	// Print the decimal point
	LCD_write_char('.');
	// Print the floating value after making sure its postive
	LCD_write_s32_number((float_val&(~(1<<7))));
	//LCD_wtire_s32_number((float_val > 0) ? float_val : (-1*float_val));
}
