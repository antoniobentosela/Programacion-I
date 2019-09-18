#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define TAM 5

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    int edad;
    char sexo;
    int nota1;
    int nota2;
    float promedio;
    eFecha fechaIngreso;
    int isEmpty;
} eAlumno;



void mostrarAlumno(eAlumno x);
void mostrarAlumnos(eAlumno vec[], int tam);
void ordenarAlumnos(eAlumno vec[], int tam);
void inicializarAlumnos(eAlumno alumnos[], int tam);
int buscarLibrer(eAlumno alumnos[], int tam);
int buscarAlumno(int legajo, eAlumno alumnos[], int tam);
int altaAlumno(eAlumno alumnos[], int tam);
int bajaAlumno (eAlumno alumnos[], int tam);
int modificarAlumno (eAlumno alumnos[], int tam);
eAlumno newAlumno (int legajo, char nombre[], char sexo, int edad, int n1, int n2, eFecha fecha);
int menu ();


int main()
{

    eAlumno lista[TAM];
    char salir = 'n';

    inicializarAlumnos(lista, TAM);

    do
    {
        switch(menu())
        {

        case 1:
            // aca va el alta alumno
            altaAlumno(lista, TAM);
            break;
        case 2:
            // aca va la baja alumno
            bajaAlumno(lista, TAM);
            break;
        case 3:
            // aca va el modificar alumno
            modificarAlumno (lista, TAM);
            break;
        case 4:
            // aca va el alta alumno
            mostrarAlumnos(lista, TAM);
            break;
        case 5:
            // aca va el alta alumno
            printf("Ordenar alumno\n");
            break;
        case 6:
            // aca va el alta alumno
            printf("Informes alumno\n");
            break;
        case 7:
            // aca va el alta alumno
            printf("Confirma salida?\n");
            fflush(stdin);
            salir = getch();
            break;
        default:
            printf("Opcion invalida");
        }
        system("pause");

    }
    while (salir == 'n');


    return 0;
}

void mostrarAlumno(eAlumno x)
{
    printf("  %d  %s  %d  %c  %d %d %.2f %02d/%02d/%d\n",
           x.legajo,
           x.nombre,
           x.edad,
           x.sexo,
           x.nota1,
           x.nota2,
           x.promedio,
           x.fechaIngreso.dia,
           x.fechaIngreso.mes,
           x.fechaIngreso.anio);
}

void mostrarAlumnos(eAlumno vec[], int tam)
{

    int flag = 0;

    printf(" Legajo Nombre Edad Sexo Nota1 Nota2 Promedio FIngreso\n");
    for(int i=0; i < tam; i++)
    {
        if (vec[i].isEmpty == 0)
        {

            mostrarAlumno(vec[i]);
            flag = 1;

        }

    }

    if (flag == 0)
    {

        printf("No hay Alumnos que mostrar");


    }

    printf("\n\n");
}

void ordenarAlumnos(eAlumno vec[], int tam)
{

    eAlumno auxAlumno;

    for(int i= 0; i < tam-1 ; i++)
    {
        for(int j= i+1; j <tam; j++)
        {
            if( vec[i].legajo > vec[j].legajo)
            {
                auxAlumno = vec[i];
                vec[i] = vec[j];
                vec[j] = auxAlumno;
            }
        }
    }
}

int menu ()
{

    int opcion;

    system("cls");
    printf("Menu de Opciones\n\n");
    printf("1-Alta de Alumno\n");
    printf("2-Baja de Alumno\n");
    printf("3-Modificar Alumno\n");
    printf("4-Listar Alumnos\n");
    printf("5-Ordenar Alumnos\n");
    printf("6-Informes\n");
    printf("7-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;

}

void inicializarAlumnos(eAlumno alumnos[], int tam)
{

    for(int i=0; i<tam; i++)
    {
        alumnos[i].isEmpty = 1;

    }
}

int buscarLibre(eAlumno alumnos[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {

        if(alumnos[i].isEmpty==1)
        {

            indice = i;

            break;
        }

    }

    return indice;
}

int buscarAlumno(int legajo, eAlumno alumnos[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {

        if(alumnos[i].isEmpty == 0 && alumnos[i].legajo == legajo)
        {

            indice = i;

            break;
        }
    }
    return indice;

}

int altaAlumno(eAlumno alumnos[], int tam)
{

    int todoOk = 0;
    int indice;
    int esta;
    int legajo;
    int edad;
    int nota1;
    int nota2;
    char sexo;
    char nombre[20];
    eFecha fecha;

    indice = buscarLibre(alumnos, tam);

    if ( indice == -1)
    {

        printf("Sistema completo. No se pueden agregar mas alumnos\n");
        system("pause");
    }
    else
    {

        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        esta = buscarAlumno(legajo, alumnos, tam);

        if (esta != -1)
        {

            printf("Legajo ya registrado\n");
            mostrarAlumno(alumnos[esta]);
            system ("pause");

        }
        else
        {

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nombre);

            printf("Ingrese edad:");
            scanf("%d", &edad);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &sexo);

            printf("Ingrese nota parcial 1: ");
            scanf("%d", &nota1);

            printf("Ingrese nota parcial 2:");
            scanf("%d", &nota2);

            printf("Ingrese fecha ingreso: dd/mm/aaaa ");
            scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

            alumnos[indice] = newAlumno(legajo, nombre, sexo, edad, nota1, nota2, fecha);
            todoOk = 1;

        }

    }

    return todoOk;
}

eAlumno newAlumno (int legajo, char nombre[], char sexo, int edad, int n1, int n2, eFecha fecha)
{

    eAlumno nuevoAlumno;
    nuevoAlumno.legajo = legajo;
    strcpy(nuevoAlumno.nombre, nombre);
    nuevoAlumno.edad = edad;
    nuevoAlumno.sexo = sexo;
    nuevoAlumno.nota1 = n1;
    nuevoAlumno.nota2 = n2;
    nuevoAlumno.promedio = (float) (n1 + n2) /2;
    nuevoAlumno.fechaIngreso = fecha;
    nuevoAlumno.isEmpty = 0;

    return nuevoAlumno;
}

int bajaAlumno (eAlumno alumnos[], int tam)
{

    int todoOk = 0;
    int indice;
    int legajo;
    char confirma;

    system ("cls");

    printf("****Baja Alumno****\n\n");

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarAlumno (legajo, alumnos, tam);

    if (indice == -1)
    {

        printf("\nNo tenemos registrado ese legajo\n");
        system("pause");
    }
    else
    {

        mostrarAlumno(alumnos[indice]);
        printf("\nConfirma eliminacion?: \n");
        fflush(stdin);
        confirma = getche ();

        if(confirma == 's')
        {

            alumnos[indice].isEmpty = 1;
            printf("\nSe ha eliminado el alumno\n");
            todoOk = 1;

        }
        else
        {

            printf("\nSe ha cancelado la baja\n");

        }

        system("pause");

    }

    return todoOk;
}

int modificarAlumno (eAlumno alumnos[], int tam){


    //int todoOk = 0;
    int indice;
    int legajo;
    char confirma;
    int nota;

    system ("cls");

    printf("****Modificar Alumno****\n\n");

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarAlumno (legajo, alumnos, tam);

    if (indice == -1)
    {

        printf("\nNo tenemos registrado ese legajo\n");
        system("pause");
    }
    else
    {

        mostrarAlumno(alumnos[indice]);
        printf("\nQue nota desea modificar (1 o 2)?: \n");
        fflush(stdin);
        confirma = getche ();

        if(confirma == '1')
        {


            printf("\nIngrese nueva nota: \n");
            scanf ("%d", &alumnos[indice].nota);
            alumnos[indice].nota1 = nota;


            //todoOk = 1;

        }
        else if (confirma == '2')
        {

            printf("\nIngrese nueva nota: \n");
            scanf ("%d", &alumnos[indice].nota);
            alumnos[indice].nota2 = nota;
            //todoOk = 1;

        }

        system("pause");

    }

    return todoOk;
}






