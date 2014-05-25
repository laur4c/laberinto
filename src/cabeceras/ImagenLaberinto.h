/**
   Laberinto - TP 1

   @author Mariano Cinalli, Ezequiel Guitler, Santiago Montiel, Lucas Dreko, Laura Corvalan
*/

#ifndef _IMAGEN_LABERINTO_H_
#define _IMAGEN_LABERINTO_H_

#include "../EasyBMP/EasyBMP.h"
#include "Camino.h"
#include "Color.h"
#include "ListaEnlazada.h"
#include <string>

const char orientaciones[] = {'N', 'S', 'E', 'O'};

class ImagenLaberinto {
   public:
      ImagenLaberinto(ListaEnlazada<Camino*> * caminos, int unidad);

      void generar();

   private:
      ListaEnlazada<Camino*> * caminos;

      int unidad;

      BMP imagen;

      void avanzarNorte(Color * color, int &x, int &y, int total);

      void avanzarSur(Color * color, int &x, int &y, int total);

      void avanzarOeste(Color * color, int &x, int &y, int total);

      void avanzarEste(Color * color, int &x, int &y, int total);

      char obtenerOrientacionContraria(char orientacion);

      void dibujar(Punto * punto, char orientacion, int x, int y, int &maxAncho);

      void dibujarUnidad(Color * color, int x, int y);
};
#endif