#ifndef BIT_math_h
#define BIT_math_h

	#define  set_bit(var, bit_no)          (var) |= (1 << (bit_no))
	#define  clr_bit(var, bit_no)          (var) &= (~(1 << (bit_no)))
	#define  tgl_bit(var, bit_no)          (var) ^= ((1) << (bit_no))
	#define  get_bit(var, bit_no)          ( (var) >> (bit_no) & (1) )
	#define  agn_bit(var, bit_no, val)	   do{ if(val) set_bit(var, bit_no); \
											   else clr_bit(var, bit_no);	 \
											  }while(0);
	
#endif
