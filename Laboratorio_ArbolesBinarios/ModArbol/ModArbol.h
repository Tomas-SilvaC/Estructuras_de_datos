#ifndef _MODARBOL_H
#define _MODARBOL_H
#include <iostream>
//nodo
//El nodo contiene un valor y dos nodos que pueden ser nodos hoja o tener hijos
struct nodo{
    int dato;
    struct nodo *left, *right;
    //Contstructor del nodo
    nodo(int dato){
        this->dato = dato;
        //inicia sin tener nada dentro de los nodos hijos, iniciando como nodo hoja
        left = right = nullptr;
    }
};
//Pre
void PreOrder (struct nodo *nod);

//Post
void PostOrder (struct nodo *nod);

//In
void InOrder (struct nodo *nod);
#endif
