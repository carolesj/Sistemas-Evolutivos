#include "tournament.h"
#include "config.h"
#include <stdlib.h>

/**
 * always 2 contestants
 * @return winner
 */
ANIMAL* battle (POPULATION* population, int population_size, ENVIRONMENT* env) {
	POPULATION* contestants = choose_contestants(population, population_size);

	struct coeficients config = get_coeficients();

	float score0 =
		config.fitness * get_fitness(contestants[0], env) +
		config.power * get_power(contestants[0]);
	float score1 =
		config.fitness * get_fitness(contestants[1], env) +
		config.power * get_power(contestants[1]);

	ANIMAL* winner;
	ANIMAL* loser;

	if (score0 > score1) {
		winner = copy_animal(contestants[0]);
		loser = copy_animal(contestants[1]);
	} else if (score0 < score1) {
		winner = copy_animal(contestants[1]);
		loser = copy_animal(contestants[0]);
	} else {
		int selected = random_between(0, 1);
		winner = copy_animal(contestants[selected]);
		// um xor(oró sem chitãozinho)
		loser = copy_animal(contestants[selected ^ 1]);
	}

	if (contestants) free(contestants);
	if (loser) free_animal(&loser);
	return winner;
}

POPULATION* tournament(POPULATION* population, int population_size, ENVIRONMENT* env) {

	POPULATION* contestants = copy_population(population, population_size);

	POPULATION* winners = malloc(sizeof(POPULATION) * population_size/2);

	for (int i = 0; i < population_size/2; i++) {
		winners[i] = battle(contestants, population_size, env);
	}

	free_population(contestants, population_size);
	return winners;
}
