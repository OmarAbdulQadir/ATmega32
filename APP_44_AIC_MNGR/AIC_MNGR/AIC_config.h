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

#ifndef AIC_CONFIG_H_
#define AIC_CONFIG_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../Drivers/MCAL/ADC/ADC_interface.h"

#define		NO_CHANNEL			3

#define		AnalogReadAcc		5

#define		CHANNEL_0PIN		5
#define		CHANNEL_0PS			ADPS_8

#define		CHANNEL_1PIN		6
#define		CHANNEL_1PS			ADPS_8

#define		CHANNEL_2PIN		7
#define		CHANNEL_2PS			ADPS_8

typedef struct{
	u8   ChannelID : 5;
	u8	 ChannelPS : 3;
}AIC_t;


#endif /* AIC_MNGR_AIC_CONFIG_H_ */
