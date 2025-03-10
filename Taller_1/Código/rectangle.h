#ifndef RECTANGLE_H
#define RECTANGLE_H
//Crea la estructura rectangulo
struct Rectangle {
  float posX;
  float posY;
  int width;
  int height;	
};
//Inicializa los metodos
float perimeterRect ( Rectangle rect );
float areaRect ( Rectangle rect );
float distOriginRect ( Rectangle rect );

#include "rectangle.cxx"

#endif
