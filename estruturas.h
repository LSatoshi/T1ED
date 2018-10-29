#ifndef estruturas_h
#define estruturas_h

typedef struct _cidades cidades;
typedef struct _rota rota;

/*
Alocação de database de n cidades
Retorna um ponteiro para tipo cidade
*/
cidades *alocar_cidades(int n);

/*
Guardar distancia de duas cidades dadas
*/
void guardar_distancia(cidades *A, int cidade_x, int cidade_y, int dist);

/*
Devolver número de cidades
*/
int n_cidades(cidades *A);

/*
Alocação de uma rota entre n cidades
Retorna um ponteiro para rota
*/
rota *alocar_rota(int n);

/*
Retorna a distância entre dadas duas cidades
*/
int distancia_cidades(cidades *A, int cidade_x, int cidade_y);

/*
Retorna o tamanho da rota dada
*/
int percorrer_rota (cidades *A, rota *R);

/*
Printar a rota dada, e seu tamanho
*/
void printar_percurso(rota *R);

/*
Troca duas cidades de lugar na rota dada, para permutação
*/
void troca(rota *R, int a, int b);

#endif
