#ifndef MWTE_FFTI_H
#define MWTE_FFTI_H


#include <limits.h>
#include <math.h>

typedef double d_type;


typedef struct  {
d_type r;
d_type i;	
} num_cpx;

typedef struc {
	int d_len	// length of data
	num_cpx * data; 
	int nfft;	// number of fft_divisions
	int factor; // current sub_fft iteration
}

/*

   C_MUL(m,a,b)         : m = a*b
   C_FIXDIV( c , div )  : if a fixed point impl., c /= div. noop otherwise
   C_SUB( res, a,b)     : res = a - b
   C_SUBFROM( res , a)  : res -= a
   C_ADD( res, b , a) : res a + b
   C_ADDTO( res , a)    : res += a
 */
   
// allocates struct for fft
void mwte_fft_alloc (int nfft, d_type* data, d_len);
// converts data to fft_struct
void mwte_fft_conv_cpx (d_type* data, d_len);
// performs forward fft in-place
void mwte_ffti (int nfft, d_type* data, d_len);

#endif