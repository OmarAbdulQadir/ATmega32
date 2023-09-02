/*
 * EXT_EEP_interface.h
 *
 *  Created on: Aug 20, 2023
 *      Author: Omar A.Qadir
 */

#ifndef EXT_EEP_INTERFACE_H_
#define EXT_EEP_INTERFACE_H_

	// EEPROM write data to block
	void EEP_vWriteDataToBlock(u8, u8, u8);

	// EEPROM read data from block
	u8 EEP_u8ReadDataFromBlock(u8, u8);

#endif /* EXT_EEP_INTERFACE_H_ */
