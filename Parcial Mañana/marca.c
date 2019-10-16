#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "marca.h"


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
