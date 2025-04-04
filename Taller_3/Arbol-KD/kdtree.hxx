/**
* Taller 3. Arboles
* Autores: Tomas Silva, Juan Pabon Vargas
* Arbol KD
**/
#include "kdtree.h"
#include "kdnodo.h"

using namespace std;


//Constructor

template<class T>
kdtree<T>::kdtree(){
	this->raiz=NULL;
}



//Revisa si el arbol esta vacio actualmente, retorna 1 de estarlo

template<class T>
bool kdtree<T>::esVacio()
{
   if(this==NULL)
   {
      return true;
   }
   else
   {
     return false;
   }
}

//Obtiene el dato en la raiz
template<class T>
T& kdtree<T>::datoRaiz()
{
   return this->raiz->obtenerDato();
}
//Obtiene la altura del arbol
template<class T>
int kdtree<T>::altura()
{
   return this->raiz->altura();
}
//Retorna el tamaño del arbol (cantidad de nodos)
template<class T>
int kdtree<T>::tamano()
{
	return this->raiz->tamano() ;
}

//Inserta un valor en el arbol
template<class T>
void kdtree<T>::insertar(vector <T> &val)
{
	if(this->raiz!=NULL){
		this->raiz->insertar(val);
	}
	else{
		kdnodo<T>* nuevo= new kdnodo<T>();
		nuevo->fijarDato(val);
		this->raiz=nuevo;
	}


}

//Busca un valor en el arbol
template<class T>
kdnodo<T>* kdtree<T>::buscar(T& val)
{
	return this->raiz->buscar(val);
}

//Imprime preOrden
template<class T>
void kdtree<T>::preOrden()
{
	this->raiz->preOrden();
}

//Imprime InOrden
template<class T>
void kdtree<T>::inOrden()
{
	this->raiz->inOrden();
}

//Imprime PosOrden
template<class T>
void kdtree<T>::posOrden()
{
	this->raiz->posOrden();
}

//Imprime NivelOrden
template<class T>
void kdtree<T>::nivelOrden()
{
	this->raiz->nivelOrden();
}

//Obtiene el maximo del arbol
template<class T>
void kdtree<T>::maximo(int &maxi)
{
	this->raiz->maximo(maxi);
}

//Obtiene el minimo del arbol
template<class T>
void kdtree<T>::minimo(int &mini)
{
	this->raiz->minimo(mini);
}
