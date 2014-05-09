#include "Punto.h"
#include "util.h"

#include <iostream>

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

std::string Punto::aString() {
   return "(" + util::int_a_string(this->x) + ", " + util::int_a_string(this->y) + ")";
}