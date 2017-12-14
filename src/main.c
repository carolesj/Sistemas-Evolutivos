#include <stdlib.h>
#include <stdio.h>
#include "tournament.h"

#define POPULATION_SIZE 16
#define MAX_GENERATION 30
#define SECTION_GENERATION 10
#define MERGE_GENERATION 20
#define MUTATION_PROBABILITY 0.2
#define MUTATION_FACTOR_1 0.1
#define MUTATION_FACTOR_2 0.3

#define EXPORT_NAME "nature's_beautiful.dat"

enum epochs {
	EPOCH_1,
	EPOCH_2a,
	EPOCH_2b,
	EPOCH_3,
	TOTAL_EPOCHS
};

void run_epoch(POPULATION* population, int population_size, ENVIRONMENT* env, int max_generations, FILE* file){
	for (int i = 0; i < max_generations; i++){
		printf("Generation %d\n", i);
		POPULATION* gen_winners = tournament(population, population_size, env);
		free_population(population, population_size);
		population = calloc(population_size, sizeof(POPULATION));
		for (int j = 0; j < population_size/2; j += 2){
			printf("Generation %d - Population: %d\n", i, j);
			if (j == 6) {
				printf("foi seis\n");
			}
			population[j] = gen_winners[j];
			population[j+1] = gen_winners[j+1];
			ANIMAL* one = population[j];
			ANIMAL* two = population[j+1];
			population[population_size/2 + j] = intercourse(one, two, MUTATION_FACTOR_1, MUTATION_PROBABILITY);
			population[population_size/2 + j+1] = intercourse(one, two, MUTATION_FACTOR_2, MUTATION_PROBABILITY);
		}
		export_population(population, population_size, i, file);
	}
}

int main (/*int argc, char ** argv*/) {
	srand(time(NULL));
	POPULATION* population;

	ENVIRONMENT* env[] = {
		// EPOCH_1
		new_environment(0.4, 0.5, 0.9, 0.2),
		// EPOCH_2a
		new_environment(0.4, 0.5, 0.9, 0.2),
		// EPOCH_2b
		new_environment(0.4, 0.5, 0.9, 0.2),
		// EPOCH_3
		new_environment(0.4, 0.5, 0.9, 0.2)
	};

	printf("Envs Declared!\n");
	population = malloc(POPULATION_SIZE * sizeof(POPULATION));

	for (int i = 0; i < POPULATION_SIZE; i++){
		population[i] = new_animal();
	}
	printf("Population Created\n");

	FILE* file = fopen(EXPORT_NAME, "a+");

	/*
	 * período pré cambriano: indivíduos aleatórios são reproduzidos entre si
	 * para se tornarem mais aptos a habitar o ambiente da EPOCH_1
	 */
	run_epoch(population, POPULATION_SIZE, env[EPOCH_1], SECTION_GENERATION, file);
	exit(0);
	printf("Ran EPOCH_1\n");
	/*
	 * período cretáceo: indivíduos são separados aleatóriamente entre dois novos
	 * ambientes, mimetizando a migração e causando a adaptação aos novos ambientes
	 * das EPOCH_2a e EPOCH_2b
	 */
	shuffle(population, POPULATION_SIZE, sizeof(POPULATION));
	POPULATION* split_population_1 = population;
	for (int i = 0; i < POPULATION_SIZE/2; i++){
		set_evolutionary_pressure(split_population_1[i], EPOCH_2a);
	}
	POPULATION* split_population_2 = population + POPULATION_SIZE/2;
	for (int i = 0; i < POPULATION_SIZE/2; i++){
		set_evolutionary_pressure(split_population_2[i], EPOCH_2b);
	}
	run_epoch(split_population_1, POPULATION_SIZE/2, env[EPOCH_2a], MERGE_GENERATION, file);
	run_epoch(split_population_2, POPULATION_SIZE/2, env[EPOCH_2b], MERGE_GENERATION, file);
	printf("Ran EPOCH_2\n");
	/*
	 * período moderno: indivíduos são reunidos novamente em um novo ambiente da EPOCH_3
	 */
	run_epoch(population, POPULATION_SIZE, env[EPOCH_3], MAX_GENERATION, file);
	printf("Ran EPOCH_3\n");

	fclose(file);

	free_population(population, POPULATION_SIZE);
	return 0;
}
