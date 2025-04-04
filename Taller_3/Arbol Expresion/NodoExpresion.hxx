/**
* Taller 3. Arboles
* Autores: Tomas Silva, Juan Pabon Vargas
* nodo Expresión
**/
#include "NodoExpresion.h"
#include <string>

using namespace std;
//Constructores 
NodoExpresion::NodoExpresion(){
	this->hijoIzq=nullptr;
	this->hijoDer=nullptr;
}
NodoExpresion::~NodoExpresion(){
}
//Get y set para dato
char NodoExpresion::getDato(){
	return this->dato;
}

void NodoExpresion::setDato(char val){
	this->dato=val;
	return;
}
//Get y set para los hijos derecho e izquierdo
NodoExpresion* NodoExpresion::getHijoIzq(){
	return this->hijoIzq;
}

NodoExpresion* NodoExpresion::getHijoDer(){
	return this->hijoDer;
}

void NodoExpresion::setHijoDer(NodoExpresion* der){
	this->hijoDer=der;
	return;
}

void NodoExpresion::setHijoIzq(NodoExpresion* izq){
	this->hijoIzq=izq;
	return;
}
//Get y set para el operando
void NodoExpresion::setOperando(bool op){
	this->operando=op;
	return;
}
bool NodoExpresion::getOperando(){
	return this->operando;
}


