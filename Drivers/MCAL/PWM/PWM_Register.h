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

#ifndef PWM_REGISTER_H
#define PWM_REGISTER_H

	/* General Registers */
	#define PWM_TIMSK		*((volatile u8* ) 0x59)
	#define PWM_TIFR		*((volatile u8* ) 0x58)
	#define PWM_SREG		*((volatile u8* ) 0x5F)

	/* Timer 0 Registers */
	#define PWM_TCCR0		*((volatile u8* ) 0x53)
	#define PWM_TCNT0		*((volatile u8* ) 0x52)
	#define PWM_OCR0		*((volatile u8* ) 0x5C)

	/* Timer 1 Registers */
	#define PWM_TCCR1A	*((volatile u8* ) 0x4F)
	#define PWM_TCCR1B	*((volatile u8* ) 0x4E)
	#define PWM_TCNT1		*((volatile u16*) 0x4C)
	#define PWM_OCR1A		*((volatile u16*) 0x4A)
	#define PWM_OCR1B		*((volatile u16*) 0x48)
	#define PWM_ICR1		*((volatile u16*) 0x46)

	/* Timer 2 Registers */
	#define PWM_TCCR2		*((volatile u8* ) 0x45)
	#define PWM_TCNT2		*((volatile u8* ) 0x44)
	#define PWM_OCR2		*((volatile u8* ) 0x43)
	#define PWM_ASSR2		*((volatile u8* ) 0x42)

#endif /* end PWM_REGISTER_H */
