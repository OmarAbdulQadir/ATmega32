/*
 * RTOS.c
 *
 *  Created on: Jul 7, 2023
 *      Author: Omar A.Qadir
 */

// STD Library section
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

// Includes
#include "../INC/RTOS.h"

// Global variables
static Task task_arr[no_tasks];
static u8 Task_count= 0;
extern u8 tick_count;

void create_task(u8 copy_task_periodicety, void(*copy_callback_ptr)(void)){
	/*
	 *
	 */
	if(Task_count < no_tasks){
		task_arr[Task_count].task_periodicety = copy_task_periodicety;
		task_arr[Task_count].task_callback_ptr = copy_callback_ptr;
		Task_count++;
	}
}


void scheduler(void ){
	/*
	 *
	 */
	for(u8 i= 0; i < no_tasks; i++){
		if((tick_count % (task_arr[i].task_periodicety)) == 0){
			task_arr[i].task_callback_ptr();
		}
	}
}
