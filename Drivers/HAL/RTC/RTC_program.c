/*******************************************************************/
/***               Date: 9/8/2023	Day: Wednesday 		         ***/
/***  	RTC (DS1307) driver for the microcontroller ATMega 32 	 ***/
/***     Created By: Omar Abdul Qadir	 Version= 1.0            ***/
/*******************************************************************/
/***         Note: All the data in the file is readable,         ***/
/***     And any editing will affect the controller's behavior,  ***/
/***          So It's not recommended to edit any data,          ***/
/***   Unless you are sure of what is the effect on behaviors.   ***/
/*******************************************************************/

/* Standard libraries section */
#include <util/delay.h>
#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/BIT_MATH.h"

/* Drivers section */
#include "../../MCAL/IIC/IIC_interface.h"

/* Private includes */
#include "RTC_interface.h"

/* Private Macros */
// RTC Read address
#define RTC_read_add			0xD1
// RTC Write address
#define RTC_write_add			0xD0
// RTC Seconds address
#define RTC_Seconds_add			0x00
// RTC Minuts address
#define RTC_Minuts_add			0x01
// RTC Hours address
#define RTC_Hour_add			0x02
// RTC Week day address
#define RTC_WeekDay_add			0x03
// RTC Day address
#define RTC_Day_add				0x04
// RTC Month address
#define RTC_Month_add			0x05
// RTC Year address
#define RTC_Year_add			0x06

// RTC Hours High nipple mask
#define Hours24_Hnipple_mask	0x30
// RTC Hours High nipple mask
#define Hours12_Hnipple_mask	0x90
// RTC Hours Low nipple mask
#define Hours_Lnipple_mask		0x0F

// RTC Minuts High nipple mask
#define Minuts_Hnipple_mask		0x70
// RTC Minuts Low nipple mask
#define Minuts_Lnipple_mask		0x0F

// RTC Seconds High nipple mask
#define Seconds_Hnipple_mask	0x70
// RTC Seconds Low nipple mask
#define Seconds_Lnipple_mask	0x0F

// RTC Year High nipple mask
#define Year_Hnipple_mask		0xF0
// RTC Year Low nipple mask
#define Year_Lnipple_mask		0x0F

// RTC Month High nipple mask
#define Month_Hnipple_mask		0x10
// RTC Month Low nipple mask
#define Month_Lnipple_mask		0x0F

// RTC Day High nipple mask
#define Day_Hnipple_mask		0x30
// RTC Day Low nipple mask
#define Day_Lnipple_mask		0x0F

// RTC WeekDay Low nipple mask
#define WeekDay_Lnipple_mask	0x07

// Repeated start code
#define RTC_Rs_code				254
// End of frame code
#define RTC_P_code				255

/* Global variables and structs */
u8 RTC_global_frame[10];

/* Setting fcuntion implementation */
void RTC_init(void ){
	/*
	 *
	 */
	I2C_void_master_init(RTC_I2C_SLW);
}

void RTC_reset(void ){
	/*
	 *
	 */
	// clocl Halt enavle
	u8 CH_val = 0;
	// Hours mode is set
	u8 HourMode = (RTC_TimeFormat == 0) ? 0 : 64;
	// Configuration frame
	u8 Config_frame[10] = {RTC_write_add, RTC_Seconds_add, CH_val, 0x00, HourMode, 0x00, 0x00, 0x00, 0x00, 255};
	for(u8 i = 0; i < 10; i++)
		RTC_global_frame[i] = Config_frame[i];
	I2C_void_master_start_comm(RTC_global_frame);
}

/* Getter functions implementation */
/* Time functions */
time_st RTC_GetTime(void ){
	/*
	 *
	 */
	time_st temp_time_;
	return temp_time_;
}

u8 RTC_GetHours(void ){
	/*
	 *
	 */
	u8 const get_Hours_frame[] = {RTC_write_add, RTC_Hour_add, RTC_Rs_code, RTC_read_add, 1, RTC_P_code};
	for(u8 i= 0; i <= 6; i++)
		RTC_global_frame[i] = get_Hours_frame[i];
	I2C_void_master_start_comm(RTC_global_frame);
	_delay_ms(0.375);
	u8 TempHours_ = *(I2C_u8_ptr_get_buffered_frame());
	#if		RTC_TimeFormat == 0
		TempHours_ = ((((TempHours_ & Hours24_Hnipple_mask) >> 4) * 10) + (TempHours_ & Hours_Lnipple_mask));
	#elif	RTC_TimeFormat == 1
		agn_bit(TempHours_, 7, ((TempHours_ >> 5)&1));
		TempHours_ = ((((TempHours_ & Hours12_Hnipple_mask) >> 4) * 10) + (TempHours_ & Hours_Lnipple_mask));
	#else
		#warning Wrong Time formate configuration
		TempHours_ = ((((TempHours_ & Hours24_Hnipple_mask) >> 4) * 10) + (TempHours_ & Hours_Lnipple_mask));
	#endif
	return TempHours_;
}

u8 RTC_GetMinutes(void ){
	/*
	 *
	 */
	u8 const get_Minuts_frame[] = {RTC_write_add, RTC_Minuts_add, RTC_Rs_code, RTC_read_add, 1, RTC_P_code};
	for(u8 i= 0; i <= 6; i++)
		RTC_global_frame[i] = get_Minuts_frame[i];
	I2C_void_master_start_comm(RTC_global_frame);
	_delay_ms(0.375);
	u8 TempMinuts_ = *(I2C_u8_ptr_get_buffered_frame());
	TempMinuts_ = ((((TempMinuts_ & Minuts_Hnipple_mask) >> 4) * 10) + (TempMinuts_ & Minuts_Lnipple_mask));
	return TempMinuts_;
}

u8 RTC_GetSeconds(void ){
	/*
	 *
	 */
	u8 const get_Seconds_frame[] = {RTC_write_add, RTC_Seconds_add, RTC_Rs_code, RTC_read_add, 1, RTC_P_code};
	for(u8 i= 0; i <= 6; i++)
		RTC_global_frame[i] = get_Seconds_frame[i];
	I2C_void_master_start_comm(RTC_global_frame);
	_delay_ms(0.375);
	u8 TempSeconds_ = I2C_u8_ptr_get_buffered_frame()[0];
	TempSeconds_ = ((((TempSeconds_ & Seconds_Hnipple_mask) >> 4) * 10) + (TempSeconds_ & Seconds_Lnipple_mask));
	return TempSeconds_;
}

/* Date functions */
date_st RTC_GetDate(void ){
	date_st temp_date_;
	return temp_date_;
}

u8 RTC_GetYear(void ){
	/*
	 *
	 */
	u8 const get_Year_frame[] = {RTC_write_add, RTC_Year_add, RTC_Rs_code, RTC_read_add, 1, RTC_P_code};
	for(u8 i= 0; i <= 6; i++)
		RTC_global_frame[i] = get_Year_frame[i];
	I2C_void_master_start_comm(RTC_global_frame);
	_delay_ms(0.375);
	u8 TempYear_ = *(I2C_u8_ptr_get_buffered_frame());
	TempYear_ = ((((TempYear_ & Year_Hnipple_mask) >> 4) * 10) + (TempYear_ & Year_Lnipple_mask));
	return TempYear_;
}

u8 RTC_GetMonth(void ){
	/*
	 *
	 */
	u8 const get_Month_frame[] = {RTC_write_add, RTC_Month_add, RTC_Rs_code, RTC_read_add, 1, RTC_P_code};
	for(u8 i= 0; i <= 6; i++)
		RTC_global_frame[i] = get_Month_frame[i];
	I2C_void_master_start_comm(RTC_global_frame);
	_delay_ms(0.375);
	u8 TempMonth_ = *(I2C_u8_ptr_get_buffered_frame());
	TempMonth_ = ((((TempMonth_ & Month_Hnipple_mask) >> 4) * 10) + (TempMonth_ & Month_Lnipple_mask));
	return TempMonth_;
}

u8 RTC_GetDay(void ){
	/*
	 *
	 */
	u8 const get_Day_frame[] = {RTC_write_add, RTC_Day_add, RTC_Rs_code, RTC_read_add, 1, RTC_P_code};
	for(u8 i= 0; i <= 6; i++)
		RTC_global_frame[i] = get_Day_frame[i];
	I2C_void_master_start_comm(RTC_global_frame);
	_delay_ms(0.375);
	u8 TempDay_ = *(I2C_u8_ptr_get_buffered_frame());
	TempDay_ = ((((TempDay_ & Day_Hnipple_mask) >> 4) * 10) + (TempDay_ & Day_Lnipple_mask));
	return TempDay_;
}

u8 RTC_GetWeekDay(void ){
	/*
	 *
	 */
	u8 get_WeekDay_frame[] = {RTC_write_add, RTC_WeekDay_add, RTC_Rs_code, RTC_read_add, 1, RTC_P_code};
	for(u8 i= 0; i <= 6; i++)
		RTC_global_frame[i] = get_WeekDay_frame[i];
	I2C_void_master_start_comm(RTC_global_frame);
	_delay_ms(0.375);
	u8 TempWeekDay_ = *(I2C_u8_ptr_get_buffered_frame());
	TempWeekDay_ = (TempWeekDay_ & WeekDay_Lnipple_mask);
	return TempWeekDay_;
}

/* Setter functions implementation */
/* Time functions */
void RTC_SetTime(time_st* ptr_time_st){

}

void RTC_SetHours(u8 copy_u8_hour){
	/*
	 *
	 */
	#if		RTC_TimeFormat == 0
		u8 Temp_Hours = ((copy_u8_hour/10) << 4) | (copy_u8_hour%10);
	#elif	RTC_TimeFormat == 1
		if(copy_u8_hour > 12){

		}
	#else
		#warning Wrong Time formate configuration
		u8 Temp_Hours = ((copy_u8_hour/10) << 4) | (copy_u8_hour%10);
	#endif
	u8 set_Hours_frame[] = {RTC_write_add, RTC_Hour_add, Temp_Hours, RTC_P_code};
	for(u8 i= 0; i <= 4; i++)
		RTC_global_frame[i] = set_Hours_frame[i];
	I2C_void_master_start_comm(RTC_global_frame);
}

void RTC_SetMinutes(u8 copy_u8_minuts){
	/*
	 *
	 */
	u8 Temp_Minuts = ((copy_u8_minuts/10) << 4) | (copy_u8_minuts%10);
	u8 set_Minuts_frame[] = {RTC_write_add, RTC_Minuts_add, Temp_Minuts, RTC_P_code};
	for(u8 i= 0; i <= 4; i++)
		RTC_global_frame[i] = set_Minuts_frame[i];
	I2C_void_master_start_comm(RTC_global_frame);
}

void RTC_SetSeconds(u8 copy_u8_seconds){
	/*
	 *
	 */
	u8 Temp_Seconds = ((copy_u8_seconds/10) << 4) | (copy_u8_seconds%10);
	u8 set_Seconds_frame[] = {RTC_write_add, RTC_Seconds_add, Temp_Seconds, RTC_P_code};
	for(u8 i= 0; i <= 4; i++)
		RTC_global_frame[i] = set_Seconds_frame[i];
	I2C_void_master_start_comm(RTC_global_frame);
}

/* Date functions */
void RTC_SetDate(date_st* ptr_date_st){

}

void RTC_SetYear(u8 copy_u8_year){
	/*
	 *
	 */
	u8 Temp_Year = ((copy_u8_year/10) << 4) | (copy_u8_year%10);
	u8 Set_Year_frame[] = {RTC_write_add, RTC_Year_add, Temp_Year, RTC_P_code};
	for(u8 i= 0; i <= 4; i++)
		RTC_global_frame[i] = Set_Year_frame[i];
	I2C_void_master_start_comm(RTC_global_frame);
}

void RTC_SetMonth(u8 copy_u8_month){
	/*
	 *
	 */
	u8 Temp_Month = ((copy_u8_month/10) << 4) | (copy_u8_month%10);
	u8 Set_Month_frame[] = {RTC_write_add, RTC_Month_add, Temp_Month, RTC_P_code};
	for(u8 i= 0; i <= 4; i++)
		RTC_global_frame[i] = Set_Month_frame[i];
	I2C_void_master_start_comm(RTC_global_frame);
}

void RTC_SetDay(u8 copy_u8_day){
	/*
	 *
	 */
	u8 Temp_Day = ((copy_u8_day/10) << 4) | (copy_u8_day%10);
	u8 Set_Day_frame[] = {RTC_write_add, RTC_Day_add, Temp_Day, RTC_P_code};
	for(u8 i= 0; i <= 4; i++)
		RTC_global_frame[i] = Set_Day_frame[i];
	I2C_void_master_start_comm(RTC_global_frame);
}

void RTC_SetWeekDay(u8 copy_u8_weekday){
	/*
	 *
	 */
	u8 Set_WeekDay_frame[] = {RTC_write_add, RTC_WeekDay_add, copy_u8_weekday, RTC_P_code};
	for(u8 i= 0; i <= 4; i++)
		RTC_global_frame[i] = Set_WeekDay_frame[i];
	I2C_void_master_start_comm(RTC_global_frame);
}
