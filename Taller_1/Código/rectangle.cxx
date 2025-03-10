#include "rectangle.h"
#include <math.h>

float perimeterRect ( Rectangle rect ) {
	//Por orden de operaciones, solo esta duplicando el ancho y suma el alto, cuando deberia de multiplicar los dos
	float perim = 0.0;
	perim = 2.0 * rect.width + rect.height;
	//Quizas:
	//perim = 2.0 * (rect.width + rect.height);
	//o
	//perim = 2.0 * rect.width +  2.0 * rect.height;
	return perim;
}

float areaRect ( Rectangle rect ) {
	//Suma los valores en lugar de multiplicarlos - error
	float area = 0.0;
	area = rect.width + rect.height;
	//area = rect.width * rect.height;
	return area;
}

float distOriginRect ( Rectangle rect ) {
	//este metodo funciona correctamente
	//saca la raiz cuadrada de las coordenadas asignadas al cuadrado
    	float dist = 0.0;
    	dist = sqrt( rect.posX * rect.posX + rect.posY * rect.posY );
    	return dist;
}
