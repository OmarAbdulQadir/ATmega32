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

#ifndef RTC_INTERFACE_H_
#define RTC_INTERFACE_H_

// I2C Slave address
#define RTC_I2C_SLW		100
// Time format 12/24H (1: 12H, 0: 24H)
#define RTC_TimeFormat	0

typedef struct{
	u8 time_Seconds;
	u8 time_Minuts;
	u8 time_Hours;
}time_st;

typedef struct{
	u8 date_WeekDay;
	u8 date_Day;
	u8 date_Month;
	u8 date_Year;
}date_st;

typedef struct{
	time_st time;
	date_st date;
}dateTime_st;

void RTC_init(void );
void RTC_reset(void );

time_st RTC_GetTime(void );
u8 RTC_GetHours(void );
u8 RTC_GetMinutes(void );
u8 RTC_GetSeconds(void );

date_st RTC_GetDate(void );
u8 RTC_GetYear(void );
u8 RTC_GetMonth(void );
u8 RTC_GetDay(void );
u8 RTC_GetWeekDay(void );

void RTC_SetTime(time_st* );
void RTC_SetHours(u8 );
void RTC_SetMinutes(u8 );
void RTC_SetSeconds(u8 );

void RTC_SetDate(date_st* );
void RTC_SetYear(u8 );
void RTC_SetMonth(u8 );
void RTC_SetDay(u8 );
void RTC_SetWeekDay(u8 );


#endif /* RTC_INTERFACE_H_ */
