/*
 * main.c
 *
 *  Created on: Aug 7, 2023
 *      Author: Omar A.Qadir
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../Drivers/MCAL/IIC/IIC_interface.h"

#define RTC_read_add	0b11010001u
#define RTC_write_add	0b11010000u

/* RTC functions */

/*
 *
 * RTC_GetDate();
 * RTC_GetHour();
 * RTC_GetMinutes();
 * RTC_GetSeconds();
 * RTC_GetYear();
 * RTC_GetMonth();
 * RTC_GetDay();
 * RTC_SetTime();
 * RTC_SetDate();
 * RTC_SetHour();
 * RTC_SetMinutes();
 * RTC_SetSeconds();
 * RTC_SetYear();
 * RTC_SetMonth();
 * RTC_SetDay();
 */

typedef struct{

};

RTC_GetTime(void);

int main(void){
	// setup section
	I2C_void_master_init(100);
	u8 RTC_frame[] = {};
	I2C_void_master_start_comm(RTC_frame);
	while(1){
		// loop section

	}
	return 0;
}
