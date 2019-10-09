#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct{

    int id;
    char descripcion[20];

}eMarca;

#endif // MARCA_H_INCLUDED


void mostrarMarcas(eMarca marca[], int tam);
void mostrarMarca(eMarca marcas);
int cargarDescMarca(int id, eMarca marcas[], int tam, char desc[]);
