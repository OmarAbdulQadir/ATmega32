/*
 * main.c
 *
 *  Created on: May 20, 2023
 *      Author: Omar A.Qadir
 */


#include <util/delay.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../Drivers/MCAL/DIO/DIO_interface.h"
#include "../../Drivers/HAL/DC_Motor/DC_Motor_interface.h"

#define forward_pin B0
#define reverse_pin B1
#define forward_sw B2
#define reverse_sw B3
#define sw_port PORTA

int main(void){

	DIO_void_set_pin_in_pullUP(sw_port, forward_sw);
	DIO_void_set_pin_in_pullUP(sw_port, reverse_sw);

	MotorX_struct motor1= {PORTA, forward_pin, reverse_pin, 100};
	MotorX_struct motor2= {PORTB, forward_pin, reverse_pin, 100};
	DC_Motor_void_init(&motor1);
	DC_Motor_void_init(&motor2);


	while(1){
		/*
		DC_motor_void_forward_full_speed(&motor1);
		_delay_ms(2500);
		DC_motor_void_stop(&motor1);
		_delay_ms(500);
		DC_motor_void_reverse_full_speed(&motor1);
		_delay_ms(2500);
		DC_motor_void_stop(&motor1);
		_delay_ms(500);
		*/


		u8 forward_sw_val = DIO_u8_get_pin(sw_port, forward_sw);
		u8 reverse_sw_val = DIO_u8_get_pin(sw_port, reverse_sw);

		if((forward_sw_val == LOW) && (reverse_sw_val == HIGH)){
			DC_motor_void_CW_full_speed(&motor1);
			DC_motor_void_CW_full_speed(&motor2);
		}
		else if((forward_sw_val == HIGH) && (reverse_sw_val == LOW)){
			DC_motor_void_CCW_full_speed(&motor1);
			DC_motor_void_CCW_full_speed(&motor2);
		}
		else{
			DC_motor_void_stop(&motor1);
			DC_motor_void_stop(&motor2);
		}
	}
	return 0;
}
