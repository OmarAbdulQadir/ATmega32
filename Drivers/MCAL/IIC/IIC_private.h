/*******************************************************************/
/***               Date: 23/6/2023	Day: Friday		             ***/
/***  	IIC protocol driver for the microcontroller ATMega 32 	 ***/
/***     Created By: Omar Abdul Qadir	 Version= 1.0            ***/
/*******************************************************************/
/***         Note: All the data in the file is readable,         ***/
/***     And any editing will affect the controller's behavior,  ***/
/***          So It's not recommended to edit any data,          ***/
/***   Unless you are sure of what is the effect on behaviors.   ***/
/*******************************************************************/


#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H


	/* Private macros section */
	// Null pointer
	#define NULL				(void* ) 0
	// End of frame code
	#define I2C_end_frame		255
	// Repeated start code
	#define I2C_repeated_start	254
	// None condition
	#define I2C_253_None		253
	// None condition
	#define I2C_252_None		252
	// None condition
	#define I2C_251_None		251
	// Start index of the frame
	#define I2C_S_frame			0
	// Maxmum number bytes per frame
	#define I2C_max_frame		8
	// No error
	#define I2C_no_err			0
	// Error SLA+W recive NACK respond resend SLA+W
	#define I2C_20_R0			2
	// Error SLA+W recive NACK respond Repeated stop
	#define I2C_20_R1			4
	// Error SLA+W recive NACK respond Stop condition
	#define I2C_20_R2			6
	// Error DBn recive NACK respond resend DBn
	#define I2C_30_R0			8
	// Error DBn recive NACK respond Repeated stop
	#define I2C_30_R1			10
	// Error DBn recive NACK respond Stop condition
	#define I2C_30_R2			12
	// Enable
	#define I2C_enable			1
	// Disable
	#define I2C_disable			0
	// Status word mask
	#define I2C_TWS_mask		0b11111000
	// Index reset
	#define I2C_Idx_reset		0
	// Slave mode value
	#define I2C_slave			0
	// Master mode value
	#define I2C_master			1

	/* Configuration bits */
	// TWI Control Register bits
	// TWI Interrupt Flag
	#define I2C_TWCR_TWINT		7
	// TWI Enable Acknowledge Bit
	#define I2C_TWCR_TWEA		6
	// TWI START Condition Bit
	#define I2C_TWCR_TWSTA		5
	// TWI STOP Condition Bit
	#define I2C_TWCR_TWSTO		4
	// TWI Write Collision Flag
	#define I2C_TWCR_TWWC		3
	// TWI Enable Bit
	#define I2C_TWCR_TWEN		2
	// TWI Interrupt Enable
	#define I2C_TWCR_TWIE		0

	// Status Regesters bits
	// Global interrup bit
	#define I2C_glob_int		7
	
	/* I2C Regesters section */
	// TWI Bit Rate Register
	#define I2C_TWBR			*((volatile u8*) 0x20)
	// TWI Control Register
	#define I2C_TWCR			*((volatile u8*) 0x56)
	// TWI Status Register
	#define I2C_TWSR			*((volatile u8*) 0x21)
	// TWI Data Register
	#define I2C_TWDR			*((volatile u8*) 0x23)
	// TWI (Slave) Address Register
	#define I2C_TWAR			*((volatile u8*) 0x22)
	// Status register
	#define I2C_SREG			*((volatile u8*) 0x5F)

	/* Helper functions */
	// Get the value of the status regester at this time
	u8 I2C_get_status_word(void );
	// Master follow transmission process
	void I2C_master_transmit_respond(void );
	// Master follow reciving process
	void I2C_master_recive_respond(void );
	// Slave follow transmission process
	void I2C_slave_transmit_respond(void );
	// Slave follow reciving process
	void I2C_slave_recive_respond(void );

	/* ISR decleration */
	// TWI serial interface interrupt
	void __vector_19(void)__attribute__((signal));


#endif /* end SPI_PRIVATE_H */
