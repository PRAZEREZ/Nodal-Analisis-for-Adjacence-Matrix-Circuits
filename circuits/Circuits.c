#include "Circuits.h"

#include <stdlib.h>
struct circuits{
grafo_t *graph;
int id;
lista_enc_t *nodes;
int tamanho;
};

struct node{
int id;
int local;
tipo_t *volt;

};

struct resistor{
tipo_t *resistencia;
// tipo_t *corrente;
 int id;

};

struct V_source{
tipo_t *tensao;
char id;

};

circ_t *create_circuit(int id, int siz){
circ_t *a=(circ_t *)malloc(sizeof(circ_t));
a->tamanho=siz;
a->graph=cria_grafo(siz);
a->nodes=cria_lista_enc();
a->id=id;
return a;
}

grafo_t *get_graph(circ_t *test){
return test->graph;
}

void create_resitance(circ_t *cir ,tipo_t *res, int a,int b){
res_t *resi=(res_t *)malloc(sizeof(res_t));
resi->resistencia=res;
resi->id=a+b;
ar_set_chave(cir->graph,resi,a,b);
ar_set_chave(cir->graph,resi,b,a);
cria_adjacencia(cir->graph,a,b);
cria_adjacencia(cir->graph,b,a);
}

void create_source(circ_t *cir,tipo_t *v,int a,int b){
tens_t *source=malloc(sizeof(tens_t));
source->tensao=v;
source->id=-a-b;
ar_set_chave(cir->graph,source,a,b);
ar_set_chave(cir->graph,source,b,a);
cria_adjacencia(cir->graph,a,b);
cria_adjacencia(cir->graph,b,a);
}
node_t *cria_noh(int id,int local){
node_t *noh=malloc(sizeof(node_t));
noh->id=id;
noh->local=local;
noh->volt=NULL;
return noh;
}

void nohs_essenciais(circ_t *c){
int i,j,count;
for(i=0;i<c->tamanho;i++){
    for(j=0;j<c->tamanho;j++)
        if(adjacente(c->graph,i,j))
        count++;


    if(count>2)
        add_cauda(c->nodes,(void *)cria_noh(i,i));
    count=0;
    }


}

