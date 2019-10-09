#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define TAM 2


typedef struct{

int codigo;
char descripcion[50];
float importe;
int cantidad;
int isEmpty;

}eProducto;

void mostrarProducto(eProducto x);
void mostrarProductos(eProducto vec[], int tam);
void inicializarProductos(eProducto productos[], int tam);
int buscarLibre(eProducto productos[], int tam);
int buscarProducto(int codigo, eProducto productos[], int tam);
int altaProducto(eProducto productos[], int tam);
int bajaProducto(eProducto productos[], int tam);
eProducto newProducto(int codigo, char descripcion[], int cantidad, float importe);
int modificarProducto(eProducto productos[], int tam);
int menu();


int main()
{

    eProducto lista[TAM];
    char salir = 'n';

    inicializarProductos(lista, TAM);

    eProducto x = {2000, "arroz", 335, 100};
    lista[0] = x;

   do
    {
        switch(menu())
        {
        case 1:

            altaProducto(lista, TAM);
            break;
        case 2:
            bajaProducto(lista, TAM);
            break;
        case 3:
            modificarProducto(lista, TAM);
            // aca va modificar alumno
            break;
        case 4:
            mostrarProductos(lista, TAM);
            // aca va el alta alumno
            break;
        case 5:
            //ordenarAlumnos(lista, TAM);
            // aca va el alta alumno
            break;
        case 6:
            printf("Informes\n");
            // aca va el alta alumno
            break;
        case 7:
            printf("Corfirma Salida?");
            fflush(stdin);
            salir = getch();
            // aca va el alta alumno
            break;
        default:
            printf("Opcion invalida\n");
        }
        system("pause");
    }
    while(salir == 'n');

    return 0;
}

void mostrarProducto(eProducto x)
{
    printf("  %d    %s       %d     $%2.f\n",
           x.codigo,
           x.descripcion,
           x.cantidad,
           x.importe
           );
}

void mostrarProductos(eProducto vec[], int tam)
{
    int flag = 0;

    system("cls");
    printf("**** Listado de Productos ****\n\n");

    printf("Codigo Descripcion Cantidad Importe\n");

    for(int i=0; i < tam; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            mostrarProducto(vec[i]);
            flag = 1;

        }
    }

    if( flag == 0)
    {
        system("cls");
        printf("\n---No hay productos que mostrar---");
    }

    printf("\n\n");
}

void inicializarProductos(eProducto productos[], int tam){

    for(int i=0; i < tam; i++)
    {
        productos[i].isEmpty = 1;
    }

}

int buscarLibre(eProducto productos[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( productos[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarProducto(int codigo, eProducto productos[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( productos[i].isEmpty == 0 && productos[i].codigo == codigo)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int altaProducto(eProducto productos[], int tam){

    int todoOk = 0;
    int indice;
    int codigo;
    char descripcion[50];
    float importe;
    int cantidad;
    int esta;

    system("cls");
    printf("**** Alta Producto ****\n\n");

    indice = buscarLibre(productos, tam);

    if( indice == -1)
    {
        printf("Sistema Completo. No se pueden agregar mas productos\n");
        system("pause");
    }
    else
    {
        printf("\nIngrese codigo: ");
        scanf("%d", &codigo);

        esta = buscarProducto(codigo, productos, tam);

        if( esta != -1)
        {
            printf("\nProducto ya registrado\n");
            mostrarProducto(productos[esta]);
            system("pause");
        }
        else
        {
            printf("Ingrese nombre del producto: ");
            fflush(stdin);
            gets(descripcion);

            printf("Ingrese cantidad: ");
            scanf("%d", &cantidad);

            printf("Ingrese importe: ");
            scanf("%f", &importe);

            productos[indice] = newProducto(codigo, descripcion, cantidad, importe);
            todoOk = 1;
        }
    }
    return todoOk;

}

eProducto newProducto(int codigo, char descripcion[], int cantidad, float importe)
{
    eProducto nuevoProducto;

    nuevoProducto.codigo = codigo;
    strcpy(nuevoProducto.descripcion, descripcion);
    nuevoProducto.cantidad = cantidad;
    nuevoProducto.importe = importe;
    nuevoProducto.isEmpty = 0;

    return nuevoProducto;
}

int bajaProducto(eProducto productos[], int tam){

    int todoOk = 0;
    int indice;
    int codigo;
    char confirma;

    system("cls");
    printf("**** Baja Producto ****\n\n");

    printf("Ingrese codigo: ");
    scanf("%d", &codigo);

    indice = buscarProducto(codigo, productos, tam);

    if( indice == -1 )
    {
        printf("\nNo tenemos registrado ese codigo\n");
        system("pause");
    }
    else
    {
        mostrarProducto(productos[indice]);
        printf("\nConfirma eliminacion?: ");
        fflush(stdin);
        confirma = getche();
        if( confirma == 's')
        {
            productos[indice].isEmpty = 1;
            printf("\n\nSe ha eliminado el producto\n");
            todoOk = 1;
        }
        else
        {
            printf("\n\nSe ha cancelado la baja\n");
        }
        system("pause");
    }
    return todoOk;
}


int menu()
{

    int opcion;
    system("cls");
    printf("Menu de Opciones\n\n");
    printf("1- Alta Producto\n");
    printf("2- Baja Producto\n");
    printf("3- Modificar Producto\n");
    printf("4- Listar Productos\n");
    printf("5- Ordenar Productos\n");
    printf("6- Informes\n");
    printf("7- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int modificarProducto(eProducto productos[], int tam)
{

    int todoOk = 0;
    int indice;
    int codigo ;
    int opcion;
    int cantidad;
    char descripcion[50];
    float importe;


    system("cls");
    printf("**** Modificar Producto ****\n\n");

    printf("Ingrese codigo: ");
    scanf("%d", &codigo);

    indice = buscarProducto(codigo, productos, tam);

    if( indice == -1 )
    {
        printf("\nNo tenemos registrado ese codigo\n");
        system("pause");
    }
    else
    {
        mostrarProducto(productos[indice]);

        printf("Modificar\n\n");
        printf("1-Cantidad\n");
        printf("2-Importe\n");
        printf("3-Descripcion\n");

        printf("Ingrese opcion:");
        scanf("%d", &opcion);

        if( opcion == 1)
        {
            printf("Ingrese nueva cantidad: ");
            scanf("%d", &cantidad);
            // falta validar nota
            productos[indice].cantidad = cantidad;
            printf("Se actualizo la cantidad");
            todoOk = 1;
        }
        else if( opcion == 2)
        {
            printf("Ingrese nuevo importe: ");
            scanf("%f", &importe);
             // falta validar nota
            productos[indice].importe = importe;
            printf("Se actualizo el importe");
            todoOk = 1;

        }
        else if (opcion == 3)
        {
            printf("Ingrese nuevo nombre: \n");
            fflush(stdin);
            gets(descripcion);
             // falta validar nota
            strcpy(productos[indice].descripcion,descripcion);
            printf("Se actualizo el nombre");
            todoOk = 1;
        }
        else
        {
            printf("No es una opcion valida\n");
        }

        system("pause");
    }
    return todoOk;
}
