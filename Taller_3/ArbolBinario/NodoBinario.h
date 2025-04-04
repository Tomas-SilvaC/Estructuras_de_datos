/**
* Taller 3. Arboles
* Autores: Tomas Silva, Juan Pabon Vargas
* Nodo binario
**/
#ifndef __NODOBINARIO__H__
#define __NODOBINARIO__H__

using namespace std;

template< class T >
class NodoBinario
{
  public:
    T dato;
    NodoBinario<T> *hijoIzq;
    NodoBinario<T> *hijoDer;

  public:
  	NodoBinario();
    T& obtenerDato();
    void fijarDato(T& val);
    NodoBinario<T>* obtenerHijoIzq();
    NodoBinario<T>* obtenerHijoDer();
    void fijarHijoIzq(NodoBinario<T> *izq);
    void fijarHijoDer(NodoBinario<T> *der);
    int altura();
    void fijarNodo(NodoBinario<T> *del);
    int tamano();
    void insertar(T& val);
    NodoBinario<T>* buscar(T& val);
    void preOrden();
    void inOrden();
    void posOrden();
    void nivelOrden();
	NodoBinario<T>* extremo_izq();
	NodoBinario<T>* extremo_der();
};

#include "NodoBinario.hxx"
#endif
