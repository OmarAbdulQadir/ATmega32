/*******************************************************************/
/***               Date: 25/6/2023	Day: Sunday		             ***/
/***  Watchdog Timer driver for the microcontroller ATMega 32 	 ***/
/***     Created By: Omar Abdul Qadir	 Version= 1.0            ***/
/*******************************************************************/
/***         Note: All the data in the file is readable,         ***/
/***     And any editing will affect the controller's behavior,  ***/
/***          So It's not recommended to edit any data,          ***/
/***   Unless you are sure of what is the effect on behaviors.   ***/
/*******************************************************************/

// Standard libraries section
#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/BIT_MATH.h"

// Private libraries section
#include "WDT_private.h"
#include "WDT_interface.h"

// Drivers section


// Global variables and structs


/******************************************************************************/
/* Functions implementation section */
void WDT_void_start(u8 copy_prescaler_value){
	/*
	 *
	 */
	// Start watchdog
	if((copy_prescaler_value >= time16_3_ms) && (copy_prescaler_value <= time2_1_s))
		TIMER_WDTCR= ((WDT_enable << WDT_WDE) | (copy_prescaler_value));
}


void WDT_void_stop(void ){
	/*
	 *
	 */
	// Stop watchdog
	TIMER_WDTCR= ((WDT_enable << WDT_WDTOE) | (WDT_enable << WDT_WDE));
	TIMER_WDTCR= WDT_disable;
}
