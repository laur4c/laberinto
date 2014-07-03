#include "cabeceras/AristaLaberinto.h"
#include <iostream>


ListaEnlazada<Tramo*> * AristaLaberinto::obtenerTramos() {
  return this->dato;
}

void AristaLaberinto::marcarTramosComoNoDibujados() {
  this->dato->iniciarCursor();
  while(this->dato->avanzarCursor()) {
    this->dato->obtenerCursor()->marcarComoNoDibujado();
  }
}

bool AristaLaberinto::dibujarEnSentidoContrario() {
   return this->enSentidoContrario;
}

AristaLaberinto::~AristaLaberinto() {
  if (!this->enSentidoContrario)
    delete this->dato;

}
