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

#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H

	/* Private macros */
	// INIT reference start
	#define INIT_ref_st 		0
	// INIT reference end
	#define INIT_ref_ed 		7
	// Bottom value
	#define TIMER_BOTTOM 		0
	// Max value
	#define	TIMER_MAX			0xFF
	// Enable Value
	#define TIMER_ENABLE		1
	// Disable value
	#define TIMER_DISABLE		0
	// Null Definition
	#define NULL 				(void* ) 0
	// TCCR0 Register reset
	#define TIMER0_TCCR_Reset	0b00000000
	// TIMSK0 Register reset
	#define TIMER0_TIMSK_Reset	0b11111100
	// TCCR2 Register reset
	#define TIMER2_TCCR_Reset	0b00000000
	// TIMSK2 Register reset
	#define TIMER2_TIMSK_Reset	0b00111111
	// Timer stop mask
	#define TIMER_STOP_MASK		0b11111000
	// One bit shift
	#define BIT_SHIFT1			1
	
	
	/* Waveform generattion modes references */
	// TIMER 0 Normal mode
	#define TIMER0_NORM		0
	// TIMER 0 CTC mode
	#define TIMER0_CTC		2
	// TIMER 1 Normel mode
	#define TIMER1_NORM		0
	// TIMER 1 CTC top - OCR
	#define TIMER1_CTC_OCR	4
	// TIMER 1 CTC top - ICR
	#define TIMER1_CTC_ICR	12
	// TIMER 2 Normal mode
	#define TIMER2_NORM		0
	// TIMER 2 CTC mode
	#define TIMER2_CTC		2
	// Timer0 separator
	#define TIMER0_sep		1
	// Timer1 Separator
	#define TIMER1_sep		4

	/* Bit numbers of timer 0 */
	// Timer/Counter Control Register
	// Waveform Generation Mode bit 0
	#define TIMER_WGM00			6
	// Waveform Generation Mode bit 1
	#define TIMER_WGM01			3
	// Compare Match Output Mode bit 1
	#define TIMER_COM01			5
	// Compare Match Output Mode bit 0
	#define TIMER_COM00			4
	// Clock Select bit 2
	#define TIMER_CS02			2
	// Clock Select bit 1
	#define TIMER_CS01			1
	// Clock Select bit 0
	#define TIMER_CS00			0


	/* Bit numbers of timer 1 */



	/* Bit numbers of timer 2 */
	// Timer/Counter Control Register
	// Waveform Generation Mode bit 0
	#define TIMER_WGM20			6
	// Waveform Generation Mode bit 1
	#define TIMER_WGM21			3
	// Compare Match Output Mode bit 1
	#define TIMER_COM21			5
	// Compare Match Output Mode bit 0
	#define TIMER_COM20			4
	// Clock Select bit 2
	#define TIMER_CS22			2
	// Clock Select bit 1
	#define TIMER_CS21			1
	// Clock Select bit 0
	#define TIMER_CS20			0


	// Timer/Counter Interrupt Mask Register
	// Timer/Counter0 Overflow Interrupt Enable
	#define TIMER_TOIE0			0
	// Timer/Counter0 Output Compare Match Interrupt Enable
	#define TIMER_OCIE0			1
	//

	//

	//

	//

	// Timer/Counter2 Overflow Interrupt Enable
	#define TIMER_TOIE2			6
	// Timer/Counter2 Output Compare Match Interrupt Enable
	#define TIMER_OCIE2			7

	//Status Register
	// Global interrupt
	#define TIMER_Glob_Init_bit	7


	/* Private functions decleration */
	// ISR of Timer/Counter2 Compare Match
	void __vector_4(void)__attribute__((signal));
	// ISR of Timer/Counter2 Overflow
	void __vector_5(void)__attribute__((signal));
	// ISR of Timer/Counter1 Match B Compare Match
	void __vector_7(void)__attribute__((signal));
	// ISR of Timer/Counter1 Match A Compare Match
	void __vector_8(void)__attribute__((signal));
	// ISR of Timer/Counter1 Overflow
	void __vector_9(void)__attribute__((signal));
	// ISR of Timer/Counter0 Compare Match
	void __vector_10(void)__attribute__((signal));
	// ISR of Timer/Counter0 Overflow
	void __vector_11(void)__attribute__((signal));


#endif /* end TIMER_PRIVATE_H */




