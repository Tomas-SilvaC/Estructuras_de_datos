/**
* Taller 3. Arboles
* Autores: Tomas Silva, Juan Pabon Vargas
* Arbol
**/
#include <iostream>
#include <string>
/*#include <bits/stdc++.h>*/
#include "arbol.h"

using namespace std;

int main(){
    //se crea un arbol con una raiz de 5.
    Arbol<int> arbol(5);
    //se insertan los datos en formato (padre, hijo)
    arbol.insertarNodo(5,6);
    arbol.insertarNodo(5,7);
    arbol.insertarNodo(5,8);

    arbol.insertarNodo(6,9);
    arbol.insertarNodo(6,10);
    arbol.insertarNodo(7,11);
    //impresion de recorridos
    cout<<"\nthis next one is preOrden:\n";
    arbol.preOrden();
    cout<<"\nthis next one is posOrden:\n";
    arbol.posOrden();
    cout<<"\nthis next one is eliminar:\n";
    // Eliminacion de un nodo
    arbol.eliminarNodo(11,7);
    cout<<"\nthis next one is nivelOrden:\n";
    arbol.nivelOrden();
    cout<<"\nthis next one is altura:\n";
    cout<<arbol.altura();
    cout<<"\nthis next one is tamano:\n";
    cout<<arbol.tamano();
    cout<<"\nthis next one is the raiz:\n";
    cout<<arbol.obtenerRaiz();
    cout<<"\nthis next one is new raiz:\n";
    Nodo<int>* root =new  Nodo<int>(5);
    //obtener la raiz
    cout<<arbol.obtenerRaiz();
    cout<<"\n";
    arbol.nivelOrden();
    //se cambia el dato del nodo (val a remplazar, val de nodo)
    cout<<"\nfijar dato:\n";
    arbol.fijarDato(4,5);
    cout<<"\n";
    arbol.nivelOrden();
}
