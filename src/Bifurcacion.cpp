#include "Bifurcacion.h"
#include <iostream>

Bifurcacion::Bifurcacion(std::string nombre, int x, int y) {
   this->nombre = nombre;
   this->punto = new Punto(x, y);
}

std::string Bifurcacion::obtenerNombre() {
   return this->nombre;
}

Punto * Bifurcacion::obtenerPunto() {
   return this->punto;
}

std::string Bifurcacion::aString() {
   return "Nombre: " + this->nombre + " Punto: " + this->punto->aString();
}
