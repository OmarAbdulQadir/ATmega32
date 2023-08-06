/*******************************************************************/
/***               Date: 03/6/2023	Day: Saturday	             ***/
/*** 	 ADC driver for the microcontroller ATMega 32			 ***/
/***     Created By: Omar Abdul Qadir	 Version= 1.1            ***/
/*******************************************************************/
/***         Note: All the data in the file is readable,         ***/
/***     And any editing will affect the controller's behavior,  ***/
/***          So It's not recommended to edit any data,          ***/
/***   Unless you are sure of what is the effect on behaviors.   ***/
/*******************************************************************/


#ifndef ADC_REGISTER_H
#define ADC_REGISTER_H
	
	// ADC multiblexer selection register
	#define ADC_ADMUX		*((volatile u8 *) 0x27)
	// ADC control and statuse register
	#define ADC_ADCSRA		*((volatile u8 *) 0x26)
	// Special functions I/O register
	#define ADC_SFIOR		*((volatile u8 *) 0x50)
	// Status register
	#define ADC_SREG		*((volatile u8 *) 0x5F)

	// ADC High data register
	#define ADC_ADCH		*((volatile u8 *) 0x25)
	// ADC Low data register
	#define ADC_ADCL		*((volatile u8 *) 0x24)
	// ADC full data register
	#define ADC_ADCD_16bit	*((volatile u16*) 0x24)


#endif	//end ADC_REGISTER_H
