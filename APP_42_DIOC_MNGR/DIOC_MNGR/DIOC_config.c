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


#include "DIOC_config.h"

DIOC_Channel DIOC_Channels_ptr[DIOC_NO_CHANNELS] = {
		{DIOC0_PORTID,
		 DIOC0_INID},

		{DIOC1_PORTID,
		 DIOC1_PINID},

		 {DIOC2_PORTID,
		 DIOC2_PINID}
};
