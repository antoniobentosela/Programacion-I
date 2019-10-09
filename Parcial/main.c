#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "marca.h"
#include "color.h"
#include "auto.h"

#define TAM 4
#define TAMM 5
#define TAMC 5
#define TAMS 4

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct{

    int id;
    char descripcion[25];
    float precio;


}eServicio;

typedef struct{

    int id;
    eAuto autos;
    int idServicio;
    eFecha fechaIngreso;

}eTrabajo;

void mostrarServicio(eServicio servicio);
void mostrarServicios(eServicio servicios[], int tam);
void mostrarTrabajo(eTrabajo x, eServicio servicios[], int tamS, eAuto autos[]);
void mostrarTrabajos(eTrabajo vec[], int tam, eServicio servicios[], int tamS, eAuto autos[]);
int menu();

int main()
{

    int id = 20000;
    eMarca marcas[TAMM]= {{1000,"Renault"},{1001,"Fiat"},{1002,"Ford"},{1003,"Chevrolet"},{1004,"Peugeot"}};
    eColor colores[TAMC]= {{5000,"Negro"},{5001,"Blanco"},{5002,"Gris"},{5003,"Rojo"},{5004,"Azul"}};
    eServicio servicios[TAMS] = {{20000,"Lavado", 250},{20001,"Pulido", 300},{20002,"Encerado", 400},{20003,"Completo", 600}};
    eAuto lista[TAM];
    eTrabajo trabajos[TAM];

    char salir = 'n';

    inicializarAutos(lista, TAM);


    id = id + hardcodearAutos(lista, TAM, 2);

   do
    {
        switch( menu())
        {
        case 1:
            if(altaAuto(lista, TAM, id, marcas, TAMM, colores, TAMC))
            {
                id++;
            }
            break;

        case 2:
            mostrarColores(colores, TAMC);
            break;

        case 3:
            ModificarAuto(lista, TAM, marcas, TAMM, colores, TAMC);
            break;

        case 4:
            mostrarAutos(lista, TAM, marcas, TAMM, colores, TAMC);
            break;

        case 5:
            //ordenarAlumnos(lista, TAM);
            break;

        case 6:
            mostrarServicios(servicios, TAMS);
            break;

        case 7:
            mostrarMarcas(marcas, TAMM);
            break;

        case 8:
            mostrarTrabajos(trabajos, TAM,  servicios, TAMS, lista);
            break;


        case 9:
            bajaAuto(lista, id, TAM, marcas, TAMM, colores, TAMC);
            break;

        case 10:
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
    printf("Menu de Opciones\n\n");
    printf("1- Alta Auto\n");
    printf("2- Listar Colores\n");
    printf("3- Modificar Auto\n");
    printf("4- Listar Autos\n");
    printf("5- Ordenar Alumno\n");
    printf("6- Listar servicios\n");
    printf("7- Listar Marcas\n\n");
    printf("8- Listar Trabajos\n\n");
    printf("9-Baja auto\n");
    printf("10- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void mostrarServicios(eServicio servicios[], int tam){
    printf(" Id   Servicio  Precio\n\n");
    for(int i=0; i < tam; i++){
        mostrarServicio(servicios[i]);
    }
    printf("\n");
}

void mostrarServicio(eServicio servicio){

    printf("  %d  %s  %2.f\n",
           servicio.id,
           servicio.descripcion,
           servicio.precio
           );

}

int cargarDescServicio(int id, eServicio servicios[], int tam, char desc[]){
    int todoOk = 0;

    for(int i=0; i < tam; i++){
        if( id == servicios[i].id){
            strcpy(desc, servicios[i].descripcion);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}

void mostrarTrabajo(eTrabajo x, eServicio servicios[], int tamS, eAuto autos[])
{
    char descServicio[25];

    cargarDescServicio(x.idServicio, servicios, tamS, descServicio);

    printf("%d  %d  %02d/%02d/%d  %s\n",
           x.id,
           x.autos.patente,
            x.fechaIngreso.dia,
           x.fechaIngreso.mes,
           x.fechaIngreso.anio,
           descServicio
           );
}

void mostrarTrabajos(eTrabajo vec[], int tam, eServicio servicios[], int tamS, eAuto autos[])
{
    int flag = 0;

    system("cls");
    printf("**** Listado de Trabajos ****\n\n");

    printf(" ID Patente Servicio Fecha\n");

    for(int i=0; i < tam; i++)
    {
        mostrarTrabajo(vec[i], servicios, tamS, autos);
        flag = 1;

    }

    if( flag == 0)
    {
        system("cls");
        printf("\n---No hay autos que mostrar---");
    }

    printf("\n\n");
}
