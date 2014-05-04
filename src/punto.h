/**
   Laberinto - TP 1

   @author Mariano Cinalli, Ezequiel Guitler, Santiago Montiel, Lucas Dreko, Laura Corvalan
*/

#ifndef _PUNTO_H_
#define _PUNTO_H_

class Punto {
   public:
      Punto(int x, int y);

      int obtenerX();

      int obtenerY();

      void cambiarXY(int x, int y);

   private:
      int x;

      int y;
};

#endif