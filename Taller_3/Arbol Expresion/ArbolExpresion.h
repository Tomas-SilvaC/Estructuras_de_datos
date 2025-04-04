/**
* Taller 3. Arboles
* Autores: Tomas Silva, Juan Pabon Vargas
* Arbol Expresión
**/
#ifndef ARBOLEXPRESION_H
#define  ARBOLEXPRESION_H
#include "NodoExpresion.h"
#include <string>

using namespace std;

class ArbolExpresion {
  protected:
    NodoExpresion* raiz;
public:
    ArbolExpresion();
    ~ArbolExpresion();
    NodoExpresion* getRaiz();
    void setRaiz(NodoExpresion* nod);

    void llenarDesdePrefija(string &expresion);
    void llenarDesdePosfija (string &expresion);

    void  obtenerPrefija(NodoExpresion* inicio);
    void  obtenerInfija(NodoExpresion* inicio);
    void  obtenerPosfija(NodoExpresion* inicio);
    int evaluar(NodoExpresion* nodi);
    bool siOperando(char car);
};
#include "ArbolExpresion.hxx"

#endif

