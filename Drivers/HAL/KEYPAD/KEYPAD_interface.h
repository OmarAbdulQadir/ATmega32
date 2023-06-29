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


#ifndef KEYPAD_INTERFACE_H
#define KEYPAD_INTERFACE_H

	/* Global functions decleration */
	// Key pad initiation
	void keypad_init(void);
	// Read Pressed value from the key pad
	s8 keypad_read(void);
	// Reset the value of the key map
	void keypad_set_map(s8* );

#endif	//end KEYPAD_INTERFACE_H
