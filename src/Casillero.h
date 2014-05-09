/**
   Laberinto - TP 1
   Representa un nodo de un recorrido, el recorrido está implementado como una lista.

   @author Mariano Cinalli, Ezequiel Guitler, Santiago Montiel, Lucas Dreko, Laura Corvalan
*/

#ifndef _CASILLERO_H_
#define _CASILLERO_H_

#include "Punto.h"
#include <string>

class Casillero {
   public:
      /**
       * Constructor.
       */
      Casillero(char orientacion, int cantidadDePasos, bool hayObjeto);

      /**
       * Modifica las coordenadas x, y
       */
      void cambiarXY(int x, int y);

      /**
       * Retorna nombre bifurcacion
       */
      std::string obtenerBifurcacion();

      /**
       * Modifica el nombre de la bifurcacion
       */
      void cambiarBifurcacion(std::string nombre);

      /**
       * Retorna nombre union
       */
      std::string obtenerEmpalme();

      /**
       * Modifica el nombre de la bifurcacion con la que se une el casillero
       */
      void cambiarEmpalme(std::string nombre);

      /**
       * Retorna orientacion
       * Posibles valores: N, S, E, O
       */
      char obtenerOrientacion();

      /**
       * Retorna total de pasos que ocupa el casillero (?)
       */
      int obtenerCantidadDePasos();

      /**
       * Retorna un punto, donde se definen las coordenadas x, y para
       * poder ubicar el casillero dentro de la imagen
       */
      Punto * obtenerPunto();

      /**
       * Retorna true si se debe marcar un objeto en la imagen (Si el caminante tiro un objeto)
       */
      bool hayObjeto();

      std::string aString();

   private:
      /**
       * Orientacion. Valores posibles: N, S, E, O
       */
      char orientacion;

      /**
       * @TODO
       * Pasos dentro del casillero?... quizas tengamos que
       * cambiar el nombre, se les ocurre algo?
       */
      int cantidadDePasos;

      /**
       * Nombre bifurcacion
       */
      std::string bifurcacion;

      /**
       * Nombre union. La palabra "union" es una palabra reservada en c++
       */
      std::string empalme;

      /**
       * True si se tiro un objeto en el casillero, false caso contrario
       */
      bool objeto;

      /**
       * Coordenadas X Y
       */
      Punto * punto;

};

#endif