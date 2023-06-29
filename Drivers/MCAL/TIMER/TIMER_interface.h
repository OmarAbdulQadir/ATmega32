/*******************************************************************/
/***               Date: 09/6/2023	Day: Friday		             ***/
/*** 	 TIMER driver for the microcontroller ATMega 32			 ***/
/***     Created By: Omar Abdul Qadir	 Version= 1.0            ***/
/*******************************************************************/
/***         Note: All the data in the file is readable,         ***/
/***     And any editing will affect the controller's behavior,  ***/
/***          So It's not recommended to edit any data,          ***/
/***   Unless you are sure of what is the effect on behaviors.   ***/
/*******************************************************************/

#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

	typedef struct{
		u8 WGM: 3;								// Wave form generation mode and timer select
		u8 COM: 2;								// Compare output mode, non PWM
		u8 CS: 3;								// Prescaler set
		void* preload;							// void pointer to array of preload values for TCNT, OCR or ICR respectively
	}timer_config;

	/* Interupts Enum */
	#define ref_TIMER0_OVF			0				// Timer/Counter0 Overflow Interrupt
	#define ref_TIMER0_COMP			1				// Timer/Counter0 Compare Match Interrupt
	#define ref_TIMER1_OVF			2				// Timer/Counter1 Overflow Interrupt
	#define ref_TIMER1_COMPB		3				// Timer/Counter1 Match A Compare Match Interrupt
	#define ref_TIMER1_COMPA		4				// Timer/Counter1 Match B Compare Match Interrupt
	#define ref_TIMER2_OVF			5				// Timer/Counter2 Overflow Interrupt
	#define ref_TIMER2_COMP			6				// Timer/Counter2 Compare Match Interrupt
	
	/* Wave form generation modes */
	#define ref_TIMER0_WGM_NORM		0				// Timer/counter0 normal mode
	#define ref_TIMER0_WGM_CTC		1				// Timer/counter0 Clear timer on compare mode
	#define ref_TIMER1_WGM_NORM		2				// Timer/counter1 normal mode
	#define ref_TIMER1_WGM_CTC_OCR	3				// Timer/counter1 Clear timer on compare mode/top OCR
	#define ref_TIMER1_WGM_CTC_ICR	4				// Timer/counter1 Clear timer on compare mode/top ICR
	#define ref_TIMER2_WGM_NORM		5				// Timer/counter2 normal mode
	#define ref_TIMER2_WGM_CTC		6				// Timer/counter2 Clear timer on compare mode
	
	/* Compare output modes */
	#define ref_TIMER_COM_NORM		0				// Timer/counter OCx disconnected
	#define ref_TIMER_COM_tgl		1				// Timer/counter toggle OCx
	#define ref_TIMER_COM_clr		2				// Timer/counter clear OCx
	#define ref_TIMER_COM_set		3				// Timer/counter set OCx
	
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

	/* General functions decleration */
	void TIMER_init(timer_config* );
	void TIMER_set_callback(u8, void (*copy_ptr_call_back_function)(void) );
	void TIMER_config(void );
	void TIMER_stop(void );

#endif /* end TIMER_INTERFACE_H */
