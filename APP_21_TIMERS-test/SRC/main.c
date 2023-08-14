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
#include "../../Drivers/HAL/LCD/LCD_interface.h"


// Functions declerations
void lde_toggle_1(void);
void lde_toggle_2(void);

// Global variable
u32 counter_value = 0;
u8 flag = 0;

// Main function
int main(void){
	// Setup section

	//TIMER_u8CounterStart(TIMER0ID, TIMER_8PRE, &counter_value);
	LCD_init();
	//TIMER_u8CounterStop(TIMER0ID);

	DIO_void_set_pin_dir(DIO_REF_PORTA, B1, OUTPUT);
	DIO_void_clear_pin(DIO_REF_PORTA, B1);

	DIO_void_set_pin_dir(DIO_REF_PORTA, B2, OUTPUT);
	DIO_void_clear_pin(DIO_REF_PORTA, B1);

	//_delay_ms(5000);

	//TIMER_u8Delay_mS(TIMER2ID, 250, lde_toggle_2);
	//TIMER_u8Delay_uS(TIMER0ID, 60000, lde_toggle_1);


	//TIMER_u8CreatePeriodicTask(TIMER2ID, 100, lde_toggle_1);

	DIO_void_assign_pin(DIO_REF_PORTA, B2, TIMER_u8FastPWM(TIMER0ID, TIMER_64PRE, 50));


	while(1){
		// Loop section
	}
	return 0;
}

void lde_toggle_1(void){
	if(flag == 0){
		flag = 1;
		//TIMER_u8CounterStop(TIMER0ID);
		DIO_void_toggle_pin(DIO_REF_PORTA, B1);
	}
	else{
		TIMER_u8deletePeriodicTask(TIMER2ID);
		LCD_write_s32_number(counter_value);
	}
}

void lde_toggle_2(void){
	//DIO_void_toggle_pin(DIO_REF_PORTA, B1);
	//TIMER_u8deletePeriodicTask(TIMER2ID);
	//LCD_write_s32_number(counter_value);
	TIMER_u8StopPWM(TIMER0ID);
}

