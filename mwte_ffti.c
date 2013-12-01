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

}
