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

#include "DIOC_interface.h"
#include "DIOC_private.h"
#include "DIOC_config.h"

extern DIOC_Channel DIOC_Channels_ptr[DIOC_NO_CHANNELS];
static u8 DIOC_initFlag = STD_FALSE;

// DIOC Manager intitiation
void DIOC_init( void )
{
	// Check if the init flag is false
	if(DIOC_initFlag == STD_FALSE)
	{// if false
		// make the init flag true
		DIOC_initFlag = STD_TRUE;
		for(u8 i = 0; i < DIOC_NO_CHANNELS; i++)
		{
			// Set initial direction of the channels
			DIO_void_set_pin_dir(DIOC_Channels_ptr[i].DIOC_PortID, DIOC_Channels_ptr[i].DIOC_PinID, OUTPUT);
			// Set initial value of the channels
			DIO_void_clear_pin(DIOC_Channels_ptr[i].DIOC_PortID, DIOC_Channels_ptr[i].DIOC_PinID);
		}
	}
	else
	{// if true
		// do nothing
	}
}

// DIOC Set Channel Direction
STD_ReturnType DIOC_SetChannelDir( u8 copy_ChannelID , u8 copy_ChannelDirection )
{
	// check data validity
	if((copy_ChannelID < DIOC_NO_CHANNELS) && ((copy_ChannelDirection == OUTPUT) || (copy_ChannelDirection == INPUT)) && (DIOC_initFlag == STD_TRUE))
	{// if data is valid
		// create status container
		u8 CH_state = DIO_u8_get_PinDir(DIOC_Channels_ptr[copy_ChannelID].DIOC_PortID, DIOC_Channels_ptr[copy_ChannelID].DIOC_PinID);
		// check the current channel direction
		if(CH_state != copy_ChannelDirection)
		{// if not same direction
			// change the direction
			DIO_void_set_pin_dir(DIOC_Channels_ptr[copy_ChannelID].DIOC_PortID, DIOC_Channels_ptr[copy_ChannelID].DIOC_PinID, copy_ChannelDirection);
			// Check if changed to the desired direction
			CH_state = DIO_u8_get_PinDir(DIOC_Channels_ptr[copy_ChannelID].DIOC_PortID, DIOC_Channels_ptr[copy_ChannelID].DIOC_PinID);
			if(CH_state != copy_ChannelDirection)
			{// if not same
				// report an error
				// return not ok notice
				return E_NOT_OK;
			}
			else
			{// if same
				// do nothing
				// return ok notice
				return E_OK;
			}
		}
		else
		{// if same directio
			// do notihing
			// return ok notice
			return E_OK;
		}
	}
	else
	{// if data is not valid
		// report an error
		// return not ok notice
		return E_NOT_OK;
	}
}

// DIOC Manager write Channel
STD_ReturnType DIOC_WriteChannel( u8 copy_ChannelID , u8 copy_ChannelValue )
{
	// Check data validity
	if((copy_ChannelID < DIOC_NO_CHANNELS) && ((copy_ChannelValue == HIGH) || (copy_ChannelValue == LOW)) && (DIOC_initFlag == STD_TRUE))
	{// if data is valid
		// create status check
		u8 CH_state = DIO_u8_get_PinDir(DIOC_Channels_ptr[copy_ChannelID].DIOC_PortID, DIOC_Channels_ptr[copy_ChannelID].DIOC_PinID);
		// Check if the channel output
		if(CH_state == OUTPUT)
		{// if output
			CH_state = DIO_u8_get_PinOut(DIOC_Channels_ptr[copy_ChannelID].DIOC_PortID, DIOC_Channels_ptr[copy_ChannelID].DIOC_PinID);
			// check the current channel value
			if(CH_state != copy_ChannelValue)
			{// if not same value
				// Change the channel value
				DIO_void_assign_pin(DIOC_Channels_ptr[copy_ChannelID].DIOC_PortID, DIOC_Channels_ptr[copy_ChannelID].DIOC_PinID, copy_ChannelValue);
				CH_state = DIO_u8_get_PinOut(DIOC_Channels_ptr[copy_ChannelID].DIOC_PortID, DIOC_Channels_ptr[copy_ChannelID].DIOC_PinID);
				// Check if the changed to the desired value
				if(CH_state != copy_ChannelValue)
				{// if not the same
					// report an error
					// return not ok notice
					return E_NOT_OK;
				}
				else
				{// if same
					// return ok notice
					return E_OK;
				}
			}
			else
			{// if same value
				// do nothing
				// return ok notice
				return E_OK;
			}
		}
		else
		{// if input
			// report errors
			// return not ok notice
			return E_NOT_OK;
		}
	}
	else
	{// if data is not valid
		// report an error
		// return not ok notice
		return E_NOT_OK;
	}
}

// DIOC Manager read Channel data
STD_ReturnType DIOC_ReadChannel( u8 copy_ChannelID , u8* ptr_ChannelValue )
{
	// Check the data validity
	if((copy_ChannelID < DIOC_NO_CHANNELS) && (DIOC_initFlag == STD_TRUE))
	{// if data valid
		// create a state container
		u8 CH_state = DIO_u8_get_PinDir(DIOC_Channels_ptr[copy_ChannelID].DIOC_PortID, DIOC_Channels_ptr[copy_ChannelID].DIOC_PinID);
		// Check if the channel is input
		if(CH_state == INPUT)
		{// if true
			// store the value into the container
			CH_state = DIO_u8_get_pin(DIOC_Channels_ptr[copy_ChannelID].DIOC_PortID, DIOC_Channels_ptr[copy_ChannelID].DIOC_PinID);
			// put the value in the ptr
			*ptr_ChannelValue = CH_state;
			// Check if the value in the ptr is right saved
			if(*ptr_ChannelValue != CH_state)
			{// if not right
				// report an error
				// return not ok notice
				return E_NOT_OK;
			}
			else
			{// if right
				// do nothing
				// return ok notice
				return E_OK;
			}
		}
		else
		{// if false
			// report an error
			// return not ok notice
			return E_NOT_OK;
		}
	}
	else
	{// if data is not valid
		// report an error
		// return not ok notice
		return E_NOT_OK;
	}
}
