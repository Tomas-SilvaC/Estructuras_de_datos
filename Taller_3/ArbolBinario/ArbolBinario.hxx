/**
* Taller 3. Arboles
* Autores: Tomas Silva, Juan Pabon Vargas
* Arbol binario
**/
#include "ArbolBinario.h"
#include "NodoBinario.h"

using namespace std;

//Constructor por defecto
template<class T>
ArbolBinario<T>::ArbolBinario()
{
	this->raiz=NULL;
}

//mira si el arbol es vacio. Retorna true si lo es, retorna false si no lo es
template<class T>
bool ArbolBinario<T>::esVacio()
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
//obtiene del dato de la raiz
template<class T>
T& ArbolBinario<T>::datoRaiz()
{
	return this->raiz->obtenerDato();
}
//devuelve la altura total del arbol
template<class T>
int ArbolBinario<T>::altura()
{
	return this->raiz->altura();
}
//devuelve la cantidad total de nodos en el arbol
template<class T>
int ArbolBinario<T>::tamano()
{
	return this->raiz->tamano() ;
}
//inserta un nodo con valor val
template<class T>
void ArbolBinario<T>::insertar(T& val)
{
	if(this->raiz!=NULL)
	{
		this->raiz->insertar(val);
	}
	else
	{
		NodoBinario<T>* nuevo= new NodoBinario<T>();
		nuevo->fijarDato(val);
		this->raiz=nuevo;
	}


}


//elimina un nodo con valor val
template<class T>
bool ArbolBinario<T>::eliminar(T& val)
{
	//Nodo* borrar = this->buscar(val);
	NodoBinario<T>* borrar = this->buscar(val);
	if(borrar == NULL)
		return false;

	if(borrar->hijoIzq != NULL)
	{
		//Nodo* nuevo = borrar->hijoIzq->extremo_der();
		NodoBinario<T>* nuevo = borrar->hijoIzq->extremo_der();
		borrar->fijarDato(nuevo->obtenerDato());
		delete (borrar);
		delete(nuevo);
	}
	else if(borrar->hijoDer != NULL)
	{
		//Nodo* nuevo = borrar->hijoDer->extremo_izq();
		NodoBinario<T>* nuevo = borrar->hijoDer->extremo_izq();
		borrar->fijarDato(nuevo->obtenerDato());
		delete(nuevo);
	}
	else if(borrar->hijoDer ==NULL && borrar->hijoIzq ==NULL)
	{
	    delete borrar;
	}
	return true;
}


//busca el nodo con valor val
template<class T>
NodoBinario<T>* ArbolBinario<T>::buscar(T& val)
{
	return this->raiz->buscar(val);
}
//Impresion de los recorridos del arbol
template<class T>
void ArbolBinario<T>::preOrden()
{
	this->raiz->preOrden();
}

template<class T>
void ArbolBinario<T>::inOrden()
{
	this->raiz->inOrden();
}

template<class T>
void ArbolBinario<T>::posOrden()
{
	this->raiz->posOrden();
}

template<class T>
void ArbolBinario<T>::nivelOrden()
{
	this->raiz->nivelOrden();
}

