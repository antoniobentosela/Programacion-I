#include <stdio.h>
#include <stdlib.h>

typedef struct
{

    int id;
    char nombre[20];
    float sueldo;

} eEmpleado;

int mostrarEmpleado(eEmpleado* e);

int main()
{

    int cant;

    eEmpleado unEmpleado = {12345, "Julia", 25000};

    mostrarEmpleado(&unEmpleado);

    /*FILE* f = fopen("data.bin", "wb");

    if(f == NULL){

        exit(1);

    }

    cant = fwrite(&unEmpleado, sizeof(eEmpleado), 1, f);

    if(cant < 1){

        printf("Problemas para guardar en el archivo");

    }
    else
    {
        printf("Se guardo de manera exitosa");
    }

    fclose(f);
*/
    eEmpleado clonEmpleado;

    FILE* f = fopen("data.bin", "rb");

    if(f == NULL){

        exit(1);

    }

    cant = fread(&clonEmpleado, sizeof(eEmpleado), 1, f);

    if(cant == 1){

        printf("Archivo leido correctamente");

    }else{

        printf("Problemas para leer el archivo");

    }


    return 0;
}

int mostrarEmpleado(eEmpleado* e){

    int todoOk = 0;

    if(e != NULL){

        printf("%d    %s    %.2f\n", e->id, e->nombre, e->sueldo);
        todoOk = 1;

    }

    return todoOk;
}
