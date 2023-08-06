/*******************************************************************/
/***               Date: 02/8/2023	Day: Wednesday               ***/
/*** DC current sensor driver for the microcontroller ATMega 32  ***/
/***    	 Created By: Omar Abdul Qadir	 Version= 1.0		 ***/
/*******************************************************************/
/***         Note: All the data in the file is readable,         ***/
/***     And any editing will affect the controller's behavior,  ***/
/***          So It's not recommended to edit any data,          ***/
/***   Unless you are sure of what is the effect on behaviors.   ***/
/*******************************************************************/


#ifndef A_DC_sensor_INTERFACE_H
#define A_DC_sensor_INTERFACE_H

	/* Voltage configurations */
	#define Volt_ref			5

	/* Sensor resistance */
	#define Res_ref				0.05

	/* Number of reading iterations*/
	#define A_DC_sensor_Acc		10

	/* Possible ADC differential channels */
	#define Amp_A0_1			11
	#define Amp_A2_3			15

	/* Initiate the sensor through a given ADC channel */
	void A_DC_sensor_voidInit(u8 );
	/* Calculate the current data and return it */
	f64 A_DC_sensor_voidClcAmps(void );

#endif	//end A_DC_sensor_INTERFACE_H
