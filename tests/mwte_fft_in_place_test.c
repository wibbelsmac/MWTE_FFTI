#include "../mwte_ffti.h"
#include <stdio.h>

void print_num_cpx_array(num_cpx* data, int size);
void mwte_fft_bit_reversal_sort_test(int size);


void mwte_fft_in_place_fft_test (int size, double signal_freq, double sample_freq) {
  printf("Start -- mwte_fft_in_place_fft_test: size %d\n", size);
  double delta_samp_omega = (signal_freq/sample_freq) * 2.0 * PI;
  int i;
  num_cpx arr[size];

  for(i = 0; i < size; i++) {
    double temp = delta_samp_omega * (float)i;
    arr[i].real = cos(temp);
    printf("data %d: cos(%f) is %f\n", i, temp, arr[i].real);
    arr[i].imag = 0;
  }
  fft_state state;
  state.d_len = size;
  state.data = arr;
  mwte_fft_in_place(&state);
  print_num_cpx_array(arr, size);
  printf("End -- mwte_fft_in_place_fft_test: size %d\n", size);
}

void print_num_cpx_array(num_cpx* data, int size) {
  int i;
  printf("Size: %d\n", size);
  for(i = 0; i < size; i++) {
    printf("i: %02d r: %f im: %f MAG: %f\n", i, data[i].real, data[i].imag, sqrt(pow(data[i].real, 2.0) + pow(data[i].imag, 2.0)));
  }
}


int main(void) {
  double sample_freq = 8.0;
  double signal_freq = 2.0;
  mwte_fft_in_place_fft_test(32, signal_freq, sample_freq);
  return 0;
}
