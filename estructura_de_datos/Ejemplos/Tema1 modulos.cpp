//Ejemplo de programa con paso y sin paso de parámetros en funciones
#include <stdio.h>
#include <math.h>

double dato=0.0; 
double resultado=0.0;
void raiz (double numero);    

int main()     //Función main sin paso de parámetros
{
    printf("PROGRAMA QUE OBTIENE LA RAIZ CUADRADA DE 2 NUMEROS ESTABLECIDOS Y UNO PROPORCIONADO POR EL USUARIO \n\n");
	raiz(9);     
    raiz(144);
    printf("Introduzca un numero positivo: ");
    scanf("%lf", &dato); // Leer el dato
    raiz(dato);
    return 0;
}

void raiz(double numero)     //Función Raiz, con datos de entrada un número real
{   
    resultado = sqrt(numero);
    printf("La raíz cuadrada es: %.2lf \n\n", resultado);
}
