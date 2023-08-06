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

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

	/* ADCMUX register pins */
	// Left adjust pin value
	#define ADC_ADLAR		0

	// Reference voltage selection High pin
	#define ADC_REFS1_pin	7
	// Reference voltage selection Low pin
	#define ADC_REFS0_pin	6
	// Left adjust pin
	#define ADC_ADLAR_pin	5

	/* ADCSRA register pins */
	// ADC enable pin Value
	#define ADC_ADEN		1
	// ADC start conversion pin value
	#define ADC_ADSC		1
	
	// ADC enable pin
	#define ADC_ADEN_pin	7
	// ADC start conversion pin
	#define ADC_ADSC_pin	6
	// ADC auto trigger enable pin
	#define	ADC_ADATE_pin	5
	// ADC interrupt flag pin
	#define ADC_ADIF_pin	4
	// ADC interrupt enable pin
	#define ADC_ADIE_pin	3
	
	/* SREG register pins */
	// Global interrupt enable pin
	#define ADC_Global_INT	7

	/* Macros */
	// Analog channel and gain selection bits clear command
	#define ADC_MUX_clear 	0b11100000
	// ADC prescaler select bits clear command
	#define ADC_ADPS_clear	0b11111000
	// ADC trigger selection bits clear command
	#define ADC_ADTS_clear	0b00011111
	// NULL
	#define NULL (void *) 0
	
	// ADC ISR
	void __vector_16 (void)__attribute__((signal));

#endif /* ADC_PRIVATE_H_ */
