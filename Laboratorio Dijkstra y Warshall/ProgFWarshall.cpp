/*---------------------------------
PONTIFICIA UNIVERSIDAD JAVERIANA   |
Autor: Tomas Silva                 |
Clase: Estructuras de datos        |
Tema: Algoritmo de Floyd Warshall  |
----------------------------------*/

/*
Descripción:
Este programa simula el algoritmo de Floyd Warshall en un grafo representado por una matriz de adyacencia
Se comprobo el funcionamiento de este programa mediante un ejemplo realizado a mano previamente
*/
#include <iostream>
#include <vector>
using namespace std;
//Va moviendose y comparando segun valores para hallar la alternativa de menor tamaño
void floyds(vector<vector<int>> b){
	int i, j, k;
	//Por cada columna y fila
	for (k = 0; k < 5; k++) {
		for (i = 0; i < 5; i++) {
			for (j = 0; j < 5; j++) {
				//Suma valores por el que sea menor o si este estaba en inifinito anteriormente
				if ((b[i][k] * b[k][j] != 0) && (i != j)) {
					if ((b[i][k] + b[k][j] < b[i][j]) || (b[i][j] == 0)) {
						b[i][j] = b[i][k] + b[k][j];
					}
				}
			}
		}
	}
	//Muestra el camino mas corto a cada nodo
	for (i = 0; i < 5; i++) {
		cout<<"Costo mínimo con respecto al nodo:"<<i<<endl;
		for (j = 0; j < 5; j++) {
			cout<<b[i][j]<<"\t";
		}
	}
}

int main(){
	//valor enorme que representa a infinito
	int inf=0xFFFF;
	//Se inicializa la matriz
	vector<vector<int>> b ={{ 0, 5, inf, 6, inf },
				{ inf, 0, 1, inf, 7 },
				{ 3, inf, 0, 4, inf },
				{ inf, inf, 2, 0, 3 },
				{ 2, inf, inf, 5, 0 }};
	

	floyds(b);
	return 0;
}
