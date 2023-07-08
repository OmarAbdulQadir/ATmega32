/*******************************************************************/
/***               Date: 12/5/2023	Day: Friday                  ***/
/***		Keypad driver for the microcontroller ATMega 32      ***/
/***    	 Created By: Omar Abdul Qadir	 Version= 2.0		 ***/
/*******************************************************************/
/***         Note: All the data in the file is readable,         ***/
/***     And any editing will affect the controller's behavior,  ***/
/***          So It's not recommended to edit any data,          ***/
/***   Unless you are sure of what is the effect on behaviors.   ***/
/*******************************************************************/


#ifndef KEYPAD_CONFIG_H
#define KEYPAD_CONFIG_H
		
	/* Port configuration */
	#define port_keypad_ DIO_REF_PORTA
	
	/* Key pad Configuration */
	// Number of columns
	#define no_columns 4
	// Number of rows
	#define no_rows 4
	
	// Pin configuration for keypad
	// Column1: PORTx0
	// Column2: PORTx1
	// Column3: PORTx2
	// Column4: PORTx3
	// Row1: PORTx4
	// Row2: PORTx5
	// Row3: PORTx6
	// Row4: PORTx7
	
	/* Default key map */
	s8 keypad_map[no_rows][no_columns] = {{1 , 2 , 3 , 4},
										  {5 , 6 , 7 , 8},
										  {9 , 10, 11, 12},
										  {13, 14, 15, 16}};

#endif	//end LCD_CONFIG_H
