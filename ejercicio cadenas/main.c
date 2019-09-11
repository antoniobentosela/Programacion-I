#include <stdio.h>
#include <stdlib.h>
#include <string.h> //funciones str, de cadenas
#include <ctype.h> //funciones de caracter (toupper, lower)

/* se debe mostrar Apellido, Nombre, sin importar como lo ingrese el
usuario (minusculas, mayusculas) y no se pueden tocar los vectores nombre y apellido.*/

int main()
{
    char nombre[20];
    char apellido [20];
    char nombreCompleto [41];
    char auxCad [100];
    int i=0;

    printf ("Ingrese nombre: ");
    fflush(stdin);
    gets (auxCad);

    while(strlen(auxCad) > 19){ //strlen calcula el largo del nombre.
    printf("Error. Nombre demasiado largo. Reingresar nombre: ");
    fflush(stdin);
    gets(auxCad);
   }

   strcpy(nombre, auxCad);

    //strncpy(nombre, auxCad, 19);

    printf ("Ingrese apellido: ");
    fflush(stdin);
    gets (auxCad);

    while(strlen(auxCad) > 19){ //strlen calcula el largo del nombre.
    printf("Error. Nombre demasiado largo. Reingresar nombre: ");
    fflush(stdin);
    gets(auxCad);
   }

    strcpy(apellido, auxCad);

    strcpy(nombreCompleto, apellido);
    strcat(nombreCompleto, ", ");
    strcat(nombreCompleto, nombre);

    strlwr (nombreCompleto);
    nombreCompleto [0] = toupper(apellido[0]);

    while(nombreCompleto[i] != '\0'){

        if (nombreCompleto[i] == ' '){

            nombreCompleto[i+1] = toupper(nombreCompleto[i+1]);
        }
        i++;
    }

    printf("%s", nombreCompleto);

    return 0;
}
