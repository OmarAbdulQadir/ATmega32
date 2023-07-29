/*
 * main.c
 *
 *  Created on: Jul 7, 2023
 *      Author: Omar A.Qadir
 */


// STD libraries section
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

// Drivers sections
#include "../../Drivers/MCAL/DIO/DIO_interface.h"
#include "../../Drivers/MCAL/TIMER/TIMER_interface.h"
#include "../INC/RTOS.h"

// Macros section


// Functions declerations
void timer_count_OVF_callback(void );
void init_tasks(void );
void Task1(void );
void Task2(void );
void Task3(void );

// Global variables section
u8 tick_count= 0;

// Main function
int main(void ){
	// Setup section

	init_tasks();

	u8 preload_timer0_val[] = {192, 0};
	timer_config timer0_config_1sec = {
		ref_TIMER0_WGM_NORM,
		ref_TIMER_COM_NORM,
		TIMER_8PRE,
		preload_timer0_val
	};

	TIMER_init(&timer0_config_1sec);
	TIMER_set_callback(ref_TIMER0_OVF, timer_count_OVF_callback);
	TIMER_config();

	while(1){
		// Loop section
	}
	return 0;
}


// Functions implementation
void timer_count_OVF_callback(void ){
	static u16 OVF_counter = 0;
	if (OVF_counter == 3907){
		TIMER_config();
		OVF_counter = 0;
		tick_count++;
		scheduler();
		DIO_void_toggle_pin(DIO_REF_PORTC, B3);
	}
	else{
		OVF_counter ++;
	}
}


void init_tasks(void ){
	create_task(1, Task1);
	create_task(2, Task2);
	create_task(3, Task3);

	DIO_void_set_pin_dir(DIO_REF_PORTC, B0, OUTPUT);
	DIO_void_clear_pin(DIO_REF_PORTC, B0);
	DIO_void_set_pin_dir(DIO_REF_PORTC, B1, OUTPUT);
	DIO_void_clear_pin(DIO_REF_PORTC, B1);
	DIO_void_set_pin_dir(DIO_REF_PORTC, B2, OUTPUT);
	DIO_void_clear_pin(DIO_REF_PORTC, B2);
	DIO_void_set_pin_dir(DIO_REF_PORTC, B3, OUTPUT);
	DIO_void_clear_pin(DIO_REF_PORTC, B3);
}


void Task1(void ){
	DIO_void_toggle_pin(DIO_REF_PORTC, B0);
}


void Task2(void ){
	DIO_void_toggle_pin(DIO_REF_PORTC, B1);
}


void Task3(void ){
	DIO_void_toggle_pin(DIO_REF_PORTC, B2);
}
