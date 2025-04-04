/**
* Taller 3. Arboles
* Autores: Tomas Silva, Juan Pabon Vargas
* Arbol AVL
**/
#include<iostream>
#include "ArbolBinarioAVL.h"
#include "NodoBinarioAVL.h"

using namespace std;

int main(int argc, char* argv[])
{
    ArbolBinarioAVL<int> arbolito;
	while(true)
	{
		int dato;
		char op;
		//Se selecciona que accion quiere tomar
		cout<<endl<<"Digite si desea agregar (A), eliminar (E) o finalizar (F): ";
		cin>>op;
		
		if(op == 'A' || op == 'a' || op == 'E' || op == 'e' || op == 'F' || op == 'f'){
    		if(op == 'A' || op == 'a'){
			//se ingresa el nodo
    		    cout<<"Ahora digite el valor a agregar: ";
    		    cin>>dato;	
    			arbolito.insertar(dato);
    		}
    		else if(op == 'E' || op == 'e'){
    		    cout<<"Ahora digite el valor a eliminar: ";
    		    cin>>dato;	
			//se elimina el nodo
    			arbolito.eliminar(dato);
    		}
		//termina de preguntar
    		else if(op == 'F' || op == 'f')
    			break;
		}
		else
		    cout<<"El valor no es posible digite nuevamente"<<endl;
		   
	}
	//Impresion de recorridos
	cout << endl << "Inorden: " << endl;
	arbolito.inOrden(arbolito.getRaiz());
	cout << endl << "PreOrden: " << endl;
	arbolito.preOrden(arbolito.getRaiz());
	cout << endl <<"Preorden: " << endl;
	arbolito.posOrden(arbolito.getRaiz());
	cout << endl <<"NivelOrden: " << endl;
	arbolito.nivelOrden(arbolito.getRaiz());
	cout << endl <<"altura: " << endl;
	cout<<arbolito.altura(arbolito.getRaiz());
	return 0;
}
