/**
* Taller 3. Arboles
* Autores: Tomas Silva, Juan Pabon Vargas
* Arbol
**/
#ifndef __ARBOL__H__
#define __ARBOL__H__

#include "nodo.h"

using namespace std;

template<class T>
class Arbol {
	protected:
    	Nodo<T> *raiz;
	public:
		Arbol();
		Arbol(T val);
	    bool esVacio();
   	 	T obtenerRaiz();
   	 	void fijarRaiz(Nodo<T>* root);
   	 	void fijarDato(T val, T valNodo);
   	 	bool insertarNodo(T padre, T val);
    	int altura();
	    int tamano();
    	bool eliminarNodo(T val, T padre);
    	Nodo<T>*  buscar(T val);
    	void preOrden();
    	void inOrden();
    	void posOrden();
    	void nivelOrden();
};

#include "arbol.hxx"
#endif
