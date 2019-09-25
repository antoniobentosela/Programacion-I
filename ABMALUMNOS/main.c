#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "carrera.h"
#include "alumno.h"

#define TAM 10
#define TAMC 3

int menu();
int menuInformes();
void InformesAlumnos(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
void MostrarAlumnosDeUnaCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
void MostrarAlumnosCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC, int idCarrera);
void mostrarAlumnosXCarrera (eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
void cantidadAlumnosXCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);


int main()
{
    int legajo = 20000;
    eCarrera carreras[TAMC]={{1000,"TUP"},{1001,"TUSI"},{1002,"LIC"}};
    eAlumno lista[TAM];
    char salir = 'n';

    inicializarAlumnos( lista, TAM);

    legajo = legajo + hardcodearAlumnos(lista, TAM, 6);

    do
    {
        switch( menu())
        {
        case 1:
            if(altaAlumno(lista, TAM, legajo, carreras, TAMC))
            {
                legajo++;
            }
            break;

        case 2:
            bajaAlumno(lista, TAM, carreras, TAMC);
            break;

        case 3:
            ModificarAlumno(lista, TAM, carreras, TAMC);
            break;

        case 4:
            mostrarAlumnos(lista, TAM, carreras, TAMC);
            break;

        case 5:

            ordenarAlumnos(lista, TAM);
            break;

        case 6:

            InformesAlumnos(lista, TAM, carreras, TAMC);

            break;
        case 7:
            mostrarCarreras(carreras, TAMC);
            break;

        case 8:
            printf("Confirma salir?:");
            fflush(stdin);
            salir = getche();
            break;

        default:
            printf("\nOpcion Invalida!\n\n");
        }
        system("pause");
    }
    while(salir == 'n');

    return 0;
}

int menu()
{
    int opcion;

    system("cls");
    printf("****** ABM Alumnos *******\n\n");
    printf("1-Alta alumno\n");
    printf("2-Baja alumno\n");
    printf("3-Modificar alumno\n");
    printf("4-Listar alumnos\n");
    printf("5-Ordenar alumnos\n");
    printf("6-Informes alumno\n");
    printf("7-Mostrar Carreras\n");
    printf("8-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int menuInformes()
{
    int opcion;

    system("cls");
    printf("****** Informes *******\n\n");
    printf("1-Mostrar Alumnos de una Carrera\n");
    printf("2-Mostrar Alumnos por Carrera\n");
    printf("3-Mostrar Cantidad de alumnos por Carrera\n");
    printf("4-Mostrar Carrera con mas inscriptos\n");
    printf("5-Mostrar Mejor Promedio por Carrera\n");
    printf("6-Mostrar Alumnos Varones\n");
    printf("7-Mostrar Mujeres de Alguna Carrera\n");
    printf("8-Mostrar Alumnos mayores a 30 de Licenciatura\n");
    printf("9-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void InformesAlumnos (eAlumno alumnos[], int tam, eCarrera carreras[], int tamC){

    char salir = 'n';
    system("cls");
    printf("*****Informes Alumnos*****\n\n");


    do
    {
        switch( menuInformes())
        {
        case 1:

            MostrarAlumnosDeUnaCarrera(alumnos, tam, carreras, tamC);

            break;

        case 2:

           mostrarAlumnosXCarrera(alumnos, tam, carreras, tamC);
            break;

        case 3:

            cantidadAlumnosXCarrera(alumnos, tam, carreras, tamC);
            break;

        case 4:

            printf("Informe 4\n");
            break;

        case 5:

            printf("Informe 5\n");
            break;

        case 6:

            printf("Informe 6\n");

            break;
        case 7:


          printf("Informe 7\n");
            break;

        case 8:


          printf("Informe 7\n");
            break;

        case 9:
            printf("Confirma salir?:");
            fflush(stdin);
            salir = getchar();
            break;

        default:
            printf("\nOpcion Invalida!\n\n");
        }
        system("pause");
    }
    while(salir == 'n');
}

void MostrarAlumnosDeUnaCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC){

int idCarrera;

system("cls");
printf("****Carreras****");
mostrarCarreras(carreras, tamC);

    printf("Ingrese id carrera: ");
    scanf("%d", &idCarrera);

    MostrarAlumnosCarrera(alumnos, tam, carreras, tamC, idCarrera);



}

void MostrarAlumnosCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC, int idCarrera){

    char desc[20];
    int flag = 0;

    cargarDescCarrera(idCarrera, carreras, 10, desc);

    printf("Carrera: %s", desc);
    printf("\n\n");

    for(int i=0; i < tam; i++){


       if (alumnos [i].isEmpty == 0 && alumnos[i].idCarrera == idCarrera){

        mostrarAlumno(alumnos[i], carreras, tamC);

        flag = 1;

       }
    }
    if (flag == 0){

        printf("No hay Alumnos cursando %s", desc);

    }

    printf("\n\n");
}

void mostrarAlumnosXCarrera (eAlumno alumnos[], int tam, eCarrera carreras[], int tamC){


    system("cls");

    printf("****Listado de Alumnos****\n\n");

    for(int i = 0; i < tamC; i ++){

        MostrarAlumnosCarrera(alumnos, tam, carreras, tamC, carreras[i].id);
    }


    printf("\n\n");

}

void cantidadAlumnosXCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC){

int contador = 0;
char desc[20];

system("cls");

    printf("****Cantidad de alumnos****\n\n");

    for(int i = 0; i < tamC; i ++){

            cargarDescCarrera(carreras[i].id, carreras, 10, desc);
            printf("Carrera: %s\n\n", desc);

            for(int j = 0; j < tam; j++){
                if(alumnos[j].isEmpty == 0 && alumnos[j].idCarrera == carreras[i].id){
                    contador ++;
                }
            }

        printf("Cantidad: %d\n\n", contador);
        contador = 0;
    }


    printf("\n\n");
}

void carreraMasInscriptos (eAlumno alumnos[], int tam, eCarrera carreras[], int tamC){

int contador = 0;
char desc[20];

system("cls");

    printf("****Carrera con mas alumnos****\n\n");

    for(int i = 0; i < tamC; i ++){

            cargarDescCarrera(carreras[i].id, carreras, 10, desc);
            printf("Carrera: %s\n\n", desc);

            for(int j = 0; j < tam; j++){
                if(alumnos[j].isEmpty == 0 && alumnos[j].idCarrera == carreras[i].id){
                    contador ++;
                }

                if ()
            }

        printf("Cantidad: %d\n\n", contador);
        contador = 0;
    }


    printf("\n\n");




}
