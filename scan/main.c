#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    int y;
    int cant;


    printf("Ingrese un numero: ");
    cant = scanf("%d %d", &x, &y);

    printf("cant: %d   x: %d   y: %d\n", cant, x, y);


    return 0;
}
