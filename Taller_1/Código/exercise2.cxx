// exercise1.cxx (Andrea Rueda) - creadora del codigo original
//Documentado por Tomas Silva

// Main program that uses the functionality of rectangle.h

#include <iostream>
#include "rectangle.h"

using namespace std;

int main () {

	Rectangle rect1;
	int a, b;
	//Pide datos relevantes para el calculo con metodos de rectangulo
	cout << "Ingrese coordenada X de la posicion del rectangulo: ";
	cin >> rect1.posX;
	cout << "Ingrese coordenada Y de la posicion del rectangulo: ";
	cin >> rect1.posY;
	cout << "Ingrese ancho del rectangulo: ";
	cin >> rect1.width;
	cout << "Ingrese alto del rectangulo: ";
	cin >> rect1.height;
	//Saca los resultados impresos en orden de perimetro, area y distancia
	cout << "\nPerimetro del rectangulo: " << perimeterRect( rect1 ) << endl;
	cout << "Area del rectangulo: " << areaRect( rect1 ) << endl;
	cout << "Distancia del rectangulo al origen de coordenadas: " << distOriginRect( rect1 ) << endl;

	return 0;
}
