#ifndef __AG_H__
#define __AG_H__

#include <time.h>

#define POP_INICIAL 50
#define POP_MAX 100
#define VALOR_MAX 100
#define GERACAO_SECCAO 25
#define MIN_RESISTENCIA_FRIO 60
#define MIN_RESISTENCIA_CALOR 60

enum ambientes {
	UNICO,
	FRIO,
	QUENTE,
	PREDADORES,
	COMIDA,
	AGUA,
	SECO
};

enum codigo_genetico {
	VELOCIDADE,
	GASTO_DE_ENERGIA,
	SONO,
	RESISTENCIA_FRIO,
	RESISTENCIA_CALOR,
	VIOLENCIA,
	
	N_GENES
};

/*Cada indivíduo possui um código genético que definirá sua forma para
 * com o ambiente, e uma nota de linguagem que poderá facilitar sua
 * interação com outros indivíduos*/

struct individuo {
	int * codigo_genetico;
	int linguagem;
}

typedef struct individuo Individuo;

/*Struct feita para gerenciar a população e suas propriedades*/

struct gerenciador_populacao {
	Individuo * individuos;
	int tamanho_populacao;
	int capacidade_populacao;
	int n_geracao;
}

typedef struct gerenciador_populacao g_populacao;


/*Cria um vetor de indivíduos com códigos genéticos e notas de linguagem
 * aleatórios*/
void inicia_populacao ();

void exporta_geracao (FILE * pa);

void libera_individuos ();

void mata_individuos (int ambiente);

void reproduz_individuos (int ambiente);

#endif
