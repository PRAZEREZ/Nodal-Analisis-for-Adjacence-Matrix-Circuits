#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#include "../Matrix/Matrix_operations.h"


#define TRUE 1
#define FALSE 0
#include <stdlib.h>
#include <stdio.h>
typedef struct vertices vertice_t;
typedef struct arestas aresta_t;
typedef struct grafos grafo_t;

grafo_t *cria_grafo(int vertices);
void libera_grafo (grafo_t *g);
int cria_adjacencia(grafo_t *g, int u, int v);
int rem_adjacencia(grafo_t *g, int u, int v);
int adjacente(grafo_t *g, int u, int v);
int  next_branchout(grafo_t *g,int inicial,int caminho,tipo_t *peso_atual,tipo_t* (*aresta_sum)(void *));
void *ar_get_chave(grafo_t *g,int a,int b);
void ar_set_chave(grafo_t *g,void *key, int a, int b);
void exportar_grafo_a(grafo_t *g,FILE* fp,void (*printkey)(void *,FILE *));
void libera_grafo_especial(grafo_t *g,void (*libera_chave)(void *));
int adjacencias(grafo_t *g,int u);
#endif // GRAFO_H_INCLUDED
