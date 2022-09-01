/*
Actividad 2

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
struct Nodo
{
    long int matricula;
    char nombre[max_char];
    float promedio;
    Nodo* siguiente; 
};

void mostrar_menu()
{
    cout << "\n\n\t\t\tMenu de Opciones" << endl;
    cout << "\t\t\t----------------" << endl;
    cout << "\n   1. Insertar elementos al final de la lista.\n";
    cout << "\n   2. Eliminar elementos en cualquier parte de la lista.\n";
    cout << "\n   3. Desplegar lista en pantalla.\n";
    cout << "\n   4. Salir.\n";
    cout << "\n\tIngrese una opcion: (1-4): ";
}

void despliega_lista(Nodo* apuntador)
{
    int contador = 1;

    while (apuntador != NULL)
    {
        cout<<"\n\tDatos del alumno ["<<contador<<"] ";
        cout<<"\n\t------------------------";
        cout<<"\n\n\tMatricula: " << apuntador-> matricula << endl;
        cout<<"\tNombre: " << apuntador -> nombre << endl;
        cout<<"\tPromedio: " << apuntador -> promedio << endl;

        apuntador = apuntador -> siguiente;
        contador++;
    }
}

void insertar_elemento(Nodo** cabecera)
{
    // 1. Creamos un nuevo nodo.
    Nodo* nuevo_nodo = new Nodo();

    // Puntero temporal.
    Nodo* temporal = *cabecera;
    
    // 2. Asignamos informacion dentro del nodo.
    // El usuario ingresa la informacion.
    cout << "Ingrese la matricula del alumno:" << endl;
    cin.ignore(); cin >> nuevo_nodo -> matricula;
    cout << "Ingrese el nombre del alumno:" << endl;
    cin.ignore(); cin.getline(nuevo_nodo -> nombre, max_char); 
    cout << "Ingrese el promedio del alumno:" << endl;
    cin.ignore(); cin >> nuevo_nodo -> promedio;
    
    // 3. Asignamos NULL al siguiente nodo.
    nuevo_nodo -> siguiente = NULL;

    // 4. Si la lista esta vacia, el nuevo nodo ahora es la cabecera.
    if (*cabecera == NULL)
    {
        *cabecera = nuevo_nodo;
        return;
    } else {
        // 5. Si no, recorre la lista hasta el ultimo nodo.
        while (temporal -> siguiente != NULL)
        {
            temporal = temporal -> siguiente;
        }
        // 6. Cambiamos el siguiente nodo al ultimo nodo.
        temporal -> siguiente = nuevo_nodo;
    }    
}

void eliminar_elemento()
{
    cout << "test";
}

// Funcion principal del programa
int main()
{
    // Variable que almacena la opcion ingresada del usuario.
    int opcion_ingresada;
    // Almacena el estado de la funcion. 
    bool salir = false;
    // Declaramos una lista enlazada vacia.
    Nodo* cabecera = NULL;

    // Menu de opciones.
    do
    {
        // Limpia la terminal.
        //system("clear");

        mostrar_menu();

        cin >> opcion_ingresada;

        // Este switch compara la opcion ingresada con las disponibles.
        switch(opcion_ingresada)
        {
            case 1:
                insertar_elemento(&cabecera);
                break;
            case 2:
                eliminar_elemento();
                break;
            case 3:
                despliega_lista(cabecera);
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

