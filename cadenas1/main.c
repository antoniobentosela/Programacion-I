#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   char nombre [10];
   char auxCad[100];

   printf("Ingrese nombre: ");
   gets(auxCad);

   while(strlen(auxCad) > 9){ //strlen calcula el largo del nombre.
    printf("Error. Nombre demasiado largo. Reingresar nombre: ");
    gets(auxCad);
   }

   /*strncpy(nombre, auxCad, 9) esto restringe los espacios y solo muestra lo que entra en 9 espacios.
   Pero no puedo hacer que el usuario reescriba el nombre, se guarda lo que entra.*/

   strcpy(nombre, auxCad); //asigna el valor de auxcad a nombre. Como si fuera un =.

   printf("%s\n", nombre);

    char n1[10] = "juan";
    char n2[10] = "juan";
    int x;

    x = strcmp(n1, n2); /*compara cadenas, Si son iguales devuelve 0.
                            si el n1 esta antes que n2 devuelve -1. Si es al reves devuelve 1.*/

    printf("%d\n", x);

    x = stricmp(n1,n2); //compara las dos cadenas. Pero no le da importancia a las mayusculas y minusculas.

    strupr(n1); // transforma minusculas a mayusculas
    strlwr(n2); // transforma mayuscula a minusculas

    strcat(n1, n2); //concatena cadenas.

    n2[0] = toupper(n2[0]); // cambia el primer caracter de la cadena, de minuscula a mayuscula.

    return 0;
}
