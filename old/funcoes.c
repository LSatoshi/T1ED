#define "funcoes.h"
#define <stdio.h>

struct best_r_ {
    int origem;
    int rota*;
    int dist;
};

int** read(char* name){
    
    FILE* arqin;
    int **matriz, m, n, k, i, j;
    
    arqin = fopen(name,"r");
    if(arqin == NULL){
        printf("erro\n");
        return (NULL);
    }
    
    fscanf(arqin, "%d", &m);
    
    matriz = (int**)malloc(sizeof(int)*m);
    if(matriz == NULL){
        printf("erro\n");
        return (NULL);
    }
    for(i = 0; i < m; i++){
        matriz[i] = (int*)malloc(sizeof(int)*m);
        if(matriz[i] == NULL){
            printf("erro\n");
            return (NULL);
        }
    }
    k = (m * (m - 1))/2;
    n = 0
    
    while(n < k) {
        fscanf(arqin,"%d", &i);
        fscanf(arqin,"%d", &j);
        
        fscanf(artqin,"%d", &matriz[i-1][j-1]);
        matriz[j-1][i-1] = matriz[i-1][j-1]; 
    }
    return (matriz);
} 

int rota(int* v, int** matriz) {
    int m, i, dist;
    dist = 0;
    
    m = sizeof(v)/sizeof(int);
    
    for(i = 0;i < (m - 2); i++) {
        dist += matriz[v[i]][v[i+1]];
    }
    
    return (dist);
}

best_r* permutacao(int* v, int r, int l){
    
}
        
    
   
  
    
    
    


