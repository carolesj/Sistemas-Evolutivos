#ifndef ANIMAL_H
#define ANIMAL_H

#include "chromossome.h"

struct animal;

typedef struct animal ANIMAL;

ANIMAL* new_animal();

ANIMAL* copy_animal(ANIMAL* base);

CHROMOSSOME* get_chromossome(ANIMAL* animal);

void free_animal(ANIMAL** animal);

#endif /* ANIMAL_H */
