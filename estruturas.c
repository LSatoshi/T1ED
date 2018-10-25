#define <stdlib.h>
#define "estruturas.h"


struct _cidades {
	int **matriz;
	int n_cidades;
};

struct _rota {
	int *percurso;
	int dist_total;
};


cidades *criar_cidades(int n) {
	cidades *A;
	int i;
	
	
	A = (cidades *)malloc(sizeof(cidades));
	if (A == NULL) return(NULL);
	
	A->n_cidades = n;
	A->matriz = (int **)malloc(sizeof(int)*n);
	if (A->matriz == NULL) return(NULL);
	
	for(i = 0; i < m; i++) {
		A->matriz[i] = (int *)malloc(sizeof(int)*n);
		if (A->matriz[i] == NULL) return(NULL);
	}
	
	return(A);
}
