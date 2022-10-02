// Programa que crea un arreglo con 10 calificaciones de alumnos ingresadas por el usuario
// Calcular el promedio o la media de estas 10 calificaciones
// Imprimir en pantalla el listado de estudiantes con una calificacion mayor a la media

#include <iostream> // libreria para datos de entrada y salida
#include <iomanip> // libreria para formato de etradas y salidas
#include <new> // para utilizar los comandos de memoria dinamica
using namespace std; // para abreviar el uso de comandos de entrada y salida

int main ()  // inicio mi programa principal
{
		
    float *notas = new float[10]; //DECLARACIÓN O ASIGNACIÓN DE MEMORIA PARA MI ARREGLO  
    int i = 0;   // declaro el controlador de ciclo for          
    float suma = 0, media; // declaro suma como acumulador de calif finales y declaro media para obtener el prom del gpo 


   // llenado del arreglo
    for (i=0; i<10; i++) // ciclo for para llenar arreglo
    {
        cout << "Alumno " << i+1 << " Calificacion final: ";  // solicito al usuario ingrese calificaciones
        cin >> notas[i];  //almacenando la calif proporcionada por el usuario en mi arreglo 
    }


   // esta sumando las calificaciones finales de los alumnos
    for (i=0; i<10; i++)
         suma = suma + notas[i];


    media = suma / 10;  //obtener el promedio de las suma de las calif entre 10 y lo almacenamos en media

 
    cout << fixed << setprecision(2);  // definir el formato de salida de la media
    cout << endl << endl << "Promedio general del grupo: " << media << endl; // mostrar en pantalla el valor de la media
   
   
    
    cout << "Listado de alumnos con calificación superiores a la media" << endl;
    cout << "-------------------------------------------------------" << endl;
    for (i=0; i<10; i++) // cilo for para obtener listad de alumnos con calif superior a la media
        if (notas[i] > media) // estructura si/entonces que compara la calif del alumno con la media
        {
            cout << "Alumno numero " << setw(3) << i+1;  // imprimir en pantalla el alumno con calif mayor a la media
            cout << " Calificacion final: " << notas[i] << endl; // imprimir en pantalla el alumno con calif mayor a la media
        }
        
		delete [ ] notas; // LIBERAR EL ESPACIO EN MEMORIA DE MI ARREGLO NOTAS
		
		  
		     
    cout << endl;
    system("pause");
}
