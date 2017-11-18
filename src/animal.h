#ifndef ANIMAL_H
#define ANIMAL_H

#include "chromossome.h"
#include "environment.h"

struct animal;

typedef struct animal ANIMAL;

ANIMAL* new_animal();

ANIMAL* copy_animal(ANIMAL* base);

CHROMOSSOME* get_chromossome(ANIMAL* animal);

float get_speed(ANIMAL* animal);

float get_metabolism(ANIMAL* animal);

float get_cold_resistance(ANIMAL* animal);

float get_power(ANIMAL* animal);

float get_rest_time(ANIMAL* animal);

float get_thirst(ANIMAL* animal);

float get_fitness(ANIMAL* animal, ENVIRONMENT* env);

void free_animal(ANIMAL** animal);

#endif /* ANIMAL_H */
