#ifndef funcoes_h
#define funcoes_h

typedef struct best_r_ best_r;//menor distancia e a rota

int** read(char* namespace); //matriz com os valores de distancia
int   rota(int* v, int** dist); 
best_r*  permutacao(int* v, int r, int l);

