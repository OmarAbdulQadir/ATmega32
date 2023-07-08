/*
 * main.c
 *
 *  Created on: Jul 8, 2023
 *      Author: Omar A.Qadir
 */


// Standard libraries
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

// Drivers section
#include "../../Drivers/MCAL/DIO/DIO_interface.h"

// FreeRTOS section
#include "../../FreeRTOS/FreeRTOS.h"
#include "../../FreeRTOS/task.h"
#include "../../FreeRTOS/semphr.h"


// Macros section


// Functions decleration
void task_1(void *);
void task_2(void *);

// Global variables
SemaphoreHandle_t x_sem;

// Main functions
int main(void ){
	// Setup section

	vSemaphoreCreateBinary(x_sem);
	xTaskCreate(task_1, "button", 85, NULL, 2, NULL);
	xTaskCreate(task_2, "Led", 85, NULL, 1, NULL);
	vTaskStartScheduler();

	while(1){
		// Loop section
	}
	return 0;
}

// Functions implementation
void task_1(void * pvParameners){
	/*
	 *
	 */
	DIO_void_set_pin_in_pullUP(DIO_REF_PORTC, B0);
	xSemaphoreTake(x_sem, 10);
	while(1){
		if(DIO_u8_get_pin(DIO_REF_PORTC, B0) == 0){
			while(DIO_u8_get_pin(DIO_REF_PORTC, B0) == 0);
			xSemaphoreGive(x_sem);
		}
		vTaskDelay(200);
	}
}

void task_2(void * pvParameners){
	/*
	 *
	 */
	DIO_void_set_pin_dir(DIO_REF_PORTC, B1, OUTPUT);
	DIO_void_clear_pin(DIO_REF_PORTC, B1);
	while(1){
		if(xSemaphoreTake(x_sem, 10) == pdPASS){
			DIO_void_toggle_pin(DIO_REF_PORTC, B1);
		}
	}
}
