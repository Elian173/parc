#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include "funciones.h"



int main()
{
    system("color F0");
    printf("Scarafilo crack\n\n");
    system("pause");

    int salir = 0;

    ArrayList* Plist;
    ArrayList* auxListanegra;
    eClientes* auxCliente;
    Plist = al_newArrayList();
    auxListanegra = al_newArrayList();
    do
    {
        switch (menu())
        {
        case 1:
            parsearArchivo(Plist);
            auxCliente = (eClientes*)Plist->get(Plist,5);
            //printf("%s %s\n",auxCliente->nombre,auxCliente->correo); printf("%d %d",Plist->size,Plist->reservedSize);
            break;
        case 2:
            parsearArchivo(auxListanegra);
            break;
        case 3:
            compararClientes(Plist, auxListanegra);
            break;
        case 4:
            listarClientes(Plist);
            system("pause");
            break;
        case 5:
            salir = 1;
            break;
        default:
            printf("Opcion invalida.\n");
        }
    }
    while (salir == 0);

    return 0;
}

