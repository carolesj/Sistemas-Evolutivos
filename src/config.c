#include "config.h"

struct coeficients get_coeficients() {
	struct coeficients config;

	config.food = FOOD;
	config.temperature = TEMPERATURE;
	config.waterness = WATERNESS;
	config.predation = PREDATION;
	config.speed_predation = SPEED_PREDATION;
	config.speed_speed = SPEED_SPEED;
	config.metabolism_speed = METABOLISM_SPEED;
	config.metabolism_temp = METABOLISM_TEMP;
	config.cold_resistance_food = COLD_RESISTANCE_FOOD;
	config.cold_resistance_waterness = COLD_RESISTANCE_WATERNESS;
	config.cold_resistance_temp = COLD_RESISTANCE_TEMP;
	config.rest_food = REST_TIME_FOOD;
	config.rest_predation = REST_TIME_PREDATION;
	config.rest_temp = REST_TIME_TEMP;
	config.thirst_speed = THIRST_SPEED;
	config.thirst_waterness = THIRST_WATERNESS;
	config.thirst_temp = THIRST_TEMP;
	config.fitness = FITNESS;
	config.power = POWER;

	return config;
}
