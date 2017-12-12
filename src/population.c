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

/**
 * select 2 contestants
 * @return array of 2 contestants
 */
POPULATION* choose_contestants(POPULATION* population, int population_size) {
	POPULATION* ret = malloc(sizeof(POPULATION) * 2);

	int animal1 = select_random_animal(population, population_size);
	ret[0] = population[animal1];
	population[animal1] = NULL;

	int animal2 = select_random_animal(population, population_size);
	ret[1] = population[animal2];
	population[animal2] = NULL;

	return ret;
}

POPULATION* copy_population(POPULATION* population, int population_size) {
	POPULATION* copy = malloc(sizeof(POPULATION) * population_size);
	for (int i = 0; i < population_size; i++){
		copy[i] = copy_animal(population[i]);
	}
	return copy;
}

void export_population(POPULATION* population, int population_size, int index, FILE* file) {
	/*
	 * index, chromo[i]->speed, metabolism, cold_resistance, power, rest_time, thirst
	 */
	fprintf(file, "%d", index);
	for (int i = 0; i < population_size; i++){
		CHROMOSSOME* i_chromo = get_chromossome(population[i]);
		fprintf(file, ",%f,%f,%f,%f,%f,%f",
				chromo_get_speed(i_chromo), 
				chromo_get_metabolism(i_chromo),
				chromo_get_cold_resistance(i_chromo),
				chromo_get_power(i_chromo),
				chromo_get_rest_time(i_chromo),
				chromo_get_thirst(i_chromo)
			   );
	}
	fprintf(file, "\n");
}

void free_population(POPULATION* population, int population_size) {
	if (!population) return;
	for (int i = 0; i < population_size; i++){
		if (population[i]) free_animal(&population[i]);
	}
	free(population);
}
