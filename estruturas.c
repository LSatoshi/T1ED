#include <stdlib.h>
#include <stdio.h>

#include "estruturas.h"

//=================================================
//Cidade
//=================================================

//Estrutura que armazena distâncias das cidades, e seu número
struct _cidades {
	int **matriz;
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
	A->matriz = (int **)malloc(sizeof(int *)*n);
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

//=================================================
//Rota
//=================================================

//Guarda informações sobre uma rota
struct _rota {
	int *percurso;
	int n_cidades;
};


/*
Alocação de uma rota entre n cidades
Retorna um ponteiro para rota
*/
rota *alocar_rota(int n) {
	rota *R;
	
	//Alocar a struct
	R = (rota *)malloc(sizeof(rota));
	if (R == NULL) return(NULL);
	
	//Guardar numero de cidades
	R->n_cidades = n;
	
	//Alocar o array percurso, com tamanho +1 para guardar a cidade inicial no fim
	R->percurso = (int *)malloc(sizeof(int)*n+1);
	if (R->percurso == NULL) return(NULL);
	
	return(R);
}

/*
Aloca e importa uma rota a partir de um array
*/
rota *importar_rota(cidades *A, int *in) {
	rota *R = alocar_rota(A->n_cidades);
	
	for (int i = 0; i < A->n_cidades; i++) {
		R->percurso[i] = in[i];
	}
	
	return(R);
}

/*
Aloca e gera uma rota inicial, com dada cidade inicial
*/
rota *gerar_rota_inicial(cidades *A, int cidade_inicial) {
	rota *R = alocar_rota(A->n_cidades); //Alocar rota

	R->percurso[0] = cidade_inicial; //Colocar cidade inicial na primeira posição
	
	int j = 1; //Cidade a ser atribuida, a começar pela 1
	for (int i = 1; i < A->n_cidades; i++) { //Percorrer o vetor da segunda posição até a ultima
		if (j == cidade_inicial) j++; //Caso a cidade a ser atribuida seja a inicial, pular pra próxima
		R->percurso[i] = j; //Atribuir a cidade
		j++; //E passar para a próxima
	}
	return(R);
}

/*
Copia os dados de uma rota a outra
E retorna seu ponteiro
*/
void copiar_rota(rota *in, rota *out) {
	for (int i = 0; i < in->n_cidades; i++) {
		out->percurso[i] = in->percurso[i];
	}
	return;
}

/*
Retorna a distância entre dadas duas cidades
*/
int distancia_cidades(cidades *A, int cidade_x, int cidade_y) {
	//printf("Acessando %d %d\n", cidade_x-1, cidade_y-1);
	return (A->matriz[cidade_x-1][cidade_y-1]);
}

/*
Retorna o tamanho da rota dada
*/
int percorrer_rota (cidades *A, rota *R) {
	int distancia = 0, cont;
	for (cont = 0; cont < R->n_cidades-1; cont++) {
		//Ir somando as distancias
		//printf("Percorrendo %d->%d\n", R->percurso[cont], R->percurso[cont+1]);
		distancia += distancia_cidades(A, R->percurso[cont], R->percurso[cont+1]);
	}
	distancia += distancia_cidades(A, R->percurso[R->n_cidades-1], R->percurso[0]);
	
	return(distancia);
}

/*
Printar a rota dada, e seu tamanho
*/
void printar_rota(cidades *A, rota *R) {
	for (int cont = 0; cont < R->n_cidades; cont++) {
		printf("%d - ", R->percurso[cont]);
	}
	printf("%d", R->percurso[0]);
	printf(" | %d \n", percorrer_rota(A, R));
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

//=================================================
//Lista encadeada (solução 2)
//=================================================
	
/*
Estruturas e funções relacionadas a solução 2,
Que utiliza listas encadeadas para facilitar remoção
*/

/*
Utilizamos uma lista encadeada para a segunda solução
*/
struct _no{
	int num;
	struct _no *prox;
};
struct _lista{
	struct _no *raiz;
};

/*Cria uma lista encadeada, e retorna seu ponteiro*/
lista *lista_criar(){
	lista *L;
	L = (lista*) malloc(sizeof(lista));
	L->raiz = NULL;
	return(L);
}

/*Insere um nó, com valor dado, na lista*/
void lista_inserir(lista *L, int item){
	no *novo = (no*) malloc(sizeof(no)); //Alocar nó
	if(novo == NULL) return;
	
	novo->num = item;
	novo->prox = L->raiz;
	L->raiz = novo;
	return;
}

/*Remove um elemento da lista encadeada*/
void lista_remover(lista *L, int item){
	no *aux, *rem;
	aux = L->raiz;
	if(aux != NULL){
		if(aux->num == item){
			L->raiz = aux->prox;
			free(aux);
			return;
		}
		while(aux->prox->num != item){
			if(aux->prox != NULL){
				aux = aux->prox;
			}
			else break;
		}
		if(aux->prox != NULL){
			rem = aux->prox;
			aux->prox = rem->prox;
			free(rem);
		}
	}
	return;	
}


/*Retorna a cidade mais próxima, de uma dada lista*/
int lista_mais_proximo(cidades *A, int origem, lista *L){
	int menor_dist = 0, aux, menor;
	no *destino;
	destino = (no*) malloc(sizeof(no));
	destino = L->raiz;
	while(destino != NULL){
		aux = distancia_cidades(A, origem, destino->num);
		if(menor_dist == 0)menor_dist = aux;
		if(aux <= menor_dist){
			menor_dist = aux;
			menor = destino->num;
		}
		destino = destino->prox;
	}
	return(menor);
}
