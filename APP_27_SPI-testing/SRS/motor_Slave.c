/*
 * motor.c
 *
 *  Created on: Jun 24, 2023
 *      Author: Omar A.Qadir
 */

// Libraries section
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

// Private libraries section
#include "../INC/motor_Slave.h"

// Drivers Section
#include "../../Drivers/MCAL/DIO/DIO_interface.h"
#include "../../Drivers/HAL/DC_Motor/DC_Motor_interface.h"



// Motor initiation
MotorX_struct fan_motor= {PORTD, B2, B3, 100};
static u8 motor_state;

void motor_slave_init(void){
	DC_Motor_void_init(&fan_motor);
	DC_motor_void_stop(&fan_motor);
}

void update_motor(u8 copy_recived_val){
	if((copy_recived_val == 'H') && (motor_state == 0)){
		DC_motor_void_CW_full_speed(&fan_motor);
		motor_state = 1;
	}
	else if((copy_recived_val == 'L')  && (motor_state == 1)){
		DC_motor_void_stop(&fan_motor);
		motor_state = 0;
	}
}
