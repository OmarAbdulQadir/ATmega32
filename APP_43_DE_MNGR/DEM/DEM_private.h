/*******************************************************************/
/***               Date: 6/9/2023	Day: Saturday                ***/
/***  Diagnostic service Mngr for the microcontroller ATMega 32  ***/
/***     Created By: Omar Abdul Qadir	 Version= 1.0            ***/
/*******************************************************************/
/***         Note: All the data in the file is readable,         ***/
/***     And any editing will affect the controller's behavior,  ***/
/***          So It's not recommended to edit any data,          ***/
/***   Unless you are sure of what is the effect on behaviors.   ***/
/*******************************************************************/

#ifndef DEM_PRIVATE_H_
#define DEM_PRIVATE_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#define	NULL			(void*)0

// DEM Read Data by identfier
u8 DEM_ReadDataByID( u8 );

// DEM Write Data by identifier
u8 DEM_WriteDataByID( u8 , u8 );

// DEM Backup Errors
u8* DEM_BackupErrors( void );

// DEM Erase Flash
u8 DEM_EraseFlash( void );

// DEM Write Flash
u8 DEM_WriteFlash( u8* );

// DEM main
void DEM_main( void );

#endif /* DEM_PRIVATE_H_ */
