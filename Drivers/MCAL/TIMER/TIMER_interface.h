/*******************************************************************/
/***               Date: 09/6/2023	Day: Friday		             ***/
/*** 	 TIMER driver for the microcontroller ATMega 32			 ***/
/***     Created By: Omar Abdul Qadir	 Version= 2.0            ***/
/*******************************************************************/
/***         Note: All the data in the file is readable,         ***/
/***     And any editing will affect the controller's behavior,  ***/
/***          So It's not recommended to edit any data,          ***/
/***   Unless you are sure of what is the effect on behaviors.   ***/
/*******************************************************************/

#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

	/* Note 1: The timer driver works well with the 8MHz crystal, and all
	   functions will not be acurate in case of changing the sys frequency */

	/* Timers IDs */
	#define TIMER0ID				0				// Timer 0 ID
	#define TIMER1ID				2				// Timer 1 ID
	#define TIMER2ID				1				// Timer 2 ID
	#define TIMER1ID_OC1B			3				// Timer 1 ID OC2 PWM

	/* Timer 0/1 Prescaler value */
	#define TIMER_1PRE				1				// Prescaler 1 clk
	#define TIMER_8PRE				2				// Prescaler 8 clk/8
	#define TIMER_64PRE				3				// Prescaler 64 clk/64
	#define TIMER_256PRE			4				// Prescaler 256 clk/256
	#define TIMER_1024PRE			5				// Prescaler 1024 clk/1024
	#define TIMER_EXT_0				6				// External clock source on T0, faling edge
	#define TIMER_EXT_1				7				// External clock source on T0, rising edge

	/* Timer 2 presceler values */
	#define TIMER2_1PRE				1				// Prescaler 1 clk
	#define TIMER2_8PRE				2				// Prescaler 8 clk/8
	#define TIMER2_32PRE			3				// Prescaler 32 clk/32
	#define TIMER2_64PRE			4				// Prescaler 64 clk/64
	#define TIMER2_128PRE			5				// Prescaler 128 clk/128
	#define TIMER2_256PRE			6				// Prescaler 256 clk/256
	#define TIMER2_1024PRE			7				// Prescaler 1024 clk/1024


	/* Note: The delay Functions accuracy decays on decreasing the delay.
	   And, this function will not work with the periodic functions */
	/* Delay functions decleration */
	u8 TIMER_u8Delay_mS(u8, u16, void (*ptr_callback)(void) );
	u8 TIMER_u8Delay_uS(u8, u16, void (*ptr_callback)(void) );

	/* Periodic functions decleration */
	u8 TIMER_u8CreatePeriodicTask(u8, u16, void (*ptr_callback)(void) );
	u8 TIMER_u8deletePeriodicTask(u8 );

	/* Counter functions decleration */
	u8 TIMER_u8CounterStart(u8, u8, u32* );
	u8 TIMER_u8CounterStop (u8 );

	/* PWM functions decleration */
	u8 TIMER_u8FastPWM(u8, u8, u8 );
	u8 TIMER_u8PhaseCorrectPWM(u8, u8, u8);
	//u8 TIMER_u8PinJoinPWM(u8, u8, u8);
	u8 TIMER_u8StopPWM(u8 );

	/* Timer 1 ICU functions decleration */
	u8 TIMER_u8StartICU(u8 , f64*, f64*);
	u8 TIMER_u8StopICU(void );


#endif /* end TIMER_INTERFACE_H */
