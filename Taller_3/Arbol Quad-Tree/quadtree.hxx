/**
* Taller 3. Arboles
* Autores: Tomas Silva, Juan Pabon Vargas
* Arbol Quad-Tree
**/
#include <bits/stdc++.h>
#include "quadtree.h"

using namespace std;
//COnstructores con y sin datos
template<class T>
Arbol<T>::Arbol()
{
    Nodo<T>* root = NULL;
}

template<class T>
Arbol<T>::Arbol(pair<T,T> val)
{
    Nodo<T>* root =new  Nodo<T>(val);
    this->raiz=root;
}
/*
template<class T>
Arbol<T>::~Arbol()
{
    delete(this->raiz);
}
*/
//revisa si el arbol esta vacio
template<class T>
bool Arbol<T>:: esVacio()
{
    if(this->raiz==NULL)
        return true;
    return false;
}
//Get y set para raiz
template<class T>
pair<T,T> Arbol<T>:: obtenerRaiz()
{
    return this->raiz;
}

template<class T>
void Arbol<T>::fijarRaiz(Nodo<T>* root)
{
    this->raiz = root;
}
//Retorna la altura del arbol
template<class T>
int Arbol<T>:: altura()
{
    return this->raiz->altura();
}
//Retorna el tamaño del arbol
template<class T>
int Arbol<T>:: tamano()
{
    return this->raiz->tamano();
}
//Inserta nodo en el arbol
template<class T>
void Arbol<T>:: insertar(pair<T,T> val, int max)
{
    this->raiz->insertar(val, max);
}
//Busca en el arbol
template<class T>
Nodo<T>* Arbol<T>::  buscar(pair<T,T> val)
{
    return this->raiz->buscar(val);
}
//Imprime preOrden
template<class T>
void Arbol<T>:: preOrden()
{
    this->raiz->preOrden();
}

//Imprime posorden
template<class T>
void Arbol<T>:: posOrden()
{
    this->raiz->posOrden();
}
//Retorna el nodo maximo del arbol
template<class T>
int Arbol<T>::getMaximo()
{
    return this->maximo;
}
//Retorna el nodo minimo del arbol
template<class T>
void Arbol<T>::setMaximo(int max)
{
    this->maximo = max;
}

