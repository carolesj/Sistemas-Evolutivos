#ifndef CHROMOSSOME_H
#define CHROMOSSOME_H

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

float get_speed(CHROMOSSOME* chromossome);

float get_metabolism(CHROMOSSOME* chromossome);

float get_cold_resistance(CHROMOSSOME* chromossome);

float get_power(CHROMOSSOME* chromossome);

float get_rest_time(CHROMOSSOME* chromossome);

float get_thirst(CHROMOSSOME* chromossome);

void free_chromossome(CHROMOSSOME ** chromossome);

#endif /* CHROMOSSOME_H */
