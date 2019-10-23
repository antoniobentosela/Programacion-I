#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

    int dia;
    int mes;
    int anio;

}eFecha;


typedef struct{

    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    eFecha fIngreso;

}eEmpleado;

eEmpleado* newEmpleado();
int mostrarEmpleado(eEmpleado* emp);
eEmpleado* newEmpleadoParam(int leg, char* nombre, char sexo, float sueldo, int dia, int mes, int anio);
int agregarEmpleado(eEmpleado* vec, int* tam, eEmpleado* emp);
int mostrarEmpleados(eEmpleado* vec, int tam);


int main()
{
    eEmpleado* pEmp;


    eEmpleado* lista = (eEmpleado*) malloc(sizeof(eEmpleado));

    int tam = 0;

    if( lista == NULL){

        printf("No se pudo conseguir lugar\n");
        exit(EXIT_FAILURE);

    }

    // Creo un nuevo empleado hardcodeado

    pEmp = newEmpleadoParam(1234, "Jorge", 'm', 25000, 12, 5, 2010);
    eEmpleado* pEmp1 = newEmpleadoParam(1234, "Juana", 'f', 25000, 12, 5, 2010);
    eEmpleado* pEmp2 = newEmpleadoParam(1234, "Marcos", 'm', 25000, 12, 5, 2010);
    eEmpleado* pEmp3 = newEmpleadoParam(1234, "Lucia", 'f', 25000, 12, 5, 2010);
    eEmpleado* pEmp4 = newEmpleadoParam(1234, "Marcelo", 'm', 25000, 12, 5, 2010);

    // Agrego el empleado a la lista

    //*(lista + tam) = *pEmp;

    if(agregarEmpleado(lista, &tam, pEmp)){

        printf("Empleado agregado con Exito\n");


    }
    else{

        printf("No se pudo agregar el empleado\n");

    }

    agregarEmpleado(lista, &tam, pEmp1);
    agregarEmpleado(lista, &tam, pEmp2);
    agregarEmpleado(lista, &tam, pEmp3);
    agregarEmpleado(lista, &tam, pEmp4);
    printf("%d", tam);

    mostrarEmpleados(lista, tam);


    //pEmp = newEmpleado();



    //mostrarEmpleado(pEmp);

    free(pEmp);

    return 0;
}

eEmpleado* newEmpleado(){

    eEmpleado* p;

    p = (eEmpleado*) malloc (sizeof(eEmpleado));

    if(p != NULL){

            p->legajo=0;
            strcpy(p->nombre, "sin definir");
            p->sexo= 'm';
            p->sueldo = 0;
            p->fIngreso = (eFecha) {1,1,1990};
    }

    return p;

}

int mostrarEmpleado(eEmpleado* emp){

    int todoOk = 0;

    if(emp!= NULL){

      printf("%d  %s   %c   %.2f   %02d/%02d/%d\n", emp->legajo, emp->nombre, emp->sexo, emp->sueldo, emp->fIngreso.dia, emp->fIngreso.mes, emp->fIngreso.anio);
      todoOk = 1;
    }

    return todoOk;

}

eEmpleado* newEmpleadoParam(int leg, char* nombre, char sexo, float sueldo, int dia, int mes, int anio){

    eEmpleado* nuevoEmpleado;

    nuevoEmpleado = newEmpleado();

    if(nuevoEmpleado != NULL){

        nuevoEmpleado->legajo = leg;
        strcpy(nuevoEmpleado->nombre, nombre);
        nuevoEmpleado->sexo= sexo;
        nuevoEmpleado->sueldo = sueldo;
        nuevoEmpleado->fIngreso.dia = dia;
        nuevoEmpleado->fIngreso.mes = mes;
        nuevoEmpleado->fIngreso.anio = anio;

    }

    return nuevoEmpleado;

}

int agregarEmpleado(eEmpleado* vec, int* tam, eEmpleado* emp){

    int todoOk = 0;

    eEmpleado* aux;

    if(vec != NULL && emp != NULL && tam != NULL){

        *(vec + (*tam)) = *emp;
        aux = (eEmpleado*) realloc(vec, sizeof(eEmpleado)* (*tam+1));

        if(aux != NULL){

            *vec = *aux;
            *tam = *tam + 1;
            todoOk = 1;

        }

    }



    return todoOk;
}

int mostrarEmpleados(eEmpleado* vec, int tam){

    int todoOk = 0;

    if(vec != NULL){

        for(int i=0; i<tam; i++){

            mostrarEmpleado(vec + i);

        }
        todoOk = 1;
    }

    return todoOk;

}
