/*
Ismael Sandoval Aguilar (2022).

Actividad 2.

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

// Funcion que muestra en la terminal la informacion de la lista.
void despliega_lista(Nodo* apuntador)
{
    // Creo que su nombre es bastante autodescriptivo.
    int contador = 1;

    // Mientras el apuntador auxiliar no sea nulo, recorre la lista.
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

// Esta funcion inserta un nuevo nodo al final de la lista.
void insertar_elemento(Nodo** cabecera)
{
    // 1. Creamos un nuevo nodo.
    Nodo* nuevo_nodo = new Nodo();

    // Puntero temporal.
    Nodo* pTemporal = *cabecera;
    
    // 2. Asignamos informacion dentro del nodo.
    // El usuario ingresa la informacion.
    cout << "\n\n\tIngrese la matricula del alumno:";
    cin.ignore(); cin >> nuevo_nodo -> matricula;
    cout << "\n\n\tIngrese el nombre del alumno:";
    cin.ignore(); cin.getline(nuevo_nodo -> nombre, max_char); 
    cout << "\n\n\tIngrese el promedio del alumno:";
    cin.ignore(); cin >> nuevo_nodo -> promedio;
    
    // 3. Asignamos NULL al siguiente nodo.
    nuevo_nodo -> siguiente = NULL;

    // 4. Si la lista esta vacia, el nuevo nodo ahora es la cabecera.
    if (*cabecera == NULL)
    {
        *cabecera = nuevo_nodo;
        return;
    } 
    else 
    {
        // 5. Si no, recorre la lista hasta el ultimo nodo.
        while (pTemporal -> siguiente != NULL)
        {
            pTemporal = pTemporal -> siguiente;
        }
        // 6. Cambiamos el siguiente nodo al ultimo nodo.
        pTemporal -> siguiente = nuevo_nodo;
    }    
}

// Elimina un elemento de la lista; en este caso, dado un nombre.
void eliminar_elemento(Nodo* &cabecera)
{
    // Creamos una variable dinamica temporal para almacenar el nombre a buscar.
    long int matricula_temporal;
    // Almacena temporalmente la direccion del nodo.
    Nodo* pTemporal;
    // Compara nodos; sera util al iterar. 
    Nodo* pComparador;
    // El puntero ahora empieza desde la cabecera.
    pComparador = cabecera;

    cout << "\n\n\n\t Eliminar un paciente";
    cout << "\n\n\t Ingrese la matricula del alumno: ";
    cin >> matricula_temporal;

    // Mientras el puntero no sea nulo, itera.
    while (pComparador != NULL)
    {
        // Compara el campo "nombre" del nodo con el nombre temporal.
        if (pComparador -> matricula == matricula_temporal)
        {
            if (pComparador == cabecera)
            {
                cabecera = cabecera -> siguiente;
            }
            else
            {
                pTemporal -> siguiente = pComparador -> siguiente;
            }
            delete(pComparador);
            cout << "\n\n\t[Registro eliminado]\n";
            return;
        }
        else
        {
            pTemporal = pComparador;
            pComparador = pComparador -> siguiente;
        }
    }
    if (pComparador == NULL)
    {
        cout << "\n\t[Codigo incorrecto]\n";
    }   
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
                eliminar_elemento(cabecera);
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

