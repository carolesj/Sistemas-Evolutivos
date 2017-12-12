#ifndef POPULATION_T
#define POPULATION_T

#include "animal.h"

typedef ANIMAL* POPULATION;

int select_random_animal(POPULATION* population, int population_size);

/**
 * select 2 contestants
 * @return array of 2 contestants
 */
POPULATION* choose_contestants(POPULATION* population, int population_size);

POPULATION* copy_population(POPULATION* population, int population_size);

void free_population(POPULATION* population, int population_size);

#endif /* POPULATION_T */
