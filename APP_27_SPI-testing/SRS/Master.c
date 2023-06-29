/*
 * Master.c
 *
 *  Created on: Jun 22, 2023
 *      Author: Omar A.Qadir
 */

// Libraries section
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <util/delay.h>

// Private libraries section
#include "../INC/Master.h"

// Drivers Section
#include "../../Drivers/MCAL/SPI/SPI_interface.h"
#include "../../Drivers/MCAL/TIMER/TIMER_interface.h"

// Global variables
extern f32 real_temprature;
extern u8 real_light, copy_byte_temp_val;

void master_read_data_words(void ){
	static u8 master_trancive_status = light_init_comm;
	_delay_ms(0.75);
	switch(master_trancive_status){
	case light_init_comm:
		SPI_u8_master_transmit(slave_select_light_pin, 0);
		master_trancive_status++;
		break;
	case light_byte:
		real_light = SPI_u8_recive();
		SPI_u8_master_transmit(slave_select_temp_pin, 0);
		master_trancive_status++;
		break;
	case temp_init_comm:
		SPI_u8_master_transmit(slave_select_temp_pin, 0);
		master_trancive_status++;
		break;
	case temp_dec_byte:
		copy_byte_temp_val = SPI_u8_recive();
		SPI_u8_master_transmit(slave_select_temp_pin, 0);
		master_trancive_status++;
		break;
	case temp_float_byte:
		real_temprature = copy_byte_temp_val;
		copy_byte_temp_val = SPI_u8_recive();
		real_temprature += (copy_byte_temp_val/100.0);
		master_trancive_status = light_init_comm;
		break;
	}
}


void master_update_time(void ){
	static u8 master_OVF_counter = 0;
	if (master_OVF_counter == 136){
		master_read_data_words();
		TIMER_config();
		master_OVF_counter = 0;
	}
	else{
		master_OVF_counter++;
	}
}
