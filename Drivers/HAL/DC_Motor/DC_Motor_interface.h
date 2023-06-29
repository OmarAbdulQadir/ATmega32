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


#ifndef DC_Motor_INTERFACE_H
#define DC_Motor_INTERFACE_H


	/* DC motor struct definition */
	typedef struct{
		u8 PORT : 2;		// Connection Port
		u8 forward_pin : 3;	// Connection forward pin
		u8 reverse_pin : 3;	// Connection reverse pin
		u8 speed;			// motor speed 0~255
	}MotorX_struct;

	/* Global function decleration */
	// Motor initiation
	void DC_Motor_void_init(MotorX_struct* );
	// Motor start rotating in clock wise in full speed
	void DC_motor_void_CW_full_speed(MotorX_struct* );
	// Motor start rotation in counter clock wise in full speed
	void DC_motor_void_CCW_full_speed(MotorX_struct* );
	// Motor stop
	void DC_motor_void_stop(MotorX_struct* );
	// Motor start rotating in clock wise in selected speed
	void DC_motor_void_CW(MotorX_struct* );
	// Motor start rotation in counter clock wise in selected speed
	void DC_motor_void_CCW(MotorX_struct* );

#endif	//end DC_Motor_INTERFACE_H
