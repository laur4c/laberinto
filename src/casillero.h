/**
   Laberinto - TP 1

   @author Mariano Cinalli, Ezequiel Guitler, Santiago Montiel, Lucas Dreko, Laura Corvalan
*/

#ifndef _CASILLERO_H_
#define _CASILLERO_H_

#include "punto.h"
#include <string>

class Casillero {
   public:
      Casillero(char orientacion, int cantidadDePasos, bool hayObjeto);

      void cambiarXY(int x, int y);

      std::string aString();

      Casillero * obtenerSiguiente();

      void cambiarSiguiente(Casillero * casillero);

      std::string obtenerBifurcacion();

      void cambiarBifurcacion(std::string nombre);

      std::string obtenerEmpalme();

      void cambiarEmpalme(std::string nombre);

      bool hayObjeto();

   private:
      char orientacion;

      int cantidadDePasos;

      std::string bifurcacion;

      std::string empalme;

      bool objeto;

      Punto * punto;

      Casillero * siguiente;
};

#endif