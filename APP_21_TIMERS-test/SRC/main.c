	/*
 * main.c
 *
 *  Created on: Jun 9, 2023
 *      Author: Omar A.Qadir
 */


// Standard libraries
#include <util/delay.h>
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
	DIO_void_clear_pin(DIO_REF_PORTA, B1);

	DIO_void_set_pin_dir(DIO_REF_PORTA, B2, OUTPUT);
	DIO_void_clear_pin(DIO_REF_PORTA, B2);

	//_delay_ms(5000);

	TIMER_u8Delay_mS(TIMER2ID, 5000, lde_toggle_2);
	//TIMER_u8Delay_uS(TIMER0ID, 60000, lde_toggle_1);

	TIMER_u8CreatePeriodicTask(TIMER0ID, 100, lde_toggle_1);

	while(1){
		// Loop section
	}
	return 0;
}

void lde_toggle_1(void){
	DIO_void_toggle_pin(DIO_REF_PORTA, B1);
}

void lde_toggle_2(void){
	//DIO_void_toggle_pin(DIO_REF_PORTA, B1);
	TIMER_u8deletePeriodicTask(TIMER0ID);
}

