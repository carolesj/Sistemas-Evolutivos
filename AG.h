#ifndef __AG_H__
#define __AG_H__


/*Cria uma população inicial aleatória com n indivíduos, cujo valor
 * máximo no código genético será dado por max-1*/
Individuo * inicia_populacao (int n, int max);

/*Atribui a nota de fitness de cada um dos n indivíduos em população*/
void avalia_populacao (int n, Individuo * populacao);

/*Acha o indivíduo que possui melhor avaliação e o retorna*/
Individuo acha_melhor (int n, Individuo * populacao);

/*Verifica se o número de indivíduos existentes ultrapassa a capacidade
 * máxima. Se ultrapassar, reproduz os indivíduos e mata os mais velhos.
 * Se não ultrapassar, realoca o vetor e reproduz os indivíduos.*/
void reproduz (int n, int max_individuos, Individuo ** populacao);

#endif
