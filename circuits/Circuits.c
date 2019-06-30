#include "Circuits.h"
#include <stdio.h>
#include <stdlib.h>
#define CMP_INT(x,y)

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
    int adjacentes;
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
    comp_t *sourcep=malloc(sizeof(comp_t));
    comp_t *sourcem=malloc(sizeof(comp_t));
    sourcep->tamanho=v;
    sourcep->id=1;
    ar_set_chave(cir->graph,sourcep,a,b);
    sourcem->tamanho=v;
    sourcem->id=-1;
    ar_set_chave(cir->graph,sourcem,b,a);
    cria_adjacencia(cir->graph,a,b);
    cria_adjacencia(cir->graph,b,a);
}
node_t *cria_noh(int id,int count)
{
    node_t *noh=malloc(sizeof(node_t));
    noh->id=id;
    noh->adjacentes=count;
    noh->volt=NULL;
    return noh;
}

void nohs_essenciais(circ_t *c)
{
    node_t *meuno;
    int i,j,count;
    for(i=0; i<c->tamanho; i++)
    {
        count=0;
        for(j=0; j<c->tamanho; j++)
            if(adjacente(c->graph,i,j))
                count++;


        if(count>2)
        {
            meuno=cria_noh(i,count);
            add_cauda(c->nodes,cria_no((void *)meuno));
        }
    }


}
tipo_t* circuit_get_res(void *key)
{
    comp_t *buffer=key;
    if(buffer->id==2)
        return buffer->tamanho;
    else
        return create_tipo(0);

}
tipo_t *circuit_get_volt(void *key)
{
    if(!key)
        return NULL;
    comp_t *buffer=key;
    tipo_t *x=create_tipo(-1);

    if(buffer->id==1)
        return buffer->tamanho;
    else if(buffer->id==-1){
        mult(x, buffer->tamanho);
        return x;}
    else
        return create_tipo(0);

}
tipo_t* circuit_return_null(void *key)
{
    return NULL;
}

void solve_circuit(circ_t *cir, int referenc)
{
    nohs_essenciais(cir);
    tipo_t *myres,**buffer,*buff, *myvolt;
    tipo_t ***SMatrix,**B;
    no_t *no_lista;
    int i,j,k,l; //iterators
    int num_nos,next,temp;
    int *nodess;
    int *exeptions;
    node_t *noh;
    num_nos=lista_tamanho(cir->nodes)-1;
    nodess=malloc(sizeof(int)*num_nos);
    exeptions=malloc(sizeof(int)*num_nos);
    no_lista=obter_cabeca(cir->nodes);
    k=0;
    for(i=num_nos-1; no_lista; i--)
    {
        noh=obter_dado(no_lista);
        nodess[i]=noh->id;
        exeptions[i]=-1;
        if(noh->id==referenc){
            noh->volt=create_tipo(0);
            nodess[i]=-1;
            i++;
        }


        no_lista=obtem_proximo(no_lista);
    }



    B=create_vetor(num_nos);
    SMatrix=create_matrix(num_nos);



    for(i=0; i<num_nos; i++)
        for(j=0; j<cir->tamanho; j++)
            if(adjacente(cir->graph,nodess[i],j) &&j!=referenc)
            {

                next=next_branchout(cir->graph,nodess[i],j,NULL,circuit_return_null);
                if(next<0)
                {
                    exeptions[i]=j;
                }
            }

        for(i=0; i<num_nos; i++)
            for(j=0; j<cir->tamanho; j++)
            if(adjacente(cir->graph,nodess[i],j) && exeptions[i]!=j )
            {
                myres=create_tipo(0);
                next=next_branchout(cir->graph,nodess[i],j,myres,circuit_get_res);
                for(k=0; nodess[k]!=next; k++) ;

                if(!is_zero(myres))
                {
                    invert(myres);
                    addup(SMatrix[i][k],myres);;
                    buff=create_tipo(-1);
                    mult(buff,myres);

                    addup(SMatrix[i][i],buff);
                }
                else if(0 )  //super no
                {
                    exeptions[k]=0;
                    buffer=SMatrix[i];
                    SMatrix[i]=create_vetor(num_nos-1);
                    free_array(buffer,num_nos-1);
                    addup(SMatrix[i][k],create_tipo(1));
                    addup(SMatrix[i][i],create_tipo(-1));
                    myvolt=create_tipo(0);
                    next_branchout(cir->graph,nodess[i],j,myvolt,circuit_get_volt);
                    addup(B[i],myvolt);
                }


            }

    for(i=0; i<num_nos; i++)
        for(j=0; j<cir->tamanho; j++)
            if(adjacente(cir->graph,nodess[i],j) &&0)
            {
                if(i>referenc)
                    temp=i;
                myvolt=create_tipo(0);
                myres=create_tipo(0);
                next_branchout(cir->graph,nodess[i],j,myres,circuit_get_res);
                next_branchout(cir->graph,nodess[i],j,myvolt,circuit_get_volt);
                addup(B[temp],myvolt);
                printf("%f\n",retorna_tipo(myvolt));
                if(!is_zero(myres)){
                negative(B[temp]);
                divide(B[temp],myres);}
            }
    print_matrix(SMatrix,num_nos);
    print_array(B,num_nos);


    free(exeptions);
    free(nodess);
}

