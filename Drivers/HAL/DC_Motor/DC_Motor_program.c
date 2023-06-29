/*******************************************************************/
/***               Date: 20/5/2023	Day: Saturday                ***/
/***	  DC-Motor driver for the microcontroller ATMega 32      ***/
/***    	 Created By: Omar Abdul Qadir	 Version= 1.0		 ***/
/*******************************************************************/
/***         Note: All the data in the file is readable,         ***/
/***     And any editing will affect the controller's behavior,  ***/
/***          So It's not recommended to edit any data,          ***/
/***   Unless you are sure of what is the effect on behaviors.   ***/
/*******************************************************************/

//Standard libraries Section
#include "../../../LIB/BIT_MATH.h"
#include "../../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"

//Private libraries Section
#include "DC_Motor_interface.h"

//Global variables


/* Implementing of the driver functions */
void DC_Motor_void_init(MotorX_struct* Motor){
	/*
	 *	Function is to initiate the motor pins configuration.
	 *	Input::
	 *			MotorX >> pointer to motor struct is passed to get its pins and port.
	 *					  Its ok to use mutimotors but its necessary to initiate each motor first.
	 *
	 *	No return from the function.
	 */
	// Configure the motor pin direction to output
	DIO_void_set_pin_dir((Motor->PORT), (Motor->forward_pin), OUTPUT);
	DIO_void_set_pin_dir((Motor->PORT), (Motor->reverse_pin), OUTPUT);
	
	// Set the initial value of the motor pins as LOW
	DIO_void_clear_pin((Motor->PORT), (Motor->forward_pin));
	DIO_void_clear_pin((Motor->PORT), (Motor->reverse_pin));
}

void DC_motor_void_CW_full_speed(MotorX_struct* Motor){
	/*
	 *	Function is to rotate the motor constantly in clock wise direction in full speed.
	 *	Inpupt::
	 *			MotorX >> pointer to motor struct is passed to get its pins and port.
	 *					  Its ok to use mutimotors but its necessary to initiate each motor first.
	 *
	 *	No return from the function.
	 *	Function rotate the motor in Clock wise direction, but sometimes the rotation direction is reversed
	 *	The best recommended solution is to swich the motor pins in the struct.
	 */
	// Set the reverse pin to LOW
	DIO_void_clear_pin((Motor->PORT), (Motor->reverse_pin));
	// Set the forward pin to HIGH
	DIO_void_set_pin((Motor->PORT), (Motor->forward_pin));
}

void DC_motor_void_CCW_full_speed(MotorX_struct* Motor){
	/*
	 *	Function is to rotate the motor constantly in counter clock wise direction in full speed.
	 *	Inpupt::
	 *			MotorX >> pointer to motor struct is passed to get its pins and port.
	 *					  Its ok to use mutimotors but its necessary to initiate each motor first.
	 *
	 *	No return from the function.
	 *	Function rotate the motor in counter Clock wise direction, but sometimes the rotation direction is reversed
	 *	The best recommended solution is to swich the motor pins in the struct.
	 */
	// Set the forward pin to LOW
	DIO_void_clear_pin((Motor->PORT), (Motor->forward_pin));
	// Set the forward pin to HIGH
	DIO_void_set_pin((Motor->PORT), (Motor->reverse_pin));
}

void DC_motor_void_stop(MotorX_struct* Motor){
	/*
	 *	Function is to electrically break the motor.
	 *	Inpupt::
	 *			MotorX >> pointer to motor struct is passed to get its pins and port.
	 *					  Its ok to use mutimotors but its necessary to initiate each motor first.
	 *
	 *	No return from the function.
	 *	In theory is the two poles of the motor is connected to the same voltage (no drop voltage on the motor's coil)
	 *	the motor will generate zero torue, however if we connect the poles of the motor to power, it breakes and that
	 *	is caused by the motor coil opposing any change that may lead to current generation.
	 */
	// Set both forward and reverse pins to LOW
	DIO_void_set_pin((Motor->PORT), (Motor->forward_pin));
	DIO_void_set_pin((Motor->PORT), (Motor->reverse_pin));
}

void DC_motor_void_CW(MotorX_struct* Motor){
	/*
	 *
	 */
}
void DC_motor_void_CCW(MotorX_struct* Motor){
	/*
	 *
	 */
}
