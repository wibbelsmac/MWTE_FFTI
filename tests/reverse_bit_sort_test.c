#include "../mwte_ffti.h"
#include <stdio.h>

void print_num_cpx_array(num_cpx* data, int size);
void mwte_fft_bit_reversal_sort_test(int size);

void mwte_fft_bit_reversal_sort_test(int size) {
  printf("Start -- mwte_fft_bit_reversal_sort_test: size %d\n", size);

  int i;
  num_cpx arr[size];

  for(i = 0; i < size; i++) {
    arr[i].real = (d_type)i;
    arr[i].imag = 0;
  }

  mwte_fft_bit_reversal_sort(arr, size);
  print_num_cpx_array(arr, size);
  printf("End -- mwte_fft_bit_reversal_sort_test: size %d\n", size);
}

void print_num_cpx_array(num_cpx* data, int size) {
  int i;
  printf("Size: %d\n", size);
  for(i = 0; i < size; i++) {
    printf("i: %02d r: %x im: %02f\n", i, (unsigned int)data[i].real, data[i].imag);
  }
}

int main(void) {
  mwte_fft_bit_reversal_sort_test(32);
  return 0;
}
