#include <stdio.h>
#include <stdlib.h>

#define  TAM 1

void mostrarAlumnos(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam);
void mostrarAlumno(int leg, int age, char sexo, int nota1, int nota2, float promedio);

int main()
{
    int legajos[TAM];
    int edades[TAM];
    char sexos [TAM];
    int notasp1[TAM];
    int notasp2 [TAM];
    float promedios [TAM];

    for (int i = 0; i < TAM; i++){

        printf ("Ingrese legajo: ");
        scanf ("%d", &legajos[i]);
        printf ("Ingrese edad: ");
        scanf ("%d", &edades[i]);
        printf ("Ingrese sexo: ");
        fflush(stdin);
        scanf ("%c", &sexos[i]);
        printf ("Ingrese nota primer parcial: ");
        scanf ("%d", &notasp1[i]);
        printf ("Ingrese nota segundo parcial: ");
        scanf ("%d", &notasp2[i]);

        promedios [i] = (float) (notasp1[i] + notasp2[i]) / 2; // El float es un casteo, le dice a la maquina q vaa recibir un float en vez de un int.

    }

    mostrarAlumnos(legajos, edades, sexos, notasp1, notasp2, promedios, TAM);

    return 0;
}

void mostrarAlumnos(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam){

printf ("\n\n");

    printf(" Legajo  Edad  Sexo  Nota1  Nota2  Promedio\n\n");

    for (int i = 0; i < tam; i++){

        mostrarAlumno()

}

    printf("\n\n");

}

void mostrarAlumno(int leg, int age, char sexo, int nota1, int nota2, float promedio){

printf("  %d       %d    %c    %d     %d      %.2f\n", leg, age, sexo, nota1, nota2, promedio);

}


