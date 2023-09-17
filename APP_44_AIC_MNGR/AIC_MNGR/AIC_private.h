/*******************************************************************/
/***               Date: 6/9/2023	Day: Saturday                ***/
/*** Analog Input Channel Mngr for the microcontroller ATMega 32 ***/
/***     Created By: Omar Abdul Qadir	 Version= 1.0            ***/
/*******************************************************************/
/***         Note: All the data in the file is readable,         ***/
/***     And any editing will affect the controller's behavior,  ***/
/***          So It's not recommended to edit any data,          ***/
/***   Unless you are sure of what is the effect on behaviors.   ***/
/*******************************************************************/

#ifndef AIC_PRIVATE_H_
#define AIC_PRIVATE_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#define	NULL			(void*)0

#define AIC_ADIE		0
#define AIC_ADTS		0
#define AIC_ADATE		0

#define	E_OK			1
#define E_NOT_OK		0

typedef	struct{
	u8 AIC_initFlag : 1;
	u8 AIC_ChEN		: 7;
}AIC_EnFlag_t;

#endif /* AIC_MNGR_AIC_PRIVATE_H_ */
