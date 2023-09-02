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

//Standard libraries Section
#include "../../../LIB/BIT_MATH.h"
#include "../../../LIB/STD_TYPES.h"
#include "../../MCAL/ADC/ADC_interface.h"

//Private libraries Section
#include "Temp_sensor_interface.h"

// Private Macros
#define Temp_ADC_max_ch			7
#define Temp_ADC_def_ch			0
#define Temp_V_ref				5000
#define Temp_sensor_Prescaler	0
#define Temp_sensor_ADATE		0
#define Temp_sensor_ADTS		0
#define Temp_sensor_ADIE		0
#define Temp_sensor_Val_flour	0
#define Temp_sensor_ADC_max		1024.0

//Global variables
ADC_config_struct Temp_sensor_config = {Temp_ADC_def_ch, Temp_sensor_Prescaler, Temp_sensor_ADATE, Temp_sensor_ADTS, Temp_sensor_ADIE};


/* Implementing of the driver functions */
// Initiate the sensor through a given ADC channel
void Temp_sensor_voidInit(u8 copy_u8_ADC_ch){
	/*
	 *
	 */
	if((copy_u8_ADC_ch <= Temp_ADC_max_ch)){
		Temp_sensor_config.MUX = copy_u8_ADC_ch;
	}
	else{

	}
	ADC_void_init();
}

// Calculate the current data and return it
f64 Temp_sensor_voidClcTemp(void ){
	/*
	 *
	 */
	u16 currentAccumulator = Temp_sensor_Val_flour;
	u16 current_ADC_data = Temp_sensor_Val_flour;
	ADC_void_config(&Temp_sensor_config);
	for(u8 acc_counter= Temp_sensor_Val_flour; acc_counter < Temp_sensor_Acc; acc_counter++){
		ADC_void_read_data(&current_ADC_data);
		currentAccumulator+= current_ADC_data;
	}
	current_ADC_data = currentAccumulator/Temp_sensor_Acc;
	f64 current_data = ((current_ADC_data/Temp_sensor_ADC_max)*Temp_V_ref)/Volt_temp_ref;
	return current_data;
}
