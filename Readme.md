Autores
=======
- Caroline Jesuíno Nunes da Silva - 9293925
- Lucas Antognoni de Castro - 8936951
- Roberto Pommella Alegro - 8936756

Genoma
======
Todos os valores no cromossomo são reais [0,1]

- Velocidade
	+ Quanto consegue correr atras de alimento e fugir de predador
- Metabolismo
	+ Quanto precisa comer / quanto tempo sobrevive sem comida
- Resistência a frio
	+ Quanto retém calor
- Poder de luta
	+ De quem ele pode se alimentar
- Tempo de repouso
	+ Tempo de recarga de energia
- Sede
	+ Quanto o indivíduo precisa beber água
- Mutabilidade
	+ Probabilidade de mutação

Ambiente
========
Todos os valores do ambiente são reais [0,1]

- Comida
	+ Quantidade de plantas burras
- Temperatura
	+ A temperatura do ambiente
- Acquamentação
	+ quantidade de recursos hídricos no ambiente
- Predação
	+ Quantidade de predadores

Reprodução
==========

Torneio
-------
Seleciona 2 a 2 e escolhe o com melhor score.

Score baseado no fitness e no Poder de luta.
`Score = [Fitness]Fitness + [PoderLuta]PoderLuta`

O melhor score sobrevive a rodada e passa para para a etapa de reprodução.

Reprodução
----------
Seleciona 2 a 2 e gera dois filhos idênticos, com chances de mutação diferentes.

Calcula a média entre os valores dos alelos e aplica mutações em cada alelo.

Para o segundo filho soma uma porcentagem de 15%

Mutação
-------
Em cada alelo soma ou subtrai (50% de chance cada) uma porcentagem variável do valor do alelo. Entre [5,20]%

Fitness
-------

```
Fitness =
	Comida * ( [t]t - [r]r ) +
	Predação * ( [v]v - [t]t ) +
	[v]v * ( [m]m + [s]s ) +
	Acquamentação * ( - [s]s - [r]r)
	Temperatura * ( [s]s - [m]m + [t]t + [r]r )
```
