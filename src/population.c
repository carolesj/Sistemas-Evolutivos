#include "population.h"
#include <stdio.h>

int select_random_animal(POPULATION* population, int population_size) {
	int animal1 = random_between(0, population_size);
	int count = 0;

	while (count < population_size && !population[animal1]) {
		count++;
		animal1 = ((animal1 + 1) % (population_size + 1));
	}

	return (count < population_size) ? animal1 : -1;
}

ANIMAL* extract_contestant(POPULATION* population, int population_size) {
	int animal = select_random_animal(population, population_size);
	if (animal < 0) {
		return NULL;
	} else {
		ANIMAL* ret = population[animal];
		population[animal] = NULL;
		return ret;
	}
}

/**
 * select 2 contestants
 * @return array of 2 contestants
 */
POPULATION* choose_contestants(POPULATION* population, int population_size) {
	POPULATION* ret = malloc(sizeof(POPULATION) * 2);

	ret[0] = extract_contestant(population, population_size);

	ret[1] = extract_contestant(population, population_size);
	
	if (ret[0] < 0x10000 || ret[0] > 0xffffffffffff) {
		ret[0] = ret[1];
	}
	
	if (ret[1] < 0x10000 || ret[1] > 0xffffffffffff) {
		ret[1] = ret[0];
	}

	//if (!ret[1]) ret[1] = ret[0];

	return ret;
}

POPULATION* copy_population(POPULATION* population, int population_size) {
	POPULATION* copy = malloc(sizeof(POPULATION) * population_size);
	for (int i = 0; i < population_size; i++){
		copy[i] = copy_animal(population[i]);
	}
	return copy;
}

void export_population(POPULATION* population, int population_size, ENVIRONMENT* env, int index, FILE* file) {
	/*
	 * index, chromo[i]->speed, metabolism, cold_resistance, power, rest_time, thirst
	 */
	for (int i = 0; i < population_size; i++){
		CHROMOSSOME* i_chromo = get_chromossome(population[i]);
		fprintf(file, "%d,%d,%f,%f,%f,%f,%f,%f,%f\n",
                get_evolutionary_pressure(population[i]),
                index,
				chromo_get_speed(i_chromo),
				chromo_get_metabolism(i_chromo),
				chromo_get_cold_resistance(i_chromo),
				chromo_get_power(i_chromo),
				chromo_get_rest_time(i_chromo),
				chromo_get_thirst(i_chromo),
                get_fitness(population[i], env)
			   );
	}
}

void free_population(POPULATION* population, int population_size) {
	if (!population) return;
	for (int i = 0; i < population_size; i++){
		if (population[i]) free_animal(&population[i]);
	}
	free(population);
}
