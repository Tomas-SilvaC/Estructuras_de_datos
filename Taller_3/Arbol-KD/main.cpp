 #include<iostream>
#include<set>
#include<map>
#include "kdtree.h"
#include "kdnodo.h"

using namespace std;

int main(int argc, char* argv[])
{
    cout<<"ARBOL-KD ORDENADO"<<endl;
    cout<<"****************************************************************"<<endl;
    kdtree<int> arbolito;
    int el;
    cout<<"Cuantos elementos en el arbol: \n";
    cin>>el;
    for(int i=0;i<el;i++)
    {
        int dats;
        vector<int> datos;
        cout<<"cuantos datos desea:\n";
        cin>>dats;
        for(int j=0;j<dats;j++)
        {
            int dat;
            cout<<"ingrese el dato:\n";
            cin>>dat;
            datos.push_back(dat);
        }
    
        arbolito.insertar(datos);
    }

	cout<<endl;
	cout<<"Pre Orden:"<<endl;
	arbolito.preOrden();
	cout<<endl;
	cout<<"Pos Orden: "<<endl;
	arbolito.posOrden();
	cout<<endl;
	cout<<"InOrden: \n";
	arbolito.inOrden();
	cout<<endl;
	cout<<"NivelOrden:\n";
	arbolito.nivelOrden();
	cout<<endl;

}