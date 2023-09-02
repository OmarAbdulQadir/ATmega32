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
#include "EEP_interface.h"
#include "EEP_Private.h"

//Private libraries Section
#include "EEP_register.h"

//Global variables

/* Implementing of the driver functions */
// EEPROM write data on specific location
void EEP_write_data(u16 copy_u16_write_add, u8 copy_u8_write_data){
	/*
	 *
	 */
	if(copy_u16_write_add <= EEP_max_add){
		while(get_bit(EEP_EECR, EEP_EEWE) != 0);
		EEP_EEAR = copy_u16_write_add;
		EEP_EEDR = copy_u8_write_data;
		set_bit(EEP_EECR, EEP_EEMWE);
		set_bit(EEP_EECR, EEP_EEWE);
	}
	else{

	}
}


// EEPROM read data from specific location
u8 EEP_read_data(u16 copy_u16_read_add){
	/*
	 *
	 */
	u8 EEP_read_data = 0;
	while(get_bit(EEP_EECR, EEP_EEWE) != 0);
	EEP_EEAR |= copy_u16_read_add;
	set_bit(EEP_EECR, EEP_EERE);
	EEP_read_data = EEP_EEDR;
	return EEP_read_data;
}
