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
static TIMER_t Timer_base[2];

/* General functions Implementation */
void TIMERx_vClear(u8 copy_u8TimerID){
	/*
	 *
	 */
	// Disable the timer interrupt
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


/* Delay functions Implementation */
u8 TIMER_u8Delay_mS(u8 copy_u8TimerID, u16 copy_DelayTime_mS, void (*ptr_callback)(void) ){
	/*
	 *
	 */
	if((copy_u8TimerID <= TIMER1ID) && (copy_DelayTime_mS >= MIN_TIME) && (copy_DelayTime_mS <= MAX_TIME) && (Timerx_occupation_flag[copy_u8TimerID] == TIMER_Clear)){
		if(copy_u8TimerID != TIMER1ID){
			Timer_base[copy_u8TimerID].TIMER_OVF = 0;
			Timer_base[copy_u8TimerID].TIMER_RestTime = 0;
			Timer_base[copy_u8TimerID].TIMER_Preload = 0;
			Timer_base[copy_u8TimerID].ptr_callback_t = NULL;
			// Raise the occupation flag
			Timerx_occupation_flag[copy_u8TimerID] = TIMER_Delay_mS;
			// Calculate number of ticks
			f64 clc_NO_Tics = ((f64)copy_DelayTime_mS * Mills_to_Nano) / Mills_TickTime;
			// Calulate the rest of the nano second
			Timer_base[copy_u8TimerID].TIMER_RestTime = ((copy_DelayTime_mS * Mills_to_Nano) - ((u32)clc_NO_Tics * Mills_TickTime));
			// Caculate the preload value
			Timer_base[copy_u8TimerID].TIMER_Preload = (OVF_MAX - ((u32)clc_NO_Tics % OVF_MAX));
			// Calulate the number of OVF
			Timer_base[copy_u8TimerID].TIMER_OVF = (Timer_base[copy_u8TimerID].TIMER_Preload != 0) ? (((u32)clc_NO_Tics / OVF_MAX) + 1) : ((u32)clc_NO_Tics / OVF_MAX);
			// Set parameters for callback
			Timer_base[copy_u8TimerID].ptr_callback_t = ptr_callback;
			if(copy_u8TimerID == TIMER0ID){
				// Set preload value
				TIMER0_TCNT = Timer_base[copy_u8TimerID].TIMER_Preload;
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
				TIMER2_TCNT = Timer_base[copy_u8TimerID].TIMER_Preload;
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
			Timer_base[copy_u8TimerID].TIMER_OVF = 0;
			Timer_base[copy_u8TimerID].TIMER_RestTime = 0;
			Timer_base[copy_u8TimerID].TIMER_Preload = 0;
			Timer_base[copy_u8TimerID].ptr_callback_t = NULL;
			// Raise the occupation flag
			Timerx_occupation_flag[copy_u8TimerID] = TIMER_Delay_uS;
			// Caculate the preload value
			Timer_base[copy_u8TimerID].TIMER_Preload = (OVF_MAX - (copy_DelayTime_uS % OVF_MAX));
			// Calulate the number of OVF
			Timer_base[copy_u8TimerID].TIMER_OVF = (Timer_base[copy_u8TimerID].TIMER_Preload != 0) ? ((copy_DelayTime_uS / OVF_MAX) + 1) : (copy_DelayTime_uS / OVF_MAX);
			// Set parameters for callback
			Timer_base[copy_u8TimerID].ptr_callback_t = ptr_callback;
			if(copy_u8TimerID == TIMER0ID){
				// Set preload value
				TIMER0_TCNT = Timer_base[copy_u8TimerID].TIMER_Preload;
				// Enable intrrupt
				TIMER_TIMSK &= TIMER0_TIMSK_Reset;
				TIMER_TIMSK |= TIMER_ENABLE;
				// Enable Global Interrupt
				TIMER_SREG |= TIMER_ENABLE << TIMER_Glob_Init_bit;
				// Reset timer configurations
				TIMER0_TCCR = TIMER_TCCR_Reset;
				// Set Prescaller to 8, confguration to (WGM: Normal, COM: Normal)
				TIMER0_TCCR |= TIMER_8PRE;
			}
			else{
				// Set preload value
				TIMER2_TCNT = Timer_base[copy_u8TimerID].TIMER_Preload;
				// Enable intrrupt
				TIMER_TIMSK &= TIMER2_TIMSK_Reset;
				TIMER_TIMSK |= TIMER_ENABLE << TIMER_TOIE2;
				// Enable Global Interrupt
				TIMER_SREG |= TIMER_ENABLE << TIMER_Glob_Init_bit;
				// Reset timer configurations
				TIMER2_TCCR = TIMER_TCCR_Reset;
				// Set Prescaller to 8, confguration to (WGM: Normal, COM: Normal)
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
	if((--(Timer_base[copy_u8TimerID].TIMER_OVF)) == 0){
		// Check the rest time in uS in case of mS delay if zero ther total delay is finished
		if((Timer_base[copy_u8TimerID].TIMER_RestTime) == 0){
			// Clear the ossupation flag
			Timerx_occupation_flag[copy_u8TimerID] = TIMER_Clear;
			// Call the function
			(Timer_base[copy_u8TimerID].ptr_callback_t)();
			// Clear timer data
			TIMERx_vClear(copy_u8TimerID);
		}
		// In case of false continue the delay in uS
		else{
			// Clear the ossupation flag
			Timerx_occupation_flag[copy_u8TimerID] = TIMER_Clear;
			// Call the uS delay function
			TIMER_u8Delay_uS(copy_u8TimerID, (Timer_base[copy_u8TimerID].TIMER_RestTime), (Timer_base[copy_u8TimerID].ptr_callback_t));
		}
	}
	// In case of false then decrement the OVF counter and continue
	else{

	}
}


/* Periodic functions decleration */
u8 TIMER_u8CreatePeriodicTask(u8 copy_u8TimerID, u16 copy_TimePeriod_mS, void (*ptr_callback)(void) ){
	/*
	 *
	 */
	if((copy_u8TimerID <= TIMER1ID) && (copy_TimePeriod_mS >= MIN_TIME) && (copy_TimePeriod_mS <= MAX_TIME) && (Timerx_occupation_flag[copy_u8TimerID] == TIMER_Clear)){
		if(copy_u8TimerID != TIMER1ID){
			Timer_base[copy_u8TimerID].TIMER_OVF = 0;
			Timer_base[copy_u8TimerID].TIMER_RestTime = 0;
			Timer_base[copy_u8TimerID].TIMER_Preload = 0;
			Timer_base[copy_u8TimerID].ptr_callback_t = NULL;
			// set timer flag to the assign task
			Timerx_occupation_flag[copy_u8TimerID] = TIMER_Ptask;
			// Calculate number of ticks
			f64 clc_NO_Tics = ((f64)copy_TimePeriod_mS * Mills_to_Nano) / Mills_TickTime;
			// Calulate the rest of the nano second
			Timer_base[copy_u8TimerID].TIMER_RestTime = ((copy_TimePeriod_mS * Mills_to_Nano) - ((u32)clc_NO_Tics * Mills_TickTime));
			// Caculate the preload value
			Timer_base[copy_u8TimerID].TIMER_Preload = (OVF_MAX - ((u32)clc_NO_Tics % OVF_MAX));
			// Calulate the number of OVF
			Timer_base[copy_u8TimerID].TIMER_OVF = (Timer_base[copy_u8TimerID].TIMER_Preload != 0) ? (((u32)clc_NO_Tics / OVF_MAX) + 1) : ((u32)clc_NO_Tics / OVF_MAX);
			// Set parameters for callback
			Timer_base[copy_u8TimerID].ptr_callback_t = ptr_callback;
			if(copy_u8TimerID == TIMER0ID){
				// Set preload value
				TIMER0_TCNT = Timer_base[copy_u8TimerID].TIMER_Preload;
				TIMER_TIMSK &= TIMER0_TIMSK_Reset;
				TIMER_TIMSK |= TIMER_ENABLE;
				// Enable Global Interrupt
				TIMER_SREG |= TIMER_ENABLE << TIMER_Glob_Init_bit;
				// Reset timer configurations
				TIMER0_TCCR = TIMER_TCCR_Reset;
				// Set Prescaller to 1024, confguration to (WGM: Normal, COM: Normal)
				TIMER0_TCCR |= TIMER_1024PRE;
			}
			else{
				// Set preload value
				TIMER2_TCNT = Timer_base[copy_u8TimerID].TIMER_Preload;
				TIMER_TIMSK &= TIMER2_TIMSK_Reset;
				TIMER_TIMSK |= TIMER_ENABLE;
				// Enable Global Interrupt
				TIMER_SREG |= TIMER_ENABLE << TIMER_Glob_Init_bit;
				// Reset timer configurations
				TIMER2_TCCR = TIMER_TCCR_Reset;
				// Set Prescaller to 1024, confguration to (WGM: Normal, COM: Normal)
				TIMER2_TCCR |= TIMER2_1024PRE;
			}

		}
	}
	return 0;
}

u8 TIMER_u8deletePeriodicTask(u8 copy_u8TimerID){
	/*
	 *
	 */
	// Chack data validity if not valid return fail code
	if((copy_u8TimerID <= TIMER1ID) && (Timerx_occupation_flag[copy_u8TimerID] == TIMER_Ptask)){
		if(copy_u8TimerID == TIMER0ID){
			// Clear timer data
			Timer_base[copy_u8TimerID].TIMER_OVF = 0;
			Timer_base[copy_u8TimerID].TIMER_RestTime = 0;
			Timer_base[copy_u8TimerID].TIMER_Preload = 0;
			Timer_base[copy_u8TimerID].ptr_callback_t = NULL;
			// Reset timer configurations
			TIMER0_TCCR = TIMER_TCCR_Reset;
		}
		else if(copy_u8TimerID == TIMER1ID){

		}
		else{
			// Clear timer data
			Timer_base[copy_u8TimerID].TIMER_OVF = 0;
			Timer_base[copy_u8TimerID].TIMER_RestTime = 0;
			Timer_base[copy_u8TimerID].TIMER_Preload = 0;
			Timer_base[copy_u8TimerID].ptr_callback_t = NULL;
			// Reset timer configurations
			TIMER2_TCCR = TIMER_TCCR_Reset;
		}
		// Disable timer interrupt
		TIMERx_vClear(copy_u8TimerID);
		// return success code
		return 1;
	}
	else{
		// return fail code
		return 0;
	}
}


void TIMER_vPtask_Callback(u8 copy_u8TimerID){
	/*
	 *
	 */
	// Create a alocal variable to count number of overflows
	static u16 OVF_counter = 0;
	// Check if the target number of overflows is reached
	if(++OVF_counter == Timer_base[copy_u8TimerID].TIMER_OVF){
		if(copy_u8TimerID == TIMER0ID){
			// stop the timer
			TIMER0_TCCR = TIMER_TCCR_Reset;
			// feed the rest time to the counter
			TIMER0_TCNT = (OVF_MAX - Timer_base[copy_u8TimerID].TIMER_RestTime);
			// Set Prescaller to 8, confguration to (WGM: Normal, COM: Normal)
			TIMER0_TCCR |= TIMER_8PRE;
		}
		else if(copy_u8TimerID == TIMER1ID){
			// feed the rest time to the counter

			// change the prescaled value to uS

		}
		else{
			// stop the timer
			TIMER2_TCCR = TIMER_TCCR_Reset;
			// feed the rest time to the counter
			TIMER2_TCNT = (OVF_MAX - Timer_base[copy_u8TimerID].TIMER_RestTime);
			// Set Prescaller to 8, confguration to (WGM: Normal, COM: Normal)
			TIMER2_TCCR |= TIMER2_8PRE;
		}
	}
	else if(OVF_counter > Timer_base[copy_u8TimerID].TIMER_OVF){
		if(copy_u8TimerID == TIMER0ID){
			// stop the timer
			TIMER0_TCCR = TIMER_TCCR_Reset;
			// call the periodic function
			Timer_base[copy_u8TimerID].ptr_callback_t();
			// feed the preload value
			TIMER0_TCNT = Timer_base[copy_u8TimerID].TIMER_Preload;
			// Set Prescaller to 1024, confguration to (WGM: Normal, COM: Normal)
			TIMER0_TCCR |= TIMER_1024PRE;
			// clear the OVF counter
			OVF_counter = 0;
		}
		else if(copy_u8TimerID == TIMER1ID){
			// stop the timer

			// call the periodic function

			// feed the preload value

			// Set Prescaller to 1024, confguration to (WGM: Normal, COM: Normal)

			// clear the OVF counter
		}
		else{
			// stop the timer
			TIMER2_TCCR = TIMER_TCCR_Reset;
			// call the periodic function
			Timer_base[copy_u8TimerID].ptr_callback_t();
			// feed the preload value
			TIMER2_TCNT = Timer_base[copy_u8TimerID].TIMER_Preload;
			// Set Prescaller to 1024, confguration to (WGM: Normal, COM: Normal)
			TIMER2_TCCR |= TIMER2_1024PRE;
			// clear the OVF counter
			OVF_counter = 0;
		}
	}
	// Incase of not equal then increment and continue
	else{
	}
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
		case TIMER_Ptask:

			TIMER_vPtask_Callback(TIMER0ID);
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

// ISR of Timer/Counter1 Input capture unit
void __vector_6(void){
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
		case TIMER_Ptask:
			TIMER_vPtask_Callback(TIMER2ID);
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
