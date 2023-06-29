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


#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H
	
	/* Global funcitons deleration */
	// LCD Initiation
	void LCD_init(void );
	// LCD Set cursor to specific location
	void LCD_set_cursor(u8, u8 );
	// LCD Clear the screen
	void LCD_clear(void );
	// LCD Turn off
	void LCD_off(void );
	// LCD Turn on
	void LCD_on(void );
	// LCD Create custom charachter
	void LCD_create_char(u8*, u8 );
	// LCD write character to the screen
	void LCD_write_char(u8 );
	// LCD write string to the screen
	void LCD_write_str(u8* );
	// LCD write decimal number to the screen
	void LCD_write_s32_number(s32 );
	// LCD write float to the screen
	void LCD_write_float(f32, u8 );

#endif	//end LCD_INTERFACE_H
