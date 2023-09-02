/*******************************************************************/
/***            	Date: 20/8/2023	Day: Sunday                  ***/
/***  External EEPROM driver for the microcontroller ATMega 32   ***/
/***    	 Created By: Omar Abdul Qadir	 Version= 1.0		 ***/
/*******************************************************************/
/***         Note: All the data in the file is readable,         ***/
/***     And any editing will affect the controller's behavior,  ***/
/***          So It's not recommended to edit any data,          ***/
/***   Unless you are sure of what is the effect on behaviors.   ***/
/*******************************************************************/


//Standard libraries Section
#include <util/delay.h>
#include "../../../LIB/BIT_MATH.h"
#include "../../../LIB/STD_TYPES.h"
#include "../../MCAL/IIC/IIC_interface.h"

//Private libraries Section
#include "EXT_EEP_config.h"
#include "EXT_EEP_private.h"
#include "EXT_EEP_interface.h"

// Private Macros


//Global variables


/* Implementing of the driver functions */
// EEPROM write data to block
void EEP_vWriteDataToBlock(u8, u8, u8){
	/*
	 *
	 */

}

// EEPROM read data from block
u8 EEP_u8ReadDataFromBlock(u8, u8){
	/*
	 *
	 */
	return 0;
}
