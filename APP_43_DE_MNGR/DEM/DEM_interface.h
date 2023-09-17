/*******************************************************************/
/***               Date: 6/9/2023	Day: Saturday                ***/
/***  Diagnostic Event Manger for the microcontroller ATMega 32  ***/
/***     Created By: Omar Abdul Qadir	 Version= 1.0            ***/
/*******************************************************************/
/***         Note: All the data in the file is readable,         ***/
/***     And any editing will affect the controller's behavior,  ***/
/***          So It's not recommended to edit any data,          ***/
/***   Unless you are sure of what is the effect on behaviors.   ***/
/*******************************************************************/

#ifndef DEM_INTERFACE_H_
#define DEM_INTERFACE_H_

/*
 * Diagnostic Event Manger
 * This module is responsible for error handling during the runtime,
 * Also responsible for some over internet diagnositic services:
 * 		-> Flasing over the air (FOTA)
 * 		-> Read data by identifier
 * 		-> Write data by identifier
 * 		-> Backup Errors
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../NvM/NvM_interface.h"
#include "../IMS/IMS_interface.h"

// DEM Init
void DEM_Init( void );

// DEM Report an error
void DEM_ReportError( u8, u8, u8 );

// DEM Report a state
void DEM_ReportState( u8, u8, u8 );

// DEM Respond to a Diagnosis
void DEM_RespondToDiagnosis( u8 );

#endif /* DEM_INTERFACE_H_ */
