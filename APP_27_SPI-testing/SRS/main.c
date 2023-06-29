/*
 * main.c
 *
 *  Created on: Jun 17, 2023
 *      Author: Omar A.Qadir
 */


// Libraries section
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

// Drivers Section
#include "../../Drivers/MCAL/DIO/DIO_interface.h"
#include "../../Drivers/MCAL/ADC/ADC_interface.h"
#include "../../Drivers/MCAL/SPI/SPI_interface.h"
#include "../../Drivers/MCAL/TIMER/TIMER_interface.h"
#include "../../Drivers/HAL/LCD/LCD_interface.h"
#include "../../Drivers/MCAL/UART/UART_interface.h"

// Private section
#include "../INC/Master.h"
#include "../INC/temp_Slave.h"
#include "../INC/light_Slave.h"
#include "../INC/motor_Slave.h"

// Macros section
#define _master_mode			0
#define _Temp_mode				1
#define _LDR_mode				2
#define _fan_mode				3

// Global variables and structs section
f32 real_temprature;
u8 real_light, copy_byte_temp_val;



// Main app section
int main(void){
	// Setup section
	// Configure the direction of mode selection value
	DIO_void_set_pin_dir(PORTC, B0, INPUT);
	DIO_void_set_pin_dir(PORTC, B1, INPUT);

	// Read the mode pins value
	u8 _mode_select = 0;
	_mode_select =  ((DIO_u8_get_pin(PORTC, B0)) | (DIO_u8_get_pin(PORTC, B1) << 1));

	// Select the mode value
	if(_mode_select == _master_mode){			// Master chip mode
		// Initiate the LCD
		LCD_init();
		// Initiate the SPI perepheral as master
		SPI_void_init_master();
		// Set callback function
		SPI_void_set_callback(master_read_data_words);

		// Initiationg UART
		UART_void_init();
		UART_void_transmit_char('S');

		// Write the template screen of the LCD
		LCD_write_str("Temp=       C");
		LCD_set_cursor(1, 0);
		LCD_write_str("Light=     lx");

		// Declare preload data
		u8 preload_values[2]= {72, 0};
		// Declare the timers configurations
		timer_config timer0_config= {ref_TIMER0_WGM_NORM, ref_TIMER_COM_NORM, TIMER_8PRE, preload_values};
		// Initiate timer
		TIMER_init(&timer0_config);
		// Set timer overflow callback function
		TIMER_set_callback(ref_TIMER0_OVF, master_update_time);
		// Configure and start the timer
		TIMER_config();

		// Declare the global variables of master mode
		u16 last_Light_val= 0;
		f32 last_temp_value= 0;

		DIO_void_set_port_dir(PORTD, OUTPUT);
		while(1){
			// Loop section
			/* Update The LCD */
			// Update new temprature value on the lcd if changed
			if(real_temprature != last_temp_value){
				LCD_set_cursor(0, 6);
				LCD_write_str("      ");
				LCD_set_cursor(0, 6);
				LCD_write_float(real_temprature, 2);
				last_temp_value = real_temprature;
				if((real_temprature >= 26) && (real_light >= 50)){
					UART_void_transmit_char('H');
				}
				else{
					UART_void_transmit_char('L');
				}
			}

			// Update new light value on the lcd if changed
			if(real_light != last_Light_val){
				LCD_set_cursor(1, 7);
				LCD_write_str("    ");
				LCD_set_cursor(1, 7);
				LCD_write_s32_number(real_light);
				last_Light_val = real_light;
				if((real_temprature >= 26) && (real_light >= 50)){
					UART_void_transmit_char('H');
				}
				else{
					UART_void_transmit_char('L');
				}
			}
		}
	}
	else if(_mode_select == _Temp_mode){		// Slave chip with Temp mode

		// Initiating the SPI Perepheral as slave
		SPI_void_init_slave();
		// Set the Update function as callback for respoding to the master temprature reques
		SPI_void_set_callback(update_temprature_value);
		// update the data regester with ready value
		SPI_u8_slave_update(0xFF);

		// Initiating the ADC perepheral
		ADC_void_init();
		// Decleration of ADC Configuration struct
		ADC_config_struct temp_adc_config= {0, 7, 0, 0, 0};
		// ADC configuring the regesters
		ADC_void_config(&temp_adc_config);

		// Declare the digital variables of the ADC
		u16 ADC_temp_data= 0, ADC_prev_temp_data= 0;
		// Read the initial ADC value
		ADC_void_read_data(&ADC_temp_data);

		// Tempratue mode indicatior pin
		DIO_void_set_pin_dir(PORTC, B2, OUTPUT);
		DIO_void_clear_pin(PORTC, B2);

		while(1){
			// Loop section
			// Update the temprature value if changed
			if((ADC_temp_data != ADC_prev_temp_data) && (ADC_temp_data != 0)){
				// Calculate the analog voltage
				f32 analog_voltage= (ADC_temp_data*5.0)/1024.0;
				// Calculate the temprature value
				real_temprature = analog_voltage*100;
				// Update the previous temprature value
				ADC_prev_temp_data= ADC_temp_data;
			}
			// Read the knew temprature value
			ADC_void_read_data(&ADC_temp_data);
		}
	}
	else if(_mode_select == _LDR_mode){		// Slave chip with LDR mode

		// Initiate SPI in slave mode
		SPI_void_init_slave();
		// update the data regester with ready value
		SPI_u8_slave_update(0xFF);

		// Declare preload data
		u8 preload_values[2]= {208, 0};
		// Declare the timers configurations
		timer_config timer0_config= {ref_TIMER0_WGM_NORM, ref_TIMER_COM_NORM, TIMER_8PRE, preload_values};
		// Initiate timer
		TIMER_init(&timer0_config);
		// Set timer overflow callback function
		TIMER_set_callback(ref_TIMER0_OVF, update_light_value);
		// Configure and start the timer
		TIMER_config();

		// Initiating the ADC perepheral
		ADC_void_init();
		// Decleration of ADC Configuration struct
		ADC_config_struct temp_adc_config= {0, 7, 0, 0, 0};
		// ADC configuring the regesters
		ADC_void_config(&temp_adc_config);

		// Light mode indicatior pin
		DIO_void_set_pin_dir(PORTC, B2, OUTPUT);
		DIO_void_set_pin(PORTC, B2);

		while(1){
			// Loop section

		}
	}
	else if(_mode_select == _fan_mode){

		// Active indecator pin
		DIO_void_set_pin_dir(PORTA, B0, OUTPUT);
		DIO_void_set_pin(PORTA, B0);

		motor_slave_init();

		// Init UART prepheral
		UART_void_init();
		UART_void_set_Rx_callback(update_motor);

		while(1){
			// loop section

		}
	}
	return 0;
}
