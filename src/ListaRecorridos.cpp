#include "ListaRecorridos.h"

using namespace std;

ListaRecorridos::ListaRecorridos() {
   this->frente = NULL;
   this->fondo = NULL;
}

bool ListaRecorridos::estaVacia() {
   return this->frente == NULL;
}

void ListaRecorridos::acolar(Recorrido * recorrido) {
   NodoRecorrido * ultimo = new NodoRecorrido(recorrido);

   if (this->estaVacia()) {
      this->frente = ultimo;
   } else {
      this->fondo->cambiarSiguiente(ultimo);
   }
   this->fondo = ultimo;
}

void ListaRecorridos::desacolar() {
   // falta implementar
}

NodoRecorrido * ListaRecorridos::obtenerFrente() {
   return this->frente;
}

