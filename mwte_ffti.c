#include "mwte_ffti.h"

void inline mwte_fft_add(num_cpx* res, num_cpx a, num_cpx b) {
  res->real = a.real + b.real;\
	res->imag = a.imag + b.imag;
}

void inline mwte_fft_add_to(num_cpx* res, num_cpx a) {
  mwte_fft_add(res, *res, a);
}

// allocates struct for fft
void mwte_fft_alloc (int nfft, d_type* data, int* d_len, fft_state* state) {

}

void mwte_fft_bit_reversal_sort(num_cpx* data, int length) {
  int i, swap_index, bit_length;
  bit_length = log2(length);

  for(i = 0; i < length; i++) {

    swap_index = mwte_fft_reverse_bits(i, bit_length);

    if(i <= swap_index) {
      mwte_fft_swap_indices(data, i, swap_index);
    }
  }
}

// converts data to fft_struct
void mwte_fft_conv_cpx (d_type* data, int d_len) {

}

void inline mwte_fft_mul(num_cpx* res, num_cpx a, num_cpx b) {
  res->real = a.real * b.real;
  res->imag = a.imag * b.imag;
}

void inline mwte_fft_mul_eq(num_cpx* res, num_cpx a) {
	mwte_fft_mul(res, *res, a);
}

void inline mwte_fft_mul_scalar(num_cpx* res, d_type s) {
  res->real = res->real * s;
  res->imag = res->imag * s;
}

int inline mwte_fft_reverse_bits(unsigned int bits, unsigned int bit_length) {
  // Algorithm taken from
  // http://graphics.stanford.edu/~seander/bithacks.html
  unsigned int mask = ~0;
  while ((bit_length >>= 1)) {
    mask ^= (mask << bit_length);
    bits = ((bits >> bit_length) & mask) | ((bits << bit_length) & ~mask);
  }

  return bits;
}

void inline mwte_fft_sub(num_cpx* res, num_cpx a, num_cpx b) {
  res->real = a.real - b.real;
  res->imag = a.imag - b.imag;
}

void inline mwte_fft_sub_from(num_cpx* res, num_cpx a) {
  mwte_fft_sub(res, *res, a);
}

void inline mwte_fft_swap_indices(num_cpx* data, int i, int j) {
  num_cpx tmp = data[i];
  data[i] = data[j];
  data[j] = tmp;
}

// performs forward fft in-place
void mwte_ffti (int nfft, d_type* data, int d_len) {
  num_cpx * fft_arr = state->data; 
  int cur_fft_size = pow(2,state->iter); // calc number of groups for FFT size 1,2,4,8
}

void inline mwte_btfly2 (num_cpx * fft_arr, int N0, fft_state* state) {
  num_cpx temp;
  int offset = N0/2;
  mwte_fft_add_to(&(fft_arr[0]), fft_arr[N0/2]);
  mwte_fft_sub(&(fft_arr[offset]),fft_arr[0], fft_arr[offset]);
  d_type freq_res = (2*pi)/((d_type)N0);
  for(int i = 1; i <  offset; i++) {
    mwte_fft_w_index(&temp, freq_res, i);
    mwte_mul_eq(&(fft_arr[i + offset]), temp);
    mwte_fft_add_to(&(fft_arr[i]), temp);
    mwte_fft_sub(&(fft_arr[i + offset]),fft_arr[i], temp);
  }
}
