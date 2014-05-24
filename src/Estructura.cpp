#ifndef _ESTRUCTURA_H_
#define _ESTRUCTURA_H_

#include "ListaEnlazada.h"
#include "NodoCasillero.cpp"

class Estructura {
   public:
      NodoCasillero * ultimo;

      NodoCasillero * primero;

      ListaEnlazada<NodoCasillero*> * bifurcaciones;
      ListaEnlazada<NodoCasillero*> * empalmes;

      bool tieneBifurcacion() {
         return !this->bifurcaciones->estaVacia();
      }

      bool tieneEmpalme() {
         return !this->empalmes->estaVacia();
      }

      Estructura() {
         this->bifurcaciones = new ListaEnlazada<NodoCasillero*>();
         this->empalmes = new ListaEnlazada<NodoCasillero*>();
      }

};

#endif