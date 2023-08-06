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

//Standard libraries Section
#include "../../../LIB/BIT_MATH.h"
#include "../../../LIB/STD_TYPES.h"

//Private libraries Section
#include "EEPROM_register.h"
#include "EEPROM_private.h"
#include "EEPROM_interface.h"

//Global variables

/* Implementing of the driver functions */
// EEPROM write data on specific location
void EEPROM_write_data(u16 copy_u16_write_add, u8 copy_u8_write_data){
	/*
	 *
	 */
	if(copy_u16_write_add <= EEPROM_max_add){
		while(get_bit(EEPROM_EECR, EEPROM_EEWE) != 0);
		EEPROM_EEAR = copy_u16_write_add;
		EEPROM_EEDR = copy_u8_write_data;
		set_bit(EEPROM_EECR, EEPROM_EEMWE);
		set_bit(EEPROM_EECR, EEPROM_EEWE);
	}
	else{

	}
}


// EEPROM read data from specific location
u8 EEPROM_read_data(u16 copy_u16_read_add){
	/*
	 *
	 */
	u8 EEPROM_read_data = 0;
	while(get_bit(EEPROM_EECR, EEPROM_EEWE) != 0);
	EEPROM_EEAR |= copy_u16_read_add;
	set_bit(EEPROM_EECR, EEPROM_EERE);
	EEPROM_read_data = EEPROM_EEDR;
	return EEPROM_read_data;
}
