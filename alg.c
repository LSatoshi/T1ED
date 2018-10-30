#include "estruturas.h"

/*
estruturas.c
*/



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
	
		
	
