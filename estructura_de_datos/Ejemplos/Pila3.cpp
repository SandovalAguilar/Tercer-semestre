// Programa que permite capturar los movimientos de caja de un banco y hacer corte de caja
#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<string.h>
#define maxchar 60

using namespace std;

struct nodo
{
    char nombre[maxchar]; // campo que almacena el nombre
    long long cuenta; // campo que almacena el numero de cuenta
    double deposito; // campo del monto a depositar
    struct nodo *sgte;
};

typedef nodo *ApPila; // apuntador a pila


//--------------------- FUNCION MENU PRINCIPAL --------------------
void menu(void){

    cout<<"\n\t\t[    REGISTRO DE DESPOSITOS BANCARIOS    ]\n";
    cout<<"\t\t----------------------------\n\n";
    cout<<" 1. INGRESAR DEPOSITO                          "<<endl;
    cout<<" 2. MOSTRAR DEPOSITOS BANCARIOS                "<<endl;
    cout<<" 3. GENERAR CORTE DE CAJA                      "<<endl;
    cout<<" 4. SALIR                                      "<<endl;

    cout<<"\n Ingrese opcion : ";
}


//-------------------- FUNCION REGISTRAR DEPOSITOS BANCARIOS ------------------
// funcion de apilar elementos --- PUSH

void registrar_depositos(ApPila &pila)
 {
	ApPila aux=new(struct nodo);
	cout<<"\t\t------------";
    cout<<"\n\tDATOS DEL DEPOSITO BANCARIO ";
    cout<<"\n\n\tCUENTA BANCARIA: "; cin>>aux->cuenta;
    cin.ignore(); cout<<"\n\tNOMBRE: "; cin.getline(aux->nombre,maxchar);
    cout<<"\n\tDEPOSITO: $"; cin>>aux->deposito;
	
	system("cls");
    aux->sgte = pila ;
    pila = aux ;
    
}

//---------------------- FUNCION MOSTRAR DEPOSITOS BANCARIOS -------------------
void mostrar_depositos(ApPila pila)
{
   ApPila aux;
   aux = pila;
   cout<<"\n\tDEPOSITOS BANCARIOS REALIZADOS "<<endl;
      while( aux!=NULL )
     {
        cout<<"\n\t ------------------------ ";
        cout<<"\n\tCUENTA: "<<aux->cuenta;
        cout<<"\n\tNOMBRE: "<<aux->nombre;
        cout << fixed << setprecision(2); 
		cout<<"\n\tDEPOSITO: $"<<aux->deposito<<endl;

       aux = aux->sgte;
	  }

}

//---------------------- FUNCION GENERAR CORTE DE CAJA -------------------
void corte_caja(ApPila pila)
{
   double total=0;
   ApPila aux;
   aux = pila;
   cout<<"\n\tCORTE DE CAJA -- SE ELIMINARAN LOS REGISTROS DE DEPOSITOS "<<endl;
      while( aux!=NULL )
     {
        cout<<" ------------------------- ";
        cout<<"\n\tCUENTA: "<<aux->cuenta;
        cout<<"\n\tNOMBRE: "<<aux->nombre;
        cout << fixed << setprecision(2); 
		cout<<"\n\tDEPOSITO: $"<<aux->deposito<<endl;
		
		total=total+aux->deposito; // CALCULAR EL TOTAL DE DEPOSITOS
        
		aux = aux->sgte;
       
      }
      cout<<"\n\tTOTAL DE DEPOSITOS REALIZADOS EN ESTE TURNO ES: $"<<total<<endl;
   
}


//------------------ FUNCION ElIMINAR REGISTROS ------------------
void borrar_depositos(ApPila &pila)
{
     ApPila aux;
     
     while( pila != NULL)
     {
           aux = pila;  // RESGUARDO MI NODO CABECERA
           pila = aux->sgte; // HACIENDO QUE EL NODO CABECERA APUNTE HACIA EL NODO SIGUIENTE
           delete(aux);
     }
}



//------------------------- FUNCION PRINCIPAL -------------------
int main(void){
	

    system("color 0b");

    ApPila pila=NULL;
    int opcion; //sn;
    
    do{
            menu();
            cin>>opcion;

            switch(opcion)
			{

                case 1: registrar_depositos(pila);
                        break;

                case 2: if(pila==NULL)
						{
                            cout<<"\n\tNo hay Depositos Registrados.....!!!!\n";
                        }
						else
						{
                            mostrar_depositos(pila);
                        }
                        break;

                case 3: if(pila==NULL)
						{
                            cout<<"\n\tNo hay Depositos Registrados.....!!!!\n";
                        }
						else
						{
							corte_caja(pila);
							borrar_depositos(pila);
                        }
                        break;

               }

            system("pause");  system("cls");

        }while(opcion!=4);

    system("pause");

    return 0;
}
