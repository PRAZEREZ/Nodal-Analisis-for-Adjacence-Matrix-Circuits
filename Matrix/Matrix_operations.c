#include "Matrix_operations.h"
#include <stdlib.h>
struct mytype
{
    float x; //aqui voce coloca o que quiser
};

tipo_t *create_tipo(float a)
{
    tipo_t *tipo=malloc(sizeof(tipo_t));
    tipo->x=a;
    return tipo;

}
void set_tipo(tipo_t *a,float b){
a->x=b;
}

float retorna_tipo(tipo_t *a)
{
    tipo_t *f=a;
    return (float)f->x;
}

void free_tipo(tipo_t *vetor_nao_ponteiro)
{
    free(vetor_nao_ponteiro);
}
void divide(tipo_t *a,tipo_t *b){

a->x=a->x/b->x;
}
void mult(tipo_t *a,tipo_t *b){

a->x=a->x*b->x;
}
void addup(tipo_t *a,tipo_t *b)
{
    a->x=a->x+b->x;
}
void negative( tipo_t *b){


 b->x=-b->x;

}

void invert(tipo_t *a){
a->x=1/a->x;

}

tipo_t **create_vetor(int size){
 int i;
 tipo_t **vetor=malloc(sizeof(tipo_t *)*size);
 for(i=0;i<size;i++)
    vetor[i]=create_tipo(0);


    return vetor;
}

tipo_t ***create_matrix(int size){
    tipo_t ***matrix=malloc(sizeof(tipo_t **)*size);
    int i;
    for(i=0;i<size;i++)
    matrix[i]=create_vetor(size);

return matrix;

}
int is_zero(tipo_t *t){
return(t->x==0);

}

void print_matrix(tipo_t ***matrix,int size){
int i,j;
for(i=0;i<size;i++){
    for(j=0;j<size;j++)
        printf("%2f ",matrix[i][j]->x);
    printf("\n");
}






}

void solve_system(tipo_t ***matriz,tipo_t **C,int tamanho)
{

tipo_t **L;
tipo_t **G;
L=create_vetor(tamanho);
G=create_vetor(tamanho);
int iter,i,k;

for(i=0;i<tamanho;i++){
    L[i]->x=0;
    G[i]->x=0;
}


for(iter=0;iter<50;iter++)
for(i=0;i<tamanho;i++){
L[i]->x=C[i]->x/matriz[i][i]->x;
for(k=0;k<i;k++)
L[i]->x=L[i]->x-matriz[i][k]->x*L[k]->x/matriz[i][i]->x;
for(k=i+1;k<tamanho;k++)
L[i]->x=L[i]->x-matriz[i][k]->x*G[k]->x/matriz[i][i]->x;
for(k=0;k<tamanho;k++)
    G[k]->x=L[k]->x;
}
for(i=0;i<tamanho;i++)
    C[i]=L[i];
free_array(G,tamanho);
free_array(L,tamanho);

}
void free_array(tipo_t **array,int tamanho){
int i;
for(i=0;i<tamanho;i++)
free(array[i]);

}
void free_matrix(tipo_t ***M,int tamanho){
int i;
for(i=0;i<tamanho;i++)
free(M[i]);


}
 
void print_array(tipo_t **arr,int size){
    int j;
    for(j=0;j<size;j++)
        printf("\n%2f ",arr[j]->x);



}

