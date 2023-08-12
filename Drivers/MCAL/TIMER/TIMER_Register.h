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

#ifndef TIMER_REGISTER_H
#define TIMER_REGISTER_H

	/* General Registers */
	#define TIMER_TIMSK		*((volatile u8* ) 0x59)
	#define TIMER_TIFR		*((volatile u8* ) 0x58)
	#define TIMER_SREG		*((volatile u8* ) 0x5F)

	/* Timer 0 Registers */
	#define TIMER0_TCCR		*((volatile u8* ) 0x53)
	#define TIMER0_TCNT		*((volatile u8* ) 0x52)
	#define TIMER0_OCR		*((volatile u8* ) 0x5C)

	/* Timer 1 Registers */
	#define TIMER1_TCCR1A	*((volatile u8* ) 0x4F)
	#define TIMER1_TCCR1B	*((volatile u8* ) 0x4E)
	#define TIMER1_TCNT1	*((volatile u16*) 0x4C)
	#define TIMER1_OCR1A	*((volatile u16*) 0x4A)
	#define TIMER1_OCR1B	*((volatile u16*) 0x48)
	#define TIMER1_ICR1		*((volatile u16*) 0x46)

	/* Timer 2 Registers */
	#define TIMER2_TCCR		*((volatile u8* ) 0x45)
	#define TIMER2_TCNT		*((volatile u8* ) 0x44)
	#define TIMER2_OCR		*((volatile u8* ) 0x43)
	#define TIMER2_ASSR2	*((volatile u8* ) 0x42)

#endif /* end TIMER_REGISTER_H */
