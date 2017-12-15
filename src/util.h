#ifndef UTIL_H
#define UTIL_H

#include <stdlib.h>
#include <time.h>

float random_f();

int random_between(int min, int max);

void shuffle(void *obj, size_t nmemb, size_t size);

void split_array(void** arr, size_t nmemb, size_t size, void** first_half, void** second_half);

void* merge_arrays(void** a, size_t nmemb_a, size_t size_a, void** b, size_t nmemb_b, size_t size_b);

#endif /* UTIL_H */
