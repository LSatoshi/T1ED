#include <stdlib.h>
#include <stdio.h>
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
		guardar_distancia(A, cidade_x, cidade_y, dist);
	}
	
	//Retornar o TAD cidades
	return(A);
}

/*
rota melhor_rota_bf(cidades *A) {
	//Alocar uma int e uma rota, que guardem o melhor caso
	int dist_melhor = 0;
	rota *R_melhor = alocar_rota(n_cidades(A));
		
	//Repetir sla
	while (bla) {
		//Alocar uma int e uma rota temporarios
		int dist_tmp;
		rota *R_tmp = alocar_rota(n_cidades(A));
		
		//Gerar uma rota
		in = gerar de alguma forma sla;
		
		//Guardar a rota, e percorrer
		guardar_rota(R_tmp, in);
		dist_tmp = percorrer_rota(A, R_tmp);
		
		//Se o percurso for melhor que o melhor, atualizar
		if (dist_tmp < dist_melhor) {			
			free(R_melhor);

			dist_melhor = dist_tmp;
			R_melhor = R_tmp;
		}
	}
	
	//Retornar o melhor percurso	
	return(R_melhor);
	
}
*/

//encontra todas rotas por uma permutação recursiva
int permuta(rota *R, int ini, int fim, cidades *A, rota *R_melhor) { //R_melhor entra como argumento para output
	int i, dist, aux;
	//Se o inicio for igual ao fim, encontrou uma permutação, então calcula a distancia e retorna
	if(ini == fim){
		dist = percorrer_rota(A, R);
		return(dist);
	}
	else{ 
		for (i = ini; i <= fim; i++){//troca um elemento, o fixa e chama a função recursivamente
			troca(R, ini, i); 
			dist = permuta(R, ini+1, fim, A, R_melhor); 
			//Se o percurso for melhor que o melhor, atualiza
			if(i == ini) aux = dist;
			if(dist <= aux){
				R_melhor = R;
			}
			troca(R, ini, i); //volta como estava
		}
	}
}
