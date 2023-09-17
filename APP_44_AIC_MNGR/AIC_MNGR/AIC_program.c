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

#include "AIC_interface.h"
#include "AIC_private.h"
#include "AIC_config.h"

extern AIC_t AnalogInChannel[NO_CHANNEL];
static ADC_config_struct AnalogChannelConfig[NO_CHANNEL];
static AIC_EnFlag_t AIC_ENFlag = {STD_FALSE, STD_FALSE};

// Analog Input Channel Manger Init
void AIC_Init( void ){
	/*
	 *
	 */
	// Enable manger
	AIC_ENFlag.AIC_initFlag = STD_TRUE;
	// Enable ADC
	ADC_void_init();
}

// Analog Channel Init
STD_ReturnType AIC_InitChannel( u8 copy_ChannelID )
{
	/*
	 *
	 */
	// check data validity
	if((copy_ChannelID < NO_CHANNEL) && (AIC_ENFlag.AIC_initFlag == STD_TRUE))
	{// if valid
		// Enable the channel flag
		set_bit(AIC_ENFlag.AIC_ChEN, copy_ChannelID);
		// Configure the channel's configuration structure
		AnalogChannelConfig[copy_ChannelID].MUX = AnalogInChannel[copy_ChannelID].ChannelID;
		AnalogChannelConfig[copy_ChannelID].ADPS = AnalogInChannel[copy_ChannelID].ChannelPS;
		AnalogChannelConfig[copy_ChannelID].ADATE = AIC_ADATE;
		AnalogChannelConfig[copy_ChannelID].ADTS = AIC_ADTS;
		AnalogChannelConfig[copy_ChannelID].ADIE = AIC_ADIE;
		// return ok notice
		return E_OK;
	}
	else
	{// if not valid
		// report an error
		// return not ok notice
		return E_NOT_OK;
	}
}

// Read Analog Channel
STD_ReturnType AIC_ReadChannel( u8 copy_ChannelID, u16* ptr_ReturnData ){
	/*
	 *
	 */
	// Check data validity
	if((copy_ChannelID < NO_CHANNEL) && (ptr_ReturnData != NULL) && (get_bit(AIC_ENFlag.AIC_ChEN, copy_ChannelID) == STD_TRUE))
	{// if valid
		// configure the ADC to read from the specific channel
		ADC_void_config(&AnalogChannelConfig[copy_ChannelID]);
		// create the containers for readings
		u16 tempAnalogData = 0;
		u16 AvgAnalogData = 0;
		// read the channel x number of times
		for(u8 i= 0; i < AnalogReadAcc; i++)
		{
			ADC_void_read_data(&tempAnalogData);
			AvgAnalogData += tempAnalogData;
		}
		// get the average reading
		AvgAnalogData /= AnalogReadAcc;
		*(ptr_ReturnData) = AvgAnalogData;
		// Check if data is stored right
		if(*(ptr_ReturnData) == AvgAnalogData)
		{// if valid
			// return ok notice
			return E_OK;
		}
		else
		{// if not valid
			// report an error
			// return not ok notice
			return E_NOT_OK;
		}
	}
	else
	{// if not valid
		// Report an error
		// return not ok notice
		return E_NOT_OK;
	}
	return 0;
}
