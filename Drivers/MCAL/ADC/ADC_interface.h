/*******************************************************************/
/***               Date: 03/6/2023	Day: Saturday	             ***/
/*** 	 ADC driver for the microcontroller ATMega 32			 ***/
/***     Created By: Omar Abdul Qadir	 Version= 1.1            ***/
/*******************************************************************/
/***         Note: All the data in the file is readable,         ***/
/***     And any editing will affect the controller's behavior,  ***/
/***          So It's not recommended to edit any data,          ***/
/***   Unless you are sure of what is the effect on behaviors.   ***/
/*******************************************************************/


#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H
	
	/* ADC setting configuration struct */
	typedef struct{
		u8 MUX:	 5;		// Analog channel and gain selection bits
		u8 ADPS: 3;		// ADC prescaler select bits
		u8 ADATE: 1;	// ADC auto trigger enable bit
		u8 ADTS: 3;		// ADC trigger selection bits
		u8 ADIE: 1;		// ADC interrupt enable bit
	}ADC_config_struct;
	
	// Prescaller Values
	#define ADPS_2		1		// ADC Prescaller 2
	#define ADPS_4		2		// ADC Prescaller 4
	#define ADPS_8		3		// ADC Prescaller 8
	#define ADPS_16		4		// ADC Prescaller 16
	#define ADPS_32		5		// ADC Prescaller 32
	#define ADPS_64		6		// ADC Prescaller 64
	#define ADPS_128	7		// ADC Prescaller 128

	//Reference selection macro
	// Reference voltage selection High pin value
	#define ADC_REFS1		0
	// Reference voltage selection Low pin value
	#define ADC_REFS0		1

	/* Global functions decleration */
	// ADC Initiation
	void ADC_void_init(void );
	// ADC setting configurations
	void ADC_void_config(ADC_config_struct* );
	// ADC start converstion
	void ADC_void_start_conv(void);
	// ADC read analog data
	void ADC_void_read_data(u16 * );
	// ADC set callback function for the ISR if interrupt is enabled
	void ADC_void_INIT_callback(void (*ptr_callback_function)(u16) );

#endif	//end ADC_INTERFACE_H
