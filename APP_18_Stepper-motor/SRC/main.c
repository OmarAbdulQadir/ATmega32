/*
 * main.c
 *
 *  Created on: May 31, 2023
 *      Author: Omar A.Qadir
 */



#include "../../LIB/STD_TYPES.h"
#include "../../Drivers/HAL/ST_Motor/ST_Motor_interface.h"

#define PORTD 3
#define B0 0
#define B1 1
#define B2 2
#define B3 3
#define Mode 3
#define Start_step 0
#define freq 31

int main(void){
	//setup section

	stepper_struct mystepper= {PORTD, B0, B1, B2, B3, Mode, Start_step, freq};
	st_mot_void_init(&mystepper);

	//loop section
	while(1){
		st_mot_void_steps_CCW(&mystepper, 1);
	}
	return 0;
}
