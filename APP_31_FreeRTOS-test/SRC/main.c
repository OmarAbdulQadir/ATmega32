/*
 * main.c
 *
 *  Created on: Jul 8, 2023
 *      Author: Omar A.Qadir
 */


// Standard libraries section
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

// Drivers section
#include "../../Drivers/MCAL/DIO/DIO_interface.h"

// Free RTOS section
#include "../../FreeRTOS/FreeRTOS.h"
#include "../../FreeRTOS/task.h"


// Macros section



// Functions declerations
void Task1(void *);
void Task2(void *);
void Task3(void *);


// Global variables section


// main function
int main(void ){
	// setup section

	xTaskCreate(Task1, "LED_1", 85, NULL, 1, NULL);
	xTaskCreate(Task2, "LED_2", 85, NULL, 1, NULL);
	xTaskCreate(Task3, "LED_3", 85, NULL, 1, NULL);
	vTaskStartScheduler();


	while (1){
		// Loop section

	}
	return 0;
}


void Task1(void * pvParameters){
	/*
	 *
	 */
	DIO_void_set_pin_dir(DIO_REF_PORTA, B1, OUTPUT);
	DIO_void_clear_pin(DIO_REF_PORTA, B1);
	while(1){
		DIO_void_toggle_pin(DIO_REF_PORTA, B1);
		vTaskDelay(1000);
	}
}


void Task2(void * pvParameters){
	/*
	 *
	 */
	DIO_void_set_pin_dir(DIO_REF_PORTA, B2, OUTPUT);
	DIO_void_clear_pin(DIO_REF_PORTA, B2);
	while(1){
		DIO_void_toggle_pin(DIO_REF_PORTA, B2);
		vTaskDelay(2000);
	}
}


void Task3(void * pvParameters){
	/*
	 *
	 */
	DIO_void_set_pin_dir(DIO_REF_PORTA, B3, OUTPUT);
	DIO_void_clear_pin(DIO_REF_PORTA, B3);
	while(1){
		DIO_void_toggle_pin(DIO_REF_PORTA, B3);
		vTaskDelay(3000);
	}
}
