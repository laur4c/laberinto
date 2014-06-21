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

      Color * color;

      bool estaDibujado();

      void marcarComoDibujado();

      void marcarComoNoDibujado();

   private:

      bool dibujado;

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