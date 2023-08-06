/*******************************************************************/
/***               Date: 03/6/2023	Day: Saturday	             ***/
/*** 	 ADC driver for the microcontroller ATMega 32			 ***/
/***     Created By: Omar Abdul Qadir	 Version= 1.1            ***/
/*******************************************************************/
/***         Note: All the data in the file is readable,         ***/
/***     And any editing will affect the controller's behavior,  ***/
/***          So It's not recommended to edit any data,          ***/
/***   Unless you are sure of what is the effect on behaviors.   ***/
/*******************************************************************/

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

	/* EEPROM Control Register bits */
	// EEPROM Ready Interrupt Enable
	#define EEPROM_EERIE		3
	// EEPROM Master Write Enable
	#define EEPROM_EEMWE		2
	// EEPROM Write Enable
	#define EEPROM_EEWE			1
	// EEPROM Read Enable
	#define EEPROM_EERE			0
	
	/* Private Macros */
	#define EEPROM_LOW			0
	#define EEPROM_HIGH			1
	#define EEPROM_max_add		((u16)1023u)
	#define EEPROM_add_mask		(((u16)0b11111100)<<(8))

#endif /* ADC_PRIVATE_H_ */
