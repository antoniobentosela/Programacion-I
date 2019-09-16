#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILAS 5
#define COLUMNAS 20

#define TAM 5

void mostrarAlumnos( char mat[] [20], int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam, int filas);
void mostrarAlumno(char nom[], int leg, int age, char sexo, int nota1, int nota2, float promedio);
void ordenarVectorLeg( char mat[][20],int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam);
void ordenarVectorSex( char mat[][20],int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam);
void ordenarVectorSexLeg( int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam);
//void mostrarNombres( char mat[][20], int filas);
void ordenarNombres( char mat[][20], int filas);



int main()
{
    int legajos[TAM] = {800, 432, 567, 879, 876};
    int edades[TAM] =  {21, 23, 20, 21, 30};
    char sexos[TAM] = {'f', 'f', 'm', 'f', 'm'};
    int notasp1[TAM] = {2, 4, 7, 8, 5};
    int notasp2[TAM] = {4, 10, 9, 4, 2};
    float promedios[TAM] = { 3, 7, 8, 6, 3.5};
     char nombres[FILAS][COLUMNAS] =
    { "Juan",
      "Manuel",
      "Alicia",
      "Sofia",
      "Claudia"
    };
    //char auxCad[100];

    /* for(int i = 0; i < TAM; i++){

         printf("Ingrese legajo: ");
         scanf("%d", &legajos[i]);

         printf("Ingrese edad: ");
         scanf("%d", &edades[i]);

         printf("Ingrese sexo: ");
         fflush(stdin);
         scanf("%c", &sexos[i]);

         printf("Ingrese Nota Primer Parcial: ");
         scanf("%d", &notasp1[i]);

         printf("Ingrese Nota Segundo Parcial: ");
         scanf("%d", &notasp2[i]);

         promedios[i] = (float) (notasp1[i] + notasp2[i]) / 2;
     }*/

     /*
    for(int i=0; i < FILAS; i++){
        printf("Ingrese un nombre: ");
        fflush(stdin);
        gets(auxCad);

        while(strlen(auxCad) >19){
            printf("Nombre demasiado largo. Maximo 19 caracteres\nReingrese nombre: ");
            fflush(stdin);
            gets(auxCad);
        }
        strcpy(nombres[i], auxCad);
    }*/

    //mostrarNombres(nombres, FILAS);

    //ordenarNombres(nombres, FILAS);

    //mostrarNombres(nombres, FILAS);

    mostrarAlumnos(nombres, legajos, edades, sexos, notasp1, notasp2, promedios, TAM, FILAS);

    ordenarVectorLeg (nombres, legajos, edades, sexos, notasp1, notasp2, promedios, TAM); //ordeno por legajo

    mostrarAlumnos(nombres, legajos, edades, sexos, notasp1, notasp2, promedios, TAM, FILAS);

    ordenarVectorSex (nombres, legajos, edades, sexos, notasp1, notasp2, promedios, TAM); // ordeno por sexo

    mostrarAlumnos(nombres, legajos, edades, sexos, notasp1, notasp2, promedios, TAM, FILAS);

    ordenarVectorSexLeg (legajos, edades, sexos, notasp1, notasp2, promedios, TAM); //ordeno por Sexo, y los sexos los ordeno por legajo.

    mostrarAlumnos(nombres, legajos, edades, sexos, notasp1, notasp2, promedios, TAM, FILAS);

    ordenarNombres(nombres, FILAS);

    mostrarAlumnos(nombres, legajos, edades, sexos, notasp1, notasp2, promedios, TAM, FILAS);


    return 0;
}

void mostrarAlumnos( char mat[][20], int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam, int filas)
{

    printf(" Nombre Legajo  Edad  Sexo  Nota1  Nota2  Promedio\n\n");
    for(int i=0; i < tam; i++)
    {
        mostrarAlumno(mat[i], leg[i], age[i], sex[i], n1[i], n2[i], prom[i]);
    }
    printf("\n\n");
}



void mostrarAlumno(char nom[], int leg, int age, char sexo, int nota1, int nota2, float promedio)
{

    printf("%s   %d     %d    %c     %d    %d     %.2f\n", nom, leg, age, sexo, nota1, nota2, promedio);

}

void ordenarVectorLeg(char mat[][20], int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam)
{

    int auxInt;
    float auxFloat;
    char auxChar;
    char aux[20];

    for (int i = 0; i < TAM-1; i++)
    {

        for (int j = i; j < TAM; j++)
        {

            if(leg[j] < leg[i] && strcmp(mat[i], mat[j]) > 0)         // Si quiero ordenar al revez, en este caso de mayor a menor, solamente cambio el signo "<"
            {

                strcpy(aux, mat[i]);
                strcpy(mat[i], mat[j]);
                strcpy(mat[j], aux);

                auxInt = leg[j];
                leg[j] = leg[i];
                leg[i] = auxInt;

                auxInt = age[j];
                age[j] = age[i];
                age[i] = auxInt;

                auxChar = sex[j];
                sex[j] = sex[i];
                sex[i] = auxChar;

                auxInt = n1[j];
                n1[j] = n1[i];
                n1[i] = auxInt;

                auxInt = n2[j];
                n2[j] = n2[i];
                n2[i] = auxInt;

                auxFloat = prom[j];
                prom[j] = prom[i];
                prom[i] = auxFloat;

            }
        }
    }
}

void ordenarVectorSex( char mat[][20], int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam)
{

    int auxInt;
    float auxFloat;
    char auxChar;
    char aux[20];

    for (int i = 0; i < TAM-1; i++)
    {

        for (int j = i; j < TAM; j++)
        {

            if(sex[j] < sex[i] && strcmp(mat[i], mat[j]) > 0)         // Si quiero ordenar al revez, en este caso de mayor a menor, solamente cambio el signo "<"
            {

                strcpy(aux, mat[i]);
                strcpy(mat[i], mat[j]);
                strcpy(mat[j], aux);

                auxInt = leg[j];
                leg[j] = leg[i];
                leg[i] = auxInt;

                auxInt = age[j];
                age[j] = age[i];
                age[i] = auxInt;

                auxChar = sex[j];
                sex[j] = sex[i];
                sex[i] = auxChar;

                auxInt = n1[j];
                n1[j] = n1[i];
                n1[i] = auxInt;

                auxInt = n2[j];
                n2[j] = n2[i];
                n2[i] = auxInt;

                auxFloat = prom[j];
                prom[j] = prom[i];
                prom[i] = auxFloat;

            }
        }
    }
}

void ordenarVectorSexLeg(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam){

    int auxInt;
    float auxFloat;
    char auxChar;



    for(int i=0; i < tam-1; i++){
        for(int j = i +1; j < tam; j++){

            if( sex[i] > sex[j]){
                    auxInt = leg[i];
                leg[i] = leg[j];
                leg[j] = auxInt;

                auxInt = age[i];
                age[i] = age[j];
                age[j] = auxInt;

                auxChar = sex[i];
                 sex[i] = sex[j];
                 sex[j] = auxChar;

                auxInt = n1[i];
                 n1[i] = n1[j];
                 n1[j] = auxInt;

                auxInt = n2[i];
                 n2[i] = n2[j];
                 n2[j] = auxInt;

              auxFloat = prom[i];
               prom[i] = prom[j];
               prom[j] = auxFloat;
            }
            else if( sex[i] == sex[j] && leg[i] > leg[j]){

                auxInt = leg[i];
                leg[i] = leg[j];
                leg[j] = auxInt;

                auxInt = age[i];
                age[i] = age[j];
                age[j] = auxInt;

                auxChar = sex[i];
                 sex[i] = sex[j];
                 sex[j] = auxChar;

                auxInt = n1[i];
                 n1[i] = n1[j];
                 n1[j] = auxInt;

                auxInt = n2[i];
                 n2[i] = n2[j];
                 n2[j] = auxInt;

              auxFloat = prom[i];
               prom[i] = prom[j];
               prom[j] = auxFloat;
            }
        }
    }
}



//Si quisiera hacer mas chico el codigo puedo utilizar un flag:

/*void ordenarAlumnosSexLeg( int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam){

    int auxInt;
    float auxFloat;
    char auxChar;
    int swap = 0;

    for(int i=0; i < tam-1; i++){
        for(int j = i +1; j < tam; j++){

            if( sex[i] > sex[j]){
                    swap = 1;
            }
            else if( sex[i] == sex[j] && leg[i] > leg[j]){

                    swap = 1;
            }

            if( swap ){

                auxInt = leg[i];
                leg[i] = leg[j];
                leg[j] = auxInt;

                auxInt = age[i];
                age[i] = age[j];
                age[j] = auxInt;

                auxChar = sex[i];
                 sex[i] = sex[j];
                 sex[j] = auxChar;

                auxInt = n1[i];
                 n1[i] = n1[j];
                 n1[j] = auxInt;

                auxInt = n2[i];
                 n2[i] = n2[j];
                 n2[j] = auxInt;

              auxFloat = prom[i];
               prom[i] = prom[j];
               prom[j] = auxFloat;
            }

            swap = 0;
        }
    }
}*/

/*void mostrarNombres( char mat[][20], int filas){
    for(int i=0; i < filas; i++){
        printf("%s\n", mat[i]);
    }
    printf("\n\n");
}*/
void ordenarNombres( char mat[][20], int filas){
char aux[20];

    for(int i=0; i < filas -1; i++){
        for( int j = i +1; j < filas; j++){
            if(strcmp(mat[i], mat[j]) > 0){

                strcpy(aux, mat[i]);
                strcpy(mat[i], mat[j]);
                strcpy(mat[j], aux);

            }
        }
    }



}





