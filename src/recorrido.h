/**
   Laberinto - TP 1

   @author Mariano Cinalli, Ezequiel Guitler, Santiago Montiel, Lucas Dreko, Laura Corvalan
*/

#ifndef _RECORRIDO_H_
#define _RECORRIDO_H_

#include "color.h"
#include "casillero.h"
#include <string>

class Recorrido {
   public:
      Recorrido(Color * color);

      bool estaVacia();

      void acolar(char orientacion, int pasos, bool objeto, std::string bifurcacion, std::string empalme);

      void desacolar();

      Casillero * obtenerFrente();

   private:

      Color * color;

      Casillero * frente;

      Casillero * fondo;

      int ancho;

      int alto;
};

#endif