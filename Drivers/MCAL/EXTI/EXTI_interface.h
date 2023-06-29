/*******************************************************************/
/***               Date: 02/6/2023	Day: Friday		             ***/
/*** External interrupt driver for the microcontroller ATMega 32 ***/
/***     Created By: Omar Abdul Qadir	 Version= 1.0            ***/
/*******************************************************************/
/***         Note: All the data in the file is readable,         ***/
/***     And any editing will affect the controller's behavior,  ***/
/***          So It's not recommended to edit any data,          ***/
/***   Unless you are sure of what is the effect on behaviors.   ***/
/*******************************************************************/


#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H
	
	/* External Interrupt configuration setting */
	typedef struct{
		u8 PIE_int0: 1;	// INT0 Enable 
		u8 sen_lev_int0: 2;	// INT0 Sense level
		u8 PIE_int1: 1;	// INT1 Enable
		u8 sen_lev_int1: 2;	// INT1 Sense level
		u8 PIE_int2: 1; // INT2 Enable
		u8 sen_lev_int2: 1; // INT2 Sense level
	}EXTI_init_config_struct;

	/* Macros Section */
	// Interrupt 0
	#define INT0 	0
	// Interrupt 1
	#define INT1 	1
	// Interrupt 2
	#define INT2 	2

	// Enable value
	#define enable	1
	// Disable value
	#define disable	0
	
	/* Sense values macros */
	// Low level trigger
	#define EXTI_low_level		0b00
	// Interrupt on change trigger
	#define EXTI_IOC			0b01
	// Falling edge trigger
	#define EXTI_falling_edge	0b10
	// Rising edge trigger
	#define EXTI_rising_edge	0b11
	//
	#define EXTI_INT2_falling_edge 0
	//
	#define EXTI_INT2_rising_edge 1

	/* Global functions deceleration */
	// External interrupt initiation
	void EXTI_void_init(EXTI_init_config_struct* );
	// Pass callback function to certain interrupt
	void EXTI_void_INT_callback(u8, void (*ptr_callback_function)(void));
	// Polling on the flag of a certain interrupt
	u8 EXTI_get_INT_flag(u8 );

#endif	//end LCD_INTERFACE_H
