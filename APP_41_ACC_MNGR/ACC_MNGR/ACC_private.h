/*******************************************************************/
/***               Date: 1/9/2023	Day: Friday                  ***/
/***     ACC Manager for the microcontroller ATMega 32 		     ***/
/***     Created By: Omar Abdul Qadir	 Version= 1.0            ***/
/*******************************************************************/
/***         Note: All the data in the file is readable,         ***/
/***     And any editing will affect the controller's behavior,  ***/
/***          So It's not recommended to edit any data,          ***/
/***   Unless you are sure of what is the effect on behaviors.   ***/
/*******************************************************************/

#ifndef ACC_MNGR_ACC_PRIVATE_H_
#define ACC_MNGR_ACC_PRIVATE_H_


typedef struct{
	u8 ACC_ControlSignalPortID : 4;
	u8 ACC_ControlSignalPinID  : 4;
	u8 ACC_StatusSignalPortID  : 4;
	u8 ACC_StatusSignalPinID   : 4;
}AC_Channel;


#define	E_OK		1
#define E_NOT_OK	0

#endif /* ACC_MNGR_ACC_PRIVATE_H_ */
