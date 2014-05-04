/**
   Laberinto - TP 1
   Representa un comando, el cual se compone de un nombre y un argumento

   @author Mariano Cinalli, Ezequiel Guitler, Santiago Montiel, Lucas Dreko, Laura Corvalan
*/

#ifndef _NODO_RECORRIDO_H_
#define _NODO_RECORRIDO_H_

#include "Recorrido.h"

class NodoRecorrido {
   public:
      NodoRecorrido(Recorrido * recorrido);

      NodoRecorrido * obtenerSiguiente();

      void cambiarSiguiente(NodoRecorrido * nodoRecorrido);

      Recorrido * obtenerRecorrido();

   private:
      Recorrido * recorrido;

      NodoRecorrido * siguiente;
};

#endif