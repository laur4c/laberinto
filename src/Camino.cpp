#include "cabeceras/Camino.h"
#include <iostream>

using namespace std;

Camino::Camino() {
   this->comienzoRecorrido = NULL;
   this->finRecorrido = NULL;
   this->empalme = false;
}

void Camino::cambiarComienzo(Punto * punto) {
   this->comienzoRecorrido = punto;
}

void Camino::cambiarFin(Punto * punto) {
   this->finRecorrido = punto;
}

Punto * Camino::obtenerComienzo() {
   return this->comienzoRecorrido;
}

Punto * Camino::obtenerFin() {
   return this->finRecorrido;
}

void Camino::marcarEmpalme() {
   this->empalme = true;
}

bool Camino::tieneEmpalme() {
   return this->empalme;
}

Camino::~Camino() {
}
