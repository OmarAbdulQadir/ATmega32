/*
 * RTOS.h
 *
 *  Created on: Jul 7, 2023
 *      Author: Omar A.Qadir
 */

#ifndef INC_RTOS_H_
#define INC_RTOS_H_

	typedef struct{
		u8 task_periodicety;
		void (*task_callback_ptr)(void);
	}Task;

	#define no_tasks	3

	void create_task(u8 copy_task_periodicety, void(*copy_callback_ptr)(void));
	void scheduler(void );

#endif /* INC_RTOS_H_ */
