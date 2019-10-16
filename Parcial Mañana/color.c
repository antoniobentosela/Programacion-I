#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "color.h"


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
