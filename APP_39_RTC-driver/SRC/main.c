/*
 * main.c
 *
 *  Created on: Aug 7, 2023
 *      Author: Omar A.Qadir
 */

#include <util/delay.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../Drivers/MCAL/DIO/DIO_interface.h"
#include "../../Drivers/HAL/LCD/LCD_interface.h"
#include "../../Drivers/HAL/RTC/RTC_interface.h"



int main(void){


	// setup section

	RTC_init();
	//RTC_reset();

	LCD_init();
	DIO_void_set_pin_in_pullUP(DIO_REF_PORTD, B0);
	DIO_void_set_pin_in_pullUP(DIO_REF_PORTD, B1);
	DIO_void_set_pin_in_pullUP(DIO_REF_PORTD, B2);
	DIO_void_set_pin_in_pullUP(DIO_REF_PORTD, B3);


	u8 (*RTC_get_data[7])(void) = {RTC_GetSeconds, RTC_GetMinutes, RTC_GetHours, RTC_GetWeekDay, RTC_GetDay, RTC_GetMonth, RTC_GetYear};
	void (*RTC_set_data[7])(u8) = {RTC_SetSeconds, RTC_SetMinutes, RTC_SetHours, RTC_SetWeekDay, RTC_SetDay, RTC_SetMonth, RTC_SetYear};
	u8* RTC_dataType[7] = {(u8*)"Seconds", (u8*)"Minutes", (u8*)"Hours", (u8*)"Day", (u8*)"Date", (u8*)"Month", (u8*)"Year"};
	u8 RTC_dataCounter = 0;
	u8 temp_val = RTC_get_data[RTC_dataCounter]();
	LCD_clear();
	LCD_set_cursor(0,0);
	LCD_write_str(RTC_dataType[RTC_dataCounter]);
	LCD_set_cursor(1,0);
	LCD_write_s32_number(temp_val);

	while(1){
		// loop section
		if(DIO_u8_get_pin(DIO_REF_PORTD, B0) == 0){
			_delay_ms(150);
			RTC_dataCounter = (RTC_dataCounter == 6) ? 0 : RTC_dataCounter+1;
			while((DIO_u8_get_pin(DIO_REF_PORTD, B0) == 0));
			LCD_clear();
			LCD_set_cursor(0,0);
			LCD_write_str(RTC_dataType[RTC_dataCounter]);
			LCD_set_cursor(1,0);
			temp_val = RTC_get_data[RTC_dataCounter]();
			LCD_write_s32_number(temp_val);
		}
		if(DIO_u8_get_pin(DIO_REF_PORTD, B1) == 0){
			_delay_ms(150);
			RTC_dataCounter = (RTC_dataCounter == 0) ? 6 : RTC_dataCounter-1;
			while((DIO_u8_get_pin(DIO_REF_PORTD, B1) == 0));
			LCD_clear();
			LCD_set_cursor(0,0);
			LCD_write_str(RTC_dataType[RTC_dataCounter]);
			LCD_set_cursor(1,0);
			temp_val = RTC_get_data[RTC_dataCounter]();
			LCD_write_s32_number(temp_val);
		}
		if(DIO_u8_get_pin(DIO_REF_PORTD, B3) == 0){
			_delay_ms(150);
			while(DIO_u8_get_pin(DIO_REF_PORTD, B3) == 0);
			while(DIO_u8_get_pin(DIO_REF_PORTD, B2) == 1){
				if(DIO_u8_get_pin(DIO_REF_PORTD, B0) == 0){
					_delay_ms(150);
					LCD_clear();
					LCD_set_cursor(0,0);
					LCD_write_str(RTC_dataType[RTC_dataCounter]);
					LCD_set_cursor(1,0);
					LCD_write_s32_number(++temp_val);
				}
				if(DIO_u8_get_pin(DIO_REF_PORTD, B1) == 0){
					_delay_ms(150);
					LCD_clear();
					LCD_set_cursor(0,0);
					LCD_write_str(RTC_dataType[RTC_dataCounter]);
					LCD_set_cursor(1,0);
					LCD_write_s32_number(--temp_val);
				}
			}
			_delay_ms(150);
			while(DIO_u8_get_pin(DIO_REF_PORTD, B2) == 0);
			RTC_set_data[RTC_dataCounter](temp_val);
		}
	}
	return 0;
}
