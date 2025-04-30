/***************************************************************************************
|Autores: Tomas Silva, Juan Pabon Vargas                                               |
|Estructuras de datos                                                                  |
|J.Corredor                                                                            |
|Laboratorio de Grafos                                                                 |
***************************************************************************************/

/*---------------------------------------------------------------------------------------
Descripcion:
El programa a continuacion ejemplifica un grafo no dirigido de tamaño definido por el 
usuario para vertices y aristas. El programa toma estas definiciones y busca, a traves 
de la matriz de adyacencia creada, la que resulta dimetrica por rutas que completen 
tanto caminos como ciclos o circuitos de Euler y Hamilton.
---------------------------------------------------------------------------------------*/
#include <iostream>
#include <string.h>
#include <algorithm>
#include <list>
#include<stdio.h>

using namespace std;
int n;
/*------------------------------------------------------------------------------
ELEMENTOS PRIMERA CLASE (CAMINOS Y CIRCUITOS DE EULER)
------------------------------------------------------------------------------*/
//Clase Euler
class Euler
{
    //Cantidad de nodos o vertices
	int V;
	//Cantidad de aristas conectadas por cada vertice
	list<int> *adj;
public:
    //Asignar la cantidad de nodos
	Euler(int V)  {
		this->V = V;
		adj = new list<int>[V];
	}
	~Euler()      {
		delete [] adj;
	}
    //Agregar una arista
	void addEdge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	//Eliminar arista
	void rmvEdge(int u, int v);
	//Imprimir circuito de Euler
	void printEulerTour();
	//Imprimir camino de Euler
	void printEulerUtil(int s);
	//Depth - First - Search
	int DFSCount(int v, bool visited[]);
	//Verificar valides de arista
	bool isValidNextEdge(int u, int v);
	//Verificar si hay o no caminos o circuitos de Euler
	int iseuler(int[]);
};

//Imprime el circuito de Euler si es que lo hay, usando printEulerUtil
void Euler::printEulerTour()
{
	int u = 0;
	for (int i = 0; i < V; i++)
		if (adj[i].size() & 1)
		{
			u = i;
			break;
		}
	printEulerUtil(u);
	cout << endl;
}

//Imprime el camino o circuito de Euler
void Euler::printEulerUtil(int u)
{
	list<int>::iterator i;
	for (i = adj[u].begin(); i != adj[u].end(); ++i)
	{
		int v = *i;
		//Verifica si la siguiente arista es valida, y de serlo imprime la arista
		if (v != -1 && isValidNextEdge(u, v))
		{
			cout << u << "-" << v << " ";
			rmvEdge(u, v);
			printEulerUtil(v);
		}
	}
}

//Verifica valides de la arista entre dos vertices
bool Euler::isValidNextEdge(int u, int v)
{
	int count = 0;
	list<int>::iterator i;
	for (i = adj[u].begin(); i != adj[u].end(); ++i)
		if (*i != -1)
			count++;
		//¿Existe una arista siguiente?
	if (count == 1)
		return true;
    
	bool visited[V];
	//Llena visited con false en todo el arreglo
	memset(visited, false, V);
	int count1 = DFSCount(u, visited);
    //Elimina la arista entre los dos vertices
	rmvEdge(u, v);
	
	memset(visited, false, V);
	int count2 = DFSCount(u, visited);
    //Vuelve a agregar la arista
	addEdge(u, v);
    
	return (count1 > count2)? false: true;
}
//Eliminar arista
void Euler::rmvEdge(int u, int v)
{
    //Busca el punto en la matriz de adyacencia por la arista y la cambia a 0
	list<int>::iterator iv = find(adj[u].begin(), adj[u].end(), v);
	*iv = -1;
    //Hace lo mismo para el punto contrario (dado que la matriz es simetrica)
    //Es decir, torna en 0 para u-v como v-u
	list<int>::iterator iu = find(adj[v].begin(), adj[v].end(), u);
	*iu = -1;
}
//Depth First Search
int Euler::DFSCount(int v, bool visited[])
{
    //Retorna la cantidad de aristas de un vertice
	visited[v] = true;
	int count = 1;
    
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (*i != -1 && !visited[*i])
		    //Incrementa la cantidad de arsitas visitadas
			count += DFSCount(*i, visited);

	return count;
}

//Verifica si existe un camino o circuito de Euler
int Euler::iseuler(int a[])
{
	int count = 0;
	//Hace conteo de los caminos pares
	for(int i=0; i<n; i++) {
		if(a[i] % 2 != 0)
			count++;
	}
	//Si es 0, hay un circuito de Euler, verificando por un numero par de conexiones
	if(count == 0) {
		cout<<"Euler's circuit exists:\n";
		return 1;
	}
	//Si es 2, hay un camino de Euler
	else if(count == 2) {
		cout<<"Euler's path exists:\n";
		return 1;
	}
	//De ser un numero distinto, hay un numero impard de conexiones y por tanto no existe ningun camino ni circuito de Euler
	else {
		cout<<"No euler's path or circuit exist:'\n\n";
		return -1;
	}
}
/*------------------------------------------------------------------------------
ELEMENTOS SEGUNDA CLASE (CAMINOS DE HAMILTON)
------------------------------------------------------------------------------*/
//Clase Hamiltonian
class Hamiltonian
{
    //Arreglo de caminos entre vertices, cantidad de vertices y aristas
	int *path,v,x;
public:
	Hamiltonian(int n) {
		v = 0;
		x = 0;
		path = new int[n];
	}
	
	bool isSafe(bool graph[][10], int pos);
	bool hamCycleUtil(bool graph[][10], int pos, int i);
	bool hamCycle(bool graph[][10]);
	void printSolution();
};

bool Hamiltonian::isSafe(bool graph[][10], int pos)
{
	if (graph [ path[pos-1] ][ v ] == 0)
		return false;

	for (int i = 0; i < pos; i++)
		if (path[i] == v)
			return false;

	return true;
}

bool Hamiltonian::hamCycleUtil(bool graph[][10], int pos, int i)
{
	if (pos == n)
	{   //Verifica si hay un ciclo de hamilton
		if ( graph[ path[pos-1] ][ path[0] ] == 1 )
		{
			cout<<"Hamiltonian cycle exists\n";
			x = 1;
		}
		else//Verifica si existe un camino en lugar de un ciclo
			cout<<"Hamiltonian path exists\n";
		return true;
	}

	for (v = 0; v < n; v++)
	{
		if(v == i)
			continue;
		if (isSafe(graph, pos))
		{
			path[pos] = v;

			if (hamCycleUtil (graph, pos+1, i) == true)
				return true;

			path[pos] = -1;
		}
	}

	return false;
}
//Revisa si existe o no un camino o ciclo de Hamilton
bool Hamiltonian::hamCycle(bool graph[][10])
{
	for (int i = 0; i < n; i++)
		path[i] = -1;

	for(int i=0; i < n; i++)
	{
		path[0] = i;
		//Si hay camino o ciclo que pase por todo vertice
		if ( hamCycleUtil(graph, 1,i) == true )
		{
		    //De haber un ciclo o camino, imprime el resultado
			printSolution();
			return true;
		}
	}
	//Si no encuentra ningun ciclo o camino
	cout<<"\nNo Hamiltonian path or cycle exist";
	return false;

}

//Impresion de camino de hamilton
void Hamiltonian::printSolution()
{
    //Imprime todos los caminos en path
	for (int i = 0; i < n - 1; i++)
		cout << path[i] << "-" << path[i + 1] << " ";
    //Imprime si hay un camino que termine en el nodo
	if(x == 1)
		cout << path[n - 1] << "-" << path[0];
	cout<<"\n";
}


int main()
{
    //Define variables
	int i,j,v1,v2,Edges;
	//Solicita numero de nodos
	cout<<"\n Enter the number of vertices of graph: ";
	cin>>n;
	//Con el numero de nodos crea las clases Euler y Hamiltonian
	Euler g1(n);
	Hamiltonian g2(n);
	
	int a[n] = {0};
	/*
	Se crea la matriz para definir caminos entre nodos o vertices
	*/
	//Define donde habran o no aristas entre nodos o vertices
	bool graph1[10][10];
	//Inicia en 0 para todos puesto que aun no se crean aristas
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			graph1[i][j]=0;
	//Solicta el total de aristas
	cout<<"\n Enter the total number of edges: ";
	cin>>Edges;
	//Solicita definir todas las aristas entre valores nodo
	for(i=1; i<=Edges; i++)
	{
		cout<<"\n Enter the edge: ";
		cin>>v1>>v2;
		//Asigna 1 en la matriz cuando hay un camino
		graph1[v1][v2]=1;
		graph1[v2][v1]=1;
		//Agrega una arista al grafo entre los valores v1 y v2
		g1.addEdge(v1, v2);
		//Aumenta la cantidad de aristas para ambos vertices
		a[v1]++;
		a[v2]++;
	}
	//Imprime si existe un camino o ciclo de Hamilton
	cout<<"\n";
	g2.hamCycle(graph1);
	cout<<"\n";
	//Imprime si existe el camino o circuito de Euler
	if(g1.iseuler(a) == 1)
		g1.printEulerTour();
	return 0;
	/*
	Ejemplos:
    	Caso 1: Hay circuitos o ciclos de Euler y Hamilton
    	4 vertices, con 4 conexiones
    	0,1,2,3
    	0-1 1-2 2-3 3-0
    	El resultado es igual al esperado
    	
    	Caso 2: Hay ciclo de Hamilton, pero no camino ni circuito de Euler
    	4 vertices, 6 conexiones
    	0,1,2,3
    	0-1 1-2 2-3 3-0 1-3 0-2
    	El resultado es igual al esperado
    	
    	Caso 3: hay circuito de Euler, pero no hay ni circuitos ni ciclos de Hamilton
    	5 vertices, 3 conexiones
    	0,1,2,3,4 (siendo el 4 y el 2 un nodos aislados)
    	0-1 1-3 3-0
    	El resultado es igual al esperado
    	
    	Caso 4: No hay ni caminos ni circuitos o ciclos para Euler ni Hamilton
    	6 vertices, 6 conexiones
    	0,1,2,3,4,5
    	0-1 1-2 2-3 3-0 0-2 1-3
    	El resultado es igual al esperado
    	
    	Teniendo en cuenta los resultados, es posible evidenciar el correcto funcionamiento del programa
	*/
}
