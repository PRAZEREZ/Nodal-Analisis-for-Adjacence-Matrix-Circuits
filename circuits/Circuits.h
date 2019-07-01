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
void exporta_comp(void *key,FILE *fp);
void exportar_circuito_dot(const char *filename, circ_t *grafo);

#endif // CIRCUITS_H_INCLUDED
