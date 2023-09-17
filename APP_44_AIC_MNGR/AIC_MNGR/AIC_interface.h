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

#ifndef AIC_INTERFACE_H_
#define AIC_INTERFACE_H_

#define AIC_MODULE_ID				50u

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../Drivers/MCAL/ADC/ADC_interface.h"

// Channels ID
#define AIC_CH0			0
#define AIC_CH1			1
#define AIC_CH2			2

// Analog Input Channel Manger Init
void AIC_Init( void );
#define AIC_Init_API_ID				51u

// Analog Channel Init
STD_ReturnType AIC_InitChannel( u8 );
#define AIC_InitChannel_API_ID		52u

// Read Analog Channel
STD_ReturnType AIC_ReadChannel( u8, u16* );
#define AIC_ReadChannel_API_ID		53u

#endif /* AIC_MNGR_AIC_INTERFACE_H_ */
