/**
   Laberinto - TP 1
   Contiene la informacion de un punto del recorrido.

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

      /**
       * Retorna la orientacion de la bifurcacion
       */
      char obtenerOrientacionDeBifurcacion();

      /**
       * Retorna true si tiene bifurcacion, false caso contrario
       */
      bool tieneBifurcacion();

      /**
       * Modifica el nombre y la orientacion de la bifurcacion
       */
      void cambiarBifurcacion(std::string nombre, char orientacion);

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

      /**
       * Setea en true el atributo objeto, que indica si hay un objeto en el punto o no
       */
      void marcarConObjeto();

      std::string aString();

   private:

      int cantidadDePasos;

      /**
       * Nombre de la bifurcacion
       */
      std::string bifurcacion;

      /**
       * Orientacion de la bifurcacion
       */
      char bifurcacionOrientacion;

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