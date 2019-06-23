#ifndef CIRCUITS_H_INCLUDED
#define CIRCUITS_H_INCLUDED
#include "../graph/Grafo.h"
#include "../Matrix/Matrix_operations.h"
#include "../Linked_list/lista_enc.h"

typedef struct circuits circ_t;
typedef struct resistor res_t;
typedef struct node node_t;
typedef struct V_source tens_t;
circ_t *create_circuit(int id, int siz);
grafo_t *get_graph(circ_t *test);
void cria_resitor(tipo_t *resistencia,int a,int b);

#endif // CIRCUITS_H_INCLUDED
