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
      ListaRecorridos();

      bool estaVacia();

      void acolar(Recorrido * recorrido);

      void desacolar();

      NodoRecorrido * obtenerFrente();

   private:

      NodoRecorrido * frente;

      NodoRecorrido * fondo;

};

#endif