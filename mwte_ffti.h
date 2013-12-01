#ifndef MWTE_FFT_IN_PLACE_H
#define MWTE_FFT_IN_PLACE_H


#include <limits.h>
#include <math.h>

typedef double d_type;


typedef struct  {
d_type real;
d_type imag;	
} num_cpx;

typedef struc {
	int nfft;	// number of fft_divisions
	int d_len	// length of data
	num_cpx * data;
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

#define MUL(res,a,b) \
	do{
		res.real = a.real * b.real;\
		res.imag = a.imag * b.imag; } while(0)
#define MULEQ (res,a) \
	MUL(res,res,a)
#define MULSCALAR(res,s) \
	do{
		res.real = res.real * s;\
		res.imag = res.imag * s; } while(0)
#define SUB(res, a, b) \
	do{
		res.real = a.real - b.real;\
		res.imag = a.imag - b.imag; } while(0)
#define SUBFROM(res, a) \
		SUB(res, res, a);
#define ADD(res, a, b) \
	do{
		res.real = a.real + b.real;\
		res.imag = a.imag + b.imag; } while(0)
#define ADDTO(res, a) \
		ADD(res, res, a);

// allocates struct for fft
void mwte_fft_alloc (int nfft, d_type* data, d_len);
// converts data to fft_struct
void mwte_fft_conv_cpx (d_type* data, d_len);
// performs forward fft in-place
void mwte_fft_in_place (int nfft, d_type* data, d_len);

#endif