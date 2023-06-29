/*
 * Master.h
 *
 *  Created on: Jun 22, 2023
 *      Author: Omar A.Qadir
 */

#ifndef INC_MASTER_H_
#define INC_MASTER_H_

#define light_init_comm			0
#define light_byte				1
#define temp_init_comm			2
#define temp_dec_byte			3
#define temp_float_byte			4

#define slave_select_light_pin	3
#define slave_select_temp_pin	4


void master_update_time(void );
void master_read_data_words(void );

#endif /* INC_MASTER_H_ */
