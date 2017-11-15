#include "tournament.h"
#include "util.h"
#include <stdlib.h>

int select_random_animal(ANIMAL** population, int population_size) {
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
ANIMAL** choose_contestants(ANIMAL** population, int population_size) {
	ANIMAL** ret = malloc(sizeof(ANIMAL*) * 2);

	int animal1 = select_random_animal(population, population_size);
	ret[0] = population[animal1];
	population[animal1] = NULL;

	int animal2 = select_random_animal(population, population_size);
	ret[1] = population[animal2];
	population[animal2] = NULL;

	return ret;
}

ANIMAL** copy_population(ANIMAL** population, int population_size) {
	ANIMAL** copy = malloc(sizeof(ANIMAL*) * population_size);
	for (int i = 0; i < population_size; i++){
		copy[i] = copy_animal(population[i]);
	}
	return copy;
}

void free_population(ANIMAL** population, int population_size) {
	if (!population) return;
	for (int i = 0; i < population_size; i++){
		if (population[i]) free_animal(&population[i]);
	}
	free(population);
}

/**
 * always 2 contestants
 * @return winner
 */
ANIMAL* battle (ANIMAL** population, int population_size) {
	ANIMAL** contestants = choose_contestants(population, population_size);
	ANIMAL* winner = contestants[0];
	ANIMAL* loser = contestants[1];

	if (contestants) free(contestants);
	if (loser) free_animal(&loser);
	return winner;
}

ANIMAL** tournament(ANIMAL** population, int population_size) {

	ANIMAL** contestants = copy_population(population, population_size);

	ANIMAL** winners = malloc(sizeof(ANIMAL*) * population_size/2);

	for (int i = 0; i < population_size/2; i++) {
		winners[i] = battle(population, population_size);
	}

	free_population(contestants, population_size);

	return winners;
}
