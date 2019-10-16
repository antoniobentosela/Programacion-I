#include "marca.h"
#include "color.h"

#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED


typedef struct
{
    int id;
    int patente;
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;
} eAuto;


#endif // AUTO_H_INCLUDED

void mostrarAuto(eAuto x, int tam, eMarca marcas[], int tamM, eColor colores[], int tamC);
void mostrarAutos(eAuto vec[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC);
void ordenarAutos(eAuto vec[], int tam);
void inicializarAutos(eAuto vec[], int tam);
int buscarLibre(eAuto vec[], int tam);
int buscarAlumno(int id, eAuto vec[], int tam);
int altaAuto(eAuto vec[], int tam, int id, eMarca marcas[], int tamM, eColor colores[], int tamC);
eAuto newAuto(int id,int patente,int modelo,int idMarca, int idColor);
/*int bajaAlumno(eAlumno vec[], int tam, eCarrera carreras[], int tamC);
int ModificarAlumno(eAlumno vec[], int tam, eCarrera carreras[], int tamC);
int hardcodearAlumnos( eAlumno vec[], int tam, int cantidad);*/
