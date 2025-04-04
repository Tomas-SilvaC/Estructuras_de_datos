/**
* Taller 3. Arboles
* Autores: Tomas Silva, Juan Pabon Vargas
* nodo AVL
**/
#ifndef NODOBINARIOAVL_H
#define NODOBINARIOAVL_H

template <class T>
//Se crea la clase nodo (NodoBinarioAVL)
class NodoBinarioAVL{
    //Funciona igual a un arbol binario normal por el momento
	public:
		T dato;
		NodoBinarioAVL<T> *hijoIzq;
		NodoBinarioAVL<T> *hijoDer;

	public:
	//Nada cambia a un arbol binario, lo que cambia es como se relacionan los nodos en el arbol
	//Constructures
		NodoBinarioAVL();
		~NodoBinarioAVL();
	//Get y set para cada elemento
		T& getDato();
		void setDato(T& val);
		NodoBinarioAVL<T>* getHijoIzq();
		NodoBinarioAVL<T>* getHijoDer();
		void setHijoIzq(NodoBinarioAVL<T>* izq);
		void setHijoDer(NodoBinarioAVL<T>* der);
};

#include "NodoBinarioAVL.hxx"

#endif //NODOBINARIOAVL_H
