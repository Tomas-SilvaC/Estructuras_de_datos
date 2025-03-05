/******************************************************************************
Tomas Silva
Laboratorio de Arbol binario
5 de Marzo de 2025
*******************************************************************************/

#include <iostream>
#include "ModArbol/ModArbol.h"
using namespace std;

int main()
{
    //Construye el arbol de Prueba
    struct nodo *arbol0=new nodo(7);
    arbol0->left =new nodo(3);
    arbol0->right =new nodo(20);
    arbol0->left->left =new nodo(0);
    arbol0->left->right =new nodo(5);
    arbol0->left->left->left =new nodo(-3);
    arbol0->left->left->right =new nodo(1);
    arbol0->left->right->left =new nodo(4);
    arbol0->left->right->right =new nodo(6);
    arbol0->right->left =new nodo(15);
    arbol0->right->right =new nodo(25);
    arbol0->right->right->right =new nodo(30);

    //Realiza los procesos
    cout<< endl <<"InOrden: ";
    InOrder (arbol0);
    
    cout<< endl <<"PreOrden: ";
    PreOrder (arbol0);
    
    cout<< endl <<"PostOrden: ";
    PostOrder (arbol0);
    
    
    return 0;
}
