#ifndef MATRIX_H_INCLUDED
#define MATRIX_F_INCLUDED

typedef struct mytype tipo_t;

float retorna_tipo(tipo_t *a);
tipo_t *create_tipo(float a);
void set_tipo(tipo_t *a,float b);
void free_tipo(tipo_t *vetor_nao_ponteiro);
void addup(tipo_t *a,tipo_t *b);
tipo_t **create_vetor(int tamanho);
tipo_t ***create_matrix(int size);
void print_matrix(tipo_t ***matrix,int size);
void print_array(tipo_t **arr,int size);
int is_zero(tipo_t *t);
void divide(tipo_t *a,tipo_t *b);
void invert(tipo_t *a);
void mult(tipo_t *a,tipo_t *b);
void free_array(tipo_t **array,int tamanho);
void negative( tipo_t *b);
void free_matrix(tipo_t ***M,int tamanho);

#endif // MATRIX_H_INCLUDED
