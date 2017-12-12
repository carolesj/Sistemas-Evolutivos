#include <stdlib.h>
#include <stdio.h>
#include "tournament.h"

#define POPULATION_SIZE 10
#define MAX_GENERATION 938457
#define SECTION_GENERATION 10
#define MERGE_GENERATION 2050
#define MUTATION_PROBABILITY 0.2
#define MUTATION_FACTOR_1 0.1
#define MUTATION_FACTOR_2 0.3

int main (/*int argc, char ** argv*/) {
	POPULATION* population;

	enum envs {
		ENVIRONMENT_1,
		ENVIRONMENT_2,
		ENVIRONMENT_3,
		TOTAL_ENVIRONMENTS
	};
	ENVIRONMENT* env[] = {
		// Env 1
		new_environment(0.4, 0.5, 0.9, 0.2),
		// Env 2
		new_environment(0.4, 0.5, 0.9, 0.2),
		// Env 3
		new_environment(0.4, 0.5, 0.9, 0.2)
	};

	population = malloc(POPULATION_SIZE * sizeof(POPULATION));

	for (int i = 0; i < POPULATION_SIZE; i++){
		population[i] = new_animal();
	}

	for (int i = 0; i < MAX_GENERATION; i++){
		POPULATION* gen_winners = tournament(population, POPULATION_SIZE, env);
		free_population(population, POPULATION_SIZE);
		population = malloc(POPULATION_SIZE * sizeof(POPULATION));
		for (int i = 0; i < POPULATION_SIZE; i++){
			if (i < POPULATION_SIZE/2) {
				population[i] = gen_winners[i];
			} else {
				int n = i - POPULATION_SIZE/2;
				ANIMAL* one = gen_winners[2*n-1];
				ANIMAL* two = gen_winners[2*n];
				population[i] = intercourse(one, two, MUTATION_FACTOR_1, MUTATION_PROBABILITY);
				population[i+1] = intercourse(one, two, MUTATION_FACTOR_2, MUTATION_PROBABILITY);
			}
		}
	}

	free_population(population, POPULATION_SIZE);
	return 0;
}
