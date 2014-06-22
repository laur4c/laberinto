/**
   Laberinto - TP 1

   @author Laura Corvalan
*/

#ifndef _TRAMO_H_
#define _TRAMO_H_

#include "Color.h"

class Tramo {

   public:

      /**
       * Color del tramo
       */
      Color * color;

      /**
       * Constructor.
       */
      Tramo(char orientacion, int longitud, bool hayObjeto, Color * color);

      /**
       * Retorna orientacion
       * Posibles valores: N, S, E, O
       */
      char obtenerOrientacion();

      /**
       * Retorna la longitud del tramo
       */
      int obtenerLongitud();

      /**
       * Retorna true si se debe marcar un objeto en la imagen (Si el caminante tiro un objeto)
       */
      bool tieneObjeto();

      /**
       * Retorna true si el tramo fue dibujado
       */
      bool estaDibujado();

      /**
       * Setea dibujado igual a true
       */
      void marcarComoDibujado();

      /**
       * Setea dibujado igual a false
       */
      void marcarComoNoDibujado();

   private:

      /**
       * Indica si el tramo ya fue dibujado. Ver ImagenLaberinto
       */
      bool dibujado;

      /**
       * Longitud del tramo
       */
      int longitud;

      /**
       * Orientacion. Valores posibles: N, S, E, O
       */
      char orientacion;

      /**
       * True si se tiro un objeto en el punto, false caso contrario
       */
      bool hayObjeto;
};

#endif