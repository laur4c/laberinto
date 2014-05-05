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
      /**
       * Constructor
       */
      NodoRecorrido(Recorrido * recorrido);

      /**
       * Retorna puntero al nodo siguiente
       */
      NodoRecorrido * obtenerSiguiente();

      /**
       * Cambia el puntero al nodo siguiente
       */
      void cambiarSiguiente(NodoRecorrido * nodoRecorrido);

      /**
       * Retorna el dato del nodo, en este caso una instancia de la clase Recorrido
       * Ver Recorrido.h
       */
      Recorrido * obtenerRecorrido();

   private:
      /**
       * Una instancia de la clase Recorrido
       */
      Recorrido * recorrido;

      /**
       * Puntero al nodo siguiente
       */
      NodoRecorrido * siguiente;
};

#endif