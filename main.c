#include <stdio.h>
#include "Circuits/Circuits.h"
#include "graph/Grafo.h"
#include "Matrix/Matrix_operations.h"

#define F(x) create_tipo(x)


circ_t *exemplo1()
{
    circ_t *c=create_circuit(1,6);

    create_source(c,F(20),3,0); //+  -

    create_resitor(c,F(2),0,1);
    create_resitor(c,F(3),1,2);
    create_resitor(c,F(2),1,4);
    create_resitor(c,F(5),3,4);
    create_resitor(c,F(10),4,5);
    create_resitor(c,F(1),5,2);
    create_resitor(c,F(3),5,3);
    /*    /---\
        /       \
       3 -- 4 -- 5
       |    |    |
       +    |    |
       20   |    |
       -    |    |
       |    |    |
       0 -- 1 -- 2 */
    return c;
}

circ_t *exemplo2()
{
    circ_t *c=create_circuit(1,12);
    create_source(c,F(30),4,0);  //+  -
    create_source(c,F(20),2,6);  //+  -
    create_resitor(c,F(7),0,1);
    create_resitor(c,F(1000),1,4);
    create_resitor(c,F(3),1,5);
    create_resitor(c,F(2),1,2);
    create_resitor(c,F(1000),2,5);
    create_resitor(c,F(1000),2,9);
    create_resitor(c,F(23),2,3);
    create_resitor(c,F(2),3,9);
    create_resitor(c,F(50),4,5);
    create_resitor(c,F(5),4,7);
    create_resitor(c,F(5),5,6);
    create_resitor(c,F(2),6,8);
    create_resitor(c,F(3),6,9);
    create_resitor(c,F(1),7,10);
    create_resitor(c,F(1),7,8);
    create_resitor(c,F(1),8,11);
    create_resitor(c,F(1000),9,11);
    create_resitor(c,F(2),10,11);
    return c;

}

circ_t *exemplo3()
{
    circ_t *c =create_circuit(1,16);
    create_resitor(c,F(8),2,13);
    create_resitor(c,F(1),0,14);
    create_resitor(c,F(1),0,1);
    create_resitor(c,F(8),0,11);
    create_resitor(c,F(1),0,14);
    create_resitor(c,F(1),1,2);
    create_resitor(c,F(1),1,3);
    create_resitor(c,F(90),1,11);
    create_resitor(c,F(40),2,4);
    create_resitor(c,F(8),2,14);
    create_resitor(c,F(1),3,4);
    create_resitor(c,F(1),4,5);
    create_resitor(c,F(20),4,6);
    create_resitor(c,F(30),4,13);
    create_resitor(c,F(1),5,7);
    create_resitor(c,F(1),6,9);
    create_resitor(c,F(1),6,12);

    create_resitor(c,F(1000),7,8);
    create_resitor(c,F(60),8,10);//substitui pela proxima linha!
    create_resitor(c,F(13),8,10);//paralelo
    create_resitor(c,F(10),9,10);
    create_resitor(c,F(1),9,11);
    create_resitor(c,F(7),11,15);
    create_source(c,F(1),15,12);


    create_source(c,F(3600),8,9);
    return c;
}

circ_t *exemplo4()//com paralelo//erro
{
    circ_t *c =create_circuit(1,4);
    create_resitor(c,F(1000),0,1);
    create_resitor(c,F(200),0,1);
    create_resitor(c,F(200),0,2);
    create_resitor(c,F(22),1,2);
    create_resitor(c,F(1000),3,2);

    create_source(c,F(2),0,3);
    create_source(c,F(1),0,1);
    return c;
}

int main()
{

    circ_t *b=exemplo2();

    solve_circuit(b,1);

    //exportar_circuito_dot("exemplo.txt",b);

    free_circuit(b);
      printf("a");
    return 0;
}


