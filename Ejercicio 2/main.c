#include <stdio.h>
#include <stdlib.h>

int main()
{

int numeros [5];
int indice;
int flag = 0;
int Max;


for (int i = 0 ; i < 5 ; i ++){

    printf ("Ingrese un numero positivo: ");
    scanf("%d", &numeros[i]);
    while (numeros [i] <= 0){

    printf ("Error.Ingrese un numero positivo: ");
    scanf("%d", &numeros[i]);
}
}


    for (int i = 0; i < 5; i ++){

        printf (" %d", numeros[i]);

    }

    for (int i = 0; i < 5; i ++){

    if (numeros[i] > Max || flag == 0){

        Max = numeros [i];
        flag = 1;
    }

    }

    printf ("\nEl numero mayor es %d", Max);


    return 0;
}
