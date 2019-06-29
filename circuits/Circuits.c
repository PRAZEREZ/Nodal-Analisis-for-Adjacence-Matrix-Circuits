#include "Circuits.h"

#include <stdlib.h>
struct circuits
{
    grafo_t *graph;
    int id;
    lista_enc_t *nodes;
    int tamanho;
};

struct node
{
    int id;
    int local;
    tipo_t *volt;

};

struct component
{

// tipo_t *currente;
    int id; //0- nothing, 1\-1- V source, 2 resistor
    tipo_t *tamanho;
};

circ_t *create_circuit(int id, int siz)
{
    circ_t *a=(circ_t *)malloc(sizeof(circ_t));
    a->tamanho=siz;
    a->graph=cria_grafo(siz);
    a->nodes=cria_lista_enc();
    a->id=id;
    return a;
}


tipo_t *cir_get_resitencia(comp_t *r)
{
    return r->tamanho;
}


grafo_t *get_graph(circ_t *test)
{
    return test->graph;
}

void create_resitor(circ_t *cir,tipo_t *res, int a,int b)
{
    comp_t *resi=(comp_t *)malloc(sizeof(comp_t));
    resi->tamanho=res;
    resi->id=2;
    ar_set_chave(cir->graph,resi,a,b);
    ar_set_chave(cir->graph,resi,b,a);
    cria_adjacencia(cir->graph,a,b);
    cria_adjacencia(cir->graph,b,a);
}

void create_source(circ_t *cir,tipo_t *v,int a,int b)
{
    comp_t *source=malloc(sizeof(comp_t));
    source->tamanho=v;
    source->id=1;
    ar_set_chave(cir->graph,source,a,b);
    source->id=-1;
    ar_set_chave(cir->graph,source,b,a);
    cria_adjacencia(cir->graph,a,b);
    cria_adjacencia(cir->graph,b,a);
}
node_t *cria_noh(int id,int local)
{
    node_t *noh=malloc(sizeof(node_t));
    noh->id=id;
    noh->local=local;
    noh->volt=NULL;
    return noh;
}

void nohs_essenciais(circ_t *c)
{
    int i,j,count;
    for(i=0; i<c->tamanho; i++)
    {
        for(j=0; j<c->tamanho; j++)
            if(adjacente(c->graph,i,j))
                count++;


        if(count>2)
            add_cauda(c->nodes,(void *)cria_noh(i,i));
        count=0;
    }


}
tipo_t *circuit_get_res(void *key)
{
    comp_t *buffer=key;
    if(buffer->id==2)
        return buffer->tamanho;
    else
        return create_tipo(0);

}

void solve_circuit(circ_t *cir)
{













}

