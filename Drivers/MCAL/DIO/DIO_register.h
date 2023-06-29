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


#ifndef DIO_REGISTER_H
#define DIO_REGISTER_H
	
	
	/* Define Port A Regesters */
	#define DIO_PINA	((volatile u8*) 0x39)
	#define DIO_DDRA	((volatile u8*) 0x3A)
	#define DIO_PORTA	((volatile u8*) 0x3B)


	/* Define Port B* Regesters */
	#define DIO_PINB	((volatile u8*) 0x36)
	#define DIO_DDRB	((volatile u8*) 0x37)
	#define DIO_PORTB	((volatile u8*) 0x38)


	/* Define Port C* Regesters */
	#define DIO_PINC	((volatile u8*) 0x33)
	#define DIO_DDRC 	((volatile u8*) 0x34)
	#define DIO_PORTC	((volatile u8*) 0x35)


	/* Define Port D* Regesters */
	#define DIO_PIND	((volatile u8*) 0x30)
	#define DIO_DDRD 	((volatile u8*) 0x31)
	#define DIO_PORTD	((volatile u8*) 0x32)

	
#endif	//end DIO_REGISTER_H
