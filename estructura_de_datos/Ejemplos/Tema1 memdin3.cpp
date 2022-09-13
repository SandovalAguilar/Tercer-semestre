// Programa que almacena el precio de n artículos comprados en un arreglo y genera el total comprado.

#include <iostream>
using namespace std;

int main()     
{
    int n = 0,  i = 0;
    float TP=0;
        
    cout << endl << "La cantidad de articulos comprados: ";
    cin >> n;
    
	float* precio = new float[n];
    
    cout << endl << "Ingreso de precios de los articulos";
    cout << endl << "-----------------------------------";
       
    for (i = 0; i < n; ++i) 
	{
        cout << "Precio del articulo " << i+1 << ": $";
        cin >> precio[i];
        TP=TP+precio[i];
    }

 // libreramos el espacio de memoria del arreglo ya que no lo utilizaremos más
    delete[] precio;
      
  
   cout << endl << "-----------------------------------";
   cout << endl << "Total a pagar: $" << TP << endl;
  
  
  
  
  return 0;
}
