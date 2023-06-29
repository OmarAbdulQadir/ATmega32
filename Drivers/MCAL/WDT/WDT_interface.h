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


#ifndef WDT_INTERFACE_H
#define WDT_INTERFACE_H

	/* Prescaler values */
	enum WDT_Prescaler{
		time16_3_ms,		// Timer value 16.3 ms
		time35_5_ms,		// Timer value 35.5 ms
		time65_0_ms,		// Timer value 65.0 ms
		time130_ms,			// Timer value 130.0 ms
		time260_ms,			// Timer value 260.0 ms
		time520_ms,			// Timer value 520.0 ms
		time1_0_s,			// Timer value 1.0 s
		time2_1_s			// Timer value 2.1 s
	};

	/* Public function decleration */
	// Start watchdog timer with selected prescaler
	void WDT_void_start(u8 );
	// Stop watchdog timer
	void WDT_void_stop(void );

#endif /* end SPI_INTERFACE_H */
