#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

/*
 * grafo.h
 *
 *  Created on: Nov 18, 2016
 *      Author: Renan Augusto Starke
 */

#define TRUE 1
#define FALSE 0

typedef struct vertices vertice_t;
typedef struct arestas aresta_t;
typedef struct grafos grafo_t;

grafo_t *cria_grafo(int vertices);
void libera_grafo (grafo_t *g);
int cria_adjacencia(grafo_t *g, int u, int v);
int rem_adjacencia(grafo_t *g, int u, int v);
int adjacente(grafo_t *g, int u, int v);

void *ar_get_chave(grafo_t *g,int a,int b);
void ar_set_chave(grafo_t *g,void *key, int a, int b);
#endif // GRAFO_H_INCLUDED
