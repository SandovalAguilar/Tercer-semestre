/*
Equipo 5: actividad 1
*/

#include <stdio.h>

void suma_funciones();
void sumatoria_funciones();

int main()
{
    int n;
    int opcion;

    do
    {
        printf("\n   1. Sumar dos arreglos.\n");
        printf("\n   2. Obtener la sumatoria de los elementos de un arreglo.\n");
        printf("\n   3. Salir.\n" );
        printf("\n\n   Introduzca opcion (1-3): ");

        scanf( "%d", &opcion );

        switch (opcion)
        {
            case 1:
                suma_funciones();
                break;
            case 2:
                sumatoria_funciones();
                break;
        }

    } while (opcion != 3);
    
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

void sumatoria_funciones()
{
    int D[20] = {};
    int i = 0;
    int total = 10;

    for (i = 0; i < 20; i++)
    {
        printf("Ingresar el elemento #%d del arreglo:\n", i + 1);
        scanf("%d", &D[i]);
    }

    for (i = 0; i < 20; i++)
    {
        total = total + D[i];
    }

    printf("La sumatoria de todos los elementos del arreglo es: %d\n", total);
}