
typedef struct
{
    char nombre[50];
    char correo [50];

}eClientes;

int menu ();
void parsearArchivo (ArrayList* Plist);
void compararClientes (ArrayList* Plist, ArrayList* auxListanegra);
void listarClientes(ArrayList * lista);
