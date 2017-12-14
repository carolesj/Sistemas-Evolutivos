#ifndef UTIL_H
#define UTIL_H

#include <stdlib.h>
#include <time.h>

float random_f();

int random_between(int min, int max);

void shuffle(void *obj, size_t nmemb, size_t size);

#endif /* UTIL_H */
