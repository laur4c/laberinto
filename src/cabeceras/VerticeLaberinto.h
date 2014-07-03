/**
   Laberinto - TP 1
   Vertice del laberinto

   @author Laura Corvalan
*/

#ifndef _VERTICE_LABERINTO_H_
#define _VERTICE_LABERINTO_H_

#include "Vertice.h"
#include "Arista.h"
#include "AristaLaberinto.h"
#include "Tramo.h"

//class AristaLaberinto;
class VerticeLaberinto : public Vertice<std::string,ListaEnlazada< Tramo* >*> {

   public:

      VerticeLaberinto(std::string nombre, std::string dato);

      /**
       * Actualiza coordenadas (x, y) del vertice
       */
      void actualizarXY(int x, int y);

      /**
       * Retorna valor coordenada X
       */
      int obtenerX();

      /**
       * Retorna valor coordenada Y
       */
      int obtenerY();

      /**
       * Retorna true si coordenadas igual a (0, 0)
       */
      bool tieneCoordenadas();

   private:


      /**
       * Representa coordenada X en la imagen del laberinto
       */
      int x;

      /**
       * Representa coordenada Y en la imagen del laberinto
       */
      int y;

};

#endif