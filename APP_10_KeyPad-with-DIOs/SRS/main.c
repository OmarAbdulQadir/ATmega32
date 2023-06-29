//Standard libraries Section
//#include <avr/io.h>
#include <util/delay.h>
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

//MCAL layer Section
//#include "../MCAL/<driverName>/interface.h"
#include "../../Drivers/MCAL/DIO/DIO_interface.h"

//HAL layer Section
//#include "../HAL/<driverName>/interface.h"

//Private libraries Section
//#include "../INC/<fileName>.h"

//Global variables, struct and enums




int main(void){
	DIO_void_set_port_dir(PORTC, OUTPUT);
	DIO_void_set_port(PORTC);

	// Connection map for keypad 3*3
	// Column1: PORTx0
	// Column2: PORTx2
	// Column3: PORTx2
	// Row1: PORTx3
	// Row2: PORTx4
	// Row3: PORTx5

	DIO_void_set_pin_dir(PORTD, B0, OUTPUT);
	DIO_void_set_pin_dir(PORTD, B1, OUTPUT);
	DIO_void_set_pin_dir(PORTD, B2, OUTPUT);
	DIO_void_set_pin(PORTD, B0);
	DIO_void_set_pin(PORTD, B1);
	DIO_void_set_pin(PORTD, B2);
	DIO_void_set_pin_dir(PORTD, B3, INPUT);
	DIO_void_set_pin_dir(PORTD, B4, INPUT);
	DIO_void_set_pin_dir(PORTD, B5, INPUT);

	u8 seg_val_dec[10] = {64, 121, 36, 48, 25, 18, 2, 120, 0, 24}; //DEC values for the 7 segment numbers

	// 1: PD0= HIGH >> Column, PD3= HIGH >> Row
	// 2: PD0= HIGH >> Column, PD4= HIGH >> Row
	// 3: PD0= HIGH >> Column, PD5= HIGH >> Row
	// 4: PD1= HIGH >> Column, PD3= HIGH >> Row
	// 5: PD1= HIGH >> Column, PD4= HIGH >> Row
	// 6: PD1= HIGH >> Column, PD5= HIGH >> Row
	// 7: PD2= HIGH >> Column, PD3= HIGH >> Row
	// 8: PD2= HIGH >> Column, PD4= HIGH >> Row
	// 9: PD2= HIGH >> Column, PD5= HIGH >> Row
	// Equation:: Value= column + 3(Row) - 8

	while(1){
		for(u8 COL= 0; COL < 3; COL++){
			//select one column
			DIO_void_set_pin(PORTD, COL);
			//check which row is pressed
			for(u8 ROW= 3; ROW < 6; ROW++){
				//check if current row is pressed
				if(HIGH == DIO_u8_get_pin(PORTD, ROW)){
					u8 value_id= ((COL)+(3*ROW)-8);
					DIO_void_assign_port(PORTC, seg_val_dec[value_id]);
					_delay_ms(50);
				}
			}
			DIO_void_clear_pin(PORTD, COL);
		}
	}
	return 0;
}
