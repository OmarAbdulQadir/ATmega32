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


#ifndef V_DC_sensor_INTERFACE_H
#define V_DC_sensor_INTERFACE_H

	/* Voltage configurations */
	#define Volt_ref			5
	/* Depends on the number of stages gain = s^no_stages */
	#define Stage_gain			4

	/* Number of reading iterations*/
	#define Vsensor_Acc			10

	/* Initiate the sensor through a given ADC channel */
	void Vsensor_voidInit(u8 );
	/* start calculation and return the voltage value*/
	f64 Vsensor_voidClcVolt(void );

#endif	//end Vsens_INTERFACE_H
