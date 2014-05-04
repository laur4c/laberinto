#include "Punto.h"

Punto::Punto(int x, int y) {
   this->x = x;
   this->y = y;
}

int Punto::obtenerX() {
   return this->x;
}

int Punto::obtenerY() {
   return this->y;
}

void Punto::cambiarXY(int x, int y) {
   this->x = x;
   this->y = y;
}

