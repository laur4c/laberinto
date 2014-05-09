/**
   Laberinto - TP 1

   @author Mariano Cinalli, Ezequiel Guitler, Santiago Montiel, Lucas Dreko, Laura Corvalan
*/

#ifndef _RECORRIDO_H_
#define _RECORRIDO_H_

#include "ListaEnlazada.h"
#include "Color.h"
#include "Casillero.h"
#include "Bifurcacion.h"

#include <string>

class Recorrido {
   public:
      /**
       * Constructor
       */
      Recorrido(Color * color);

      void agregarCasillero(char orientacion, int pasos, bool tieneObjeto, std::string bifurcacion, std::string empalme);

      void agregarBifurcacion(std::string nombre, int x, int y);

      /**
       * Retorna lista de bifurcaciones
       */
      ListaEnlazada<Bifurcacion> * obtenerBifurcaciones();

      ListaEnlazada<Casillero> * obtenerCamino();

      std::string aString();

      void mostrar();

      ~Recorrido();

   private:

      /**
       * Color del recorrido. La clase Color tiene solo tres atributos:
       * rojo, verde y azul
       */
      Color * color;

      /**
       * Lista de bifurcaciones encontradas en el recorrido
       */
      ListaEnlazada<Bifurcacion> * bifurcaciones;

      ListaEnlazada<Casillero> * camino;

      int ancho;

      int alto;
};

#endif