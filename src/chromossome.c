#include "chromossome.h"
#include "util.h"
#include <time.h>
#include <stdlib.h>

struct chromossome {
	float speed;
	float metabolism;
	float cold_resistance;
	float power;
	float rest_time;
	float thirst;
};

CHROMOSSOME* new_random_chromossome() {
	return new_chromossome(
			random_f(),
			random_f(),
			random_f(),
			random_f(),
			random_f(),
			random_f()
			);
}

CHROMOSSOME* new_chromossome(
		float speed,
		float metabolism,
		float cold_resistance,
		float power,
		float rest_time,
		float thirst
		) {
	CHROMOSSOME* ret = malloc(sizeof(CHROMOSSOME));

	ret->speed = speed;
	ret->metabolism = metabolism;
	ret->cold_resistance = cold_resistance;
	ret->power = power;
	ret->rest_time = rest_time;
	ret->thirst = thirst;

	return ret;
}

CHROMOSSOME* copy_chromossome(CHROMOSSOME* base) {
	if (!base) return NULL;
	return new_chromossome(
			base->speed,
			base->metabolism,
			base->cold_resistance,
			base->power,
			base->rest_time,
			base->thirst
			);
}

float get_speed(CHROMOSSOME* chromossome) {
	if (!chromossome) return 0;
	return chromossome->speed;
}

float get_metabolism(CHROMOSSOME* chromossome) {
	if (!chromossome) return 0;
	return chromossome->metabolism;
}

float get_cold_resistance(CHROMOSSOME* chromossome) {
	if (!chromossome) return 0;
	return chromossome->cold_resistance;
}

float get_power(CHROMOSSOME* chromossome) {
	if (!chromossome) return 0;
	return chromossome->power;
}

float get_rest_time(CHROMOSSOME* chromossome) {
	if (!chromossome) return 0;
	return chromossome->rest_time;
}

float get_thirst(CHROMOSSOME* chromossome) {
	if (!chromossome) return 0;
	return chromossome->thirst;
}

void free_chromossome(CHROMOSSOME** chromossome){
	if (*chromossome) free(*chromossome);
	chromossome = NULL;
}
