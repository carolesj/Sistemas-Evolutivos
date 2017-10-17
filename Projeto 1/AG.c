#include "AG.h"

g_populacao populacao;

void inicia_populacao () {
	int j;
	srand(time(NULL));
	populacao.individuos = malloc(sizeof(individuo) * POP_INICIAL);
	
	/*Inicializa o código genético dos indivíduos de forma aleatória, assim
	 * como sua nota de linguagem*/
	for (int i = 0; i < POP_INICIAL; i++) {
		populacao.*(individuos + i) -> codigo_genetico = malloc(sizeof(int) * N_GENES);
		for (j = 0; j < N_GENES; j++) {
			*(populacao.*(individuos + i) -> codigo_genetico + j) = rand() % VALOR_MAX;
		}
		populacao.*(individuos + i) -> linguagem = rand() % VALOR_MAX;
	}
	populacao.tamanho_populacao = POP_INICIAL;
	populacao.capacidade_populacao = POP_INICIAL;
	populacao.n_geracao = 0;
	return;
}

void exporta_geracao (FILE * pa) {
	int i, j;
	fprintf("%d:\n", populacao.n_geracao);
	for (i = 0; i < populacao.tamanho_populacao; i++) {
		for (j = 0; j < N_GENES; j++) {
			fprintf("%d ", (populacao.*(individuos + i) -> *(codigo_genetico + j)));
		}
		fprintf("%d\n", (populacao.*(individuos + i) -> linguagem));
	}
	return;
}

void libera_individuos () {
	free(populacao.individuos);
}

void mata_individuos (int ambiente) {
	int i, j, mortos = 0;
	//mata indívidos baseando-se em suas habilidades inatas em relação
	//ao lugar onde vivem
	switch (ambiente) {
		case FRIO:
			//percorre a população e verifica se cada indivíduo possui
			//resistência ao frio maior que a mínima necessária
			for (i = 0; i < populacao.tamanho_populacao; i++) {
				if ((populacao.*(individuos + i)) -> 
						*(codigo_genetico + RESISTENCIA_FRIO) < MIN_RESISTENCIA_FRIO) {
					//se a resistência for menor que a necessária, diminui
					//o tamanho da populacao e sobrescreve o morto com os 
					//seguintes
					for (j = i; j < populacao.tamanho_populacao; j++) {
						populacao.*(individuos + j) = populacao.*(individuos + j + 1);
					}
					if (populacao.tamanho_populacao > 0) populacao.tamanho_populacao--;
				}
			}
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

void reproducao (int ambiente) {
	srand(time(NULL));
	int pai, mae, i;
	float inteligencia;
	
	//Escolhe aleatoriamente pai e mãe sem verificar se são o mesmo indivíduo
	pai = rand() % (tam_populacao + 1);
	mae = rand() % (tam_populacao + 1);
	//Define aleatoriamente o quão proeficiente em linguagem é o filho
	populacao.*(individuos + (populacao.tamanho_populacao)) = rand() % VALOR_MAX;
	//Define a porcentagem máxima que ele poderá aproveitar do que for
	//passado oralmente pelos pais
	inteligencia = ((((populacao.*(individuos + pai)) -> linguagem) /100.0) + 
			(((populacao.*(individuos + pai)) -> linguagem) / 100.0) / 2.0)
			* populacao.(individuos + (populacao.tamanho_populacao)) -> linguagem;
	
	//faz a reprodução entre os pais
	for (i = 0; i < N_GENES; i++) {
		populacao.(individuos + (populacao.tamanho_populacao))->*(codigo_genetico + i) =
				((populacao.(individuos + pai))->*(codigo_genetico + i) +
				(populacao.(individuos + mae))-> *(codigo_genetico + i)) / 2;
		//se o código genético não for aquele importante para o ambiente 
		//em que ele está, ele pode aprender oralmente
		if (i != ambiente) {
			populacao.*(individuos + (populacao.tamanho_populacao)).*(codigo_genetico + i) =
					populacao.*(individuos + (populacao.tamanho_populacao)).*(codigo_genetico + i) + 
					(populacao.*(individuos + (populacao.tamanho_populacao)).*(codigo_genetico + i)) * inteligencia); 
		}
	}
	
	return;
}

void reproduz_individuos (int ambiente) {
	int n_cruzamentos;
	srand(time(NULL));
	/*O máximo de cruzamentos que pode acontecer por geração é igual ao
	 * tamanho da população dividido por dois (algo como relações monogâmicas)*/
	n_cruzamentos = rand() % (populacao.tamanho_populacao / 2) + 1;
	/*Verifica se o vetor possui tamanho suficiente para receber as crias.
	 * Se não possuir, realoca o vetor e atualiza a capacidade dele*/
	if(populacao.tamanho_populacao + n_cruzamentos > populacao.capacidade_populacao) {
		populacao.individuos = realloc(populacao.individuos, 
				(populacao.tamanho_populacao + n_cruzamentos));
		populacao.capacidade_populacao = populacao.tamanho_populacao + n_cruzamentos;
	}
	for (int i = populacao.tamanho_populacao; i < populacao.tamanho_populacao + n_cruzamentos; i++) {
		populacao.*(individuos + i) = reproducao(ambiente);
		populacao.tamanho_populacao++;
	}

	return;
}

