/**
* Taller 3. Arboles
* Autores: Tomas Silva, Juan Pabon Vargas
* Arbol Quad-Tree
**/
#include <bits/stdc++.h>
#include "quadtree.h"

using namespace std;

int main(){

    Arbol<int> arbol({1,7});
    int borde = 8;
    arbol.setMaximo(borde);
    arbol.insertar({6,7}, borde);
    arbol.insertar({1,2}, borde);
    arbol.insertar({6,2}, borde);
    arbol.insertar({2,6}, borde);
    arbol.insertar({7,7}, borde);

    cout<<"El recorrido preOrden es: \n";
    arbol.preOrden();
    return 0;
}
