/*
Equipo 5 

Desarrollar un programa que genere un arreglo de tamaño N en forma dinamica
con la instruccion NEW. El valor de N lo proporciona el usuario. Ponerle
a cada elemento del arreglo un entero iniciando en 10 e incrementandose de 10 
en 10. Imprimir el arreglo resultante en pantalla antes de liberar el espacio
en memoria.

*/ 

// Libreria para operaciones de entrada y salida
#include <iostream>
// Abreación de las funciones
using namespace std;

// Declaración de la función principal
int main()
{
    // Asignación de variables estáticas 
    int n = 0;
    int i = 0;

    // El usuario introduce el valor de "n"
    cout << "Introducir el tamaño del arreglo:\n";
    cin >> n; 

    // Declaración del puntero "arreglo" en memoria dinámica
    int* arreglo = new int[n];

    // Itera "n" veces e incrementa de 10 en 10
    for (i = 0; i < n; i++) 
    {
        // Dado un índice, asigna el valor siguiente
        arreglo[i] = (i + 1) * 10;
    }

    // Itera "n" veces e imprime el contenido del arreglo
    cout << "Elementos del arreglo:\n";
    for (i = 0; i < n; i++) 
    {
        cout << arreglo[i] << " ";
    }

    // Salto del línea
    cout << endl;

    // Libera el espacio en memoria dinámica
    delete[] arreglo;

    // Finalización del programa
    return 0;
}

