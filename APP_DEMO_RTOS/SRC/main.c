/*
 * main.c
 *
 *  Created on: Sep 16, 2023
 *      Author: Omar A.Qadir
 */



// Standard libraries section
#include <util/delay.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

// Drivers section
#include "../../Drivers/MCAL/DIO/DIO_interface.h"

// Free RTOS section
#include "../../FreeRTOS/FreeRTOS.h"
#include "../../FreeRTOS/task.h"
#include "../../FreeRTOS/semphr.h"

// Functions declerations
void Task1(void *);
void Task2(void *);
void Task3(void *);

// Global variables
SemaphoreHandle_t x_sem;

int main( void )
{
	// Setup section
	DIO_void_set_pin_dir(DIO_REF_PORTA, B1, OUTPUT);
	DIO_void_set_pin_dir(DIO_REF_PORTA, B2, OUTPUT);
	DIO_void_set_pin_dir(DIO_REF_PORTA, B3, OUTPUT);

	x_sem = xSemaphoreCreateMutex();
	xSemaphoreGive(x_sem);

	xTaskCreate(Task1, "LED_1", 85, NULL, 1, NULL);

	vTaskStartScheduler();

	while( 1 )
	{
		// Super loop

	}
	return 0;
}


void Task3 ( void * TaskParameter)
{
	// Setup section
	DIO_void_set_pin(DIO_REF_PORTA, B1);

	_delay_ms(1000);

	DIO_void_clear_pin(DIO_REF_PORTA, B1);

	while ( 1 )
	{
		// Super loop
		if(xSemaphoreTake(x_sem, portMAX_DELAY) == pdPASS)
		{
			DIO_void_set_pin(DIO_REF_PORTA, B1);
			while(1);
		}
		else
		{
			vTaskDelay(5);
		}
	}
}


void Task2 ( void * TaskParameter)
{
	// Setup section
	DIO_void_set_pin(DIO_REF_PORTA, B2);

	_delay_ms(1000);

	DIO_void_clear_pin(DIO_REF_PORTA, B2);

	while ( 1 )
	{
		// Super loop
		vTaskDelay(5000);
	}
}


void Task1 ( void * TaskParameter)
{
	// Setup section
	DIO_void_set_pin(DIO_REF_PORTA, B3);

	_delay_ms(1000);

	DIO_void_clear_pin(DIO_REF_PORTA, B3);

	while ( 1 )
	{
		// Super loop
		if(xSemaphoreTake(x_sem, portMAX_DELAY) == pdPASS)
		{
			xTaskCreate(Task3, "LED_3", 85, NULL, 3, NULL);
			xTaskCreate(Task2, "LED_2", 85, NULL, 2, NULL);
			xSemaphoreGive(x_sem);
		}
	}
}
