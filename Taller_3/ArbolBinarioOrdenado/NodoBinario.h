/**
* Taller 3. Arboles
* Autores: Tomas Silva, Juan Pabon Vargas
* nodo binario 
**/
#ifndef NODOBINARIO_H
#define NODOBINARIO_H


template <class T>

class NodoBinario{
	protected:
		T dato;
		NodoBinario<T> *hijoIzq;
		NodoBinario<T> *hijoDer;

	public:
		NodoBinario();
		NodoBinario(T& val);
		~NodoBinario();
		T& getDato();
		void setDato(T& val);
		NodoBinario<T>* getHijoIzq();
		NodoBinario<T>* getHijoDer();
		void setHijoIzq(NodoBinario<T> *izq);
		void setHijoDer(NodoBinario<T> *der);
};

#include "NodoBinario.hxx"
#endif //NODOBINARIO_H
