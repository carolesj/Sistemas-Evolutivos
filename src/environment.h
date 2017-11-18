#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

typedef struct env ENVIRONMENT;

ENVIRONMENT* new_empty_environment();

ENVIRONMENT* new_environment(float food, float temperature, float waterness, float predation);

float get_food(ENVIRONMENT* env);

float get_temperature(ENVIRONMENT* env);

float get_waterness(ENVIRONMENT* env);

float get_predation(ENVIRONMENT* env);

ENVIRONMENT* copy_environment(ENVIRONMENT* base);

void free_environment(ENVIRONMENT** environment);

#endif /* ENVIRONMENT_H */
