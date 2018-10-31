#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "estruturas.h"

#include "funcoes.h"

/*
Lê informações de um arquivo de nome dado
*/
cidades *ler_arquivo(char *arquivo) {
	FILE *arqin = fopen(arquivo, "r"); //Abrir arquivo
	
	
	int n; //Ler número de cidades
	fscanf(arqin, "%d", &n);
	//Alocar o TAD, e guardar em A
	cidades *A = alocar_cidades(n);
	
	int cidade_x, cidade_y, dist;
	int n_max = n*(n-1)/2; //Numero maximo de rotas sem repetir
	
	//Ler distância de duas cidades do arquivo e guardar no TAD através da função
	for (int cont = 0; cont < n_max; cont++) {
		fscanf(arqin, "%d %d %d", &cidade_x, &cidade_y, &dist);
		//printf("Guardando [%d][%d] = %d\n", cidade_x-1, cidade_y-1, dist);
		guardar_distancia(A, cidade_x, cidade_y, dist);
	}
	
	//Retornar o TAD cidades
	return(A);
}

/*
Função recursiva que permuta uma dada rota R, e guarda em R_best a melhor rota possivel
*/
void bf_permutacao(cidades *A, rota *R, rota *R_best, int ini, int tam, int *dist_best) {
	if (tam == ini) { //Quando terminarmos de gerar uma nova permutação
		int dist = percorrer_rota(A, R); //Obter tamanho da rota R
		if (dist < *dist_best) { //Caso seja melhor
			//Copiamos ela para a melhor rota, e guardamos sua distancia
			*dist_best = dist;
			copiar_rota(R, R_best);
			return;
		}
	}
	//Algoritmo de permutação
	for (int i = ini; i < tam; i++) {
		troca(R, ini, i);
		bf_permutacao(A, R, R_best, ini+1, tam, dist_best);
		troca(R, ini, i);
	}
	return;
}

/*
Chama a função recursiva, e printa a melhor rota.
*/
void melhor_rota_1 (cidades *A, int cidade_inicial) {
	rota *R_best = alocar_rota(n_cidades(A)); //Criar uma rota vazia
	rota *R = gerar_rota_inicial(A, cidade_inicial); //Criar uma rota inicial
	
	int *dist_best = (int *)malloc(sizeof(int));
	*dist_best = INT_MAX;
	
	bf_permutacao(A, R, R_best, 1, n_cidades(A), dist_best); //Permutar todas as rotas, e guardar em R_best a melhot
		
	printar_rota(A, R_best); //printar a melhor rota.
}

/*
Printa a melhor rota, utilizando o segundo método
*/
void melhor_rota_2(cidades *A, int cidade_inicial){
	int i, *percurso, n = n_cidades(A);
	lista *opcoes;
	opcoes = lista_criar();	
	percurso = (int*) malloc(sizeof(int)*n);
	//Inserir possiveis opções de rota
	for(i = 1; i <= n; i++){
		if(i != cidade_inicial){
			lista_inserir(opcoes, i);
		}
	}
	//Guardar cidade inicial
	percurso[0] = cidade_inicial;
	
	for(i = 0; i < n-1; i++){
		//Ir aicionando no array a cidade mais próxima a anterior
		percurso[i+1] = lista_mais_proximo(A, percurso[i], opcoes);
		//Remove a cidade já percorrida da lista
		lista_remover(opcoes, percurso[i+1]);
	}
	
	//Cria um tad rota, e importa do vetor
	rota *R_best = importar_rota(A, percurso);
	
	printar_rota(A, R_best);
}

/*Resolve o problema utilizando um dos dois algoritmos*/
void resolucao(char *nome, int inicial, int modo) {
	cidades *A = ler_arquivo(nome);
	if (modo == 1) melhor_rota_1(A, inicial);
	else           melhor_rota_2(A, inicial);
}
