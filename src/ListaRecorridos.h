/**
   Laberinto - TP 1

   @author Mariano Cinalli, Ezequiel Guitler, Santiago Montiel, Lucas Dreko, Laura Corvalan
*/

#ifndef _LISTA_RECORRIDOS_H_
#define _LISTA_RECORRIDOS_H_

#include "NodoRecorrido.h"
#include <string>

class ListaRecorridos {
   public:
      /**
       * Constructor.
       */
      ListaRecorridos();

      /**
       * Retorna true si la lista esta vacia, false en caso contrario
       */
      bool estaVacia();

      /**
       * Agrega un elemento al final de la lista.
       */
      void acolar(Recorrido * recorrido);

      /**
       * Remueve un elemento del frente de la lista.
       */
      void desacolar();

      /**
       * Retorna primer elemento de la lista
       */
      NodoRecorrido * obtenerFrente();

   private:

      /**
       * Puntero a primer elemento de la lista
       */
      NodoRecorrido * frente;

      /**
       * Puntero a ultimo elemento de la lista
       */
      NodoRecorrido * fondo;

};

#endif