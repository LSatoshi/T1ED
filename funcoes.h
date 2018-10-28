#ifndef funcoes_h
#define funcoes_h
#include "estruturas.h"

/*
Lê informações de um arquivo de nome dado
*/
cidades *ler_arquivo(char *arquivo);

//rota melhor_rota_bf(cidades *A);

//encontra todas rotas por uma permutação recursiva
int permuta(rota *R, int ini, int fim, cidades *A, rota *R_melhor);

#endif
