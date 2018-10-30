#ifndef estruturas_h
#define estruturas_h

typedef struct _cidades cidades;
typedef struct _rota rota;
typedef struct _no no;
typedef struct _lista lista;

cidades *alocar_cidades(int n);
void guardar_distancia(cidades *A, int x, int y, int dist);
int n_cidades(cidades *A);
rota *alocar_rota(int n);
rota *importar_rota(cidades *A, int *in);
rota *gerar_rota_inicial(cidades *A, int cidade_inicial);
void copiar_rota(rota *in, rota *out);
int distancia_cidades(cidades *A, int cidade_x, int cidade_y);
int percorrer_rota (cidades *A, rota *R);
void printar_rota(rota *R);
void troca(rota *R, int a, int b);
lista *lista_criar();
void lista_inserir(lista *L, int item);
void lista_remover(lista *L, int item);
int lista_mais_proximo(cidades *A, int origem, lista *L);
#endif
