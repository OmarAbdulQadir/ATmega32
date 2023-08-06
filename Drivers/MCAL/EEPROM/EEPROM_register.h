/*******************************************************************/
/***               Date: 03/8/2023	Day: Thursday	             ***/
/*** 	EEPROM driver for the microcontroller ATMega 32			 ***/
/***     Created By: Omar Abdul Qadir	 Version= 1.1            ***/
/*******************************************************************/
/***         Note: All the data in the file is readable,         ***/
/***     And any editing will affect the controller's behavior,  ***/
/***          So It's not recommended to edit any data,          ***/
/***   Unless you are sure of what is the effect on behaviors.   ***/
/*******************************************************************/


#ifndef ADC_REGISTER_H
#define ADC_REGISTER_H

	// EEPROM Address Register
	#define EEPROM_EEAR		*((volatile u16*) 0x3E)

	// EEPROM Data Register
	#define EEPROM_EEDR		*((volatile u8 *) 0x3D)

	// EEPROM Control Register
	#define EEPROM_EECR		*((volatile u8 *) 0x3C)


#endif	//end ADC_REGISTER_H
