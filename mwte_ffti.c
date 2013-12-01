#include "mwte_ffti.h"

// allocates struct for fft
void mwte_fft_alloc (int nfft, d_type* data, int* d_len, fft_state* state) {

}

void mwte_fft_bit_reversal_sort(num_cpx* data, int length) {
  int i, swap_index, bits_length;
  bit_length = log2(length);

  for(i = 0; i < length; i++) {

    swap_index = mwte_fft_reverse_bits(i, bit_length);

    if(i <= swap_index) {
      mwte_fft_swap_indices(data, i, swap_index);
    }
  }
}

// converts data to fft_struct
void mwte_fft_conv_cpx (d_type* data, d_len) {

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

void inline mwte_fft_swap_indices(num_cpx* data, int i, int j) {
  num_cpx tmp = data[i];
  data[i] = data[j];
  data[j] = tmp;
}

// performs forward fft in-place
void mwte_ffti (int nfft, d_type* data, d_len) {

}
