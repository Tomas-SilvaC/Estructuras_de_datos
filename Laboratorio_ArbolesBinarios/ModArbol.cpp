#include <iostream>
#include "ModArbol.h"
using namespace std;

//Para cada algoritmo:
//primero revisara que el nodo exista, con tal de permitir la impresion
//De no ser null, imprime en el orden correspondiente haciendo uso de recursion

//Pre
//Imprime primero la raiz, luego el dato a su izquierda y luego a su derecha
void PreOrder (struct nodo *nod){
    if(nod==nullptr){
        return;
    }
    cout<< nod->dato <<"->";
    PreOrder(nod->left);
    PreOrder(nod->right);
}

//Post
//Imprime primero el dato a la izquierda, luego el dato a su derecha y luego la raiz
void PostOrder (struct nodo *nod){
    if(nod==nullptr){
        return;
    }
    PostOrder(nod->left);
    PostOrder(nod->right);
    cout<< nod->dato <<"->";
}

//In
//Imprime primero el dato a la izquierda, luego la raiz y luego el dato a su derecha 
void InOrder (struct nodo *nod){
    if(nod==nullptr){
        return;
    }
    InOrder(nod->left);
    cout<< nod->dato <<"->";
    InOrder(nod->right);
    
}
