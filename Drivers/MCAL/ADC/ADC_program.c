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

//Standard libraries Section
#include "../../../LIB/BIT_MATH.h"
#include "../../../LIB/STD_TYPES.h"

//Private libraries Section
#include "ADC_register.h"
#include "ADC_private.h"
#include "ADC_interface.h"

//Global variables
static void (*callback_functions_address)(u16 )= NULL;

/* Implementing of the driver functions */
void ADC_void_init(void ){
	/*
	 *	Function to initiate the ADC perepheral.
	 *	No inputs to the function.
	 *
	 *	No return from the function.
	 */
	// Assign the value of the left adjust bit
	agn_bit(ADC_ADMUX, ADC_ADLAR_pin, ADC_ADLAR);

	// Assign the values of the reference selection regesters
	agn_bit(ADC_ADMUX, ADC_REFS0_pin, ADC_REFS0);
	agn_bit(ADC_ADMUX, ADC_REFS1_pin, ADC_REFS1);

	// Assign the value of the enable bit
	agn_bit(ADC_ADCSRA, ADC_ADEN_pin, ADC_ADEN);
}


void ADC_void_config(ADC_config_struct* ptr_config){
	/*
	 *	Function configure or reconfigure the ADC perepheral
	 *	Inputs::
	 *		ptr_config>> Pointer to ADC configurations Struct.
	 *	
	 *	Function does not return any values, Hence it needs to be called every time you need to reconfigure the ADC.
	 */
	// Configure the analog channel and gain selection bits
	ADC_ADMUX &= ADC_MUX_clear;
	ADC_ADMUX |= ptr_config -> MUX;

	// Configure the ADC prescaler select bits
	ADC_ADCSRA &= ADC_ADPS_clear;
	ADC_ADCSRA |= ptr_config -> ADPS;

	// Configure the ADC auto trigger source bits
	ADC_SFIOR &= ADC_ADTS_clear;
	ADC_SFIOR |= ptr_config -> ADTS;

	// Configure the ADC auto trigger enable bit
	agn_bit(ADC_ADCSRA, ADC_ADATE_pin, ptr_config -> ADATE);

	// Configure the ADC interrupt enable bit
	agn_bit(ADC_ADCSRA, ADC_ADIE_pin, ptr_config -> ADIE);

	// Configure the Global interupt bit
	agn_bit(ADC_SREG, ADC_Global_INT, ptr_config -> ADIE);
}

void ADC_void_start_conv(void){
	/*
	 *	Function to make the ADC start converstion
	 *	No inputs to the function.
	 *
	 *	No return from the function.
	 */
	// Enable ADC start conversion bit
	agn_bit(ADC_ADCSRA, ADC_ADSC_pin, ADC_ADSC);
}

void ADC_void_read_data(u16* ptr_result){
	/*
	 *	Function to return the ADC value by polling.
	 *	Inputs::
	 *		ptr_result>> pointer to the ADC value container variable.
	 *	
	 *	Function does not retuen any data, Hence it needs to be called when a value update is needed.
	 */
	// Enable ADC start conversion bit
	agn_bit(ADC_ADCSRA, ADC_ADSC_pin, ADC_ADSC);

	// Polling on the ADC interrupt flag bit
	while(get_bit(ADC_ADCSRA, ADC_ADIF_pin) == 0);

	// Resit the ADC interrupt flag bit
	set_bit(ADC_ADCSRA, ADC_ADIF_pin);

	// Return the digital value
	*(ptr_result)= ADC_ADCD_16bit;
}


void ADC_void_INIT_callback(void (*ptr_callback_function)(u16 ) ){
	/*
	 *	Function to address the call back function to the ISR
	 *	Inputs::
	 *		ptr_callback_function>> pointer to the callback function.
	 *
	 *	Function does not return any value and anly called when addressing the callback function.
	 */
	callback_functions_address= ptr_callback_function;
}

void __vector_16(void){
	/*
	 *	ADC flag ISR
	 */
	if(callback_functions_address != NULL){
		callback_functions_address(ADC_ADCD_16bit);
	}
}
