// Lista en C++ con Clase
#include <iostream> //es la biblioteca estándar en C++ para poder tener acceso a los dispositivos estándar de entrada y/o salida.
using namespace std;
 
class nodo { //  guarda la informacion que vamos a manejar en la lista, valor de informacion int entero
   public:
      nodo(int v, nodo *sig = NULL) // constructor que tiene dos parametros, puede se un valor y no null tambien
         {
            valor = v;
            siguiente = sig;
         }
 
  private: //Son inaccesibles para las demas clases.
   int valor; //nodo de tipo entero
   nodo *siguiente; // A punta al nodo sigiente
       
  friend class lista; //Una clase amiga puede acceder a miembros privados y protegidos de otra clase en la que está declarada como amiga.                                                                
};
 
typedef nodo *pnodo; //tipo de dato llamado pnodo(nombre del dato) que apunta hacia una instancia de tipo nodo y * es el puntero
 
class lista {  //tiene varios metodos, permite crear nodos y manejarlos
  public: // Permite el acceso a todo mienbro desde dentro y fuera de las clase
   lista() { primero = actual = NULL; } //cuando se crea la lista primero y actual quedan null
   ~lista();// destructor de la clase ~(alt 126), se llama igual que la clase, no retorna a nada ni recibe parametros y sirve para limpiar la lista, vaciar el espacio en memoria
   
   void Insertar(int v); //inserta un valor en la lista y debe ser entero
   void Borrar(int v); //se debe indicar el elemento a borrar, entoces se llama al elemento a borrar
   bool ListaVacia() { return primero == NULL; } //si la lista da null es porque esta vacia
   void Mostrar(); //lo que hace es recorrer la lista y la muestra
   void Siguiente();//pasa al siguiente elemento
   void Primero();
   void Ultimo();
   bool Actual() { return actual != NULL; }
   int ValorActual() { return actual->valor; }
   
  private:
   pnodo primero; // es un puntero a alguna instacia de nodo
   pnodo actual; //es un puntero hacia un nodo
};
 
lista::~lista()
{
  pnodo aux; //Declara un puntero aux
 
  while(primero) { //Mientras primero cunpla las condiciones de las linia 49 a 50 se ejecutara
     aux = primero; // se asigna el valor de aux a primero
     primero = primero->siguiente; // Primer apunta al nodo siguiente
     delete aux; //se elimina aux
  }
  actual = NULL; // si no cunple while entonces tendra valor nulo
}
 
void lista::Insertar(int v)// se inserta un valor en la lista
{
  pnodo anterior;
 
  //si la lista sta vacia
  if(ListaVacia() || primero->valor > v) { // Acignamos a lista un nuevo nodo de valor v y cuyo sigiente ellemento es la lista actual
             
     primero = new nodo(v, primero);
  }
  else {
     //Busca el nodo de valosr menor a v
     anterior = primero;
      //Avansamos hasta el ultimo elemento o hasta que sigiente tenga un valor mayor que v
     
     while(anterior->siguiente && anterior->siguiente->valor <= v)
        anterior = anterior->siguiente;
     // Creamos un nuevo nodo despues del nodo anterior y cuyo sigiente es el sigiente del anterior
     anterior->siguiente = new nodo(v, anterior->siguiente);
  }
}
 
void lista::Borrar(int v) //Bora un nodo de la lista
{
  pnodo anterior, nodo;
 
  nodo = primero; //Nodo primero
  anterior = NULL;//valor null para anterior
  while(nodo && nodo->valor < v) { //Mientras nodo y nodo apunten a valor y siendo menor a "v"
     anterior = nodo;              //se le asigna el valor del nodo al "anterior"
     nodo = nodo->siguiente; // si nodo es igual a nodo apunta a sigiente
  }
  if(!nodo || nodo->valor != v) return;
  else { // bora el nodo
     if(!anterior) //Este if indica cual queremos borrar y como prosegira
        primero = nodo->siguiente; //"primero" se iguala a nodo apuntando a "siguiente"
     else  // un elemento cualquiera
        anterior->siguiente = nodo->siguiente; //hacemos que nodo apunta al nodo que queremos borrar
     delete nodo; //Liberacion de menoria del nodo
  }  
}
 
void lista::Mostrar() //lo que hace es recorrer la lista y la muestra
{
  nodo *aux; //Nodo apunta a aux
 
  aux = primero; //aux se le asigna el valor de primero
  while(aux) {  //Mientras aux cumpla con la condicion entonces imprime aux apunta a valor
     cout << aux->valor << "-> ";  
     aux = aux->siguiente; // aux apunta al siguiente
  }
  cout << endl; // salto de linia
}
 
void lista::Siguiente()
{
  if(actual) actual = actual->siguiente; //"actual" apunta a "sigiente"
}
 
void lista::Primero()
{
  actual = primero; //"actual" tomo el valor de "primero"
}
 
void lista::Ultimo()
{
  actual = primero;  //"actual" tomo el valor de "primero"
  if(!ListaVacia()) // si es diferente de la "ListaVacia"
     while(actual->siguiente) Siguiente(); //ciclo que verifica que se cumpla la condicion de "actual"
}
 
int main()
{
  lista Lista; //manda a llamar la lista
  //inserta los elemento
  Lista.Insertar(20);
  Lista.Insertar(10);
  Lista.Insertar(40);
  Lista.Insertar(30);
 
  Lista.Mostrar();  //Llama a la funcion mostrar
 
  cout << "Lista de elementos:" << endl; //inpesion de los elementos
  Lista.Primero(); //Llama a la funcion Primero
  while(Lista.Actual()) { //mientras cunpla la condicion imprimira el valor actual y salto de linia
     cout << Lista.ValorActual() << endl;
     Lista.Siguiente(); //Llama a la funcion Siguiente
  }
  Lista.Primero(); //Llama a la funcion Primero
  cout << "Primero: " << Lista.ValorActual() << endl; //imprime el primer valor de la lista actual
 
  Lista.Ultimo(); //Llama a la funcion Ultimo
  cout << "Ultimo: " << Lista.ValorActual() << endl; //imprime el ultimo valor de la lista actual
  //Borrando los elementos
  Lista.Borrar(10);
  Lista.Borrar(15);
  Lista.Borrar(45);
  Lista.Borrar(30);
  Lista.Borrar(40);
 
  Lista.Mostrar(); //Llama a la funcion Mostrar
 
  cin.get();
  return 0;
}