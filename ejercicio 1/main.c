#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int nota;
    int notaMax;
    int notaMin;
    int flag = 0;
    int contMujeres = 0;
    int contador = 0;
    int acumuladorNotas = 0;
    int acumuladorNotasM = 0;
    char nombre [20];
    char nombreMax [20];
    char nombreMin [20];
    char sexo;
    char sexoMax;
    char sexoMin;
    char seguir;
    float promedioNotas;
    float promedioNotasM = 0;



    do {

        printf ("\nIngrese un nombre: ");
        fflush (stdin);
        gets (nombre);

        printf ("\nIngrese el sexo f/m: ");
        fflush (stdin);
        scanf ("%c", &sexo);

        while (sexo != 'f' && sexo != 'm'){

            printf ("\nError.Ingrese el sexo f/m: ");
            fflush (stdin);
            scanf ("%c", &sexo);

        }

        printf ("\nIngrese la nota 0-10: ");
        scanf ("%d", &nota);

        while (nota < 0 || nota > 10){

            printf ("\nError.Ingrese la nota 0-10: ");
            scanf ("%d", &nota);
        }

        //necesito esto para calcular el promedio total.
        acumuladorNotas += nota;
        contador ++;

        //necesito esto para calcular el promedio de mujeres.

        if (sexo == 'f'){

            acumuladorNotasM += nota;
            contMujeres ++;
        }


        if (nota > notaMax || flag == 0){

            notaMax = nota;
            sexoMax = sexo;
            strcpy (nombreMax, nombre);

        }

        if (nota < notaMin || flag == 0){

            notaMin = nota;
            sexoMin = sexo;
            strcpy (nombreMin, nombre);
            flag = 1;

        }









        printf ("\nQuiere continuar?: ");
        fflush (stdin);
        //scanf("%c", &seguir);
        seguir = getche ();

    } while (seguir == 's');

    // el float es para que el programa tome tambien numeros con coma.
    promedioNotas = (float) acumuladorNotas / contador;

    if (contMujeres != 0){
    promedioNotasM = acumuladorNotasM / contMujeres;
    }

    printf("promedio de notas %.2f\n", promedioNotas);
    printf ("promedio notas mujeres %.2f\n", promedioNotasM);
    printf ("Mayor nota: nombre: %s sexo: %c  nota: %d\n",nombreMax,sexoMax,notaMax);
    printf ("Menor nota: nombre: %s sexo: %c  nota: %d\n",nombreMin,sexoMin,notaMin);


    return 0;
}
