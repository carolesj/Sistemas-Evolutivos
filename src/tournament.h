#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include "animal.h"

typedef ANIMAL* POPULATION;

POPULATION* tournament(POPULATION* population, int population_size, ENVIRONMENT* env);

#endif /* TOURNAMENT_H */
