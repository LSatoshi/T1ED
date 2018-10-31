#include <stdio.h>
#include <stdlib.h>

#include "funcoes.h"

int main() {
	char *arquivo; //Nome do arquivo
	arquivo = (char*) malloc(sizeof(char)*50);
	int modo, cidade_inicial;
	printf("Problema do Caixeiro Viajante\n");
	printf("Digite o nome do arquivo a ser lido\n>");
	scanf("%s", arquivo);
	
	printf("Digite a cidade inicial\n>");
	scanf("%d", &cidade_inicial);
	
	printf("Escolha o algoritmo:\n");
	printf("1 - Brute force\n");
	printf("2 - Algoritmo por seleção\n");
	scanf("%d", &modo);
	
	resolucao(arquivo, cidade_inicial, modo);
	return 0;
}
