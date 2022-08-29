/*
Equipo 5: actividad 2

Desarrollar un programa utilizando listas simplemente enlazadas
donde se pueda insertar elementos solo al final de la lista, 
eliminar elementos de cualquier parte de la lista y mostrar la 
lista en pantalla, (4 opciones de menú, insertar, eliminar, 
mostrar y salir). El nodo debe contener matricula, nombre del alumno 
y promedio general.
*/

// Incluimos la libreria y utilizamos la abreviacion.
#include <iostream>
using namespace std;

// Declaramos las constantes que limitaran el tamaño de los nombres y matriculas.
const int max_char = 50;
const int max_int = 6;

// Declaramos la estructura del nodo.
struct nodo
{
    long int matricula;
    char nombre[max_char];
    float promedio;
};

// Declaramos las funciones prototipo.
void despliega_lista();
void insertar_elemento();
void eliminar_elemento();

// Funcion principal del programa
int main()
{
    // Variable que almacena la opcion ingresada del usuario.
    int opcion_ingresada;
    // Almacena el estado de la funcion. 
    bool salir = false;

    // Menu de opciones.
    do
    {
        // Limpia la terminal.
        // system("cls");

        cout << "\n\n\t\t\tMenu de Opciones" << endl;
        cout << "\t\t\t----------------" << endl;
        cout << "\n   1. Insertar elementos al final de la lista.\n";
        cout << "\n   2. Eliminar elementos en cualquier parte de la lista.\n";
        cout << "\n   3. Desplegar lista en pantalla.\n";
        cout << "\n   4. Salir.\n";
        cout << "\n\tIngrese una opcion: (1-4): ";

        cin >> opcion_ingresada;

        // Este switch compara la opcion ingresada con las disponibles.
        switch(opcion_ingresada)
        {
            case 1:
                insertar_elemento();
                break;
            case 2:
                eliminar_elemento();
                break;
            case 3:
                despliega_lista();
                break;
            case 4:
                salir = true;
                break;
            default:
                cout << "\n\tIngrese una opcion valida: ";
        }

    // Mientras salir sea falso, el menu se seguira desplegando
    } while(salir == false);
    
    return 0;
}

void despliega_lista()
{
    cout << "test";
}

void insertar_elemento()
{
    cout << "test";
}

void eliminar_elemento()
{
    cout << "test";
}