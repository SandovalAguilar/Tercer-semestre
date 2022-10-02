#include <iostream>
using namespace std;

int main() 
{
    // declaramos una variable de tipo entero
    int* num1;               // int *num1 = new int                 
    // declaramos una variable de tipo flotante
    float* num2;

   // asignación dinamica de memoria
    num1 = new int;
    num2 = new float;

    //almacenamos valores en las variables
    *num1 = 45;
    *num2 = 45.45;

    // Imprimamos las variables en pantalla
    cout << endl << " Valor entero: " << *num1 << endl;
    cout << " Valor flotante: " << *num2 << endl;

    // liberemos los recursos del sistema
    delete num1; 
    delete num2;

    return 0;
}
