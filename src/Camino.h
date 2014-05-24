/**
   Laberinto - TP 1

   @author Mariano Cinalli, Ezequiel Guitler, Santiago Montiel, Lucas Dreko, Laura Corvalan
*/

#ifndef _CAMINO_H_
#define _CAMINO_H_

#include "ListaEnlazada.h"
#include "Color.h"
#include "Casillero.h"
#include "Bifurcacion.h"

#include <string>

class Camino {
   public:
      /**
       * Constructor
       */
      Camino(Color * color);

      /**
       * Agrega un elemento al recorrido ListaEnlazada<Casillero>
       */
      void agregarCasillero(char orientacion, int pasos, bool tieneObjeto, std::string bifurcacion, std::string empalme);

      void agregarBifurcacion(std::string nombre, int x, int y);

      void agregarEmpalme(std::string nombre, int x, int y);

      bool tieneEmpalmes();

      /**
       * Retorna lista de bifurcaciones
       */
      ListaEnlazada<Bifurcacion*> * obtenerBifurcaciones();

      /**
       * Retorna lista de casilleros
       */
      ListaEnlazada<Casillero*> * obtenerRecorrido();

      std::string aString();

      void mostrar();

      ~Camino();

   private:

      /**
       * Color del recorrido. La clase Color tiene solo tres atributos:
       * rojo, verde y azul
       */
      Color * color;

      /**
       * Lista de bifurcaciones encontradas en el recorrido
       */
      ListaEnlazada<Bifurcacion*> * bifurcaciones;

      ListaEnlazada<Bifurcacion*> * empalmes;

      ListaEnlazada<Casillero*> * recorrido;

      int ancho;

      int alto;
};

#endif