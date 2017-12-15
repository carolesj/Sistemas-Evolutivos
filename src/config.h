#ifndef CONFIG_H
#define CONFIG_H

// Environment
#define FOOD 0.3
#define TEMPERATURE 0.7
#define WATERNESS 0.4
#define PREDATION 0.6
// Chromossome
#define SPEED_PREDATION 0.7
#define SPEED_SPEED 0.3
#define METABOLISM_SPEED 0.6
#define METABOLISM_TEMP 0.4
#define COLD_RESISTANCE_FOOD 0.3
#define COLD_RESISTANCE_WATERNESS 0.3
#define COLD_RESISTANCE_TEMP 0.4
#define REST_TIME_FOOD 0.2
#define REST_TIME_PREDATION 0.4
#define REST_TIME_TEMP 0.4
#define THIRST_SPEED 0.6
#define THIRST_WATERNESS 0.2
#define THIRST_TEMP 0.2
// Battle
#define FITNESS 0.7
#define POWER 0.3

struct coeficients {
	// Environment
	float food;
	float temperature;
	float waterness;
	float predation;
	// Chromossome
	float speed_predation;
	float speed_speed;
	float metabolism_speed;
	float metabolism_temp;
	float cold_resistance_food;
	float cold_resistance_waterness;
	float cold_resistance_temp;
	float rest_food;
	float rest_predation;
	float rest_temp;
	float thirst_speed;
	float thirst_waterness;
	float thirst_temp;
	// Battle
	float fitness;
	float power;
};

struct coeficients get_coeficients();

#endif /* CONFIG_H */
