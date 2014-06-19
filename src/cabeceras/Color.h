/**
   Laberinto - TP 1
   Representa un color.

   @author Laura Corvalan

*/

#ifndef _COLOR_H_
#define _COLOR_H_

#include <string>

class Color {
   public:
      Color(int rojo, int verde, int azul);

      int rojo;

      int verde;

      int azul;
};

#endif