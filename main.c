#include <stdio.h>
#include "Circuits/Circuits.h"
#include "graph/Grafo.h"
#include "Matrix/Matrix_operations.h"

#define F(x) create_tipo(x)

circ_t *exemplo1()
{
    circ_t *c=create_circuit(1,6);
    create_source(c,F(20),1,0);

    create_resitor(c,F(5),3,4);
    create_resitor(c,F(10),4,5);
    create_resitor(c,F(2),1,4);
    create_resitor(c,F(2),0,1);
    create_resitor(c,F(3),1,2);
    create_resitor(c,F(1),5,2);
    create_resitor(c,F(3),5,3);






}

circ_t *exemplo2()
{




}

circ_t *exemplo3()
{


}

int main()
{
    tipo_t **a=create_vetor(3);
    int i;
    set_tipo(a[2],5);
    circ_t *b=exemplo1();
    for(i=0; i<3; i++)
        printf("%f\n",retorna_tipo(a[i]));




    return 0;
}


