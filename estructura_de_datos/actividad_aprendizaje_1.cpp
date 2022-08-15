/*
Equipo 5 

Desarrollar un programa que genere un arreglo de tamaño N en forma dinamica
con la instruccion NEW. El valor de N lo proporciona el usuario. Ponerle
a cada elemento del arreglo un entero iniciando en 10 e incrementandose de 10 
en 10. Imprimir el arreglo resultante en pantalla antes de liberar el espacio
en memoria.

*/ 

#include <iostream>
#include <new>

using namespace std;

int main()
{
    int n = 0;
    int i = 0;

    cout << "Introducir el tamaño del arreglo\n:";
    cin >> n; 

    int *arreglo = new int[n];

    for (i = 0; i < n; i++) 
    {
        arreglo[i] = (i + 1) * 10;
    }

    cout << "Elementos del arreglo:\n";

    for (i = 0; i < n; i++) 
    {
        cout << arreglo[i] << " ";
    }

    cout << endl;

    delete[] arreglo;

    return 0;
}

