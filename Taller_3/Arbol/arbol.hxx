/**
* Taller 3. Arboles
* Autores: Tomas Silva, Juan Pabon Vargas
* Arbol
**/
#include <iostream>
#include <queue>
#include "arbol.h"

using namespace std;

//Constructor por defecto
template<class T>
Arbol<T>::Arbol()
{
    Nodo<T>* root = NULL;
}
//Constructor por valor
template<class T>
Arbol<T>::Arbol(T val)
{
    Nodo<T>* root =new  Nodo<T>(val);
    this->raiz=root;
}
//revisa si el arbol esta vacio. Retorna true si lo esta, retorna false si no lo esta
template<class T>
bool Arbol<T>:: esVacio()
{
    if(this->raiz==NULL)
        return true;
    return false;
}

//devuelve la raiz
template<class T>
T Arbol<T>:: obtenerRaiz()
{
    return this->raiz->obtenerDato();
}

//setter de la raiz
template<class T>
void Arbol<T>::fijarRaiz(Nodo<T>* root)
{
    this->raiz = root;
}
//setter del dato del nodo
template<class T>
void Arbol<T>::fijarDato(T val, T valNodo)
{
    Nodo<T>* aux = this->raiz->buscar(valNodo);
    if(aux == NULL)
        cout<<"no se encuentra el nodo con ese valor";
    else{
        aux->fijarDato(val);
    }
    
}

//devuelve la altura total del arbol
template<class T>
int Arbol<T>:: altura()
{
    return this->raiz->altura();
}

//devuelve el tamano del arbol
template<class T>
int Arbol<T>:: tamano()
{
    return this->raiz->tamano();
}

//se inserta un nodo dado el padre del nodo que se va insertar
template<class T>
bool Arbol<T>:: insertarNodo(T padre, T val)
{
    Nodo<T>* aux = this->raiz->buscar(padre);
    if(aux == NULL)
        return false;
    aux->adicionarDesc(val);
    return true;
}

//se elimina un nodo dado el padre del nodo que se va eliminar
template<class T>
bool Arbol<T>:: eliminarNodo(T val, T padre)
{   
    Nodo<T>* aux = this->raiz->buscar(padre);
    if(aux == NULL)
        return false;
    return aux->eliminarDesc(val, padre);
}

//retorna un apuntador al nodo con el valor val
template<class T>
Nodo<T>* Arbol<T>::  buscar(T val)
{
    return this->raiz->buscar(val);
}

//imprime el recorrido preOrden
template<class T>
void Arbol<T>:: preOrden()
{
    this->raiz->preOrden();
}
//imprime el recorrido inOrden
template<class T>
void Arbol<T>:: inOrden()
{
    this->raiz->inOrden();
}
//imprime el recorrido posOrden
template<class T>
void Arbol<T>:: posOrden()
{
    this->raiz->posOrden();
}
//imprime el recorrido nivelOrden
template<class T>
void Arbol<T>:: nivelOrden()
{
    queue <Nodo <T>*> col;
    this->raiz->nivelOrden(col);
}

