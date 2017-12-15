#include <stdlib.h>
#include <string.h>
#include "util.h"

float random_f() {
    return (2 * ((float)rand()/(float)(RAND_MAX))) - 1;
}

int random_between(int min, int max) {
    return (rand() % (max + 1)) + min;
}

int rrand(int m) {
    return (int)((double)m * ( rand() / (RAND_MAX+1.0) ));
}

#define BYTE(X) ((unsigned char *)(X))
void shuffle(void *obj, size_t nmemb, size_t size) {
    void *temp = malloc(size);
    size_t n = nmemb;
    while ( n > 1 ) {
        size_t k = rrand(n--);
        memcpy(temp, BYTE(obj) + n*size, size);
        memcpy(BYTE(obj) + n*size, BYTE(obj) + k*size, size);
        memcpy(BYTE(obj) + k*size, temp, size);
    }
    free(temp);
}

void split_array(void** arr, size_t nmemb, size_t size, void** first_half, void** second_half) {
    int half = (int) (nmemb / 2);
    size_t first_half_size = size * half;
    *first_half = malloc(first_half_size);
    memcpy(*first_half, *arr, first_half_size);
    size_t second_half_size = first_half_size + (nmemb % 2)*size;
    *second_half = malloc(second_half_size);
    memcpy(*second_half, *arr + first_half_size, second_half_size);
    free(*arr);
    *arr = NULL;
}

void* merge_arrays(void** a, size_t nmemb_a, size_t size_a, void** b, size_t nmemb_b, size_t size_b){
    void* ret = malloc(nmemb_a * size_a + nmemb_b * size_b);
    memcpy(ret, *a, nmemb_a * size_a);
    memcpy(ret + nmemb_a * size_a, *b, nmemb_b * size_b);
    free(*a);
    *a = NULL;
    free(*b);
    *b = NULL;
    return ret;
}
