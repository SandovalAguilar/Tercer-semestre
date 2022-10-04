//Programa que genera n elementos de la serie fibonacci----- n es proporcionada por el usuario
// La serie fibonacci se define iniciando en 1 y se va sumando con el elemento anterior a este por lo que tiene
// la siguiente forma 1 1 2 3 5 8 13 21 34 55 ......

#include <iostream>
using namespace std;

int fibonacci(int a, int b, int n)
{ 

	if (n)
	{		
		int c = a + b;	
		cout << c << " ";	
		return b + fibonacci(b, c, n-1); 
	
	} else {
	    return 1;	
	}
}

/*

** n = 3
** a = 1, b = 0, n = 2

int fibonacci(int 1, int 0, int 2)
{ 
	if (2) 
	{		
		int c = 1 + 0;	
		cout << 1 << " ";	
		return 0 + fibonacci(0, 1, 2-1);
	
	} else {
	    return 1;	
	}
}

$$ 1

** a = 0, b = 1, n = 1

int fibonacci(int 0, int 1, int 1)
{ 
	if (1) 
	{		
		int c = 0 + 1;	
		cout << 1 << " ";	
		return 1 + fibonacci(1, 1, 1-1);
	
	} else {
	    return 1;	
	}
}

$$ 1 1

** a = 1, b = 1, n = 0

int fibonacci(int 1, int 1, int 0)
{ 
	if (0) 
	{		
		int c = 1 + 1;	
		cout << 2 << " ";	
		return 1 + fibonacci(1, 1, 1-1);
	
	} else {
	    return 1;	
	}
}

$$ 1 1 2

*/

int main()
{
	int n;
	cout << endl << " Ingrese la cantidad de elementos que desea generar: ";
	cin >> n;  cout<<endl; 
	
	cout << fibonacci(1, 0, n-1);  
	return 0;
}

