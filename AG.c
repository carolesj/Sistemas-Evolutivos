#include <stdlib.h>
#include <time.h>
#include <limits.h>

typedef struct individuo {
	int codigo_genetico;
	double fitness;
} Individuo;

/*Cria uma população inicial aleatória com n indivíduos*/
Individuo * inicia_populacao (int n, int max = INT_MAX) {
	Individuo * populacao;
	int i;
	
	populacao = malloc(sizeof(Individuo) * n);
	
	srand(time(NULL));
	for (i = 0; i < n; i++) {
		(*(populacao + i)).codigo_genetico = rand()%max;
	}
	
	return populacao;
}

/*Avalia a população baseada na equação de fitness escolhida e atribui
 * a cada indivíduo sua nota. A equação usada aqui é
 * fitness = valor do código genético*/
void avalia_populacao (int n, Individuo * populacao) {
	int i;
	
	for (i = 0; i < n; i++) {
		*(populacao + i).fitness = *(populacao + i).codigo_genetico;
	}
	
	return;
}

/*Acha o indivíduo que possui melhor avaliação e o retorna*/
Individuo acha_melhor (int n, Individuo * populacao) {
	int i;
	int posicao = 0;
	
	for (i = 1; i < n; i++) {
		if(*(populacao + i).fitness > *(populacao + posicao).fitness) {
			posicao = i;
		}
	}
	
	return *(populacao + posicao);
}


void reproduz (int n, int max_individuos, Individuo ** populacao) {
	
}
