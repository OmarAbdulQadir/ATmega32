/*******************************************************************/
/***               Date: 2/5/2023	Day: Tuesday                 ***/
/***    Digital I/O driver for the microcontroller ATMega 32     ***/
/***     Created By: Omar Abdul Qadir	 Version= 3.0            ***/
/*******************************************************************/
/***         Note: All the data in the file is readable,         ***/
/***     And any editing will affect the controller's behavior,  ***/
/***          So It's not recommended to edit any data,          ***/
/***   Unless you are sure of what is the effect on behaviors.   ***/
/*******************************************************************/


#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

	//Standard libraries Section
	#include "../../../LIB/BIT_MATH.h"
	#include "../../../LIB/STD_TYPES.h"

	/* Defining global values of ports and pins */
	#define DIO_REF_PORTA		0
	#define DIO_REF_PORTB		1
	#define DIO_REF_PORTC		2
	#define DIO_REF_PORTD		3
	
	#define B0 0
	#define B1 1
	#define B2 2
	#define B3 3
	#define B4 4
	#define B5 5
	#define B6 6
	#define B7 7
	
	#define PORT_OUTPUT	0xFF
	#define OUTPUT 1
	#define INPUT 0
	
	#define HIGH 1
	#define LOW 0
	
	#define PORT_MAX 0xFF
	
	/* Declaring the driver functions */
	/* Set direction of PORTx functions */
	void DIO_void_set_port_dir(u8, u8 ); //inputs:: port group: 0:A, 1:B, 2:C and 3:D // direction: 0:Input and 1:OUTPUT
	void DIO_void_set_port_in_pullUp(u8 ); //inputs: port group: 0:A, 1:B, 2:C and 3:D
	u8 DIO_u8_get_PortDir(u8 );

	/* Set direction of PINx functions */
	void DIO_void_set_pin_dir(u8, u8, u8 ); //inputs:: port group: 0:A, 1:B, 2:C and 3:D // direction: 0:Input and 1:OUTPUT // pin number: 0:7
	void DIO_void_set_pin_in_pullUP(u8, u8 ); //inputs: port group: 0:A, 1:B, 2:C and 3:D // pin number: 0:7
	u8 DIO_u8_get_PinDir(u8, u8);
	
	/* Assign Value to output PORTx functions */
	void DIO_void_set_port(u8 ); //inputs:: port group: 0:A, 1:B, 2:C and 3:D
	void DIO_void_clear_port(u8 ); //inputs:: port group: 0:A, 1:B, 2:C and 3:D
	void DIO_void_toggle_port(u8 ); //inputs:: port group: 0:A, 1:B, 2:C and 3:D
	void DIO_void_assign_port(u8, u8 ); //inputs:: port group: 0:A, 1:B, 2:C and 3:D // port value: 0:255
	u8 DIO_u8_get_PortOut(u8 );
	
	/* Assign Value to output PINx functions */
	void DIO_void_set_pin(u8, u8 ); //inputs: port group: 0:A, 1:B, 2:C and 3:D // pin number: 0:7
	void DIO_void_clear_pin(u8, u8 ); //inputs: port group: 0:A, 1:B, 2:C and 3:D // pin number: 0:7
	void DIO_void_toggle_pin(u8, u8 ); //inputs: port group: 0:A, 1:B, 2:C and 3:D // pin number: 0:7
	void DIO_void_assign_pin(u8, u8, u8 ); //inputs: port group: 0:A, 1:B, 2:C and 3:D // pin number: 0:7 // pin value: 0:LOW and 1:HIGH
	u8 DIO_u8_get_PinOut(u8, u8);
	
	/* Get value from input PORTx functions */
	u8 DIO_u8_get_port(u8 ); //inputs: port group: 0:A, 1:B, 2:C and 3:D // return:: port value: 0:255
	
	/* Get value from input PINx functions */
	u8 DIO_u8_get_pin(u8, u8 ); //inputs: port group: 0:A, 1:B, 2:C and 3:D // pin number: 0:7 // return:: pin value: 0:LOW and 1:HIGH


#endif	//end DIO_INTERFACE_H
