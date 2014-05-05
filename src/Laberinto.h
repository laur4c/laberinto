/**
   Laberinto - TP 1

   @author Santiago Montiel, Lucas Dreko, Laura Corvalan
*/

#ifndef _LABERINTO_H_
#define _LABERINTO_H_

#include "util.h"
#include "ListaRecorridos.h"
#include "ListaComandos.h"

class Laberinto {
   public:
      /**
       * Constructor.
       */
      Laberinto();

      /**
       * A partir de una lista de comandos, popula la lista de recorridos
       * Ver ListaRecorridos.h, Recorrido.h
       */
      void generarRecorridosDesdeListaDeComandos(ListaComandos * comandos);

      /**
       * Retorna lista de recorridos
       */
      ListaRecorridos * obtenerRecorridos();

   private:

      /**
       * Lista de recorridos
       */
      ListaRecorridos * recorridos;

      /**
       * Setea las coordenadas (X, Y) de los casilleros de
       * todos los recorridos del laberinto.
       * Siempre empezando en el punto (0, 0) dentro del eje de coordenadas
       */
      void definirCoordenadas(Recorrido * recorrido);
};

#endif