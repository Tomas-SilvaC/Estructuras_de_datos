/**
* Taller 3. Arboles
* Autores: Tomas Silva, Juan Pabon Vargas
* Arbol AVL
**/
#ifndef ARBOLBINARIOAVL_H
#define ARBOLBINARIOAVL_H

#include "NodoBinarioAVL.h"
#include <queue>
#include <iostream>
template <class T>

class ArbolBinarioAVL{
	protected:
		NodoBinarioAVL<T> *raiz;
	public:
	    //Constructores
		ArbolBinarioAVL();
		~ArbolBinarioAVL();
		void setRaiz(NodoBinarioAVL<T>* raiz);
		NodoBinarioAVL<T>* getRaiz();
		bool esVacio();
		T& datoRaiz();
		int altura(NodoBinarioAVL<T> *inicio);
		int tamano(NodoBinarioAVL<T> *inicio);
		//Giros del arbol (y lo que diferencia esta clase de "arbol.cxx"
		NodoBinarioAVL<T>* giroDerecha(NodoBinarioAVL<T>*& inicio);
		NodoBinarioAVL<T>* giroIzquierdaDerecha(NodoBinarioAVL<T>* &padre);
		void printTreeLevelOrder(NodoBinarioAVL<T>* root);
		NodoBinarioAVL<T>* giroIzquierda(NodoBinarioAVL<T>*& inicio);
		NodoBinarioAVL<T>* giroDerechaIzquierda(NodoBinarioAVL<T>* &padre);
		//Agregar, eliminar y buscar valores
		bool insertar(T& val);
		bool eliminar(T& val);
		bool buscar(T& val);
		//Tipos de organización de arbol binario
		void preOrden(NodoBinarioAVL<T> *inicio);
		void inOrden(NodoBinarioAVL<T> *inicio);
		void posOrden(NodoBinarioAVL<T> *inicio);
		void nivelOrden(NodoBinarioAVL<T> *inicio);
};
#include "ArbolBinarioAVL.hxx"

#endif //ARBOLBINARIOAVL_H
