/*
 * main.c
 *
 *  Created on: Jun 9, 2023
 *      Author: Omar A.Qadir
 */


// Standard libraries
//#include <util/delay.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

// Drivers section
#include "../../Drivers/MCAL/DIO/DIO_interface.h"
#include "../../Drivers/MCAL/TIMER/TIMER_interface.h"

// Functions declerations
void lde_toggle_1(void);
void lde_toggle_2(void);

// Global variable


// Main function
int main(void){
	// Setup section

	DIO_void_set_pin_dir(DIO_REF_PORTA, B1, OUTPUT);
	DIO_void_set_pin(DIO_REF_PORTA, B1);

	DIO_void_set_pin_dir(DIO_REF_PORTA, B2, OUTPUT);
	DIO_void_set_pin(DIO_REF_PORTA, B2);


	DIO_void_set_pin_dir(DIO_REF_PORTB, B3, OUTPUT);
	//DIO_void_clear_pin(PORTB, B3);

	DIO_void_set_pin_dir(DIO_REF_PORTD, B7, OUTPUT);
	//DIO_void_set_pin(PORTD, B7);

	// Ttick= 8/8000000= 1us
	// Tocf= 1*256= 256us
	// no. ovf for 1 sec=

	u8 timer_preload[2]= {0, 150};
	timer_config temp_timer_config0={ref_TIMER0_WGM_CTC, ref_TIMER_COM_tgl, TIMER_8PRE, timer_preload};
	TIMER_set_callback(ref_TIMER0_COMP, lde_toggle_1);


	timer_config temp_timer_config1={ref_TIMER2_WGM_CTC, ref_TIMER_COM_tgl, TIMER2_8PRE, timer_preload};
	TIMER_set_callback(ref_TIMER2_COMP, lde_toggle_2);


	TIMER_init(&temp_timer_config0);
	TIMER_config();

	TIMER_init(&temp_timer_config1);
	TIMER_config();

/*
 * control the buzzer frequency using timer and adc
 */

	while(1){
		// Loop section

	}
	return 0;
}
void lde_toggle_1(void){
	static u8 ovf_counter= 0;
	if(ovf_counter == 4){
		DIO_void_toggle_pin(DIO_REF_PORTA, B1);
		ovf_counter= 0;
	}
	else{
		ovf_counter++;
	}
}

void lde_toggle_2(void){
	static u8 ovf_counter= 0;
	if(ovf_counter == 4){
		DIO_void_toggle_pin(DIO_REF_PORTA, B2);
		ovf_counter= 0;
	}
	else{
		ovf_counter++;
	}
}
