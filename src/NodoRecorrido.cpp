#include "NodoRecorrido.h"
#include <iostream>


NodoRecorrido::NodoRecorrido(Recorrido * recorrido) {
   this->recorrido = recorrido;
   this->siguiente = NULL;
}

NodoRecorrido * NodoRecorrido::obtenerSiguiente() {
   return this->siguiente;
}

void NodoRecorrido::cambiarSiguiente(NodoRecorrido * nodoRecorrido) {
   this->siguiente = nodoRecorrido;
}

Recorrido * NodoRecorrido::obtenerRecorrido() {
   return this->recorrido;
}