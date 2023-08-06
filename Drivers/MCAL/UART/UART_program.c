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

// Standard libraries section
#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/BIT_MATH.h"

// Private libraries section
#include "UART_private.h"
#include "UART_interface.h"


// Global variables and structs
static u8* UART_copy_ptr_str = NULL;
static void (*UART_Rx_callback)(u8 ) = NULL;


/******************************************************************************/
/* Functions implementation section */
void UART_void_init(void ){
	/*
	 *
	 */
	// Set the buad rate
	UART_UBRRH = UART_UBRRH_val;
	UART_UBRRL = UART_UBRRL_val;


	// Configure the control and status regester
	UART_UCSRB = ((UART_enable << UART_UCSRB_RXCIE) | (UART_enable << UART_UCSRB_TXCIE) | (UART_disable << UART_UCSRB_UDRIE) | (UART_enable << UART_UCSRB_RXEN) | (UART_enable << UART_UCSRB_TXEN) | (UART_disable << UART_UCSRB_UCSZ2) | (UART_disable));
	UART_UCSRC = (UART_UCSRC_mask | (UART_disable << UART_UCSRC_UMSEL) | (UART_parity_mode << UART_UCSRC_UPM) | (UART_disable << UART_UCSRC_USBS) | (UART_UCSZ_val << UART_UCSRC_UCSZ) | (UART_disable << UART_UCSRC_UCPOL));

	// Enable global interrupt
	set_bit(UART_SREG, UART_global_int);
}

u8 UART_u8_if_available(void ){
	/*
	 *
	 */
	return get_bit(UART_UCSRA, UART_UCSRA_UDRE);
}

void UART_void_transmit_char(u8 copy_data_byte){
	/*
	 *
	 */
	while(UART_u8_if_available() == 0);
	UART_UDR = copy_data_byte;
}

void UART_void_transmit_str(u8* copy_ptr_str){
	/*
	 *
	 */
	static u8 str_index = 0;
	if(*(copy_ptr_str + str_index) == '\0'){
		str_index = 0;
		UART_copy_ptr_str= NULL;
	}
	else{
		if(str_index == 0){
			UART_copy_ptr_str = copy_ptr_str;
		}
		UART_void_transmit_char(*(copy_ptr_str + str_index));
			str_index++;
	}
}

void UART_void_set_Rx_callback(void (*copy_ptr_callback)(u8 )){
	/*
	 *
	 */
	UART_Rx_callback = copy_ptr_callback;
}

// UART, Rx complete
void __vector_13(void){
	/*
	 *
	 */
	if(UART_Rx_callback != NULL){
		UART_Rx_callback(UART_UDR);
	}
}

// USART Data Register Empty
void __vector_14(void){
	/*
	 *
	 */

}

// UART, Tx complete
void __vector_15(void){
	/*
	 *
	 */
	UART_void_transmit_str(UART_copy_ptr_str);
}
