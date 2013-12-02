tests: mwte_ffti_in_place_test reverse_bit_sort_test

mwte_ffti_in_place_test: mwte_ffti.c
	gcc -Wall mwte_ffti.c tests/mwte_fft_in_place_test.c -o mwte_fft_in_place_test

reverse_bit_sort_test: mwte_ffti.c
	gcc -Wall mwte_ffti.c tests/reverse_bit_sort_test.c -o reverse_bit_sort_test

clean:
	rm reverse_bit_sort_test mwte_fft_in_place_test

