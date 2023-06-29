/*******************************************************************/
/***               Date: 02/6/2023	Day: Thursday                ***/
/***	Stepper-Motor driver for the microcontroller ATMega 32   ***/
/***    	 Created By: Omar Abdul Qadir	 Version= 1.0		 ***/
/*******************************************************************/
/***         Note: All the data in the file is readable,         ***/
/***     And any editing will affect the controller's behavior,  ***/
/***          So It's not recommended to edit any data,          ***/
/***   Unless you are sure of what is the effect on behaviors.   ***/
/*******************************************************************/

//Standard libraries Section
#include <util/delay.h>
#include "../../../LIB/BIT_MATH.h"
#include "../../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"

//Private libraries Section
#include "ST_Motor_interface.h"

//Global variables
// Stepper motor steps array
static u8 steps_array[8]= {1, 3, 2, 6, 4, 12, 8, 9};


/* Implementing of the driver functions */
void st_mot_void_init(stepper_struct* ptr_stepper){
	/*
	 *	Function configurs the coil pins as output
	 *	Intputs::
	 *			ptr_steppe>> Srepper motor struct
	 *	
	 *	Function does not return any value, Hence it need to be called for each stepper motor to be configured,
	 *	or the motor behavior will not be as expected.
	 */
	// Configuring the stepper pins directioin
	DIO_void_set_pin_dir(ptr_stepper -> port, ptr_stepper -> coil1, OUTPUT);
	DIO_void_set_pin_dir(ptr_stepper -> port, ptr_stepper -> coil2, OUTPUT);
	DIO_void_set_pin_dir(ptr_stepper -> port, ptr_stepper -> coil3, OUTPUT);
	DIO_void_set_pin_dir(ptr_stepper -> port, ptr_stepper -> coil4, OUTPUT);
}

void st_mot_stop(stepper_struct* ptr_stepper){
	/*
	 *	Function stops the stepper motor
	 *	Intputs::
	 *			ptr_steppe>> Srepper motor struct
	 *	
	 *	Function does not return any value. It just power off all motor pins.
	 */
	// Set All pins to Low
	DIO_void_clear_pin(ptr_stepper -> port, ptr_stepper -> coil1);
	DIO_void_clear_pin(ptr_stepper -> port, ptr_stepper -> coil2);
	DIO_void_clear_pin(ptr_stepper -> port, ptr_stepper -> coil3);
	DIO_void_clear_pin(ptr_stepper -> port, ptr_stepper -> coil4);
}

void st_mot_void_steps_CW(stepper_struct* ptr_stepper, u8 copy_u8_no_steps ){
	/*
	 *	Function rotates the stepper motor in CW direction
	 *	Intputs::
	 *			ptr_steppe>> Srepper motor struct
	 *			copy_u8_no_steps>> Number of steps that needed to be performed.
	 *	
	 *	Function does not return any value. It just rotate the motor in CW direction with gevin number of steps
	 */
	// Check the mode value of the stepper to move accordingly
	// First mode full step single coil
	if((ptr_stepper -> mode) == 0){
		// Loop till the end of the steps
		while (0 != copy_u8_no_steps){
			// Create the next step variable to store the calculated step index
			u8 next_step;
			// Check the current step value till max to reset
			if((ptr_stepper -> step) <= 3)
				// Calculate the step index from the stepper current step
				next_step = (ptr_stepper -> step)*2;
			else{
				// Reset the step counter if more than max index
				(ptr_stepper -> step)= 3;
				next_step = 6;
			}
			// Convert the dec step value to bits then set the stepper pins to thier values
			DIO_void_assign_pin(ptr_stepper -> port, ptr_stepper -> coil1, get_bit(steps_array[next_step], 0));
			DIO_void_assign_pin(ptr_stepper -> port, ptr_stepper -> coil2, get_bit(steps_array[next_step], 1));
			DIO_void_assign_pin(ptr_stepper -> port, ptr_stepper -> coil3, get_bit(steps_array[next_step], 2));
			DIO_void_assign_pin(ptr_stepper -> port, ptr_stepper -> coil4, get_bit(steps_array[next_step], 3));
			// Decrement the stepper current step value
			ptr_stepper -> step -= 1;
			// Decrement the step counter
			copy_u8_no_steps--;
			// Delay for requested frequency
			_delay_ms(10);
			}
	}
	// First mode full step double coil
	else if((ptr_stepper -> mode) == 1){
		// Loop till the end of the steps
		while (0 != copy_u8_no_steps){
			// Create the next step variable to store the calculated step index
			u8 next_step;
			// Check the current step value till max to reset
			if((ptr_stepper -> step) <= 3)
				// Calculate the step index from the stepper current step
				next_step = ((ptr_stepper -> step)*2)+1;
			else{
				// Reset the step counter if more than max index
				(ptr_stepper -> step)= 3;
				next_step = 7;
			}
			// Convert the dec step value to bits then set the stepper pins to thier values
			DIO_void_assign_pin(ptr_stepper -> port, ptr_stepper -> coil1, get_bit(steps_array[next_step], 0));
			DIO_void_assign_pin(ptr_stepper -> port, ptr_stepper -> coil2, get_bit(steps_array[next_step], 1));
			DIO_void_assign_pin(ptr_stepper -> port, ptr_stepper -> coil3, get_bit(steps_array[next_step], 2));
			DIO_void_assign_pin(ptr_stepper -> port, ptr_stepper -> coil4, get_bit(steps_array[next_step], 3));
			// Decrement the stepper current step value
			ptr_stepper -> step -= 1;
			// Decrement the step counter
			copy_u8_no_steps--;
			// Delay for requested frequency
			_delay_ms(10);
		}
	}
	// First mode half step
	else{
		// Loop till the end of the steps
		while (0 != copy_u8_no_steps){
			// Create the next step variable to store the calculated step index
			u8 next_step;
			// Check the current step value till max to reset
			if((ptr_stepper -> step) <= 7)
				// Calculate the step index from the stepper current step
				next_step= (ptr_stepper -> step);
			else{
				// Reset the step counter if more than max index
				(ptr_stepper -> step)= 7;
				next_step= 7;
			}
			// Convert the dec step value to bits then set the stepper pins to thier values
			DIO_void_assign_pin(ptr_stepper -> port, ptr_stepper -> coil1, get_bit(steps_array[next_step], 0));
			DIO_void_assign_pin(ptr_stepper -> port, ptr_stepper -> coil2, get_bit(steps_array[next_step], 1));
			DIO_void_assign_pin(ptr_stepper -> port, ptr_stepper -> coil3, get_bit(steps_array[next_step], 2));
			DIO_void_assign_pin(ptr_stepper -> port, ptr_stepper -> coil4, get_bit(steps_array[next_step], 3));
			// Decrement the stepper current step value
			ptr_stepper -> step -= 1;
			// Decrement the step counter
			copy_u8_no_steps--;
			// Delay for requested frequency
			_delay_ms(10);
		}
	}
	st_mot_stop(ptr_stepper);
}

void st_mot_void_steps_CCW(stepper_struct* ptr_stepper, u8 copy_u8_no_steps){
	/*
	 *	Function rotates the stepper motor in CCW direction.
	 *	Intputs::
	 *			ptr_steppe>> Srepper motor struct
	 *			copy_u8_no_steps>> Number of steps that needed to be performed.
	 *	
	 *	Function does not return any value. It just rotate the motor in CCW direction with gevin number of steps	 */
	if((ptr_stepper -> mode) == 0){
		// Loop till the end of the steps
			while (0 != copy_u8_no_steps){
				// Create the next step variable to store the calculated step index
				u8 next_step;
				// Check the current step value till max to reset
				if((ptr_stepper -> step) <= 3)
					// Calculate the step index from the stepper current step
					next_step = (ptr_stepper -> step)*2;
				else{
					// Reset the step counter if more than max index
					(ptr_stepper -> step)= 0;
					next_step = 0;
				}
				// Convert the dec step value to bits then set the stepper pins to thier values
				DIO_void_assign_pin(ptr_stepper -> port, ptr_stepper -> coil1, get_bit(steps_array[next_step], 0));
				DIO_void_assign_pin(ptr_stepper -> port, ptr_stepper -> coil2, get_bit(steps_array[next_step], 1));
				DIO_void_assign_pin(ptr_stepper -> port, ptr_stepper -> coil3, get_bit(steps_array[next_step], 2));
				DIO_void_assign_pin(ptr_stepper -> port, ptr_stepper -> coil4, get_bit(steps_array[next_step], 3));
				// Increment the stepper current step value
				ptr_stepper -> step += 1;
				// Decrement the step counter
				copy_u8_no_steps--;
				// Delay for requested frequency
				_delay_ms(10);
				}
		}
		else if((ptr_stepper -> mode) == 1){
			// Loop till the end of the steps
			while (0 != copy_u8_no_steps){
				// Create the next step variable to store the calculated step index
				u8 next_step;
				// Check the current step value till max to reset
				if((ptr_stepper -> step) <= 3)
					// Calculate the step index from the stepper current step
					next_step = ((ptr_stepper -> step)*2)+1;
				else{
					// Reset the step counter if more than max index
					(ptr_stepper -> step)= 0;
					next_step = 1;
				}
				// Convert the dec step value to bits then set the stepper pins to thier values
				DIO_void_assign_pin(ptr_stepper -> port, ptr_stepper -> coil1, get_bit(steps_array[next_step], 0));
				DIO_void_assign_pin(ptr_stepper -> port, ptr_stepper -> coil2, get_bit(steps_array[next_step], 1));
				DIO_void_assign_pin(ptr_stepper -> port, ptr_stepper -> coil3, get_bit(steps_array[next_step], 2));
				DIO_void_assign_pin(ptr_stepper -> port, ptr_stepper -> coil4, get_bit(steps_array[next_step], 3));
				// Increment the stepper current step value
				ptr_stepper -> step += 1;
				// Decrement the step counter
				copy_u8_no_steps--;
				// Delay for requested frequency
				_delay_ms(10);
			}
		}
		else{
			// Loop till the end of the steps
			while (0 != copy_u8_no_steps){
				// Create the next step variable to store the calculated step index
				u8 next_step;
				// Check the current step value till max to reset
				if((ptr_stepper -> step) <= 7)
					// Calculate the step index from the stepper current step
					next_step= (ptr_stepper -> step);
				else{
					// Reset the step counter if more than max index
					(ptr_stepper -> step)= 0;
					next_step= 0;
				}
				// Convert the dec step value to bits then set the stepper pins to thier values
				DIO_void_assign_pin(ptr_stepper -> port, ptr_stepper -> coil1, get_bit(steps_array[next_step], 0));
				DIO_void_assign_pin(ptr_stepper -> port, ptr_stepper -> coil2, get_bit(steps_array[next_step], 1));
				DIO_void_assign_pin(ptr_stepper -> port, ptr_stepper -> coil3, get_bit(steps_array[next_step], 2));
				DIO_void_assign_pin(ptr_stepper -> port, ptr_stepper -> coil4, get_bit(steps_array[next_step], 3));
				// Increment the stepper current step value
				ptr_stepper -> step += 1;
				// Decrement the step counter
				copy_u8_no_steps--;
				// Delay for requested frequency
				_delay_ms(10);
			}
	}
	st_mot_stop(ptr_stepper);
}
