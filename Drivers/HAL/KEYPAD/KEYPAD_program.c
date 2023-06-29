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

//Standard libraries Section
#include "../../../LIB/BIT_MATH.h"
#include "../../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"

//Private libraries Section
#include "KEYPAD_config.h"
#include "KEYPAD_private.h"
#include "KEYPAD_interface.h"

//Global variables


/* Implementing of the driver functions */
void keypad_init(void){
	/*
	 *	Function is to configure the pins direction.
	 *
	 *	No input Parameters is required
	 *	Also Setting configurations in the config.h file is essential before use
	 *
	 *	No return from the function
	 */
	// Set the direction of the columns as output
	for(u8 col = start_col; col < no_columns; col++){
		DIO_void_set_pin_dir(port_keypad_, col, OUTPUT);
		DIO_void_set_pin(port_keypad_, col);
		}
	// set the direction of the rows as input pullUp
	for(u8 row = start_row; row < (start_row+no_rows); row++){
		DIO_void_set_pin_in_pullUP(port_keypad_, row);
	}
}


s8 keypad_read(void){
	/*
	 *	Function is to return the corresponding value of the pressed key
	 *
	 *	No input parameters but InIT function must be called first
	 *	As the behavior of the function will not be as expexted.
	 *
	 *	Output::
	 *			keypad_map[R][C] >> the coressponding value of the key pressed will be
	 *								returned as s8 variable, And a value -1 means no key is pressed.
	 *
	 *	Function will not affect the keypad map any other behavior only is returns the first key pressed,
	 *	as it will not return the higher order key if two keys are pressed as the same time.
	 *	Ex: 1 and 6 is pressed >> 1 is lower in order so the return will be value 1, and at the same time,
	 *	6 will not be returned is the two keys were released at the same time.
	 */
	// Loop on each columns
	for(u8 COL = start_col; COL < no_columns; COL++){
		// turn on the column to check if thier is pressed button
		DIO_void_clear_pin(port_keypad_, COL);
		for(u8 ROW = start_row; ROW < (start_row+no_rows); ROW++){
			//check row value for the selected column
			if(LOW == DIO_u8_get_pin(port_keypad_, ROW)){
				//return selected row value after the key is unpressed
				while(LOW == DIO_u8_get_pin(port_keypad_, ROW));
				return keypad_map[ROW-start_row][COL];
			}
		}
		// Turn off the column if no key was pressed
		DIO_void_set_pin(port_keypad_, COL);
	}
	// return -1 if no buttons were pressed
	return -1;
}

void keypad_set_map(s8* copy_pu8_new_keypad_map){
	/*
	 *	Function is to change the default key pad map
	 *
	 *	Intput:: 
	 *			copy_pu8_new_keypad_map	>> pointer to the new keypad map
	 *									   -> It must be equal in length to the mult of rows and cloums
	 *									   -> EX: R= 3, C= 4 means its length Should be equal 12
	 *
	 *	No return from the function
	 */
	// Loop on each column
	for(u8 COL = start_; COL < no_columns; COL++){
		// Loop on each row
		for(u8 ROW = start_; ROW < no_rows; ROW++){
			// Assign the the new value of the key
			keypad_map[ROW][COL] = *(copy_pu8_new_keypad_map+(ROW*no_columns)+(COL));
		}
	}
}
