/*******************************************************************/
/***               Date: 03/8/2023	Day: Thursday                ***/
/*** Temperature sensor driver for the microcontroller ATMega 32 ***/
/***    	 Created By: Omar Abdul Qadir	 Version= 1.0		 ***/
/*******************************************************************/
/***         Note: All the data in the file is readable,         ***/
/***     And any editing will affect the controller's behavior,  ***/
/***          So It's not recommended to edit any data,          ***/
/***   Unless you are sure of what is the effect on behaviors.   ***/
/*******************************************************************/


#ifndef Temp_sensor_INTERFACE_H
#define Temp_sensor_INTERFACE_H

	/* Milli-Volts per 1 degree celsius configurations */
	#define Volt_temp_ref		10

	/* Number of reading iterations*/
	#define Temp_sensor_Acc		10

	/* Initiate the sensor through a given ADC channel */
	void Temp_sensor_voidInit(u8 );
	/* Calculate the temperature data and return it */
	f64 Temp_sensor_voidClcTemp(void );

#endif	//end Temp_sensor_INTERFACE_H
