#include "Matrix_operations.h"
#include <stdlib.h>
struct mytype
{
    float r;
};

tipo_t *create_tipo(float a)
{
    tipo_t *tipo=malloc(sizeof(tipo_t));
    tipo->r=a;
    return tipo;

}
void set_tipo(tipo_t *a,float b){
a->r=b;
}

float retorna_tipo(tipo_t *a)
{
    tipo_t *f=a;
    return (float)f->r;
}

void free_tipo(tipo_t *vetor_nao_ponteiro)
{
    free(vetor_nao_ponteiro);
}

void addup(tipo_t *a,tipo_t *b)
{
    a->r=a->r+b->r;
}

tipo_t *invert(tipo_t *a){
tipo_t *b=create_tipo(1/a->r);


return b;
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
void print_matrix(tipo_t ***matrix,int size){
int i,j;
for(i=0;i<size;i++){
    for(j=0;j<size;j++)
        printf("%5.f ",matrix[i][j]->r);
    printf("\n");
}






}

void solve_system(tipo_t ***matrix,tipo_t **b,int size){


}

