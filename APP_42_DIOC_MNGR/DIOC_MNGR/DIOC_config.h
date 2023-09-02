/*******************************************************************/
/***               Date: 2/9/2023	Day: Saturday                ***/
/***    DIOC Manager for the microcontroller ATMega 32 		     ***/
/***     Created By: Omar Abdul Qadir	 Version= 1.0            ***/
/*******************************************************************/
/***         Note: All the data in the file is readable,         ***/
/***     And any editing will affect the controller's behavior,  ***/
/***          So It's not recommended to edit any data,          ***/
/***   Unless you are sure of what is the effect on behaviors.   ***/
/*******************************************************************/

#ifndef DIOC_MNGR_DIOC_CONFIG_H_
#define DIOC_MNGR_DIOC_CONFIG_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../Drivers/MCAL/DIO/DIO_interface.h"
#include "DIOC_private.h"

#define DIOC_NO_CHANNELS		3

#define DIOC0_PORTID			DIO_REF_PORTB
#define DIOC0_INID				B0

#define DIOC1_PORTID			DIO_REF_PORTB
#define DIOC1_PINID				B1

#define DIOC2_PORTID			DIO_REF_PORTD
#define DIOC2_PINID				B6

#endif /* DIOC_MNGR_DIOC_CONFIG_H_ */
