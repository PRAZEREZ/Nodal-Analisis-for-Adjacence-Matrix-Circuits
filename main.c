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
    /*    /---\
        /       \
       3 -- 4 -- 5
       | \_ |_  /|
       +    |    |
       20   |   |
       -    |    |
       |    |    |
       0 -- 1 -- 2 */
    return c;
}

circ_t *exemplo2()
{



    return NULL;
}

circ_t *exemplo3()
{

    return NULL;
}

int main()
{

    circ_t *b=exemplo1();
    solve_circuit(b);

    return 0;
}


