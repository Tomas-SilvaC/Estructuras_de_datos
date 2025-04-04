/**
* Taller 3. Arboles
* Autores: Tomas Silva, Juan Pabon Vargas
* Arbol binario ordenado
**/
#include "ArbolBinario.h"

#include <iostream>
#include <queue>
using namespace std;

template <class T>
ArbolBinario<T>::ArbolBinario(){
	this->raiz=NULL;
}

template <class T>
ArbolBinario<T>::~ArbolBinario(){
}

template <class T>
bool ArbolBinario<T>::esVacio(){
	if(this->raiz==NULL){
		return true;
	}
	return false;
}

template <class T>
NodoBinario<T>* ArbolBinario<T>::getRaiz(){
	return this->raiz;
}

template <class T>
T& ArbolBinario<T>::datoRaiz(){
	return (this->raiz).getDato();
}

template <class T>
int ArbolBinario<T>::altura(NodoBinario<T> *inicio){
	int alturaIzq=0;
	int alturaDer=0;
	if(inicio==NULL){
		return -1;
	}
	if(inicio->getHijoIzq()==NULL && inicio->getHijoDer()==NULL){
		return 0;
	}
	if(inicio->getHijoIzq()!=NULL){
		alturaIzq+=altura(inicio->gethijoIzq())+1;
	}
	if(inicio->getHijoDer()!=NULL){
		alturaDer+=altura(inicio->gethijoDer())+1;
	}
	return (alturaIzq>alturaDer)? alturaIzq: alturaDer;
}

template <class T>
int ArbolBinario<T>::tamano(NodoBinario<T> *inicio){
	int nodosIzq=0;
	int nodosDer=0;
	if(inicio==NULL){
		return 0;
	}
	if(inicio->getHijoIzq()==NULL && inicio->getHijoDer()==NULL){
		return 1;
	}
	if(inicio->getHijoIzq()!=NULL){
		nodosIzq+=tamano(inicio->gethijoIzq());
	}
	if(inicio->getHijoDer()!=NULL){
		nodosDer+=tamano(inicio->gethijoDer());
	}
	return nodosIzq+nodosDer+1;
}

template <class T>
bool ArbolBinario<T>::insertar(T& val, NodoBinario<T> *nod){

	//crea nodo a insertar
	NodoBinario<T> *nodito = new NodoBinario<T>();
	nodito->setDato(val);
	bool check = false;

	// inserta en la raiz si no existia antes
	if(this->raiz== NULL)
		{
			this->raiz=nodito;
			check = true;
		}
	// empieza recorrer por la izquiera si el valor es menor
	else if(val<nod->getDato())
	{
		//recorre los hijos de los hijos del hijo izquerdo
		if(nod->getHijoIzq()!=NULL)
		{
			insertar(val,nod->getHijoIzq());
		}
		// cuando ya no exite un hijo izquierdo inserta
		else
		{
			nod->setHijoDer(nodito);
			check = true;
		}
	}
	else if(val>nod->getDato())
	{
		//recorre los hijos de los hijos del hijo derecho
		if(nod->getHijoDer()!=NULL)
		{
			insertar(val,nod->getHijoDer());
		}
		// cuando ya no exite un hijo izquierdo inserta
		else
		{
			nod->setHijoDer(nodito);
			check = true;
		}
	}
	// si nunca inserto en hijo izquierdo o derecho , es porque ya existe
	else
	{
		check =  false;
	}
	return check;
}
template <class T>
void ArbolBinario<T>::inOrden(NodoBinario<T> *nod){
	if(nod->getHijoIzq() != nullptr){
		inOrden(nod->getHijoIzq());
	}

	cout << " " << nod->getDato();

	if(nod->getHijoDer() != nullptr){
		inOrden(nod->getHijoDer());
	}
	return;
}
template <class T>
void ArbolBinario<T>::posOrden(NodoBinario<T> *nod){
	if(nod->getHijoIzq()!=nullptr){
		posOrden(nod->getHijoIzq());
	}
	if(nod->getHijoDer()!=nullptr){
		posOrden(nod->getHijoDer());
	}
	cout<<nod->getDato()<<" ";
	return;
}
template <class T>
void ArbolBinario<T>::preOrden(NodoBinario<T> *nod) {
	cout<<nod->getDato()<<" ";
	if(nod->getHijoIzq()!=nullptr){
		preOrden(nod->getHijoIzq());
	}
	if(nod->getHijoDer()!=nullptr){
		preOrden(nod->getHijoDer());
	}
	return;
}
template <class T>
//Funcionamiento de Nivel Orden
void ArbolBinario<T>::nivelOrden(NodoBinario<T> *nod){
    //crea una cola en lugar de pasarla como parametro de entrada, 
    //al igual que utiliza un while en lugar de un for para su analisis
	queue<NodoBinario<T>> colaNivel;
	NodoBinario<T> nodo;
	colaNivel.push(*nod);
	
	while(!colaNivel.empty()){
	    //Por cada nivel
		nodo=colaNivel.front();
		//Primero la raiz
		colaNivel.pop();
		cout<<nodo.getDato()<<" ";
		//El valor a la izquierda
		if(nodo.getHijoIzq()!=nullptr){
			colaNivel.push(*nodo.getHijoIzq());
		}
		//El valor a la derecha
		if(nodo.getHijoDer()!=nullptr){
			colaNivel.push(*nodo.getHijoDer());
		}
	}
	return;
}
template <class T>
int ArbolBinario<T>::minValor(NodoBinario<T> *nodo)
{
    NodoBinario<T> *c = nodo;
    while(c &&c->getHijoIzq() != nullptr)
    {
        c = c->getHijoIzq();
    }
    return c->getDato();
}

template <class T>
NodoBinario<T>* ArbolBinario<T>::eliminar(T& val, NodoBinario<T> *nodo)
{
    bool check = false;
    if(nodo==nullptr)
    {
        return nodo;
    }
    if(val>nodo->getDato())
    {
        nodo->setHijoDer(eliminar(val,nodo->getHijoDer()));
    }
    else if(val<nodo->getDato())
    {
        nodo->setHijoIzq(eliminar(val,nodo->getHijoIzq()));
    }
    else
    {
        if(nodo->getHijoIzq()==nullptr)
        {
            NodoBinario<T> *ind = nodo->getHijoDer();
            delete nodo;
            return ind;
        }
        else if(nodo->getHijoDer()==nullptr)
        {
            NodoBinario<T> *ind = nodo->getHijoIzq();
            delete nodo;
            return ind;
        }
        int v = minValor(nodo->getHijoDer());
        nodo->setDato(v);
        nodo->setHijoDer(eliminar(val,nodo->getHijoDer()));
    }
    return nodo;
}
