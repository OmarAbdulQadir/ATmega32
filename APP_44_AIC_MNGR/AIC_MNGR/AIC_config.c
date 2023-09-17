/*******************************************************************/
/***               Date: 6/9/2023	Day: Saturday                ***/
/*** Analog Input Channel Mngr for the microcontroller ATMega 32 ***/
/***     Created By: Omar Abdul Qadir	 Version= 1.0            ***/
/*******************************************************************/
/***         Note: All the data in the file is readable,         ***/
/***     And any editing will affect the controller's behavior,  ***/
/***          So It's not recommended to edit any data,          ***/
/***   Unless you are sure of what is the effect on behaviors.   ***/
/*******************************************************************/

#include "AIC_private.h"
#include "AIC_config.h"

AIC_t AnalogInChannel[NO_CHANNEL] = {
		{
				CHANNEL_0PIN,
				CHANNEL_0PS,
		},
		{
				CHANNEL_1PIN,
				CHANNEL_1PS,
		},
		{
				CHANNEL_2PIN,
				CHANNEL_2PS,
		}
};
