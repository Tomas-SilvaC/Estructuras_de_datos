/**
* Taller 3. Arboles
* Autores: Tomas Silva, Juan Pabon Vargas
* Arbol binario ordenado
**/
#include "ArbolBinario.h"
#include "NodoBinario.h"
#include <iostream>
using namespace std;

int main(){
    ArbolBinario<int> arbol;
    string data = "";
    int dato = 1;
    //insercion de datos
    while(true){
        cout<<"Que operacion quiere realizar: A (insertar dato), B (eliminar dato), C (finalizar):";
        cin>>data;
        if(data == "C"){
            break;
        }
        else if(data=="A"||data=="a")
        {
            cout<<"Ingrese el dato: ";
            cin>>dato;
            arbol.insertar(dato, arbol.getRaiz());
        }
        else if(data=="B"||data=="b")
        {
            cout<<"Ingrese el dato que quiere eliminar: ";
            cin>>dato;
            arbol.eliminar(dato, arbol.getRaiz());
        }
        
    }
    // Impresion de recorrido
    cout<<"\nEl recorrido inOrdene es: \n";
    arbol.inOrden(arbol.getRaiz());
    cout<<"\nEl recorrido posOrden es: \n";
    arbol.posOrden(arbol.getRaiz());
    cout<<"\nEl recorrido preOrden es: \n";
    arbol.preOrden(arbol.getRaiz());
    cout<<"\nEl recorrido levelOrden es: \n";
    arbol.nivelOrden(arbol.getRaiz());
    int b = 11;

    
    return 0;
}
