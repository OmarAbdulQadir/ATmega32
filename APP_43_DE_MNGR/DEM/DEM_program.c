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


#include "DEM_interface.h"
#include "DEM_private.h"
#include "DEM_config.h"


// DEM Init
void DEM_Init( void )
{
	/*
	 *
	 */
}

// DEM Report an error
void DEM_ReportError( u8 copy_ModuleID, u8 copy_ServiceID, u8 copy_ErrorID )
{
	/*
	 *
	 */
}

// DEM Report a state
void DEM_ReportState( u8 copy_ModuleID, u8 copy_ServiceID, u8 copy_StateID )
{
	/*
	 *
	 */
}

// DEM Respond to a Diagnosis
void DEM_RespondToDiagnosis( u8 copy_ServiceID )
{
	/*
	 *
	 */
}

// DEM Read Data by identfier
u8 DEM_ReadDataByID( u8 copy_DataID)
{
	/*
	 *
	 */
	return 0;
}

// DEM Write Data by identifier
u8 DEM_WriteDataByID( u8 copy_DataID, u8 copy_Data)
{
	/*
	 *
	 */
	return 0;
}

// DEM Backup Errors
u8* DEM_BackupErrors( void )
{
	/*
	 *
	 */
	return NULL;
}

// DEM Erase Flash
u8 DEM_EraseFlash( void )
{
	/*
	 *
	 */
	return 0;
}

// DEM Write Flash
u8 DEM_WriteFlash( u8* ptr64Wu16_FlashPageData )
{
	/*
	 *
	 */
	return 0;
}


// DEM main
void DEM_main( void ){
	/*
	 *
	 */
	// Setup Section

	while(1){
		// super loop section

	}
}
