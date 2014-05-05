/**
   Laberinto - TP 1

   @author Mariano Cinalli, Ezequiel Guitler, Santiago Montiel, Lucas Dreko, Laura Corvalan
*/

#ifndef _LISTA_BIFURCACIONES_H_
#define _LISTA_BIFURCACIONES_H_

#include "Bifurcacion.h"

class ListaBifurcaciones {
   public:
      /**
       * Constructor.
       */
      ListaBifurcaciones();

      /**
       * Retorna true si la lista esta vacia, false en caso contrario
       */
      bool estaVacia();

      /**
       * Agrega un elemento al final de la lista.
       */
      void acolar(std::string nombre, int x, int y);

      /**
       * Remueve un elemento del frente de la lista.
       */
      void desacolar();

      /**
       * Retorna primer elemento de la lista
       */
      Bifurcacion * obtenerFrente();

   private:

      /**
       * Puntero a primer elemento de la lista
       */
      Bifurcacion * frente;

      /**
       * Puntero a ultimo elemento de la lista
       */
      Bifurcacion * fondo;

};

#endif