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

#include <util/delay.h>
#include "ACC_interface.h"

// AC_Channels_ptr
extern AC_Channel AC_Channels_ptr[ACC_NO_CHANNELS];

// ACC Manager intitiation
void ACC_init( void )
{
	/*
	 *
	 */
	// Wait for the HW to startup
	_delay_ms(10);
	// Create State container
	u8 Ch_state= 0;
	// Loop and initiate the of each channel
	for(u8 i= 0; i < ACC_NO_CHANNELS; i++){
		// initiate the control signal pin as output
		DIO_void_set_pin_dir((AC_Channels_ptr[i].ACC_ControlSignalPortID), (AC_Channels_ptr[i].ACC_ControlSignalPinID), OUTPUT);
		// initiate the status pin as input
		DIO_void_set_pin_in_pullUP((AC_Channels_ptr[i].ACC_StatusSignalPortID), (AC_Channels_ptr[i].ACC_StatusSignalPinID));
		// get the status value of the channel
		Ch_state = DIO_u8_get_pin((AC_Channels_ptr[i].ACC_StatusSignalPortID), (AC_Channels_ptr[i].ACC_StatusSignalPinID));
		// check if the channel is on
		if(Ch_state == ACC_ChannelOn){
			// turn off the channel
			DIO_void_toggle_pin((AC_Channels_ptr[i].ACC_ControlSignalPortID), (AC_Channels_ptr[i].ACC_ControlSignalPinID));
		}
		else
		{
			// Do nothing
		}
	}
}

// ACC Manager write Channel
STD_ReturnType ACC_WriteChannel( u8 Copy_ChannelID, u8 copy_ChannelValue )
{
	/*
	 *
	 */
	// Check input parameters validity
	if((Copy_ChannelID < ACC_NO_CHANNELS) && ((copy_ChannelValue == ACC_ChannelOff) || (copy_ChannelValue == ACC_ChannelOn)))
	{// If valid
		// Create state container
		u8 Ch_state= 0;
		// Chech the channel status
		Ch_state = DIO_u8_get_pin((AC_Channels_ptr[Copy_ChannelID].ACC_StatusSignalPortID), (AC_Channels_ptr[Copy_ChannelID].ACC_StatusSignalPinID));
		DIO_void_assign_port(DIO_REF_PORTB, Ch_state);
		if(Ch_state != copy_ChannelValue)
		{// Not the same value
			// Toggle the status value
			DIO_void_toggle_pin((AC_Channels_ptr[Copy_ChannelID].ACC_ControlSignalPortID), (AC_Channels_ptr[Copy_ChannelID].ACC_ControlSignalPinID));
			_delay_ms(10);
			Ch_state = DIO_u8_get_pin((AC_Channels_ptr[Copy_ChannelID].ACC_StatusSignalPortID), (AC_Channels_ptr[Copy_ChannelID].ACC_StatusSignalPinID));
			// Recheck the state signal
			if(Ch_state == copy_ChannelValue)
			{// Signal status changed to the right value
				// Return on notice
				return E_OK;
			}
			else
			{// Signal status is not correct
				// Report an error
				// return not ok notice
				return E_NOT_OK;
			}
		}
		else
		{// Same value
			// Do nothing
			// Return ok notice
			return E_OK;
		}
	}
	else
	{// If not valid
		// Report an error
		// Return not ok notice
		return E_NOT_OK;
	}
}

// ACC Manager read Channel data
STD_ReturnType ACC_ReadChannel( u8 Copy_ChannelID, u8* ptr_ChannelValue )
{
	/*
	 *
	 */
	// Check input parameters validity
	if(Copy_ChannelID < ACC_NO_CHANNELS)
	{// If valid
		// create status container
		u8 Ch_state= 0;
		// Check the channel status value
		Ch_state = DIO_u8_get_pin((AC_Channels_ptr[Copy_ChannelID].ACC_StatusSignalPortID), (AC_Channels_ptr[Copy_ChannelID].ACC_StatusSignalPinID));
		// Return the channel value in the pointer
		*ptr_ChannelValue = Ch_state;
		// Return ok notice
		return E_OK;
	}
	else
	{// If not valid
		// Report an error
		// Return not ok notice
		return E_NOT_OK;
	}
}
