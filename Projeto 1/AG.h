#ifndef __AG_H__
#define __AG_H__

#include <time.h>

#define POP_INICIAL 50
#define N_GENES 4
#define VALOR_MAX 100
#define GERACAO_SECCAO 25

/*Cada indivíduo possui um código genético que definirá sua forma para
 * com o ambiente, e uma nota de linguagem que poderá facilitar sua
 * interação com outros indivíduos*/

struct individuo {
	int * codigo_genetico;
	int linguagem;
}

typedef struct individuo Individuo;


/*Cria um vetor de indivíduos com códigos genéticos e notas de linguagem
 * aleatórios*/
Individuo * inicia_populacao ();

void exporta_geracao(Individuo * populacao, int n_individuos, FILE * pa, int n_geracao);

void libera_individuos(Individuo * populacao);

#endif
