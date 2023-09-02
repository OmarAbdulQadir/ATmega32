/*******************************************************************/
/***               Date: 1/9/2023	Day: Friday                  ***/
/***     ACC Manager for the microcontroller ATMega 32 		     ***/
/***     Created By: Omar Abdul Qadir	 Version= 1.0            ***/
/*******************************************************************/
/***         Note: All the data in the file is readable,         ***/
/***     And any editing will affect the controller's behavior,  ***/
/***          So It's not recommended to edit any data,          ***/
/***   Unless you are sure of what is the effect on behaviors.   ***/
/*******************************************************************/

#ifndef ACC_MNGR_ACC_CONFIG_H_
#define ACC_MNGR_ACC_CONFIG_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../Drivers/MCAL/DIO/DIO_interface.h"
#include "ACC_private.h"

#define ACC_NO_CHANNELS			4

#define ACC0_CS_PORTID			DIO_REF_PORTC
#define ACC0_CS_PINID			B2
#define ACC0_SS_PORTID			DIO_REF_PORTC
#define ACC0_SS_PINID			B3

#define ACC1_CS_PORTID			DIO_REF_PORTC
#define ACC1_CS_PINID			B4
#define ACC1_SS_PORTID			DIO_REF_PORTC
#define ACC1_SS_PINID			B5

#define ACC2_CS_PORTID			DIO_REF_PORTC
#define ACC2_CS_PINID			B6
#define ACC2_SS_PORTID			DIO_REF_PORTC
#define ACC2_SS_PINID			B7

#define ACC3_CS_PORTID			DIO_REF_PORTD
#define ACC3_CS_PINID			B4
#define ACC3_SS_PORTID			DIO_REF_PORTD
#define ACC3_SS_PINID			B5

#endif /* ACC_MNGR_ACC_CONFIG_H_ */
