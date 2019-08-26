#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    char opcion;
    char seguir = 'n';

    do {

        //limpio la pantalla.
      system ("cls");
        printf ("----Menu de opciones-----\n\n");
        printf ("a- Sumar\n");
        printf ("b- Restar\n");
        printf ("c- Multiplicar\n");
        printf ("d- Dividir\n");
        printf ("e- Salir\n\n");
        printf ("Ingrese opcion: ");
        opcion = getche ();

        switch (opcion){

            case 'a':
                printf ("Usted eligio Sumar\n");
                system ("pause");
                break;

            case 'b':
                printf ("Usted eligio Restar\n");
                system ("pause");
                break;

            case 'c':
                printf ("Usted eligio Multiplicar\n");
                system ("pause");
                break;

            case 'd':
                printf ("Usted eligio Dividir\n");
                system ("pause");
                break;

            case 'e':
                printf ("Usted eligio Salir\n\n");
                printf ("Confirma Salida?");
                seguir = getche ();
                system ("pause");
                break;

            default:
                printf ("opcion invalida\n\n");
                system ("pause");
                break;




        }
    }while (seguir == 'n');
    return 0;
}
