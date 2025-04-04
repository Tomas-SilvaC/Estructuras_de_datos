/**
* Taller 3. Arboles
* Autores: Tomas Silva, Juan Pabon Vargas
* Nodo
**/
#ifndef __NODO__H__
#define __NODO__H__

#include <queue>
#include <vector>//para usar vectores, se necesita la libreria de vectores
using namespace std;

template< class T >
class Nodo{
  protected:
    T dato;
    vector<Nodo <T>* > hijos;

  public:
  	Nodo();
  	Nodo(T valor);
  	int altura();
  	int tamano();
    T& obtenerDato();
    void fijarDato(T& val);
    void limpiarLista();
    void adicionarDesc(T& val);
    bool eliminarDesc(T &val, T &padre);
    void preOrden();
    void posOrden();
    void nivelOrden(std::queue<Nodo<T>*> &cola);
    Nodo* buscar(T val);
};

#include "nodo.hxx"
#endif
