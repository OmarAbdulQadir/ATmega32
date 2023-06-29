/*******************************************************************/
/***               Date: 24/6/2023	Day: Saturday	             ***/
/***  UART protocol driver for the microcontroller ATMega 32 	 ***/
/***     Created By: Omar Abdul Qadir	 Version= 1.0            ***/
/*******************************************************************/
/***         Note: All the data in the file is readable,         ***/
/***     And any editing will affect the controller's behavior,  ***/
/***          So It's not recommended to edit any data,          ***/
/***   Unless you are sure of what is the effect on behaviors.   ***/
/*******************************************************************/


#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

	/* Configuration bits section */
	// Buad rate configuration
	#define UART_Baud_Rate		9600
	// Parity mode check
	#define UART_parity_mode	0

	/* Buad rate configuration */
	#if UART_Baud_Rate ==  2400

	#define UART_UBRRL_val		207
	#define UART_UBRRH_val		128

	#elif UART_Baud_Rate == 4800

	#define UART_UBRRL_val		103
	#define UART_UBRRH_val		0

	#elif UART_Baud_Rate == 9600

	#define UART_UBRRL_val		51
	#define UART_UBRRH_val		0

	#elif UART_Baud_Rate == 14400

	#define UART_UBRRL_val		34
	#define UART_UBRRH_val		0

	#elif UART_Baud_Rate == 19200

	#define UART_UBRRL_val		25
	#define UART_UBRRH_val		0

	#elif UART_Baud_Rate == 38400

	#define UART_UBRRL_val		12
	#define UART_UBRRH_val		0

	#elif UART_Baud_Rate == 250000

	#define UART_UBRRL_val		1
	#define UART_UBRRH_val		0

	#else

	#define UART_UBRRL_val		51
	#define UART_UBRRH_val		0

	#endif


	/* Function decleration section */
	// Enable UART perepheral and configure its setting
	void UART_void_init(void );
	// Check if the UART is available to send data
	u8 UART_u8_if_available(void );
	// Transmit a char
	void UART_void_transmit_char(u8 );
	// Transmit a string
	void UART_void_transmit_str(u8* );
	// Set Recive callback function
	void UART_void_set_Rx_callback(void (*copy_ptr_callback)(u8 ));

#endif /* end UART_INTERFACE_H */
