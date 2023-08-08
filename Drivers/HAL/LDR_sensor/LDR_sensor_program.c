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

//Standard libraries Section
#include <util/delay.h>
#include "../../../LIB/BIT_MATH.h"
#include "../../../LIB/STD_TYPES.h"
#include "../../MCAL/ADC/ADC_interface.h"

//Private libraries Section
#include "LDR_sensor_interface.h"

// Private Macros
#define LDR_sensor_def_ch		0
#define LDR_sensor_max_ch		7
#define LDR_sensor_Prescaler	0
#define LDR_sensor_ADATE		0
#define LDR_sensor_ADTS			0
#define LDR_sensor_ADIE			0
#define LDR_sensor_Val_flour	0
#define LDR_sensor_ADC_MAX		1024

//Global variables
ADC_config_struct LDR_sensor_config = {LDR_sensor_def_ch, LDR_sensor_Prescaler, LDR_sensor_ADATE, LDR_sensor_ADTS, LDR_sensor_ADIE};


/* Implementing of the driver functions */
// Initiate the sensor through a given ADC channel
void LDRsensor_voidInit(u8 copy_u8_ADC_ch){
	/*
	 *
	 */
	if(copy_u8_ADC_ch <= LDR_sensor_max_ch){
		LDR_sensor_config.MUX = copy_u8_ADC_ch;
	}
	ADC_void_init();
}

// start calculating the voltage value
u8 LDRsensor_voidClcInt(void ){
	/*
	 *
	 */
	u16 LDR_sensor_Accumulator = LDR_sensor_Val_flour;
	u16 LDR_ADC_Data = LDR_sensor_Val_flour;
	ADC_void_config(&LDR_sensor_config);
	for(u8 acc_counter= LDR_sensor_Val_flour; acc_counter < LDRsensor_Acc; acc_counter++){
		ADC_void_read_data(&LDR_ADC_Data);
		LDR_sensor_Accumulator += LDR_ADC_Data;
	}
	LDR_ADC_Data = LDR_sensor_Accumulator/LDRsensor_Acc;
	#if LDR_connect == 1
		if(LDR_ADC_Data < 150)
			return 0;
		else if (LDR_ADC_Data < 500)
			return 2;
		else if (LDR_ADC_Data < 750)
			return 4;
		else
			return 6;
	#elif LDR_connect == 0
		if(LDR_ADC_Data < 150)
			return 6;
		else if (LDR_ADC_Data < 500)
			return 4;
		else if (LDR_ADC_Data < 750)
			return 2;
		else
			return 0;
	#else
		return 10;
	#endif
}
