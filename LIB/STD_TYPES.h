#ifndef STD_types_h
#define STD_types_h

	// Decimal type unsigned value with 8 bits size
	typedef unsigned char u8;
	typedef signed char s8;
	typedef unsigned int u16;
	typedef signed int s16;
	typedef unsigned long u32;
	typedef signed long s32;
	typedef unsigned long long u64;
	typedef signed long long s64;
	typedef float f32;
	typedef double f64;

	
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