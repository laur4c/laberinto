/**
   Laberinto - TP 1
   Contiene la informacion de un punto del recorrido.

   @author Mariano Cinalli
   @author Ezequiel Guitler
   @author Santiago Montiel
   @author Lucas Dreko
   @author Laura Corvalan
*/

#ifndef _INFO_PUNTO_H_
#define _INFO_PUNTO_H_

#include <string>

class InfoPunto {
   public:
      /**
       * Orientacion. Valores posibles: N, S, E, O
       */
      char orientacion;


      /**
       * Constructor.
       */
      InfoPunto(char orientacion, int cantidadDePasos, bool hayObjeto);

      /**
       * Retorna nombre bifurcacion
       */
      std::string obtenerBifurcacion();

      bool tieneBifurcacion();

      /**
       * Modifica el nombre de la bifurcacion
       */
      void cambiarBifurcacion(std::string nombre);

      /**
       * Retorna nombre union
       */
      std::string obtenerEmpalme();

      /**
       * Retorna true si el punto tiene empalme
       */
      bool tieneEmpalme();

      /**
       * Modifica el nombre de la bifurcacion con la que se une el punto
       */
      void cambiarEmpalme(std::string nombre);

      /**
       * Retorna orientacion
       * Posibles valores: N, S, E, O
       */
      char obtenerOrientacion();

      /**
       * Retorna total de pasos que ocupa el punto
       */
      int obtenerCantidadDePasos();

      /**
       * Retorna true si se debe marcar un objeto en la imagen (Si el caminante tiro un objeto)
       */
      bool hayObjeto();

      std::string aString();

   private:

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
       * True si se tiro un objeto en el punto, false caso contrario
       */
      bool objeto;
};

#endif