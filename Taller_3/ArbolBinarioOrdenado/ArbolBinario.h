/**
* Taller 3. Arboles
* Autores: Tomas Silva, Juan Pabon Vargas
* Arbol binario ordenado
**/
#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
#include "NodoBinario.h"

template <class T>

class ArbolBinario{
	protected:
		NodoBinario<T> *raiz;
	public:
		ArbolBinario();
		~ArbolBinario();
		NodoBinario<T>* getRaiz();
		bool esVacio();
		T& datoRaiz();
		int altura();
		int tamano();
		void insertar(T& val);
		int altura(NodoBinario<T> *nod);
		int tamano(NodoBinario<T> *nod);
		bool insertar(T& val,NodoBinario<T> *nodo);
		int minValor(NodoBinario<T> *nodo);
		NodoBinario<T>* eliminar(T& val, NodoBinario<T> *nodo);
		void preOrden(NodoBinario<T> *nod);
		void inOrden(NodoBinario<T> *nod);
		void posOrden(NodoBinario<T> *nod);
		void nivelOrden(NodoBinario<T> *nod);
};

#include "ArbolBinario.hxx"

#endif //ARBOLBINARIO_H
