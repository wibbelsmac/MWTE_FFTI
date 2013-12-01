#ifndef MWTE_FFT_IN_PLACE_H
#define MWTE_FFT_IN_PLACE_H


#include <limits.h>
#include <math.h>

#define PI 3.14159265359
typedef double d_type;


typedef struct  {
d_type real;
d_type imag;	
} num_cpx;

typedef struct {
	int nfft;	// number of fft_divisions
	int d_len;	// length of data
	num_cpx* data;
	int factor; // current sub_fft iteration
} fft_state;

/*
   MUL(res,a,b)         : m = a*b
   MULEQ(res,a)         : m *= a
   MULSCALAR(res,a,s)         : m = a*s
   SUB( res, a,b)     : res = a - b
   SUBFROM( res , a)  : res -= a
   ADD( res, b , a) : res a + b
   ADDTO( res , a)    : res += a
 */

void inline mwte_fft_add(num_cpx* res, num_cpx a, num_cpx b);
void inline mwte_fft_add_to(num_cpx* res, num_cpx a);

// allocates struct for fft
void mwte_fft_alloc (int nfft, d_type* data, int* d_len, fft_state* state);
// sorts data by the bit reversal length must be power of 2
void mwte_fft_bit_reversal_sort(num_cpx* data, int length);
// converts data to fft_struct
void mwte_fft_conv_cpx (d_type* data, int d_len);

void inline mwte_fft_mul(num_cpx* res, num_cpx a, num_cpx b);
void inline mwte_fft_mul_eq(num_cpx* res, num_cpx a);
void inline mwte_fft_mul_scalar(num_cpx* res, d_type s);

// reverses bits up to given bit_length, bit_length must be power of two
int inline mwte_fft_reverse_bits(unsigned int bits, unsigned int bit_length);

void inline mwte_fft_sub(num_cpx* res, num_cpx a, num_cpx b);
void inline mwte_fft_sub_from(num_cpx* res, num_cpx a);

// swaps data[i] and data[j]
void inline mwte_fft_swap_indices(num_cpx* data, int i, int j);
// F_r = sum[k=0:k=N0-1](f_k * W_N0^kr)
// W_N0 = e^(2 * pi / N0)
// k = index
void inline mwte_fft_w_index(num_cpx* data, d_type min_res, int index);
// performs forward fft in-place
void mwte_fft_in_place (fft_state* state);

#endif
