/**
   Laberinto - TP 1
   @author Mariano Cinalli, Ezequiel Guitler, Santiago Montiel, Lucas Dreko, Laura Corvalan
*/

#ifndef _BIFURCACION_H_
#define _BIFURCACION_H_

#include "Punto.h"
#include <iostream>

class Bifurcacion {
   public:
      /**
       * Constructor
       */
      Bifurcacion(std::string nombre, int x, int y);

      /**
       * Retorna el dato del nodo, en este caso el nombre de la bifurcacion
       */
      std::string obtenerNombre();

      /**
       * Retorna una instancia de la clase Punto
       */
      Punto * obtenerPunto();

      std::string aString();
   private:
      /**
       * Nombre de la bifurcacion
       */
      std::string nombre;

      /**
       * Instancia clase Punto
       * Coordenadas X, Y de la bifurcacion dentro del eje de coordenadas
       */
      Punto * punto;
};

#endif