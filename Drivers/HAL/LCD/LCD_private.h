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


#ifndef LCD_PRIVATE_H
#define LCD_PRIVATE_H
	
	/* Private function decleration section */
	// Math power
	s32 LCD_pow(u8 , u8 );
	// Write data to the LCD in 8bit mode
	void LCD_write_data_8bit(u8 lcd_copy_word_8bit);
	// Write command to the LCD in 8bit mode
	void LCD_write_cmd_8bit(u8 lcd_copy_cmd_8bit);
	// Read address from the LCD in 8bit mode
	u8 LCD_read_address_8bit(void );
	// Write data to the LCD in 4bit mode
	void LCD_write_data_4bit(u8 lcd_copy_word_4bit);
	// Write command to the LCD in 4bit mode
	void LCD_write_cmd_4bit(u8 lcd_copy_cmd_4bit);
	// Function set in 4bit mode
	void LCD_function_set_4bit(void );
	// Read address from the LCD in 4bit mode
	u8 LCD_read_data_4bit(void);
	
	/* Command section */
	// Step	name	     Rs-RW-DB7-DB6-DB5-DB4-DB3-DB2-DB1-DB0
	// function set 8bit:: 	 0 -0 -0  -0  -1  -1  -N  -F  -x  -x
	// N= 1: 2-line display - F= 0: 5 x 7 dot display
	#define function_set_8bit	0b00111000
	// Display on/off::  0 -0 -0  -0  -0  -0  -1  -D  -C  -B 
	// D= 1: display on - C= 0: Cursor off - B= 0: Blinking off
	#define display_on			0b00001100
	// Display on/off::  0 -0 -0  -0  -0  -0  -1  -D  -C  -B
	// D= 0: display on - C= 0: Cursor off - B= 0: Blinking off
	#define display_off			0b00001000
	// Display clear::	 0 -0 -0  -0  -0  -0  -0  -0  -0  -1
	#define display_clear		0b00000001
	// Return Home::	 0 -0 -0  -0  -0  -0  -0  -0  -1  -x
	#define return_home			0b00000010
	
	/* Macros definition section */
	// Null terminator
	#define null '\0'
	// Line 2 start address
	#define line2 64
	// Bussy flag position
	#define lcd_busy_flag 7

	
#endif	//end LCD_PRIVATE_H
