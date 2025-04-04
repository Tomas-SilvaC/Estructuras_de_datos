/**
* Taller 3. Arboles
* Autores: Tomas Silva, Juan Pabon Vargas
* Nodo
**/
#include <iostream>
#include "nodo.h"

using namespace std;

//constructor por defecto
template<class T>
Nodo<T>::Nodo()
{

}
//Constructor con valor
template<class T>
Nodo<T>::Nodo(T valor)
{
    this->dato = valor;
}
//Getter del atributo dato
template<class T>
T& Nodo<T>::obtenerDato()
{
    return this->dato;
}
//Setter de atrbuto dato
template<class T>
void Nodo<T>::fijarDato(T& val)
{
    this->dato = val;
    return;
}


//Devuelve la altura del arbol
template<class T>
int Nodo<T>::altura()
{
	if(hijos.size()==0)
	{
		return 1;
	}
	int maximo = 0, aux_altura;
	for(int i = 0;i<hijos.size() ; i++){
	    aux_altura = hijos[i]->altura();
        if(aux_altura> maximo)
            maximo = aux_altura;
	}
	return maximo + 1;
}

//devuelve la cantidad de nodos que poseen los subarboles
template<class T>
int Nodo<T>::tamano()
{
	if(this->hijos.size()==0)
	{
		return 1;
	}
	int conta = 0;
	for( int i = 0; i<hijos.size() ; ++i){
        conta+=hijos[i]->tamano();
	}
	return conta+1;
}

//borra la lista de hijos
template<class T>
void Nodo<T>:: limpiarLista()
{
    if(hijos.size()==0){
        delete(this);
        return;

    }

    for(int i=0; i<hijos.size(); i++){
        hijos[i].limpiarLista();
    }

}


//agrega un nodo descendiente
template<class T>
void Nodo<T>:: adicionarDesc(T &val)
{
    Nodo* hijo = new Nodo(val);
    hijos.push_back(hijo);
}

//elimina un nodo en especifico
template<class T>
bool Nodo<T>:: eliminarDesc(T &val, T &padre){
    Nodo* aux;
    int i = 0;
    for(i = 0; i<hijos.size() ; i++){
        if(hijos[i]->obtenerDato()==val)
        {
            break;
        }
    }
    if(!hijos[i]->hijos.empty())
    {
        int countHijos = hijos[i]->hijos.size();
        for(int j=0;j<countHijos;j++)
        {
           hijos.push_back(hijos[i]->hijos[j]);
        }
        for(int l = 0;l<hijos.size();l++)
        {
            if(hijos[l]->obtenerDato()==val)
            {
                Nodo* n = hijos[l];
                hijos.erase(hijos.begin()+l);
                hijos.push_back(n);
                break;
            }
        }
    }
    hijos.pop_back();
    
    return true;
}


template<class T>
Nodo<T>* Nodo<T>:: buscar(T val){
    if(this->dato == val)
        return this;
    if(this->hijos.size() == 0)
        //cout<<"not found";
        return NULL;
    Nodo* aux;
    for(int i = 0; i<hijos.size() ; i++){
        aux = hijos[i]->buscar(val);
        if(aux!=NULL)
            return aux;
    }
    //cout<<"not found";
    return NULL;

}

template<class T>
void Nodo<T>:: preOrden()
{
	cout << "\t"<<this->obtenerDato() << endl;
	for(int i = 0; i < hijos.size() ; i++){
        hijos[i]->preOrden();
	}
	return;
}

template<class T>
void Nodo<T>:: posOrden()
{
	for(int i = 0; i < hijos.size() ; i++){
        hijos[i]->posOrden();
	}

	cout << "\t"<<this->obtenerDato() << endl;
	return;

}

template<class T>
void Nodo<T>::nivelOrden(std::queue<Nodo<T>*> &cola) {
    cola.push(this); // Start with the root node

    while (!cola.empty()) {
        Nodo<T>* current = cola.front();
        cola.pop();

        cout << current->obtenerDato() << " ";

        // Enqueue all children
        for (size_t i = 0; i < current->hijos.size(); i++) {
            cola.push(current->hijos[i]);
        }
    }

    cout << std::endl;
    return;
}





