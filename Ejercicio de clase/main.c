#include <stdio.h>
#include <stdlib.h>

int main()
{
    char sexos [5];

    for (int i = 0 ; i < 5 ; i ++){

        printf ("Ingrese sexo: ");
        fflush(stdin);
        scanf ("%c", sexos[i]);

        while (sexos != 'f' && sexos != 'm'){

            printf ("Error. Ingrese un sexo entre f y m: ");
            fflush(stdin);
            scanf ("%c", sexos[i]);

        }
    }

    printf ("el contenido del array es %c: ",




    return 0;
}
