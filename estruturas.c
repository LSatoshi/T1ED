#include <stdlib.h>
#include <stdio.h>

#include "estruturas.h"


struct _cidades {
	int **matriz;
	int n_cidades;
};

struct _rota {
	int *percurso;
	int n_cidades;
};

/*
Alocação de database de n cidades
Retorna um ponteiro para tipo cidade
*/
cidades *alocar_cidades(int n) {
	cidades *A;
	int i;
	
	//Alocar struct
	A = (cidades *)malloc(sizeof(cidades));
	if (A == NULL) return(NULL);
	
	//Guardar numero de cidades
	A->n_cidades = n;
	
	//Alocar matriz n*n com informações de distância
	A->matriz = (int **)malloc(sizeof(int)*n);
	if (A->matriz == NULL) return(NULL);
	for(i = 0; i < n; i++) {
		A->matriz[i] = (int *)malloc(sizeof(int)*n);
		if (A->matriz[i] == NULL) return(NULL);
	}	

	return(A);
}

/*
Guardar distancia de duas cidades dadas
*/
void guardar_distancia(cidades *A, int x, int y, int dist) {
	//Armazenar distância dist da cidade x pra y (E vice-versa)
	A->matriz[x-1][y-1] = dist;
	A->matriz[y-1][x-1] = dist;
	
	return;
}

/*
Devolver número de cidades
*/
int n_cidades(cidades *A) {
	return (A->n_cidades);
}


/*
Alocação de uma rota entre n cidades
Retorna um ponteiro para rota
*/
rota *alocar_rota(int n) {
	rota *R;
	
	//Guardar numero de cidades
	R->n_cidades = n;
	
	//Alocar a struct
	R = (rota *)malloc(sizeof(rota));
	if (R == NULL) return(NULL);
	
	//Alocar o array percurso, com tamanho +1 para guardar a cidade inicial no fim
	R->percurso = (int *)malloc(sizeof(int)*n+1);
	if (R->percurso == NULL) return(NULL);
	
	return(R);
}

/*
Armazenamento de rota
*/
void guardar_rota(rota *R, int in[]) {
	//Copiar a rota para a struct
	for (int cont = 0; cont < R->n_cidades; cont++)
		R->percurso[cont] = in[cont];
	
	R->percurso[R->n_cidades] = in[0]; //Colocar a cidade inicial no fim
	
	return;
}

/*
Retorna a distância entre dadas duas cidades
*/
int distancia_cidades(cidades *A, int cidade_x, int cidade_y) {
	return (A->matriz[cidade_x-1][cidade_y-1]);
}

/*
Retorna o tamanho da rota dada
*/
int percorrer_rota (cidades *A, rota *R) {
	int distancia = 0;
	for (int cont = 1; cont <= A->n_cidades; cont++) {
		//Ir somando as distancias
		distancia += distancia_cidades(A, R->percurso[cont], R->percurso[cont+1]);
	}
	
	return(distancia);
}

/*
Printar a rota dada, e seu tamanho
*/
void printar_percurso(rota *R) {
	for (int cont = 0; cont < R->n_cidades; cont++) {
		printf("%d", R->percurso[cont]);
		if (cont != R->n_cidades - 1)
			printf("-");
	}
	printf(" | %d \n", R->dist);
}

/*
Troca duas cidades de lugar na rota dada, para permutação
*/
void troca(rota *R, int a, int b){
	if(b < R->n_cidades){
		int tmp;
		tmp = R->percurso[a];
		R->percurso[a] = R->percurso[b];
		R->percurso[b] = tmp;
	}
}
	
