#include <stdio.h>
#include <stdlib.h>


int main()
{
    //                                                  unaFuncion                (        )
    //tipo de dato que devuelve la funcion              nombre de la funcion       parametros

    // Ej: letra = tolower (letra);

    int numero1;
    int numero2;
    int suma;

    printf ("ingrese un numero: ");
    scanf ("%d", numero1);

    printf ("ingrese otro numero: ");
    scanf ("%d", numero2);

    //suma = numero1 + numero2;

    suma = sumar1(numero1, numero2);

    printf("La suma de los numeros es %d\n", suma);

    // suma1 = (recibe los numero) y devuelve la suma.

    int sumar1 (int a, int b); // prototipo de la funcion.



    return 0;
}

int sumar1 (int a, int b){

    int suma;

    suma = a + b;

    return suma;

}
