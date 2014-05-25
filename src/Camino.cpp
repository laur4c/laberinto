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

void Camino::eliminarTodoElRecorrido(char * orientaciones, Punto * punto) {
   char unaOrientacion;
   Punto * puntoSiguiente;
   for (unsigned int i = 0; i < 4; i++) {
      unaOrientacion = orientaciones[i];

      if (punto->tienePuntoEn(unaOrientacion)) {
         puntoSiguiente = punto->obtenerPunto(unaOrientacion);
         punto->cambiarPunto(unaOrientacion, NULL);
         this->eliminarTodoElRecorrido(orientaciones, puntoSiguiente);
      }
   }
   delete punto;
}

Camino::~Camino() {
   char * orientaciones = new char[3];
   orientaciones[0] = 'N';
   orientaciones[1] = 'S';
   orientaciones[2] = 'E';
   orientaciones[3] = 'O';

   this->eliminarTodoElRecorrido(orientaciones, this->comienzoRecorrido);
}
