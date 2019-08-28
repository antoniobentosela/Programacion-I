#include <stdio.h>
#include <stdlib.h>

char menu (void);

int main()
{

    char seguir = 'n';

    do {

        //limpio la pantalla.


        switch (menu()){

            case 'a':
                printf ("\n\nUsted eligio Sumar\n\n");
                system ("pause");
                break;

            case 'b':
                printf ("\n\nUsted eligio Restar\n\n");
                system ("pause");
                break;

            case 'c':
                printf ("\n\nUsted eligio Multiplicar\n\n");
                system ("pause");
                break;

            case 'd':
                printf ("\n\nUsted eligio Dividir\n\n");
                system ("pause");
                break;

            case 'e':
                printf ("\n\nUsted eligio Salir\n\n");
                printf ("Confirma Salida?: ");
                fflush(stdin);
                seguir = getche ();
                printf("\n\n");
                system ("pause");
                break;

            default:
                printf ("\n\nOpcion invalida\n\n");
                system ("pause");
                break;
        }

    }while (seguir == 'n');

    return 0;
}

char menu (void){

char opcion;

        system ("cls");
        printf ("-----Menu de opciones-----\n\n");
        printf ("a- Sumar\n");
        printf ("b- Restar\n");
        printf ("c- Multiplicar\n");
        printf ("d- Dividir\n");
        printf ("e- Salir\n\n");
        printf ("Ingrese opcion: ");
        fflush (stdin);
        opcion = getche ();

        return opcion;

}

