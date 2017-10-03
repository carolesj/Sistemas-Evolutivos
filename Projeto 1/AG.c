#include "AG.h"

Individuo * inicia_populacao () {
	int j;
	Individuo * populacao_inicial;
	srand(time(NULL));
	populacao_inicial = malloc(sizeof(individuo) * POP_INICIAL);
	
	/*Inicializa o código genético dos indivíduos de forma aleatória, assim
	 * como sua nota de linguagem*/
	for (int i = 0; i < POP_INICIAL; i++) {
		*(populacao_inicial + i) -> codigo_genetico = malloc(sizeof(int) * N_GENES);
		for (j = 0; j < N_GENES; j++) {
			*(*(populacao_inicial + i) -> codigo_genetico + j) = rand() % VALOR_MAX;
		}
		*(populacao_inicial + i) -> linguagem = rand() % VALOR_MAX;
	}
	
	return populacao_inicial;
}

void exporta_geracao(Individuo * populacao, int n_individuos, FILE * pa, int n_geracao) {
	int i, j;
	fprintf("%d:\n", n_geracao);
	for (i = 0; i < n_individuos; i++) {
		for (j = 0; j < N_GENES; j++) {
			fprintf("%d ", ((populacao + i) -> *(codigo_genetico + j)));
		}
		fprintf("%d\n", ((populacao + i) -> linguagem));
	}
	return;
}

void libera_individuos(Individuo * populacao) {
	free(populacao);
}
