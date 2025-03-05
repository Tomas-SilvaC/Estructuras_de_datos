/******************************************************************************
Tomas Silva
Laboratorio de Arbol binario
5 de Marzo de 2025
*******************************************************************************/

#include <iostream>
#include "ModArbol.h"
using namespace std;

int main()
{
    struct nodo *arbol0=new nodo(23);
    arbol0->left =new nodo(2);
    arbol0->right =new nodo(42);
    arbol0->left->left =new nodo(-1);
    arbol0->left->right =new nodo(8);
    
    cout<< endl <<"PreOrden: ";
    PreOrder (arbol0);
    cout<< endl <<"PostOrden: ";
    PostOrder (arbol0);
    cout<< endl <<"InOrden: ";
    InOrder (arbol0);
    
    return 0;
}
