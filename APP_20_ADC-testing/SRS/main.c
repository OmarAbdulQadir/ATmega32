/*
 * main.c
 *
 *  Created on: Jun 3, 2023
 *      Author: Omar A.Qadir
 */

#include <util/delay.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../Drivers/MCAL/DIO/DIO_interface.h"
#include "../../Drivers/MCAL/ADC/ADC_interface.h"
#include "../../Drivers/HAL/LCD/LCD_interface.h"


int main(void ){
	// Setup section
	LCD_init();
	LCD_write_str("Val= ");

	DIO_void_set_pin_dir(DIO_REF_PORTA, B0, INPUT);

	ADC_config_struct Congif= {0, 7, 0, 0, 0};
	ADC_void_init();
	ADC_void_config(&Congif);
	u16 ADC_DATA = 0, ADC_DATA_prev= 1023;
	ADC_void_read_data(&ADC_DATA);
	while (1){
		// Loop section
		if((ADC_DATA != ADC_DATA_prev) && (ADC_DATA != 0)){
			LCD_clear();
			LCD_write_str("Val= ");
			f32 analog_vol= (ADC_DATA*5.0)/1024.0;
			f32 temp = analog_vol*100;
			LCD_write_float(temp, 2);
			ADC_DATA_prev = ADC_DATA;
		}
		_delay_ms(500);
		ADC_void_read_data(&ADC_DATA);
	}
	return 0;
}
