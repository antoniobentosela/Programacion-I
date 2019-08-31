#include <stdio.h>
#include <stdlib.h>

float CargarNumeros (float a, float b);


int main()
{


    float a;
    float b;
    float resultado;
    char seguir = 'n';
    char opcion;


    do{

        system ("cls");
        printf ("-----Calculadora-----\n\n");
        printf ("1- Ingresar operandos \n");
        printf ("2- Calcular todas las operaciones\n");
        printf ("3- Salir\n");




        switch (opcion){

        case '1':

        CargarNumeros (a , b);

        break;

        }






} while (seguir == 'n');















    return 0;
}


float CargarNumeros (float a, float b){



printf ("Ingrese un numero: \n");
scanf ("%f", &a);
printf ("Ingrese otro numero: \n");
scanf ("%f", &b);


}
