//Ejemplo de programa con paso y sin paso de par�metros en funciones
#include <stdio.h>
#include <math.h>

double dato=0.0; 
double resultado=0.0;
void raiz (double numero);    

int main()     //Funci�n main sin paso de par�metros
{
    printf("PROGRAMA QUE OBTIENE LA RAIZ CUADRADA DE 2 NUMEROS ESTABLECIDOS Y UNO PROPORCIONADO POR EL USUARIO \n\n");
	raiz(9);     
    raiz(144);
    printf("Introduzca un numero positivo: ");
    scanf("%lf", &dato); // Leer el dato
    raiz(dato);
    return 0;
}

void raiz(double numero)     //Funci�n Raiz, con datos de entrada un n�mero real
{   
    resultado = sqrt(numero);
    printf("La ra�z cuadrada es: %.2lf \n\n", resultado);
}
