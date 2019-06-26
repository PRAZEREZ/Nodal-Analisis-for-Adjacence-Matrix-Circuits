#include "Matrix_operations.h"

tipo_t *create_type(float a){
 tipo_t tipo=a,*c;
 c=&tipo;
 return c;

}

float retorna_tipo(tipo_t *a){
float f=*a;
return f;
}

void libera_tipo(tipo_t *a){
free(a);

}
