#include <stdio.h>
#include <stdlib.h>

float CargarNumeros (float a, float b);
float CalcularSuma (float a, float b);
float CalcularResta (float a, float b);
float CalcularMultiplicacion (float a, float b);
float CalcularDivision (float a, float b, float* resultado);
float CargarNumeros (float a, float b);
float CalcularTodos (float a, float b,float* resultadoSuma,
                     float *resultadoResta, float* resultadoMultiplicacion,float* resultadoDivision,float*exitoEnDivision);
float MostrarResultados (float resultadoSuma, float resultadoResta, float resultadoMultiplicacion, float resultadoDivision, float exitoEnDivision);



int main()
{


    float a;
    float b;
    //float resultado;
    char seguir = 'n';
    char opcion;
    float resultadoSuma;
    float resultadoDivision;
    float resultadoResta;
    float resultadoMultiplicacion;
    //float resultadoFact;
    float exitoEnDivision;

    do
    {

        system ("cls");
        printf ("-----Calculadora-----\n\n");
        printf ("1- Ingresar operandos \n");
        printf ("2- Calcular todas las operaciones\n");
        printf ("3- Salir\n");
        printf ("Ingrese una opcion: \n");
        opcion = getche ();
        fflush (stdin);




        switch (opcion)
        {

        case '1':

            CargarNumeros (a, b);
            break;

        case '2':
            CalcularTodos(a,b,&resultadoSuma,&resultadoResta,&resultadoDivision,&resultadoMultiplicacion,&exitoEnDivision);



                     break;
        case '3':

            MostrarResultados(resultadoSuma,  resultadoResta,  resultadoMultiplicacion,  resultadoDivision,  exitoEnDivision);

            break;





    }
    }while (seguir == 'n');















    return 0;
}


float CargarNumeros (float a, float b)
{



    printf ("\nIngrese un numero: \n");
    scanf ("%f", &a);
    printf ("\nIngrese otro numero: \n");
    scanf ("%f", &b);

    return ( a , b);
}

float CalcularSuma (float a, float b)
{

    float resultado;

    resultado = a + b;

    return resultado;

}

float CalcularResta (float a, float b)
{

    float resultado;

    resultado = a - b;

    return resultado;

}

float CalcularMultiplicacion (float a, float b)
{

    float resultado;

    resultado = a * b;

    return resultado;

}

float CalcularDivision (float a, float b, float* resultado)
{
    float retorno =0;


    if(b != 0)
    {
        *resultado = a / b;
        retorno = 1;
    }



}


float CalcularTodos (float a, float b,float* resultadoSuma,
                     float *resultadoResta, float* resultadoMultiplicacion,float* resultadoDivision,float*exitoEnDivision)
{
    *resultadoSuma = CalcularSuma(a,b);
    *resultadoResta = CalcularResta(a,b);
    *resultadoMultiplicacion = CalcularMultiplicacion(a,b);
    *exitoEnDivision= CalcularDivision(a,b,resultadoDivision);







}

float MostrarResultados (float resultadoSuma, float resultadoResta, float resultadoMultiplicacion, float resultadoDivision, float exitoEnDivision){


    printf ("La suma es: %f", &resultadoSuma);
    printf ("La suma es: %f", &resultadoResta);
    printf ("La suma es: %f", &resultadoMultiplicacion);

 if(exitoEnDivision==1)
            {
                printf("Division es %f",resultadoDivision);
    } else {

        printf ("Error, no se puede dividir por 0");

    }
}

