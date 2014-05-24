#ifndef _ESTRUCTURA_H_
#define _ESTRUCTURA_H_

#include "ListaEnlazada.h"
#include "NodoCasillero.cpp"

class Estructura {
   public:
      NodoCasillero * ultimo;

      NodoCasillero * primero;

      Color * color;

      ListaEnlazada<NodoCasillero*> * bifurcaciones;
      ListaEnlazada<NodoCasillero*> * empalmes;

      bool tieneBifurcacion() {
         return !this->bifurcaciones->estaVacia();
      }

      bool tieneEmpalme() {
         return !this->empalmes->estaVacia();
      }

      Estructura(Color * color) {
         this->color = color;
         this->bifurcaciones = new ListaEnlazada<NodoCasillero*>();
         this->empalmes = new ListaEnlazada<NodoCasillero*>();
      }

      void recMostrar(NodoCasillero * nodo) {
         cout << "----------------" << endl;
         cout << nodo->obtenerDato()->aString() << endl;

         if (nodo->obtenerNorte() != NULL) {

            this->recMostrar(nodo->obtenerNorte());
         }
         if (nodo->obtenerSur() != NULL) {

            this->recMostrar(nodo->obtenerSur());
         }
         if (nodo->obtenerEste() != NULL) {
            this->recMostrar(nodo->obtenerEste());
         }
         if (nodo->obtenerOeste() != NULL) {
            this->recMostrar(nodo->obtenerOeste());
         }
         cout << "------FIN----------" << endl;
      }

      void mostrar() {
         recMostrar(this->primero);
      }
};

#endif