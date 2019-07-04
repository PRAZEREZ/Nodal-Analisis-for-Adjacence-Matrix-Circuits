#ifndef CIRCUITS_H_INCLUDED
#define CIRCUITS_H_INCLUDED
#include "../graph/Grafo.h"
#include "../Matrix/Matrix_operations.h"
#include "../Linked_list/lista_enc.h"

typedef struct circuits circ_t;
typedef struct component comp_t;
typedef struct node node_t;
/**
  * @brief  Cria um circuito
  * @param	id: Identificador numerico do circuito
  * @param	tamanho: Num de vertices do circuito
  * @retval circ_t *: ponteiro para circuito
  */
circ_t *create_circuit(int id, int tamanho);
/**
  * @brief  Retorna um grafo associado a um circuito
  * @param	circ: Ponteiro do circuito
  * @retval grafo_t *: ponteiro para circuito
  */
grafo_t *get_graph(circ_t *circ);
/**
  * @brief  Cria um fonte de tensao entre os vertices
  * @param	cir: Ponteiro do circuito
  * @param	v: Valor da tensao
  * @param	a: vertice positivo
  * @param	b: vertice negativo
  * @retval nenhum.
  */
void create_source(circ_t *cir,tipo_t *v,int a,int b);
/**
  * @brief  Cria um fonte de tensao entre os vertices
  * @param	cir: Ponteiro do circuito
  * @param	res: Valor da resistencia
  * @param	a: primeiro vertice do resitor
  * @param	b: segundo vertice do resistor
  * @retval nenhum.
  */
void create_resitor(circ_t *cir,tipo_t *res, int a,int b);
/**
  * @brief  Determina as tencoes de no do circuito
  * @param	cir: Ponteiro do circuito
  * @param	referenc: vertice de referencia
  * @retval nenhum.
  */
void solve_circuit(circ_t *cir,int referenc);
/**
  * @brief  Retorna o valor de um resistor
  * @param	key: Ponteiro do componente associado a aresta
  * @retval tipo_t *: Valor do resistor. Ou tipo com valor nulo.
  */
tipo_t *circuit_get_res(void *key);
/**
  * @brief  Retorna o valor de uma fonte
  * @param	key: Ponteiro do componente associado a aresta
  * @retval tipo_t *: Valor da tensao. Ou tipo com valor nulo.
  */
tipo_t *circuit_get_volt(void *key);
/**
  * @brief  Adiciona os nos essencias na lista encadeada
  * @param	c: Circuito o qual nao tem nos essencias.
  * @retval Nenhum
  */

void nohs_essenciais(circ_t *c);
/**
  * @brief  Libera a memoria do grafo e do circuito
  * @param	c: Circuito a ser liberado
  * @retval Nenhum
  */
void free_circuit(circ_t *c);
/**
  * @brief  Exporta um componente do circuito em linguagem dot
  * @param	key: Componente a ser exportado
  * @param	fp: Ponteiro para o arquivo
  * @retval Nenhum
  */
void exporta_comp(void *key,FILE *fp);
/**
  * @brief  Libera uma variavel do tipo comp_t *
  * @param	a: ponteiro void, vai ser convertido para comp_t
  * @retval Nenhum
  */
void free_comp(void *a);
/**
  * @brief  Exporta o circuito em linguagem dot
  * @param	c: Circuito a ser exportado
  * @retval Nenhum
  */
void exportar_circuito_dot(const char *filename, circ_t *grafo);
/**
  * @brief  Retorna vetor nulo
  * @param	key: ponteiro
  * @retval tipo_t*: Vetor nulo
  */
tipo_t* return_null(void *key);
#endif // CIRCUITS_H_INCLUDED
