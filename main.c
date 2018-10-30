#include <stdio.h>
#include <stdlib.h>

#include "funcoes.c"

int main() {
	char arquivo[50]; //Nome do arquivo
	int modo, cidade_inicial;
	
	printf("Digite o nome do arquivo a ser lido\n>");
	gets(arquivo);
	
	printf("Digite a cidade inicial\n>");
	scanf("%d", &cidade_inicial);
	
	printf("Escolha o algoritmo:\n");
	printf("1 - Brute force");
	printf("2 - Algoritmo por seleção");
	scanf("%d", &modo);
	
	resolucao(arquivo, cidade_inicial, modo);
}
