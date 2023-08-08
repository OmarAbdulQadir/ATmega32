/*******************************************************************/
/***               Date: 06/8/2023	Day: sunday                  ***/
/***	LDR sensor driver for the microcontroller ATMega 32      ***/
/***    	 Created By: Omar Abdul Qadir	 Version= 1.0		 ***/
/*******************************************************************/
/***         Note: All the data in the file is readable,         ***/
/***     And any editing will affect the controller's behavior,  ***/
/***          So It's not recommended to edit any data,          ***/
/***   Unless you are sure of what is the effect on behaviors.   ***/
/*******************************************************************/


#ifndef LDR_sensor_INTERFACE_H
#define LDR_sensor_INTERFACE_H

	/* Voltage configurations */
	#define Volt_ref			5

	/* conneced to PWR (1) or GND (0) */
	#define LDR_connect			1

	/* Number of reading iterations*/
	#define LDRsensor_Acc		10

	/* Initiate the sensor through a given ADC channel */
	void LDRsensor_voidInit(u8 );
	/* start calculation and return the intensity level value*/
	u8 LDRsensor_voidClcInt(void );

#endif	//end LDR_sensor_INTERFACE_H
