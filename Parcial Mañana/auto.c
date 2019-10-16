#include "auto.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void mostrarAuto(eAuto x, int tam, eMarca marcas[], int tamM, eColor colores[], int tamC)
{
    char descMarca[20];
    char descColor[20];

    cargarDescMarca(x.idMarca, marcas, tamM, descMarca);
    cargarDescColor(x.idColor, colores, tamC, descColor);

    printf("  %d  %d  %s  %s %d\n",
           x.id,
           x.patente,
           x.idMarca,
           x.idColor,
           x.modelo
           );
}

void mostrarAutos(eAuto vec[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC)
{
    int flag = 0;

    system("cls");
    printf("**** Listado de Autos ****\n\n");

    printf(" ID Patente Marca Color Modelo FIngreso\n");

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 0)
        {
            mostrarAuto(vec[i], tam, marcas, tamM, colores, tamC);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        system("cls");
        printf("\n---No hay autos que mostrar---");
    }

    printf("\n\n");
}

void inicializarAutos(eAuto autos[], int tam)
{

    for(int i=0; i < tam; i++)
    {
        autos[i].isEmpty = 1;
    }
}

int buscarLibre(eAuto autos[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(autos[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarAuto(int id, eAuto autos[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( autos[i].isEmpty == 0 && autos[i].id == id)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaAuto(eAuto vec[], int tam, int id, eMarca marcas[], int tamM, eColor colores[], int tamC)
{
    int todoOk = 0;
    int indice;
    int patente;
    int modelo;
    int idColor;
    int idMarca;

    system("cls");

    printf("*****Alta Auto*****\n\n");

    indice = buscarLibre(vec, tam);

    if( indice == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {
        printf("Ingrese patente: ");
        scanf("%d", &patente);

        printf("Ingrese modelo: ");
        scanf("%d", &modelo);

        mostrarMarcas(marcas, tamM);
        printf("Ingrese id marca: ");
        scanf("%d", &idMarca);

        mostrarColores(colores, tamC);
        printf("Ingrese id color: ");
        scanf("%d", &idColor);

        vec[indice] = newAuto(id, patente, modelo,idMarca, idColor);
        todoOk = 1;
        printf("Alta exitosa!!\n\n");
    }

    return todoOk;
}

eAuto newAuto(
    int id,
    int patente,
    int modelo,
    int idMarca,
    int idColor
    )
{

    eAuto au;
    au.id = id;
    au.patente = patente;
    au.modelo = modelo;
    au.idMarca = idMarca;
    au.idColor = idColor;
    au.isEmpty = 0;

    return au;
}


int hardcodearAutos(eAuto vec[], int tam, int cantidad)
{
    int cont = 0;

    eAuto suplentes[]=
    {
        { 20000, 300, 2005},
        /*{ 20001, "Alberto", 21, 'm', 2, 8, 5, {12, 5, 2019},1002, 0},
        { 20002, "Ana", 22, 'f', 4, 5, 4.5, {2, 7, 2018},1002, 0},
        { 20003, "Luis", 20, 'm', 9, 8, 8.5, {21, 5, 2018},1000, 0},
        { 20004, "Alicia", 21, 'f', 6, 7, 6.5, {11, 9, 2017},1001, 0},
        { 20005, "Diego", 23, 'm', 2, 2, 2, {12, 4, 2014},1000, 0},
        { 20006, "Sofia", 19, 'f', 8, 9, 8.5, {12, 2, 2014},1002, 0},
        { 20007, "Clara", 21, 'f', 2, 4, 3, {28, 8, 2018},1001, 0},
        { 20008, "Mauro", 20, 'm', 4, 7, 5.5, {23, 3, 2015},1001, 0},
        { 20009, "Daniela", 22, 'f', 2, 8, 4, {10, 10, 2016},1000, 0},
        { 20010, "Agustin", 24, 'm', 6, 7, 6.5, {1, 7, 2017},1002, 0}*/
    };

    if( cantidad <= 10 && tam >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {

            vec[i] = suplentes[i];
            cont++;
        }
    }

    return cont;
}
