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
	// Enable
	#define I2C_enable			1
	// Disable
	#define I2C_disable			0
	// Status word mask
	#define I2C_TWS_mask		0b1111100
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
	#define ADC_SREG			*((volatile u8*) 0x5F)
	
	/* ISR decleration */
	// TWI serial interface interrupt
	void __vector_19(void)__attribute__((signal));
	
	/* Helper functions */
	// Master send one byte data
	void I2C_u8_master_sent_byte(u8 );
	// Master recive one byte data
	void I2C_master_recive_byte(void );

#endif /* end SPI_PRIVATE_H */
