/*
 * clc.c
 *
 *  Created on: May 23, 2023
 *      Author: Omar A.Qadir
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../INC/clc.h"

static s16 res; // result variable is used to store result of the last operation, and must use a getter function to access it.

enum operations{
	mul = 42,
	add = 43,
	sub = 45,
	div = 47,
	equal= 61
};

enum values{
	ground= 0,
	active= 1,
	shift= 10,
	postive= 1,
	negative= -1,
	operation_code= 0
};

s16 calc_action(s16 op1, s16 op2, s16 operation){
	/*
	 *
	 */
	switch(operation){
		case mul:
			return op1*op2;
		case add:
			return op1+op2;
		case sub:
			return op1-op2;
		case div:
			return op1/op2;
		default:
			return 0;
	}
}

void calc(int digit, int number_flag){
	/*
	 *
	 */
	static s16 op1;
	static s16 op2;
	static u8 op_flag1 = ground, op_flag2 = ground, op1_sign = ground, op2_sign = ground;
	static u8 operation;

	if(number_flag == operation_code){
		if(digit == equal){
			res= calc_action((op1*((op1_sign == ground) ? postive:negative)), (op2*((op2_sign == ground) ? postive:negative)), operation);
			op_flag1= ground;
			op_flag2= ground;
			op1_sign= ground;
			op2_sign= ground;
			op1= ground;
			op2= ground;
			operation= ground;
		}
		else{
			if(op_flag2 == ground){
				op1= res;
			}
			operation= digit;
			op_flag1= active;
			printf("op= %c\n", operation);
		}
	}
	else if((digit == negative)&&(number_flag == negative)){
		op_flag1= ground;
		op_flag2= ground;
		op1_sign= ground;
		op2_sign= ground;
		op1= ground;
		op2= ground;
		operation= ground;
		res= ground;
	}
	else{
		if (op_flag1 == ground){
			op_flag2= active;
			if(digit == sub)
				op1_sign= active;
			else{
				op1*= shift;
				op1+= digit;
				printf("op1= %d\n", op1);
			}
		}
		else if(op_flag1 == active){
			if(digit == sub)
				op2_sign= active;
			else{
				op2*= shift;
				op2+= digit;
				printf("op2= %d\n", op2);
			}
		}
	}
}

s16 get_result(void){
	/*
	 *
	 */
	return  res;
}
