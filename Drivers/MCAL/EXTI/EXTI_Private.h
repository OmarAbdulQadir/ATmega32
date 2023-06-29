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

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

	/* Null defenition */
	#define NULL ((void *) 0)

	/* Global Interrupt Enable bit */
	#define EXTI_GIE	7

	/* Sense level bits */
	// sense levels of INT0
	#define EXTI_ISC00	0
	#define EXTI_ISC01	1
	// sense levels of INT2
	#define EXTI_ISC10	2
	#define EXTI_ISC11	3
	// sense levels of INT2
	#define EXTI_ISC2	6

	/* Pereferal Interrupt Enable bits */
	// Pereferal Interrupt Enable for INT0
	#define	EXTI_PIE0	6
	// Pereferal Interrupt Enable for INT1
	#define EXTI_PIE1	7
	// Pereferal Interrupt Enable for INT2
	#define EXTI_PIE2	5

	/* Pereferal Interrupt flag bits */
	// Pereferal Interrupt flag for INT0
	#define EXTI_PIF0	6
	// Pereferal Interrupt flag for INT1
	#define	EXTI_PIF1	7
	// Pereferal Interrupt flag for INT2
	#define EXTI_PIF2	5

	/* ISR Declerations */
	// Interrupt 0 ISR Decleration
	void __vector_1 (void)__attribute__((signal));
	// Interrupt 1 ISR Decleration
	void __vector_2 (void)__attribute__((signal));
	// Interrupt 2 ISR Decleration
	void __vector_3 (void)__attribute__((signal));
	

#endif /* EXTI_PRIVATE_H_ */
