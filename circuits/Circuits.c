#include "Circuits.h"
#include <stdio.h>
#include <stdlib.h>

#define ZERO create_tipo(0)
#define UNO create_tipo(1)
#define ZERAR(x) set_tipo_x(x,0)

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
    comp_t *rest=(comp_t *)malloc(sizeof(comp_t));
    resi->tamanho=res;
    resi->id=2;
    rest->tamanho=ZERO;
    addup(rest->tamanho,res);
    rest->id=2;
    cria_adjacencia(cir->graph,a,b);
    cria_adjacencia(cir->graph,b,a);
    ar_set_chave(cir->graph,rest,a,b);
    ar_set_chave(cir->graph,resi,b,a);

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
    tipo_t *dado=ZERO;

    if(buffer->id==2)
    {
        addup(dado,buffer->tamanho);
        return dado;
    }
    else
        return dado;

}
tipo_t *circuit_get_volt(void *key)
{
    if(!key)
        return NULL;
    comp_t *buffer=key;
    tipo_t *x=ZERO;

    if(buffer->id==1)
    {
        addup(x, buffer->tamanho);
        return x;
    }
    else if(buffer->id==-1)
    {
        negative(x);
        addup(x, buffer->tamanho);
        return x;
    }
    else
        return x;

}
tipo_t* circuit_return_null(void *key)
{
    return NULL;
}

void solve_circuit(circ_t *cir, int referenc)
{
    nohs_essenciais(cir);
    tipo_t *myres, *myvolt;
    tipo_t ***SMatrix,**B;
    no_t *no_lista;
    int i,j,k; //iterators
    int num_nos,next;
    int *nodess;
    int *exeptions;
    int *sper_nodes;
    node_t *noh;
    num_nos=lista_tamanho(cir->nodes)-1;
    nodess=malloc(sizeof(int)*num_nos);
    exeptions=malloc(sizeof(int)*num_nos);
    sper_nodes=malloc(sizeof(int)*num_nos);
    no_lista=obter_cabeca(cir->nodes);

    for(i=0; no_lista;)
    {
        noh=obter_dado(no_lista);
        if(noh->id!=referenc)
        {
            sper_nodes[i]=-1;
            nodess[i]=noh->id;
            exeptions[i]=-1;
            i++;
        }
        else
        {
            noh->volt=ZERO;
        }
        no_lista=obtem_proximo(no_lista);
    }

    B=create_vetor(num_nos);
    SMatrix=create_matrix(num_nos);
    for(i=0; i<num_nos-1; i++)
        for(j=0; j<cir->tamanho; j++)
            if(adjacente(cir->graph,nodess[i],j) &&j!=referenc)
            {

                next=next_branchout(cir->graph,nodess[i],j,NULL,circuit_return_null);
                if(next<0)
                {
                    exeptions[i]=j;
                }//busca pelas arestas que nao levam a nos essenciais
            }
    for(i=0; i<num_nos; i++)
    {
        for(j=0; j<cir->tamanho; j++)
        {
            if(adjacente(cir->graph,nodess[i],j) && exeptions[i]!=j )
            {
                myres=ZERO;
                next=next_branchout(cir->graph,nodess[i],j,myres,circuit_get_res);
                if(!is_zero(myres))
                {
                    invert(myres);
                    addup(SMatrix[i][i],myres);
                    if(next==referenc)
                        ;
                    else
                    {
                        for(k=0; nodess[k]!=next; k++) ;
                        negative(myres);
                        addup(SMatrix[i][k],myres);
                    }
                    myvolt=ZERO;
                    next_branchout(cir->graph,nodess[i],j,myvolt,circuit_get_volt);
                    if(!is_zero(myvolt))
                    {
                        addup(B[i],myvolt);
                        mult(B[i],myres);
                    }
                    free_tipo(myvolt);
                }
                else   //!super no
                {
                    if(next==referenc)
                        sper_nodes[i]=referenc;
                    else
                    {
                        sper_nodes[i]=j;
                    }
                }
                free_tipo(myres);

            }
        }

    }
    for(i=0; i<num_nos; i++){
        if(sper_nodes[i]==referenc)
        {
            for(j=0; j<num_nos; j++)
                ZERAR(SMatrix[i][j]);
            myvolt=create_tipo(1);
            addup(SMatrix[i][i],myvolt);
            for(j=0; next!=referenc; j++)
            {
                ZERAR(myvolt);
                next=next_branchout(cir->graph,nodess[i],j,myvolt,circuit_get_volt);
            }
            addup(B[i],myvolt);
            free_tipo(myvolt);
        }
        else if(sper_nodes[i]!=-1)
        {
            //I EH POSITIVO K EH NEGATIVO

            myvolt=ZERO;
            next=next_branchout(cir->graph,nodess[i],sper_nodes[i],myvolt,circuit_get_volt);
            addup(B[i],myvolt);
            for(k=0; nodess[k]!=next; k++) ;
            for(j=0; j<num_nos; j++)
            {
                addup(SMatrix[k][j],SMatrix[i][j]);
                ZERAR(SMatrix[i][j]);
            }

            myres=UNO;
            addup(SMatrix[i][i],myres);
            negative(myres);
            addup(SMatrix[i][k],myres);
            free_tipo(myres);
            free_tipo(myvolt);
            sper_nodes[k]=-1;
        }}

        solve_system(SMatrix,B,num_nos);
        no_lista=obter_cabeca(cir->nodes);
        for(i=0;no_lista;){
            noh=obter_dado(no_lista);
            if(noh->id!=referenc)
            {
                noh->volt=B[i];
                i++;
            }
            no_lista=obtem_proximo(no_lista);
        }

        free(B);
        free_matrix(SMatrix,num_nos);
        free(sper_nodes);
        free(exeptions);
        free(nodess);
    }

    void exporta_comp(void *key,FILE *fp)
    {


        if(key==NULL && fp==NULL)
        {
            printf("chave nula");
            exit(-1);
        }
        comp_t *buffer=key;
        if(buffer->id==2)
            fprintf(fp,"[label=\"%2.f Ώ\"]",retorna_x(buffer->tamanho));
        else if(buffer->id==1)
            fprintf(fp,"[label=%2.f][color=blue]",retorna_x(buffer->tamanho));
        else if(buffer->id==-1)
            fprintf(fp,"[label=%2.f][color=red]",retorna_x(buffer->tamanho));


    }


void exportar_circuito_dot(const char *filename, circ_t *circuito)
{

    FILE* fp = fopen (filename, "w");
    if (fp == NULL)
    {
        printf ("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    fprintf(fp, "digraph G {\n");
    no_t *no_lista=obter_cabeca(circuito->nodes);
    node_t *essentials;
    while(no_lista)
    {
        essentials=obter_dado(no_lista);
        fprintf(fp, "%d [label=%f]\n", essentials->id, retorna_x(essentials->volt));
        no_lista=obtem_proximo(no_lista);

    }

    exportar_grafo_a(circuito->graph,fp,exporta_comp);

}

void free_comp(void *a)
{
    if(a==NULL)
    {
        return;
    }
    comp_t *b=(comp_t *)a;
    free_tipo(b->tamanho);
}


void free_circuit(circ_t *c)
{
    libera_grafo_especial(c->graph,free_comp);
    no_t *no_lista=obter_cabeca(c->nodes),*no_temp;
    node_t *noh_tipo;
    while(no_lista!=NULL)
    {
        noh_tipo=obter_dado(no_lista);
        free_tipo(noh_tipo->volt);
        free(noh_tipo);
        no_temp=no_lista;
        no_lista=obtem_proximo(no_lista);
        free(no_temp);
    }

    free(c);


}

