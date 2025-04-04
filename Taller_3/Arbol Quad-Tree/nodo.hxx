/**
* Taller 3. Arboles
* Autores: Tomas Silva, Juan Pabon Vargas
* nodo Quad-Tree
**/
#include "nodo.h"
#include <bits/stdc++.h>

using namespace std;
//Constructores con y sin valor
template<class T>
Nodo<T>::Nodo()
{

    this->NW = NULL;
    this->NE = NULL;
    this->SW = NULL;
    this->SE = NULL;
}

template<class T>
Nodo<T>::Nodo(pair<T,T> val)
{
    this->dato = val;
    this->NW = NULL;
    this->NE = NULL;
    this->SW = NULL;
    this->SE = NULL;
}

//Get y set para dato
template<class T>
pair<T,T> Nodo<T>::obtenerDato()
{
    return this->dato;
}

template<class T>
void Nodo<T>::fijarDato(pair<T,T> val)
{
    this->dato = val;
    return;
}
//Retorna la altura del arbol
template<class T>
int Nodo<T>::altura()
{
    if(NW == NULL && NE == NULL && SW == NULL && SE == NULL )
        return 1;

    int mayor=0,actual;
    if(NW != NULL)
    {
        actual= this->NW->altura()+1;
        if(actual>mayor)
            mayor=actual;
    }
    if(NE != NULL)
    {
        actual = this->NE->altura()+1;
        if(actual>mayor)
            mayor=actual;
    }
    if(SW != NULL)
    {
        actual = this->SW->altura()+1;
        if(actual>mayor)
            mayor=actual;
    }
    if(SE != NULL)
    {
        actual = this->SE->altura()+1;
        if(actual>mayor)
            mayor=actual;
    }
}

//Retorna el tamaño del arbol
template<class T>
int Nodo<T>::tamano()
{
    if(NW == NULL && NE == NULL && SW == NULL && SE == NULL )
        return 1;

    int cont=0;
    if(NW != NULL)
    {
        cont+= this->NW->altura()+1;
    }
    if(NE != NULL)
    {
        cont+= this->NE->altura()+1;
    }
    if(SW != NULL)
    {
        cont+= this->SW->altura()+1;
    }
    if(SE != NULL)
    {
        cont+= this->SE->altura()+1;
    }
    return cont;
}
//Inserta en el arbol
template<class T>
void Nodo<T>:: insertar(pair<T,T> val, int max)
{
    cout<<"this is the pair that was entered: "<<val.first<<","<<val.second<<endl;
    /*Norte*/
    if(this->dato.first < val.first)
    {
        if(this->dato.second < val.second)
        {
            if(this->NE!= NULL)
            {
                this->NE->insertar(val, max);
            }
            else
            {
                cout<<"NE: ";
                Nodo<T>* nuevo = new Nodo();
                nuevo->fijarDato(val);
                cout<<nuevo->dato.first<<","<<nuevo->dato.second;
                this->NE = nuevo;
            }
        }
        else
        {
            if(this->SE!= NULL)
            {
                this->SE->insertar(val, max);
            }
            else
            {
                cout<<"SE: ";
                Nodo<T>* nuevo = new Nodo();
                nuevo->fijarDato(val);
                cout<<nuevo->dato.first<<","<<nuevo->dato.second;
                this->SE = nuevo;
            }
        }
    }

    /*Sur*/
    if(this->dato.first > val.first )
    {
        if(this->dato.second < val.second)
        {
            if(this->NW!= NULL)
            {
                this->NW->insertar(val, max);
            }
            else
            {
                cout<<"NW: ";
                Nodo<T>* nuevo = new Nodo();
                nuevo->fijarDato(val);
                cout<<nuevo->dato.first<<","<<nuevo->dato.second;
                this->NW = nuevo;
            }
        }
        else
        {
            if(this->SW!= NULL)
            {
                this->SW->insertar(val, max);
            }
            else
            {
                cout<<"SW: ";
                Nodo<T>* nuevo = new Nodo();
                nuevo->fijarDato(val);
                cout<<nuevo->dato.first<<","<<nuevo->dato.second;
                this->SW = nuevo;
            }
        }
    }
}
//Busca en el arbol
template<class T>
Nodo<T>* Nodo<T>:: buscar(pair<T,T> val)
{
    if(this->dato == val)
        return this;
    if(NW == NULL && NE == NULL && SW == NULL && SE == NULL )
        return NULL;

    if(this->dato.first < val.first)
    {
        if(this->dato.second < val.second)
        {
            if(this->NE!= NULL)
            {
                return this->NE->buscar(val);
            }
            else
            {
                return NULL;
            }
        }
        else
        {
            if(this->SE!= NULL)
            {
                return this->SE->buscar(val);
            }
            else
            {
                return NULL;
            }
        }
    }

    /*Sur*/
    if(this->dato.first > val.first )
    {
        if(this->dato.second < val.second)
        {
            if(this->NW!= NULL)
            {
                return this->NW->buscar(val);
            }
            else
            {
                return NULL;
            }
        }
        else
        {
            if(this->SW!= NULL)
            {
                return this->SW->buscar(val);
            }
            else
            {
                return NULL;
            }
        }
    }

    return NULL;

}
//Imprime PreOrder
template<class T>
void Nodo<T>:: preOrden()
{
    cout << "("<<this->dato.first<<','<<this->dato.second <<")"<< endl;
    if(this->NW !=NULL)
        this->NW->preOrden();
    if(this->NE !=NULL)
        this->NE->preOrden();
    if(this->SW !=NULL)
        this->SW->preOrden();
    if(this->SE !=NULL)
        this->SE->preOrden();

    return;
}




//Imprime en posOrder
template<class T>
void Nodo<T>:: posOrden()
{
    if(this->NW !=NULL)
        this->NW->preOrden();
    if(this->NE !=NULL)
        this->NE->preOrden();
    if(this->SW !=NULL)
        this->SW->preOrden();
    if(this->SE !=NULL)
        this->SE->preOrden();

    cout << "("<<this->dato.first<<','<<this->dato.second <<")"<< endl;
    return;

}




