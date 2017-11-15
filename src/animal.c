#include "animal.h"
#include "chromossome.h"
#include <stdlib.h>

struct animal {
	CHROMOSSOME *chromossome;
};

ANIMAL* new_empty_animal() {
	ANIMAL* animal = malloc(sizeof(ANIMAL));
	return animal;
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
	return animal;
}

CHROMOSSOME* get_chromossome(ANIMAL* animal) {
	if (!animal) return NULL;
	return animal->chromossome;
}

void free_animal(ANIMAL** animal){
	if (*animal) free(*animal);
	animal = NULL;
}
