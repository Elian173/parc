#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include "funciones.h"
#include <string.h>

int menu()
{
    int respuesta;

    system("cls");

    printf("1- Cargar Destinatarios.\n");
    printf("2- Cargar Lista Negra.\n");
    printf("3- Depurar.\n");
    printf("4- Listar\n");
    printf("5- Salir\n");
    printf("Respuesta : ");

    scanf("%d",&respuesta);

    return respuesta;
}

void parsearArchivo (ArrayList* Plist)
{

    FILE* archivo;
    char nomArchivo[200];
    char auxNombre[200];
    char auxCorreo[200];

    eClientes* auxClientes;

    printf("ingrese el nombre del archivo: ");
    fflush(stdin);
    gets(nomArchivo);

    archivo = fopen(nomArchivo,"r");

    if(archivo == NULL)
    {
        printf("\nNo Se Encontro El Archivo.\n");
    }
    else
    {
        while(!feof(archivo)) // mientras no sea el final del archivo.
        {
            fscanf(archivo,"%[^,],%[^\n]",auxNombre,auxCorreo); // lee el nombre y el correo hasta un \n.
            auxClientes =(eClientes*)malloc(sizeof(eClientes)); // reserva espacio en memoria.
            strcpy(auxClientes->nombre,auxNombre); // cargar en la estructura.
            strcpy(auxClientes->correo,auxCorreo);

            Plist->add(Plist,auxClientes); // agrega auxCliente a plist (pasas la direccion de memoria de donde estan los datos).

            // printf("%s %s\n",auxClientes->nombre,auxClientes->correo);
        }

        printf("\nSe Cargo El Archivo Con Exito.\n");
        system("pause");

    }
}

void compararClientes (ArrayList* lista, ArrayList* listaNegra)
{
    int i,j;
    eClientes* cliente;
    eClientes*  clienteNegro;
    ArrayList* nuevalista;

    nuevalista = al_newArrayList();

    for(j=0;j<listaNegra->size;j++)
    {
        clienteNegro = (eClientes*)listaNegra->get(listaNegra,j);

        for(i=0;i<lista->size;i++)
        {
            cliente = (eClientes*) lista->get(lista,i);

            if (strcmp(clienteNegro->correo,cliente->correo) == 0)
            {
                contract(lista, i);
            }
        }
    }
}
void listarClientes(ArrayList * lista)
{
    eClientes* auxCliente;
    int i;

    for(i=0; i<lista->size; i++)
    {
        auxCliente = (eClientes*) lista->get(lista,i);
        printf("%s, %s \n",auxCliente->nombre,auxCliente->correo);
        break;
    }

    getchar();

}
