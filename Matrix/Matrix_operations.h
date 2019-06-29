#ifndef MATRIX_H_INCLUDED
#define MATRIX_F_INCLUDED

typedef struct mytype tipo_t;

float retorna_tipo(tipo_t *a);
tipo_t *create_tipo(float a);
void set_tipo(tipo_t *a,float b);
void free_tipo(tipo_t *vetor_nao_ponteiro);
void addup(tipo_t *a,tipo_t *b);
tipo_t **create_vetor(int tamanho);
void print_matrix(tipo_t ***matrix,int size);
#endif // MATRIX_H_INCLUDED
