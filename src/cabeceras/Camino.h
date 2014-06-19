/**
   Laberinto - TP 1

   Representa un Camino en el laberinto
   Tiene un puntero al comienzo del recorrido y otro al final.
   La idea es representar un camino del recorrido en esta estructura, con sus uniones y bifurcaciones

   Ver Punto.h

   @author Laura Corvalan
*/

#ifndef _CAMINO_H_
#define _CAMINO_H_

#include "Punto.h"
#include "util.h"
#include <string>

class Camino {
   public:
      /**
       * Constructor
       * Setea comienzoRecorrido, finRecorrido en NULL y empalme en false
       */
      Camino();

      /**
       * Modifica el punto donde comienza el recorridos
       */
      void cambiarComienzo(Punto * punto);

      /**
       * Modifica el punto donde finaliza el recorridos
       */
      void cambiarFin(Punto * punto);

      /**
       * Retorna punto de comienzo
       */
      Punto * obtenerComienzo();

      /**
       * Retorna punto de fin de recorrido
       */
      Punto * obtenerFin();

      /**
       * Modifica empalme = true. Indica que existen uniones en el recorrido
       */
      void marcarEmpalme();

      /**
       * Retorna true si el camino tiene uniones, false caso contrario
       */
      bool tieneEmpalme();

      /**
       * @TODO implementar
       */
      ~Camino();

   private:

      /**
       * Punto de comienzo de recorrido
       */
      Punto * comienzoRecorrido;

      /**
       * Punto de fin de recorrido
       */
      Punto * finRecorrido;

      /**
       * Valor booleano que indica si el camino tiene uniones
       */
      bool empalme;

      /**
       * Valor booleano que indica si el camino tiene uniones
       */
      void eliminarTodoElRecorrido(char * orientaciones, Punto * punto);
};

#endif