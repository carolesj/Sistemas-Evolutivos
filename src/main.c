#include <stdlib.h>
#include <stdio.h>
#include "tournament.h"

#define POPULATION_SIZE 512
#define MAX_GENERATION 1000
#define SECTION_GENERATION 1000
#define MERGE_GENERATION 2000
#define MUTATION_PROBABILITY 0.2
#define MUTATION_FACTOR_1 0.1
#define MUTATION_FACTOR_2 0.3

#define DEFAULT_EXPORT_NAME "nature's_beautiful.dat"

enum epochs {
	EPOCH_1,
	EPOCH_2a,
	EPOCH_2b,
	EPOCH_3,
	TOTAL_EPOCHS
};

POPULATION* run_epoch(POPULATION* population, int population_size, ENVIRONMENT* env, int  epoch, int max_generations, FILE* file){
	for (int i = 0; i < max_generations; i++){
		POPULATION* gen_winners = tournament(population, population_size, env);
		free_population(population, population_size);
		population = calloc(population_size, sizeof(POPULATION));
		for (int j = 0; j < population_size/2; j += 2){
			printf("Epoch %d - Generation %d - Population: %d\n", epoch, i, j);
            set_evolutionary_pressure(gen_winners[j], epoch);
            set_evolutionary_pressure(gen_winners[j+1], epoch);
			population[j] = gen_winners[j];
			population[j+1] = gen_winners[j+1];
			ANIMAL* one = population[j];
			ANIMAL* two = population[j+1];
			population[population_size/2 + j] = intercourse(one, two, MUTATION_FACTOR_1, MUTATION_PROBABILITY);
			population[population_size/2 + j+1] = intercourse(one, two, MUTATION_FACTOR_2, MUTATION_PROBABILITY);
		}
        // free gen_winners
		export_population(population, population_size, env, i, file);
	}
    return population;
}

int main (int argc, char ** argv) {

    char* filename;
    if (argc < 2) {
        printf("Using default file: %s\n", DEFAULT_EXPORT_NAME);
        filename = DEFAULT_EXPORT_NAME;
    } else {
        filename = argv[1];
    }
    FILE* file = fopen(filename, "w");

	srand((unsigned int) time(NULL));
	POPULATION* population;

	ENVIRONMENT* env[] = {
        // food, temperature, waterness, predation
		// EPOCH_1
		new_environment(0.9, 0.5, 0.9, 0.1),
		// EPOCH_2a
		new_environment(0.2, 0.5, 0.5, 0.7),
		// EPOCH_2b
		new_environment(0.4, 0.8, 0.2, 0.2),
		// EPOCH_3
		new_environment(0.5, 0.2, 0.9, 0.5)
	};

	population = malloc(POPULATION_SIZE * sizeof(POPULATION));

	for (int i = 0; i < POPULATION_SIZE; i++){
		population[i] = new_animal();
	}

	/*
	 * período pré cambriano: indivíduos aleatórios são reproduzidos entre si
	 * para se tornarem mais aptos a habitar o ambiente da EPOCH_1
	 */
	population = run_epoch(population, POPULATION_SIZE, env[EPOCH_1], EPOCH_1, SECTION_GENERATION, file);
	printf("Ran EPOCH_1\n");
	/*
	 * período cretáceo: indivíduos são separados aleatóriamente entre dois novos
	 * ambientes, mimetizando a migração e causando a adaptação aos novos ambientes
	 * das EPOCH_2a e EPOCH_2b
	 */
	shuffle(population, POPULATION_SIZE, sizeof(POPULATION));
	POPULATION* split_population_1;
    POPULATION* split_population_2;
    split_array(
            (void **) &population, POPULATION_SIZE, sizeof(ANIMAL*),
            (void **) &split_population_1, (void **) &split_population_2
    );
	split_population_1 = run_epoch(
            split_population_1, POPULATION_SIZE/2,
            env[EPOCH_2a], EPOCH_2a, MERGE_GENERATION,
            file
    );
    printf("Ran EPOCH_2a\n");
	split_population_2 = run_epoch(
            split_population_2, POPULATION_SIZE/2 + (POPULATION_SIZE % 2),
            env[EPOCH_2b], EPOCH_2b, MERGE_GENERATION,
            file
    );
	printf("Ran EPOCH_2b\n");
    population = merge_arrays(
            (void **) &split_population_1, POPULATION_SIZE / 2, sizeof(ANIMAL*),
            (void **) &split_population_2, POPULATION_SIZE / 2 + (POPULATION_SIZE % 2), sizeof(ANIMAL*)
    );
    shuffle(population, POPULATION_SIZE, sizeof(POPULATION));
	/*
	 * período moderno: indivíduos são reunidos novamente em um novo ambiente da EPOCH_3
	 */

	run_epoch(population, POPULATION_SIZE, env[EPOCH_3], EPOCH_3, MAX_GENERATION, file);
	printf("Ran EPOCH_3\n");

	fclose(file);

	free_population(population, POPULATION_SIZE);
	return 0;
}
