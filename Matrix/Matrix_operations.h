#ifndef MATRIX_H_INCLUDED
#define MATRIX_F_INCLUDED
#include <stdio.h>

typedef struct mytype tipo_t;
/**
  * @brief  Retorna o parametro x de tipo_t
  * @param	a: ponteiro o qual se deseja saber o valor de x
  *
  * @retval float: paramtro x do ponterio tipo_t
  */
float retorna_x(tipo_t *a);
/**
  * @brief  Cria um novo tipo recebendo um float
  * @param	a: Valor de x para o tipo
  *
  * @retval tipo_t *: ponteiro para o novo tipo
  */
tipo_t *create_tipo(float a);
/**
  * @brief  Muda o valor de x de um tipo
  * @param	a: ponteiro para o tipo
  * @param	b: novo valor de x para o tipo
  *
  * @retval nenhum.
  */
void set_tipo_x(tipo_t *a,float b);
/**
  * @brief  Libeira a memoria de um tipo
  * @param	a: ponteiro para o tipo
  *
  * @retval nenhum.
  */
void free_tipo(tipo_t *vetor_nao_ponteiro);
/**
  * @brief  Incremento
  * @param	a: variavel que vai ser incrementada
  * @param	b: Variavel do quanto vai incrementar
  * @retval nenhum.
  */
void addup(tipo_t  *a,tipo_t *b);
/**
  * @brief  Cria um novo vetor tipo_t
  * @param	tamanho: tamanho do vetor
  *
  * @retval tipo_t **: vetor de tipo_t
  */
tipo_t **create_vetor(int tamanho);
/**
  * @brief  Cria uma nova matriz de tipo_t
  * @param	tamanho: tamanho da matriz
  *
  * @retval tipo_t ***: matriz de tipo_t
  */
tipo_t ***create_matrix(int tamanho);
/**
  * @brief  Printa uma matriz
  * @param	tamanho: tamanho da matriz
  * @param  matrix: Matriz que vai ser printada
  * @retval Nenhum
  */
void print_matrix(tipo_t ***matrix,int size);
/**
  * @brief  Printa um vetor
  * @param	tamanho: tamanho da vetor
  * @param  arr: Vetor que vai ser printado
  * @retval Nenhum
  */
void print_array(tipo_t **arr,int size);
/**
  * @brief  Determina se um tipo e nulo
  * @param	t: tipo que talvez seja zero
  * @retval int: 1 se t for nulo, 0 se t nao for nulo
  */
int is_zero(tipo_t *t);
/**
  * @brief  Divide a por b
  * @param	a: Numerador, vai ser alterado
  * @param	b: Denominador
  * @retval nenhum.
  */
void divide(tipo_t *a,tipo_t *b);
/**
  * @brief  Eleva a por -1
  * @param	a: Variavel a ser invertida
  * @retval nenhum.
  */
void invert(tipo_t *a);
/**
  * @brief  Multiplica a por b
  * @param	a: variavel que vai ser multiplicada
  * @param	b: Variavel do quanto vai Multiplicar
  * @retval nenhum.
  */
void mult(tipo_t *a,tipo_t *b);
/**
  * @brief  Libera um vetor de tipo_t
  * @param	a: variavel que vai ser liberada
  * @param	tamanho: tamanho do vetor
  * @retval nenhum.
  */
void free_array(tipo_t **array,int tamanho);
/**
  * @brief  Inverte o sinal de um tipo
  * @param	b: Variavel a ser negativada
  * @retval nenhum.
  */
void negative( tipo_t *b);
/**
  * @brief  Libera uma matriz de tipo_t
  * @param	M: Matriz a ser liberada
  * @param	tamanho: tamanho da matriz
  * @retval nenhum.
  */
void free_matrix(tipo_t ***M,int tamanho);
/**
  * @brief Resolve sistemas lineares, método Gauss Siedel
  * @param	matriz: Matriz de termos dependentes
  * @param	C: Vetor de termos idependentes
  * @param	tamanho: tamanho da matriz
  * @retval nenhum.
  */
void solve_system(tipo_t ***matriz,tipo_t **C,int tamanho);
#endif // MATRIX_H_INCLUDED
