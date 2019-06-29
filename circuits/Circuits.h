#ifndef CIRCUITS_H_INCLUDED
#define CIRCUITS_H_INCLUDED
#include "../graph/Grafo.h"
#include "../Matrix/Matrix_operations.h"
#include "../Linked_list/lista_enc.h"

typedef struct circuits circ_t;
typedef struct component comp_t;
typedef struct node node_t;
circ_t *create_circuit(int id, int siz);
grafo_t *get_graph(circ_t *test);
void create_source(circ_t *cir,tipo_t *v,int a,int b);
void create_resitor(circ_t *cir,tipo_t *res, int a,int b);
void solve_circuit(circ_t *cir);
tipo_t *circuit_get_res(void *key);

#endif // CIRCUITS_H_INCLUDED
