#include <stdio.h>
#include "Circuits/Circuits.h"
#include "graph/Grafo.h"
#include "Matrix/Matrix_operations.h"

#define F(x) create_type(x)



int main(){
    tipo_t *a=F(1.1);
    printf("%f",retorna_tipo(a));
    return 0;
}
