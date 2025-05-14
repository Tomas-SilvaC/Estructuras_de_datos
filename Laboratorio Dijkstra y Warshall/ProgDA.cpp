/*------------------------------------
PONTIFICIA UNIVERSIDAD JAVERIANA     |
Autor: Tomas Alejandro Silva Correal |
Clase: Estructuras de datos          |
Tema: Algoritmo de dijkstra          |
-------------------------------------*/

/*
Descripción:
Este programa simula el Algoritmo de dijkstra para un grafo representado a traves de su matriz de adyacencia
Con tal de comprobar su respectivo funcionamiento se utilizo un ejemplo realizado a mano previamente.
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int mindi(int dist[], bool sptset[], int V){
	//Inicializa con valor minimo 
	int min = INT_MAX, min_index;
	//va viajando entre distancias obteniendo la de menor costo
	for(int v=0; v<V; v++){
		if(sptset[v] == false && dist[v] <= min){
			min=dist[v], min_index = v;
		}
	}
	return min_index;
}
//Imprime el resultado o solución
void printsol(int dist[], int v){
	//Titulos
	cout<<"Vertice \t Distancia desde la fuente"<<endl;
	//Valores correspindientes
	for (int i=0; i<v; i++){
		cout<< i<< "\t\t\t\t"<<dist[i]<<endl;
	}
}
void dijkstra( vector<vector<int>> grafo, int src, int V){
	int dist[V]; //La matriz de salida. dist[i] tendrá la distancia más corta desde src a i
	bool sptSet[V]; // sptSet[i] será verdadero si el vértice i está incluido en el árbol del
	// camino más corto o la distancia más corta de src a i está finalizada.
	// Inicializa todas las distancias INFINITE y stpSet[] como false
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;
	// La distancia del vértice de origen respecto a sí mismo es siempre 0
	dist[src] = 0;
	// Encontrar el camino más corto para todos los vértices
	for (int count = 0; count < V - 1; count++) {
		// Elige el vértice de distancia mínima del conjunto de vértices aún no procesados. u es siempre igual a src en la primera iteración.
		int u = mindi(dist, sptSet, V);
		// Marcar el vértice elegido como procesado
		sptSet[u] = true;
		// Actualiza el valor dist de los vértices adyacentes al vértice elegido.
		for (int v = 0; v < V; v++)
		// Actualizar dist[v] sólo si no está en sptSet, hay una arista de u a v, y el peso
		// total de la ruta de src a v a través de u es menor que el valor actual de dist[v].
		if (!sptSet[v] && grafo[u][v]
			&& dist[u] != INT_MAX
			&& dist[u] + grafo[u][v] < dist[v])
			dist[v] = dist[u] + grafo[u][v];
	}
	// imprimir la matriz de distancias construida
	printsol(dist, V);
}

int main(){
	vector<vector<int>> Grafo;
	Grafo={ { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
	dijkstra(Grafo, 0, Grafo.size());
}
