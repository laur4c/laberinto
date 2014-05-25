/**
   Laberinto - TP 1

   @author Mariano Cinalli, Ezequiel Guitler, Santiago Montiel, Lucas Dreko, Laura Corvalan
*/

#ifndef _PUNTO_H_
#define _PUNTO_H_

#include <iostream>
#include "InfoPunto.h"
#include "Color.h"

class Punto {
   public:

      Punto(InfoPunto * info, Color * color);

      Punto * obtenerPunto(char orientacion);

      void cambiarPunto(char orientacion, Punto * punto);

      Punto * obtenerNorte();

      Punto * obtenerSur();

      Punto * obtenerEste();

      Punto * obtenerOeste();

      bool tienePuntoEn(char orientacion);

      bool tieneNorte();

      bool tieneSur();

      bool tieneEste();

      bool tieneOeste();

      void cambiarSur(Punto * punto);

      void cambiarNorte(Punto * punto);

      void cambiarEste(Punto * punto);

      void cambiarOeste(Punto * punto);

      InfoPunto * obtenerInformacion();

      Color * obtenerColor();

      void marcarComoDibujado();

      bool estaDibujado();

      std::string aString();

   private:
         Color * color;

         InfoPunto * informacion;

         bool dibujado;

         Punto * norte;

         Punto * sur;

         Punto * este;

         Punto * oeste;
};

#endif