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

#ifndef DIOC_MNGR_DIOC_INTERFACE_H_
#define DIOC_MNGR_DIOC_INTERFACE_H_

#define DIOC_MODULE_ID				40u

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../Drivers/MCAL/DIO/DIO_interface.h"

// DIOC Channel IDs
#define DIOC_ChannelID0				0
#define DIOC_ChannelID1				1
#define DIOC_ChannelID2				2

// DIOC Manager intitiation
void DIOC_init( void );
#define DIOC_init_API_ID			41u

// DIOC Set Channel Direction
STD_ReturnType DIOC_SetChannelDir( u8 , u8  );
#define DIOC_SetChannelDir_API_ID	42u

// DIOC Manager write Channel
STD_ReturnType DIOC_WriteChannel( u8 , u8  );
#define DIOC_WriteChannel_API_ID	43u

// DIOC Manager read Channel data
STD_ReturnType DIOC_ReadChannel( u8 , u8*  );
#define DIOC_ReadChannel_API_ID		44u

#endif /* DIOC_MNGR_DIOC_INTERFACE_H_ */
