#ifndef CHROMOSSOME_H
#define CHROMOSSOME_H

#include "util.h"

struct chromossome;

typedef struct chromossome CHROMOSSOME;

CHROMOSSOME* new_random_chromossome();

CHROMOSSOME* copy_chromossome(CHROMOSSOME* base);

CHROMOSSOME* new_chromossome(
		float speed,
		float metabolism,
		float cold_resistance,
		float power,
		float rest_time,
		float thirst
		);

CHROMOSSOME* gametosex(
		CHROMOSSOME* one,
		CHROMOSSOME* two,
		float mutation_factor,
		float mutation_probability
		);

float chromo_get_speed(CHROMOSSOME* chromossome);

float chromo_get_metabolism(CHROMOSSOME* chromossome);

float chromo_get_cold_resistance(CHROMOSSOME* chromossome);

float chromo_get_power(CHROMOSSOME* chromossome);

float chromo_get_rest_time(CHROMOSSOME* chromossome);

float chromo_get_thirst(CHROMOSSOME* chromossome);

void free_chromossome(CHROMOSSOME ** chromossome);

#endif /* CHROMOSSOME_H */
