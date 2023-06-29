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


#ifndef WDT_PRIVATE_H
#define WDT_PRIVATE_H

	/* Macros section */
	// Enable
	#define WDT_enable		1
	// Disable
	#define WDT_disable		0

	/* Watch dog control register bits */
	// Watchdog Enable bit
	#define WDT_WDE			3
	// Watchdog Turn-off Enable bit
	#define WDT_WDTOE		4

	/* Watchdog control register */
	#define TIMER_WDTCR		*((volatile u8*) 0x41)

#endif /* end SPI_PRIVATE_H */
