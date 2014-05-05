#include "Bifurcacion.h"
#include <iostream>

Bifurcacion::Bifurcacion(std::string nombre, int x, int y) {
   this->nombre = nombre;
   this->punto = new Punto(x, y);
   this->siguiente = NULL;
}

Bifurcacion * Bifurcacion::obtenerSiguiente() {
   return this->siguiente;
}

void Bifurcacion::cambiarSiguiente(Bifurcacion * bifurcacion) {
   this->siguiente = bifurcacion;
}

std::string Bifurcacion::obtenerNombre() {
   return this->nombre;
}

Punto * Bifurcacion::obtenerPunto() {
   return this->punto;
}