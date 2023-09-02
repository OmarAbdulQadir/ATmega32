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

#ifndef ACC_MNGR_ACC_INTERFACE_C_
#define ACC_MNGR_ACC_INTERFACE_C_

#define ACC_MODULE_ID				30u

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../Drivers/MCAL/DIO/DIO_interface.h"
#include "ACC_private.h"
#include "ACC_config.h"

// ACC Channel IDs
#define ACC_ChannelID0				0
#define ACC_ChannelID1				1
#define ACC_ChannelID2				2
#define ACC_ChannelID3				3

// ACC Channel states
#define ACC_ChannelOn				0
#define ACC_ChannelOff				1

// ACC Manager intitiation
void ACC_init( void );
#define ACC_init_API_ID				31u

// ACC Manager write Channel
STD_ReturnType ACC_WriteChannel( u8 , u8  );
#define ACC_WriteChannel_API_ID		32u

// ACC Manager read Channel data
STD_ReturnType ACC_ReadChannel( u8 , u8*  );
#define ACC_ReadChannel_API_ID		33u

#endif /* ACC_MNGR_ACC_INTERFACE_C_ */
