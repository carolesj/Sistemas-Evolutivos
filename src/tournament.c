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

	if (contestants[0] < 0x10000 || contestants[1] < 0x10000){
		printf("ChooseContestants deu ruim:\n0: %p\n1: %p\n", contestants[0], contestants[1]);
	}

	float score0 =
		config.fitness * get_fitness(contestants[0], env) +
		config.power * get_power(contestants[0]);
	float score1 =
		config.fitness * get_fitness(contestants[1], env) +
		config.power * get_power(contestants[1]);

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
		// um xor(oró sem chitãozinho)
		loser = contestants[selected ^ 1];
	}

	if (contestants) free(contestants);
	if (loser) free_animal(&loser);
	return winner;
}

POPULATION* tournament(POPULATION* population, int population_size, ENVIRONMENT* env) {

	printf("starting tournament\n");

	POPULATION* contestants = copy_population(population, population_size);

	POPULATION* winners = malloc(sizeof(POPULATION) * population_size/2);

	printf("battles");
	for (int i = 0; i < population_size/2; i++) {
		winners[i] = battle(contestants, population_size, env);
	}
	printf("finished tournament");

	free_population(contestants, population_size);
	return winners;
}
