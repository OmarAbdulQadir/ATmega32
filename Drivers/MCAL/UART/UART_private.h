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


#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

	/* Private macros section */
	// Null pointer
	#define NULL				(void* ) 0
	// enable
	#define UART_enable			1
	// disable
	#define UART_disable		0
	// Control and status register A intiation mask
	#define UART_UCSRA_mask		0b11111100
	// Control and status register C intiation mask
	#define UART_UCSRC_mask		0b10000000
	// Char size mode
	#define UART_UCSZ_val		3


	/* Configuration bits */
	// Configuration bit of register UCSRA
	// USART Receive Complete
	#define UART_UCSRA_RXC		7
	// USART Transmit Complete
	#define UART_UCSRA_TXC		6
	// USART Data Register Empty
	#define UART_UCSRA_UDRE		5
	// Frame Error
	#define UART_UCSRA_FE		4
	// Data OverRun
	#define UART_UCSRA_DOR		3
	// Parity Error
	#define UART_UCSRA_PE		2

	// Configuration bit of register UCSRB
	// RX Complete Interrupt Enable
	#define UART_UCSRB_RXCIE	7
	// TX Complete Interrupt Enable
	#define UART_UCSRB_TXCIE	6
	// USART Data Register Empty Interrupt Enable
	#define UART_UCSRB_UDRIE	5
	// Receiver Enable
	#define UART_UCSRB_RXEN		4
	// Transmitter Enable
	#define UART_UCSRB_TXEN		3
	// Character Size
	#define UART_UCSRB_UCSZ2	2
	// Receive Data Bit 8
	#define UART_UCSRB_RXB8		1
	// Transmit Data Bit 8
	#define UART_UCSRB_TXB8		0

	// Configuration bit of register UCSRC
	// USART Mode Select
	#define UART_UCSRC_UMSEL	6
	// Parity Mode
	#define UART_UCSRC_UPM		4
	// Stop Bit Select
	#define UART_UCSRC_USBS		3
	// Character Size
	#define UART_UCSRC_UCSZ		1
	// Clock Polarity
	#define UART_UCSRC_UCPOL	0

	// Configuration bit of register SREG
	// Global interrupt bit
	#define UART_global_int		7


	/* SPI Regesters section */
	// USART Baud Rate Registers - Low bits
	#define UART_UBRRL		*((volatile u8*) 0x29)
	// USART Baud Rate Registers - High bits
	#define UART_UBRRH		*((volatile u8*) 0x40)
	// USART I/O Data Register – UDR
	#define UART_UDR		*((volatile u8*) 0x2C)
	// USART Control and Status Register A
	#define UART_UCSRA		*((volatile u8*) 0x2B)
	// USART Control and Status Register B
	#define UART_UCSRB		*((volatile u8*) 0x2A)
	// USART Control and Status Register C
	#define UART_UCSRC		*((volatile u8*) 0x40)
	// Global interubt enable
	#define UART_SREG		*((volatile u8*) 0x5F)

	/* ISR decleration */
	// USART, Rx Complete
	void __vector_13(void)__attribute__((signal));
	// USART Data Register Empty
	void __vector_14(void)__attribute__((signal));
	// USART, Tx Complete
	void __vector_15(void)__attribute__((signal));

#endif /* end UART_PRIVATE_H */
