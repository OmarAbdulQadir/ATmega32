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

#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H

	/* Private macros */
	// Bottom value
	#define PWM_BOTTOM 			0
	// Max value
	#define	PWM_MAX				0xFF
	// Enable Value
	#define PWM_ENABLE			1
	// Disable value
	#define PWM_DISABLE			0
	// Null Definition
	#define NULL 				(void* ) 0
	// TCCR0 Register reset
	#define PWM0_TCCR_Reset		0b00000000
	// TIMSK0 Register reset
	#define PWM0_TIMSK_Reset	0b11111100
	// TCCR2 Register reset
	#define PWM2_TCCR_Reset		0b00000000
	// TIMSK2 Register reset
	#define PWM2_TIMSK_Reset	0b00111111
	// Timer stop mask
	#define PWM_STOP_MASK		0b11111000
	// TCNT index
	#define PWM_TCNT_i			0
	// OCR index
	#define PWM_OCR_i			1
	// ICR index
	#define PWM_ICR_i			2
	
	
	/* Waveform generattion modes references */

	/* Bit numbers of timer 0 */
	// Timer/Counter Control Register
	// Waveform Generation Mode bit 0
	#define PWM_WGM00			6
	// Waveform Generation Mode bit 1
	#define PWM_WGM01			3
	// Compare Match Output Mode bit 1
	#define PWM_COM01			5
	// Compare Match Output Mode bit 0
	#define PWM_COM00			4
	// Clock Select bit 2
	#define PWM_CS02			2
	// Clock Select bit 1
	#define PWM_CS01			1
	// Clock Select bit 0
	#define PWM_CS00			0


	/* Bit numbers of timer 1 */



	/* Bit numbers of timer 2 */
	// Timer/Counter Control Register
	// Waveform Generation Mode bit 0
	#define PWM_WGM20			6
	// Waveform Generation Mode bit 1
	#define PWM_WGM21			3
	// Compare Match Output Mode bit 1
	#define PWM_COM21			5
	// Compare Match Output Mode bit 0
	#define PWM_COM20			4
	// Clock Select bit 2
	#define PWM_CS22			2
	// Clock Select bit 1
	#define PWM_CS21			1
	// Clock Select bit 0
	#define PWM_CS20			0


	// Timer/Counter Interrupt Mask Register
	// Timer/Counter0 Overflow Interrupt Enable
	#define PWM_TOIE0			0
	// Timer/Counter0 Output Compare Match Interrupt Enable
	#define PWM_OCIE0			1
	//

	//

	//

	//

	// Timer/Counter2 Overflow Interrupt Enable
	#define PWM_TOIE2			6
	// Timer/Counter2 Output Compare Match Interrupt Enable
	#define PWM_OCIE2			7

	//Status Register
	// Global interrupt
	#define PWM_Glob_Init_bit	7


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


#endif /* end PWM_PRIVATE_H */




