#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "carrera.h"
#include "alumno.h"
#include "comida.h"
#include "almuerzo.h"

#define TAM 10
#define TAMC 3
#define TAMCOM 5
#define TAMAL 20

//Informes
int menu();
int menuInformes();
void InformesAlumnos(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC, eAlmuerzo almuerzos[], int tamal, eComida comidas[], int tamcom);
void mostrarAlumnosXCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
void mostrarAlumnosCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC, int idCarrera);
void mostrarAlumnosDeUnaCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
void mostrarCantidadAlumnosXCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
int cantidadAlumnosCarrera(eAlumno alumnos[], int tam, int idCarrera);
void mejoresPromediosXCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
void mostrarAlmuerzosFecha(eAlmuerzo almuerzos[], int tAlmuerzo, eComida comidas[], int tComida);
int cantidadAlmuerzosCarrera(int idCarrera, eAlumno alumnos [], int tAlumno, eAlmuerzo almuerzos[], int tAlmuerzo);
int informarAlmuerzosXCarrera(eCarrera carreras[], int tCarrera, eAlumno alumnos [], int tAlumno, eAlmuerzo almuerzos[], int tAlmuerzo);
void totalDeudaAlumno(eAlumno alumnos [], int tAlumno,  eAlmuerzo almuerzos[], int tAlmuerzo, eComida comidas[], int tComida, eCarrera carreras[], int tCarrera);
int compararFecha(eFecha f1, eFecha f2);

int main()
{
    int legajo = 20000;
    int idAlmuerzo = 60000;
    eCarrera carreras[TAMC] = {{1000,"TUP"},{1001,"TUSI"},{1002,"LIC"}};
    eComida comidas[TAMCOM] = {{5000,"Bife", 250},{5001,"Fideos", 180},{5002,"Pizza", 200},{5003,"Arroz", 160},{5004,"Milanesa", 220}};
    eAlumno lista[TAM];
    eAlmuerzo almuerzos[TAMAL];
    char salir = 'n';

    inicializarAlmuerzos(almuerzos, TAMAL);
    inicializarAlumnos(lista, TAM);

    legajo = legajo + hardcodearAlumnos(lista, TAM, 9);
    idAlmuerzo = idAlmuerzo + hardcodearAlmuerzos(almuerzos, TAMAL, 10);

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
            InformesAlumnos(lista, TAM, carreras, TAMC, almuerzos, TAMAL, comidas, TAMCOM);
            break;

        case 7:
            mostrarCarreras(carreras, TAMC);
            break;

        case 8:
            mostrarComidas(comidas, TAMCOM);
            break;

        case 9:
            mostrarAlmuerzos(almuerzos, TAMAL, comidas, TAMCOM);
            break;

        case 10:
            if(altaAlmuerzo(almuerzos, TAMAL, idAlmuerzo, lista, TAM, comidas, TAMCOM, carreras, TAMC))
            {
                idAlmuerzo++;
            }
            break;

        case 11:
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
    printf("8-Mostrar Comidas\n");
    printf("9-Mostrar Almuerzos\n");
    printf("10-Alta Almuerzo\n");
    printf("11-Salir\n\n");
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
    printf("4-Mostrar La Carrera con mas incriptos\n");
    printf("5-Mostrar Mejor Promedio por Carrera\n");
    printf("6-Mostrar Alumnos Varones\n");
    printf("7-Mostrar Mujeres de Alguna Carrera\n");
    printf("8-Mostrar Alumnos mayores a 30 de Licenciatura\n");
    printf("9-Mostrar Almuerzos de una fecha determinada\n");
    printf("10-Listar Alumnos que comieron una determinada comida\n");
    printf("11-Listar Cantidad de Almuerzos por Carrera\n");
    printf("12-Carrera amante de las milanesas\n");
    printf("13-Informe Deuda de Alumno Seleccionado\n");
    printf("14-Recaudacion x venta comida seleccionada\n");
    printf("20-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

void InformesAlumnos(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC, eAlmuerzo almuerzos[], int tAlmuerzos, eComida comidas[], int tComidas)
{
    char salir = 'n';
    system("cls");
    printf("***** Informes Alumnos ****\n\n");

    do
    {
        switch( menuInformes())
        {
        case 1:
            mostrarAlumnosDeUnaCarrera(alumnos, tam, carreras, tamC);
            break;

        case 2:
            mostrarAlumnosXCarrera(alumnos, tam, carreras, tamC);
            break;

        case 3:
            mostrarCantidadAlumnosXCarrera(alumnos, tam, carreras, tamC);
            break;

        case 4:
            //carreraMasCursada(alumnos, tam, carreras, tamC);
            break;

        case 5:
            //mejoresPromediosXCarrera(alumnos, tam, carreras, tamC);
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
            mostrarAlmuerzosFecha(almuerzos, TAMAL, comidas, TAMCOM);
            break;

        case 10:
            mostrarAlmuerzosFecha(almuerzos, tAlmuerzos, comidas, tComidas);
            break;

        case 11:
            informarAlmuerzosXCarrera(carreras, tamC, alumnos, tam, almuerzos, tAlmuerzos);
            break;
        case 12:
            totalDeudaAlumno(alumnos, tam, almuerzos, tAlmuerzos, comidas, TAMCOM, carreras, TAMC);
            break;
        case 14:

            break;
        case 20:
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

void mostrarAlumnosDeUnaCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC)
{
    // aca mostramos carreras y obtenemos el idCarrera
    // y llamamos a mostrarAlumnosCarrera
    int idCarrera;
    system("cls");
    printf("***Carreras***\n\n");
    mostrarCarreras(carreras, tamC);
    printf("Ingrese id carrera: ");
    scanf("%d", &idCarrera);
    mostrarAlumnosCarrera(alumnos, tam, carreras, tamC, idCarrera);

}

void mostrarAlumnosCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC, int idCarrera)
{

    char desc[20];
    int flag = 0;
    cargarDescCarrera(idCarrera, carreras, 20,desc);

    printf("Carrera: %s\n\n", desc);

    for(int i=0; i < tam; i++)
    {
        if( alumnos[i].isEmpty == 0 && alumnos[i].idCarrera == idCarrera)
        {
            mostrarAlumno(alumnos[i], carreras, tamC);
            flag = 1;
        }
    }
    if( flag == 0)
    {
        printf("No hay Alumnos cursando %s", desc);
    }
    printf("\n\n");
}

void mostrarAlumnosXCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC)
{

    system("cls");
    printf("***Listado de Alumnos por Carrera***\n\n");

    for(int i=0; i < tamC; i++)
    {
        mostrarAlumnosCarrera(alumnos, tam, carreras, tamC, carreras[i].id);
    }

    printf("\n\n");
}

void mostrarCantidadAlumnosXCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC)
{

    int contador = 0;
    char desc[20];

    system("cls");
    printf("***Cantidad de Alumnos por Carrera***\n\n");

    // Recorro vector de carreras
    for(int i=0; i < tamC; i++)
    {
        cargarDescCarrera(carreras[i].id, carreras, tamC,desc);
        printf("Carrera: %s\n\n", desc);

        for(int j= 0; j < tam; j++)
        {
            if( alumnos[j].isEmpty == 0 && alumnos[j].idCarrera == carreras[i].id)
            {
                contador++;
            }
        }
        printf("Cantidad: %d\n\n", contador);
        contador = 0;
    }
    printf("\n\n");
}

int cantidadAlumnosCarrera(eAlumno alumnos[], int tam,int idCarrera)
{
    int cant = 0;

    for(int i= 0; i < tam; i++ )
    {
        if(alumnos[i].isEmpty == 0 && alumnos[i].idCarrera == idCarrera)
        {
            cant++;
        }
    }
    return cant;
}

void carreraMasCursada(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC)
{
    int cantidades[tamC];
    int mayor;
    int flag = 0;
    char desc[20];

    for( int i=0; i < tamC; i++)
    {
        cantidades[i] = cantidadAlumnosCarrera(alumnos, tam, carreras[i].id);
    }

    for(int i=0; i < tamC; i++)
    {
        if( mayor < cantidades[i] || flag==0)
        {
            mayor = cantidades[i];
            flag = 1;
        }
    }

    for(int i=0; i < tamC; i++)
    {
        if( cantidades[i]== mayor)
        {

            cargarDescCarrera( carreras[i].id, carreras, tamC, desc);
            printf("Carrera: %s %d alumnos\n", desc, mayor);
        }
    }
}

void mejoresPromediosXCarrera(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC)
{

    char desc[20];
    float mayor;
    int flag = 0;
    system("cls");
    printf("***Mejores Promedios por Carrera***\n\n");

    for( int i=0; i < tamC; i++)
    {
        cargarDescCarrera(carreras[i].id, carreras, tamC,desc);
        printf("Carrera: %s\n\n", desc);

        for(int j=0; j < tam; j++)
        {
            if( ((mayor < alumnos[j].promedio && alumnos[j].isEmpty == 0) && alumnos[j].idCarrera == carreras[i].id) || ( flag == 0  && alumnos[j].idCarrera == carreras[i].id))
            {
                mayor = alumnos[j].promedio;
                flag = 1;
            }
        }

        printf("Promedio: %.2f\n\n", mayor);
        mayor = 0;
        flag = 0;
    }
}

void mostrarAlmuerzosFecha(eAlmuerzo almuerzos[], int tAlmuerzos, eComida comidas[], int tComidas)
{
    eFecha fecha;
    int flag = 0;

    printf("Ingrese fecha: ");
    scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

    for(int i = 0; i < tAlmuerzos; i++)
    {
        if(almuerzos[i].isEmpty == 0 && compararFecha(fecha, almuerzos[i].fecha) == 1)
        {
            mostrarAlmuerzo(almuerzos[i], comidas, tComidas);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("No se encontrar almuerzos en la fecha indicada\n");
    }
}

int compararFecha(eFecha f1, eFecha f2)
{
    int sonIguales = 0;
    if(f1.dia == f2.dia && f1.mes == f2.mes && f1.anio == f2.anio)
    {
        sonIguales = 1;
    }

    return sonIguales;
}

int cantidadAlmuerzosCarrera(int idCarrera, eAlumno alumnos [], int tAlumno, eAlmuerzo almuerzos[], int tAlmuerzo)
{

    int cantidad = 0;

    for(int i=0; i < tAlumno; i++)
    {

        if(alumnos[i].idCarrera == idCarrera && alumnos[i].isEmpty == 0)
        {
            for(int j= 0; j < tAlmuerzo; j++)
            {

                if(almuerzos[j].legajo == alumnos[i].legajo && almuerzos[j].isEmpty == 0)
                {

                    cantidad ++;

                }
            }
        }
    }

    return cantidad;

}

int informarAlmuerzosXCarrera(eCarrera carreras[], int tCarrera, eAlumno alumnos [], int tAlumno, eAlmuerzo almuerzos[], int tAlmuerzo)
{

    int cantidad;

    system("cls");
    printf("---Cantidad de almuerzos por carrera---\n\n");

    for(int i =0; i < tCarrera; i++)
    {

        cantidad = cantidadAlmuerzosCarrera(carreras[i].id, alumnos, tAlumno, almuerzos, tAlmuerzo);
        printf("%s: %d", carreras[i].descripcion, cantidad);
        printf ("\n\n");

    }

    return cantidad;
}

void totalDeudaAlumno(eAlumno alumnos [], int tAlumno,  eAlmuerzo almuerzos[], int tAlmuerzo, eComida comidas[], int tComida, eCarrera carreras[], int tCarrera)
{
    float deuda = 0;
    system ("cls");
    int aux;

    mostrarAlumnos(alumnos, tAlumno, carreras, tCarrera);
    printf("Seleccione legajo alumno: ");
    scanf("%d", &aux);

        for (int i = 0; i < tAlmuerzo; i++)
        {
            if(almuerzos[i].legajo == aux && almuerzos[i].isEmpty == 0)
            {

                for (int k = 0; k < tComida; k++)
                {
                    if(almuerzos[i].idComida == comidas[k].id)
                    {

                        deuda += comidas[k].precio;
                    }
                }
            }
        }

        printf("\n\nLa deuda de este alumno es: $%2.f\n\n ", deuda);

}

void recaudacionVentaComida (eAlmuerzo almuerzos[], int tAlmuerzo, eComida comidas[], int tComidas){

int recaudacion = 0;
int aux;

system ("cls");

    mostrarComida(comidas, tComidas);
    printf("Seleccione comida: ");
    scanf("%d", &aux)

        for(int i = 0; i < tAlmuerzos; i++){



        }


}
