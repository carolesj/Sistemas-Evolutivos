#include "chromossome.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

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

float _gametosex_part(
		float a, float b,
		float mutation_factor,
		float mutation_probability
		) {
	float value = (a + b)/2;
	if (random_f() < mutation_probability) {
		int sign = random_between(0, 1) ? 1 : -1;
		value += mutation_factor * sign;
	}
	return value;
}

CHROMOSSOME* gametosex(
		CHROMOSSOME* one,
		CHROMOSSOME* two,
		float mutation_factor,
		float mutation_probability
		) {

	#define __mix_chromo(X) X = _gametosex_part(\
			one->X,\
			two->X,\
			mutation_factor,\
			mutation_probability\
			)

	float __mix_chromo(speed);
	float __mix_chromo(metabolism);
	float __mix_chromo(cold_resistance);
	float __mix_chromo(power);
	float __mix_chromo(rest_time);
	float __mix_chromo(thirst);

	CHROMOSSOME* c = new_chromossome(
			speed,
			metabolism,
			cold_resistance,
			power,
			rest_time,
			thirst
			);
	return c;
}

float chromo_get_speed(CHROMOSSOME* chromossome) {
	if (!chromossome) return 0;
	return chromossome->speed;
}

float chromo_get_metabolism(CHROMOSSOME* chromossome) {
	if (!chromossome) return 0;
	return chromossome->metabolism;
}

float chromo_get_cold_resistance(CHROMOSSOME* chromossome) {
	if (!chromossome) return 0;
	return chromossome->cold_resistance;
}

float chromo_get_power(CHROMOSSOME* chromossome) {
	if (!chromossome) return 0;
	return chromossome->power;
}

float chromo_get_rest_time(CHROMOSSOME* chromossome) {
	if (!chromossome) return 0;
	return chromossome->rest_time;
}

float chromo_get_thirst(CHROMOSSOME* chromossome) {
	if (!chromossome) return 0;
	return chromossome->thirst;
}

void free_chromossome(CHROMOSSOME** chromossome){
	if (*chromossome) free(*chromossome);
	chromossome = NULL;
}
