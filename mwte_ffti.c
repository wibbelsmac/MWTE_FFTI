#include "mwte_ffti.h"

// allocates struct for fft
void mwte_fft_alloc (int nfft, d_type* data, int* d_len, fft_state* state) {

}

void mwte_fft_bit_reversal_sort(num_cpx* data);

// converts data to fft_struct
void mwte_fft_conv_cpx (d_type* data, d_len) {

}

int inline mwte_fft_reverse_bits(unsigned int bits, unsigned int size);

void inline mwte_fft_swap_indices(num_cpx* data, int i, int j);

// performs forward fft in-place
void mwte_ffti (int nfft, d_type* data, d_len) {
  num_cpx * fft_arr = state->data; 
  cur_fft_size = pow(2,state->iter); // calc number of groups for FFT size 1,2,4,8

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