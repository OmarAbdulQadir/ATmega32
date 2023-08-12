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

/* Standard libraries Section */
#include "../../../LIB/BIT_MATH.h"
#include "../../../LIB/STD_TYPES.h"


/* Helper Drivers Section */
#include "../DIO/DIO_interface.h"


/* Private libraries Section */
#include "TIMER_Register.h"
#include "TIMER_Private.h"
#include "TIMER_interface.h"


/* Global variables */
// Timers occupation flag (0: disabled, 1: clear, 2: Occupied by delay mS function, 3: Occupied by delay uS function 4: Occupied by counter function, 5: Occupied by PWM function)
u8 Timerx_occupation_flag[3] = {TIMER_ENABLE, TIMER_ENABLE, TIMER_ENABLE};
// Delay variables
static delay_t Delay_base[2];


/* Delay functions Implementation */
u8 TIMER_u8Delay_mS(u8 copy_u8TimerID, u16 copy_DelayTime_mS, void (*ptr_callback)(void) ){
	/*
	 *
	 */
	if((copy_u8TimerID <= TIMER1ID) && (copy_DelayTime_mS >= MIN_TIME) && (copy_DelayTime_mS <= MAX_TIME) && (Timerx_occupation_flag[copy_u8TimerID] == TIMER_Clear)){
		if(copy_u8TimerID != TIMER1ID){
			Delay_base[copy_u8TimerID].Delay_OVF = 0;
			Delay_base[copy_u8TimerID].Delay_RestTime = 0;
			Delay_base[copy_u8TimerID].ptr_callback_t = NULL;
			// Raise the occupation flag
			Timerx_occupation_flag[copy_u8TimerID] = TIMER_Delay_mS;
			// Calculate number of ticks
			f64 clc_NO_Tics = ((f64)copy_DelayTime_mS * Mills_to_Nano) / Mills_TickTime;
			// Calulate the rest of the nano second
			Delay_base[copy_u8TimerID].Delay_RestTime = ((copy_DelayTime_mS * Mills_to_Nano) - ((u32)clc_NO_Tics * Mills_TickTime));
			// Calulate the number of OVF
			Delay_base[copy_u8TimerID].Delay_OVF = (((u32)clc_NO_Tics / OVF_MAX) + 1);
			// Caculate the preload value
			u8 clc_PreloadValue = (OVF_MAX - ((u32)clc_NO_Tics % OVF_MAX));
			// Set parameters for callback
			Delay_base[copy_u8TimerID].ptr_callback_t = ptr_callback;
			// Create the control register value container
			if(copy_u8TimerID == TIMER0ID){
				// Set preload value
				TIMER0_TCNT = clc_PreloadValue;
				// Enable intrrupt
				TIMER_TIMSK &= TIMER0_TIMSK_Reset;
				TIMER_TIMSK |= TIMER_ENABLE;
				// Enable Global Interrupt
				TIMER_SREG |= TIMER_ENABLE << TIMER_Glob_Init_bit;
				// Reset timer configurations
				TIMER0_TCCR = TIMER_TCCR_Reset;
				// Set Prescaller to 1024
				TIMER0_TCCR |= TIMER_1024PRE;
			}
			else{
				// Set preload value
				TIMER2_TCNT = clc_PreloadValue;
				// Enable intrrupt
				TIMER_TIMSK &= TIMER2_TIMSK_Reset;
				TIMER_TIMSK |= TIMER_ENABLE << TIMER_TOIE2;
				// Enable Global Interrupt
				TIMER_SREG |= TIMER_ENABLE << TIMER_Glob_Init_bit;
				// Reset timer configurations
				TIMER2_TCCR = TIMER_TCCR_Reset;
				// Set Prescaller to 1024
				TIMER2_TCCR |= TIMER2_1024PRE;
			}
			return 1;
		}
		else{

			return 1;
		}
	}
	else{
		return 0;
	}
}

u8 TIMER_u8Delay_uS(u8 copy_u8TimerID, u16 copy_DelayTime_uS, void (*ptr_callback)(void) ){
	/*
	 *
	 */
	if((copy_u8TimerID <= TIMER1ID) && (copy_DelayTime_uS >= MIN_TIME) && (copy_DelayTime_uS <= MAX_TIME) && (Timerx_occupation_flag[copy_u8TimerID] == TIMER_Clear)){
		if(copy_u8TimerID != TIMER1ID){
			Delay_base[copy_u8TimerID].Delay_OVF = 0;
			Delay_base[copy_u8TimerID].Delay_RestTime = 0;
			Delay_base[copy_u8TimerID].ptr_callback_t = NULL;
			// Raise the occupation flag
			Timerx_occupation_flag[copy_u8TimerID] = TIMER_Delay_uS;
			// Calulate the number of OVF
			Delay_base[copy_u8TimerID].Delay_OVF = ((copy_DelayTime_uS / OVF_MAX) + 1);
			// Caculate the preload value
			u8 clc_PreloadValue = (OVF_MAX - (copy_DelayTime_uS % OVF_MAX));
			// Set parameters for callback
			Delay_base[copy_u8TimerID].ptr_callback_t = ptr_callback;
			// Create the control register value container
			// Set the confguration to (WGM: Normal, COM: Normal)
			if(copy_u8TimerID == TIMER0ID){
				// Set preload value
				TIMER0_TCNT = clc_PreloadValue;
				// Enable intrrupt
				TIMER_TIMSK &= TIMER0_TIMSK_Reset;
				TIMER_TIMSK |= TIMER_ENABLE;
				// Enable Global Interrupt
				TIMER_SREG |= TIMER_ENABLE << TIMER_Glob_Init_bit;
				// Reset timer configurations
				TIMER0_TCCR = TIMER_TCCR_Reset;
				// Set Prescaller to 8
				TIMER0_TCCR |= TIMER_8PRE;
			}
			else{
				// Set preload value
				TIMER2_TCNT = clc_PreloadValue;
				// Enable intrrupt
				TIMER_TIMSK &= TIMER2_TIMSK_Reset;
				TIMER_TIMSK |= TIMER_ENABLE << TIMER_TOIE2;
				// Enable Global Interrupt
				TIMER_SREG |= TIMER_ENABLE << TIMER_Glob_Init_bit;
				// Reset timer configurations
				TIMER2_TCCR = TIMER_TCCR_Reset;
				// Set Prescaller to 8
				TIMER2_TCCR |= TIMER2_8PRE;
			}
			return 1;
		}
		else{

			return 1;
		}
	}
	else{
		return 0;
	}
}

void TIMER_vDelay_Callback(u8 copy_u8TimerID ){
	/*
	 *
	 */
	// // Decrement the OVF counter then check the over flow counter if zero then delay in mS is finished
	if((--(Delay_base[copy_u8TimerID].Delay_OVF)) == 0){
		// Check the rest time in uS in case of mS delay if zero ther total delay is finished
		if((Delay_base[copy_u8TimerID].Delay_RestTime) == 0){
			// Clear the ossupation flag
			Timerx_occupation_flag[copy_u8TimerID] = TIMER_Clear;
			// Call the function
			(Delay_base[copy_u8TimerID].ptr_callback_t)();
			// Clear timer data
			TIMERx_vClear(copy_u8TimerID);
		}
		// In case of false continue the delay in uS
		else{
			// Clear the ossupation flag
			Timerx_occupation_flag[copy_u8TimerID] = TIMER_Clear;
			// Call the uS delay function
			TIMER_u8Delay_uS(copy_u8TimerID, (Delay_base[copy_u8TimerID].Delay_RestTime), (Delay_base[copy_u8TimerID].ptr_callback_t));
		}
	}
	// In case of false then decrement the OVF counter and continue
	else{

	}
}

void TIMERx_vClear(u8 copy_u8TimerID){
	/*
	 *
	 */
	// Disable the tmer interrupt
	switch(copy_u8TimerID){
		case TIMER0ID:
			// Reset timer configurations
			TIMER0_TCCR = TIMER_TCCR_Reset;
			// Disable intrrupt
			TIMER_TIMSK &= TIMER0_TIMSK_Reset;
			break;
		case TIMER2ID:
			// Reset timer configurations
			TIMER2_TCCR = TIMER_TCCR_Reset;
			// Disable intrrupt
			TIMER_TIMSK &= TIMER2_TIMSK_Reset;
			break;
		default:
			break;
	}
}


/* Periodic functions decleration */
u8 TIMER_u8CreatePeriodicTask(u8 copy_u8TimerID, u16 copy_TimePeriod_mS, void (*ptr_callback)(void) ){
	/*
	 *
	 */

	return 0;
}


/* Counter functions Implementation */
u8   TIMER_u8CounterStart (u8 copy_u8TimerID, u8 copy_u8TimerPrescaler, u32* ptr_return_variable){
	/*
	 *
	 */

	return 0;
}

u8 TIMER_u8CounterStop  (void ){
	/*
	 *
	 */
	return 0;
}


/* PWM functions Implementation */


/* Timer ISR Implementation */
// ISR of Timer/Counter0 Overflow
void __vector_11(void){
	/*
	 *
	 */
	switch(Timerx_occupation_flag[TIMER0ID]){
		case TIMER_Clear:
			TIMERx_vClear(TIMER0ID);
			break;
		case TIMER_Delay_mS:
			TIMER_vDelay_Callback(TIMER0ID);
			break;
		case TIMER_Delay_uS:
			TIMER_vDelay_Callback(TIMER0ID);
			break;
		case TIMER_Counter:

			break;
		case TIMER_PWM:

			break;
		default:
			break;
	}
}

// ISR of Timer/Counter0 Compare Match
void __vector_10(void){
	/*
	 *
	 */

}

// ISR of Timer/Counter1 Overflow
void __vector_9(void){
	/*
	 *
	 */

}

// ISR of Timer/Counter1 Match A Compare Match
void __vector_8(void){
	/*
	 *
	 */

}

// ISR of Timer/Counter1 Match B Compare Match
void __vector_7(void){
	/*
	 *
	 */

}

// ISR of Timer/Counter2 Overflow
void __vector_5(void){
	/*
	 *
	 */
	switch(Timerx_occupation_flag[TIMER2ID]){
		case TIMER_Clear:
			TIMERx_vClear(TIMER2ID);
			break;
		case TIMER_Delay_mS:
			TIMER_vDelay_Callback(TIMER2ID);
			break;
		case TIMER_Delay_uS:
			TIMER_vDelay_Callback(TIMER2ID);
			break;
		case TIMER_Counter:

			break;
		case TIMER_PWM:

			break;
		default:
			break;
	}
}

// ISR of Timer/Counter2 Compare Match
void __vector_4(void){
	/*
	 *
	 */

}
