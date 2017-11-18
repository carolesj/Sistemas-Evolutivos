#include "util.h"

float random_f() {
	srand(time(NULL));
	return (2 * ((float)rand()/(float)(RAND_MAX))) - 1;
}

int random_between(int min, int max) {
	srand(time(NULL));
	return (rand() % (max + 1)) + min;
}
