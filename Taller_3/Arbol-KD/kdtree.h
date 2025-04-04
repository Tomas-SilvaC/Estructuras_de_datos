/**
* Taller 3. Arboles
* Autores: Tomas Silva, Juan Pabon Vargas
* Arbol KD
**/
#ifndef __KDTREE__H__
#define __KDTREE__H__

#include "kdtree.h"
#include "kdnodo.h"
using namespace std;

template<class T>
class kdtree {
  protected:
    kdnodo<T> *raiz;
public:
	kdtree();
    bool esVacio();
    T& datoRaiz();
    int altura();
    int tamano();
    void insertar(vector <T> &val);
    kdnodo<T>*  buscar(T& val);
    void preOrden();
    void inOrden();
    void posOrden();
    void nivelOrden();
    void maximo(int &maxi);
    void minimo(int &mini);
};

#include "kdtree.hxx"
#endif
