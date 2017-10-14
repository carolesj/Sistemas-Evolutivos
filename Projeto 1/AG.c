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

void mata_individuos (Individuo * populacao, int * tam_populacao, int ambiente) {
	int i, j, mortos = 0;
	//mata indívidos baseando-se em suas habilidades inatas em relação
	//ao lugar onde vivem
	switch (ambiente) {
		case FRIO:
			//percorre a população e verifica se cada indivíduo possui
			//resistência ao frio maior que a mínima necessária
			for (i = 0; i < *tam_populacao; i++) {
				if ((populacao + i)->*(codigo_genetico + RESISTENCIA_FRIO) < MIN_RESISTENCIA_FRIO) {
					//se a resistência for menor que a necessária, diminui
					//o tamanho da populacao e sobrescreve o morto com os 
					//seguintes
					for (j = i; j < *tam_populacao; j++) {
						*(populacao + j) = *(populacao + j + 1);
					}
					*tam_populacao--;
				}
			}
			//realoca o vetor com a quantidade correta de indivíduos
			populacao = realloc(populacao, *tam_populacao);
			break;
		case QUENTE:
			break;
		case PREDADORES:
			break;
		case COMIDA:
			break;
		case AGUA:
			break;
		case SECO:
			break;
	}
}


Individuo * reproduz_individuos (Individuo * populacao, int * tam_populacao, int ambiente) {
	int n_cruzamentos;
	srand(time(NULL));
	/*O máximo de cruzamentos que pode acontecer por geração é igual ao
	 * tamanho da população dividido por dois (algo como relações monogâmicas)*/
	n_cruzamentos = rand() % (tam_populacao / 2);
	populacao = realloc(populacao, (*tam_populacao + n_cruzamentos));
	for (int i = *tam_populacao; i < *tam_populacao + n_cruzamentos; i++) {
		*(populacao + i) = torneio_de_dois(populacao, *tam_populacao, ambiente);
	}
	*tam_populacao += n_cruzamento;
	return populacao;
}

Individuo torneio_de_dois (Individuo * populacao, int tam_populacao, int ambiente) {
	srand(time(NULL));
	int pai, mae, i;
	Individuo filho;
	float inteligencia;
	
	//Escolhe aleatoriamente pai e mãe sem verificar se são o mesmo indivíduo
	pai = rand() % (tam_populacao + 1);
	mae = rand() % (tam_populacao + 1);
	//Define aleatoriamente o quão proeficiente em linguagem é o filho
	filho.linguagem = rand() % VALOR_MAX;
	//Define a porcentagem máxima que ele poderá aproveitar do que for
	//passado oralmente pelos pais
	inteligencia = ((((populacao + pai) -> linguagem) /100) + (((populacao + mae) -> linguagem) / 100) / 2)
			* (filho.linguagem);
	
	//faz a reprodução entre os pais
	for (i = 0; i < N_GENES; i++) {
		filho.*(codigo_genetico + i) = ((populacao + pai) -> *(codigo_genetico + i) +
				(populacao + mae) -> *(codigo_genetico + i)) / 2;
		//se o código genético não for aquele importante para o ambiente 
		//em que ele está, ele pode aprender oralmente
		if (i != ambiente) {
			filho.*(codigo_genetico + i) = filho.*(codigo_genetico + i) + 
					(filho.*(codigo_genetico + i) * inteligencia); 
		}
	}
	
	return filho;
}

