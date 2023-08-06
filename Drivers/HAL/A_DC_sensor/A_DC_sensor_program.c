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

//Standard libraries Section
#include <util/delay.h>
#include "../../../LIB/BIT_MATH.h"
#include "../../../LIB/STD_TYPES.h"
#include "../../MCAL/ADC/ADC_interface.h"

//Private libraries Section
#include "A_DC_sensor_interface.h"

// Private Macros
#define A_DC_sensor_Prescaler	2
#define A_DC_sensor_ADATE		0
#define A_DC_sensor_ADTS		0
#define A_DC_sensor_ADIE		0
#define A_DC_sensor_Val_flour	0
#define A_DC_sensor_ADC_max		1024.0
#define NULL 					(void *) 0

//Global variables
ADC_config_struct A_DC_sensor_config = {Amp_A0_1, A_DC_sensor_Prescaler, A_DC_sensor_ADATE, A_DC_sensor_ADTS, A_DC_sensor_ADIE};
f64 max_current = A_DC_sensor_Val_flour;


/* Implementing of the driver functions */
// Initiate the sensor through a given ADC channel
void A_DC_sensor_voidInit(u8 copy_u8_ADC_ch){
	/*
	 *
	 */
	if((copy_u8_ADC_ch == Amp_A0_1) || (copy_u8_ADC_ch == Amp_A2_3)){
		A_DC_sensor_config.MUX = copy_u8_ADC_ch;
	}
	else{

	}
	ADC_void_init();
	max_current = ((Volt_ref*Volt_ref)/Res_ref);
}

// Calculate the current data and return it
f64 A_DC_sensor_voidClcAmps(void ){
	/*
	 *
	 */
	u16 currentAccumulator = A_DC_sensor_Val_flour;
	u16 current_ADC_data = A_DC_sensor_Val_flour;
	ADC_void_config(&A_DC_sensor_config);
	for(u8 acc_counter= A_DC_sensor_Val_flour; acc_counter < A_DC_sensor_Acc; acc_counter++){
		ADC_void_read_data(&current_ADC_data);
		currentAccumulator+= current_ADC_data;
	}
	current_ADC_data = currentAccumulator/A_DC_sensor_Acc;
	f64 current_data = (current_ADC_data*max_current)/A_DC_sensor_ADC_max;
	return current_data;
}
