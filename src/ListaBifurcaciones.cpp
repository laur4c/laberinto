#include "ListaBifurcaciones.h"

using namespace std;

ListaBifurcaciones::ListaBifurcaciones() {
   this->frente = NULL;
   this->fondo = NULL;
}

bool ListaBifurcaciones::estaVacia() {
   return this->frente == NULL;
}

void ListaBifurcaciones::acolar(string nombre, int x, int y) {
   Bifurcacion * ultimo = new Bifurcacion(nombre, x, y);

   if (this->estaVacia()) {
      this->frente = ultimo;
   } else {
      this->fondo->cambiarSiguiente(ultimo);
   }
   this->fondo = ultimo;
}

void ListaBifurcaciones::desacolar() {
   // falta implementar
}

Bifurcacion * ListaBifurcaciones::obtenerFrente() {
   return this->frente;
}

