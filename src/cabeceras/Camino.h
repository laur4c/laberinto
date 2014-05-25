/**
   Laberinto - TP 1

   @author Mariano Cinalli, Ezequiel Guitler, Santiago Montiel, Lucas Dreko, Laura Corvalan
*/

#ifndef _CAMINO_H_
#define _CAMINO_H_

#include "Punto.h"
#include <string>

class Camino {
   public:
      /**
       * Constructor
       */
      Camino();

      void cambiarComienzo(Punto * punto);

      void cambiarFin(Punto * punto);

      Punto * obtenerComienzo();

      Punto * obtenerFin();

      void marcarEmpalme();

      bool tieneEmpalme();

      ~Camino();

   private:

      Punto * comienzoRecorrido;

      Punto * finRecorrido;

      bool empalme;
};

#endif