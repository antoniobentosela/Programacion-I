#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define TAM 4
#define TAMM 5
#define TAMC 5
#define TAMS 4

typedef struct{

    int id;
    char descripcion[20];

}eMarca;

typedef struct{

    int id;
    char nombreColor[20];

}eColor;

typedef struct
{
    int id;
    int patente;
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;
} eAuto;

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
void mostrarAuto(eAuto x, int tam, eMarca marcas[], int tamM, eColor colores[], int tamC);
void mostrarAutos(eAuto vec[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC);
void ordenarAutos(eAuto vec[], int tam);
void inicializarAutos(eAuto vec[], int tam);
int buscarLibre(eAuto vec[], int tam);
int buscarAlumno(int id, eAuto vec[], int tam);
int altaAuto(eAuto vec[], int tam, int id, eMarca marcas[], int tamM, eColor colores[], int tamC);
eAuto newAuto(int id,int patente,int modelo,int idMarca, int idColor);
void mostrarColores(eColor colores[], int tam);
void mostrarColor(eColor color);
int cargarDescColor(int id, eColor colores[], int tam, char desc[]);
void mostrarMarcas(eMarca marca[], int tam);
void mostrarMarca(eMarca marcas);
int cargarDescMarca(int id, eMarca marcas[], int tam, char desc[]);
int modificarAuto(eMarca marcas[], int tamM, eAuto autos[], int tam, eColor colores[], int tamC);
int bajaAuto(eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC);
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
            modificarAuto(lista, TAM, marcas, TAMM, colores, TAMC);
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
            //mostrarTrabajos(trabajos, TAM,  servicios, TAMS, lista);
            break;


        case 9:
            bajaAuto(lista, TAM, marcas, TAMM, colores, TAMC);
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

void mostrarAuto(eAuto x, int tam, eMarca marcas[], int tamM, eColor colores[], int tamC)
{
    char descMarca[20];
    char descColor[20];

    cargarDescMarca(x.idMarca, marcas, tamM, descMarca);
    cargarDescColor(x.idColor, colores, tamC, descColor);

    printf("  %d  %d  %d  %d %d\n",
           x.id,
           x.patente,
           x.idColor,
           x.idMarca,
           x.modelo
           );
}

void mostrarAutos(eAuto vec[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC)
{
    int flag = 0;

    system("cls");
    printf("**** Listado de Autos ****\n\n");

    printf(" ID Patente Marca Color Modelo\n");

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
        { 20000, 300, 1000, 5000 , 2005}
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

void mostrarColores(eColor colores[], int tam){
    printf(" Id   Nombre\n\n");
    for(int i=0; i < tam; i++){
        mostrarColor( colores[i]);
    }
    printf("\n");
}

void mostrarColor(eColor color){

    printf("  %d      %10s\n", color.id, color.nombreColor);

}

int cargarDescColor(int id, eColor colores[], int tam, char desc[]){
    int todoOk = 0;

    for(int i=0; i < tam; i++){
        if( id == colores[i].id){
            strcpy(desc, colores[i].nombreColor);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}

void mostrarMarcas(eMarca marcas[], int tam){
    printf(" Id   Descripcion\n\n");
    for(int i=0; i < tam; i++){
        mostrarMarca(marcas[i]);
    }
    printf("\n");
}

void mostrarMarca(eMarca marca){

    printf("  %d      %10s\n", marca.id, marca.descripcion);

}

int cargarDescMarca(int id, eMarca marcas[], int tam, char desc[]){
    int todoOk = 0;

    for(int i=0; i < tam; i++){
        if( id == marcas[i].id){
            strcpy(desc, marcas[i].descripcion);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}

int modificarAuto(eMarca marcas[], int tamM, eAuto autos[], int tam, eColor colores[], int tamC){


    int todoOk = 0;
    int indice;
    int id;
    int opcion;
    int color;
    int marca;


    system("cls");
    printf("**** Modificar Alumno ****\n\n");

    printf("Ingrese id: ");
    scanf("%d", &id);

    indice = buscarAuto(id, autos, tam);

    if( indice == -1 )
    {
        printf("\nNo tenemos registrado ese id\n");
        system("pause");
    }
    else
    {

        mostrarAuto(autos[indice], tam, marcas, tamM, colores, tamC);

        printf("Modificar\n\n");
        printf("Color \n");
        printf("Marca\n");

        printf("Ingrese opcion:");
        scanf("%d", &opcion);

        if( opcion == 1)
        {
            mostrarColores(colores, tamC);

            printf("Ingrese color: ");
            scanf("%d", &color);
            // falta validar nota
            autos[indice].idColor = color;
            printf("Se actualizo el color");
            todoOk = 1;
        }
        else if( opcion == 2)
        {
            mostrarMarcas(marcas, tamM);
            printf("Ingrese marca: ");
            scanf("%d", &marca);
             // falta validar nota
            autos[indice].idMarca = marca;
            printf("Se actualizo la marca");
            todoOk = 1;

        }
        else
        {
            printf("No es una opcion valida\n");
        }

        system("pause");
    }
    return todoOk;
}

int bajaAuto(eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC)
{

    int todoOk = 0;
    int indice;
    int id;
    char confirma;

    system("cls");
    printf("**** Baja Auto ****\n\n");

    printf("Ingrese id: ");
    scanf("%d", &id);

    indice = buscarAuto(id, autos, tam);

    if( indice == -1 )
    {
        printf("\nNo tenemos registrado ese id\n");
        system("pause");
    }
    else
    {
        mostrarAuto(autos[indice], tam, marcas, tamM, colores, tamC);
        printf("\nConfirma eliminacion?: ");
        fflush(stdin);
        confirma = getche();
        if( confirma == 's')
        {
            autos[indice].isEmpty = 1;
            printf("\n\nSe ha eliminado el auto\n");
            todoOk = 1;
        }
        else
        {
            printf("\n\nSe ha cancelado la baja\n");
        }
        system("pause");
    }
    return todoOk;
}


