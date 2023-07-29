/*
 * main.c
 *
 *  Created on: Jun 16, 2023
 *      Author: Omar A.Qadir
 */

// Libraries section
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

// Drivers section
#include "../../Drivers/MCAL/DIO/DIO_interface.h"
#include "../../Drivers/HAL/LCD/LCD_interface.h"

// Macros section
#define TIMER_TIMSK		*((volatile u8* ) 0x59)
#define TIMER_SREG		*((volatile u8* ) 0x5F)

#define TIMER_TCCR0		*((volatile u8* ) 0x53)
#define TIMER_OCR0		*((volatile u8* ) 0x5C)

#define TIMER_TCCR1A	*((volatile u8* ) 0x4F)
#define TIMER_TCCR1B	*((volatile u8* ) 0x4E)
#define TIMER_TCNT1		*((volatile u16*) 0x4C)
#define TIMER_ICR1		*((volatile u16*) 0x46)

#define TIMER_TCCR2		*((volatile u8* ) 0x45)

// Functions decleration section
void __vector_6(void)__attribute__((signal));
void lcd_refresh(void);

// Global variables and structs section
u16 on_time, off_time, freq;
u8 flag, duty;

int main(void){
	// set input pin clear
	DIO_void_set_pin_dir(DIO_REF_PORTD, B6, INPUT);
	DIO_void_set_pin_dir(DIO_REF_PORTB, B3, OUTPUT);

	// Setup section
	// Timer 0 setup
	// configure the output signal f= and d=
	TIMER_TCCR0= 0b01101010;
	// start timer with the presecaler
	TIMER_OCR0= 128;

	// Timer 1 setup
	// Normal mode
	TIMER_TCCR1A= 0b00000000;
	// Set prescaller= clk/8 and sense the rising edge
	TIMER_TCCR1B= 0b01000010;
	// Enable ICU interrupt
	TIMER_TIMSK= 0b00100000;
	// Enable global variable
	TIMER_SREG= 0b10000000;

	u16 on_time_prev= on_time;
	// Initiate the lcdb
	LCD_init();
	lcd_refresh();

	while (1){
		// Loop section
		if (on_time != on_time_prev){
			// Calculate the signal specs
			lcd_refresh();
		}
		on_time_prev= on_time;
	}
	return 0;
}


void __vector_6(void){
	if(0 == flag){
		// get off time from the icu regester
		off_time= TIMER_ICR1;
		// reset the timer counter register
		TIMER_TCNT1= 0;
		// sense faling edge
		TIMER_TCCR1B= 0b00000010;
		flag= 1;
	}
	else{
		// get on time from the icu regester
		on_time= TIMER_ICR1;
		// reset the timer counter register
		TIMER_TCNT1= 0;
		// sense rising edge
		TIMER_TCCR1B= 0b01000010;
		flag= 0;
	}
}

void lcd_refresh(void){
	freq= (1000000)/(on_time + off_time);
	duty= (on_time*100)/(on_time + off_time);
	LCD_clear();
	LCD_write_str("ferq= ");
	LCD_write_s32_number(freq);
	LCD_set_cursor(1, 0);
	LCD_write_str("duty= ");
	LCD_write_s32_number(duty);
}
