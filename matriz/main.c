#include <stdio.h>
#include <stdlib.h>

void mostrarNombres(char mat[][20], int tam); //la fila se deja vacia

int main()
{
    char nombres[5][20];

    for(int i=0; i < 5; i++){

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(nombres[i]);

    }

 mostrarNombres(nombres[][20], 5);

    printf("\n\n");


    return 0;
}

mostrarNombres(char mat[][20], int tam){

    for(int i=0; i < tam; i++){

    printf("%s\n", mat[i]);

    }

}
