/**
* Taller 3. Arboles
* Autores: Tomas Silva, Juan Pabon Vargas
* nodo AVL
**/
#include "NodoBinarioAVL.h"

using namespace std;

template <class T>
//Constructores
NodoBinarioAVL<T>::NodoBinarioAVL(){
    //Los valores inician en NULL
	this->hijoIzq=NULL;
	this->hijoDer=NULL;
}

template <class T>
NodoBinarioAVL<T>::~NodoBinarioAVL(){
}
//Get y set de los elementos de la clase
template <class T>
T& NodoBinarioAVL<T>::getDato(){
	return this->dato;
}

template <class T>
void NodoBinarioAVL<T>::setDato(T& val){
	this->dato=val;
	return;
}

template <class T>
NodoBinarioAVL<T>* NodoBinarioAVL<T>::getHijoIzq(){
	return this->hijoIzq;
}

template <class T>
NodoBinarioAVL<T>* NodoBinarioAVL<T>::getHijoDer(){
	return this->hijoDer;
}

template <class T>
void NodoBinarioAVL<T>::setHijoIzq(NodoBinarioAVL<T>* izq){
	this->hijoIzq=izq;
	return;
}

template <class T>
void NodoBinarioAVL<T>::setHijoDer(NodoBinarioAVL<T>* der){
	this->hijoDer=der;
	return;
}
