#include "estruturas.h"

/*
estruturas.c
*/

typedef struct _no{
	int num;
	struct _no *prox;
}no;

typedef struct _lista{
	struct _no *raiz;
}lista;

lista *criar_lista(){
	lista *L;
	L = (lista*) malloc(sizeof(lista));
	L->raiz = NULL;
	return(L);
}

void insere_lista(int item, lista *L){
	no *novo;
	novo = (no*) malloc(sizeof(no));
	if(novo == NULL){
		printf("erro\n");
		return();
	}
	novo->num = item;
	novo->prox = L->raiz;
	L->raiz = novo;
	return();
}

int mais_proximo(cidades *A, int origem, lista *L){
	int menor_dist = 0, aux, menor;
	no *destino;
	destino = L->raiz
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

void remover(int item, lista *L){
	no *aux, *rem;
	aux = *L->raiz;
	if(aux != NULL){
		rem = 
	
}	

/////////////////////////////////////////////////////////////////////////////////////////////////
/*
funcoes.c 
*/

rota *algoritmo(cidades *A, int ini){
	int *rota_m, n;
	lista *opcoes = criar_lista();
	rota *melhor;
	n = n_cidades(A);
	rota_m = (int*) malloc(sizeof(int)*n);
	for(int i = 0, i < n, i++){
		if(i != ini){
			insere_lista(i, opcoes);
		}
	}
	rota_m[0] = ini;
	for(i = 0, i < n-1, i++){
		rota_m[i+1] = mais_proximo(A, i, opcoes);
		remover(rota_m[i+1], L);
	}
	melhor = alocar_rota(rota_m);
	return(melhor);
}
	
		
	
