#ifndef funcoes_h
#define funcoes_h

#include "estruturas.h"

cidades *ler_arquivo(char arquivo[]);
void bf_permutacao(cidades *A, rota *R, rota *R_best, int ini, int tam, int *dist_best);
void melhor_rota_1 (cidades *A, int cidade_inicial);
void melhor_rota_2(cidades *A, int cidade_inicial);
void resolucao(char *nome, int inicial, int modo);
#endif
