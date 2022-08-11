/*
Equipo 5: actividad 1
*/

#include <stdio.h>

void suma_funciones();
void sumatoria_funciones();

int main()
{
    suma_funciones();
    
    return 0;
}

void suma_funciones()
{
    int A[10] = {};
    int B[10] = {};
    int C[10] = {};
    int aux = 0;
    int i = 0;
    int j = 0;

    for (i = 1; i < 3; i++)
    {
        printf("Introducir los elementos del arreglo #%d:\n", i);
        for (j = 0; j < 10; j++)
        {
            if (i == 1)
            {
                printf("Introducir el elemento #%d del arreglo:\n", j + 1);
                scanf("%d", &A[j]);
            }
            else
            {
                printf("Introducir el elemento #%d del arreglo:\n", j + 1);
                scanf("%d", &B[j]);
            }
        }
    }

    for (i = 0; i < 10; i++)
    {
        C[i] = A[i] + B[i];
    }

    for (i = 0; i < 10; i++)
    {
        printf("%d ", C[i]);
    }   
}
