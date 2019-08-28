#include <stdio.h>
#include <stdlib.h>

float calcularSupCirculo (float);

int main()
{
    float r;
    float sup;

    printf("Ingrese el radio: ");
    scandf ("%f", &r);

    printf("La superficie es %f: ", r);

    return 0;
}

float calcularSupCirculo (float radio){

float superficie;

superficie = 3,14 * (radio * radio)

return superficie;
}
