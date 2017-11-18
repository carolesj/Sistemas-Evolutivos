#include "environment.h"
#include <stdlib.h>

struct env {
	/* amount of food in the environment */
	float food;
	/* temperature of the environment */
	float temperature;
	/* amount of hidraulic resources in the environment */
	float waterness;
	/* predation factor of the environment */
	float predation;
};

ENVIRONMENT* new_empty_environment() {
	ENVIRONMENT* environment = malloc(sizeof(ENVIRONMENT));
	return environment;
}

ENVIRONMENT* new_environment(float food, float temperature, float waterness, float predation) {
	ENVIRONMENT* environment = new_empty_environment();
	environment->food = food;
	environment->temperature = temperature;
	environment->waterness = waterness;
	environment->predation = predation;
	return environment;
}

float get_food(ENVIRONMENT* env) {
	return env->food;
}

float get_temperature(ENVIRONMENT* env) {
	return env->temperature;
}

float get_waterness(ENVIRONMENT* env) {
	return env->waterness;
}

float get_predation(ENVIRONMENT* env) {
	return env->predation;
}

ENVIRONMENT* copy_environment(ENVIRONMENT* base) {
	if (!base) return NULL;
	ENVIRONMENT* environment = new_empty_environment();
	return environment;
}

void free_environment(ENVIRONMENT** environment){
	if (*environment) free(*environment);
	environment = NULL;
}
