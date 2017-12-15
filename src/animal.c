#include "animal.h"
#include "config.h"
#include <stdlib.h>
#include <stdio.h>

struct animal {
	CHROMOSSOME *chromossome;
	int evolutionary_pressure;
};

ANIMAL* new_empty_animal() {
	ANIMAL* animal = malloc(sizeof(ANIMAL));
	animal->evolutionary_pressure = 0;
	return animal;
}

void set_evolutionary_pressure(ANIMAL* animal, int pressure) {
	animal->evolutionary_pressure = pressure;
}

int get_evolutionary_pressure(ANIMAL* animal) {
	return animal->evolutionary_pressure;
}

/*
 * sexual_intercourse_between_two_loving_and_consenting_adult_animals
 * SIBTLCAA
 */
ANIMAL* intercourse(ANIMAL* one, ANIMAL* two, float mutation_factor, float mutation_probability) {
	ANIMAL* baby = new_empty_animal();
    baby->evolutionary_pressure = one->evolutionary_pressure;
	baby->chromossome = gametosex(
			one->chromossome,
			two->chromossome,
			mutation_factor,
			mutation_probability
			);
	return baby;
}

ANIMAL* new_animal() {
	ANIMAL* animal = new_empty_animal();
	animal->chromossome = new_random_chromossome();
	return animal;
}

ANIMAL* copy_animal(ANIMAL* base) {
	if (!base) return NULL;
	ANIMAL* animal = new_empty_animal();
	animal->chromossome = copy_chromossome(base->chromossome);
	animal->evolutionary_pressure = base->evolutionary_pressure;
	return animal;
}

CHROMOSSOME* get_chromossome(ANIMAL* animal) {
	if (!animal) return NULL;
	return animal->chromossome;
}

float get_speed(ANIMAL* animal) {
	if (!animal) return 0;
	CHROMOSSOME* chromo = get_chromossome(animal);
	return chromo_get_speed(chromo);
}

float get_metabolism(ANIMAL* animal) {
	if (!animal) return 0;
	CHROMOSSOME* chromo = get_chromossome(animal);
	return chromo_get_metabolism(chromo);
}

float get_cold_resistance(ANIMAL* animal) {
	if (!animal) return 0;
	CHROMOSSOME* chromo = get_chromossome(animal);
	return chromo_get_cold_resistance(chromo);
}

float get_power(ANIMAL* animal) {
	if (!animal) return 0;
	CHROMOSSOME* chromo = get_chromossome(animal);
	return chromo_get_power(chromo);
}

float get_rest_time(ANIMAL* animal) {
	if (!animal) return 0;
	CHROMOSSOME* chromo = get_chromossome(animal);
	return chromo_get_rest_time(chromo);
}

float get_thirst(ANIMAL* animal) {
	if (!animal) return 0;
	CHROMOSSOME* chromo = get_chromossome(animal);
	return chromo_get_thirst(chromo);
}

void free_animal(ANIMAL** animal){
	if (*animal) free(*animal);
	animal = NULL;
}

/**
 * Fitness =
 *     food * ( [rest]rest - [cr]cr ) +
 *     predation * ( [spd]spd - [rest]rest ) +
 *     [spd]spd * ( [met]met + [thr]thr ) +
 *     waterness * ( - [thr]thr - [cr]cr)
 *
 *     [X] = coeficient of X
 *     rest = rest time
 *     cr = cold resistance
 *     spd = speed
 *     met = metabolism
 *     thr = thirst
 */
float get_fitness(ANIMAL* animal, ENVIRONMENT* env) {
	struct coeficients config = get_coeficients();

	float rest = get_rest_time(animal);
	float cr = get_cold_resistance(animal);
	float spd = get_speed(animal);
	float met = get_metabolism(animal);
	float thr = get_thirst(animal);

	float food_stuff = get_food(env) *
		((config.rest_food * rest) - (config.cold_resistance_food * cr));

	float predation_stuff = get_predation(env) *
		((config.speed_predation * spd) - (config.rest_predation * rest));

	float speed_stuff = config.speed_speed * get_speed(animal) *
		((config.metabolism_speed * met) + (config.thirst_speed * thr));

	float temperature_stuff = get_temperature(env) *
		((config.thirst_temp * thr) - (
		(config.metabolism_temp * met) +
		(config.rest_temp * rest) +
		(config.cold_resistance_temp * cr)));

	float waterness_stuff = get_waterness(env) *
		(-(config.thirst_waterness * thr) - (config.cold_resistance_waterness * cr));

	return food_stuff + predation_stuff + speed_stuff + temperature_stuff + waterness_stuff;
}
