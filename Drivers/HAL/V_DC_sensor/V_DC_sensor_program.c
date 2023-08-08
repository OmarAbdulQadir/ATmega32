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

//Standard libraries Section
#include <util/delay.h>
#include "../../../LIB/BIT_MATH.h"
#include "../../../LIB/STD_TYPES.h"
#include "../../MCAL/ADC/ADC_interface.h"

//Private libraries Section
#include "V_DC_sensor_interface.h"

// Private Macros
#define V_DC_sensor_def_ch		0
#define V_DC_sensor_max_ch		7
#define V_DC_sensor_Prescaler	0
#define V_DC_sensor_ADATE		0
#define V_DC_sensor_ADTS		0
#define V_DC_sensor_ADIE		0
#define V_DC_sensor_Val_flour	0
#define V_DC_sensor_ADC_MAX		1024.0

//Global variables
ADC_config_struct V_DC_sensor_config = {V_DC_sensor_def_ch, V_DC_sensor_Prescaler, V_DC_sensor_ADATE, V_DC_sensor_ADTS, V_DC_sensor_ADIE};


/* Implementing of the driver functions */
// Initiate the sensor through a given ADC channel
void Vsensor_voidInit(u8 copy_u8_ADC_ch){
	/*
	 *
	 */
	if(copy_u8_ADC_ch <= V_DC_sensor_max_ch){
		V_DC_sensor_config.MUX = copy_u8_ADC_ch;
	}
	ADC_void_init();
}

// start calculating the voltage value
f64 Vsensor_voidClcVolt(void ){
	/*
	 *
	 */
	u16 voltageAccumulator = V_DC_sensor_Val_flour;
	u16 Voltage_ADC_Data = V_DC_sensor_Val_flour;
	ADC_void_config(&V_DC_sensor_config);
	for(u8 acc_counter= V_DC_sensor_Val_flour; acc_counter < Vsensor_Acc; acc_counter++){
		ADC_void_read_data(&Voltage_ADC_Data);
		voltageAccumulator += Voltage_ADC_Data;
	}
	Voltage_ADC_Data = voltageAccumulator/Vsensor_Acc;
	f64 voltageValue = ((Voltage_ADC_Data*Volt_ref)/V_DC_sensor_ADC_MAX)*Stage_gain;
	return voltageValue;
}
