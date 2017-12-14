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
