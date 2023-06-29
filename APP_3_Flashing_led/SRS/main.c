/*
 * main.c
 *
 *  Created on: May 5, 2023
 *      Author: Omar A.Qadir
 */


//Standard libraries Section
#include <avr/io.h>
#include <util/delay.h>


int main(void){

	DDRA= 1;
	PORTA= 0;

	while(1){
		PORTA= 1;
		_delay_ms(1000);
		PORTA= 0;
		_delay_ms(500);
	}
	return 0;
}
