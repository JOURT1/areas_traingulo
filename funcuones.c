#include <stdio.h>
#include "funciones.h"

int ingreseCedula(){
    int cedula;
    printf("Ingrese la cedula del contacto: ");
    scanf("%d",&cedula);
    return cedula;
}

int obtenerPosicionContacto(int cedula[5],int cedulaBuscar){
    int indice=0;
    for (int i = 0; i < 5; i++)
    {
        if (cedula[i]==cedulaBuscar)
        {
            indice=i;
        }
        
    }
    return indice;
}

void imprimirContactos(char nombre[5][50],int telefonos[10][2],int indice){
    printf("Los telefonos asociados a %s\n",nombre[indice]);
    for (int i = 0; i < 10; i++)
    {
        if (telefonos[i][0]==indice)
        {
            printf("%d\n",telefonos[i][1]);
        }
    }
}

void imprimirDirecciones(char direcciones[10][2][50],int indice){

    for (int i = 0; i < 10; i++)
    {
        if (direcciones[i][0][0] - '0' ==indice)
        {
            printf("%s\n",direcciones[i][1]);
        }
    }
}