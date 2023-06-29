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

//Standard libraries Section
#include "../../../LIB/BIT_MATH.h"
#include "../../../LIB/STD_TYPES.h"

//Private libraries Section
#include "EXTI_register.h"
#include "EXTI_private.h"
#include "EXTI_interface.h"

//Global variables
// Call back functions container
static void (*call_back_function[3])(void);

/* Implementing of the driver functions */
void EXTI_void_init(EXTI_init_config_struct* EXTI_config){
	/*
	 *	Function Initiate the External interrupt peripheral using the given configurations.
	 *	Inputs::
	 *		EXTI_config>> Pointer to Configuration struct that contains Enable values of INT0, INT1, INT2,
	 *					Besides the sense level of each
	 *		
	 *	Function does not return any value, Hence function must be called every time you need
	 *	to change the configurations.
	 */
	// set sense level of INT0
	/* for more optimization its recommended to set all using clear all 3 bits then or the new value */
	agn_bit(EXTI_MCUCR, EXTI_ISC00, (get_bit((EXTI_config -> sen_lev_int0), 0)));
	agn_bit(EXTI_MCUCR, EXTI_ISC01, (get_bit((EXTI_config -> sen_lev_int0), 1)));

	// set sense level of INT1
	/* for more optimization its recommended to configure all using clear all 3 bits then or the new value */
	agn_bit(EXTI_MCUCR, EXTI_ISC10, (get_bit((EXTI_config -> sen_lev_int1), 0)));
	agn_bit(EXTI_MCUCR, EXTI_ISC11, (get_bit((EXTI_config -> sen_lev_int1), 1)));

	// set sense level of INT2
	agn_bit(EXTI_MCUCSR, EXTI_ISC2, (EXTI_config -> sen_lev_int2));

	// configure peripheral interrupt
	/* for more optimization its recommended to configure all using clear all 3 bits then or the new value */
	agn_bit(EXTI_GICR, EXTI_PIE0, (EXTI_config -> PIE_int0));
	agn_bit(EXTI_GICR, EXTI_PIE1, (EXTI_config -> PIE_int1));
	agn_bit(EXTI_GICR, EXTI_PIE2, (EXTI_config -> PIE_int2));

	// Enable global interrupt
	set_bit(EXTI_SREG, EXTI_GIE);
}

u8 EXTI_get_INT_flag(u8 copy_INT_id){
	/*
	 *	Function return value of the INT flag in case of Polling not interrupting
	 *	Inputs::
	 *		copy_INT_id: Interrupt id of the selected interrupt
	 *	Function does not return any value, Hence the function is worthless when using interrupting method
	 *	as the ISR will always reset the flag when it is called.
	 */
	// Switching on the selected interrupt
	switch (copy_INT_id){
	// Return the INT0 flag is selected
	case INT0:
		return get_bit(EXTI_GIFR, EXTI_PIF0);
	// Return the INT1 flag is selected
	case INT1:
		return get_bit(EXTI_GIFR, EXTI_PIF1);
	// Return the INT2 flag is selected
	case INT2:
		return get_bit(EXTI_GIFR, EXTI_PIF2);
	// Return 0 if wrong flag value is passed
	default:
		return 0;
	}
}

void EXTI_void_INT_callback(u8 copy_INT_id, void (*ptr_callback_function)(void)){
	/*
	 *	Function address the call back functions to be called by the ISR of each Interrupt
	 *	Inputs::
	 *		copy_INT_id>> Interrupt id of the selected interrupt
	 *		ptr_callback_function>> Pointer to the callback function that needs to executed
	 *							when the flag is raised.
	 *	Function does not return any value, Hence the function will be called only to address the callback
	 *	function or change it.
	 */
	// Store the callback function address in the container is the passed INT selection is right
	if(copy_INT_id < 3)
		call_back_function[copy_INT_id]= ptr_callback_function;
}

void __vector_1 (void){
	/*
	 *	External Interrupt 0 ISR.
	 */
	// call the callback function by reference is stored, else nothing will happen
	if(call_back_function[0] != NULL)
		call_back_function[0]();
}

void __vector_2 (void){
	/*
	 *	External Interrupt 1 ISR.
	 */
	// call the callback function by reference is stored, else nothing will happen
	if(call_back_function[1] != NULL)
		call_back_function[1]();
}

void __vector_3 (void){
	/*
	 *	External Interrupt 2 ISR.
	 */
	// call the callback function by reference is stored, else nothing will happen
	if(call_back_function[2] != NULL)
		call_back_function[2]();
}
