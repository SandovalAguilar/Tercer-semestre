//Programa que genera n elementos de la serie fibonacci----- n es proporcionada por el usuario
// La serie fibonacci se define iniciando en 1 y se va sumando con el elemento anterior a este por lo que tiene
// la siguiente forma 1 1 2 3 5 8 13 21 34 55 ......

#include <iostream>
using namespace std;

int fibonacci(int a, int b, int n){ 
	//a=1 b=0 n=6   //a=0 b=1 n=5   //a=1 b=1 n=4   //a=1 b=2 n=3   //a=2 b=3 n=2   //a=3 b=5 n=1   //a=5 b=8 n=0
	
	if (n)
	{		
		int c = a + b;	//c=0+1=1  //c=0+1=1  //c=1+1=2  //c=1+2=3  //c=2+3=5  //c=3+5=8  //c=5+8=13
		
		cout << c << " ";	//1  //1  //2  //3  //5  //8  //13
		return b + fibonacci(b, c, n-1); // 0 + fibonacci(0,1,5)
		                                 // 0 + 1 + fibonacci(1,1,4)    	
	                                     // 0 + 1 + 1 + fibonacci(1,2,3)
	                                     // 0 + 1 + 1 + 2 + fibonacci(2,3,2)
	                                     // 0 + 1 + 1 + 2 + 3 + fibonacci(3,5,1)
	                                     // 0 + 1 + 1 + 2 + 3 + 5 + fibonacci(5,8,0)
	                                     // 0 + 1 + 1 + 2 + 3 + 5 + 8 + fibonacci(8,13,-1)
	
	} else {
		return 1;	// 0 + 1 + 1 + 2 + 3 + 5 + 8 + 1
	}
}

int main()
{
	int n;
	cout << endl << " Ingrese la cantidad de elementos que desea generar: ";
	cin >> n;  cout<<endl; // supongampos que deseamos generar 7 elementos  PRUEBA DE ESCRITORIO	
	
	cout << fibonacci(1, 0, n-1);  // esta es la llamada inicial a la funci�n toma como parametros a=1 b=0 n-1=6	
	return 0;
}

