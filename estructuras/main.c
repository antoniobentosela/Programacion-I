#include <stdio.h>
#include <stdlib.h>

typedef struct {

    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct {

char nombre[20];
char sexo;
int edad;
int nota1;
int nota2;
int legajo;
float promedio;
eFecha fechaDeIngreso;

}eAlumno;

int main()
{

    eAlumno alumno1 = {"Antonio",'m', 22, 4, 6, 123, 5, {12, 7, 1997}};
    /*eAlumno alumno1;

    printf ("Ingrese nombre: ");
    gets(alumno1.nombre);

    printf ("Ingrese legajo: ");
    scanf("%d", &alumno1.legajo);

    printf ("Ingrese edad: ");
    scanf("%d", &alumno1.edad);

    printf ("Ingrese sexo: ");
    fflush(stdin);
    scanf("%c", &alumno1.sexo);

     printf ("Ingrese nota parcial 1: ");
    scanf("%d", &alumno1.nota1);

     printf ("Ingrese nota parcial 2: ");
    scanf("%d", &alumno1.nota2);

    printf("Ingrese dia de ingreso: ");
    scanf("%d", &alumno1.fechaDeIngreso.dia);

    printf("Ingrese mes de ingreso: ");
    scanf("%d", &alumno1.fechaDeIngreso.mes);

    printf("Ingrese anio de ingreso: ");
    scanf("%d", &alumno1.fechaDeIngreso.anio);

    alumno1.promedio = (float) (alumno1.nota1 + alumno1.nota2) / 2;

    */

    printf("Nombre: %s\nLegajo: %d\nEdad: %d\nSexo: %c\nNota1: %d\nNota2: %d\nPromedio: %2.f\nFecha de Ingreso: %02d/%02d/%d",
           alumno1.nombre,
           alumno1.legajo,
           alumno1.edad,
           alumno1.sexo,
           alumno1.nota1,
           alumno1.nota2,
           alumno1.promedio,
           alumno1.fechaDeIngreso.dia,
           alumno1.fechaDeIngreso.mes,
           alumno1.fechaDeIngreso.anio
           );

    return 0;
}
