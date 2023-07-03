/*******************************************************************/
/***               Date: 03/7/2023	Day: Monday 		         ***/
/*** 	 PWM driver for the microcontroller ATMega 32			 ***/
/***     Created By: Omar Abdul Qadir	 Version= 1.0            ***/
/*******************************************************************/
/***         Note: All the data in the file is readable,         ***/
/***     And any editing will affect the controller's behavior,  ***/
/***          So It's not recommended to edit any data,          ***/
/***   Unless you are sure of what is the effect on behaviors.   ***/
/*******************************************************************/

#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H

	typedef struct{
		u8 WGM		: 1;							// Wave form generation mode
		u8 COM		: 2;							// Compare output mode
		u8 CS		: 3;							// Prescaler value
		u8 Timer	: 2;							// Timer selection
		void* 	preload;							// Pointer to preload values TCNT, OCR and ICR respectiverly
	}PWM_config;

	/* Interupts */
	#define ref_TIMER0_OVF			0				// Timer/Counter0 Overflow Interrupt
	#define ref_TIMER0_COMP			1				// Timer/Counter0 Compare Match Interrupt
	#define ref_TIMER1_OVF			2				// Timer/Counter1 Overflow Interrupt
	#define ref_TIMER1_COMPB		3				// Timer/Counter1 Match A Compare Match Interrupt
	#define ref_TIMER1_COMPA		4				// Timer/Counter1 Match B Compare Match Interrupt
	#define ref_TIMER2_OVF			5				// Timer/Counter2 Overflow Interrupt
	#define ref_TIMER2_COMP			6				// Timer/Counter2 Compare Match Interrupt
	
	/* Timers */
	#define PWM_TIMER0				0				// Timer0 is used to generate PWM
	#define PWM_TIMER1				1				// Timer0 is used to generate PWM
	#define PWM_TIMER2				2				// Timer0 is used to generate PWM

	/* Wave form generation modes */
	#define PWM_fast				1				// Fast pulse width modulation
	#define PWM_phase_correct		0				// Phase correct pulse width modulation
	
	/* Compare output modes */
	#define PWM_normal				0				// Normal mode, OCx is disconected
	// Fast PWM modes
	#define PWM_fast_set_top		2				// OCx set at top of compare
	#define PWM_fast_clr_top		3				// Ocx clear at top of compare
	// Phase correct PWM modes
	#define PWM_clr_UP_set_DOWM		2				// Ocx set at up-counting, and clear at dowm-counting
	#define PWM_set_UP_clr_DOWM		3				// Ocx set at dowm-counting, and clear at up-counting

	/* Timer 0/1 Prescaler value */
	#define PWM_1PRE				1				// Prescaler 1 clk
	#define PWM_8PRE				2				// Prescaler 8 clk/8
	#define PWM_64PRE				3				// Prescaler 64 clk/64
	#define PWM_256PRE				4				// Prescaler 256 clk/256
	#define PWM_1024PRE				5				// Prescaler 1024 clk/1024
	#define PWM_EXT_0				6				// External clock source on T0, faling edge
	#define PWM_EXT_1				7				// External clock source on T0, rising edge

	/* Timer 2 presceler values */
	#define PWM_T2_1PRE				1				// Prescaler 1 clk
	#define PWM_T2_8PRE				2				// Prescaler 8 clk/8
	#define PWM_T2_32PRE			3				// Prescaler 32 clk/32
	#define PWM_T2_64PRE			4				// Prescaler 64 clk/64
	#define PWM_T2_128PRE			5				// Prescaler 128 clk/128
	#define PWM_T2_256PRE			6				// Prescaler 256 clk/256
	#define PWM_T2_1024PRE			7				// Prescaler 1024 clk/1024

	/* General functions decleration */
	// Generate fast pulse width modulation
	u8 gen_PWM(PWM_config* );
	// Set callback function in case of normal COM
	void set_callback(u8 copy_vector_id, void (*call_back_function)(void) );
	// Stop pulse width modulation for certain timer
	u8 PWM_stop(u8 );

#endif /* end PWM_INTERFACE_H */
