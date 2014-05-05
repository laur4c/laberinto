#include "Recorrido.h"
#include <iostream>

using namespace std;

Recorrido::Recorrido(Color * color) {
   this->color = color;
   this->frente = NULL;
   this->fondo = NULL;

   this->bifurcaciones = new ListaBifurcaciones();
}

ListaBifurcaciones * Recorrido::obtenerBifurcaciones() {
   return this->bifurcaciones;
}

bool Recorrido::estaVacia() {
   return this->frente == NULL;
}

void Recorrido::acolar(char orientacion, int pasos, bool objeto, string bifurcacion, string empalme) {
   Casillero * ultimo = new Casillero(orientacion, pasos, objeto);
   ultimo->cambiarBifurcacion(bifurcacion);
   ultimo->cambiarEmpalme(empalme);

   if (this->estaVacia()) {
      this->frente = ultimo;
   } else {
      this->fondo->cambiarSiguiente(ultimo);
   }
   this->fondo = ultimo;
}

void Recorrido::desacolar() {
   // falta implementar
}

Casillero * Recorrido::obtenerFrente() {
   return this->frente;
}

Recorrido::~Recorrido() {
   delete this->bifurcaciones;
}