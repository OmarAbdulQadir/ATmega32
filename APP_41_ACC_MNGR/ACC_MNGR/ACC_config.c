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


#include "ACC_config.h"


AC_Channel AC_Channels_ptr[ACC_NO_CHANNELS] = {

		{ACC0_CS_PORTID,
		 ACC0_CS_PINID,
		 ACC0_SS_PORTID,
		 ACC0_SS_PINID},

		{ACC1_CS_PORTID,
		 ACC1_CS_PINID,
		 ACC1_SS_PORTID,
		 ACC1_SS_PINID},

		{ACC2_CS_PORTID,
		 ACC2_CS_PINID,
		 ACC2_SS_PORTID,
		 ACC2_SS_PINID},

		 {ACC3_CS_PORTID,
		  ACC3_CS_PINID,
		  ACC3_SS_PORTID,
		  ACC3_SS_PINID},

};
