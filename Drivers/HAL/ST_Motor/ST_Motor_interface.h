/*******************************************************************/
/***               Date: 02/6/2023	Day: Thursday                ***/
/***	Stepper-Motor driver for the microcontroller ATMega 32   ***/
/***    	 Created By: Omar Abdul Qadir	 Version= 1.0		 ***/
/*******************************************************************/
/***         Note: All the data in the file is readable,         ***/
/***     And any editing will affect the controller's behavior,  ***/
/***          So It's not recommended to edit any data,          ***/
/***   Unless you are sure of what is the effect on behaviors.   ***/
/*******************************************************************/


#ifndef ST_Motor_INTERFACE_H
#define ST_Motor_INTERFACE_H

	/* Stepper motor struct definition */
	typedef struct{
	u8 port: 2;		// Motor connection port
	u8 coil1: 3;	// Coil 1 connection port
	u8 coil2: 3;	// Coil 2 connection port
	u8 coil3: 3;	// Coil 3 connection port
	u8 coil4: 3;	// Coil 4 connection port
	u8 mode: 2;		// Stepping mode
	u8 step: 3;		// Current step of the motor initally given 0, and only the program access it
	u8 speed: 5;	// Rotaion speed of the motor
	}stepper_struct;
	
	/* Macros definition */
	// Speed parameter of the stepper motor
	#define freq_prescaler 0

	//stepper modes:: 0: single coil, 1: douple coil, 2,3: half step
	//speed from 0 - 31 >> delay time between steps= prescaler - (speed*10) : under condition of at least t(min) = 10ms

	/* Global functions Decleration */
	// Initiate the stepper configuraions
	void st_mot_void_init(stepper_struct* );
	// Stop all motor pins
	void st_mot_stop(stepper_struct* );
	// move given number of steps clock wise
	void st_mot_void_steps_CW(stepper_struct*, u8 );
	// move given number of steps counter clock wise
	void st_mot_void_steps_CCW(stepper_struct*, u8 );
	// move given angle clock wise
	
	// move given angle counter clock wise


#endif	//end ST_Motor_INTERFACE_H
