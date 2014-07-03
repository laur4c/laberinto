/**
   Laberinto - TP 1
   Vertice del laberinto

   @author Laura Corvalan
*/

#ifndef _ARISTA_LABERINTO_H_
#define _ARISTA_LABERINTO_H_

#include "ListaEnlazada.h"
#include "Vertice.h"
#include "Arista.h"
#include "Tramo.h"
#include "VerticeLaberinto.h"
#include <iostream>

//class VerticeLaberinto;
class AristaLaberinto : public Arista<ListaEnlazada <Tramo*>*, std::string> {

   public:

      /**
       * Retorna lista de tramos
       *
       * Cada tramo tiene una sentido y una longitud.
       * Ver Tramo.h
       */
      ListaEnlazada<Tramo*> * obtenerTramos();

      /**
       * Marca todos los tramos de la arista como no dibujados
       */
      void marcarTramosComoNoDibujados();

      /**
       * Retorna true si sus tramos deben dibujarse en el sentido contrario
       *
       * Indica si debe dibujarse en sentido contrario.
       * Cuando se agrega una arista al laberinto, se agrega la arista con el sentido
       * que indica el archivo de texto y otra con el sentido contrario.
       * Esto se hace para poder, desde un vertice
       * recorrer todo el laberinto
       */
      bool dibujarEnSentidoContrario();

      ~AristaLaberinto();
   private:


};

#endif