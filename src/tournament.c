#include "tournament.h"
#include "config.h"
#include <stdlib.h>

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

void free_population(POPULATION* population, int population_size) {
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
ANIMAL* battle (POPULATION* population, int population_size, ENVIRONMENT* env) {
	POPULATION* contestants = choose_contestants(population, population_size);

	struct coeficients config = get_coeficients();

	float score0 = config.fitness * get_fitness(contestants[0], env) + config.power * get_power(contestants[0]);
	float score1 = config.fitness * get_fitness(contestants[1], env) + config.power * get_power(contestants[1]);

	ANIMAL* winner;
	ANIMAL* loser;

	if (score0 > score1) {
		winner = contestants[0];
		loser = contestants[1];
	} else if (score0 < score1) {
		winner = contestants[1];
		loser = contestants[0];
	} else {
		int selected = random_between(0, 1);
		winner = contestants[selected];
		loser = contestants[selected ^ 1];
	}

	if (contestants) free(contestants);
	if (loser) free_animal(&loser);
	return winner;
}

POPULATION* tournament(POPULATION* population, int population_size, ENVIRONMENT* env) {

	POPULATION* contestants = copy_population(population, population_size);

	POPULATION* winners = malloc(sizeof(POPULATION) * population_size/2);

	for (int i = 0; i < population_size/2; i++) {
		winners[i] = battle(population, population_size, env);
	}

	free_population(contestants, population_size);

	return winners;
}
