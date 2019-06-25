#include "Circuits.h"

#include <stdlib.h>
struct circuits{
grafo_t *graph;
int id;
lista_enc_t *essencial_nodes;

};

struct node{
int id;
int local;
tipo_t *volt;

};

struct resistor{
tipo_t *resistencia;
// tipo_t *corrente;
unsigned int id;

};

struct V_source{
tipo_t *tensao;
char sinal;

};

circ_t *create_circuit(int id, int siz){
circ_t *a=(circ_t *)malloc(sizeof(circ_t));
a->graph=cria_grafo(siz);
a->essencial_nodes=cria_lista_enc();
a->id=id;
return a;
}

grafo_t *get_graph(circ_t *test){
return test->graph;
}

void create_resitance(circ_t *g ,tipo_t *res, int a,int b){
res_t *resistencia=malloc(sizeof(res_t));
resistencia->resistencia=res;
resistencia->id=a+b;
ar_set_chave(g,res,a,b);
ar_set_chave(g,res,b,a);
cria_adjacencia(g,a,b);
cria_adjacencia(g,b,a);
}

