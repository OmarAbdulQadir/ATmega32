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

#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H

	typedef struct{
		u16 TIMER_OVF;
		u16 TIMER_RestTime;
		u16 TIMER_Preload;
		void (*ptr_callback_t)(void);
	}TIMER_t;

	/* Private macros */
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
	// TCCR0/2 Register reset
	#define TIMER_TCCR_Reset	0b00000000
	// TIMSK0 Register reset
	#define TIMER0_TIMSK_Reset	0b11111100
	// TIMSK2 Register reset
	#define TIMER2_TIMSK_Reset	0b00111111
	// Timer stop mask
	#define TIMER_STOP_MASK		0b11111000
	// One bit shift
	#define BIT_SHIFT1			1
	// Minimum delay time
	#define MIN_TIME			1
	// Maxmum delay time
	#define MAX_TIME			65535
	//
	#define Mills_to_Micro		1000
	//
	#define Mills_TickTime		128
	//
	#define OVF_MAX				256
	
	
	/* Waveform generattion modes references */
	// TIMER 0/2 Normal mode
	#define TIMER_NORM		0
	// Timer 0/2 PWM, Phase correct
	#define TIMER_PWM_PC	1
	// TIMER 0/2 CTC mode
	#define TIMER_CTC		2
	// Timer 0/2 PWM, Fast PWM
	#define TIMER_PWM_F		3


	/* Compare output modes */
	// Timer/counter OCx disconnected
	#define ref_TIMER_COM_NORM		0
	// Timer/counter toggle OCx
	#define ref_TIMER_COM_tgl		1
	// Timer/counter clear OCx
	#define ref_TIMER_COM_clr		2
	// Timer/counter set OCx
	#define ref_TIMER_COM_set		3


	/* Interupts index */
	// Timer/Counter0 Overflow Interrupt
	#define ref_TIMER0_OVF			0
	// Timer/Counter0 Compare Match Interrupt
	#define ref_TIMER0_COMP			1
	// Timer/Counter1 Overflow Interrupt
	#define ref_TIMER1_OVF			2
	// Timer/Counter1 Match A Compare Match Interrupt
	#define ref_TIMER1_COMPB		3
	// Timer/Counter1 Match B Compare Match Interrupt
	#define ref_TIMER1_COMPA		4
	// Timer/Counter2 Overflow Interrupt
	#define ref_TIMER2_OVF			5
	// Timer/Counter2 Compare Match Interrupt
	#define ref_TIMER2_COMP			6


	/* Bit numbers of timer 0/2 */
	// Timer/Counter Control Register
	// Waveform Generation Mode bit 0
	#define TIMER_WGM0			6
	// Waveform Generation Mode bit 1
	#define TIMER_WGM1			3
	// Compare Match Output Mode bit 1
	#define TIMER_COM1			5
	// Compare Match Output Mode bit 0
	#define TIMER_COM0			4
	// Clock Select bit 2
	#define TIMER_CS2			2
	// Clock Select bit 1
	#define TIMER_CS1			1
	// Clock Select bit 0
	#define TIMER_CS0			0


	/* Bit numbers of timer 1 */



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


	/* Timer occupation cases */
	#define TIMER_Clear			1
	#define	TIMER_Delay_mS		2
	#define	TIMER_Delay_uS		3
	#define TIMER_Counter		4
	#define	TIMER_PWM			5
	#define TIMER_Ptask			6
	#define TIMER_ICU			7


	/* Callback functions decleration */
	// Callback function for delay task handling
	void TIMER_vDelay_Callback(u8 );
	// Callback function for delay task handling
	void TIMER_vPtask_Callback(u8 );
	// Callback function for counter task handling
	void TIMER_vCounter_callback(u8 );
	// Callback function for PWM task handling
	void TIMER_vPWM_callback(u8 );
	// Callback function for ICU task handling
	void TIMER_vICU_callback(void );
	// Clear timer from delay configurations
	void TIMERx_vClear(u8 );

	/* Private functions decleration */
	// ISR of Timer/Counter2 Overflow
	void __vector_5 (void)__attribute__((signal));
	// ISR of Timer/Counter1 Input capture unit
	void __vector_6 (void)__attribute__((signal));
	// ISR of Timer/Counter1 Overflow
	void __vector_9 (void)__attribute__((signal));
	// ISR of Timer/Counter0 Overflow
	void __vector_11(void)__attribute__((signal));


#endif /* end TIMER_PRIVATE_H */
