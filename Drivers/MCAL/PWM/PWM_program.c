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

//Standard libraries Section
#include "../../../LIB/BIT_MATH.h"
#include "../../../LIB/STD_TYPES.h"

//Private libraries Section
#include "PWM_Register.h"
#include "PWM_Private.h"
#include "PWM_interface.h"


//Global variables
// Call back function container
static void (*call_back_function[7])(void);


/* Implementing of the driver functions */
u8 gen_PWM(PWM_config* copy_ptr_PWM_config){
	/*
	 *
	 */
	if((copy_ptr_PWM_config -> Timer) == PWM_TIMER0){
		// Timer 0 control register reset
		PWM_TCCR0 = PWM0_TCCR_Reset;
		// Reconfigure timer 0 contol register
		PWM_TCCR0 |= (((copy_ptr_PWM_config -> WGM) << PWM_WGM01) | (PWM_ENABLE << PWM_WGM00) | ((copy_ptr_PWM_config -> COM) << PWM_COM00) | (copy_ptr_PWM_config -> CS));
		// Load the value of the TCNT register
		PWM_TCNT0 = *((u8*)(copy_ptr_PWM_config -> preload));
		// Load the value of the OCR register
		PWM_OCR0 = *((u8*)(copy_ptr_PWM_config -> preload)+1);
		// in normal mode interrupts must be enabled
		if((copy_ptr_PWM_config -> COM) == PWM_normal){
			// Enable OVF and COC interrupt for timer 0
			PWM_TIMSK |= ((PWM_ENABLE << PWM_TOIE0) | (PWM_ENABLE << PWM_OCIE0));
			// Enable global interrupt
			set_bit(PWM_SREG, PWM_Glob_Init_bit);
		}
		// Return success code
		return 0;
	}
	else if((copy_ptr_PWM_config -> Timer) == PWM_TIMER1){

		// Return success code
		return 1;
	}
	else if((copy_ptr_PWM_config -> Timer) == PWM_TIMER2){
		// Timer 0 control register reset
		PWM_TCCR2 = PWM2_TCCR_Reset;
		// Reconfigure timer 0 contol register
		PWM_TCCR2 |= (((copy_ptr_PWM_config -> WGM) << PWM_WGM21) | (PWM_DISABLE << PWM_WGM20) | ((copy_ptr_PWM_config -> COM) << PWM_COM20) | (copy_ptr_PWM_config -> CS));
		// Load the value of the TCNT register
		PWM_TCNT2 = *((u8*)(copy_ptr_PWM_config -> preload));
		// Load the value of the OCR register
		PWM_OCR2 = *((u8*)(copy_ptr_PWM_config -> preload)+1);
		// in normal mode interrupts must be enabled
		if((copy_ptr_PWM_config -> COM) == PWM_normal){
			// Enable OVF and COC interrupt for timer 2
			PWM_TIMSK |= ((PWM_ENABLE << PWM_TOIE2) | (PWM_ENABLE << PWM_OCIE2));
			// Enable global interrupt
			set_bit(PWM_SREG, PWM_Glob_Init_bit);
		}
		// Return success code
		return 2;
	}
	else{
		// Return faild code
		return 3;
	}
}


u8 PWM_stop(u8 copr_timer_id){
	/*
	 *
	 */
	if (copr_timer_id == PWM_TIMER0){
		// Clear the prescaler bits to stop the timer 0
		PWM_TCNT0 &= PWM_STOP_MASK;
		// Retuen success code
		return 0;
	}
	else if (copr_timer_id == PWM_TIMER1){

		// Retuen success code
		return 1;
	}
	else if (copr_timer_id == PWM_TIMER2){
		// Clear the prescaler bits to stop the timer 2
		PWM_TCCR2 &= PWM_STOP_MASK;
		// Retuen success code
		return 2;
	}
	else{
		// Retuen failed code
		return 3;
	}
}

void set_callback(u8 copy_vector_id, void (*copy_ptr_call_back_function)(void) ){
	/*
	 *
	 */
	// Save the fucntion pointer to its index in the callback functions array
	if((copy_vector_id >= 0)&&(copy_vector_id <= 6))
		call_back_function[copy_vector_id] = copy_ptr_call_back_function;
}

void __vector_11(void){
	/*
	 *
	 */
	if(call_back_function[ref_TIMER0_OVF] != NULL)
		call_back_function[ref_TIMER0_OVF]();
}

void __vector_10(void){
	/*
	 *
	 */
	if(call_back_function[ref_TIMER0_COMP] != NULL)
		call_back_function[ref_TIMER0_COMP]();
}

void __vector_9(void){
	/*
	 *
	 */
	if(call_back_function[ref_TIMER1_OVF] != NULL)
		call_back_function[ref_TIMER1_OVF]();
}

void __vector_8(void){
	/*
	 *
	 */
	if(call_back_function[ref_TIMER1_COMPB] != NULL)
		call_back_function[ref_TIMER1_COMPB]();
}

void __vector_7(void){
	/*
	 *
	 */
	if(call_back_function[ref_TIMER1_COMPA] != NULL)
		call_back_function[ref_TIMER1_COMPA]();
}

void __vector_5(void){
	/*
	 *
	 */
	if(call_back_function[ref_TIMER2_OVF] != NULL)
		call_back_function[ref_TIMER2_OVF]();
}

void __vector_4(void){
	/*
	 *
	 */
	if(call_back_function[ref_TIMER2_COMP] != NULL)
		call_back_function[ref_TIMER2_COMP]();
}
