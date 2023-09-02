/*******************************************************************/
/***               Date: 2/9/2023	Day: Saturday                ***/
/***    DIOC Manager for the microcontroller ATMega 32 		     ***/
/***     Created By: Omar Abdul Qadir	 Version= 1.0            ***/
/*******************************************************************/
/***         Note: All the data in the file is readable,         ***/
/***     And any editing will affect the controller's behavior,  ***/
/***          So It's not recommended to edit any data,          ***/
/***   Unless you are sure of what is the effect on behaviors.   ***/
/*******************************************************************/

#ifndef DIOC_MNGR_DIOC_PRIVATE_H_
#define DIOC_MNGR_DIOC_PRIVATE_H_

typedef struct{
	u8 DIOC_PortID : 4;
	u8 DIOC_PinID  : 4;
}DIOC_Channel;


#define	E_OK		1
#define E_NOT_OK	0

#endif /* DIOC_MNGR_DIOC_PRIVATE_H_ */
