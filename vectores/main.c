#include <stdio.h>
#include <stdlib.h>

void mostrarVectorInt(int vec[], int tam);
void mostrarVectorChar(char vec[], int tam);
void mostrarVectorFloat(float vec[], int tam);

int main()
{

    int numeros [] = {23, 21, 43, 54, 28, 21, 66, 88, 32, 50};
    char x[] = {'a', 'e', 'i', 'o', 'u'};
    char nombre[] = {'J', 'u', 'a', 'n', '\0', 'r', '4', 'y'};
    float reales[] = {23.5, 56.34, 55.1, 89.7, 90.9};

    mostrarVectorInt (numeros, 10);
    printf ("\n\n");
    printf ("%s", nombre); // muestra los caractere en cadena
    printf ("\n\n");
    mostrarVectorChar( x, 5); // muestra los caracteres por separado
    printf ("\n\n");
    mostrarVectorFloat(reales, 5);
    printf ("\n\n");

    return 0;
}

void mostrarVectorInt(int vec[], int tam){

 for (int  i = 0 ; i < 10 ; i ++ ){

    printf ("%d ", vec[i]);

   }
}

void mostrarVectorChar(char vec[], int tam){

    for (int  i = 0 ; i < 5 ; i ++ ){

    printf ("%c ", vec[i]);

   }
}

void mostrarVectorFloat(float vec[], int tam){

for (int  i = 0 ; i < 5 ; i ++ ){

    printf ("%.1f ", vec[i]); // el punto y el numero determinan cuantos numeros despues de la coma se muestran.
                             // si fuese .2, en el primer caso por ej mostraria 23.50, en vez de 23.5

   }

}
