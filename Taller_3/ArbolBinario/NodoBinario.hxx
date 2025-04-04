/**
* Taller 3. Arboles
* Autores: Tomas Silva, Juan Pabon Vargas
* Nodo binario
**/
#include "NodoBinario.h"
#include <bits/stdc++.h>

using namespace std;


//Constructor por defecto 
template<class T>
NodoBinario<T>::NodoBinario()
{
    this->hijoIzq=NULL;
    this->hijoDer=NULL;
}
//Getter del atributo de nombre dato
template<class T>
T& NodoBinario<T>::obtenerDato()
{
    return this->dato;
}
//Setter del atributo de nombre dato
template<class T>
void NodoBinario<T>::fijarDato(T& val)
{
    this->dato = val;
}
//Getter del apuntador al hijo izquierdo
template<class T>
NodoBinario<T>* NodoBinario<T>::obtenerHijoIzq()
{
    return this->hijoIzq;
}
//Getter del apuntador al hijo derecho
template<class T>
NodoBinario<T>* NodoBinario<T>::obtenerHijoDer()
{
    return this->hijoDer;
}
//Setter del hijo izquierdo del nodo
template<class T>
void NodoBinario<T>::fijarHijoIzq(NodoBinario<T> *izq)
{
    this->hijoIzq = izq;
    return;
}
//Setter del hijo derecho del nodo
template<class T>
void NodoBinario<T>::fijarHijoDer(NodoBinario<T> *der)
{
    this->hijoDer = der;
    return;
}
//retorna la altura del nodo
template<class T>
int NodoBinario<T>::altura()
{
	if(this->hijoIzq==NULL && this->hijoDer == NULL)
	{
		return 1;
	}
	if(this->hijoIzq==NULL)
		return this->hijoDer->altura();
	else if(this->hijoDer==NULL)
		return this->hijoIzq->altura();


	return max(this->hijoIzq->altura() , this->hijoDer->altura());
}

//retorna la cantidad de nodos en el arbol
template<class T>
int NodoBinario<T>::tamano()
{
	if(this->hijoIzq==NULL && this->hijoDer == NULL)
	{
		return 1;
	}
	if(this->hijoIzq==NULL)
		return this->hijoDer->tamano() +1 ;
	else if(this->hijoDer==NULL)
		return this->hijoIzq->tamano() +1 ;


	return this->hijoIzq->tamano() + this->hijoDer->tamano() +1 ;
}
//inserta un nodo con el valor val
template<class T>
void NodoBinario<T>:: insertar(T& val)
{

	if(val > this->obtenerDato()){
		if(this->hijoDer==NULL)
		{
			NodoBinario* nuevo= new NodoBinario();
			nuevo->fijarDato(val);
			this->fijarHijoDer(nuevo);
		}
		else
		{
			this->hijoDer->insertar(val);
		}
	}

	if(val < this->obtenerDato()){
		if(this->hijoIzq==NULL)
		{
			NodoBinario* nuevo= new NodoBinario();
			nuevo->fijarDato(val);
			this->fijarHijoIzq(nuevo);
		}
		else
		{
			this->hijoIzq->insertar(val);
		}
	}

}

//busca el nodo con valor val
template<class T>
NodoBinario<T>* NodoBinario<T>:: buscar(T& val)
{
	if(this->obtenerDato()==val){
		return this;
	}

	if(val < this-> obtenerDato()){
        if(this->hijoIzq != NULL)
            return this->hijoIzq->buscar(val);
        else
            return NULL;
	}
	else{
        if(this->hijoDer != NULL)
            return this->hijoDer->buscar(val);
        else
            return NULL;
	}
}

//Retorna un apuntador al nodo que mas se encuentra a la derecha
template<class T>
NodoBinario<T>* NodoBinario<T>::extremo_der()
{
    if(this->hijoDer != NULL)
        return this->hijoDer->extremo_der();
    else
        return this;
}
//Retorna un apuntador al nodo que se encuentra mas a la izquierda
template<class T>
NodoBinario<T>* NodoBinario<T>::extremo_izq()
{
    if(this->hijoIzq != NULL)
        return this->hijoIzq->extremo_izq();
    else
        return this;
}

//Imprime los recorridos del arbol
template<class T>
void NodoBinario<T>:: preOrden()
{
	cout << "\t"<<this->obtenerDato() << endl;
	if(this->hijoIzq != NULL)
		this->hijoIzq->preOrden();
	if(this->hijoDer != NULL)
		this->hijoDer->preOrden();
	return;
}


template<class T>
void NodoBinario<T>:: inOrden()
{
	if(this->hijoIzq != NULL)
		this->hijoIzq->inOrden();

	cout << "\t"<<this->obtenerDato() << endl;

	if(this->hijoDer != NULL)
		this->hijoDer->inOrden();
	return;

}



template<class T>
void NodoBinario<T>:: posOrden()
{
	if(this->hijoIzq != NULL)
		this->hijoIzq->posOrden();

	if(this->hijoDer != NULL)
		this->hijoDer->posOrden();

	cout << "\t"<<this->obtenerDato() << endl;
	return;

}


template<class T>
void NodoBinario<T>:: nivelOrden()
{
	queue<NodoBinario*> cola;
	cola.push(this);
	while(!cola.empty()){
		cout<<"\t"<<cola.front()->obtenerDato()<<endl;
		if(cola.front()->hijoIzq != NULL){
			cola.push(cola.front()->hijoIzq);
		}

		if(cola.front()->hijoDer != NULL){
			cola.push(cola.front()->hijoDer);
		}
		cola.pop();
	}
}
