// programa que apila y muestra en pantalla
#include<iostream>
#include<conio.h>
using namespace std;

struct nodo
{ 
	int nro; // campo de información
    struct nodo *sgte; // campo liga
	};

typedef nodo *Pila; // apuntador a nodo cabecera


//Función para insertar elementos en la pila *****************
void push(Pila &p, int n)
	{ 
		Pila q=new(struct nodo);
  		q->nro=n;
  		
		q->sgte=p;
  		p=q;
	}


//Función para visualizar elementos en la pila ***************
void imprimir(Pila p1)
	{ 
		while(p1!=NULL)
 		{
 			cout<<"     "<<p1->nro<<endl;
  			p1=p1->sgte;
 		}		
	cout<<endl;
	}	

// Función principal *****************************************
int main(void)
{ 
	Pila p1=NULL;
  	Pila p=NULL;
	int opc,n,valor,i;
	do
	{ 
		system("cls");
		cout<<endl<<endl<<" Menu de opciones"<<endl;
  		cout<<endl<<" 1: Apilar"<<endl;
		cout<<" 2: Ver pila"<<endl;
		cout<<" 3: Salir"<<endl;
 
 		cout<<" Ingrese una opcion: ";
 		cin>>opc;
 
 		switch(opc)
 		{
		 	case 1: 
				system("cls");
 				cout<<endl<<"Ingrese tamaño de la pila: "; 
				cin>>n;
           		cout<<endl<<"Ingresar datos..."<<endl;
           		for(i=0;i<n;i++)
           		{
			   		cout<<"Elemento:"<< i+1<<endl;
            		cin>>valor;
      				push(p1,valor);
            	}
        	break;

 			case 2:
 				system("cls");
 				cout<<endl<<" ** PILA **"<<endl;
   				imprimir(p1);
				system("pause"); 
   			break;
 		}		
	}
	while(opc!=3);
}
