#ifndef STD_types_h
#define STD_types_h

	// Decimal type unsigned value with 8 bits size
	typedef unsigned char u8;
	typedef signed char s8;
	typedef unsigned short u16;
	typedef signed short s16;
	typedef unsigned long u32;
	typedef signed long s32;
	typedef unsigned long long int u64;
	typedef signed long long int s64;
	typedef float f32;
	typedef double f64;

	typedef unsigned char STD_ReturnType;
	
	#define STD_TRUE	1
	#define STD_FALSE	0

	/* Comment: 8bit register                               */
	typedef union{
		struct{
			u8 BIT0:1;
			u8 BIT1:1;
			u8 BIT2:1;
			u8 BIT3:1;
			u8 BIT4:1;
			u8 BIT5:1;
			u8 BIT6:1;
			u8 BIT7:1;
		}BitAccess;
		u8 ByteAccess;
	}Register_8Bit;
	
#endif
