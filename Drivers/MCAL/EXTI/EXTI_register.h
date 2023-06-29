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


#ifndef EXTI_REGISTER_H
#define EXTI_REGISTER_H
	
	/* External interrupt setting registers */
	// Global interrupt enable
	#define EXTI_SREG	*((volatile u8*) 0x5F)
	// Peripheral interrupt enable
	#define EXTI_GICR	*((volatile u8*) 0x5B)
	// Sense levels of INT0, INT1
	#define EXTI_MCUCR	*((volatile u8*) 0x55)
	// Sense level of INT2
	#define EXTI_MCUCSR	*((volatile u8*) 0x54)
	// peripheral interrupt flags
	#define EXTI_GIFR	*((volatile u8*) 0x5A)

#endif	//end EXTI_REGISTER_H
