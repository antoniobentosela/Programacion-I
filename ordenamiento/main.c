#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void mostrarVectorInt(int vec[], int tam);
void ordenarVectorInt (int vec[], int tam, int criterio);

int main()
{
    int vec [TAM] = {7, 5, 8, 1, 3};

    printf("Vector sin ordenar\n\n");
    mostrarVectorInt(vec, TAM);

    // ordeno el vector de manera ascendente
    ordenarVectorInt (vec, TAM, 0);

    printf("\n\nVector ordenado de menor a mayor\n\n");

    mostrarVectorInt(vec, TAM);

    // ordeno el vector de manera descendente
    ordenarVectorInt (vec, TAM, 1);

    printf("\n\nVector ordenado de mayor a menor\n\n");

    mostrarVectorInt(vec, TAM);

    printf("\n\n");

    return 0;
}

void mostrarVectorInt(int vec[], int tam)
{

    for (int  i = 0 ; i < 5 ; i ++ )
    {

        printf ("%d ", vec[i]);

    }
}

void ordenarVectorInt (int vec[], int tam, int criterio)
{

    int aux;

    for (int i = 0; i < TAM-1; i++)
    {

        for (int j = i; j < TAM; j++)
        {

            if (criterio == 0)
            {

                if(vec[j] < vec[i])         // Si quiero ordenar al revez, en este caso de mayor a menor, solamente cambio el signo "<"
                {

                    aux = vec[j];
                    vec[j] = vec[i];
                    vec[i] = aux;

                }

            }
            else
            {

                if (criterio == 1)
                {

                    if(vec[j] > vec[i])
                    {

                        aux = vec[j];
                        vec[j] = vec[i];
                        vec[i] = aux;
                    }
                }
            }
        }
    }
}

