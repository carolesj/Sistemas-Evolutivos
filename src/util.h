#ifndef UTIL_H
#define UTIL_H

#include <stdlib.h>
#include <time.h>

float random_f() {
	srand(time(NULL));
	return (float)rand()/(float)(RAND_MAX);
}

int random_between(int min, int max) {
	srand(time(NULL));
	return (rand() % (max + 1)) + min;
}

#endif /* UTIL_H */
