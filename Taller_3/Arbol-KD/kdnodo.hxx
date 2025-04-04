/**
* Taller 3. Arboles
* Autores: Tomas Silva, Juan Pabon Vargas
* nodo KD
**/
#include "kdnodo.h"
#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

//Constructor
template<class T>
kdnodo<T>::kdnodo()
{
    this->hijoIzq = nullptr;
    this->hijoDer = nullptr;
    this->tag = 0;
}
//Get para dato
template<class T>
vector <T> kdnodo<T>::obtenerDato()
{
    return this->datos;
}
//Set para dato
template<class T>
void kdnodo<T>::fijarDato(vector <T>& val)
{
    this->datos = val;
}
//Set para el tag
template<class T>
void kdnodo<T>::fijarTag(int value)
{
    this->tag = value;
}
//Get del hijo izquierdo
template<class T>
kdnodo<T>* kdnodo<T>::obtenerHijoIzq()
{
    return this->hijoIzq;
}
//Get del hijo derecho
template<class T>
kdnodo<T>* kdnodo<T>::obtenerHijoDer()
{
    return this->hijoDer;
}
//Set del hijo izquierdo
template<class T>
void kdnodo<T>::fijarHijoIzq(kdnodo<T> *izq)
{
    this->hijoIzq = izq;
}
//Set del hijo derecho
template<class T>
void kdnodo<T>::fijarHijoDer(kdnodo<T> *der)
{
    this->hijoDer = der;
}
//Retorna la altura
template<class T>
int kdnodo<T>::altura()
{
	if(this->hijoIzq==NULL && this->hijoDer == NULL)
	{
		return 1;
	}
	if(this->hijoIzq==NULL)
		return this->hijoDer->altura();
	else if(this->hijoDer==NULL)
		return this->hijoIzq->altura();


	return max(this->hijoIzq->altura(), this->hijoDer->altura());
}

//Retorna el tamaño
template<class T>
int kdnodo<T>::tamano()
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
//Inserta un valor al arbol
template<class T>
void kdnodo<T>:: insertar(vector <T> &val)
{

	if(val[this->tag] >= this->datos[this->tag])
  {
		if(this->hijoDer == NULL)
		{
			kdnodo* nuevo= new kdnodo();
            nuevo->fijarTag((this->tag+1)%val.size());
			nuevo->fijarDato(val);
			this->fijarHijoDer(nuevo);
		}
		else
		{
			this->hijoDer->insertar(val);
		}
	}

	if(val[this->tag] < this->datos[this->tag])
  {
		if(this->hijoIzq == NULL)
		{
            kdnodo* nuevo= new kdnodo();
            nuevo->fijarTag((this->tag+1)%val.size());
			nuevo->fijarDato(val);
			this->fijarHijoIzq(nuevo);
		}
		else
		{
			this->hijoIzq->insertar(val);
		}
	}

}

//Busca un valor del arbol
template<class T>
kdnodo<T>* kdnodo<T>:: buscar(vector <T>& val)
{
	if(this->iguales(val))
    {
		return this;
	}

	if(val[this->tag] < this->datos[this->tag])
    {
		return this->hijoIzq->buscar(val);
	}
	else
    {
		return this->hijoDer->buscar(val);
	}
}
//Revisa si el dato es igual al valor
template<class T>
bool kdnodo<T>::iguales(vector <T>& val)
{
  for(int i = 0 ; i < val.size() ; ++i)
  {
    if(this->datos[i] != val[i])
    {
      return false;
    }
  }
  return true;
}

//Imprime PreOrder
template<class T>
void kdnodo<T>:: preOrden()
{
this->imprimir();
  if(this->hijoIzq != NULL)
		this->hijoIzq->preOrden();
	if(this->hijoDer != NULL)
		this->hijoDer->preOrden();
	return;
}

//Imprime InOrder
template<class T>
void kdnodo<T>:: inOrden()
{
	if(this->hijoIzq != NULL)
		this->hijoIzq->inOrden();

    this->imprimir();

	if(this->hijoDer != NULL)
		this->hijoDer->inOrden();
	return;

}


//Imprime PosOrder
template<class T>
void kdnodo<T>:: posOrden()
{
	if(this->hijoIzq != NULL)
		this->hijoIzq->posOrden();

	if(this->hijoDer != NULL)
		this->hijoDer->posOrden();

    this->imprimir();
    return;
}

//Imprime NivelOrder
template<class T>
void kdnodo<T>:: nivelOrden()
{
	queue<kdnodo*> cola;
	cola.push(this);
	while(!cola.empty()){
		cola.front()->imprimir();
		if(cola.front()->hijoIzq != NULL){
			cola.push(cola.front()->hijoIzq);
		}

		if(cola.front()->hijoDer != NULL){
			cola.push(cola.front()->hijoDer);
		}
		cola.pop();
	}
}

//Retorna el maximo del arbol
template<class T>
void kdnodo<T>:: maximo(int &maxi)
{
	if(maxi < this->obtenerDato())
	{
		maxi = this->obtenerDato();
	}
	if(this->hijoIzq != NULL)
		this->hijoIzq->maximo(maxi);

	if(this->hijoDer != NULL)
		this->hijoDer->maximo(maxi);
	return;

}

//Retorna el minimo del arbol
template<class T>
void kdnodo<T>:: minimo(int &mini)
{
	if(mini > this->obtenerDato())
	{
		mini = this->obtenerDato();
	}
	if(this->hijoIzq != NULL)
		this->hijoIzq->minimo(mini);

	if(this->hijoDer != NULL)
		this->hijoDer->minimo(mini);
	return;

}

//Genera la impresion
template<class T>
void kdnodo<T>:: imprimir()
{
  cout<<"( ";
  for(int i = 0 ; i < this->datos.size() ; ++i)
  {
    cout<<this->datos[i];
    if(i!=this->datos.size()-1)
      cout<<", ";

  }
  cout<<" )\n";
}
